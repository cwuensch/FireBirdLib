#include "FBLib_rec.h"

void HDD_EncodeRECHeader_Header(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  Buffer[0] = (RECHeaderInfo->HeaderMagic >> 24) & 0xff;
  Buffer[1] = (RECHeaderInfo->HeaderMagic >> 16) & 0xff;
  Buffer[2] = (RECHeaderInfo->HeaderMagic >>  8) & 0xff;
  Buffer[3] =  RECHeaderInfo->HeaderMagic & 0xff;

  *( word*)(&Buffer [4]) = RECHeaderInfo->HeaderVersion;

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    //TMS
    memcpy(&Buffer[0x0006], RECHeaderInfo->HeaderUnknown2, 2);
    *(dword*)(&Buffer[0x0008]) = RECHeaderInfo->HeaderStartTime;
    *( word*)(&Buffer[0x000c]) = RECHeaderInfo->HeaderDuration;
    *( word*)(&Buffer[0x000e]) = RECHeaderInfo->HeaderDurationSec;
    Buffer[0x0010] = RECHeaderInfo->CryptFlag;
    Buffer[0x0011] = RECHeaderInfo->HeaderFlags;
    Buffer[0x0012] = RECHeaderInfo->HeaderUnknown4;
  }
  else
  {
    //5k
    *( word*)(&Buffer [0x0008]) = RECHeaderInfo->HeaderDuration;
    *( word*)(&Buffer [0x000a]) = RECHeaderInfo->HeaderSvcNumber;
    *( word*)(&Buffer [0x000c]) = RECHeaderInfo->HeaderSvcType;
  }
}

void HDD_EncodeRECHeader_ServiceInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  Flags;

  p = OffsetServiceInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    //TMS
    *( byte*)(&Buffer[p + 0x0000]) = RECHeaderInfo->SISatIndex;
    *( byte*)(&Buffer[p + 0x0001]) = RECHeaderInfo->SIServiceType;

    Flags = (RECHeaderInfo->SITPIdx << 6) |
            (RECHeaderInfo->SITunerNum << 4) |
            (RECHeaderInfo->SIDelFlag  << 3) |
            (RECHeaderInfo->SICASFlag  << 2) |
            (RECHeaderInfo->SILockFlag << 1) |
             RECHeaderInfo->SISkipFlag;
    *(word*)&Buffer[p +0x0002] = Flags;

    *(word*)&Buffer[p + 0x0004] = RECHeaderInfo->SIServiceID;
    *(word*)&Buffer[p + 0x0006] = RECHeaderInfo->SIPMTPID;
    *(word*)&Buffer[p + 0x0008] = RECHeaderInfo->SIPCRPID;
    *(word*)&Buffer[p + 0x000a] = RECHeaderInfo->SIVideoPID;
    *(word*)&Buffer[p + 0x000c] = RECHeaderInfo->SIAudioPID;

    memcpy (&Buffer[p + 0x000e], RECHeaderInfo->SISvcName, 24);

    Buffer[p + 0x0026] = RECHeaderInfo->SIVideoStreamType;
    Buffer[p + 0x0027] = RECHeaderInfo->SIAudioStreamType;
  }
  else
  {
    //5k
    *( byte*)(&Buffer[p + 0x0000]) = RECHeaderInfo->SISatIndex;
    *( byte*)(&Buffer[p + 0x0001]) = RECHeaderInfo->SIServiceType;

    Flags = (RECHeaderInfo->SITPIdx << 6) |
            (RECHeaderInfo->SITunerNum << 4) |
            (RECHeaderInfo->SIDelFlag  << 3) |
            (RECHeaderInfo->SICASFlag  << 2) |
            (RECHeaderInfo->SILockFlag << 1) |
             RECHeaderInfo->SISkipFlag;
    *(word*)&Buffer[p +0x0002] = Flags;

    *(word*)&Buffer[p + 0x0004] = RECHeaderInfo->SIServiceID;
    *(word*)&Buffer[p + 0x0006] = RECHeaderInfo->SIPMTPID;
    *(word*)&Buffer[p + 0x0008] = RECHeaderInfo->SIPCRPID;
    *(word*)&Buffer[p + 0x000a] = RECHeaderInfo->SIVideoPID;
    *(word*)&Buffer[p + 0x000c] = RECHeaderInfo->SIAudioPID;

    if (RECHeaderInfo->RECHeaderType == RHT_5kUK)
    {
      memcpy (&Buffer[p + 0x000e], RECHeaderInfo->SISvcName, 28);
    }
    else
      memcpy (&Buffer[p + 0x000e], RECHeaderInfo->SISvcName, 24);
  }
}

