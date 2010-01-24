#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDDrawScrollBar(void)
{
  int                   Y;

  if(Menu[CurrentMenuLevel].NrItems < 11)
  {
    TAP_Osd_PutGd(OSDRgn, 661, 95, &_ScrollBarInvisible_Gd, FALSE);
  }
  else
  {
    TAP_Osd_PutGd(OSDRgn, 661, 95, &_ScrollBarVisible_Gd, FALSE);
    Y = 108 + (Menu[CurrentMenuLevel].CurrentSelection * 321) / (Menu[CurrentMenuLevel].NrItems - 1);
    TAP_Osd_PutGd(OSDRgn, 662, Y, &_ScrollBarKnob_Gd, FALSE);
  }
}

#endif