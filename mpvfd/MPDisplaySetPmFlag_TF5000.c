#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplaySetPmFlag (bool active)
{
  VFDDisplay.Segments.PostMeridiem = active;
}

#endif
