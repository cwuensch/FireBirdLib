#include <tap.h>
#include "FBLib_rec.h"

void infData_CloseFile(void)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_CloseFile");
  #endif

  if(infDatainfFile)
  {
    TAP_Hdd_Fclose(infDatainfFile);
    infDatainfFile = NULL;
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
