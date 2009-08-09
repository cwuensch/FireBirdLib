#include "FBLib_flash.h"

dword FlashFindEndOfServiceTableAddress(bool TVService)
{
#ifdef _TMS_
  TYPE_ServiceTMS       *TvSvc;
#else
  TYPE_Service          *TvSvc;
#endif

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0)) return 0;

#ifdef _TMS_
  if (TVService) TvSvc = (TYPE_ServiceTMS*)(FlashBlockOffset [TVServices] + 4);
            else TvSvc = (TYPE_ServiceTMS*)(FlashBlockOffset [RadioServices] + 4);
#else
  if (TVService) TvSvc = (TYPE_Service*)(FlashBlockOffset [TVServices] + 4);
            else TvSvc = (TYPE_Service*)(FlashBlockOffset [RadioServices] + 4);
#endif

  while ((TvSvc->TunerNum != 0) && (TvSvc->PMTPID != 0))
    TvSvc++;

#ifdef DEBUG_FIREBIRDLIB
  TAP_Print ("FireBirdLib: FindEndOfServiceTable @ 0x%8.8x\n", (dword) TvSvc);
#endif

  return (dword) TvSvc;
}
