#include "FBLib_tap.h"

#ifndef _TMS_

bool HDD_TAP_isRunning (dword TAPID)
{
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  return (HDD_TAP_GetIndexByID (TAPID) >= 0);
}

#endif
