#include                <stdio.h>
#include                "../libFireBird.h"

dword HDD_GetFileTimeByRelFileName(char *FileName)
{
  TRACEENTER();

  char                  AbsFileName[256];
  dword                 ret;

  if(FileName)
  {
    TAP_SPrint(AbsFileName, "%s%s", TAPFSROOT, FileName);
    ret = HDD_GetFileTimeByAbsFileName(AbsFileName);
  }
  else ret = 0;

  TRACEEXIT();
  return ret;
}
