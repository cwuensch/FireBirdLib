#ifdef _TMS_

#include                "../libFireBird.h"

dword HDD_GetFileTimeByRelFileName(char *FileName)
{
  char                  AbsFileName[256];

  if(!FileName) return 0;

  TAP_SPrint(AbsFileName, "%s%s", TAPFSROOT, FileName);

  return HDD_GetFileTimeByAbsFileName(AbsFileName);
}

#endif
