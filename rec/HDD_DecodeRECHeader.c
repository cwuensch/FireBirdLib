#include <string.h>
#include "FBLib_rec.h"

                           //unknown 5kS     5kT     5kC     5kT5700 5kUK    TMSs
dword OffsetServiceInfo[] = {     0, 0x000e, 0x000e, 0x000e, 0x000e, 0x000e, 0x001c};
dword OffsetTPInfo[]      = {     0, 0x0034, 0x0034, 0x0034, 0x0038, 0x0038, 0x0570};
dword OffsetEventInfo[]   = {     0, 0x0044, 0x0044, 0x0040, 0x0050, 0x0048, 0x0044};
dword OffsetExtEventInfo[]= {     0, 0x0168, 0x0168, 0x0164, 0x0174, 0x016c, 0x0168};
dword OffsetCryptInfo[]   = {     0, 0x0570, 0x0570, 0x056c, 0x057c, 0x0574,      0};
dword OffsetBookmarks[]   = {     0, 0x0578, 0x0578, 0x0574, 0x0584, 0x057c, 0x0584};


word getWord(void *buffer, bool NeedsByteSwapping)
{
  word                  w;
  byte                 *p;

  p = (byte*)buffer;
  if(NeedsByteSwapping)
    w = (p[1] | (p[0] << 8));
  else
    w = (p[0] | (p[1] << 8));

  return w;
}

dword getDword(void *buffer, bool NeedsByteSwapping)
{
  dword                 d;
  byte                 *p;

  p = (byte*)buffer;
  if(NeedsByteSwapping)
    d = (p[3] | (p[2] << 8) | (p[1] << 16) | (p[0] << 24));
  else
    d = (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24));

  return d;
}

bool                    WrongEndian = FALSE;

void HDD_DecodeRECHeader_Header(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  p = 0;
  RECHeaderInfo->HeaderVersion = getWord(&Buffer[p + 4], FALSE);
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);

  //Check the endianess of the file
  WrongEndian = (RECHeaderInfo->HeaderVersion == 0x0050) || (RECHeaderInfo->HeaderVersion == 0x1050) || (RECHeaderInfo->HeaderVersion == 0x0080);

  if(WrongEndian)
    RECHeaderInfo->HeaderVersion = getWord(&Buffer[p + 4], TRUE);

  if(RECHeaderInfo->HeaderVersion == 0x8000)
  {
    //TMS
    RECHeaderInfo->RECHeaderType = RHT_TMSs;
    RECHeaderInfo->HeaderStartTime = getDword(&Buffer[p + 0x0008], WrongEndian);
    RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x000c], WrongEndian);
    memcpy (RECHeaderInfo->HeaderUnknown3, &Buffer[p + 0x000e], 2);
    RECHeaderInfo->CryptFlag = Buffer[p + 0x0010];
    RECHeaderInfo->HeaderFlags = Buffer[p + 0x0011];
    RECHeaderInfo->HeaderUnknown4 = Buffer[p + 0x0012];
  }
  else
  {
    //5k
    RECHeaderInfo->RECHeaderType = RHT_5kS;
    RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x0008], WrongEndian);
    RECHeaderInfo->HeaderSvcNumber = getWord(&Buffer[p + 0x000a], WrongEndian);
    RECHeaderInfo->HeaderSvcType   = getWord(&Buffer[p + 0x000c], WrongEndian);
  }
}

