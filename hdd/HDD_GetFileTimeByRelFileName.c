#include                <stdio.h>
#include                "../libFireBird.h"

dword HDD_GetFileTimeByRelFileName(char *FileName)
{
  char                  AbsFileName[FBLIB_DIR_SIZE], CurDir[FBLIB_DIR_SIZE];

  if(!FileName) return 0;

  HDD_TAP_GetCurrentDir(CurDir);
  TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, CurDir, FileName);

  return HDD_GetFileTimeByAbsFileName(AbsFileName);
}
