#include                "FBLib_dialog.h"

void DialogProfileLoadDefault(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileLoadDefault");
#endif

  DialogProfileLoad(DEFAULTPROFILE, NULL);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
