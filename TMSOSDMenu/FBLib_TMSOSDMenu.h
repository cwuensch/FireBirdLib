#ifndef FBLIB_TMSOSDMENU_H
#define FBLIB_TMSOSDMENU_H

#include                "libFireBird.h"

#ifdef FB_USE_UNICODE_OSD
  extern tFontDataUC    OSDMenuFont_10;
  extern tFontDataUC    OSDMenuFont_12;
  extern tFontDataUC    OSDMenuFont_14;
  extern tFontDataUC    OSDMenuFont_16;
  extern tFontDataUC    OSDMenuFont_18;
  extern tFontDataUC    OSDMenuFont_20;
  extern tFontDataUC    OSDMenuFont_20B;
#else
  #define tFontDataUC                 tFontData
  #define FMUC_GetStringHeight(...)   FM_GetStringHeight( __VA_ARGS__ )
  #define FMUC_GetStringWidth(...)    FM_GetStringWidth( __VA_ARGS__ )
  #define FMUC_PutString(...)         FM_PutString( __VA_ARGS__ )
  #define FMUC_PutStringAA(...)       FM_PutStringAA( __VA_ARGS__ )
  #define OSDMenuFont_10              Calibri_10_FontData
  #define OSDMenuFont_12              Calibri_12_FontData
  #define OSDMenuFont_14              Calibri_14_FontData
  #define OSDMenuFont_16              Calibri_16_FontData
  #define OSDMenuFont_18              Calibri_18_FontData
  #define OSDMenuFont_20              Calibri_20_FontData
  #define OSDMenuFont_20B             Calibri_20B_FontData
#endif

#define ITEMNAMESIZE    128
#define ITEMVALUESIZE   128
#define STDSTRINGSIZE   256
#define NRMENULEVELS     5
#define MAXMBBUTTONS     5
#define FONTYOFFSET     -3
#define INFOBOX_WIDTH   380
#define INFOBOX_HEIGHT  190

#define WaitSpinnerItems       12
#define WaitSpinnerItemWidth    6
#define WaitSpinnerItemHeight  14
#define WaitSpinnerWidth       ((2 * WaitSpinnerItems - 1) * WaitSpinnerItemWidth)
#define WaitSpinnerItemsTrail   8
#define WaitSpinnerSpeed       10
#define WaitSpinnerItemColorBlank RGB(192, 192, 192)
#define WaitSpinnerItemColorShade -64   // shade to RGB(128, 128, 128)
#define WaitSpinnerItemColorTrail RGB(120, 120, 120)

extern dword WaitSpinnerPosY;

typedef struct
{
  char                  Name[ITEMNAMESIZE];
  char                  Value[ITEMVALUESIZE];
  TYPE_GrData          *pNameIconGd;
  TYPE_GrData          *pValueIconGd;
  dword                 ColorPatch;
  dword                 NameColor;
  dword                 TextColor;
  bool                  Selectable;
  bool                  ValueArrows;
  dword                 ID;
  int                   CustomIndex;
}tItem;

typedef struct
{
  dword                 X;
  dword                 Y;
  TYPE_GrData          *pButtonGd;
  dword                 Color;
  char                  Text[STDSTRINGSIZE];
}tButtons;

typedef enum
{
  OMDM_Standard,
  OMDM_Memo,
  OMDM_Text            // like Memo, but CurrentTopIndex won't follow CurrentSelection
} tOSDMenuDisplayMode;

typedef struct
{
  int                   NrLines;
  tItem                *Item;
  int                   NrItems;
  int                   MaxItems;
  int                   CurrentSelection;
  int                   CurrentTopIndex;
  bool                  AllowScrollingOfLongText;
  bool                  HasValueColumn;
  dword                 ValueXPos;
  int                   ValueXOffset;
  bool                  ScrollLoop;
  bool                  NumberedItems;
  bool                  hasValueArrows;
  tButtons              Buttons[20];
  dword                 NrButtons;
  dword                 ButtonXStart[4];
  char                  TitleLeft[STDSTRINGSIZE];
  char                  TitleRight[STDSTRINGSIZE];
  dword                 LogoX;
  dword                 LogoY;
  TYPE_GrData          *pLogoGd;
  dword                 PrevLogoX;
  dword                 PrevLogoY;
  dword                 PrevLogoW;
  dword                 PrevLogoH;
  char                 *MemoText;
  tOSDMenuDisplayMode   OSDMenuDisplayMode;
  tFontDataUC          *FontLeftTitle;
  tFontDataUC          *FontRightTitle;
  tFontDataUC          *FontListLineNumber;
  tFontDataUC          *FontListNameColumn;
  tFontDataUC          *FontListValueColumn;
  tFontDataUC          *FontButtons;
  tFontDataUC          *FontMemo;
}tMenu;

