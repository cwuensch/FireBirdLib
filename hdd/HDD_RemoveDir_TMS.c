#include                <stdlib.h>
#include                "../libFireBird.h"

#ifdef _TMS_

void HDD_RemoveDir(char *DirPath, bool Recursive)
{
  char                  cmd[512];
  //char                  DirPathUTF8[256];

  //if(TAP_GetVersion() >= 0x0108)
  //{
  //  StrToUTF8(DirPath, DirPathUTF8);
  //
  //  if(Recursive)
  //    TAP_SPrint(cmd, "rm -rf %s/%s", TAPFSROOT, DirPathUTF8);
  //  else
  //    TAP_SPrint(cmd, "rmdir %s/%s", TAPFSROOT, DirPathUTF8);
  //}
  //else
  //{
    if(Recursive)
      TAP_SPrint(cmd, "rm -rf %s/%s", TAPFSROOT, DirPath);
    else
      TAP_SPrint(cmd, "rmdir %s/%s", TAPFSROOT, DirPath);
  //}

  system(cmd);
}

#endif
