#include                "FBLib_dialog.h"

void DialogMsgBoxExit(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxExit");
#endif

  if (!FBDialogMsgBox || !FBDialogMsgBox->isVisible)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  TAP_Osd_Delete (FBDialogMsgBox->MemOSDRgn);

  if (FBDialogMsgBox->OSDSaveBox)
  {
    TAP_Osd_RestoreBox_Chk("DialogMsgBoxExit", FBDialogMsgBox->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogMsgBox->OSDRgn), GetOSDRegionHeight(FBDialogMsgBox->OSDRgn), FBDialogMsgBox->OSDSaveBox);
    TAP_MemFree (FBDialogMsgBox->OSDSaveBox);
    FBDialogMsgBox->OSDSaveBox = NULL;
  }

  FreeOSDRegion(FBDialogMsgBox->OSDRgn);   // doesn't wipe out

  FBDialogMsgBox->isVisible = FALSE;

  if (FBDialogMsgBox->isNormalMode) TAP_EnterNormal();

  FBDialogMsgBox = NULL;

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
