#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuPop(void)
{
  if(CurrentMenuLevel == 0) return FALSE;

  CurrentMenuLevel--;

  return TRUE;
}

#endif
