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

  strncpy(pMenu->TitleLeft, TitleLeft, STDSTRINGSIZE);
  pMenu->TitleLeft[STDSTRINGSIZE - 1] = '\0';

  strncpy(pMenu->TitleRight, TitleRight, STDSTRINGSIZE);
  pMenu->TitleRight[STDSTRINGSIZE - 1] = '\0';
}

#endif
