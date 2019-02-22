#include                "FBLib_TMSOSDMenu.h"

void OSDDrawScrollBar(void)
{
  TRACEENTER();

  int                   n, Y;

  if(Menu[CurrentMenuLevel].NrItems < Menu[CurrentMenuLevel].NrLines + 1)
  {
    TAP_Osd_PutGd(OSDRgn, 661, 96, &_ScrollBarInvisible_Gd, FALSE);
  }
  else
  {
    TAP_Osd_PutGd(OSDRgn, 661, 96, &_ScrollBarVisible_Gd, FALSE);
    n = (Menu[CurrentMenuLevel].OSDMenuDisplayMode == OMDM_Text ? Menu[CurrentMenuLevel].NrLines : 1);
    Y = 108 + (Menu[CurrentMenuLevel].CurrentSelection * 324) / (Menu[CurrentMenuLevel].NrItems - n);
    TAP_Osd_PutGd(OSDRgn, 662, Y, &_ScrollBarKnob_Gd, FALSE);
  }

  TRACEEXIT();
}
