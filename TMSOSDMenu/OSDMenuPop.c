#include                "FBLib_TMSOSDMenu.h"

bool OSDMenuPop(void)
{
  if(CurrentMenuLevel == 0) return FALSE;

  TAP_MemFree(Menu[CurrentMenuLevel].Item);

  CurrentMenuLevel--;

  return TRUE;
}
