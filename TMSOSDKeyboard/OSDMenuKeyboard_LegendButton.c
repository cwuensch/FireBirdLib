#include                <string.h>
#include                "FBLib_TMSOSDKeyboard.h"

void OSDMenuKeyboard_LegendButton(dword Line, TYPE_GrData *ButtonGd, char *Text)
{
  if(OSDMenuKeyboard_NrButtons < 20)
  {
    OSDMenuKeyboard_Buttons[OSDMenuKeyboard_NrButtons].Line = Line;
    OSDMenuKeyboard_Buttons[OSDMenuKeyboard_NrButtons].ButtonGd = ButtonGd;
    strncpy(OSDMenuKeyboard_Buttons[OSDMenuKeyboard_NrButtons].Text, Text, 20);
    OSDMenuKeyboard_Buttons[OSDMenuKeyboard_NrButtons].Text[19] = '\0';

    OSDMenuKeyboard_NrButtons++;
  }
}
