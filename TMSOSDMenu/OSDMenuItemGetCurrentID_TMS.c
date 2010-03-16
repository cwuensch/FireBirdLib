#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

dword OSDMenuItemGetCurrentID(void)
{
  return OSDMenuItemGetID(Menu[CurrentMenuLevel].CurrentSelection);
}

#endif
