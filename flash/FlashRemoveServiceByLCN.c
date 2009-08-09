#include "FBLib_flash.h"

dword FlashRemoveServiceByLCN (char* LCN, bool TVService)
{
  dword                 FoundCount = 0;
  bool                 *FlagArray;
  int                   i, nTvSvc, nRadioSvc;

  if (!LibInitialized) InitTAPex();
  if (!LibInitialized || (FlashOffset == 0 || SystemType == ST_UNKNOWN)) return 0;

  TAP_Channel_GetTotalNum(&nTvSvc, &nRadioSvc);
  if(!TVService) nTvSvc = nRadioSvc;

  if ((FlagArray = TAP_MemAlloc(nTvSvc * sizeof(bool))))
  {
    memset(FlagArray, 0, nTvSvc * sizeof(bool));
    FoundCount = FlashFindServiceByLCN(LCN, TVService, FlagArray, NULL);
    if (FoundCount)
    {
      for (i = nTvSvc - 1; i >= 0; i--)
        if (FlagArray[i])
          FlashRemoveServiceByIndex(i, TVService);
    }
    TAP_MemFree(FlagArray);
  }

  return FoundCount;
}
