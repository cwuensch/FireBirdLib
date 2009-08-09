#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwDSTCheck (void)
{
  static dword          fwDSTCheck = 0;

  if (!fwDSTCheck)
    fwDSTCheck = FindInstructionSequence ("0c06a44b 00000000 304200ff 5040000b 8f999e38 8f999e38 93390006",
                                          "fc000000 ffffffff ffffffff ffff0000 ffe00000 ffe00000 fc00ffff",
                                           0x80100000, 0x80280000, 0, TRUE);

  return fwDSTCheck;
}

#endif
