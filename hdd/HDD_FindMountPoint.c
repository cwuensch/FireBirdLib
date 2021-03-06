#include                "libFireBird.h"

bool HDD_FindMountPoint(const char *AbsPath, char *const OutMountPoint)
{
  TRACEENTER();

  bool ret;

  ret = HDD_FindMountPointDevice(AbsPath, OutMountPoint, NULL);

  TRACEEXIT();
  return ret;
}
