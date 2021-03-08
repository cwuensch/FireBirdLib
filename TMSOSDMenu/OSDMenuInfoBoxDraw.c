#include                "FBLib_TMSOSDMenu.h"

void OSDMenuInfoBoxDraw(word rgn)
{
  if (rgn)
  {
    TAP_Osd_FillBox(rgn, 0,  0, INFOBOX_WIDTH, 36, RGB(32, 32, 32));
    TAP_Osd_FillBox(rgn, 0, 34, INFOBOX_WIDTH, INFOBOX_HEIGHT - 34, RGB(40, 40, 40));
    TAP_Osd_DrawRectangle(rgn, 0,  0, INFOBOX_WIDTH, 36,                  2, RGB(70, 70, 70));
    TAP_Osd_DrawRectangle(rgn, 0, 34, INFOBOX_WIDTH, INFOBOX_HEIGHT - 34, 2, RGB(70, 70, 70));
  }
}
