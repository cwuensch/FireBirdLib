#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuInfoBoxIsVisible(void)
{
  return (InfoBoxOSDRgn != 0);
}

#endif
