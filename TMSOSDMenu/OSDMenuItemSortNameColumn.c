#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMenuItemSortNameColumn(bool Ascending)
{
  int                   i, j, NrItems;
  tItem                *Menu1, *Menu2, TempItem;

  NrItems = Menu[CurrentMenuLevel].NrItems;

  for(i = 0; i < NrItems - 1; i++)
  {
    Menu1 = &Menu[CurrentMenuLevel].Item[i];
    for(j = i + 1; j < NrItems; j++)
    {
      Menu2 = &Menu[CurrentMenuLevel].Item[j];
      if((Ascending && strcmp(Menu1->Name, Menu2->Name) > 0) ||
         (!Ascending && strcmp(Menu1->Name, Menu2->Name) < 0))
      {
        memcpy(&TempItem, &Menu[CurrentMenuLevel].Item[i], sizeof(tItem));
        memcpy(&Menu[CurrentMenuLevel].Item[i], &Menu[CurrentMenuLevel].Item[j], sizeof(tItem));
        memcpy(&Menu[CurrentMenuLevel].Item[j], &TempItem, sizeof(tItem));
      }
    }
  }

  ListDirty = TRUE;
}
