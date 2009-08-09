#include "../libFireBird.h"

inline dword FIS_vFlash (void)
{
  static dword          vFlash = 0;

#ifdef _TMS_

  if(!vFlash)
  {
    dword *_applFlashAddr = (dword*)TryResolve("_applFlashAddr");

    if(!_applFlashAddr) return 0;
    vFlash = *_applFlashAddr;
  }

#else

  dword                 *pFlash, gp;

  if (!vFlash)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    pFlash = (dword*)FindInstructionSequence ("8f999ebc 0016c340 03382021 0c000c56 24052000",
                                              "ff800000 ffe007ff fc00ffff fc000000 ffffffff",
                                               0x80100000, 0x80280000, 0, FALSE);

    if (pFlash)
    {
      pFlash = (dword*)(gp + (short)(*pFlash & 0xffff));
      vFlash = *pFlash;
    }
  }

#endif

  return vFlash;
}
