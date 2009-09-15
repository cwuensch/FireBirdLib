#include                "FBLib_dialog.h"

void DialogWindowItemAddSeparator(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowItemAddSeparator");
#endif

  DialogWindowItemAdd("", 0, "", 0, FALSE, FALSE, DialogItemIcon_None, NULL);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
