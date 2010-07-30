#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

int OSDMenuFindNextSelectableEntry(int CurrentSelection)
{
  tMenu                *pMenu;
  int                   i, Cnt;

  pMenu = &Menu[CurrentMenuLevel];

  if((CurrentSelection >= (pMenu->NrItems - 1)) && !pMenu->ScrollLoop) return -1;

  //Count the number of selectable EndMessageWin
  Cnt = 0;
  for(i = 0; i < pMenu->NrItems; i++)
  {
    if(pMenu->Item[i].Selectable) Cnt++;
  }
  if(Cnt == 0) return -1;

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

#endif
