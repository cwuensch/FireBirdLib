#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vLEDDisplayBuffer (void)
{
  static dword          vLEDDisplayBuffer = 0;
  dword                *p;

  if (!vLEDDisplayBuffer)
  {
    p = (dword*)FindInstructionSequence ("27859d90 0c001aa6 2404000f 02a02825 0c001aa6 2404000f",
                                         "ffff0000 fc000000 ffffffff fc00ffff fc000000 ffffffff",
                                          0x80005000, 0x80180000, 0, FALSE);
    if (p) vLEDDisplayBuffer = FIS_GetGP((dword*)0x80000000) + (short)(*p & 0xffff);
  }

  return vLEDDisplayBuffer;
}

#endif
