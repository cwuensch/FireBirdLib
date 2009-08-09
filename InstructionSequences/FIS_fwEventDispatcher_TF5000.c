#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwEventDispatcher (void)
{
  static dword          fwEventDispatcher = 0;

  if (!fwEventDispatcher)
  {
    fwEventDispatcher = FindInstructionSequence ("0080f025 00a0b025 0000a025 0c0000f4 00000000 0040a825 3c198056 8f391fdc 27390001",
                                                 "ffffffff ffffffff ffffffff ffff0000 ffffffff ffffffff ffff0000 ffff0000 ffffffff",
                                                  0x80000000, 0x80200000, 0, TRUE);

    //A different signature as used by several firmwares starting 2008
    if (!fwEventDispatcher)
      fwEventDispatcher = FindInstructionSequence ("27bdffe0 afb60018 afbe001c afbf0014 0080f025 00a0b025 02c03025 03c02825 24040001 0c001cab 00000000 304200ff 8fbf0014 8fb60018 8fbe001c 27bd0020 03e00008",
                                                   "ffff0000 fe000000 fe000000 fe000000 ffff07ff ffff07ff fc1fffff fc1fffff ffffffff fc000000 ffffffff ffffffff fe000000 fe000000 fe000000 ffff0000 ffffffff",
                                                   0x80004000, 0x80010000, 0, FALSE);
  }

  return fwEventDispatcher;
}

#endif
