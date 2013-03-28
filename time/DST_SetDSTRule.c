#include                "FBLib_time.h"

tDSTRule                DSTRule = DSTR_Firmware;
tDSTRule                DSTRule;
dword                   DSTStartUTCsaved = 0, DSTEndUTCsaved = 0;

void DST_SetDSTRule(tDSTRule NewDSTRule)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("DST_SetDSTRule");
  #endif

  DSTRule = NewDSTRule;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
