#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplayClearSegments (byte MemoryAddress, byte MemoryData)
{
  VFDDisplay.Memory.tapData [MemoryAddress] &= ~MemoryData;
}

#endif
