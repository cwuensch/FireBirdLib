#include                "FBLib_dialog.h"

void DialogProgressBarExit(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProgressBarExit");
#endif

  if (!FBDialogProgressBar || !FBDialogProgressBar->isVisible)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  TAP_Osd_Delete (FBDialogProgressBar->MemOSDRgn);

  if (FBDialogProgressBar->OSDSaveBox)
  {
    TAP_Osd_RestoreBox_Chk("DialogProgressBarExit", FBDialogProgressBar->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogProgressBar->OSDRgn), GetOSDRegionHeight(FBDialogProgressBar->OSDRgn), FBDialogProgressBar->OSDSaveBox);
    TAP_MemFree (FBDialogProgressBar->OSDSaveBox);
    FBDialogProgressBar->OSDSaveBox = NULL;
  }

  FreeOSDRegion(FBDialogProgressBar->OSDRgn);   // doesn't wipe out

  FBDialogProgressBar->isVisible = FALSE;

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

  if (FBDialogProgressBar->isNormalMode) TAP_EnterNormal();

  FBDialogProgressBar = NULL;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
