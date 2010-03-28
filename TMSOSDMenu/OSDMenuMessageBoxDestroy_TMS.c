#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuMessageBoxDestroy(void)
{
  if(MessageBoxOSDRgn)
  {
    TAP_Osd_Delete(MessageBoxOSDRgn);
    MessageBoxOSDRgn = 0;

    if(InfoBoxSaveArea && OSDRgn) TAP_Osd_RestoreBox(OSDRgn, InfoBoxSaveAreaX, InfoBoxSaveAreaY, _InfoBox_Gd.width, _InfoBox_Gd.height, InfoBoxSaveArea);
    if(InfoBoxSaveArea)
    {
      TAP_MemFree(InfoBoxSaveArea);
      InfoBoxSaveArea = NULL;
    }

    TAP_Osd_Sync();

    if((!OSDRgn) && (!InfoBoxOSDRgn) && (!MessageBoxOSDRgn)) TAP_EnterNormal();
  }
}

#endif
