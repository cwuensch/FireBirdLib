#include "../libFireBird.h"

inline dword FIS_vBootReason(void)
{
  static dword          vBootReason = 0;

#ifdef _TMS_

  if(!vBootReason)
    vBootReason = TryResolve("_powerOnSrc");

#else

  if (!vBootReason)
    vBootReason = 0xa3fffffc;

#endif

  return vBootReason;
}
