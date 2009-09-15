#include                "FBLib_debug.h"

void CallTraceComment(char *Comment)
{
  char                  Spaces [101];

  if(!CallTraceInitialized) CallTraceInit();

  Spaces [0] = '\0';

  if (CallTraceEnabled)
  {
    memset (Spaces, ' ', CallLevel < 50 ? CallLevel << 1 : 100);
    Spaces [CallLevel < 50 ? CallLevel << 1 : 100] = '\0';
    if (Comment && *Comment) TAP_PrintNet("%s# %s\n", Spaces, Comment);
  }
}