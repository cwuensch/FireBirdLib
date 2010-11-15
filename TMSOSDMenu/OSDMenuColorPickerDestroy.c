#include                "FBLib_TMSOSDMenu.h"

void OSDMenuColorPickerDestroy(void)
{
  if(ColorPickerOSDRgn)
  {
    TAP_Osd_Delete(ColorPickerOSDRgn);
    ColorPickerOSDRgn = 0;

    if(InfoBoxSaveArea && OSDRgn) TAP_Osd_RestoreBox(OSDRgn, InfoBoxSaveAreaX, InfoBoxSaveAreaY, _ColorPicker_Gd.width, _ColorPicker_Gd.height, InfoBoxSaveArea);
    if(InfoBoxSaveArea)
    {
      TAP_MemFree(InfoBoxSaveArea);
      InfoBoxSaveArea = NULL;
    }

    TAP_Osd_Sync();

    if((!OSDRgn) && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn) && (!ProgressBarOSDRgn)) TAP_EnterNormal();
  }
}