void HDD_DecodeRECHeader_ServiceInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  Flags;

  //known: 5k? and TMSs
  p = OffsetServiceInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    //TMS
    RECHeaderInfo->SISatIndex    =  *( byte*)(&Buffer[p + 0x0000]);
    RECHeaderInfo->SIServiceType =  *( byte*)(&Buffer[p + 0x0001]);

    Flags = getWord(&Buffer[p +0x0002], WrongEndian);
    RECHeaderInfo->SITPIdx     =  Flags >> 6;
    RECHeaderInfo->SITunerNum  = (Flags >> 4) & 3;
    RECHeaderInfo->SIDelFlag   = (Flags >> 3) & 1;
    RECHeaderInfo->SICASFlag   = (Flags >> 2) & 1;
    RECHeaderInfo->SILockFlag  = (Flags >> 1) & 1;
    RECHeaderInfo->SISkipFlag  =  Flags       & 1;

    RECHeaderInfo->SIServiceID = getWord(&Buffer[p + 0x0004], WrongEndian);
    RECHeaderInfo->SIPMTPID    = getWord(&Buffer[p + 0x0006], WrongEndian);
    RECHeaderInfo->SIPCRPID    = getWord(&Buffer[p + 0x0008], WrongEndian);
    RECHeaderInfo->SIVideoPID  = getWord(&Buffer[p + 0x000a], WrongEndian);
    RECHeaderInfo->SIAudioPID  = getWord(&Buffer[p + 0x000c], WrongEndian);

    memcpy (RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

    RECHeaderInfo->SIVideoStreamType = Buffer[p + 0x0026];
    RECHeaderInfo->SIAudioStreamType = Buffer[p + 0x0027];
  }
  else
  {
    //5k
    RECHeaderInfo->SISatIndex  =  *( byte*)(&Buffer[p + 0x0000]);
    RECHeaderInfo->SIServiceType =  *( byte*)(&Buffer[p + 0x0001]);
    RECHeaderInfo->SITPIdx     =  getWord(&Buffer[p + 0x0002], WrongEndian) >> 6;
    RECHeaderInfo->SITunerNum  = (getWord(&Buffer[p + 0x0002], WrongEndian) >> 4) & 3;
    RECHeaderInfo->SIDelFlag   = (getWord(&Buffer[p + 0x0002], WrongEndian) >> 3) & 1;
    RECHeaderInfo->SICASFlag   = (getWord(&Buffer[p + 0x0002], WrongEndian) >> 2) & 1;
    RECHeaderInfo->SILockFlag  = (getWord(&Buffer[p + 0x0002], WrongEndian) >> 1) & 1;
    RECHeaderInfo->SISkipFlag  = (getWord(&Buffer[p + 0x0002], WrongEndian)     ) & 1;

    RECHeaderInfo->SIServiceID = getWord(&Buffer[p + 0x0004], WrongEndian);
    RECHeaderInfo->SIPMTPID    = getWord(&Buffer[p + 0x0006], WrongEndian);
    RECHeaderInfo->SIPCRPID    = getWord(&Buffer[p + 0x0008], WrongEndian);
    RECHeaderInfo->SIVideoPID  = getWord(&Buffer[p + 0x000a], WrongEndian);
    RECHeaderInfo->SIAudioPID  = getWord(&Buffer[p + 0x000c], WrongEndian);

    if (RECHeaderInfo->HeaderVersion == 0x5010)
    {
      memcpy (RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 28);
      RECHeaderInfo->RECHeaderType = RHT_5kUK;
    }
    else
      memcpy (RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);
  }
}

