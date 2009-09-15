#include                "FBLib_dialog.h"

void DialogWindowScrollUp(void)
{
  int                   selected;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowScrollUp");
#endif

  if (!FBDialogWindow || !FBDialogWindow->NrItems || !FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  CalcPrepare();
  selected = FBDialogWindow->SelectedItem;

  if (FBDialogWindow->hasCursor && FBDialogProfile->ScrollWrapAround && (FBDialogWindow->SelectedItem == 0)) FBDialogWindow->SelectedItem = FBDialogWindow->NrItems - 1;
  else FBDialogWindow->SelectedItem--;

  if (FBDialogWindow->hasCursor && FBDialogProfile->ScrollScreen && (FBDialogWindow->SelectedItem < FBDialogWindow->TopItem)) FBDialogWindow->TopItem -= FBDialogWindow->NrItemLines;

  CalcTopIndex(selected, -1);
  DialogWindowRefresh();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
