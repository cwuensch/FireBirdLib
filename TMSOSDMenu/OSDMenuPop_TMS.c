#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuPop(void)
{
  if(CurrentMenuLevel == 0) return FALSE;

  TAP_MemFree(Menu[CurrentMenuLevel].Item);

  CurrentMenuLevel--;

  return TRUE;
}

#endif
