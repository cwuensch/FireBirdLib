#include                "FBLib_dialog.h"

tDialogProgressBar      *FBDialogProgressBar  = NULL;

void DialogProgressBarInit(tDialogProgressBar *DialogProgressBar, tDialogProfile *DialogProfile, dword X, dword Y, char *Title, int Minimum, int Maximum)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProgressBarInit");
#endif

  if (FBDialogProgressBar || !(FBDialogProgressBar = DialogProgressBar))
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  memset(FBDialogProgressBar, 0, sizeof(tDialogProgressBar));

  FBDialogProgressBar->OSDX   = X;
  FBDialogProgressBar->OSDY   = Y;
  FBDialogProgressBar->Min    = Minimum;
  FBDialogProgressBar->Max    = Maximum;
  FBDialogProgressBar->Value  = Minimum;

  DialogProgressBarTitleSet(Title);

  if (!FBDialogProfile)
  {
    FBDialogProfile = DialogProfile;
    ProfileInit();
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
