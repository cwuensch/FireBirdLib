#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplaySetSegments (byte MemoryAddress, byte MemoryData)
{
  VFDDisplay.Memory.tapData [MemoryAddress] |= MemoryData;
}

#endif
