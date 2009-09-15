#include                <string.h>
#include                "FBLib_dialog.h"

void DialogProgressBarTitleSet(char *Title)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProgressBarTitleSet");
#endif

  if (!FBDialogProgressBar)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  if (Title)
  {
    strncpy(FBDialogProgressBar->Title, Title, sizeof(FBDialogProgressBar->Title) - 1);
    FBDialogProgressBar->Title[sizeof(FBDialogProgressBar->Title) - 1] = '\0';
  }

  if (FBDialogProgressBar->isVisible) DrawProgressBarTitle();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
