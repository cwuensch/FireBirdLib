#include                "FBLib_TMSOSDMenu.h"

void OSDMenuInfoBoxDestroy(void)
{
  if(InfoBoxOSDRgn)
  {
    TAP_Osd_Delete(InfoBoxOSDRgn);
    TAP_Osd_Sync();
    InfoBoxOSDRgn = 0;

    if((!OSDRgn) && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn)) TAP_EnterNormal();
  }
}
