#include                "FBLib_TMSOSDMenu.h"

void OSDDrawTitle(void)
{
  dword                 tw;

  OSDMenuPutS(OSDRgn, 53, 40, 658, Menu[CurrentMenuLevel].TitleLeft, RGB(230,230,250), COLOR_None, 20, FALSE, ALIGN_LEFT);
  tw = FM_GetStringWidth(Menu[CurrentMenuLevel].TitleLeft, &Calibri_20_FontData);

  OSDMenuPutS(OSDRgn, 53 + tw + 5, 52, 658, Menu[CurrentMenuLevel].TitleRight, RGB(102,102,102), COLOR_None, 16, TRUE, ALIGN_RIGHT);

  if(CallbackProcedure) CallbackProcedure(OSDCB_Title, OSDRgn);
}
