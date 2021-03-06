#include                "FBLib_TMSOSDMenu.h"

void OSDMenuInfoBoxDestroyNoOSDUpdate(void)
{
  TRACEENTER();

  tOSDMapInfo          *OSDMapInfo;

  if(WaitSpinnerRgn)
  {
    TAP_Osd_Delete(WaitSpinnerRgn);
    WaitSpinnerRgn = 0;
  }

  if(InfoBoxOSDRgn)
  {
    TAP_Osd_Delete(InfoBoxOSDRgn);
    InfoBoxOSDRgn = 0;

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
  }

#ifdef FB_USE_UNICODE_OSD
  OSDMenuFreeStdFonts();
#endif

  TRACEEXIT();
}
