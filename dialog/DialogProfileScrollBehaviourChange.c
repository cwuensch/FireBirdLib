#include                "FBLib_dialog.h"

void DialogProfileScrollBehaviourChange(bool ScrollScreen, bool WrapAround)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogProfileScrollBehaviourChange");
#endif

  if (FBDialogProfile)
  {
    FBDialogProfile->ScrollScreen     = ScrollScreen;
    FBDialogProfile->ScrollWrapAround = WrapAround;
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
