#include                "FBLib_TMSOSDMenu.h"

void OSDMenuMessageBoxDestroyNoOSDUpdate(void)
{
  TRACEENTER();

  tOSDMapInfo          *OSDMapInfo;

  if(MessageBoxOSDRgn)
  {
    TAP_Osd_Delete(MessageBoxOSDRgn);
    MessageBoxOSDRgn = 0;

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
