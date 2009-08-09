#include "FBLib_flash.h"

#ifdef _TMS_

TYPE_ServiceTMS *FlashGetServiceByIndex (word ServiceIdx, bool TVService)
{
  TYPE_ServiceTMS      *Svc;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0)) return NULL;

  if (TVService) Svc = (TYPE_ServiceTMS *) (FlashBlockOffset[TVServices] + 4 + ServiceIdx * sizeof(TYPE_ServiceTMS));
            else Svc = (TYPE_ServiceTMS *) (FlashBlockOffset[RadioServices] + 4 + ServiceIdx * sizeof(TYPE_ServiceTMS));

  return ((dword) Svc >= FlashFindEndOfServiceTableAddress(TVService) ? NULL : Svc);
}

#endif
