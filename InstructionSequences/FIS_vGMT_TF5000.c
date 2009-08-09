#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vGMT (void)
{
  static dword          vGMT = 0;
  dword                 gp;

  if (!vGMT)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    vGMT = FindInstructionSequence ("3c04801e 0c02b6eb 248418c0 8f9884b4 0018c402 0c04539b 3304ffff 8f9e84b4",
                                    "ffff0000 fc000000 fc1f0000 ffe00000 ffe007ff fc000000 fc1fffff fc000000",
                                     0x80100000, 0x80200000, 3, FALSE);

    if (vGMT) vGMT = gp + (short)(*(dword*)(vGMT) & 0x0000ffff);
  }

  return vGMT;
}

#endif
