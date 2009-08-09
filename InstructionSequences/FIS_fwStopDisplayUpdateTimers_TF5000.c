#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_fwStopDisplayUpdateTimers (void)
{
  static dword          *fwStopDisplayUpdateTimers = NULL;
  dword                 JALCount = 0;

  if (!fwStopDisplayUpdateTimers)
  {
    //Search for the second JAL in the EF00 event handler
    fwStopDisplayUpdateTimers = (dword*)FindInstructionSequence("3c058011 24a5c1a8 3404ef00 00003025 0c0565d3 24070064",
                                                                "ffff0000 ffff0000 ffffffff ffffffff fc000000 ffffffff",
                                                                0x800E0000, 0x80180000, 0, FALSE);

    if (!fwStopDisplayUpdateTimers) return 0;
    fwStopDisplayUpdateTimers = (dword*)((fwStopDisplayUpdateTimers[0] << 16) + (short)(fwStopDisplayUpdateTimers[1] & 0xffff));
    while (JALCount < 2)
    {
      fwStopDisplayUpdateTimers++;
      if ((*fwStopDisplayUpdateTimers & CMD_MASK) == JAL_CMD) JALCount++;
    }

    //if the next instruction is an ADDIU, it is a call to update the LED display, not the one we're looking for
    if ((fwStopDisplayUpdateTimers[1] & 0xfc000000) == 0x24000000) return 0;

    fwStopDisplayUpdateTimers = (dword*)(ABS_ADDR(fwStopDisplayUpdateTimers[0]));
  }

  return (dword)fwStopDisplayUpdateTimers;
}

#endif
