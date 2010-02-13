#include                <stdlib.h>
#include                "../libFireBird.h"

#ifdef _TMS_

void HDD_RemoveDir(char *DirPath, bool Recursive)
{
  char                  cmd[512];

  if(Recursive)
    TAP_SPrint(cmd, "rm -rf %s/%s", TAPFSROOT, DirPath);
  else
    TAP_SPrint(cmd, "rmdir %s/%s", TAPFSROOT, DirPath);

  system(cmd);
}

#endif
