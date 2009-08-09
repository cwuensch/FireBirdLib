#include "FBLib_av.h"
#include "../libFireBird.h"

#ifndef _TMS_

int GetPinStatus (void)
{
  int                   *p = (int*)FIS_vPinStatus();

  return (int)(p ? *p : -2);
}

#endif