typedef struct
{
  dword                 NrButtons;
  dword                 CurrentButton;
  char                  Button[MAXMBBUTTONS][STDSTRINGSIZE];
  char                  Title[STDSTRINGSIZE];
  char                  Text[STDSTRINGSIZE];
//  tFontDataUC          *FontColorPickerTitle;
//  tFontDataUC          *FontColorPickerCursor;
}tMessageBox;

typedef enum
{
  CCS_Red,
  CCS_Green,
  CCS_Blue
}tCurrentColorSelected;

typedef enum
{
  LCT_Blue,
  LCT_BlueDark,
  LCT_NRCURSORS
} tOSDMenuLastCursorType;

#ifndef FB_USE_UNICODE_OSD
  extern tFontData      Calibri_10_FontData;
  extern tFontData      Calibri_12_FontData;
  extern tFontData      Calibri_14_FontData;
  extern tFontData      Calibri_16_FontData;
  extern tFontData      Calibri_18_FontData;
  extern tFontData      Calibri_20_FontData;
  extern tFontData      Calibri_20B_FontData;
#endif


extern word             OSDRgn;
extern word             MyOSDRgn; //Used by OSDMenuSaveMyRegion()
extern word             OSDMenuSelectionBarRgn;
extern bool             OSDDirty, TitleDirty, ListDirty, ButtonsDirty, LogoDirty;
extern tMenu            Menu[NRMENULEVELS];
extern dword            CurrentMenuLevel;
extern dword            ButtonColor;
extern dword            LastUnprocessedOSDMenuKey;
extern tCursorType      MenuCursorType;
extern tOSDMenuLastCursorType    OSDMenuLastCursor;

extern word             InfoBoxOSDRgn;
extern dword            InfoBoxTimeOut;
extern byte            *InfoBoxSaveArea;
extern dword            InfoBoxSaveAreaX, InfoBoxSaveAreaY;

extern word             MessageBoxOSDRgn;
extern tMessageBox      MessageBox;
extern bool             MessageBoxNoNormalMode;
extern bool             MessageBoxAllowScrollOver;

extern word             ProgressBarOSDRgn;
extern word             ProgressBarFullRgn;
extern dword            ProgressBarLastValue;

extern word             ColorPickerOSDRgn;
extern dword            ColorPickerColor;
extern dword            ColorPickerDefaultColor;
extern tCurrentColorSelected  CurrentColorSelected;
extern int              ColorPickerLastCursorRed, ColorPickerLastCursorGreen, ColorPickerLastCursorBlue;

extern word             WaitSpinnerRgn;
extern int              WaitSpinnerIndex;
extern dword            WaitSpinnerTimeout;

int  OSDMenuFindNextSelectableEntry(int CurrentSelection);
int  OSDMenuFindPreviousSelectableEntry(int CurrentSelection);
void OSDCalcIndices(void);
void OSDDrawBackground(void);
void OSDDrawButtons(void);
void OSDDrawList(void);
void OSDDrawLogo(void);
void OSDDrawMemo(void);
void OSDDrawScrollBar(void);
void OSDDrawTitle(void);
void OSDMemoFormatText(void);
void OSDMenuColorPickerDrawCursor(tCurrentColorSelected CursorColor, bool Selected);
void OSDMenuDrawCursor(dword x, dword y, dword w, dword h);
void OSDMenuFreeStdFonts(void);
TYPE_GrData *OSDMenuGetIconPointer(tButtonIcon ButtonIcon, TYPE_GrData *UserDefinedButton);
void OSDMenuLoadStdFonts(void);
void OSDMenuWaitSpinnerIdle(void);
void OSDMenuWaitSpinnerDrawItem(word rgn, dword x, dword rgb);
dword OSDMenuWaitSpinnerShadeColor(dword rgb, word step, word steps);

void OSDMenuInfoBoxDraw(word rgn);

extern void (*CallbackProcedure)(tOSDCB OSDCBType, word OSDRgn);

#endif
