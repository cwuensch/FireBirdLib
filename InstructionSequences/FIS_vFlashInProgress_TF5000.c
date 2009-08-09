#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vFlashInProgress (void)
{
  dword                 *p, gp;
  static dword          vFlashInProgress = 0;

  if (!vFlashInProgress)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    p = (dword*)FindInstructionSequence ("27bdffe8 afbf0014 14a00009 a78084d2 a78085b0 839984d4 13200008 24020001",
                                         "ffff0000 ffff0000 ffff0000 ffff0000 ffff0000 ffe00000 fc000000 ffffffff",
                                         0x80100000, 0x80180000, 3, FALSE);


    if (!p) return 0;

    vFlashInProgress = gp + (short)(*p & 0xffff);
  }

  return vFlashInProgress;
}

#endif
