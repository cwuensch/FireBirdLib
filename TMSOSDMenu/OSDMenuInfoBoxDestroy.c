#include                "FBLib_TMSOSDMenu.h"

void OSDMenuInfoBoxDestroy(void)
{
  TRACEENTER();

  if(InfoBoxOSDRgn)
  {
    OSDMenuInfoBoxDestroyNoOSDUpdate();
    TAP_Osd_Sync();
  }

  if((!OSDRgn) && (!MessageBoxOSDRgn) && (!ProgressBarOSDRgn) && (!ColorPickerOSDRgn)) TAP_EnterNormal();

  TRACEEXIT();
}
