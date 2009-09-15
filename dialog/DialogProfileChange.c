#include                "FBLib_dialog.h"

void DialogProfileChange(tDialogProfile *DialogProfile)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileChange");
#endif

  FBDialogProfile = DialogProfile;
  ProfileDirty();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
