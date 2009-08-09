#include "../libFireBird.h"

inline dword FIS_vParentalInfo(void)
{
  static dword          vParentalInfo = 0;

#ifdef _TMS_

  dword                 *d;

  if(!vParentalInfo)
  {
    d = (dword*)TryResolve("_parentalInfo");
    if(d) vParentalInfo = *d;
  }

#else

  if(!vParentalInfo)
    vParentalInfo = FIS_vEEPROM() + 0x24;

#endif

  return vParentalInfo;
}

