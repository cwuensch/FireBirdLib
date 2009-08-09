#include "../libFireBird.h"

inline dword FIS_vEEPROMPin (void)
{
    static dword        vEEPROMPin = 0;

#ifdef _TMS_

  if (!vEEPROMPin)
    vEEPROMPin = TryResolve("_parentalInfo");

#else

  dword                 gp;
  short                *p;

  if (!vEEPROMPin)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    p = (short*)FindInstructionSequence("8f99a4a0 97390000 17240003 24190a2e 03e00008 00001025 14990003 2402ffff 03e00008 00001025 03e00008 00000000",
                                        "ffff0000 ffffffff fffffff0 ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff",
                                        0x80160000, 0x80280000, 0, FALSE);

    if (p) vEEPROMPin = *(dword*)(gp + p[1]);
  }

#endif

  return vEEPROMPin;
}
