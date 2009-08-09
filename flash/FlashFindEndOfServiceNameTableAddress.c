#include <string.h>
#include "FBLib_flash.h"

dword FlashFindEndOfServiceNameTableAddress (void)
{
  dword                 LastEntry = 0;

#ifdef _TMS_
  TYPE_ServiceTMS       *Svc;
#else
  TYPE_Service          *Svc;
#endif

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0)) return 0;

  //Find the highest service name table pointer in the TV services
#ifdef _TMS_
  Svc = (TYPE_ServiceTMS*)(FlashBlockOffset[TVServices] + 4);
#else
  Svc = (TYPE_Service*)(FlashBlockOffset[TVServices] + 4);
#endif

  while (Svc->TunerNum != 0)
  {
    if (Svc->NameOffset > LastEntry) LastEntry = Svc->NameOffset;
    Svc++;
  }

  //Repeat for all radio services
#ifdef _TMS_
  Svc = (TYPE_ServiceTMS*)(FlashBlockOffset[RadioServices] + 4);
#else
  Svc = (TYPE_Service*)(FlashBlockOffset[RadioServices] + 4);
#endif

  while (Svc->TunerNum != 0)
  {
    if (Svc->NameOffset > LastEntry) LastEntry = Svc->NameOffset;
    Svc++;
  }

  LastEntry = LastEntry + FlashBlockOffset[ServiceNames] + 4;
  LastEntry += strlen((char*)LastEntry);

  return LastEntry + 1;
}
