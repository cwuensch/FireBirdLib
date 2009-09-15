#include                <string.h>
#include                "FBLib_dialog.h"

void DialogWindowItemChangeValue(int ItemIndex, char *Value, dword ValueColor)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowItemChangeValue");
#endif

  if (!FBDialogWindow || !FBDialogWindow->DialogItems || ItemIndex < 0 || ItemIndex >= FBDialogWindow->NrItems)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  if (Value)
  {
    strncpy (FBDialogWindow->DialogItems[ItemIndex].Value, Value, sizeof(FBDialogWindow->DialogItems->Value) - 1);
    FBDialogWindow->DialogItems[ItemIndex].Value[sizeof(FBDialogWindow->DialogItems->Value) - 1] = '\0';
  }

  FBDialogWindow->DialogItems[ItemIndex].ValueColor = ValueColor;

  if (ItemIndex >= FBDialogWindow->TopItem && ItemIndex <= FBDialogWindow->TopItem + FBDialogWindow->NrItemLines - 1) FBDialogWindow->OSDLineForeDirty[ItemIndex - FBDialogWindow->TopItem] = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
