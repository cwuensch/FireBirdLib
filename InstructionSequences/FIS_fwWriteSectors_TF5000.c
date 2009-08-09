#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwWriteSectors (void)
{
  dword                 fwWriteSectors = 0;

  if (!fwWriteSectors) fwWriteSectors = FindInstructionSequence ("3c18b001 240e0034 af0e2d3c 24040028 0c02b661",
                                                                 "fc00ffff fc00ffff fc00ffff ffffffff fc000000",
                                                                  0x80000000, 0x80400000, 0, TRUE);

  return fwWriteSectors;
}

#endif
