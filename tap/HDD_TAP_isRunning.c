#include "FBLib_tap.h"

bool HDD_TAP_isRunning (dword TAPID)
{

#ifndef _TMS_
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;
#endif

  return (HDD_TAP_GetIndexByID (TAPID) >= 0);

}
