#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

TYPE_GrData *OSDMenuGetIconPointer(tButtonIcon ButtonIcon, TYPE_GrData *UserDefinedButton)
{
  switch(ButtonIcon)
  {
    case BI_None        : return NULL;
    case BI_UserDefined : return UserDefinedButton;
    case BI_Red         : return &_Button_red_Gd;
    case BI_Green       : return &_Button_green_Gd;
    case BI_Yellow      : return &_Button_yellow_Gd;
    case BI_Blue        : return &_Button_blue_Gd;
    case BI_White       : return &_Button_white_Gd;
    case BI_Menu        : return &_Button_menu_Gd;
    case BI_Info        : return &_Button_info_Gd;
    case BI_Ok          : return &_Button_ok_Gd;
    case BI_Exit        : return &_Button_exit_Gd;
    case BI_Record      : return &_Button_record_Gd;
    case BI_Select      : return &_Button_select_Gd;
    case BI_Ffwd        : return &_Button_ffwd_Gd;
    case BI_Rwd         : return &_Button_rwd_Gd;
    case BI_JumpStart   : return &_Button_jumpstart_Gd;
    case BI_JumpEnd     : return &_Button_jumpend_Gd;
    case BI_Sat         : return &_Button_sat_Gd;
  }

  return NULL;
}

#endif
