#ifndef FBLIB_TMSOSDKEYBOARD_H
  #define FBLIB_TMSOSDKEYBOARD_H

  #include              "../libFireBird.h"
  #include              "OSDMenuKeyboard_Colors.h"
  #include              "TMSRemote_TAPCOM.h"

  #define NRKEYPADKEYS    29

  typedef enum
  {
    KPM_Letters,
    KPM_LettersCAPS,
    KPM_Num,
    KPM_Symbols,
    KPM_Special,
    KPM_SpecialCAPS,
    KPM_SpecialChars3,
    KPM_NrModes
  } tKeyPadMode;

  typedef struct
  {
    dword               Line;
    TYPE_GrData        *ButtonGd;
    char                Text[20];
  } tOSDMenuKeyboard_Buttons;

  extern tFontData      Calibri_14_FontData;
  extern word           OSDMenuKeyboard_rgn;
  extern bool           OSDMenuKeyboard_ReturnToNormal;

  extern char           OSDMenuKeyboard_Clipboard[MAX_FILE_NAME_SIZE + 1];
  extern char          *OSDMenuKeyboard_Title;
  extern char          *OSDMenuKeyboard_StringVar;
  extern char          *OSDMenuKeyboard_StringVarOrig;
  extern dword          OSDMenuKeyboard_StringMaxLen;
  extern int            OSDMenuKeyboard_CursorPosition;
  extern int            OSDMenuKeyboard_TextStartPosition;
  extern int            OSDMenuKeyboard_ButtonsX[3];
  extern tOSDMenuKeyboard_Buttons OSDMenuKeyboard_Buttons[20];
  extern int            OSDMenuKeyboard_NrButtons;
  extern char           Keypad[KPM_NrModes][26];
  extern tKeyPadMode    KeyPadMode;
  extern bool           KeyPadShiftState;
  extern bool           KeyPadCursorMode;
  extern int            KeyPadPosition;

  void OSDMenuKeyboard_DrawAll(void);
  void OSDMenuKeyboard_DrawKeys(void);
  void OSDMenuKeyboard_DrawText(void);
  void OSDMenuKeyboard_DrawLegendButton(dword Line, TYPE_GrData *ButtonGd, char *Text);
  bool OSDMenuKeyboard_EventHandler(word *event, dword *param1, dword *param2);
  void OSDMenuKeyboard_TMSRemoteDirectMode(bool DirectMode);
  void OSDMenuKeyboard_Destroy(void);

#endif
