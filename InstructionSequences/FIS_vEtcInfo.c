#include "../libFireBird.h"

inline dword FIS_vEtcInfo(void)
{
  static dword          vEtcInfo;

#ifdef _TMS_

  if(!vEtcInfo)
    vEtcInfo = TryResolve("_etcInfo");

#else

  if (!vEtcInfo)
    vEtcInfo = FIS_vEEPROM();

#endif

  return vEtcInfo;
}
