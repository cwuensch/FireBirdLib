#include                "FBLib_TMSOSDMenu.h"

int OSDMenuFindNextSelectableEntry(int CurrentSelection)
{
  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  if((CurrentSelection >= (pMenu->NrItems - 1)) && !pMenu->ScrollLoop) return -1;

  do
  {
    CurrentSelection++;
    if(CurrentSelection >= pMenu->NrItems)
    {
      if(pMenu->ScrollLoop)
        CurrentSelection = 0;
      else
        return -1;
    }
  } while(!pMenu->Item[CurrentSelection].Selectable);

  return CurrentSelection;
}