void HDD_EncodeRECHeader_TPInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  TPFlags1;

  p = OffsetTPInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    memcpy (&Buffer[p + 0], RECHeaderInfo->TPUnknown1, 4);
    *(byte*)(&Buffer[p + 4]) = RECHeaderInfo->TPSatIndex;

    TPFlags1 =  RECHeaderInfo->TPPolarization |
               (RECHeaderInfo->TPMode <<  1) |
               (RECHeaderInfo->TPSystem <<  4) |
               (RECHeaderInfo->TPModulation << 5) |
               (RECHeaderInfo->TPFEC << 7) |
               (RECHeaderInfo->TPPilot << 11);
    *(word*)&Buffer[p +  5] = TPFlags1;

    Buffer[p + 7] = RECHeaderInfo->TPUnknown2;
    *(dword*)&Buffer[p +  8] = RECHeaderInfo->TPFrequency;
    *(word*)&Buffer[p + 12]  = RECHeaderInfo->TPSymbolRate;
    *(word*)&Buffer[p + 14]  = RECHeaderInfo->TPTSID;
    RECHeaderInfo->TPFlags2 = (RECHeaderInfo->TPFlags2 & 0xfffe) | RECHeaderInfo->TPClockSync;
    *(word*)&Buffer[p + 16] = RECHeaderInfo->TPFlags2;
    *(word*)&Buffer[p + 18] = RECHeaderInfo->TPOriginalNetworkID;
  }
  else
  {
    switch (RECHeaderInfo->HeaderType)
    {
      case ST_DVBS:
      {
        *(byte*)(&Buffer[p +  0]) = RECHeaderInfo->TPSatIndex;

        TPFlags1 = (RECHeaderInfo->TPPolarization << 7) |
                   (RECHeaderInfo->TPMode << 4);
        *( byte*)(&Buffer[p +  1]) = TPFlags1;

         memcpy(&Buffer[p + 2], RECHeaderInfo->TPUnknown3, 2);
       *(dword*)&Buffer[p + 4]  = RECHeaderInfo->TPFrequency;
        *(word*)&Buffer[p +  8] = RECHeaderInfo->TPSymbolRate;
        *(word*)&Buffer[p + 10] = RECHeaderInfo->TPTSID;
         memcpy(&Buffer[p + 12], RECHeaderInfo->TPUnknown5, 2);
        *(word*)&Buffer[p + 14] = RECHeaderInfo->TPOriginalNetworkID;
        break;
      }

      case ST_DVBT:
      case ST_DVBT5700:
      {
        *(word*)&Buffer[p + 0]  = RECHeaderInfo->TPChannelNumber;
        *(byte*)&Buffer[p + 2]  = RECHeaderInfo->TPBandwidth;
        *(byte*)&Buffer[p + 3]  = RECHeaderInfo->TPUnknown2;
       *(dword*)&Buffer[p + 4]  = RECHeaderInfo->TPFrequency;
        *(word*)&Buffer[p + 8]  = RECHeaderInfo->TPTSID;
        *(byte*)&Buffer[p + 10] = RECHeaderInfo->TPLPHPStream;
        *(byte*)&Buffer[p + 11] = RECHeaderInfo->TPUnknown4;
        *(word*)&Buffer[p + 12] = RECHeaderInfo->TPOriginalNetworkID;
        *(word*)&Buffer[p + 14] = RECHeaderInfo->TPNetworkID;

        if (RECHeaderInfo->HeaderType == ST_DVBT5700)
          memcpy(&Buffer[p + 16], RECHeaderInfo->TPUnknown7, 8);
        break;
      }

      case ST_DVBC:
      {
       *(dword*)&Buffer[p +  0] = RECHeaderInfo->TPFrequency;
        *(word*)&Buffer[p +  4] = RECHeaderInfo->TPSymbolRate;
        *(word*)&Buffer[p +  6] = RECHeaderInfo->TPTSID;
        *(word*)&Buffer[p +  8] = RECHeaderInfo->TPOriginalNetworkID;
        *(byte*)&Buffer[p + 10] = RECHeaderInfo->TPModulation;
        *(byte*)&Buffer[p + 11] = RECHeaderInfo->TPUnknown6;
        break;
      }

      case ST_UNKNOWN:
      case ST_DVBSTMS:
      {
        break;
      }
    }
  }
}

