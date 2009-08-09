#include "FBLib_flash.h"

#ifndef _TMS_


//This routine set a flag for every service for which the service name matches.
//The caller is responsible for initializing the flag array. Flags will be or-ed.
dword FlashFindServiceByUHF (char* UHFChannel, bool TVService, bool UseAUSChannelCoding, bool *FlagArray, dword *NewFlags)
{
  TYPE_Service          *TvSvc;
  dword                 FoundCount = 0;
  int                   ServiceIndex = 0;
  char                  UHFs [100];
  TYPE_TpInfoT          *TPInfo;

  if (NewFlags) *NewFlags = 0;
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0 || SystemType != ST_DVBT)) return 0;

  if (TVService) TvSvc = (TYPE_Service *) (FlashBlockOffset[TVServices] + 4);
  else (dword) TvSvc = (TYPE_Service *) (FlashBlockOffset[RadioServices] + 4);

  while (TvSvc->TunerNum != 0)
  {
    TPInfo = (TYPE_TpInfoT *) (FlashBlockOffset[Transponders] + 4 + 4 + sizeof(TYPE_TpInfoT) * TvSvc->TPIdx);
    if (UseAUSChannelCoding)
    {
      memset (UHFs, 0, sizeof(UHFs));
      if (TPInfo->ChannelNr > 0x0f) UHFs [0] = 48 + (TPInfo->ChannelNr >> 4);
      if ((TPInfo->ChannelNr & 0x0f) == 0x0a) UHFs [strlen (UHFs)] = 0x41;
      else UHFs [strlen (UHFs)] = 48 + (TPInfo->ChannelNr & 0x0f);
    }
    else TAP_SPrint (UHFs, "%d", TPInfo->ChannelNr);

    if (strcmp (UHFChannel, UHFs) == 0)
    {
      if (NewFlags && !FlagArray[ServiceIndex]) *NewFlags = *NewFlags + 1;
      FlagArray[ServiceIndex] = TRUE;
      FoundCount++;
    }
    TvSvc++;
    ServiceIndex++;
  }

  return FoundCount;
}

#endif
