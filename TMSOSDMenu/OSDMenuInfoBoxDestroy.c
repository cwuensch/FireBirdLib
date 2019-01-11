#include                "FBLib_TMSOSDMenu.h"

void OSDMenuInfoBoxDestroy(void)
{
  bool EnterNormal = TRUE;

  if(InfoBoxOSDRgn)
  {
    OSDMenuInfoBoxDestroyNoOSDUpdate();
    TAP_Osd_Sync();
  }

#ifdef FB_COLORPICKER_ENABLED
  if(ColorPickerOSDRgn) EnterNormal = FALSE;
#endif
  if(EnterNormal && (!OSDRgn) && (!MessageBoxOSDRgn) && (!ProgressBarOSDRgn)) TAP_EnterNormal();
}