void HDD_DecodeRECHeader_TPInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  dword                 sPoints = 0, tPoints = 0, cPoints = 0;
  dword                 Frequency, SymbolRate;
  byte                  Modulation, Polarization, BandWidth, LPHPStream;
  word                  v1, v2;
  word                  TPFlags1;

  //known: 5k?, RHT_5kUK and TMSs
  p = OffsetTPInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    memcpy (RECHeaderInfo->TPUnknown1, &Buffer[p + 0], 4);
    RECHeaderInfo->TPSatIndex           =  *( byte*)(&Buffer[p +  4]);

    TPFlags1                            = getWord(&Buffer[p +  5], WrongEndian);
    RECHeaderInfo->TPPolarization       =  TPFlags1 & 0x01;
    RECHeaderInfo->TPMode               = (TPFlags1 >>  1) & 0x07;
    RECHeaderInfo->TPSystem             = (TPFlags1 >>  4) & 0x01;
    RECHeaderInfo->TPModulation         = (TPFlags1 >>  5) & 0x03;
    RECHeaderInfo->TPFEC                = (TPFlags1 >>  7) & 0x0f;
    RECHeaderInfo->TPPilot              = (TPFlags1 >> 11) & 0x01;

    RECHeaderInfo->TPUnknown2           = Buffer[p + 7];
    RECHeaderInfo->TPFrequency          =  getDword(&Buffer[p +  8], WrongEndian);
    RECHeaderInfo->TPSymbolRate         = getWord(&Buffer  [p + 12], WrongEndian);
    RECHeaderInfo->TPTSID               = getWord(&Buffer  [p + 14], WrongEndian);
    RECHeaderInfo->TPFlags2             = getWord(&Buffer  [p + 16], WrongEndian);
    RECHeaderInfo->TPClockSync          = RECHeaderInfo->TPFlags2 & 0x0001;
    RECHeaderInfo->TPOriginalNetworkID  =  getWord(&Buffer[p + 18], WrongEndian);
    RECHeaderInfo->HeaderType           = ST_DVBSTMS;
  }
  else
  {
    //Use the following rules for the type decision (thx to jkIT)
    //Count 1 point for every matching rule
    //for dvb-s:
    //  Transponder_Info.Polarity & 0x6F == 0 ?
    //  Transponder_Info.Symbol_Rate in [2000...30000] ?
    //  Transponder_Info.Frequency in [10700...12800] ?
    //for dvb-t
    //  Transponder_Info.Bandwidth in [6..8] ?
    //  Transponder_Info.Frequency in [174000...230000] or [470000...862000] ?
    //  Transponder_Info.LP_HP_Stream & 0xFE == 0 ?
    //for dvb-c
    //  Transponder_Info.Frequency in [47000...862000] ?
    //  Transponder_Info.Symbol_Rate in [2000...30000] ?
    //  Transponder_Info.Modulation <= 4 ?

    //Count cable points
    Frequency = getDword(&Buffer[p + 0], WrongEndian);
    SymbolRate = getWord(&Buffer[p + 4], WrongEndian);
    Modulation = *(byte *) (&Buffer[p + 10]);
    if ((Frequency >= 47000) && (Frequency <= 862000)) cPoints++;
    if ((SymbolRate >= 2000) && (SymbolRate <= 30000)) cPoints++;
    if (Modulation <= 4) cPoints++;

    //Count sat points
    Frequency = getDword(&Buffer[p + 4], WrongEndian);
    SymbolRate = getWord(&Buffer[p + 8], WrongEndian);
    Polarization = *(byte *) (&Buffer[p + 1]);
    if ((Frequency >= 10700) && (Frequency <= 12800)) sPoints++;
    if ((SymbolRate >= 2000) && (SymbolRate <= 30000)) sPoints++;
    if ((Polarization & 0x6F) == 0) sPoints++;

    //Count terrestrial points
    BandWidth = *(byte *) (&Buffer[p + 2]);
    LPHPStream = *(byte *) (&Buffer[p + 10]);
    if (((Frequency >= 174000) && (Frequency <= 230000)) || ((Frequency >= 470000) && (Frequency <= 862000))) tPoints++;
    if ((BandWidth >= 6) && (BandWidth <= 8)) tPoints++;
    if ((LPHPStream & 0xFE) == 0) tPoints++;

    //If one system has 3 points and all other have less than 3, use that DVB system
    if ((sPoints == 3) && (tPoints  < 3) && (cPoints  < 3))
    {
      RECHeaderInfo->HeaderType = ST_DVBS;
      RECHeaderInfo->RECHeaderType = RHT_5kS;
    }

    if ((sPoints <  3) && (tPoints == 3) && (cPoints  < 3))
    {
      //Try to find out if this is a TF5700 Header: compare the date
      v1 = getWord(&Buffer[84], WrongEndian);   // StartMJD
      v2 = getWord(&Buffer[88], WrongEndian);   // EndMJD
      RECHeaderInfo->HeaderType = (v1 && v2 && (v1 == v2 || v1 + 1 == v2) ? ST_DVBT5700 : ST_DVBT);

      if(RECHeaderInfo->HeaderType == ST_DVBT)
        RECHeaderInfo->RECHeaderType = RHT_5kT;
      else
        RECHeaderInfo->RECHeaderType = RHT_5kT5700;
    }

    if ((sPoints <  3) && (tPoints  < 3) && (cPoints == 3))
    {
      RECHeaderInfo->HeaderType = ST_DVBC;
      RECHeaderInfo->RECHeaderType = RHT_5kC;
    }

#ifdef DEBUG_FIREBIRDLIB
  TAP_Print ("FireBirdLib: DecodeRCEHeader: DVBs=%d, DVBt=%d, DVBc=%d\n", sPoints, tPoints, cPoints);
#endif

    //Transponder block
    switch (RECHeaderInfo->HeaderType)
    {
      case ST_DVBS:
      {
        RECHeaderInfo->TPSatIndex           = *( byte*)(&Buffer[p +  0]);
        TPFlags1                            = *( byte*)(&Buffer[p +  1]);
        RECHeaderInfo->TPPolarization       =  TPFlags1 >> 7;
        RECHeaderInfo->TPMode               = (TPFlags1 >> 4) & 7;
        memcpy(RECHeaderInfo->TPUnknown3, &Buffer[p + 2], 2);
        RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  4], WrongEndian);
        RECHeaderInfo->TPSymbolRate         = getWord(&Buffer[p +  8], WrongEndian);
        RECHeaderInfo->TPTSID               = getWord(&Buffer[p + 10], WrongEndian);
        memcpy (RECHeaderInfo->TPUnknown5, &Buffer[p + 12], 2);
        RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 14], WrongEndian);
        break;
      }

      case ST_DVBT:
      case ST_DVBT5700:
      {
        RECHeaderInfo->TPChannelNumber      = getWord(&Buffer[p +  0], WrongEndian);
        RECHeaderInfo->TPBandwidth          = *( byte*)(&Buffer[p +  2]);
        RECHeaderInfo->TPUnknown2           = *( byte*)(&Buffer[p +  3]);
        RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  4], WrongEndian);
        RECHeaderInfo->TPTSID               = getWord(&Buffer[p +  8], WrongEndian);
        RECHeaderInfo->TPLPHPStream         = *( byte*)(&Buffer[p + 10]);
        RECHeaderInfo->TPUnknown4           = *( byte*)(&Buffer[p + 11]);
        RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 12], WrongEndian);
        RECHeaderInfo->TPNetworkID          = getWord(&Buffer[p + 14], WrongEndian);
        if (RECHeaderInfo->HeaderType == ST_DVBT5700)
          memcpy(RECHeaderInfo->TPUnknown7, &Buffer[p + 16], 8);
        break;
      }

      case ST_DVBC:
      {
        RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  0], WrongEndian);
        RECHeaderInfo->TPSymbolRate         = getWord(&Buffer[p +  4], WrongEndian);
        RECHeaderInfo->TPTSID               = getWord(&Buffer[p +  6], WrongEndian);
        RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p +  8], WrongEndian);
        RECHeaderInfo->TPModulation         = *( byte*)(&Buffer[p + 10]);
        RECHeaderInfo->TPUnknown6           = *( byte*)(&Buffer[p + 11]);
        break;

      case ST_UNKNOWN:
      case ST_DVBSTMS:
        break;
      }
    }
  }
}

