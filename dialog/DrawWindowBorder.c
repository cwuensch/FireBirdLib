#include                "FBLib_dialog.h"

void DrawWindowBorder (void)
{
  if (!FBDialogWindow || !FBDialogProfile) return;

  if (FBDialogWindow->OSDBorderBackDirty)
  {
    BuildWindowBorder();

    if (FBDialogWindow->OSDRgn)
    {
      // draw
      TAP_Osd_Copy_Chk("DrawWindowBorder A", FBDialogWindow->MemOSDBorderN, FBDialogWindow->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogWindow->MemOSDBorderN), GetOSDRegionHeight(FBDialogWindow->MemOSDBorderN), 0,                                                                           0,                      TRUE);
      TAP_Osd_Copy_Chk("DrawWindowBorder B", FBDialogWindow->MemOSDBorderW, FBDialogWindow->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogWindow->MemOSDBorderW), GetOSDRegionHeight(FBDialogWindow->MemOSDBorderW), 0,                                                                           FBDialogWindow->ItemsY, TRUE);
      TAP_Osd_Copy_Chk("DrawWindowBorder C", FBDialogWindow->MemOSDBorderE, FBDialogWindow->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogWindow->MemOSDBorderE), GetOSDRegionHeight(FBDialogWindow->MemOSDBorderE), FBDialogWindow->OSDWidth - GetOSDRegionWidth(FBDialogWindow->MemOSDBorderE), FBDialogWindow->ItemsY, TRUE);
      TAP_Osd_Copy_Chk("DrawWindowBorder D", FBDialogWindow->MemOSDBorderS, FBDialogWindow->OSDRgn, 0, 0, GetOSDRegionWidth(FBDialogWindow->MemOSDBorderS), GetOSDRegionHeight(FBDialogWindow->MemOSDBorderS), 0,                                                                           FBDialogWindow->InfoSY, TRUE);

#ifdef _TMS_
      TAP_Osd_Sync();
#endif

      FBDialogWindow->OSDBorderBackDirty = FALSE;
    }
  }
}
