#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwShutdownHandler (void)
{
  static dword          fwShutdownHandler = 0;

  if (!fwShutdownHandler)
    fwShutdownHandler = FindInstructionSequence ("24840f44 240f0001 a38f85f2 0c05dd59 240400ff 304200ff 10400044 24040001 27a4002c 3c068011 24c6d358 0c04da75",
                                                 "ffff0000 fc00ffff ffe00000 fc000000 ffffffff 00000000 bfeb0000 00000000 00000000 ffff0000 ffff0000 fc000000",
                                                  0x800F0000, 0x80160000, 0, TRUE);

  return fwShutdownHandler;
}

#endif
