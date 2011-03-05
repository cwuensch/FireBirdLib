#include                "FBLib_flash.h"

bool FlashServiceAdd(int SvcType, tFlashService *Service)
{
  int                   NrServices;
  word                 *nSvc;

  NrServices = FlashServiceGetTotal(SvcType);

  if(SvcType == SVC_TYPE_Tv)
    nSvc = (word*)TryResolve("_nTvSvc");
  else
    nSvc = (word*)TryResolve("_nRadioSvc");

  *nSvc = *nSvc + 1;

  return FlashServiceSetInfo(SvcType, NrServices, Service);
}
