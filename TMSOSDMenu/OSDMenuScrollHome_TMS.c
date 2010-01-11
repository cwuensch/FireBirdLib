#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

int OSDMenuScrollHome(void)
{
  tMenu                *pMenu;
  int                   ret;

  pMenu = &Menu[CurrentMenuLevel];

  ret = OSDMenuFindNextSelectableEntry(-1);
  if(ret == -1) return -1;

  pMenu->CurrentSelection = ret;
  ListDirty = TRUE;

  return ret;
}

#endif
