#include "FBLib_flash.h"

#ifdef _TMS_

dword FlashRemoveServiceByIndex(int ChannelIndex, bool TVService)
{
  TYPE_ServiceTMS      *TvSvc, *TvSvcSource, *TvSvcDest;
  dword                 RemovedCount = 0;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0 || SystemType == ST_UNKNOWN)) return 0;

  if (TVService) TvSvc = (TYPE_ServiceTMS *) (FlashBlockOffset[TVServices] + 4 + sizeof(TYPE_ServiceTMS) * ChannelIndex);
            else TvSvc = (TYPE_ServiceTMS *) (FlashBlockOffset[RadioServices] + 4 + sizeof(TYPE_ServiceTMS) * ChannelIndex);

  if (TvSvc->TunerNum != 0)
  {
    RemovedCount++;
    TvSvcDest = TvSvc;
    TvSvcSource = TvSvc;
    TvSvcSource++;
    do
    {
      memcpy(TvSvcDest, TvSvcSource, sizeof(TYPE_ServiceTMS));
      TvSvcSource++;
      TvSvcDest++;
    } while (TvSvcDest->TunerNum != 0);

    //A channel has been removed, reindex the timer table
    FlashReindexTimers(ChannelIndex, (TVService ? SVC_TYPE_Tv : SVC_TYPE_Radio), delete);

    //Also re-index the favourites tables
    FlashReindexFavourites(ChannelIndex, (TVService ? SVC_TYPE_Tv : SVC_TYPE_Radio), delete);
  }

  return RemovedCount;
}

#endif
