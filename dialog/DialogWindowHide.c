#include                "FBLib_dialog.h"

void DialogWindowHide(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowHide");
#endif

  if (!FBDialogWindow || !FBDialogWindow->isVisible || !FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  if (FBDialogWindow->Multiple)
  {
    if (FBDialogWindow->MultipleOSDSaveBox)
    {
      TAP_Osd_RestoreBox_Chk("DialogWindowHide", FBDialogWindow->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogWindow->OSDRgn), GetOSDRegionHeight(FBDialogWindow->OSDRgn), FBDialogWindow->MultipleOSDSaveBox);
      TAP_MemFree (FBDialogWindow->MultipleOSDSaveBox);
      FBDialogWindow->MultipleOSDSaveBox = NULL;
    }
    FreeOSDRegion(FBDialogWindow->OSDRgn);   // doesn't wipe out
  }
  else
  {
    DialogWindowAlpha(0);
    TAP_Osd_FillBox_Chk("DialogWindowHide", FBDialogWindow->OSDRgn, 0, 0, FBDialogWindow->OSDWidth, FBDialogWindow->OSDHeight, 0);
    TAP_Osd_SetTransparency (FBDialogWindow->OSDRgn, 255);
    TAP_Osd_Delete (FBDialogWindow->OSDRgn);
  }

  FBDialogWindow->OSDRgn = 0;

  FBDialogWindow->isVisible = FALSE;

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

  if (FBDialogWindow->isNormalMode) TAP_EnterNormal();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

}
