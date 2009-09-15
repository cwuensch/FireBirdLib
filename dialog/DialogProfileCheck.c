#include                "FBLib_dialog.h"

void DialogProfileCheck(tDialogProfile *DialogProfile, char *AppName)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileCheck");
#endif

  if (FBDialogProfile || !DialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  FBDialogProfile = DialogProfile;
  ProfileInit();
  FBDialogProfile->Magic = 0;
  DialogProfileLoadMy(AppName);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
