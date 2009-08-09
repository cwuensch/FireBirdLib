#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwPIC2_ISR18 (void)
{
  static dword          fwPIC2_ISR18 = 0;

  if (!fwPIC2_ISR18) fwPIC2_ISR18 = FindInstructionSequence ("241e0011 10000005 00000000 241e0013 10000002 00000000 241e001b a380801c 10000019 00000000",
                                                             "fc00ffff fc000000 ffffffff fc00ffff fc000000 ffffffff fc00ffff ffff0000 fc000000 ffffffff",
                                                              0x80000000, 0x80008000, 0, TRUE);

  return fwPIC2_ISR18;
}

#endif
