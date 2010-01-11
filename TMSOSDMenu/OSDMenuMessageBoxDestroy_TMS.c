#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuMessageBoxDestroy(void)
{
  if(MessageBoxOSDRgn)
  {
    TAP_Osd_Delete(MessageBoxOSDRgn);
    TAP_Osd_Sync();
    MessageBoxOSDRgn = 0;

    if((!OSDRgn) && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn)) TAP_EnterNormal();
  }
}

#endif
