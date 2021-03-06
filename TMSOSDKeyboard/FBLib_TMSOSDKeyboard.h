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

  extern bool           OSDMenuKeyboard_GUIInitialized;

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
  extern char           Keypad[KPM_NrModes][26][2];
  extern tKeyPadMode    KeyPadMode;
  extern bool           KeyPadShiftState;
  extern bool           KeyPadCursorMode;
  extern int            KeyPadPosition;
  extern word           OSDMenuKeyboard_rgn;
  extern tFontData      Calibri_14_FontData;
  extern bool           OSDMenuKeyboard_ReturnToNormal;

  void OSDMenuKeyboard_DrawAll(void);
  void OSDMenuKeyboard_DrawKeys(void);
  void OSDMenuKeyboard_DrawText(void);
  void OSDMenuKeyboard_DrawLegendButton(dword Line, TYPE_GrData *ButtonGd, char *Text);
  void OSDMenuKeyboard_TMSRemoteDirectMode(bool DirectMode);
  void OSDMenuKeyboard_CursorRight(void);
  void OSDMenuKeyboard_CursorLeft(void);
  void OSDMenuKeyboard_CursorEnd(void);
  void OSDMenuKeyboard_DeleteRight(void);
  void OSDMenuKeyboard_DeleteLeft(void);
  void OSDMenuKeyboard_Finish(void);
  void OSDMenuKeyboard_SaveAndFinish(void);
  void OSDMenuKeyboard_SetShiftState(void);

#endif
