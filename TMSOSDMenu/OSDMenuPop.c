#include                "FBLib_TMSOSDMenu.h"

bool OSDMenuPop(void)
{
  if(CurrentMenuLevel == 0) return FALSE;

  CurrentMenuLevel--;

  return TRUE;
}
