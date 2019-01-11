#include                <stdlib.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMenuDestroy(void)
{
  bool EnterNormal = TRUE;

  TRACEENTER();

  if(OSDRgn)
  {
    TAP_Osd_Delete(OSDRgn);
    TAP_Osd_Sync();
    OSDRgn = 0;
    if(OSDMenuSelectionBarRgn) TAP_Osd_Delete(OSDMenuSelectionBarRgn);
    OSDMenuSelectionBarRgn = 0;
    OSDMenuLastCursor = LCT_NRCURSORS;
  }

#ifdef FB_COLORPICKER_ENABLED
  if(ColorPickerOSDRgn) EnterNormal = FALSE;
#endif
  if(EnterNormal && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn) && (!ProgressBarOSDRgn)) TAP_EnterNormal();

  if(Menu[CurrentMenuLevel].Item)
  {
    TAP_MemFree(Menu[CurrentMenuLevel].Item);
    Menu[CurrentMenuLevel].Item = NULL;
  }

#ifdef FB_USE_UNICODE_OSD
  OSDMenuFreeStdFonts();
#endif

  CallbackProcedure = NULL;

  TRACEEXIT();
}
