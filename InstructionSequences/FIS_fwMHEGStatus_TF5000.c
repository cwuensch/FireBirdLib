#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwMHEGStatus (void)
{
  static dword          fwMHEGStatus = 0;
  short                *pMHEG;
  dword                 gp;

  if (!fwMHEGStatus)
  {
    if (!(gp = FIS_GetGP((dword*)0x80000000))) return 0;

    pMHEG = (word *) FindInstructionSequence("27bdffe0 afb50014 afb60018 afbe001c afbf0010 8f9e8b64 13c00007 0080a825 0c070c1a",
                                             "ffffffff ffffffff ffffffff ffffffff ffffffff ffff0000 ffffffff ffffffff ff000000",
                                             0x80190000, 0x80200000, 5, FALSE );

    if (!pMHEG) return 0;

    fwMHEGStatus = (gp + pMHEG[1]);
    if (!fwMHEGStatus) return 0;
  }

  return fwMHEGStatus;
}

#endif
