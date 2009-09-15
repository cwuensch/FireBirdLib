#include                "FBLib_debug.h"

void CallTraceExitResult (dword *Magic, char *Result)
{
  char                  Spaces [101];

  if(!CallTraceInitialized) CallTraceInit();

  Spaces [0] = '\0';

  if (CallLevel > 0) CallLevel--;
                else TAP_PrintNet("\n\nCallLevel Underflow!\n\n");


  if (CallTraceEnabled || Magic)
  {
    memset (Spaces, ' ', CallLevel < 50 ? CallLevel << 1 : 100);
    Spaces [CallLevel < 50 ? CallLevel << 1 : 100] = '\0';
    if (Result && *Result) TAP_PrintNet("%s  = %s\n", Spaces, Result);
  }

  if (Magic && *Magic != DEFAULTMAGIC)
  {
    TAP_PrintNet("\n\n%sINVALID MAGIC!\n\n", Spaces);
    *Magic = DEFAULTMAGIC;
  }
}
