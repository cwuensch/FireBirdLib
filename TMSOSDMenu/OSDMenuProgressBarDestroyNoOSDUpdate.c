#include                "FBLib_TMSOSDMenu.h"

void OSDMenuProgressBarDestroyNoOSDUpdate(void)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("OSDMenuProgressBarDestroyNoOSDUpdate");
  #endif

  if(ProgressBarOSDRgn)
  {
    TAP_Osd_Delete(ProgressBarOSDRgn);
    TAP_Osd_Delete(ProgressBarFullRgn);
    ProgressBarOSDRgn = 0;
    ProgressBarFullRgn = 0;
  }
  OSDMenuInfoBoxDestroyNoOSDUpdate();
  ProgressBarLastValue =  0xfff;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
