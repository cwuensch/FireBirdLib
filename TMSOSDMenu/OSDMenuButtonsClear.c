#include                "FBLib_TMSOSDMenu.h"

void OSDMenuButtonsClear(void)
{
  int                   i;

  Menu[CurrentMenuLevel].NrButtons = 0;
  for(i = 0; i < 4; i++)
    Menu[CurrentMenuLevel].ButtonXStart[i] = 55;

  ButtonsDirty = TRUE;
}