void HDD_DecodeRECHeader_EventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  p = OffsetEventInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    memcpy (RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
    RECHeaderInfo->EventDurationHour   = *( byte*)(&Buffer[p +  3]);
    RECHeaderInfo->EventDurationMin    = *( byte*)(&Buffer[p +  2]);
    RECHeaderInfo->EventEventID        = getDword(&Buffer[p + 0x0004], WrongEndian);
    RECHeaderInfo->EventStartTime      = getDword(&Buffer[p + 0x0008], WrongEndian);
    RECHeaderInfo->EventEndTime        = getDword(&Buffer[p + 0x000c], WrongEndian);
    RECHeaderInfo->EventRunningStatus  = *( byte*)(&Buffer[p + 0x0010]);
    RECHeaderInfo->EventTextLength     = *( byte*)(&Buffer[p + 0x0011]);
    RECHeaderInfo->EventParentalRate   = *( byte*)(&Buffer[p + 0x0012]);
    memcpy(RECHeaderInfo->EventEventName, &Buffer[p + 0x0013], RECHeaderInfo->EventTextLength);
    memcpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 0x0013 + RECHeaderInfo->EventTextLength], 273 - RECHeaderInfo->EventTextLength);
  }
  else
  {
    memcpy (RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
    RECHeaderInfo->EventDurationHour   = *( byte*)(&Buffer[p +  2]);
    RECHeaderInfo->EventDurationMin    = *( byte*)(&Buffer[p +  3]);
    RECHeaderInfo->EventEventID        =  getDword(&Buffer[p +  4], WrongEndian);
    RECHeaderInfo->EventStartTime      =  getDword(&Buffer[p +  8], WrongEndian);
    RECHeaderInfo->EventEndTime        =  getDword(&Buffer[p + 12], WrongEndian);
    RECHeaderInfo->EventRunningStatus  = *( byte*)(&Buffer[p + 16]);
    RECHeaderInfo->EventTextLength     = *( byte*)(&Buffer[p + 17]);
    RECHeaderInfo->EventParentalRate   = *( byte*)(&Buffer[p + 18]);
    memcpy (RECHeaderInfo->EventEventName, &Buffer[p + 19], RECHeaderInfo->EventTextLength);
    memcpy (RECHeaderInfo->EventEventDescription, &Buffer[p + 19 + RECHeaderInfo->EventTextLength], 273 - RECHeaderInfo->EventTextLength);
    RECHeaderInfo->EventServiceID      =  getWord(&Buffer[p + 276], WrongEndian);
    memcpy (RECHeaderInfo->EventUnknown2, &Buffer[p + 278], 10);
  }
}

