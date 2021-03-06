#include                <string.h>
#include                "tap.h"
#include                "libFireBird.h"

/* #include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_SkipLeft.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_SkipRight.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_Slow_Inactive.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_Rwd_Inactive.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_Ffwd_Inactive.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_Pause_Inactive.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_Play_Inactive.gd" */

#include                "../../TMSOSDMenu/graphic/Button_jumpstart.gd"
#include                "../../TMSOSDMenu/graphic/Button_jumpend.gd"
#include                "../../TMSOSDMenu/graphic/Button_step.gd"
#include                "../../TMSOSDMenu/graphic/Button_rwd.gd"
#include                "../../TMSOSDMenu/graphic/Button_ffwd.gd"
#include                "../../TMSOSDMenu/graphic/Button_pause.gd"
#include                "../../TMSOSDMenu/graphic/Button_play.gd"
#include                "../../TMSOSDMenu/graphic/Button_recall.gd"
#include                "../../TMSOSDMenu/graphic/Button_blue.gd"
#include                "../../../TAP/SamplesTMS/MovieCutter/source/Graphics/Button_Exit.gd"
#include                "../../TMSOSDMenu/graphic/Button_stop.gd"

#define PROGRAM_NAME    "OSDKeyboard Demo"
#define VERSION         "V0.2"

TAP_ID                  (0x8E0Affff);
TAP_PROGRAM_NAME        (PROGRAM_NAME" "VERSION);
TAP_AUTHOR_NAME         ("FireBird");
TAP_DESCRIPTION         ("OSDKeyboard Demo");
TAP_ETCINFO             (__DATE__);

char                    Text[100];

dword TAP_EventHandler(word event, dword param1, dword param2)
{
  (void) param2;

  //The event handler returns true if the user has clicked exit
  //The keyboard does not enter normal mode if the Toppy wasn't in normal during the first call of the event handler
  //It's the responsibility of the caller to restore the OSD. The keyboard deletes its OSD region but doesn't do any OSD update.
  if(OSDMenuKeyboard_EventHandler(&event, &param1, &param2))
  {
    //Output the text on the telnet console and exit the demo
    TAP_Print("OSD Keyboard = '%s'\n", Text);
    DumpMemory(Text, strlen(Text), 16);
    TAP_Exit();
  }

  //Do not pass any key events to the next TAP / the firmware
  if(event == EVT_KEY) param1 = 0;

  return param1;
}

int TAP_Main(void)
{
  KeyTranslate(TRUE, &TAP_EventHandler);

  strcpy(Text, "Test");

  //Initialize the Keyboard
  //Right now, there is no save or exit. Whenever the remote control's exit is clicked, the contents of the textbox will be copied into the destination variable.
  OSDMenuKeyboard_Setup("Keyboard Test", Text, sizeof(Text));

/*  OSDMenuKeyboard_LegendButton(1, &_Button_SkipLeft_Gd, "");
  OSDMenuKeyboard_LegendButton(1, &_Button_SkipRight_Gd, "Cursor bewegen  ");
  OSDMenuKeyboard_LegendButton(1, &_Button_Slow_Inactive_Gd, "Zum Ende  ");
  OSDMenuKeyboard_LegendButton(1, &_Button_Rwd_Inactive_Gd, "");
  OSDMenuKeyboard_LegendButton(1, &_Button_Ffwd_Inactive_Gd, "Löschen");
  OSDMenuKeyboard_LegendButton(2, &_Button_Pause_Inactive_Gd, "Groß-/Kleinbuchst.  ");
  OSDMenuKeyboard_LegendButton(2, &_Button_Play_Inactive_Gd, "Sonderzeichen"); */

  OSDMenuKeyboard_LegendButton(1, &_Button_jumpstart_Gd, "");
  OSDMenuKeyboard_LegendButton(1, &_Button_jumpend_Gd, "Cursor bewegen   ");
  OSDMenuKeyboard_LegendButton(1, &_Button_step_Gd, "Ende   ");
  OSDMenuKeyboard_LegendButton(1, &_Button_rwd_Gd, "");
  OSDMenuKeyboard_LegendButton(1, &_Button_ffwd_Gd, "Zeichen löschen");
  OSDMenuKeyboard_LegendButton(2, &_Button_pause_Gd, "Groß-/Kleinbuchst.  ");
  OSDMenuKeyboard_LegendButton(2, &_Button_play_Gd, "Sonderzeichen");
  OSDMenuKeyboard_LegendButton(3, &_Button_recall_Gd, "Original ");
  OSDMenuKeyboard_LegendButton(3, &_Button_blue_Gd, "Alles löschen   ");
  OSDMenuKeyboard_LegendButton(3, &_Button_Exit_Gd, "Abbrechen ");
  OSDMenuKeyboard_LegendButton(3, &_Button_stop_Gd, "Speichern");
  return 1;
}
