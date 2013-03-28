#include                "FBLib_debug.h"

void CallTraceEnter(char *ProcName)
{
  char                  Spaces[101];
  byte                 *ISOText;

  if(CallTraceDoNotReenter) return;
  CallTraceDoNotReenter = TRUE;

  if(!CallTraceInitialized) CallTraceInit();

  if(CallLevel >= CTSTACKSIZE) TAP_Print("CallLevel Overflow!\n");

  if(CallTraceEnabled && ProcName)
  {
    StrToISOAlloc(ProcName, &ISOText);
    memset(Spaces, ' ', CallLevel < CTSTACKSIZE ? CallLevel << 1 : 100);
    Spaces[CallLevel < CTSTACKSIZE ? CallLevel << 1 : 100] = '\0';
    TAP_PrintNet("%s%s\n", Spaces, ISOText);

    //Add the current routine to the stack
    if(CallLevel < CTSTACKSIZE)
    {
      CallTraceStack[CallLevel].ProcName = ProcName;
      CallTraceStack[CallLevel].EntryTime = TAP_GetTick();
    }

    TAP_MemFree(ISOText);
  }

  CallLevel++;
  CallTraceDoNotReenter = FALSE;
}
