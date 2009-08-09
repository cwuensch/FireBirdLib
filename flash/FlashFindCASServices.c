#include "FBLib_flash.h"

//This routine set a flag for every service which is marked as scrambled.
//The caller is responsible for initializing the flag array. Flags will be or-ed.
dword FlashFindCASServices(bool TVService, bool *FlagArray, dword *NewFlags)
{
#ifdef _TMS_
  TYPE_ServiceTMS      *TvSvc;
#else
  TYPE_Service         *TvSvc;
#endif

  int                   ServiceIndex = 0, FoundCount = 0;

  if (NewFlags) *NewFlags = 0;
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || !FlagArray || (FlashOffset == 0 || SystemType == ST_UNKNOWN)) return 0;

#ifdef _TMS_
  if (TVService) TvSvc = (TYPE_ServiceTMS *) (FlashBlockOffset[TVServices] + 4);
            else TvSvc = (TYPE_ServiceTMS *) (FlashBlockOffset[RadioServices] + 4);
#else
  if (TVService) TvSvc = (TYPE_Service *) (FlashBlockOffset[TVServices] + 4);
            else TvSvc = (TYPE_Service *) (FlashBlockOffset[RadioServices] + 4);
#endif

  while (TvSvc->TunerNum != 0)
  {
    if (TvSvc->CASFlag)
    {
      if (NewFlags && !FlagArray[ServiceIndex]) *NewFlags = *NewFlags + 1;
      FlagArray[ServiceIndex] = TRUE;
      FoundCount++;
    }
    ServiceIndex++;
    TvSvc++;
  }

  return FoundCount;
}
