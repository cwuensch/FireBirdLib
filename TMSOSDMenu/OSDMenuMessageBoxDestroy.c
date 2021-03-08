#include                "FBLib_TMSOSDMenu.h"

void OSDMenuMessageBoxDestroy(void)
{
  bool EnterNormal = TRUE;

  TRACEENTER();

  if(MessageBoxOSDRgn)
  {
    OSDMenuMessageBoxDestroyNoOSDUpdate();
    TAP_Osd_Sync();
  }

#ifdef FB_COLORPICKER_ENABLED
  if(ColorPickerOSDRgn) EnterNormal = FALSE;
#endif
  if(EnterNormal && (!OSDRgn) && (!InfoBoxOSDRgn) && (!ProgressBarOSDRgn)) TAP_EnterNormal();

#ifdef FB_USE_UNICODE_OSD
  OSDMenuFreeStdFonts();
#endif

  TRACEEXIT();
}
