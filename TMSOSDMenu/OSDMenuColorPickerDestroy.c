#include                "FBLib_TMSOSDMenu.h"

void OSDMenuColorPickerDestroy(void)
{
  TRACEENTER();

  tOSDMapInfo          *OSDMapInfo;

  if(ColorPickerOSDRgn)
  {
    TAP_Osd_Delete(ColorPickerOSDRgn);
    ColorPickerOSDRgn = 0;

    if(InfoBoxSaveArea)
    {
      if(MyOSDRgn)
      {
        OSDMapInfo = (tOSDMapInfo*) FIS_vOsdMap();
        if(OSDMapInfo)
          TAP_Osd_RestoreBox(MyOSDRgn, InfoBoxSaveAreaX - OSDMapInfo[MyOSDRgn].x, InfoBoxSaveAreaY - OSDMapInfo[MyOSDRgn].y, INFOBOX_WIDTH, INFOBOX_HEIGHT, InfoBoxSaveArea);
      }
      else if(OSDRgn) TAP_Osd_RestoreBox(OSDRgn, InfoBoxSaveAreaX, InfoBoxSaveAreaY, INFOBOX_WIDTH, INFOBOX_HEIGHT, InfoBoxSaveArea);

      TAP_MemFree(InfoBoxSaveArea);
      InfoBoxSaveArea = NULL;
      MyOSDRgn = 0;
    }

    TAP_Osd_Sync();

    if((!OSDRgn) && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn) && (!ProgressBarOSDRgn)) TAP_EnterNormal();
  }

  TRACEEXIT();
}
