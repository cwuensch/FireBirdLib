#include                "FBLib_TMSOSDMenu.h"
//#include                "graphic/WaitSpinner_All.gd"

//word                    WaitSpinnerRgn = 0;
int                     WaitSpinnerIndex = 0;
dword                   WaitSpinnerTimeout = 0;


void OSDMenuWaitSpinnerInit(void)
{
  TRACEENTER();

  if(InfoBoxOSDRgn && WaitSpinnerRgn == 0)
  {
    WaitSpinnerRgn = TAP_Osd_Create(0, 0, WaitSpinnerWidth, WaitSpinnerItemHeight, 0, OSD_Flag_MemRgn);

    if(WaitSpinnerRgn)
    {
      int i;

      TAP_Osd_FillBox(WaitSpinnerRgn, 0, 0, WaitSpinnerWidth, WaitSpinnerItemHeight, RGB(40, 40, 40));

      for (i = 0; i < WaitSpinnerItems; i++)
        OSDMenuWaitSpinnerDrawItem(WaitSpinnerRgn, i * WaitSpinnerItemWidth * 2, WaitSpinnerItemColorBlank);

      TAP_Osd_Copy(WaitSpinnerRgn, InfoBoxOSDRgn, 0, 0, WaitSpinnerWidth, WaitSpinnerItemHeight, (INFOBOX_WIDTH - WaitSpinnerWidth) >> 1, WaitSpinnerPosY, FALSE);
      TAP_Osd_Sync();

      WaitSpinnerIndex = 0;
      WaitSpinnerTimeout = TAP_GetTick() + WaitSpinnerSpeed;
    }
  }

  TRACEEXIT();
}
