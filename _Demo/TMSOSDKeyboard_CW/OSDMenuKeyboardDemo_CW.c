#include                <string.h>
#include                "tap.h"
#include                "libFireBird.h"

#define PROGRAM_NAME    "OSDKeyboard Demo"
#define VERSION         "V0.2"

TAP_ID                  (0x8E0Affff);
TAP_PROGRAM_NAME        (PROGRAM_NAME" "VERSION);
TAP_AUTHOR_NAME         ("FireBird");
TAP_DESCRIPTION         ("OSDKeyboard Demo");
TAP_ETCINFO             (__DATE__);

extern char            *OSDMenuKeyboard_StringVar;
extern int              KeyPadPosition;

char                    Text[100];


// Die Funktion zeigt einen Informationsdialog (OK) an, und wartet auf die Bestätigung des Benutzers.
void ShowErrorMessage(char *MessageStr, char *TitleStr)
{
  dword OldSysState, OldSysSubState;

  TRACEENTER();
  HDD_TAP_PushDir();
  TAP_GetState(&OldSysState, &OldSysSubState);

  OSDMenuMessageBoxInitialize((TitleStr) ? TitleStr : PROGRAM_NAME, MessageStr);
  OSDMenuMessageBoxDoNotEnterNormalMode(TRUE);
  OSDMenuMessageBoxButtonAdd("OK");
  OSDMenuMessageBoxShow();

  while (OSDMenuMessageBoxIsVisible())
  {
    TAP_SystemProc();
    TAP_Sleep(1);
  }

  TAP_Osd_Sync();
  if(OldSysSubState != 0) TAP_EnterNormalNoInfo();

  HDD_TAP_PopDir();
  TRACEEXIT();
}


dword TAP_EventHandler(word event, dword param1, dword param2)
{
  (void) param2;

  TRACEENTER();

//if (event == EVT_KEY || event == EVT_TMSREMOTEASCII)
//  TAP_PrintNet("MessageBox = %d, Keyboard = %d, event = %u, param1 = %lu\n", OSDMenuMessageBoxIsVisible(), OSDMenuKeyboard_isVisible(), event, param1);

  // Behandlung offener MessageBoxen (rekursiver Aufruf, auch bei DoNotReenter)
  if(OSDMenuMessageBoxIsVisible())
  {
    OSDMessageEvent(&event, &param1, &param2);
    param1 = 0;
  }

  // Behandlung der OSD-Tastatur, falls offen (auch bei DoNotReenter?)
  else if(OSDMenuKeyboard_isVisible())
  {
    if ( (event == EVT_KEY && param1 == RKEY_Stop)
      || (event == EVT_KEY && param1 == RKEY_Ok && KeyPadPosition == 28)
      || (EVT_TMSREMOTEASCII && (param1 == 0x0D || param1 == 0x0171)) )
    {
      // Wenn Name ungültig, Meldung anzeigen
      if (strchr(OSDMenuKeyboard_StringVar, '/'))
      {
        ShowErrorMessage("Zeichen '/' ist nicht erlaubt!", NULL);
        param1 = 0;
      }
    }
    OSDMenuKeyboard_EventHandler(&event, &param1, &param2);
    param1 = 0;
  }

  return param1;
}

int TAP_Main(void)
{
  KeyTranslate(TRUE, &TAP_EventHandler);

  strcpy(Text, "Test");

  //Initialize the Keyboard
  //Right now, there is no save or exit. Whenever the remote control's exit is clicked, the contents of the textbox will be copied into the destination variable.
  OSDMenuKeyboard_Setup("Keyboard Test", Text, sizeof(Text), TRUE, TRUE);

  OSDMenuKeyboard_Show();
  while (OSDMenuKeyboard_isVisible())
  {
    TAP_SystemProc();
    TAP_Sleep(1);
  }

  TAP_PrintNet("Eingabe: %s\n", Text);

  return 0;
}
