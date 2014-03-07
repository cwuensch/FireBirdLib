#include                <stdio.h>
#include                "../libFireBird.h"

__ino64_t HDD_GetInodeByRelFileName(char *FileName)
{
  TRACEENTER();

  char                  AbsFileName[256];
  __ino64_t             ret;

  if(FileName)
  {
    TAP_SPrint(AbsFileName, "%s%s", TAPFSROOT, FileName);
    ret = HDD_GetInodeByAbsFileName(AbsFileName);
  }
  else
    ret = 0;

  TRACEEXIT();
  return ret;
}
