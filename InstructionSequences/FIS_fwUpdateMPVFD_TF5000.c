#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwUpdateMPVFD (void)
{
  static dword          fwUpdateMPVFD = 0;

  if (!fwUpdateMPVFD)
    fwUpdateMPVFD = FindInstructionSequence ("2ea10030 10200025 00000000 3c198057 2739cd7c 27390030 03352021 03d52821 02c03025 0c03dbc2 00000000 10400018 00000000",
                                             "ffe0ffff ffff0000 ffffffff ffe00000 fc000000 fc00ffff fc00ffff fc00ffff fc00ffff fc000000 ffffffff ffff0000 ffffffff",
                                              0x80004000, 0x80010000, 0, TRUE);

  return fwUpdateMPVFD;
}

#endif
