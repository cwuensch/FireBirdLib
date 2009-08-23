#include                "FBLib_tmsvfd.h"

#ifdef _TMS_

bool VFD_isInUseByTAP(void)
{
  return VFDUsedByTAP;
}

#endif
