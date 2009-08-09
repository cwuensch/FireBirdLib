#include <string.h>
#include "FBLib_flash.h"

#ifdef _TMS_

TYPE_ServiceTMS *FlashGetServiceByName (char* ChannelName, bool TVService)
{
  TYPE_ServiceTMS       *Svc;
  char                  ServiceName[MAX_SvcName];

  if (!LibInitialized) InitTAPex();
  if (!LibInitialized || (FlashOffset == 0 || SystemType == ST_UNKNOWN)) return NULL;

  Svc = (TYPE_ServiceTMS *) (FlashBlockOffset[TVService ? TVServices : RadioServices] + 4);

  while (Svc->TunerNum)
  {
    strncpy(ServiceName, (char *) (FlashBlockOffset[ServiceNames] + 4 + Svc->NameOffset), MAX_SvcName);
    ServiceName[MAX_SvcName - 1] = '\0';

    if (strcasecmp(ChannelName, ServiceName) == 0 || strcasecmp(ChannelName, ValidFileName(ServiceName, NonPrintableChars)) == 0) return Svc;
    else Svc++;
  }

  return NULL;
}

#endif
