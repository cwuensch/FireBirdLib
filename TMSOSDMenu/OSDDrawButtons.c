#include                "FBLib_TMSOSDMenu.h"

void OSDDrawButtons(void)
{
  tMenu                *pMenu;
  dword                 i;

  pMenu = &Menu[CurrentMenuLevel];

  for(i = 0; i < pMenu->NrButtons; i++)
  {
    TAP_Osd_PutGd(OSDRgn, pMenu->Buttons[i].X , pMenu->Buttons[i].Y, pMenu->Buttons[i].pButtonGd, TRUE);
    OSDMenuPutS(OSDRgn, pMenu->Buttons[i].X + pMenu->Buttons[i].pButtonGd->width, pMenu->Buttons[i].Y + 2, 670, pMenu->Buttons[i].Text, RGB(230, 230, 250), COLOR_None, 12, FALSE, ALIGN_LEFT);
  }
}
