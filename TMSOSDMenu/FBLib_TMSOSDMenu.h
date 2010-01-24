#ifndef FBLIB_TMSOSDMENU_H
#define FBLIB_TMSOSDMENU_H

#include                "tap.h"
#include                "..\libFireBird.h"

#define MAXITEMS        100
#define ITEMNAMESIZE    64
#define ITEMVALUESIZE   64
#define STDSTRINGSIZE   64
#define NRMENULEVELS     5
#define MAXMBBUTTONS     5
#define FONTYOFFSET     -3

typedef struct
{
  char                  Name[ITEMNAMESIZE];
  char                  Value[ITEMVALUESIZE];
  TYPE_GrData          *pNameIconGd;
  TYPE_GrData          *pValueIconGd;
  bool                  Selectable;
  bool                  ValueArrows;
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
  tItem                 Item[MAXITEMS];
  int                   NrItems;
  int                   CurrentSelection;
  int                   CurrentTopIndex;
  bool                  AllowScrollingOfLongText;
  bool                  HasValueColumn;
  bool                  ScrollLoop;
  bool                  NumberedItems;
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

extern tFontData        Calibri_12_FontData;
extern tFontData        Calibri_14_FontData;
extern tFontData        Calibri_16_FontData;
extern tFontData        Calibri_18_FontData;
extern tFontData        Calibri_20_FontData;
extern tFontData        Calibri_20B_FontData;

extern TYPE_GrData      _Button_blue_Gd;
extern TYPE_GrData      _Button_exit_Gd;
extern TYPE_GrData      _Button_ffwd_Gd;
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


extern word             OSDRgn;
extern bool             OSDDirty, TitleDirty, ListDirty, ButtonsDirty, LogoDirty;
extern tMenu            Menu[NRMENULEVELS];
extern dword            CurrentMenuLevel;

extern word             InfoBoxOSDRgn;
extern dword            InfoBoxTimeOut;

extern word             MessageBoxOSDRgn;
extern tMessageBox      MessageBox;


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

#endif