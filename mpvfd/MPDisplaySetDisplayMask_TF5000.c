#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplaySetDisplayMask (byte MaskAddress, byte MaskData)
{
  StringsMask [MaskAddress] = MaskData;
}

#endif
