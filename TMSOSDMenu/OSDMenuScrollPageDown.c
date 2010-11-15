#include                "FBLib_TMSOSDMenu.h"

int OSDMenuScrollPageDown(void)
{
  tMenu                *pMenu;
  int                   ret, x;

  pMenu = &Menu[CurrentMenuLevel];

  if((pMenu->CurrentSelection == (pMenu->NrItems - 1)) && pMenu->ScrollLoop)
  {
    ret = OSDMenuFindNextSelectableEntry(-1);
  }
  else if(pMenu->CurrentSelection == (pMenu->CurrentTopIndex + 9))
  {
    x = pMenu->CurrentSelection + 10;
    if(x >= pMenu->NrItems) x = pMenu->NrItems - 1;
    ret = OSDMenuFindNextSelectableEntry(x - 1);
  }
  else
    ret = OSDMenuFindNextSelectableEntry(pMenu->CurrentTopIndex + 8);

  if(ret == -1) return -1;

  pMenu->CurrentSelection = ret;
  ListDirty = TRUE;

  return ret;
}
