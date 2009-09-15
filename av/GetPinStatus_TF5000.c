#include "FBLib_av.h"
#include "../libFireBird.h"

#ifndef _TMS_

int GetPinStatus(void)
{
  int                  *p;
  int                   ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("GetPinStatus");
#endif

  p = (int*)FIS_vPinStatus();
  ret = (int)(p ? *p : -2);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}

#endif
