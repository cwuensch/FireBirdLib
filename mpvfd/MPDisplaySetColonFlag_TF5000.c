#include "FBLib_mpvfd.h"

#ifndef _TMS_

void MPDisplaySetColonFlag (bool active)
{
  VFDDisplay.Segments.Colon = active;
}

#endif
