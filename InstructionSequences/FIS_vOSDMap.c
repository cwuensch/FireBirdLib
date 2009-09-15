#include "../libFireBird.h"

inline dword FIS_vOSDMap (void)
{
#ifndef _TMS_
  dword                 *p;
#endif

  static dword          vOSDMap = 0;

#ifdef _TMS_

  if (!vOSDMap)
    vOSDMap = TryResolve("_osdInfo");

#else

  if (!vOSDMap)
  {
    p = (dword*)FindInstructionSequence ("3c198057 27398c00 0004c100 0338f021 8fc70008 10e0006c 3419ffff 9398887a",
                                         "ffe00000 fc000000 ffe007ff fc0007ff fc00ffff bfffff00 00000000 ffe00000",
                                         0x80090000, 0x80280000, 0, FALSE);

    //The TF6xxx series seems to use a completely different mechanism.
    if (!p) return 0;

    vOSDMap = (p[0] << 16) + (short)(p[1] & 0xffff);
  }

#endif

  return vOSDMap;
}
