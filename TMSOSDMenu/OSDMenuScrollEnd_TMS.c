#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

int OSDMenuScrollEnd(void)
{
  tMenu                *pMenu;
  int                   ret;

  pMenu = &Menu[CurrentMenuLevel];

  ret = OSDMenuFindPreviousSelectableEntry(pMenu->NrItems);
  if(ret == -1) return -1;

  pMenu->CurrentSelection = ret;
  ListDirty = TRUE;

  return ret;
}

#endif
