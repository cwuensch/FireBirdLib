#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

#include                "graphic/Selection_Bar.gd"
#include                "graphic/Pfeil_l.gd"
#include                "graphic/Pfeil_r.gd"
#include                "graphic/ScrollBarInvisible.gd"
#include                "graphic/ScrollBarVisible.gd"
#include                "graphic/ScrollBarKnob.gd"
#include                "graphic/InfoBox.gd"
#include                "graphic/MessageBoxSelectedButtonBackground.gd"

#include                "graphic/Button_red.gd"
#include                "graphic/Button_green.gd"
#include                "graphic/Button_yellow.gd"
#include                "graphic/Button_blue.gd"
#include                "graphic/Button_white.gd"
#include                "graphic/Button_menu.gd"
#include                "graphic/Button_info.gd"
#include                "graphic/Button_ok.gd"
#include                "graphic/Button_exit.gd"
#include                "graphic/Button_record.gd"
#include                "graphic/Button_select.gd"
#include                "graphic/Button_ffwd.gd"
#include                "graphic/Button_rwd.gd"
#include                "graphic/Button_jumpstart.gd"
#include                "graphic/Button_jumpend.gd"
#include                "graphic/Button_sat.gd"

#include                "graphic/ColorPicker.gd"
#include                "graphic/ColorPicker_CursorNone.gd"
#include                "graphic/ColorPicker_CursorDeselected.gd"
#include                "graphic/ColorPicker_ValueBackroundSelected.gd"

#ifdef _TMS_

word                    OSDRgn = 0;
bool                    OSDDirty, TitleDirty, ListDirty, ButtonsDirty, LogoDirty;
tMenu                   Menu[NRMENULEVELS];
dword                   CurrentMenuLevel = 0;

word                    InfoBoxOSDRgn = 0;
dword                   InfoBoxTimeOut = 0;
byte                   *InfoBoxSaveArea = NULL;
dword                   InfoBoxSaveAreaX, InfoBoxSaveAreaY;

word                    MessageBoxOSDRgn = 0;
tMessageBox             MessageBox;

word                    ColorPickerOSDRgn = 0;
dword                   ColorPickerColor;
dword                   ColorPickerDefaultColor;
tCurrentColorSelected   CurrentColorSelected;
int                     ColorPickerLastCursorRed, ColorPickerLastCursorGreen, ColorPickerLastCursorBlue;

void OSDMenuInitialize(bool AllowScrollingOfLongText, bool HasValueColumn, bool NumberedItems, bool ScrollLoop, char *TitleLeft, char *TitleRight)
{
  tMenu                *pMenu;
  int                   i;

  //Clear everything
  pMenu = &Menu[CurrentMenuLevel];

  memset(pMenu, 0, sizeof(tMenu));
  for(i = 0; i < 4; i++)
    pMenu->ButtonXStart[i] = 55;

  if(OSDRgn) TAP_Osd_Delete(OSDRgn);
  OSDRgn = 0;

  pMenu->AllowScrollingOfLongText = AllowScrollingOfLongText;
  pMenu->HasValueColumn = HasValueColumn;
  pMenu->NumberedItems = NumberedItems;
  pMenu->ScrollLoop = ScrollLoop;
  pMenu->ValueXPos = 350;
  pMenu->Item = TAP_MemAlloc(30 * sizeof(tItem));
  pMenu->MaxItems = 30;
  memset(&pMenu->Item[0], 0, pMenu->MaxItems * sizeof(tItem));

  if(TitleLeft)
    strncpy(pMenu->TitleLeft, TitleLeft, STDSTRINGSIZE);
  else
    pMenu->TitleLeft[0] = '\0';
  pMenu->TitleLeft[STDSTRINGSIZE - 1] = '\0';

  if(TitleRight)
    strncpy(pMenu->TitleRight, TitleRight, STDSTRINGSIZE);
  else
    pMenu->TitleRight[0] = '\0';
  pMenu->TitleRight[STDSTRINGSIZE - 1] = '\0';
}

#endif
