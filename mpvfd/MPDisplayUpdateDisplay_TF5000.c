#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplayUpdateDisplay (void)
{
  combineVfdData (VFDDisplay.Memory.fwData, &VFDDisplay.Memory);
  sendToVfdDisplay (VFDDisplay.Memory.fwData);
}

#endif
