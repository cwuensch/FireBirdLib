#include                "FBLib_dialog.h"

void BuildWindowBorder (void)
{
  dword                 wMax, eMax;

  if (!FBDialogWindow || !FBDialogProfile) return;

  // cache northern border
  if (!FBDialogWindow->MemOSDBorderN
#ifndef _TMS_
      || !isOSDRegionAlive(FBDialogWindow->MemOSDBorderN)
#endif
     )
    FBDialogWindow->MemOSDBorderN = TAP_Osd_Create(0, 0, FBDialogWindow->OSDWidth, Border_N_Gd->height, 0, OSD_Flag_MemRgn);

  // fill cache

  TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder A", FBDialogWindow->MemOSDBorderN, 0, 0, Border_NW_Gd, TRUE, FBDialogProfile->BorderColor);

  if (FBDialogWindow->NrTitleColumns)   // remember: the Border_N*_Gd and Title_*_Gd are of same width
  {
    TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder B", FBDialogWindow->MemOSDBorderN, Border_NW_Gd->width, 0, Border_N_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogWindow->MemOSDBorderN, Border_NW_Gd->width, 0, Border_N_Gd->width, Border_N_Gd->height, FBDialogWindow->NrTitleColumns - 1, X);
  }

  TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder C", FBDialogWindow->MemOSDBorderN, Border_NW_Gd->width + FBDialogWindow->NrTitleColumns * Border_N_Gd->width, 0, Border_NE_Gd, TRUE, FBDialogProfile->BorderColor);

  // cache western border

  wMax = Border_Items_W_Gd->width;
  if (Border_InfoN_W_Gd->width > wMax) wMax = Border_InfoN_W_Gd->width;
  if (Border_Info_W_Gd->width  > wMax) wMax = Border_Info_W_Gd->width;

  if (!FBDialogWindow->MemOSDBorderW
#ifndef _TMS_
      || !isOSDRegionAlive(FBDialogWindow->MemOSDBorderW)
#endif
     )

    FBDialogWindow->MemOSDBorderW = TAP_Osd_Create(0, 0, wMax, FBDialogWindow->InfoSY - FBDialogWindow->ItemsY, 0, OSD_Flag_MemRgn);

  // cache eastern border

  eMax = Border_Items_E_Gd->width;
  if (Border_InfoN_E_Gd->width > eMax) eMax = Border_InfoN_E_Gd->width;
  if (Border_Info_E_Gd->width  > eMax) eMax = Border_Info_E_Gd->width;

  if (!FBDialogWindow->MemOSDBorderE
#ifndef _TMS_
      || !isOSDRegionAlive(FBDialogWindow->MemOSDBorderE)
#endif
     )
    FBDialogWindow->MemOSDBorderE = TAP_Osd_Create(0, 0, eMax, FBDialogWindow->InfoSY - FBDialogWindow->ItemsY, 0, OSD_Flag_MemRgn);

  // fill cache

  // item lines
  if (FBDialogWindow->NrItemLines)
  {
    TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder D", FBDialogWindow->MemOSDBorderW, 0, 0, Border_Items_W_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogWindow->MemOSDBorderW, 0, 0, Border_Items_W_Gd->width, Border_Items_W_Gd->height, FBDialogWindow->NrItemLines - 1, Y);

    TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder E", FBDialogWindow->MemOSDBorderE, eMax - Border_Items_E_Gd->width, 0, Border_Items_E_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogWindow->MemOSDBorderE, eMax - Border_Items_E_Gd->width, 0, Border_Items_E_Gd->width, Border_Items_E_Gd->height, FBDialogWindow->NrItemLines - 1, Y);
  }

  // northern boundary of info area
  TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder F", FBDialogWindow->MemOSDBorderW, 0,                               FBDialogWindow->InfoNY - FBDialogWindow->ItemsY, Border_InfoN_W_Gd, TRUE, FBDialogProfile->BorderColor);
  TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder G", FBDialogWindow->MemOSDBorderE, eMax - Border_InfoN_E_Gd->width, FBDialogWindow->InfoNY - FBDialogWindow->ItemsY, Border_InfoN_E_Gd, TRUE, FBDialogProfile->BorderColor);

  // info area lines
  if (FBDialogWindow->NrInfoLines)
  {
    TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder H", FBDialogWindow->MemOSDBorderW, 0, FBDialogWindow->InfoY - FBDialogWindow->ItemsY, Border_Info_W_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogWindow->MemOSDBorderW, 0, FBDialogWindow->InfoY - FBDialogWindow->ItemsY, Border_Info_W_Gd->width, Border_Info_W_Gd->height, FBDialogWindow->NrInfoLines - 1, Y);

    TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder I", FBDialogWindow->MemOSDBorderE, eMax - Border_Info_E_Gd->width, FBDialogWindow->InfoY - FBDialogWindow->ItemsY, Border_Info_E_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogWindow->MemOSDBorderE, eMax - Border_Info_E_Gd->width, FBDialogWindow->InfoY - FBDialogWindow->ItemsY, Border_Info_E_Gd->width, Border_Info_E_Gd->height, FBDialogWindow->NrInfoLines - 1, Y);
  }

  // cache southern border
  if (!FBDialogWindow->MemOSDBorderS
#ifndef _TMS_
      || !isOSDRegionAlive(FBDialogWindow->MemOSDBorderS)
#endif
     )
    FBDialogWindow->MemOSDBorderS = TAP_Osd_Create(0, 0, FBDialogWindow->OSDWidth, Border_S_Gd->height, 0, OSD_Flag_MemRgn);

  // fill cache

  TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder J", FBDialogWindow->MemOSDBorderS, 0, 0, Border_SW_Gd, TRUE, FBDialogProfile->BorderColor);

  if (FBDialogWindow->NrInfoSColumns)   // remember: the Border_S*_Gd and InfoS_*_Gd are of same width
  {
    TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder K", FBDialogWindow->MemOSDBorderS, Border_SW_Gd->width, 0, Border_S_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogWindow->MemOSDBorderS, Border_SW_Gd->width, 0, Border_S_Gd->width, Border_S_Gd->height, FBDialogWindow->NrInfoSColumns - 1, X);
  }

  TAP_Osd_PutFreeColorGd_Chk("BuildWindowBorder L", FBDialogWindow->MemOSDBorderS, Border_SW_Gd->width + FBDialogWindow->NrInfoSColumns * Border_S_Gd->width, 0, Border_SE_Gd, TRUE, FBDialogProfile->BorderColor);

  FBDialogWindow->OSDBorderBackDirty = TRUE;
}
