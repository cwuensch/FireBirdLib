#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vFlashFWMaxSize (void)
{
  static dword          vFlashFWMaxSize = 0;
  short                *p;
  dword                 gp;

  if (!vFlashFWMaxSize)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    // Flash, FlashFWStart: short@+3($gp) (and +7), FlashFWSize: short@+9($gp)
    p = (short*)FindInstructionSequence("3c19bfc0 8f9895cc 0338f021 8f9995cc 8f9895dc 0338c821 3c0fbfc0 032fc821 03d9082b 10200044 00000000",
                                        "ffffffff ffff0000 ffffffff ffff0000 ffff0000 ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff",
                                         0x80180000, 0x80280000, 0, FALSE);

    if (!p) return 0;

    vFlashFWMaxSize = gp + p[9];
  }

  return vFlashFWMaxSize;
}

#endif
