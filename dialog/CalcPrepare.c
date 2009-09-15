#include                "FBLib_dialog.h"

int PrevTopItem;
int PrevSelItem;

void CalcPrepare(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("CalcPrepare");
#endif

  if (FBDialogWindow)
  {
    PrevTopItem = FBDialogWindow->TopItem;
    PrevSelItem = FBDialogWindow->SelectedItem;
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
