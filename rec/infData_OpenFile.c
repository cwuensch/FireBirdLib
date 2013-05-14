#include <tap.h>
#include "FBLib_rec.h"

TYPE_File              *infDatainfFile = NULL;

bool infData_OpenFile(char *infFileName)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_OpenFile");
  #endif

  infDatainfFile = TAP_Hdd_Fopen(infFileName);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return (infDatainfFile != NULL);
}
