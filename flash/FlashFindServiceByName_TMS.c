#include <string.h>
#include "FBLib_flash.h"

#ifdef _TMS_

//This routine set a flag for every service for which the service name matches.
//The caller is responsible for initializing the flag array. Flags will be or-ed.
dword FlashFindServiceByName(char* ChannelName, bool TVService, bool *FlagArray, dword *NewFlags)
{
  TYPE_ServiceTMS       *TvSvc;
  dword                 FoundCount = 0;
  int                   ServiceIndex = 0;
  char                  ServiceName [MAX_SvcName + 1];

  if (NewFlags) *NewFlags = 0;
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0 || SystemType == ST_UNKNOWN)) return 0;

  if (TVService) TvSvc = (TYPE_ServiceTMS *) (FlashBlockOffset[TVServices] + 4);
  else TvSvc = (TYPE_ServiceTMS *) (FlashBlockOffset[RadioServices] + 4);

  while (TvSvc->TunerNum != 0)
  {
    strncpy (ServiceName, (char *) (FlashBlockOffset [ServiceNames] + 4 + TvSvc->NameOffset), MAX_SvcName);
    ServiceName[MAX_SvcName - 1] = '\0';

    if (strcasecmp (ChannelName, ServiceName) == 0 || strcasecmp (ChannelName, ValidFileName (ServiceName, NonPrintableChars)) == 0)
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
