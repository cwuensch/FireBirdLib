#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

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

#endif
