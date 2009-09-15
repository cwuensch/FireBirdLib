#include                "FBLib_dialog.h"

void DialogWindowTypeChange(eDialogWindowTypes WindowType)
{
  int                   i;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowTypeChange");
#endif

  if (!FBDialogWindow || (int) WindowType < 0 || WindowType >= DialogWindowType_NR_OF_TYPES)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  FBDialogWindow->Type = WindowType;

  for (i = 0; i < FBDialogWindow->NrItemLines; i++) FBDialogWindow->OSDLineForeDirty[i] = TRUE;
  FBDialogWindow->OSDLineBackDirty         = TRUE;
  FBDialogWindow->OSDLineSelectedBackDirty = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
