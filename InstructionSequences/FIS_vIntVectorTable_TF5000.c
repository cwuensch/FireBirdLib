#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vIntVectorTable (void)
{
  dword                 *p;
  static dword          vIntVectorTable = 0;

  if (!vIntVectorTable)
  {
    p = (dword*) FindInstructionSequence ("00000000 3c19b000 8f390040 02b9c824 13200011 00000000 3c1981bf 27392120",
                                          "ffffffff ffe0ffff fc00ffff fc0007ff fc1f0000 ffffffff fc000000 fc000000",
                                          0x80000180, 0x80010000, 6, FALSE);

    if (p) vIntVectorTable = (p[0] << 16) + (short)(p[1] & 0xffff);
  }

  return vIntVectorTable;
}

#endif
