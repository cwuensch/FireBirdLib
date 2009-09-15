#include                "FBLib_dialog.h"

void DialogProgressBarSet(int Value, dword BarColor)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProgressBarSet");
#endif

  if (!FBDialogProgressBar || !FBDialogProgressBar->isVisible)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  DrawProgressBarBar(Value, BarColor);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
