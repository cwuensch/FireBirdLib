#include                "FBLib_dialog.h"

void DialogWindowItemChangeFlags(int ItemIndex, bool Selectable, bool Enabled)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowItemChangeFlags");
#endif

  if (!FBDialogWindow || !FBDialogWindow->DialogItems || ItemIndex < 0 || ItemIndex >= FBDialogWindow->NrItems)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  FBDialogWindow->DialogItems[ItemIndex].Selectable = Selectable;
  FBDialogWindow->DialogItems[ItemIndex].Enabled    = Enabled;

  if (ItemIndex >= FBDialogWindow->TopItem && ItemIndex <= FBDialogWindow->TopItem + FBDialogWindow->NrItemLines - 1) FBDialogWindow->OSDLineForeDirty[ItemIndex - FBDialogWindow->TopItem] = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
