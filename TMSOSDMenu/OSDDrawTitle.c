#include                "FBLib_TMSOSDMenu.h"

void OSDDrawTitle(void)
{
  OSDMenuPutS(OSDRgn, 53, 40, 658, Menu[CurrentMenuLevel].TitleLeft, RGB(230,230,250), COLOR_None, 20, FALSE, ALIGN_LEFT);
  OSDMenuPutS(OSDRgn, 53, 52, 658, Menu[CurrentMenuLevel].TitleRight, RGB(102,102,102), COLOR_None, 16, FALSE, ALIGN_RIGHT);
}