void HDD_EncodeRECHeader_EventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  p = OffsetEventInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    memcpy(&Buffer[p], RECHeaderInfo->EventUnknown1, 2);

    *(byte*)&Buffer[p + 0x0003] = RECHeaderInfo->EventDurationHour;
    *(byte*)&Buffer[p + 0x0002] = RECHeaderInfo->EventDurationMin;
   *(dword*)&Buffer[p + 0x0004] = RECHeaderInfo->EventEventID;
   *(dword*)&Buffer[p + 0x0008] = RECHeaderInfo->EventStartTime;
   *(dword*)&Buffer[p + 0x000c] = RECHeaderInfo->EventEndTime;
    *(byte*)&Buffer[p + 0x0010] = RECHeaderInfo->EventRunningStatus;
    *(byte*)&Buffer[p + 0x0011] = RECHeaderInfo->EventTextLength;
    *(byte*)&Buffer[p + 0x0012] = RECHeaderInfo->EventParentalRate;

    memcpy(&Buffer[p + 0x0013], RECHeaderInfo->EventEventName, RECHeaderInfo->EventTextLength);
    memcpy(&Buffer[p + 0x0013 + RECHeaderInfo->EventTextLength], RECHeaderInfo->EventEventDescription, 273 - RECHeaderInfo->EventTextLength);
  }
  else
  {
    memcpy (&Buffer[p], RECHeaderInfo->EventUnknown1, 2);

    *(byte*)&Buffer[p + 0x0002] = RECHeaderInfo->EventDurationHour;
    *(byte*)&Buffer[p + 0x0003] = RECHeaderInfo->EventDurationMin;
   *(dword*)&Buffer[p + 0x0004] = RECHeaderInfo->EventEventID;
   *(dword*)&Buffer[p + 0x0008] = RECHeaderInfo->EventStartTime;
   *(dword*)&Buffer[p + 0x000c] = RECHeaderInfo->EventEndTime;
    *(byte*)&Buffer[p + 0x0010] = RECHeaderInfo->EventRunningStatus;
    *(byte*)&Buffer[p + 0x0011] = RECHeaderInfo->EventTextLength;
    *(byte*)&Buffer[p + 0x0012] = RECHeaderInfo->EventParentalRate;

    memcpy (&Buffer[p + 19], RECHeaderInfo->EventEventName, RECHeaderInfo->EventTextLength);
    memcpy (&Buffer[p + 19 + RECHeaderInfo->EventTextLength], RECHeaderInfo->EventEventDescription, 273 - RECHeaderInfo->EventTextLength);
   *(word*)&Buffer[p + 276] = RECHeaderInfo->EventServiceID;
    memcpy (&Buffer[p + 278], RECHeaderInfo->EventUnknown2, 10);
  }
}

