#include                "FBLib_dialog.h"

void DialogWindowChange(tDialogWindow *DialogWindow, bool Redraw)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowChange");
#endif

  FBDialogWindow = DialogWindow;

  if (Redraw) WindowDirty();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
