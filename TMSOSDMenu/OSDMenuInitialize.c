#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

//#include                "graphic/InfoBox.gd"

word                    OSDMenuSelectionBarRgn = 0;
bool                    OSDDirty, TitleDirty, ListDirty, ButtonsDirty, LogoDirty;
tMenu                   Menu[NRMENULEVELS];
dword                   CurrentMenuLevel = 0;
dword                   ButtonColor;
dword                   LastUnprocessedOSDMenuKey = 0;
tCursorType             MenuCursorType;
tOSDMenuLastCursorType  OSDMenuLastCursor = LCT_NRCURSORS;

#ifdef FB_USE_UNICODE_OSD
  tFontDataUC           OSDMenuFont_10;
  tFontDataUC           OSDMenuFont_12;
  tFontDataUC           OSDMenuFont_14;
  tFontDataUC           OSDMenuFont_16;
  tFontDataUC           OSDMenuFont_18;
  tFontDataUC           OSDMenuFont_20;
  tFontDataUC           OSDMenuFont_20B;
#endif

void (*CallbackProcedure)(tOSDCB OSDCBType, word OSDRgn) = NULL;

void OSDMenuInitialize(bool AllowScrollingOfLongText, bool HasValueColumn, bool NumberedItems, bool ScrollLoop, char *TitleLeft, char *TitleRight)
{
  tMenu                *pMenu;
  int                   i;

  TRACEENTER();

  //Clear everything
  pMenu = &Menu[CurrentMenuLevel];

  memset(pMenu, 0, sizeof(tMenu));
  for(i = 0; i < 4; i++)
    pMenu->ButtonXStart[i] = 55;

  if(OSDRgn) TAP_Osd_Delete(OSDRgn);
  OSDRgn = 0;
  MyOSDRgn = 0;

#ifdef FB_USE_UNICODE_OSD
  OSDMenuLoadStdFonts();
#endif

  pMenu->AllowScrollingOfLongText = AllowScrollingOfLongText;
  pMenu->HasValueColumn = HasValueColumn;
  pMenu->NumberedItems = NumberedItems;
  pMenu->ScrollLoop = ScrollLoop;
  pMenu->ValueXPos = 350;
  pMenu->hasValueArrows = FALSE;
  pMenu->MaxItems = 30;
  pMenu->Item = TAP_MemAlloc(pMenu->MaxItems * sizeof(tItem));
  memset(&pMenu->Item[0], 0, pMenu->MaxItems * sizeof(tItem));

  pMenu->FontLeftTitle          = &OSDMenuFont_20;  // 20
  pMenu->FontRightTitle         = &OSDMenuFont_16;  // 16
  pMenu->FontListLineNumber     = &OSDMenuFont_14;
  pMenu->FontListNameColumn     = &OSDMenuFont_14;
  pMenu->FontListValueColumn    = &OSDMenuFont_14;
  pMenu->FontButtons            = &OSDMenuFont_12;
  pMenu->FontMemo               = &OSDMenuFont_14;


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

  pMenu->OSDMenuDisplayMode = OMDM_Standard;
  ButtonColor = RGB(230, 230, 250);

  MenuCursorType = CT_Standard;

  CallbackProcedure = NULL;

  TRACEEXIT();
}
