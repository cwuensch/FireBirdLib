#include                "FBLib_dialog.h"

void DialogWindowScrollDown(void)
{
  int                   selected;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowScrollDown");
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

  if (FBDialogWindow->hasCursor && FBDialogProfile->ScrollWrapAround && (FBDialogWindow->SelectedItem == FBDialogWindow->NrItems - 1)) FBDialogWindow->SelectedItem = 0;
  else FBDialogWindow->SelectedItem++;

  if (FBDialogWindow->hasCursor && FBDialogProfile->ScrollScreen && (FBDialogWindow->SelectedItem >= FBDialogWindow->TopItem + FBDialogWindow->NrItemLines)) FBDialogWindow->TopItem = FBDialogWindow->SelectedItem;

  CalcTopIndex(selected, +1);
  DialogWindowRefresh();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}