void HDD_EncodeRECHeader_ExtendedEventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  p = OffsetExtEventInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    *(word*)&Buffer[p + 0x0000] = RECHeaderInfo->ExtEventServiceID;
    *(word*)&Buffer[p + 0x0002] = RECHeaderInfo->ExtEventTextLength;
    *(dword*)&Buffer[p + 0x0004] = RECHeaderInfo->ExtEventEventID;
    memcpy (&Buffer[p + 0x0008], RECHeaderInfo->ExtEventText, 1024);
  }
  else
  {
    *(word*)&Buffer[p + 0x0000] = RECHeaderInfo->ExtEventServiceID;
    *(word*)&Buffer[p + 0x0002] = RECHeaderInfo->ExtEventTextLength;
    memcpy (&Buffer[p + 0x0004], RECHeaderInfo->ExtEventUnknown2, 2);
    *(word*)&Buffer[p + 0x0006] = RECHeaderInfo->ExtEventEventID;
    memcpy (&Buffer[p + 0x0008], RECHeaderInfo->ExtEventText, 1024);
  }
}

void HDD_EncodeRECHeader_CryptInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  p = OffsetCryptInfo[RECHeaderInfo->RECHeaderType];

  //The TMS crypt info is already included in the file header block
  if(RECHeaderInfo->RECHeaderType != RHT_TMSs)
  {
    memcpy (&Buffer[p], RECHeaderInfo->CryptReserved1, 4);
    *( byte*)(&Buffer[p + 0x0004]) = RECHeaderInfo->CryptFlag;
    memcpy (&Buffer[p + 0x0005], RECHeaderInfo->CryptReserved2, 3);
  }
}

void HDD_EncodeRECHeader_Bookmarks(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  p = OffsetBookmarks[RECHeaderInfo->RECHeaderType];

  //It's not yet known if the bookmark block exists on the TMS
  if(RECHeaderInfo->RECHeaderType != RHT_TMSs)
  {
    memcpy (&Buffer[p], RECHeaderInfo->Bookmark, 64 * sizeof (dword));
    *(dword*)&Buffer[p + 0x0100] = RECHeaderInfo->Resume;
  }
  else
  {
    *(dword*)&Buffer[p + 0x0000] = RECHeaderInfo->NrBookmarks;
    memcpy (&Buffer[p + 0x0004], RECHeaderInfo->Bookmark, 177 * sizeof (dword));
    *(dword*)&Buffer[p + 0x02c8] = RECHeaderInfo->Resume;
  }
}

void HDD_EncodeRECHeader (char *Buffer, tRECHeaderInfo *RECHeaderInfo, eRECHeaderType RecHeaderType)
{
  RECHeaderInfo->RECHeaderType = RecHeaderType;
  switch(RecHeaderType)
  {
    case RHT_UNKNOWN: RECHeaderInfo->HeaderType = ST_UNKNOWN; break;
    case RHT_5kS    : RECHeaderInfo->HeaderType = ST_DVBS; break;
    case RHT_5kT    : RECHeaderInfo->HeaderType = ST_DVBT; break;
    case RHT_5kC    : RECHeaderInfo->HeaderType = ST_DVBC; break;
    case RHT_5kT5700: RECHeaderInfo->HeaderType = ST_DVBT5700; break;
    case RHT_5kUK   : RECHeaderInfo->HeaderType = ST_DVBT; break;
    case RHT_TMSs   : RECHeaderInfo->HeaderType = ST_DVBSTMS; break;
  }

  HDD_EncodeRECHeader_Header(Buffer, RECHeaderInfo);
  HDD_EncodeRECHeader_ServiceInfo(Buffer, RECHeaderInfo);
  HDD_EncodeRECHeader_TPInfo(Buffer, RECHeaderInfo);
  HDD_EncodeRECHeader_EventInfo(Buffer, RECHeaderInfo);
  HDD_EncodeRECHeader_ExtendedEventInfo(Buffer, RECHeaderInfo);
  HDD_EncodeRECHeader_CryptInfo(Buffer, RECHeaderInfo);
  HDD_EncodeRECHeader_Bookmarks(Buffer, RECHeaderInfo);
}
