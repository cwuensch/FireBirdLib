#include                "FBLib_dialog.h"

#include                "graphic_1555/MsgBox_W_Title.gd"
#include                "graphic_1555/MsgBox_W_SubTitle.gd"
#include                "graphic_1555/MsgBox_W_Border.gd"
#include                "graphic_1555/MsgBox_W_Text.gd"
#include                "graphic_1555/MsgBox_C_Title.gd"
#include                "graphic_1555/MsgBox_C_SubTitle.gd"
#include                "graphic_1555/MsgBox_C_Border.gd"
#include                "graphic_1555/MsgBox_C_Text.gd"
#include                "graphic_1555/MsgBox_E_Title.gd"
#include                "graphic_1555/MsgBox_E_SubTitle.gd"
#include                "graphic_1555/MsgBox_E_Border.gd"
#include                "graphic_1555/MsgBox_E_Text.gd"
#include                "graphic_1555/MsgBox_In.gd"
#include                "graphic_1555/MsgBox_Out.gd"

TYPE_GrData             *MsgBox_W_Title_Gd;
TYPE_GrData             *MsgBox_W_Border_Gd;
TYPE_GrData             *MsgBox_W_SubTitle_Gd;
TYPE_GrData             *MsgBox_W_Text_Gd;
TYPE_GrData             *MsgBox_C_Title_Gd;
TYPE_GrData             *MsgBox_C_Border_Gd;
TYPE_GrData             *MsgBox_C_SubTitle_Gd;
TYPE_GrData             *MsgBox_C_Text_Gd;
TYPE_GrData             *MsgBox_E_Title_Gd;
TYPE_GrData             *MsgBox_E_Border_Gd;
TYPE_GrData             *MsgBox_E_SubTitle_Gd;
TYPE_GrData             *MsgBox_E_Text_Gd;
TYPE_GrData             *MsgBox_In_Gd;
TYPE_GrData             *MsgBox_Out_Gd;

