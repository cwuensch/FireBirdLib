#include                "FBLib_TMSOSDMenu.h"

void OSDMenuDestroy(void)
{
  if(OSDRgn)
  {
    TAP_Osd_Delete(OSDRgn);
    TAP_Osd_Sync();
    OSDRgn = 0;

    if((!OSDRgn) && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn)) TAP_EnterNormal();
  }
}
