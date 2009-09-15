#include                "FBLib_dialog.h"

void DialogMsgBoxShowInfo(dword ms)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxShowInfo");
#endif

  if (!FBDialogMsgBox)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  FBDialogMsgBox->InfoBoxTimeout = (ms ? TAP_GetTick() + ms / 10 : 0xffffffff);

  FBDialogMsgBox->ButtonText [0][0] = '\0';
  DialogMsgBoxShow ();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
