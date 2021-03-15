#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"
#include                "graphic/Progressbar.gd"
//extern TYPE_GrData      _Progressbar_Gd;

#define PROGRESSBARX    234
#define PROGRESSBARY    330

//word                    ProgressBarOSDRgn = 0;
word                    ProgressBarFullRgn = 0;
dword                   ProgressBarLastValue = 0xfff;


void OSDMenuProgressBarShow(const char *Title, const char *Text, dword Value, dword MaxValue, TYPE_GrData *DifferentProgressBar)
{
  const dword Color_Edge = RGB(160,160,160);

  TRACEENTER();

  if(Value != ProgressBarLastValue)
  {
    OSDMenuInfoBoxShow(Title, Text, 0x7fffffff);
    if(!ProgressBarOSDRgn)
    {
      ProgressBarOSDRgn = TAP_Osd_Create(PROGRESSBARX, PROGRESSBARY, _Progressbar_Gd.width, _Progressbar_Gd.height, 0, 0);
      ProgressBarFullRgn = TAP_Osd_Create(0, 0, _Progressbar_Gd.width, _Progressbar_Gd.height, 0, OSD_Flag_MemRgn);
    }
    TAP_Osd_PutGd(ProgressBarFullRgn, 0, 0, (DifferentProgressBar ? DifferentProgressBar : &_Progressbar_Gd), FALSE);
//    TAP_Osd_PutGd(ProgressBarOSDRgn, 0, 0, &_InputBox_Gd, FALSE);
    TAP_Osd_Draw3dBoxFill(ProgressBarOSDRgn, 0, 0, _Progressbar_Gd.width, _Progressbar_Gd.height, Color_Edge, COLOR_White, COLOR_White);
    TAP_Osd_PutPixel(ProgressBarOSDRgn, 0, _Progressbar_Gd.height - 2, Color_Edge);
    TAP_Osd_PutPixel(ProgressBarOSDRgn, _Progressbar_Gd.width - 2, 0, Color_Edge);
    TAP_Osd_Copy(ProgressBarFullRgn, ProgressBarOSDRgn, 0, 0, _Progressbar_Gd.width * Value / MaxValue, _Progressbar_Gd.height, 0, 0, FALSE);
    TAP_Osd_Sync();
    ProgressBarLastValue = Value;
  }

  TRACEEXIT();
}
