#include "FBLib_tap.h"

#ifdef _TMS_

dword HDD_TAP_DisableAll (bool DisableEvents)
{
  dword                 i, TAPID, count = 0;

  for (i = 0; i < TAP_MAX; i++)
  {
    TAPID = HDD_TAP_GetIDByIndex(i);
    if((TAPID != 0) && (HDD_TAP_Disable(TAPID, DisableEvents))) count++;
  }

  return count;
}

#endif
