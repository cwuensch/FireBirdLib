#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

dword OSDMenuItemGetNrOfItems(void)
{
  return Menu[CurrentMenuLevel].NrItems;
}

#endif
