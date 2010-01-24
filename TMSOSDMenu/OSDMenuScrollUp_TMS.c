#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

int OSDMenuScrollUp(void)
{
  tMenu                *pMenu;
  int                   ret;

  pMenu = &Menu[CurrentMenuLevel];

  ret = OSDMenuFindPreviousSelectableEntry(pMenu->CurrentSelection);
  if(ret == -1) return -1;

  pMenu->CurrentSelection = ret;
  ListDirty = TRUE;

  return ret;
}

#endif