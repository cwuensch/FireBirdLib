#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuIsVisible(void)
{
  return OSDRgn != 0;
}

#endif
