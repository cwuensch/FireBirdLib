#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

int OSDMenuGetCurrentItem(void)
{
  return Menu[CurrentMenuLevel].CurrentSelection;
}

#endif
