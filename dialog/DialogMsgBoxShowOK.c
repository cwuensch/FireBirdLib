#include                <string.h>
#include                "FBLib_dialog.h"

void DialogMsgBoxShowOK(void)
{
  #ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxShowOK");
#endif

  if (!FBDialogMsgBox)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  strcpy(FBDialogMsgBox->ButtonText [0], "OK");
  FBDialogMsgBox->ButtonText [1][0] = '\0';
  DialogMsgBoxShow ();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
