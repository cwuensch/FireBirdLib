#include                <stdlib.h>
#include                "FBLib_TMSOSDMenu.h"

void OSDMenuDestroy(void)
{
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

  if((!InfoBoxOSDRgn) && (!MessageBoxOSDRgn) && (!ProgressBarOSDRgn) && (!ColorPickerOSDRgn)) TAP_EnterNormal();

  if(Menu[CurrentMenuLevel].Item)
  {
    TAP_MemFree(Menu[CurrentMenuLevel].Item);
    Menu[CurrentMenuLevel].Item = NULL;
  }

  if (Menu[CurrentMenuLevel].MemoText)
  {
    TAP_MemFree(Menu[CurrentMenuLevel].MemoText);
    Menu[CurrentMenuLevel].MemoText = NULL;
  }

#ifdef FB_USE_UNICODE_OSD
  OSDMenuFreeStdFonts();
#endif

  CallbackProcedure = NULL;

  TRACEEXIT();
}
