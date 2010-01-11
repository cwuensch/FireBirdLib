#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuMessageBoxIsVisible(void)
{
  return (MessageBoxOSDRgn != 0);
}

#endif
