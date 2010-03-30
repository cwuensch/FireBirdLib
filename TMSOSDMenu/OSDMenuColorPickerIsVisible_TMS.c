#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuColorPickerIsVisible(void)
{
  return (ColorPickerOSDRgn != 0);
}

#endif
