#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplayClearDisplay (void)
{
  memset (VFDDisplay.Memory.tapData, 0, sizeof(VFDDisplay.Memory.tapData));
  memset (VFDDisplay.Memory.fwData, 0, sizeof(VFDDisplay.Memory.fwData));
}

#endif