void HDD_DecodeRECHeader_ExtendedEventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  //known: all
  p = OffsetExtEventInfo[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType == RHT_TMSs)
  {
    RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
    RECHeaderInfo->ExtEventTextLength  = getWord(&Buffer[p + 0x0002], WrongEndian);
    RECHeaderInfo->ExtEventEventID     = getDword(&Buffer[p + 0x0004], WrongEndian);
    memcpy (RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);
  }
  else
  {
    RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
    RECHeaderInfo->ExtEventTextLength  = getWord(&Buffer[p + 0x0002], WrongEndian);
    memcpy (RECHeaderInfo->ExtEventUnknown2, &Buffer[p + 0x0004], 2);
    RECHeaderInfo->ExtEventEventID     = getWord(&Buffer[p + 0x0006], WrongEndian);
    memcpy (RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);
  }
}

void HDD_DecodeRECHeader_CryptInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  //known: all
  p = OffsetCryptInfo[RECHeaderInfo->RECHeaderType];

  //The TMS crypt info is already included in the file header block
  if(RECHeaderInfo->RECHeaderType != RHT_TMSs)
  {
    memcpy (RECHeaderInfo->CryptReserved1, &Buffer[p], 4);
    RECHeaderInfo->CryptFlag =   *( byte*)(&Buffer[p + 0x0004]);
    memcpy (RECHeaderInfo->CryptReserved2, &Buffer[p + 0x0005], 3);
  }
}

void HDD_DecodeRECHeader_Bookmarks(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;

  //known: all
  p = OffsetBookmarks[RECHeaderInfo->RECHeaderType];

  if(RECHeaderInfo->RECHeaderType != RHT_TMSs)
  {
    memcpy (RECHeaderInfo->Bookmark, &Buffer[p], 64 * sizeof (dword));
    RECHeaderInfo->Resume = getDword(&Buffer[p + 0x0100], WrongEndian);
  }
  else
  {
    RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
    memcpy (RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
    RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
  }
}

eRECHeaderType HDD_DecodeRECHeader(char *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  memset (RECHeaderInfo, 0, sizeof (tRECHeaderInfo));
  RECHeaderInfo->HeaderType = ST_UNKNOWN;
  RECHeaderInfo->RECHeaderType = RHT_UNKNOWN;
  WrongEndian = FALSE;

  //Is this a REC header?
  RECHeaderInfo->HeaderMagic     = (Buffer[0] << 24) | (Buffer[1] << 16) | (Buffer[2] << 8) | Buffer[3];
  if (RECHeaderInfo->HeaderMagic != 0x54467263) return RECHeaderInfo->HeaderType;

  HDD_DecodeRECHeader_Header(Buffer, RECHeaderInfo);
  HDD_DecodeRECHeader_ServiceInfo(Buffer, RECHeaderInfo);
  HDD_DecodeRECHeader_TPInfo(Buffer, RECHeaderInfo);
  HDD_DecodeRECHeader_EventInfo(Buffer, RECHeaderInfo);
  HDD_DecodeRECHeader_ExtendedEventInfo(Buffer, RECHeaderInfo);
  HDD_DecodeRECHeader_CryptInfo(Buffer, RECHeaderInfo);
  HDD_DecodeRECHeader_Bookmarks(Buffer, RECHeaderInfo);

  return RECHeaderInfo->RECHeaderType;
}
