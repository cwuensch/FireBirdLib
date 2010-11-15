#ifndef FBLIB_TMSOSDMENU_H
#define FBLIB_TMSOSDMENU_H

#include                "tap.h"
#include                "../libFireBird.h"

#define ITEMNAMESIZE    128
#define ITEMVALUESIZE   128
#define STDSTRINGSIZE   256
#define NRMENULEVELS     5
#define MAXMBBUTTONS     5
#define FONTYOFFSET     -3

typedef struct
{
  char                  Name[ITEMNAMESIZE];
  char                  Value[ITEMVALUESIZE];
  TYPE_GrData          *pNameIconGd;
  TYPE_GrData          *pValueIconGd;
  dword                 ColorPatch;
  bool                  Selectable;
  bool                  ValueArrows;
  dword                 ID;
}tItem;

typedef struct
{
  dword                 X;
  dword                 Y;
  TYPE_GrData          *pButtonGd;
  char                  Text[STDSTRINGSIZE];
}tButtons;

typedef struct
{
  tItem                *Item;
  int                   NrItems;
  int                   MaxItems;
  int                   CurrentSelection;
  int                   CurrentTopIndex;
  bool                  AllowScrollingOfLongText;
  bool                  HasValueColumn;
  dword                 ValueXPos;
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
}tMenu;

typedef struct
{
  dword                 NrButtons;
  dword                 CurrentButton;
  char                  Button[MAXMBBUTTONS][STDSTRINGSIZE];
  char                  Title[STDSTRINGSIZE];
  char                  Text[STDSTRINGSIZE];
}tMessageBox;

typedef enum
{
  CCS_Red,
  CCS_Green,
  CCS_Blue
}tCurrentColorSelected;

typedef enum
{
  OMDM_Standard,
  OMDM_Memo
} tOSDMenuDisplayMode;

extern tFontData        Calibri_12_FontData;
extern tFontData        Calibri_14_FontData;
extern tFontData        Calibri_16_FontData;
extern tFontData        Calibri_18_FontData;
extern tFontData        Calibri_20_FontData;
extern tFontData        Calibri_20B_FontData;

extern TYPE_GrData      _Button_blue_Gd;
extern TYPE_GrData      _Button_exit_Gd;
extern TYPE_GrData      _Button_ffwd_Gd;
extern TYPE_GrData      _Button_filelist_Gd;
extern TYPE_GrData      _Button_green_Gd;
extern TYPE_GrData      _Button_info_Gd;
extern TYPE_GrData      _Button_jumpend_Gd;
extern TYPE_GrData      _Button_jumpstart_Gd;
extern TYPE_GrData      _Button_menu_Gd;
extern TYPE_GrData      _Button_ok_Gd;
extern TYPE_GrData      _Button_record_Gd;
extern TYPE_GrData      _Button_red_Gd;
extern TYPE_GrData      _Button_rwd_Gd;
extern TYPE_GrData      _Button_sat_Gd;
extern TYPE_GrData      _Button_select_Gd;
extern TYPE_GrData      _Button_white_Gd;
extern TYPE_GrData      _Button_yellow_Gd;
extern TYPE_GrData      _InfoBox_Gd;
extern TYPE_GrData      _Messagebox_Gd;
extern TYPE_GrData      _MessageBoxSelectedButtonBackground_Gd;
extern TYPE_GrData      _pfeil_lGd;
extern TYPE_GrData      _pfeil_rGd;
extern TYPE_GrData      _ScrollBarInvisible_Gd;
extern TYPE_GrData      _ScrollBarKnob_Gd;
extern TYPE_GrData      _ScrollBarVisible_Gd;
extern TYPE_GrData      _Selection_Bar_Gd;

extern TYPE_GrData      _ColorPicker_Gd;
extern TYPE_GrData      _ColorPicker_CursorNone_Gd;
extern TYPE_GrData      _ColorPicker_CursorDeselected_Gd;
extern TYPE_GrData      _ColorPicker_ValueBackroundSelected_Gd;

extern word             OSDRgn;
extern bool             OSDDirty, TitleDirty, ListDirty, ButtonsDirty, LogoDirty;
extern tMenu            Menu[NRMENULEVELS];
extern dword            CurrentMenuLevel;
extern tOSDMenuDisplayMode  OSDMenuDisplayMode;

extern word             InfoBoxOSDRgn;
extern dword            InfoBoxTimeOut;
extern byte            *InfoBoxSaveArea;
extern dword            InfoBoxSaveAreaX, InfoBoxSaveAreaY;

extern word             MessageBoxOSDRgn;
extern tMessageBox      MessageBox;

extern word             ProgressBarOSDRgn;
extern word             ProgressBarFullRgn;
extern dword            ProgressBarLastValue;

extern word             ColorPickerOSDRgn;
extern dword            ColorPickerColor;
extern dword            ColorPickerDefaultColor;
extern tCurrentColorSelected  CurrentColorSelected;
extern int              ColorPickerLastCursorRed, ColorPickerLastCursorGreen, ColorPickerLastCursorBlue;

int  OSDMenuGetW(const char * str, byte fntSize);
void OSDMenuPutS(word rgn, dword x, dword y, dword maxX, const char * str, dword fcolor, dword bcolor, byte fntSize, byte bDot, byte align);
TYPE_GrData *OSDMenuGetIconPointer(tButtonIcon ButtonIcon, TYPE_GrData *UserDefinedButton);
int  OSDMenuFindNextSelectableEntry(int CurrentSelection);
int  OSDMenuFindPreviousSelectableEntry(int CurrentSelection);
void OSDDrawBackground(void);
void OSDDrawTitle(void);
void OSDDrawLogo(void);
void OSDDrawButtons(void);
void OSDCalcIndices(void);
void OSDDrawScrollBar(void);
void OSDDrawList(void);
void OSDDrawMemo(void);
void OSDMenuColorPickerDrawCursor(tCurrentColorSelected CursorColor, bool Selected);

#endif
