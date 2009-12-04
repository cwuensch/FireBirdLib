#include                "FBLib_dialog.h"

void BuildWindowScrollBar(void)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("BuildWindowScrollBar");
#endif

  if (!FBDialogWindow || !FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  // cache scrollbar
  if (!FBDialogWindow->MemOSDScrollBar || !isOSDRegionAlive(FBDialogWindow->MemOSDScrollBar))
    FBDialogWindow->MemOSDScrollBar = TAP_Osd_Create_Chk("BuildWindowScrollBar", 0, 0, Scroll_Back_Gd->width << 1, FBDialogWindow->NrItemLines * Scroll_Back_Gd->height, 0, OSD_Flag_MemRgn);

  // fill cache

  if (FBDialogWindow->NrItemLines)
  {
    TAP_Osd_PutFreeColorGd_Chk("BuildWindowScrollBar A", FBDialogWindow->MemOSDScrollBar, 0, 0, Scroll_Back_Gd, TRUE, FBDialogProfile->ScrollBarColor);
    OSDCopy(FBDialogWindow->MemOSDScrollBar, 0, 0, Scroll_Back_Gd->width, Scroll_Back_Gd->height, FBDialogWindow->NrItemLines - 1, Y);

    TAP_Osd_PutFreeColorGd_Chk("BuildWindowScrollBar B", FBDialogWindow->MemOSDScrollBar, 0, 0, Scroll_End_Gd, TRUE, FBDialogProfile->ScrollBarColor);
    TAP_Osd_Copy_Chk("BuildWindowScrollBar C", FBDialogWindow->MemOSDScrollBar, FBDialogWindow->MemOSDScrollBar, 0, 0, Scroll_End_Gd->width, Scroll_End_Gd->height, 0, GetOSDRegionHeight(FBDialogWindow->MemOSDScrollBar) - Scroll_End_Gd->height, TRUE);
  }

  FBDialogWindow->OSDScrollBarBackDirty = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
