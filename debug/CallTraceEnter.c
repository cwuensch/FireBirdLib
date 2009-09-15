#include                "FBLib_debug.h"

void CallTraceEnter (char *ProcName)
{
  char                  Spaces [101];

  if(!CallTraceInitialized) CallTraceInit();

  if (CallLevel >= 50) TAP_PrintNet("\n\nCallLevel Overflow!\n\n");
  if (CallTraceEnabled)
  {
    memset (Spaces, ' ', CallLevel < 50 ? CallLevel << 1 : 100);
    Spaces [CallLevel < 50 ? CallLevel << 1 : 100] = '\0';
    TAP_PrintNet("%s%s\n", Spaces, ProcName);
  }
  CallLevel++;
}
