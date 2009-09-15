#include                "FBLib_dialog.h"

void CheckSelectable(int OldItem, int Direction)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("CheckSelectable");
#endif

  if (!FBDialogWindow || !FBDialogWindow->DialogItems)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  while ((FBDialogWindow->SelectedItem < 0 || FBDialogWindow->SelectedItem >= FBDialogWindow->NrItems) || !FBDialogWindow->DialogItems[FBDialogWindow->SelectedItem].Selectable)
  {
    if (FBDialogWindow->SelectedItem == OldItem) break;
    else FBDialogWindow->SelectedItem += Direction;
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
