#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

//extern TYPE_GrData      _InfoBox_gd

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

void OSDMenuInit(bool AllowScrollingOfLongText, bool HasValueColumn, bool NumberedItems, bool ScrollLoop, char *TitleLeft, char *TitleRight)
{
  tMenu                *pMenu;

  TRACEENTER();

  //Clear everything
  pMenu = &Menu[CurrentMenuLevel];

  memset(pMenu, 0, sizeof(tMenu));

#ifdef FB_USE_UNICODE_OSD
  OSDMenuLoadStdFonts();
#endif

  pMenu->OSDMenuDisplayMode = OMDM_Standard;
  pMenu->AllowScrollingOfLongText = AllowScrollingOfLongText;
  pMenu->HasValueColumn = HasValueColumn;
  pMenu->NumberedItems = NumberedItems;
  pMenu->ScrollLoop = ScrollLoop;
  pMenu->XPos = 60;
  pMenu->Width = 600;
  pMenu->ValueXPos = 350;
  pMenu->ValueXOffset = 15;
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
    strncpyUC(pMenu->TitleLeft, TitleLeft, STDSTRINGSIZE);
  else
    pMenu->TitleLeft[0] = '\0';
  pMenu->TitleLeft[STDSTRINGSIZE - 1] = '\0';

  if(TitleRight)
    strncpyUC(pMenu->TitleRight, TitleRight, STDSTRINGSIZE);
  else
    pMenu->TitleRight[0] = '\0';
  pMenu->TitleRight[STDSTRINGSIZE - 1] = '\0';

  pMenu->OSDMenuDisplayMode = OMDM_Standard;
  ButtonColor = RGB(230, 230, 250);

  MenuCursorType = CT_Standard;

  CallbackProcedure = NULL;

  TRACEEXIT();
}
