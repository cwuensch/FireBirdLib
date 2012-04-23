#include "../libFireBird.h"

inline dword FIS_vfavName(void)
{
  static dword          vfavGrp = 0;

  if (!vfavGrp)
    vfavGrp = TryResolve("_favGrp");

  return vfavGrp;
}
