#include <string.h>
#include "FBLib_rec.h"

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

void HDD_DecodeRECHeader_ST_S(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  TPFlags1;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderSvcNumber = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->HeaderSvcType   = getWord(&Buffer[p + 0x000c], WrongEndian);

  //Service Info
  p = 0x000e;
  RECHeaderInfo->SISatIndex  =  Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType = Buffer[p + 0x0001];
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
  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  //Transponder Info
  p = 0x0034;
  RECHeaderInfo->TPSatIndex           = Buffer[p + 0];
  TPFlags1                            = Buffer[p + 1];
  RECHeaderInfo->TPPolarization       =  TPFlags1 >> 7;
  RECHeaderInfo->TPMode               = (TPFlags1 >> 4) & 7;
  memcpy(RECHeaderInfo->TPUnknown3, &Buffer[p + 2], 2);
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->TPSymbolRate         = getWord(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer[p + 10], WrongEndian);
  memcpy(RECHeaderInfo->TPUnknown5, &Buffer[p + 12], 2);
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 14], WrongEndian);

  //Event Info
  p = 0x0044;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  2];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  3];
  RECHeaderInfo->EventEventID        =  getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->EventStartTime      =  getDword(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->EventEndTime        =  getDword(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 16];
  EventTextLength                    = Buffer[p + 17];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 18];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 19], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 19 + EventTextLength], 273 - EventTextLength);
  RECHeaderInfo->EventServiceID      =  getWord(&Buffer[p + 276], WrongEndian);
  memcpy(RECHeaderInfo->EventUnknown2, &Buffer[p + 278], 10);

  //Extended Event Info
  p = 0x0168;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  memcpy(RECHeaderInfo->ExtEventUnknown2, &Buffer[p + 0x0004], 2);
  RECHeaderInfo->ExtEventEventID     = getWord(&Buffer[p + 0x0006], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info
  p = 0x0570;
  memcpy(RECHeaderInfo->CryptReserved1, &Buffer[p], 4);
  RECHeaderInfo->CryptFlag = Buffer[p + 0x0004];
  memcpy(RECHeaderInfo->CryptReserved2, &Buffer[p + 0x0005], 3);

  //Bookmarks
  p = 0x0578;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy (RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_T(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderSvcNumber = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->HeaderSvcType   = getWord(&Buffer[p + 0x000c], WrongEndian);

  //Service Info
  p = 0x000e;
  RECHeaderInfo->SISatIndex  =  Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType =  Buffer[p + 0x0001];
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
  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  //Transponder Info
  p = 0x0034;
  RECHeaderInfo->TPChannelNumber      = getWord(&Buffer[p +  0], WrongEndian);
  RECHeaderInfo->TPBandwidth          = Buffer[p +  2];
  RECHeaderInfo->TPUnknown2           = Buffer[p +  3];
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->TPLPHPStream         = Buffer[p + 10];
  RECHeaderInfo->TPUnknown4           = Buffer[p + 11];
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->TPNetworkID          = getWord(&Buffer[p + 14], WrongEndian);

  //Event Info
  p = 0x0044;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  2];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  3];
  RECHeaderInfo->EventEventID        =  getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->EventStartTime      =  getDword(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->EventEndTime        =  getDword(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 16];
  EventTextLength                    = Buffer[p + 17];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 18];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 19], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 19 + EventTextLength], 273 - EventTextLength);
  RECHeaderInfo->EventServiceID      =  getWord(&Buffer[p + 276], WrongEndian);
  memcpy(RECHeaderInfo->EventUnknown2, &Buffer[p + 278], 10);

  //Extended Event Info
  p = 0x0168;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  memcpy(RECHeaderInfo->ExtEventUnknown2, &Buffer[p + 0x0004], 2);
  RECHeaderInfo->ExtEventEventID     = getWord(&Buffer[p + 0x0006], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info
  p = 0x0570;
  memcpy(RECHeaderInfo->CryptReserved1, &Buffer[p], 4);
  RECHeaderInfo->CryptFlag = Buffer[p + 0x0004];
  memcpy(RECHeaderInfo->CryptReserved2, &Buffer[p + 0x0005], 3);

  //Bookmarks
  p = 0x0578;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy(RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_C(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderSvcNumber = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->HeaderSvcType   = getWord(&Buffer[p + 0x000c], WrongEndian);

  //Service Info
  p = 0x000e;
  RECHeaderInfo->SISatIndex  =  Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType = Buffer[p + 0x0001];
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
  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  //Transponder Info
  p = 0x0034;
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  0], WrongEndian);
  RECHeaderInfo->TPSymbolRate         = getWord(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer[p +  6], WrongEndian);
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->TPModulation         = Buffer[p + 10];
  RECHeaderInfo->TPUnknown6           = Buffer[p + 11];

  //Event Info
  p = 0x0040;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  2];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  3];
  RECHeaderInfo->EventEventID        = getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->EventStartTime      = getDword(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->EventEndTime        = getDword(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 16];
  EventTextLength                    = Buffer[p + 17];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 18];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 19], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 19 + EventTextLength], 273 - EventTextLength);
  RECHeaderInfo->EventServiceID      =  getWord(&Buffer[p + 276], WrongEndian);
  memcpy(RECHeaderInfo->EventUnknown2, &Buffer[p + 278], 10);

  //Extended Event Info
  p = 0x0164;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  memcpy(RECHeaderInfo->ExtEventUnknown2, &Buffer[p + 0x0004], 2);
  RECHeaderInfo->ExtEventEventID     = getWord(&Buffer[p + 0x0006], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info
  p = 0x056c;
  memcpy(RECHeaderInfo->CryptReserved1, &Buffer[p], 4);
  RECHeaderInfo->CryptFlag = Buffer[p + 0x0004];
  memcpy(RECHeaderInfo->CryptReserved2, &Buffer[p + 0x0005], 3);

  //Bookmarks
  p = 0x0574;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy(RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_T5700(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderSvcNumber = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->HeaderSvcType   = getWord(&Buffer[p + 0x000c], WrongEndian);

  //Service Info
  p = 0x000e;
  RECHeaderInfo->SISatIndex  = Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType = Buffer[p + 0x0001];
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
  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  //Transponder Info
  p = 0x0038;
  RECHeaderInfo->TPChannelNumber      = getWord(&Buffer[p +  0], WrongEndian);
  RECHeaderInfo->TPBandwidth          = Buffer[p +  2];
  RECHeaderInfo->TPUnknown2           = Buffer[p +  3];
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->TPLPHPStream         = Buffer[p + 10];
  RECHeaderInfo->TPUnknown4           = Buffer[p + 11];
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->TPNetworkID          = getWord(&Buffer[p + 14], WrongEndian);
  memcpy(RECHeaderInfo->TPUnknown7, &Buffer[p + 16], 8);

  //Event Info
  p = 0x0050;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  2];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  3];
  RECHeaderInfo->EventEventID        =  getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->EventStartTime      =  getDword(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->EventEndTime        =  getDword(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 16];
  EventTextLength                    = Buffer[p + 17];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 18];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 19], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 19 + EventTextLength], 273 - EventTextLength);
  RECHeaderInfo->EventServiceID      =  getWord(&Buffer[p + 276], WrongEndian);
  memcpy(RECHeaderInfo->EventUnknown2, &Buffer[p + 278], 10);

  //Extended Event Info
  p = 0x0174;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  memcpy(RECHeaderInfo->ExtEventUnknown2, &Buffer[p + 0x0004], 2);
  RECHeaderInfo->ExtEventEventID     = getWord(&Buffer[p + 0x0006], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info
  p = 0x057c;
  memcpy(RECHeaderInfo->CryptReserved1, &Buffer[p], 4);
  RECHeaderInfo->CryptFlag = Buffer[p + 0x0004];
  memcpy(RECHeaderInfo->CryptReserved2, &Buffer[p + 0x0005], 3);

  //Bookmarks
  p = 0x0584;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy(RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_TUK(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderSvcNumber = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->HeaderSvcType   = getWord(&Buffer[p + 0x000c], WrongEndian);

  //Service Info
  p = 0x000e;
  RECHeaderInfo->SISatIndex  = Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType = Buffer[p + 0x0001];
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
  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 28);

  //Transponder Info
  p = 0x0038;
  RECHeaderInfo->TPChannelNumber      = getWord(&Buffer[p +  0], WrongEndian);
  RECHeaderInfo->TPBandwidth          = Buffer[p +  2];
  RECHeaderInfo->TPUnknown2           = Buffer[p +  3];
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->TPLPHPStream         = Buffer[p + 10];
  RECHeaderInfo->TPUnknown4           = Buffer[p + 11];
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->TPNetworkID          = getWord(&Buffer[p + 14], WrongEndian);

  //Event Info
  p = 0x0048;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  2];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  3];
  RECHeaderInfo->EventEventID        =  getDword(&Buffer[p +  4], WrongEndian);
  RECHeaderInfo->EventStartTime      =  getDword(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->EventEndTime        =  getDword(&Buffer[p + 12], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 16];
  EventTextLength                    = Buffer[p + 17];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 18];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 19], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 19 + EventTextLength], 273 - EventTextLength);
  RECHeaderInfo->EventServiceID      =  getWord(&Buffer[p + 276], WrongEndian);
  memcpy(RECHeaderInfo->EventUnknown2, &Buffer[p + 278], 10);

  //Extended Event Info
  p = 0x016c;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  memcpy(RECHeaderInfo->ExtEventUnknown2, &Buffer[p + 0x0004], 2);
  RECHeaderInfo->ExtEventEventID     = getWord(&Buffer[p + 0x0006], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info
  p = 0x0574;
  memcpy(RECHeaderInfo->CryptReserved1, &Buffer[p], 4);
  RECHeaderInfo->CryptFlag = Buffer[p + 0x0004];
  memcpy(RECHeaderInfo->CryptReserved2, &Buffer[p + 0x0005], 3);

  //Bookmarks
  p = 0x057c;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy(RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_TMSS(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  Flags;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderStartTime = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->HeaderDurationSec  = getWord(&Buffer[p + 0x000e], WrongEndian);
  RECHeaderInfo->CryptFlag   = Buffer[p + 0x0010] & 0x03;
  RECHeaderInfo->HeaderFlags = Buffer[p + 0x0010] & 0xfc;
  RECHeaderInfo->HeaderCopyFlag = Buffer[p + 0x0011] & 0x80;
  RECHeaderInfo->HeaderFlags2 = Buffer[p + 0x0011] & 0x7f;
  memcpy(RECHeaderInfo->HeaderUnknown4, &Buffer[p + 0x0012], 10);

  //Service Info
  p = 0x001c;
  RECHeaderInfo->SISatIndex    =  Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType =  Buffer[p + 0x0001];

  Flags = getWord(&Buffer[p +0x0002], WrongEndian);
  RECHeaderInfo->SITPIdx     =  Flags & 0x3ff;
  RECHeaderInfo->SITunerNum  = (Flags >> 10) & 3;
  RECHeaderInfo->SIDelFlag   = (Flags >> 12) & 1;
  RECHeaderInfo->SICASFlag   = (Flags >> 13) & 1;
  RECHeaderInfo->SILockFlag  = (Flags >> 14) & 1;
  RECHeaderInfo->SISkipFlag  =  Flags >> 15;

  RECHeaderInfo->SIServiceID = getWord(&Buffer[p + 0x0004], WrongEndian);
  RECHeaderInfo->SIPMTPID    = getWord(&Buffer[p + 0x0006], WrongEndian);
  RECHeaderInfo->SIPCRPID    = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->SIVideoPID  = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->SIAudioPID  = getWord(&Buffer[p + 0x000c], WrongEndian);

  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  RECHeaderInfo->SIVideoStreamType = Buffer[p + 0x0026];
  RECHeaderInfo->SIAudioStreamType = Buffer[p + 0x0027];

  //Transponder info
  p = 0x0570;
  memcpy(RECHeaderInfo->TPUnknown1, &Buffer[p + 0], 4);
  RECHeaderInfo->TPSatIndex           = Buffer[p +  4];

  Flags                               = getWord(&Buffer[p +  5], WrongEndian);
  RECHeaderInfo->TPPolarization       =  Flags & 0x01;
  RECHeaderInfo->TPMode               = (Flags >>  1) & 0x07;
  RECHeaderInfo->TPSystem             = (Flags >>  4) & 0x01;
  RECHeaderInfo->TPModulation         = (Flags >>  5) & 0x03;
  RECHeaderInfo->TPFEC                = (Flags >>  7) & 0x0f;
  RECHeaderInfo->TPPilot              = (Flags >> 11) & 0x01;

  RECHeaderInfo->TPUnknown2           = Buffer[p + 7];
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p +  8], WrongEndian);
  RECHeaderInfo->TPSymbolRate         = getWord(&Buffer  [p + 12], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer  [p + 14], WrongEndian);

  RECHeaderInfo->TPFlags2             = getWord(&Buffer  [p + 16], WrongEndian);
  RECHeaderInfo->TPClockSync          = RECHeaderInfo->TPFlags2 & 0x0001;
  RECHeaderInfo->TPFlags2             = RECHeaderInfo->TPFlags2 & 0xfffe;

  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 18], WrongEndian);

  //Event Info
  p = 0x0044;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  3];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  2];
  RECHeaderInfo->EventEventID        = getDword(&Buffer[p + 0x0004], WrongEndian);
  RECHeaderInfo->EventStartTime      = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->EventEndTime        = getDword(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 0x0010];
  EventTextLength                    = Buffer[p + 0x0011];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 0x0012];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 0x0013], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 0x0013 + EventTextLength], 273 - EventTextLength);

  //Extended Event Info
  p = 0x0168;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  RECHeaderInfo->ExtEventEventID     = getDword(&Buffer[p + 0x0004], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info: see header flags

  //Bookmarks
  p = 0x0584;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy (RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_TMST(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  Flags;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderStartTime = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->HeaderDurationSec  = getWord(&Buffer[p + 0x000e], WrongEndian);

  RECHeaderInfo->CryptFlag = Buffer[p + 0x0010] & 0x03;
  RECHeaderInfo->HeaderFlags = Buffer[p + 0x0010] & 0xfc;

  RECHeaderInfo->HeaderCopyFlag = Buffer[p + 0x0011] & 0x80;
  RECHeaderInfo->HeaderFlags2 = Buffer[p + 0x0011] & 0x7f;

  memcpy(RECHeaderInfo->HeaderUnknown4, &Buffer[p + 0x0012], 10);

  //Service Info
  p = 0x001c;
  RECHeaderInfo->SISatIndex    =  Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType =  Buffer[p + 0x0001];

  Flags = getWord(&Buffer[p +0x0002], WrongEndian);
  RECHeaderInfo->SITPIdx     =  Flags & 0x3ff;
  RECHeaderInfo->SITunerNum  = (Flags >> 10) & 3;
  RECHeaderInfo->SIDelFlag   = (Flags >> 12) & 1;
  RECHeaderInfo->SICASFlag   = (Flags >> 13) & 1;
  RECHeaderInfo->SILockFlag  = (Flags >> 14) & 1;
  RECHeaderInfo->SISkipFlag  =  Flags >> 15;

  RECHeaderInfo->SIServiceID = getWord(&Buffer[p + 0x0004], WrongEndian);
  RECHeaderInfo->SIPMTPID    = getWord(&Buffer[p + 0x0006], WrongEndian);
  RECHeaderInfo->SIPCRPID    = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->SIVideoPID  = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->SIAudioPID  = getWord(&Buffer[p + 0x000c], WrongEndian);

  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  RECHeaderInfo->SIVideoStreamType = Buffer[p + 0x0026];
  RECHeaderInfo->SIAudioStreamType = Buffer[p + 0x0027];

  //Transponder info
  p = 0x0570;
  memcpy(RECHeaderInfo->TPUnknown1, &Buffer[p + 0x0000], 4);
  RECHeaderInfo->TPSatIndex      = Buffer[p + 0x0004];
  RECHeaderInfo->TPChannelNumber = Buffer[p + 0x0005];
  RECHeaderInfo->TPBandwidth     = Buffer[p + 0x0006];
  RECHeaderInfo->TPUnknown2      = Buffer[p + 0x0007];
  RECHeaderInfo->TPFrequency     = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->TPTSID          = getWord(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->TPLPHPStream    = Buffer[p + 0x000e];
  RECHeaderInfo->TPUnknown4      = Buffer[p + 0x000f];
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 0x0010], WrongEndian);
  RECHeaderInfo->TPNetworkID     = getWord(&Buffer[p + 0x0012], WrongEndian);

  //Event Info
  p = 0x0044;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  3];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  2];
  RECHeaderInfo->EventEventID        = getDword(&Buffer[p + 0x0004], WrongEndian);
  RECHeaderInfo->EventStartTime      = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->EventEndTime        = getDword(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 0x0010];
  EventTextLength                    = Buffer[p + 0x0011];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 0x0012];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 0x0013], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 0x0013 + EventTextLength], 273 - EventTextLength);

  //Extended Event Info
  p = 0x0168;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  RECHeaderInfo->ExtEventEventID     = getDword(&Buffer[p + 0x0004], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Crypt Info: see header

  //Bookmarks
  p = 0x0584;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy (RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

void HDD_DecodeRECHeader_ST_TMSC(byte *Buffer, tRECHeaderInfo *RECHeaderInfo)
{
  dword                 p;
  word                  Flags;
  byte                  EventTextLength;
  word                  ExtEventTextLength;

  //Header
  p = 0;
  memcpy(RECHeaderInfo->HeaderUnknown2, &Buffer[p + 6], 2);
  RECHeaderInfo->HeaderStartTime = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->HeaderDuration  = getWord(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->HeaderDurationSec  = getWord(&Buffer[p + 0x000e], WrongEndian);
  RECHeaderInfo->CryptFlag   = Buffer[p + 0x0010] & 0x03;
  RECHeaderInfo->HeaderFlags = Buffer[p + 0x0010] & 0xfc;
  RECHeaderInfo->HeaderCopyFlag = Buffer[p + 0x0011] & 0x80;
  RECHeaderInfo->HeaderFlags2 = Buffer[p + 0x0011] & 0x7f;
  memcpy(RECHeaderInfo->HeaderUnknown4, &Buffer[p + 0x0012], 10);

  //Service Info
  p = 0x001c;
  RECHeaderInfo->SISatIndex    =  Buffer[p + 0x0000];
  RECHeaderInfo->SIServiceType =  Buffer[p + 0x0001];

  Flags = getWord(&Buffer[p +0x0002], WrongEndian);
  RECHeaderInfo->SITPIdx     =  Flags & 0x3ff;
  RECHeaderInfo->SITunerNum  = (Flags >> 10) & 3;
  RECHeaderInfo->SIDelFlag   = (Flags >> 12) & 1;
  RECHeaderInfo->SICASFlag   = (Flags >> 13) & 1;
  RECHeaderInfo->SILockFlag  = (Flags >> 14) & 1;
  RECHeaderInfo->SISkipFlag  =  Flags >> 15;

  RECHeaderInfo->SIServiceID = getWord(&Buffer[p + 0x0004], WrongEndian);
  RECHeaderInfo->SIPMTPID    = getWord(&Buffer[p + 0x0006], WrongEndian);
  RECHeaderInfo->SIPCRPID    = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->SIVideoPID  = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->SIAudioPID  = getWord(&Buffer[p + 0x000c], WrongEndian);

  strncpy(RECHeaderInfo->SISvcName, &Buffer[p + 0x000e], 24);

  RECHeaderInfo->SIVideoStreamType = Buffer[p + 0x0026];
  RECHeaderInfo->SIAudioStreamType = Buffer[p + 0x0027];

  //Event Info
  p = 0x0044;
  memcpy(RECHeaderInfo->EventUnknown1, &Buffer[p], 2);
  RECHeaderInfo->EventDurationHour   = Buffer[p +  3];
  RECHeaderInfo->EventDurationMin    = Buffer[p +  2];
  RECHeaderInfo->EventEventID        = getDword(&Buffer[p + 0x0004], WrongEndian);
  RECHeaderInfo->EventStartTime      = getDword(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->EventEndTime        = getDword(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->EventRunningStatus  = Buffer[p + 0x0010];
  EventTextLength                    = Buffer[p + 0x0011];
  RECHeaderInfo->EventParentalRate   = Buffer[p + 0x0012];
  strncpy(RECHeaderInfo->EventEventName, &Buffer[p + 0x0013], EventTextLength);
  strncpy(RECHeaderInfo->EventEventDescription, &Buffer[p + 0x0013 + EventTextLength], 273 - EventTextLength);

  //Extended Event Info
  p = 0x0168;
  RECHeaderInfo->ExtEventServiceID   = getWord(&Buffer[p + 0x0000], WrongEndian);
  ExtEventTextLength                 = getWord(&Buffer[p + 0x0002], WrongEndian);
  RECHeaderInfo->ExtEventEventID     = getDword(&Buffer[p + 0x0004], WrongEndian);
  strncpy(RECHeaderInfo->ExtEventText, &Buffer[p + 0x0008], 1024);

  //Transponder info
  p = 0x0570;
  memcpy(RECHeaderInfo->TPUnknown1, &Buffer[p + 0x0000], 4);
  RECHeaderInfo->TPFrequency          = getDword(&Buffer[p + 0x0004], WrongEndian) >> 8;
  RECHeaderInfo->TPSymbolRate         = getWord(&Buffer[p + 0x0008], WrongEndian);
  RECHeaderInfo->TPTSID               = getWord(&Buffer[p + 0x000a], WrongEndian);
  RECHeaderInfo->TPOriginalNetworkID  = getWord(&Buffer[p + 0x000c], WrongEndian);
  RECHeaderInfo->TPModulation         = Buffer[p + 0x000e];
  RECHeaderInfo->TPUnknown6           = Buffer[p + 0x000f];

  //Crypt Info: see header flags

  //Bookmarks
  p = 0x0580;
  RECHeaderInfo->NrBookmarks = getDword(&Buffer[p + 0x0000], WrongEndian);
  memcpy (RECHeaderInfo->Bookmark, &Buffer[p + 0x0004], 177 * sizeof (dword));
  RECHeaderInfo->Resume = getDword(&Buffer[p + 0x02c8], WrongEndian);
}

bool HDD_DecodeRECHeader(byte *Buffer, tRECHeaderInfo *RECHeaderInfo, SYSTEM_TYPE SystemType)
{
  if(SystemType == ST_UNKNOWN) SystemType = GetSystemType();

  memset (RECHeaderInfo, 0, sizeof (tRECHeaderInfo));

  //Is this a REC header?
  RECHeaderInfo->HeaderMagic     = (Buffer[0] << 24) | (Buffer[1] << 16) | (Buffer[2] << 8) | Buffer[3];
  if (RECHeaderInfo->HeaderMagic != 0x54467263) return FALSE;

  RECHeaderInfo->HeaderVersion = getWord(&Buffer[4], FALSE);

  //Check the endianess of the file
  WrongEndian = (RECHeaderInfo->HeaderVersion == 0x0050) || (RECHeaderInfo->HeaderVersion == 0x1050) || (RECHeaderInfo->HeaderVersion == 0x0080);
  if(WrongEndian) RECHeaderInfo->HeaderVersion = getWord(&Buffer[4], TRUE);

  switch(SystemType)
  {
    case ST_UNKNOWN:  return FALSE;
    case ST_S:        HDD_DecodeRECHeader_ST_S(Buffer, RECHeaderInfo); break;
    case ST_ST:       return FALSE;
    case ST_T:        HDD_DecodeRECHeader_ST_T(Buffer, RECHeaderInfo); break;
    case ST_C:        HDD_DecodeRECHeader_ST_C(Buffer, RECHeaderInfo); break;
    case ST_CT:       return FALSE;
    case ST_T5700:    HDD_DecodeRECHeader_ST_T5700(Buffer, RECHeaderInfo); break;
    case ST_TUK:      HDD_DecodeRECHeader_ST_TUK(Buffer, RECHeaderInfo); break;
    case ST_TMSS:     HDD_DecodeRECHeader_ST_TMSS(Buffer, RECHeaderInfo); break;
    case ST_TMST:     HDD_DecodeRECHeader_ST_TMST(Buffer, RECHeaderInfo); break;
    case ST_TMSC:     HDD_DecodeRECHeader_ST_TMSC(Buffer, RECHeaderInfo); break;

    case ST_NRTYPES: break;
  }

  return TRUE;
}
