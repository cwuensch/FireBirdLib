#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

char *OSDMenuItemGetName(int ItemIndex)
{
  if((ItemIndex < 0) || (ItemIndex >= Menu[CurrentMenuLevel].NrItems)) return NULL;

  return Menu[CurrentMenuLevel].Item[ItemIndex].Name;
}

#endif