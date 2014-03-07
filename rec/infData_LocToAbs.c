#include <tap.h>
#include "FBLib_rec.h"

char *infData_LocToAbs(char *LocalInfName)
{
  char                  CurrentDir[512];
  static char           AbsPath[512];

  TRACEENTER();

  HDD_TAP_GetCurrentDir(CurrentDir);
    TAP_SPrint(AbsPath, "%s%s/%s", TAPFSROOT, CurrentDir, LocalInfName);

  TRACEEXIT();
  return AbsPath;
}
