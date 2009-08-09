#include                "FBLib_dialog.h"

void DrawProgressBarTitle (void)
{
  if (!FBDialogProgressBar || !FBDialogProfile) return;

  if (FBDialogProgressBar->MemOSDRgn && FBDialogProgressBar->OSDRgn)
  {
    TAP_Osd_PutFreeColorGd_Chk("DrawProgressBarTitle A", FBDialogProgressBar->MemOSDRgn, 0, 0, ProgressBar_Title_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);
    TAP_Osd_PutS(FBDialogProgressBar->MemOSDRgn, TITLE_OFFSET_XY, 16, ProgressBar_Title_Gd->width - TITLE_OFFSET_XY, FBDialogProgressBar->Title, FBDialogProfile->TitleTextColor, 0, 0, FNT_Size_1622, TRUE, ALIGN_CENTER);
    TAP_Osd_Copy_Chk("DrawProgressBarTitle B", FBDialogProgressBar->MemOSDRgn, FBDialogProgressBar->OSDRgn, 0, 0, ProgressBar_Title_Gd->width, ProgressBar_Title_Gd->height, 0, 0, TRUE);

#ifdef _TMS_
    TAP_Osd_Sync();
#endif
  }
}
