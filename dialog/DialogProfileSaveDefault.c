#include                "FBLib_dialog.h"

bool DialogProfileSaveDefault(void)
{
  bool                  ret;
  INILOCATION           INILocation;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileSaveDefault");
#endif

  ret = HDD_TAP_PushDir();
  INILocation = INILocateFile (DEFAULTPROFILE, NULL);
  if (INILocation == INILOCATION_NotFound) INILocation = INILOCATION_AtProgramFiles;
  if (ret) (void)HDD_TAP_PopDir();

  ret = DialogProfileSave(DEFAULTPROFILE, INILocation, NULL);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
