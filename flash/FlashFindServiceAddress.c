#include "FBLib_flash.h"

dword FlashFindServiceAddress(word ServiceID, word PMTPID, word PCRPID, bool TVService)
{
#ifdef _TMS_
  TYPE_ServiceTMS       *TvSvc;
#else
  TYPE_Service          *TvSvc;
#endif

  if (!LibInitialized) InitTAPex();
  if (!LibInitialized || (FlashOffset == 0)) return 0;

#ifdef DEBUG_FIREBIRDLIB
  TAP_Print ("FireBirdLib: FindService   : SVDID=%5d, PMTPID=%5d, PCRPID=%5d ", ServiceID, PMTPID, PCRPID);
#endif

#ifdef _TMS_
  if (TVService) TvSvc = (TYPE_ServiceTMS*)(FlashBlockOffset[TVServices] + 4);
            else TvSvc = (TYPE_ServiceTMS*)(FlashBlockOffset[RadioServices] + 4);
#else
  if (TVService) TvSvc = (TYPE_Service*)(FlashBlockOffset[TVServices] + 4);
            else TvSvc = (TYPE_Service*)(FlashBlockOffset[RadioServices] + 4);
#endif

  do
  {
    if ((TvSvc->SVCID == ServiceID) && (TvSvc->PMTPID == PMTPID) && (TvSvc->PCRPID == PCRPID)) break;
    TvSvc++;
  } while ((TvSvc->TunerNum != 0) && (TvSvc->PMTPID != 0));

  if ((TvSvc->TunerNum == 0) || (TvSvc->PMTPID == 0))
  {

#ifdef _TMS_
    TvSvc = (TYPE_ServiceTMS*)0;
#else
    TvSvc = (TYPE_Service*)0;
#endif

#ifdef DEBUG_FIREBIRDLIB
    TAP_Print ("not found.\n");
#endif

  }

#ifdef DEBUG_FIREBIRDLIB
  else TAP_Print ("@ 0x%8.8x\n", (dword) (dword) TvSvc);
#endif

  return (dword)TvSvc;
}
