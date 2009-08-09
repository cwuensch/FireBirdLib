#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vPinStatus (void)
{
  dword                 *EP, gp;
  static dword          pIRDLocked = 0;

  if (!pIRDLocked)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    EP = (dword*) FindInstructionSequence ("3404e300 02a02825 00003025 0c054965 240700f1 8f988974",
                                           "ffffffff fc1fffff ffffffff fc000000 ffffffff ffe00000",
                                           0x80150000, 0x80200000, 5, FALSE);

    if (EP) pIRDLocked = (gp + (short) (EP [0] & 0x0000ffff));
  }

  return pIRDLocked;
}

#endif
