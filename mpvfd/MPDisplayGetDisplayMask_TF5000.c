#include "FBLib_mpvfd.h"

#ifndef _TMS_

byte MPDisplayGetDisplayMask (byte MaskAddress)
{
  return StringsMask [MaskAddress];
}

#endif
