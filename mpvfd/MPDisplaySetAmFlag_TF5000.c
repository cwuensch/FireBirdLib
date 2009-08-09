#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplaySetAmFlag (bool active)
{
  VFDDisplay.Segments.AnteMeridiem = active;
}

#endif
