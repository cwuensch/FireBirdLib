#include                <string.h>
#include                "tap.h"
#include                "../../libFireBird.h"

#define PROGRAM_NAME    "FIS_Test"
#define LOGNAME         "FIS_Test.log"

#ifdef _TMS_
  #define FIRMWAREDAT   "FirmwareTMS.dat"
#else
  #define FIRMWAREDAT   "Firmware.dat"
#endif

TAP_ID(1);
TAP_PROGRAM_NAME        (PROGRAM_NAME);
TAP_AUTHOR_NAME         ("FireBird");
TAP_DESCRIPTION         ("");
TAP_ETCINFO             (__DATE__);

char                    LogPuffer[256];
#define DEBUG(...)      {sprintf(LogPuffer, __VA_ARGS__); LogEntry(LOGNAME, PROGRAM_NAME, TRUE, TIMESTAMP_HMS, LogPuffer);}

dword TAP_EventHandler (word event, dword param1, dword param2)
{
  (void) event;
  (void) param2;

  return param1;
}

#ifndef _TMS_
  extern int            _appl_version;
#endif

char                    x[256];

int TAP_Main (void)
{
  word                  SystemID;
  dword                 i;
  tFWDATHeader         *FWDatHeader;
  tToppyInfo           *ToppyInfo;
  tFWInfo              *FWInfo;
  INILOCATION           Loc;
  SYSTEM_TYPE           SystemType = ST_UNKNOWN;

#ifndef _TMS_
  int                   FWID = -1;
#endif

  SystemID = GetSysID();

#ifdef _TMS_
  DEBUG("SysID=%d, ApplID=%4.4x", SystemID, TAP_GetVersion());
#else
  DEBUG("SysID=%d, ApplID=%4.4x, FWgp=%8.8x", SystemID, _appl_version, FIS_GetGP((dword*)0x80000000));
#endif
  DEBUG("Built with FBLib version %s", __FBLIB_VERSION__);
  DEBUG("");

  //Details about Flash access
  if (InitTAPex())
  {
    DEBUG("Main init = OK");
  }
  else
  {

#ifdef _TMS_
    DEBUG("Main init failed");
#else

    x[0] = '\0';
    if (!FWgp) strcat(x, "FWgp");
    if (!pFWWD)
    {
      if(x[0]) strcat(x, ",");
      strcat(x, "pFWWD");
    }
    if (!TAP_TableAddress)
    {
      if(x[0]) strcat(x, ",");
      strcat(x, "TAP_TableAddress");
    }
    if (!EnqueueEventAddress)
    {
      if(x[0]) strcat(x, ",");
      strcat(x, "EnqueueEventAddress");
    }
    DEBUG("Main init failed (%s not found)", x);
#endif
  }

  if(FlashInitialize(SystemID))
  {
    DEBUG("Flash init = OK");
  }
  else
  {
    DEBUG("Flash init failed.");
    DEBUG("  This might be due to a failed main init, a failed attempt to open Firmware.dat,");
    DEBUG("  your system ID missing in Firmware.dat (see next paragraph) or the failure to");
    DEBUG("  locate FIS_vFlash()");
  }

  //Details about Firmware.dat
  DEBUG("");
  HDD_TAP_PushDir();
  Loc = INILocateFile(FIRMWAREDAT, NULL);
  if (Loc == INILOCATION_NotFound)
  {
    HDD_TAP_PopDir();

    DEBUG("%s not found.", FIRMWAREDAT);
  }
  else
  {
    TAP_SPrint(x, "%s found at ", FIRMWAREDAT);
    switch(Loc)
    {
      case INILOCATION_AtCurrentDir:    strcat(x, "current directory"); break;
      case INILOCATION_AtAppName:       strcat(x, "/ProgramFiles/Settings/<appname>"); break;
      case INILOCATION_AtSettings:      strcat(x, "/ProgramFiles/Settings"); break;
      case INILOCATION_AtProgramFiles:  strcat(x, "/ProgramFiles"); break;
      default: strcat(x, "(unhandled)"); break;
    }

    if (!LoadFirmwareDat(&FWDatHeader, &ToppyInfo, &FWInfo))
    {
      HDD_TAP_PopDir();
      DEBUG("%s", x);
      DEBUG("  Failed while trying to load %s", FIRMWAREDAT);
    }
    else
    {
      HDD_TAP_PopDir();
      DEBUG("%s", x);
      DEBUG("  Compile date %d-%02d-%02d", FWDatHeader->CompileDate >> 16, (FWDatHeader->CompileDate >> 8) & 0xff, FWDatHeader->CompileDate & 0xff);
      DEBUG("  %d SysIDs, %d F/W IDs", FWDatHeader->NrOfToppyInfoEntries, FWDatHeader->NrOfFWInfoEntries);
    }

    for (i = 0; i < FWDatHeader->NrOfToppyInfoEntries; i++, ToppyInfo++)
    {
      if (ToppyInfo->SysID == SystemID)
      {
        SystemType = ToppyInfo->SystemType;
        break;
      }
    }

    if(ToppyInfo->SystemType == ST_UNKNOWN)
    {
      DEBUG("  Your SysID is not included in %s!", FIRMWAREDAT);
    }
    else
    {
      DEBUG("  %s", ToppyInfo->Device);
      DEBUG("  %s", ToppyInfo->AppType);

      switch (ToppyInfo->SystemType)
      {
        case ST_DVBS    : DEBUG("  DVBs"); break;
        case ST_DVBT    : DEBUG("  DVBt"); break;
        case ST_DVBC    : DEBUG("  DVBc"); break;
        case ST_DVBT5700: DEBUG("  Modified DVBt (TF5700)"); break;
        case ST_DVBSTMS : DEBUG("  DVBs (TMS)"); break;
        default:;
      }

      switch(ToppyInfo->DisplayType)
      {
        case DT_LED:     DEBUG("  DisplayType   =  LED"); break;
        case DT_VFD5500: DEBUG("  DisplayType   =  TF5500 dot matrix VFD"); break;
        case DT_VFDMP:   DEBUG("  DisplayType   =  Masterpiece VFD"); break;
      }
    }

#ifndef _TMS_
    for (i = 0; i < FWDatHeader->NrOfFWInfoEntries; i++, FWInfo++)
    {
      if (FWInfo->SysID == SystemID && FWInfo->FWgp == FWgp)
      {
        FWID = i;
        break;
      }
    }

    if(FWID == -1)
    {
      DEBUG("  Your firmware is not included in %s!", FIRMWAREDAT);
    }
    else
    {
      DEBUG("  FW Date       = %d-%02d-%02d", FWInfo->FWDate >> 16, (FWInfo->FWDate >> 8) & 0xff, FWInfo->FWDate & 0xff);
      DEBUG("  FW AppVersion = %x", FWInfo->AppVersion);
      DEBUG("  FW beta state = %s", FWInfo->Beta ? "yes": "no");
    }
#endif
  }

  //Details about the FindInstructionSequences
  DEBUG("");

#ifdef _TMS_
  DEBUG("FIS_fwApplVfdStart                = %8.8x", FIS_fwApplVfdStart());
  DEBUG("FIS_fwApplVfdStop                 = %8.8x", FIS_fwApplVfdStop());
  DEBUG("FIS_fwPowerOff                    = %8.8x", FIS_fwPowerOff());
  DEBUG("FIS_fwApplVfdSendData             = %8.8x", FIS_fwApplVfdSendData());
  DEBUG("FIS_fwSetIrCode                   = %8.8x", FIS_fwSetIrCode());
#else
  DEBUG("FIS_fwAddEventHandler             = %8.8x", FIS_fwAddEventHandler());
  DEBUG("FIS_fwBIOS                        = %8.8x", FIS_fwBIOS());
  DEBUG("FIS_fwDelEventHandler             = %8.8x", FIS_fwDelEventHandler());
  DEBUG("FIS_fwDSTCheck                    = %8.8x", FIS_fwDSTCheck());
  DEBUG("FIS_fwEnqueueEvent                = %8.8x", FIS_fwEnqueueEvent());
  DEBUG("FIS_fwEventDispatcher             = %8.8x", FIS_fwEventDispatcher());
  DEBUG("FIS_fwFlashEraseSector            = %8.8x", FIS_fwFlashEraseSector());
  DEBUG("FIS_fwFlashFindSectorAddressIndex = %8.8x", FIS_fwFlashFindSectorAddressIndex());
  DEBUG("FIS_fwFlashGetSectorAddress       = %8.8x", FIS_fwFlashGetSectorAddress());
  DEBUG("FIS_fwFWFlashProgram              = %8.8x", FIS_fwFWFlashProgram());
  DEBUG("FIS_fwGetMPVFDDataBuffer          = %8.8x", FIS_fwGetMPVFDDataBuffer());
  DEBUG("FIS_fwMemMonitor                  = %8.8x", FIS_fwMemMonitor());
  DEBUG("FIS_fwMHEGDisable                 = %8.8x", FIS_fwMHEGDisable());
  DEBUG("FIS_fwMHEGStatus                  = %8.8x", FIS_fwMHEGStatus());
  DEBUG("FIS_fwMoveOld                     = %8.8x", FIS_fwMoveOld());
  DEBUG("FIS_fwObtainResource              = %8.8x", FIS_fwObtainResource());
  DEBUG("FIS_fwPIC2_ISR18                  = %8.8x", FIS_fwPIC2_ISR18());
  DEBUG("FIS_fwReboot                      = %8.8x", FIS_fwReboot());
  DEBUG("FIS_fwReleaseResource             = %8.8x", FIS_fwReleaseResource());
  DEBUG("FIS_fwSendToFP                    = %8.8x", FIS_fwSendToFP());
  DEBUG("FIS_fwSendToLEDDisplay            = %8.8x", FIS_fwSendToLEDDisplay());
  DEBUG("FIS_fwSetLEDByMode                = %8.8x", FIS_fwSetLEDByMode());
  DEBUG("FIS_fwSetPlaybackMode             = %8.8x", FIS_fwSetPlaybackMode());
  DEBUG("FIS_fwSetPlaybackSpeed            = %8.8x", FIS_fwSetPlaybackSpeed());
  DEBUG("FIS_fwSetVFDByMode                = %8.8x", FIS_fwSetVFDByMode());
  DEBUG("FIS_fwShutdownHandler             = %8.8x", FIS_fwShutdownHandler());
  DEBUG("FIS_fwStopDisplayUpdateTimers     = %8.8x", FIS_fwStopDisplayUpdateTimers());
  DEBUG("FIS_fwTAPStart                    = %8.8x", FIS_fwTAPStart());
  DEBUG("FIS_fwUpdateMPVFD                 = %8.8x", FIS_fwUpdateMPVFD());
  DEBUG("FIS_fwWriteSectors                = %8.8x", FIS_fwWriteSectors());
  DEBUG("FIS_fwWriteSectorsDMA             = %8.8x", FIS_fwWriteSectorsDMA());
#endif

  DEBUG("");

  DEBUG("FIS_vBootReason                   = %8.8x", FIS_vBootReason());
  DEBUG("FIS_vEEPROM                       = %8.8x", FIS_vEEPROM());
  DEBUG("FIS_vEEPROMPin                    = %8.8x", FIS_vEEPROMPin());
  DEBUG("FIS_vEtcInfo                      = %8.8x", FIS_vEtcInfo());
  DEBUG("FIS_vFlash                        = %8.8x", FIS_vFlash());
  DEBUG("FIS_vOSDMap                       = %8.8x", FIS_vOSDMap());
  DEBUG("FIS_vParentalInfo                 = %8.8x", FIS_vParentalInfo());
  DEBUG("FIS_vRECSlotAddress0              = %8.8x", FIS_vRECSlotAddress(0));
  DEBUG("FIS_vRECSlotAddress1              = %8.8x", FIS_vRECSlotAddress(1));

#ifdef _TMS_
  DEBUG("FIS_vRECSlotAddress2              = %8.8x", FIS_vRECSlotAddress(2));
  DEBUG("FIS_vgrid                         = %8.8x", FIS_vgrid());
  DEBUG("FIS_vcurTapTask                   = %8.8x", FIS_vcurTapTask());
  DEBUG("FIS_vMACAddress                   = %8.8x", FIS_vMACAddress());
#else
  DEBUG("FIS_vEventHandlerMap              = %8.8x", FIS_vEventHandlerMap());
  DEBUG("FIS_vFlashFWMaxSize               = %8.8x", FIS_vFlashFWMaxSize());
  DEBUG("FIS_vFlashFWStartOffset           = %8.8x", FIS_vFlashFWStartOffset());
  DEBUG("FIS_vFlashInProgress              = %8.8x", FIS_vFlashInProgress());
  DEBUG("FIS_vGMT                          = %8.8x", FIS_vGMT());
  DEBUG("FIS_vHddInfoStructure1            = %8.8x", FIS_vHddInfoStructure1());
  DEBUG("FIS_vHddInfoStructure2            = %8.8x", FIS_vHddInfoStructure2());
  DEBUG("FIS_vHDDLiveFSFAT1                = %8.8x", FIS_vHDDLiveFSFAT1());
  DEBUG("FIS_vHDDLiveFSRootDir             = %8.8x", FIS_vHDDLiveFSRootDir());
  DEBUG("FIS_vHDDLiveFSSuperblock          = %8.8x", FIS_vHDDLiveFSSuperblock());
  DEBUG("FIS_vHDDShutdown                  = %8.8x", FIS_vHDDShutdown());
  DEBUG("FIS_vHeapMap                      = %8.8x", FIS_vHeapMap());
  DEBUG("FIS_vHeapStart                    = %8.8x", FIS_vHeapStart());
  DEBUG("FIS_vIntVectorTable               = %8.8x", FIS_vIntVectorTable());
  DEBUG("FIS_vKeyMap                       = %8.8x", FIS_vKeyMap());
  DEBUG("FIS_vLEDDisplayBuffer             = %8.8x", FIS_vLEDDisplayBuffer());
  DEBUG("FIS_vMPEGHeader                   = %8.8x", FIS_vMPEGHeader());
  DEBUG("FIS_vMPVFD                        = %8.8x", FIS_vMPVFD());
  DEBUG("FIS_vMPVFDBackup                  = %8.8x", FIS_vMPVFDBackup());
  DEBUG("FIS_vPinStatus                    = %8.8x", FIS_vPinStatus());
  DEBUG("FIS_vPlaybackPaused               = %8.8x", FIS_vPlaybackPaused());
  DEBUG("FIS_vPlaySlot                     = %8.8x", FIS_vPlaySlot());
  DEBUG("FIS_vRecFile0                     = %8.8x", FIS_vRecFile(0));
  DEBUG("FIS_vRecFile1                     = %8.8x", FIS_vRecFile(1));
  DEBUG("FIS_vSuppressedAutoStart          = %8.8x", FIS_vSuppressedAutoStart());
  DEBUG("FIS_vSysOsdControl                = %8.8x", FIS_vSysOsdControl());
  DEBUG("FIS_vTAP_Vfd_Control              = %8.8x", FIS_vTAP_Vfd_Control());
  DEBUG("FIS_vTAP_Vfd_Status               = %8.8x", FIS_vTAP_Vfd_Status());
  DEBUG("FIS_vTAPTable                     = %8.8x", FIS_vTAPTable());
  DEBUG("FIS_vTaskAddressTable             = %8.8x", FIS_vTaskAddressTable());
  DEBUG("FIS_vVolume                       = %8.8x", FIS_vVolume());
  DEBUG("FIS_vWD1                          = %8.8x", FIS_vWD1());
#endif

  return 0;
}
