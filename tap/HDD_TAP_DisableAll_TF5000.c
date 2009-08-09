#include "FBLib_tap.h"

#ifndef _TMS_

dword HDD_TAP_DisableAll (bool DisableEvents)
{
  dword                 i, TAPID, count = 0;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  for (i = 0; i < TAP_MAX; i++)
  {
    if (i != TAP_TableIndex)
    {
      TAPID = HDD_TAP_GetIDByIndex (i);

      if (TAPID != 0)
      {
        if (!HDD_TAP_Disable(TAPID, DisableEvents)) count++;
      }
    }
  }

  return count;
}

#endif
