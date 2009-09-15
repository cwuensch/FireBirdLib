#include                "FBLib_dialog.h"

INILOCATION DialogProfileLoad(char *FileName, char *AppName)
{
  INILOCATION           ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileLoad");
#endif

  ret = ProfileLoad(FileName, TRUE, AppName);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}
