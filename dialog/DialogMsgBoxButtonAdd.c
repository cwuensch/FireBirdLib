#include                <string.h>
#include                "FBLib_dialog.h"

void DialogMsgBoxButtonAdd(char *ButtonText, bool Default)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxButtonAdd");
#endif

  if (!FBDialogMsgBox || !ButtonText)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  if ((unsigned int) FBDialogMsgBox->NrButtons < sizeof1st(FBDialogMsgBox->ButtonText))
  {
    strncpy(FBDialogMsgBox->ButtonText[FBDialogMsgBox->NrButtons], ButtonText, sizeof(*FBDialogMsgBox->ButtonText) - 1);
    FBDialogMsgBox->ButtonText[FBDialogMsgBox->NrButtons][sizeof(*FBDialogMsgBox->ButtonText) - 1] = '\0';

    if (Default) FBDialogMsgBox->DefaultButton = FBDialogMsgBox->NrButtons;

    FBDialogMsgBox->NrButtons++;
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
