#include                "FBLib_dialog.h"

void DialogWindowItemDeleteAll(void)
{
  int                   i;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowItemDeleteAll");
#endif

  if (!FBDialogWindow || !FBDialogWindow->DialogItems)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  memset (FBDialogWindow->DialogItems, 0, FBDialogWindow->ReservedItems * sizeof(tDialogItem));

  FBDialogWindow->NrItems = 0;
  FBDialogWindow->TopItem = 0;
  FBDialogWindow->SelectedItem = 0;

  for (i = 0; i < FBDialogWindow->NrItemLines; i++) FBDialogWindow->OSDLineForeDirty[i] = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
