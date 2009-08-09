#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vMPEGHeader(void)
{
  static dword          vMPEGHeader = 0;
  dword                *p;

  if (!vMPEGHeader)
  {
    p = (dword*)FindInstructionSequence ("8f9999b8 27360020 3c180810 37181013",
                                         "ffe00000 fc00ffff ffe0ffff fc00ffff",
                                          0x800c0000, 0x80100000, 0, FALSE);

    if (p) p = (dword*)(FIS_GetGP((dword*)0x80000000) + (short)(*p & 0xffff));
    if (isValidRAMPtr(p)) vMPEGHeader = *p;
  }

  return vMPEGHeader;
}

#endif
