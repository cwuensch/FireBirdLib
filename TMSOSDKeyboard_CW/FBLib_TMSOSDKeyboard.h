#ifndef FBLIB_TMSOSDKEYBOARD_H
  #define FBLIB_TMSOSDKEYBOARD_H

  #include              "../libFireBird.h"
  #include              "../TMSOSDMenu/FBLib_TMSOSDMenu.h"
  #include              "TMSRemote_TAPCOM.h"
  #include              "USBKeyboard.h"

  #define DICTIONARYPATH         TAPFSROOT "/ProgramFiles/Settings/Dictionary.txt"

  #define NRKEYROWS              4
  #define NRKEYCOLS              9
  #define NRKEYPADNORMALKEYS    27
  #define NRKEYPADSPECIALKEYS    7
  #define NRKEYPADCOLORBUTTONS   5
  #define NRKEYALTSYMBOLS        8
  #define MAXSUGGESTIONLENGTH  256
  #define DICTHEAPSIZE        4096   // 20
  #define DICTENTRIES          500   //  4

  typedef enum
  {
    KPM_LettersCAPS,
    KPM_Letters,
    KPM_Symbols,
    KPM_NrModes
  } tKeyPadMode;

  typedef enum
  {
    KEY_A,      KEY_B,   KEY_C,   KEY_D,  KEY_E,  KEY_F,  KEY_G,  KEY_H,  KEY_I,
    KEY_J,      KEY_K,   KEY_L,   KEY_M,  KEY_N,  KEY_O,  KEY_P,  KEY_Q,  KEY_R,
    KEY_Shift,  KEY_S,   KEY_T,   KEY_U,  KEY_V,  KEY_W,  KEY_X,  KEY_Y,  KEY_Z,
    KEY_BackSp, KEY_Del, KEY_Alt,   KEY_Space  ,   KEY_Cancel  ,    KEY_Save   ,
    NrKeyPadKeys
  } tKeyPadKeys;

  typedef struct
  {
    byte                ColSpan;
    TYPE_GrData        *Icon;
    char               *Text;
  } tKeyPadButton;


  extern const char     Keypad[KPM_NrModes][NRKEYPADNORMALKEYS][NRKEYALTSYMBOLS];
  extern const char     T9Array[10][7];
  extern const char     T9ArrayCaps[10][7];
  extern tKeyPadButton  SpecialKeys[NRKEYPADSPECIALKEYS];
  extern tKeyPadButton  ColorButtons[NRKEYPADCOLORBUTTONS];

  extern char          *Keyb_Clipboard;

  extern char          *Keyb_DictHeap;
  extern int           *Keyb_Dictionary;
  extern int            Keyb_DictHeapSize, Keyb_DictHeapPos;
  extern int            Keyb_DictNrEntries, Keyb_DictMaxEntries;

  extern int            Keyb_SugOffset, Keyb_InsertedChars;
  extern int            Keyb_NrSug, Keyb_FirstSug, Keyb_CurSug;

  extern char          *OSDKeyboard_Title;
  extern char          *OSDKeyboard_StringVar;
  extern char          *OSDKeyboard_StringVarOrig;
  extern dword          OSDKeyboard_StringMaxLen;

  extern word           OSDKeyboard_rgn;
  extern bool           OSDKeyboard_ReturnToNormal;
  extern bool           OSDKeyboard_AllowEmpty;
  extern bool           OSDKeyboard_SaveDict;
  extern bool           OSDKeyboard_SavedVar;

  extern int            OSDKeyboard_CursorPosition;
  extern int            OSDKeyboard_TextStartPosition;

  extern tKeyPadMode    KeyPadMode;
  extern byte           KeyPadShiftState;  // 0: FALSE, 1: TRUE, 2: CAPSLOCK
  extern bool           KeyPadCursorMode;
  extern int            KeyPadSelection;
  extern tKeyPadKeys    KeyPadPosition;


  void AddWordToDict(const char* newWord);
  void OSDKeyboard_DrawAll(void);
  void OSDKeyboard_DrawKeys(bool DoSync);
  void OSDKeyboard_DrawKeySelection(void);
  void OSDKeyboard_DrawText(void);
  void OSDKeyboard_DrawSuggesion(void);
  void OSDKeyboard_TMSRemoteDirectMode(bool DirectMode);
#endif
