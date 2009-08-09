#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwMemMonitor (void)
{
  static dword          fwMemMonitor = 0;
  char                  s[10];

  if (!fwMemMonitor)
    fwMemMonitor = FindInstructionSequence ("8f260000 3c048027 2484aed0 03c02825 0c02b716 00000000 27de0001 1000ffef 00000000",
                                            "fc1fffff ffff0000 ffff0000 fc0007ff fc000000 ffffffff fc00ffff ffff0000 ffffffff",
                                             0x80000000, 0x80008000, 0, TRUE);

  if (!fwMemMonitor)
  {
    //The following search returns the address of MemoryMonitor
    fwMemMonitor = FindInstructionSequence ("3c048028 248423c4 0c02cbff 00000000 24180004",
                                            "ffff0000 ffff0000 fc000000 ffffffff ffe0ffff",
                                             0x80090000, 0x800c0000, 0, TRUE);
    if (fwMemMonitor)
    {
      TAP_SPrint(s, "%8.8x", JAL_CMD | REL_ADDR(fwMemMonitor));
      fwMemMonitor = FindInstructionSequence (s, "ffffffff", 0x80000000, 0x80008000, 0, TRUE);
    }
  }

  return fwMemMonitor;
}

#endif
