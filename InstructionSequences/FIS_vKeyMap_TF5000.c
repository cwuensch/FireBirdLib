#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vKeyMap (void)
{
  static dword          vKeyMap = 0;
  dword                *p;

  if (!vKeyMap)
  {
    p = (dword*)FindInstructionSequence ("3c19ff00 0099c824 0019ce02 332500ff 14a00005 24190001 3c198025 273923ec 10000009",
                                         "ffe0ffff fc0007ff ffc007ff fc00ffff fc1f0000 ffe0ffff ffe00000 fc000000 ffff0000",
                                          0x80100000, 0x80200000, 6, FALSE);

    if (p) vKeyMap = (p[0] << 16) + (short)(p[1] & 0xffff);
  }

  return vKeyMap;
}

#endif
