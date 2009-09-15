#include                "FBLib_debug.h"

dword       CallLevel        = 0;
bool        CallTraceEnabled = FALSE;
bool        CallTraceInitialized = FALSE;

void CallTraceInit(void)
{
  CallLevel = 0;
  CallTraceEnabled = TRUE;
  CallTraceInitialized = TRUE;
}
