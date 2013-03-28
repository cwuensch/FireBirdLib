#include                "FBLib_TMSOSDMenu.h"

void OSDMenuSetCallback(void *OSDCallbackProcedure)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("OSDMenuSetCallback");
  #endif

  CallbackProcedure = OSDCallbackProcedure;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
