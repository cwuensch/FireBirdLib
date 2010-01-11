#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuItemsClear(void)
{
  Menu[CurrentMenuLevel].NrItems = 0;
  ListDirty = TRUE;
}

#endif
