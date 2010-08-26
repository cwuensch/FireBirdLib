#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDDrawMemo(void)
{
  int                   i;
  dword                 Y;
  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  //The background
  TAP_Osd_Draw3dBoxFill(OSDRgn, 60, 96, 600, 367, RGB(30, 30, 30), RGB(30, 30, 30), RGB(30, 30, 30));

  for(i = 0; i < 15; i++)
  {
    Y = 99 + (i * 24);

    //The text of the left column
    if((i + pMenu->CurrentTopIndex) < pMenu->NrItems)
      OSDMenuPutS(OSDRgn, 76, Y + 5, 645, pMenu->Item[i + pMenu->CurrentTopIndex].Name, RGB(255, 255, 255), COLOR_None, 14, TRUE, ALIGN_LEFT);
  }
}

#endif
