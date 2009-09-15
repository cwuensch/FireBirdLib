#include                "FBLib_dialog.h"

void DialogWindowCursorSet(int ItemIndex)
{
  int                   selected;
  int                   direction;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowCursorSet");
#endif

  if (!FBDialogWindow || !FBDialogWindow->DialogItems || ItemIndex < 0 || ItemIndex >= FBDialogWindow->NrItems)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  selected = FBDialogWindow->SelectedItem;

  if (ItemIndex == 0) direction = +1;
  else if (ItemIndex == FBDialogWindow->NrItems - 1) direction = -1;
  else direction = 0;

  CalcPrepare();
  FBDialogWindow->TopItem = FBDialogWindow->SelectedItem = ItemIndex;
  CalcTopIndex(selected, direction);
  DialogWindowRefresh();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
