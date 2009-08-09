#include "FBLib_mpvfd.h"

#ifndef _TMS_

byte MPDisplayGetDisplayByte (byte MemoryAddress)
{
  return VFDDisplay.Memory.tapData [MemoryAddress];
}

#endif
