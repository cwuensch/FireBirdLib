#include                "FBLib_TMSOSDMenu.h"

void OSDMenuMessageBoxDestroy(void)
{
  TRACEENTER();

  if(MessageBoxOSDRgn)
  {
    OSDMenuMessageBoxDestroyNoOSDUpdate();
    TAP_Osd_Sync();
  }

  if((!OSDRgn) && (!InfoBoxOSDRgn) && (!ProgressBarOSDRgn) && (!ColorPickerOSDRgn)) TAP_EnterNormal();

#ifdef FB_USE_UNICODE_OSD
  OSDMenuFreeStdFonts();
#endif

  TRACEEXIT();
}
