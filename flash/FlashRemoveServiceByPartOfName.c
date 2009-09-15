#include                <string.h>
#include                "FBLib_flash.h"
#include                "../string/FBLib_string.h"

dword FlashRemoveServiceByPartOfName (char* ChannelName, bool TVService)
{
  dword                 FoundCount = 0;
  bool                 *FlagArray;
  int                   i, nTvSvc, nRadioSvc;

  if (!LibInitialized) InitTAPex();
  if (!LibInitialized || (FlashOffset == 0 || SystemType == ST_UNKNOWN)) return 0;

  TAP_Channel_GetTotalNum(&nTvSvc, &nRadioSvc);
  if(!TVService) nTvSvc = nRadioSvc;

  if ((FlagArray = TAP_MemAlloc_Chk("FlashRemoveServiceByPartOfName", nTvSvc * sizeof(bool))))
  {
    memset(FlagArray, 0, nTvSvc * sizeof(bool));
    FoundCount = FlashFindServiceByPartOfName(ChannelName, TVService, FlagArray, NULL);
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
