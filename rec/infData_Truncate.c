#include <unistd.h>
#include "FBLib_rec.h"

void infData_Truncate(const char *infFileName, dword Position)
{
  TRACEENTER();

  char                  AbsFileName[FBLIB_DIR_SIZE], CurDir[FBLIB_DIR_SIZE];

  if(infFileName && *infFileName)
  {
    HDD_TAP_GetCurrentDir(CurDir);
    TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, CurDir, infFileName);
    if(*AbsFileName) truncate(AbsFileName, Position);
  }

  TRACEEXIT();
}
