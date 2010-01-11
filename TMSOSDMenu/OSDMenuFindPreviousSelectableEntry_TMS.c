#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

int OSDMenuFindPreviousSelectableEntry(int CurrentSelection)
{
  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  if((CurrentSelection < 0) && !pMenu->ScrollLoop) return -1;

  do
  {
    CurrentSelection--;
    if(CurrentSelection < 0)
    {
      if(pMenu->ScrollLoop)
        CurrentSelection = pMenu->NrItems - 1;
      else
        return -1;
    }
  } while(!pMenu->Item[CurrentSelection].Selectable);

  return CurrentSelection;
}

#endif
