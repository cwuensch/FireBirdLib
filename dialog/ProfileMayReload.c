#include                "FBLib_dialog.h"

bool ProfileMayReload(void)
{
  bool                  ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("ProfileMayReload");
#endif

  if (!FBDialogProfile || (FBDialogProfile->Magic != DIALOGPROFILE_MAGIC)) ret = TRUE;
  else ret = (FBDialogProfile->HDDAccess == 1 || (FBDialogProfile->HDDAccess == 2 && TAP_GetSystemVar(SYSVAR_Timeshift) == 1));

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
