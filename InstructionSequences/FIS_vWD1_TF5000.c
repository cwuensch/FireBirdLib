#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vWD1 (void)
{
  static dword          vWD1 = 0;
  dword                 gp;

  if (!vWD1)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    vWD1 = FindInstructionSequence ("0080f025 0c052c4d 8f8484f4 0c052719 03c02025 1040001a 0040f025 0c052889 03c02025",
                                    "ffffffff fc000000 ffff0000 fc000000 ffffffff ffff0000 ffffffff fc000000 ffffffff",
                                    0x800F0000, 0x80180000, 2, FALSE);
    if (vWD1) vWD1 = gp + (short)(*(dword*)(vWD1) & 0xffff);
  }

  return vWD1;
}

#endif
