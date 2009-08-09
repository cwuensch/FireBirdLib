#include                "FBLib_dialog.h"

void DialogProgressBarSet  (int Value, dword BarColor)
{
  if (!FBDialogProgressBar || !FBDialogProgressBar->isVisible) return;

  DrawProgressBarBar(Value, BarColor);
}
