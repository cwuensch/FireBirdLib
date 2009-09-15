#include                <string.h>
#include                "FBLib_dialog.h"

INILOCATION DialogProfileLoadMy(char *AppName)
{
  char                  ProfileName[64];
  INILOCATION           ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileLoadMy");
#endif

  if (!FBDialogProfile || !AppName || !ProfileMayReload())
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return INILOCATION_NotFound;
  }

  memset(ProfileName, 0, sizeof(ProfileName));
  strncpy(ProfileName, AppName, sizeof(ProfileName) - 12);
  strcat(ProfileName, "Profile.ini");

  ret = ProfileLoad(ProfileName, FALSE, AppName);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
