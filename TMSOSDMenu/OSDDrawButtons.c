#include                "FBLib_TMSOSDMenu.h"

void OSDDrawButtons(void)
{
  tMenu                *pMenu;
  dword                 i;

  pMenu = &Menu[CurrentMenuLevel];

  for(i = 0; i < pMenu->NrButtons; i++)
  {
    TAP_Osd_PutGd(OSDRgn, pMenu->Buttons[i].X , pMenu->Buttons[i].Y, pMenu->Buttons[i].pButtonGd, TRUE);
    OSDMenuPutS(OSDRgn, pMenu->Buttons[i].X + pMenu->Buttons[i].pButtonGd->width + 2, pMenu->Buttons[i].Y + 3, 670, pMenu->Buttons[i].Text, pMenu->Buttons[i].Color, COLOR_None, 12, FALSE, ALIGN_LEFT);
  }

  if(CallbackProcedure) CallbackProcedure(OSDCB_Buttons, OSDRgn);
}
