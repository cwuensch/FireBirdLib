#include <string.h>
#include <unistd.h>
#include <tap.h>
#include "FBLib_rec.h"

void infData_Truncate(char *infFileName, dword Position)
{
  char                  AbsFileName[512];

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_Truncate");
  #endif

  strcpy(AbsFileName, TAPFSROOT);
  HDD_TAP_GetCurrentDir(&AbsFileName[strlen(AbsFileName)]);
  strcat(AbsFileName, "/");
  strcat(AbsFileName, infFileName);
  truncate(AbsFileName, Position);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
