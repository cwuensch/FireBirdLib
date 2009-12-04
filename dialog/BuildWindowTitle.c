#include                "FBLib_dialog.h"

void BuildWindowTitle(void)
{
  dword                 TitleCWidth;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("BuildWindowTitle");
#endif

  if (!FBDialogWindow || !FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  // remember: all Title_*_Gd have transparent upper parts of (the visible part of) Border_N_Gd width

  // cache title background

  TitleCWidth = FBDialogWindow->NrTitleColumns * Title_C_Gd->width;

  if (!FBDialogWindow->MemOSDTitle || !isOSDRegionAlive(FBDialogWindow->MemOSDTitle))
    FBDialogWindow->MemOSDTitle = TAP_Osd_Create_Chk("BuildWindowTitle", 0, 0, Title_W_Gd->width + TitleCWidth + Title_E_Gd->width, Title_C_Gd->height << 1, 0, OSD_Flag_MemRgn);

  // fill cache
  TAP_Osd_PutFreeColorGd_Chk("BuildWindowTitle A", FBDialogWindow->MemOSDTitle, 0, 0, Title_W_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);

  if (FBDialogWindow->NrTitleColumns)
  {
    TAP_Osd_PutFreeColorGd_Chk("BuildWindowTitle B", FBDialogWindow->MemOSDTitle, Title_W_Gd->width, 0, Title_C_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);
    OSDCopy(FBDialogWindow->MemOSDTitle, Title_W_Gd->width, 0, Title_C_Gd->width, Title_C_Gd->height, FBDialogWindow->NrTitleColumns - 1, X);
  }

  TAP_Osd_PutFreeColorGd_Chk("BuildWindowTitle C", FBDialogWindow->MemOSDTitle, Title_W_Gd->width + TitleCWidth, 0, Title_E_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);

  FBDialogWindow->OSDTitleBackDirty = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
