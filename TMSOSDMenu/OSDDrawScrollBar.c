#include                "FBLib_TMSOSDMenu.h"

void OSDDrawScrollBar(void)
{
  TRACEENTER();

  tMenu                *pMenu;
  int                   n, Y;

  pMenu = &Menu[CurrentMenuLevel];

  if(pMenu->NrItems < pMenu->NrLines + 1)
  {
    TAP_Osd_PutGd(OSDRgn, 661, 96, &_ScrollBarInvisible_Gd, FALSE);
  }
  else
  {
    TAP_Osd_PutGd(OSDRgn, 661, 96, &_ScrollBarVisible_Gd, FALSE);
    n = (pMenu->OSDMenuDisplayMode == OMDM_Text ? pMenu->NrLines : 1);
    Y = 108 + (pMenu->CurrentSelection * 324) / (pMenu->NrItems - n);
    TAP_Osd_PutGd(OSDRgn, 662, Y, &_ScrollBarKnob_Gd, FALSE);
  }

  TRACEEXIT();
}
