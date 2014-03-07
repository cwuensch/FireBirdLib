#include                <stdio.h>
#include                <stdlib.h>
#include                "../libFireBird.h"

void HDD_RemoveDir(char *DirPath, bool Recursive)
{
  TRACEENTER();

  char                  cmd[512];

  if(DirPath && *DirPath)
  {
    if(Recursive)
      TAP_SPrint(cmd, "rm -rf %s/%s", TAPFSROOT, DirPath);
    else
      TAP_SPrint(cmd, "rmdir %s/%s", TAPFSROOT, DirPath);

    system(cmd);
  }

  TRACEEXIT();
}
