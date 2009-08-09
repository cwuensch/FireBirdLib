#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplayToggleSegments (byte MemoryAddress, byte MemoryData)
{
  VFDDisplay.Memory.tapData [MemoryAddress] ^= MemoryData;
}

#endif
