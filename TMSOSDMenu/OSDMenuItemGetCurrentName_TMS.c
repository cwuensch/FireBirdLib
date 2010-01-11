#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

char *OSDMenuItemGetCurrentName(void)
{
  return OSDMenuItemGetName(Menu[CurrentMenuLevel].CurrentSelection);
}

#endif
