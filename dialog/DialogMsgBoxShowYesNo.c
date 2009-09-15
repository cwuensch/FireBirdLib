#include                <string.h>
#include                "FBLib_dialog.h"

void DialogMsgBoxShowYesNo(dword DefaultButton)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxShowYesNo");
#endif

  if (!FBDialogMsgBox)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  switch (TAP_GetSystemVar (SYSVAR_OsdLan))
  {
    case LAN_German:
      strcpy (FBDialogMsgBox->ButtonText [0], "Ja");
      strcpy (FBDialogMsgBox->ButtonText [1], "Nein");
      break;

    default:
      strcpy (FBDialogMsgBox->ButtonText [0], "Yes");
      strcpy (FBDialogMsgBox->ButtonText [1], "No");
  }
  FBDialogMsgBox->ButtonText [2][0] = '\0';
  FBDialogMsgBox->DefaultButton = DefaultButton;
  DialogMsgBoxShow();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
