#include                "FBLib_dialog.h"

void DrawProgressBarBar(int Value, dword BarColor)
{
  int                   Perc;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DrawProgressBarBar");
#endif

  if (!FBDialogProgressBar || !FBDialogProfile || !FBDialogProgressBar->MemOSDRgn || !FBDialogProgressBar->OSDRgn)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  if (FBDialogProgressBar->Max == FBDialogProgressBar->Min) Perc = PROGRESSBARWIDTH;
  else Perc = (Value - FBDialogProgressBar->Min) * PROGRESSBARWIDTH / (FBDialogProgressBar->Max - FBDialogProgressBar->Min);

  if (Perc < 0) Perc = 0;
  if (Perc > PROGRESSBARWIDTH) Perc = PROGRESSBARWIDTH;

  if ((FBDialogProgressBar->Perc == Perc) && (FBDialogProgressBar->BarColor == BarColor))
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  if (Perc >= FBDialogProgressBar->Perc)
  {
    if (FBDialogProgressBar->BarColor == BarColor)
    {
      //Just draw the new bar
      TAP_Osd_FillBox_Chk("DrawProgressBarBar A", FBDialogProgressBar->MemOSDRgn, PROGRESSBARLEFT + FBDialogProgressBar->Perc, PROGRESSBARTOP, Perc - FBDialogProgressBar->Perc, PROGRESSBARHEIGHT, BarColor ? BarColor : FBDialogProfile->ProgressBarColor);
    }
    else
    {
      //Draw the complete bar
      TAP_Osd_FillBox_Chk("DrawProgressBarBar B", FBDialogProgressBar->MemOSDRgn, PROGRESSBARLEFT, PROGRESSBARTOP, Perc, PROGRESSBARHEIGHT, BarColor ? BarColor : FBDialogProfile->ProgressBarColor);
    }
  }
  else
  {
    if (FBDialogProgressBar->BarColor == BarColor)
    {
      //Just erase the delta
      TAP_Osd_FillBox_Chk("DrawProgressBarBar C", FBDialogProgressBar->MemOSDRgn, PROGRESSBARLEFT + Perc, PROGRESSBARTOP, FBDialogProgressBar->Perc - Perc, PROGRESSBARHEIGHT, RGB(0, 0, 0));
    }
    else
    {
      //We need to redraw the bar because the color has changed, then erase the delta
      TAP_Osd_FillBox_Chk("DrawProgressBarBar D", FBDialogProgressBar->MemOSDRgn, PROGRESSBARLEFT, PROGRESSBARTOP, Perc, PROGRESSBARHEIGHT, BarColor ? BarColor : FBDialogProfile->ProgressBarColor);
      TAP_Osd_FillBox_Chk("DrawProgressBarBar E", FBDialogProgressBar->MemOSDRgn, PROGRESSBARLEFT + Perc, PROGRESSBARTOP, FBDialogProgressBar->Perc - Perc, PROGRESSBARHEIGHT, RGB(0, 0, 0));
    }
  }

  TAP_Osd_PutFreeColorGd_Chk("DrawProgressBarBar A", FBDialogProgressBar->MemOSDRgn, 0, ProgressBar_Border_Top_Gd->height, ProgressBar_Border_Bottom_Gd, TRUE, FBDialogProfile->BorderColor);
  TAP_Osd_Copy_Chk("DrawProgressBarBar B", FBDialogProgressBar->MemOSDRgn, FBDialogProgressBar->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogProgressBar->MemOSDRgn), GetOSDRegionHeight(FBDialogProgressBar->MemOSDRgn), 0, 0, TRUE);

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

  FBDialogProgressBar->Value    = Value;
  FBDialogProgressBar->BarColor = BarColor;
  FBDialogProgressBar->Perc     = Perc;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
