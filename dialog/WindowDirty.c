#include                "FBLib_dialog.h"

// just in case someone needs to manipulate a tDialogWindow directly
void WindowDirty(void)
{
  int                   i;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("WindowDirty");
#endif

  if (!FBDialogWindow)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  // force complete redraw
  FBDialogWindow->OSDBorderBackDirty       = TRUE;
  FBDialogWindow->OSDTitleForeDirty        = TRUE;
  FBDialogWindow->OSDTitleBackDirty        = TRUE;
  for (i = 0; i < FBDialogWindow->NrItemLines; i++) FBDialogWindow->OSDLineForeDirty[i] = TRUE;
  FBDialogWindow->OSDLineBackDirty         = TRUE;
  FBDialogWindow->OSDLineSelectedBackDirty = TRUE;
  FBDialogWindow->OSDScrollBarForeDirty    = TRUE;
  FBDialogWindow->OSDScrollBarBackDirty    = TRUE;
  FBDialogWindow->OSDInfoForeDirty         = TRUE;
  FBDialogWindow->OSDInfoBackDirty         = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
