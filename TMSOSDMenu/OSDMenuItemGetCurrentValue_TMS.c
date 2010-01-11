#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

char *OSDMenuItemGetCurrentValue(void)
{
  return OSDMenuItemGetValue(Menu[CurrentMenuLevel].CurrentSelection);
}

#endif
