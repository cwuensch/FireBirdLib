#include "FBLib_main.h"

#ifndef _TMS_

bool isMasterpiece (void)
{
  return FIS_fwUpdateMPVFD() != 0;
}

#endif