void DialogMsgBoxShow(void)
{
  dword                 State, SubState;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxShow");
#endif

  if (!FBDialogMsgBox || FBDialogMsgBox->isVisible || !FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  MsgBox_W_Title_Gd       = &_MsgBox_W_Title_Gd;
  MsgBox_W_Border_Gd      = &_MsgBox_W_Border_Gd;
  MsgBox_W_SubTitle_Gd    = &_MsgBox_W_SubTitle_Gd;
  MsgBox_W_Text_Gd        = &_MsgBox_W_Text_Gd;
  MsgBox_C_Title_Gd       = &_MsgBox_C_Title_Gd;
  MsgBox_C_Border_Gd      = &_MsgBox_C_Border_Gd;
  MsgBox_C_SubTitle_Gd    = &_MsgBox_C_SubTitle_Gd;
  MsgBox_C_Text_Gd        = &_MsgBox_C_Text_Gd;
  MsgBox_E_Title_Gd       = &_MsgBox_E_Title_Gd;
  MsgBox_E_Border_Gd      = &_MsgBox_E_Border_Gd;
  MsgBox_E_SubTitle_Gd    = &_MsgBox_E_SubTitle_Gd;
  MsgBox_E_Text_Gd        = &_MsgBox_E_Text_Gd;
  MsgBox_In_Gd            = &_MsgBox_In_Gd;
  MsgBox_Out_Gd           = &_MsgBox_Out_Gd;

  TAP_GetState (&State, &SubState);
  FBDialogMsgBox->isNormalMode = ((State == STATE_Normal) && (SubState == SUBSTATE_Normal));
  if (FBDialogMsgBox->isNormalMode) TAP_ExitNormal();

  if (!FBDialogMsgBox->InfoBoxTimeout)
  {
    // count buttons
    for (FBDialogMsgBox->NrButtons = 0; ((unsigned int) FBDialogMsgBox->NrButtons < sizeof1st(FBDialogMsgBox->ButtonText)) && *FBDialogMsgBox->ButtonText[FBDialogMsgBox->NrButtons]; FBDialogMsgBox->NrButtons++);
  }

  //MsgBoxes with less than 2 buttons look strange.
  FBDialogMsgBox->ExpandedBox = (FBDialogMsgBox->NrButtons < 2);
  FBDialogMsgBox->VirtualButtonCount = (FBDialogMsgBox->ExpandedBox ? 3 : FBDialogMsgBox->NrButtons);

  FBDialogMsgBox->DialogWidth = MsgBox_W_Title_Gd->width + FBDialogMsgBox->VirtualButtonCount * MsgBox_C_Title_Gd->width + MsgBox_E_Title_Gd->width;

  if ((int) FBDialogMsgBox->DefaultButton < 0) FBDialogMsgBox->DefaultButton = 0;
  if ((int) FBDialogMsgBox->DefaultButton >= FBDialogMsgBox->NrButtons) FBDialogMsgBox->DefaultButton = FBDialogMsgBox->NrButtons - 1;

  FBDialogMsgBox->SelectedButton = FBDialogMsgBox->DefaultButton;

  //Draw the main window
  if (!FBDialogMsgBox->MemOSDRgn)
  {
    //FBDialogMsgBox->MemOSDRgn = TAP_Osd_Create_Chk(0, 0, FBDialogMsgBox->DialogWidth, MsgBox_C_Border_Gd->height, 0, OSD_Flag_MemRgn);
    FBDialogMsgBox->MemOSDRgn = TAP_Osd_Create_Chk("DialogMsgBoxShow A", 0, 0, FBDialogMsgBox->DialogWidth, MsgBox_W_Title_Gd->height + MsgBox_W_SubTitle_Gd->height + MsgBox_W_Text_Gd->height, 0, OSD_Flag_MemRgn);

    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow A", FBDialogMsgBox->MemOSDRgn, 0, 0,                                                        MsgBox_W_Title_Gd,    TRUE, FBDialogProfile->TitleBackgroundColor);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow B", FBDialogMsgBox->MemOSDRgn, 0, MsgBox_W_Title_Gd->height,                                MsgBox_W_SubTitle_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow C", FBDialogMsgBox->MemOSDRgn, 0, MsgBox_W_Title_Gd->height + MsgBox_W_SubTitle_Gd->height, MsgBox_W_Text_Gd,     TRUE, FBDialogProfile->InfoBackgroundColor);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow D", FBDialogMsgBox->MemOSDRgn, 0, 0,                                                        MsgBox_W_Border_Gd,   TRUE, FBDialogProfile->BorderColor);

    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow E", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, 0, MsgBox_C_Title_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);
    OSDCopy(FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, 0, MsgBox_C_Title_Gd->width, MsgBox_C_Title_Gd->height, FBDialogMsgBox->VirtualButtonCount - 1, X);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow F", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, MsgBox_W_Title_Gd->height, MsgBox_C_SubTitle_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);
    OSDCopy(FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, MsgBox_W_Title_Gd->height, MsgBox_C_SubTitle_Gd->width, MsgBox_C_SubTitle_Gd->height, FBDialogMsgBox->VirtualButtonCount - 1, X);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow G", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, MsgBox_W_Title_Gd->height + MsgBox_W_SubTitle_Gd->height, MsgBox_C_Text_Gd, TRUE, FBDialogProfile->InfoBackgroundColor);
    OSDCopy(FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, MsgBox_W_Title_Gd->height + MsgBox_W_SubTitle_Gd->height, MsgBox_C_Text_Gd->width, MsgBox_C_Text_Gd->height, FBDialogMsgBox->VirtualButtonCount - 1, X);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow H", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, 0, MsgBox_C_Border_Gd, TRUE, FBDialogProfile->BorderColor);
    OSDCopy(FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width, 0, MsgBox_C_Border_Gd->width, MsgBox_C_Border_Gd->height, FBDialogMsgBox->VirtualButtonCount - 1, X);

    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow I", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width + FBDialogMsgBox->VirtualButtonCount * MsgBox_C_Title_Gd->width, 0,                                                        MsgBox_E_Title_Gd,    TRUE, FBDialogProfile->TitleBackgroundColor);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow J", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width + FBDialogMsgBox->VirtualButtonCount * MsgBox_C_Title_Gd->width, MsgBox_W_Title_Gd->height,                                MsgBox_E_SubTitle_Gd, TRUE, FBDialogProfile->TitleBackgroundColor);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow K", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width + FBDialogMsgBox->VirtualButtonCount * MsgBox_C_Title_Gd->width, MsgBox_W_Title_Gd->height + MsgBox_W_SubTitle_Gd->height, MsgBox_E_Text_Gd,     TRUE, FBDialogProfile->InfoBackgroundColor);
    TAP_Osd_PutFreeColorGd_Chk("DialogMsgBoxShow L", FBDialogMsgBox->MemOSDRgn, MsgBox_W_Title_Gd->width + FBDialogMsgBox->VirtualButtonCount * MsgBox_C_Title_Gd->width, 0,                                                        MsgBox_E_Border_Gd,   TRUE, FBDialogProfile->BorderColor);
  }

  if (!FBDialogMsgBox->OSDRgn)
    FBDialogMsgBox->OSDRgn = TAP_Osd_Create_Chk("DialogMsgBoxShow B", (720 - FBDialogMsgBox->DialogWidth) >> 1, (576 - MsgBox_C_Border_Gd->height) >> 1, FBDialogMsgBox->DialogWidth, GetOSDRegionHeight(FBDialogMsgBox->MemOSDRgn), 0, 0);

  FBDialogMsgBox->OSDSaveBox = TAP_Osd_SaveBox_Chk("DialogMsgBoxShow", FBDialogMsgBox->OSDRgn, 0, 0, FBDialogMsgBox->DialogWidth, GetOSDRegionHeight(FBDialogMsgBox->OSDRgn));
  TAP_Osd_Copy_Chk("DialogMsgBoxShow M", FBDialogMsgBox->MemOSDRgn, FBDialogMsgBox->OSDRgn, 0, 0, FBDialogMsgBox->DialogWidth, GetOSDRegionHeight(FBDialogMsgBox->MemOSDRgn), 0, 0, TRUE);

  FBDialogMsgBox->isVisible = TRUE;

  DrawMsgBoxTitle();
  DrawMsgBoxButtons();

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
