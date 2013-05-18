#include <string.h>
#include <unistd.h>
#include <tap.h>
#include "FBLib_rec.h"

void infData_TruncateAbs(char *infFileName, dword Position)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_TruncateAbs");
  #endif

  truncate(infFileName, Position);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
