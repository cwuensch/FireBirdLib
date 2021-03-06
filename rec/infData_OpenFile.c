#include <stdio.h>
#include "FBLib_rec.h"

FILE                   *infDatainfFile = NULL;

bool infData_OpenFile(char *infFileName)
{
  TRACEENTER();

  char                  AbsFileName[FBLIB_DIR_SIZE], CurDir[FBLIB_DIR_SIZE];

  infDatainfFile = NULL;
  if(infFileName && *infFileName)
  {
    HDD_TAP_GetCurrentDir(CurDir);
    TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, CurDir, infFileName);
    if(*AbsFileName) infDatainfFile = fopen(AbsFileName, "r+");
  }

  TRACEEXIT();
  return (infDatainfFile != NULL);
}
