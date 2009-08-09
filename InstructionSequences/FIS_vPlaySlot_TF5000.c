#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vPlaySlot (void)
{
  static dword          vPlaySlot = 0;
  dword                 *p;

  if (!vPlaySlot)
  {
    p = (dword*)FindInstructionSequence ("0019ce00 0019cfc2 0000a025 333000ff 0c05676c 24040001 16c00003 24180001 00008025 24180001 56d8000c a38084d0 3c1e81a0 93de1ce0",
                                         "ffe007ff ffe007ff fc0007ff fc00ffff fc000000 ffffffff fc1f0000 ffe0ffff fc0007ff ffe0ffff fc000000 ffff0000 ffe00000 fc000000",
                                         0x800c0000, 0x80180000, 11, FALSE);

    if (!p) p = (dword*)FindInstructionSequence ("0019ce00 0c054ced 0019afc2 8faf0048 55e00003 8fb90048 0000a825 8fb90048 24180001 5738000c a38084dc 3c1681b7 92d6aff0",
                                                 "ffe007ff fc000000 ffe007ff ffc00000 fc000000 ffc00000 fc0007ff ffc00000 ffe00001 fc000000 ffff0000 ffe00000 fc000000",
                                                 0x800c0000, 0x80180000, 10, FALSE);

    if (!p) return 0;

    vPlaySlot = (p[1] << 16) + (short)(p[2] & 0xffff);
  }

  return vPlaySlot;
}

#endif
