#include "FBLib_flash.h"

#ifdef _TMS_

word FlashServiceAddressToServiceIndex(TYPE_ServiceTMS *ServiceAddress)
{
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0)) return 0;

  if ((dword) ServiceAddress >= FlashBlockOffset [RadioServices]) return (((dword) ServiceAddress - FlashBlockOffset [RadioServices]) / sizeof(TYPE_ServiceTMS));
                                                             else return (((dword) ServiceAddress - FlashBlockOffset [TVServices]) / sizeof(TYPE_ServiceTMS));
}

#endif
