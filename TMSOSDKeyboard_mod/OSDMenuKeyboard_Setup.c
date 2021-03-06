#include                <string.h>
#include                "FBLib_TMSOSDKeyboard.h"
#include                "../TMSOSDMenu/graphic/TextCursor14.gd"

char                    OSDMenuKeyboard_Clipboard[MAX_FILE_NAME_SIZE + 1];

char                   *OSDMenuKeyboard_Title = NULL;
char                   *OSDMenuKeyboard_StringVar = NULL;
char                   *OSDMenuKeyboard_StringVarOrig = NULL;
dword                   OSDMenuKeyboard_StringMaxLen = 0;
int                     OSDMenuKeyboard_CursorPosition = 0;
int                     OSDMenuKeyboard_TextStartPosition = 0;
int                     OSDMenuKeyboard_ButtonsX[3];
tOSDMenuKeyboard_Buttons OSDMenuKeyboard_Buttons[20];
int                     OSDMenuKeyboard_NrButtons = 0;

char                    Keypad[KPM_NrModes][26] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                                                   {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
//                                                 {'À', 'à', 'Á', 'á', 'Â', 'â', 'Ã', 'ã', 'Å', 'å', 'Æ', 'æ', 'Ç', 'ç', 'È', 'è', 'É', 'é', 'Ê', 'ê', 'Ë', 'ë', 'Ð', 'ð', ' ', ' '},
//                                                 {'Ì', 'ì', 'Í', 'í', 'Î', 'î', 'Ï', 'ï', 'Ñ', 'ñ', 'Ò', 'ò', 'Ó', 'ó', 'Ô', 'ô', 'Õ', 'õ', 'Ø', 'ø', 'Ù', 'ù', 'Ú', 'ú', 'Û', 'û'},
//                                                 {'Ý', 'ý', 'Þ', 'þ', 'µ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

                                                   {'Ä', 'ä', 'Ö', 'ö', 'Ü', 'ü', 'ß', '|', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', ',', '.', ':', '+', '-', '_', '(', ')'},
                                                   {'?', '!', ';', '=', '"', '\'','§', '$', '%', '&', '/', '\\','[', ']', '{', '}', '<', '>', '*', '#', '^', '~', '°', '@', '´', '`'},
                                                   {'à', 'á', 'â', 'ã', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ð', 'ì', 'í', 'î', 'ï', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ø', 'ù', 'ú', 'û', 'ý'},
                                                   {'À', 'Á', 'Â', 'Ã', 'Å', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ð', 'Ì', 'Í', 'Î', 'Ï', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ø', 'Ù', 'Ú', 'Û', 'Ý'}, 
                                                   {'þ', 'Þ', 'ÿ', 'µ', '±', '×', '÷', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

//                                                {{'a', 'ä', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'ö', 'p', 'q', 'r', 's', 'ß', 't', 'u', 'ü', 'v', 'w', 'x', 'y', 'z'},
//                                                 {'A', 'Ä', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'Ö', 'P', 'Q', 'R', 'S', 'ß', 'T', 'U', 'Ü', 'V', 'W', 'X', 'Y', 'Z'},
//                                                 {'!', '?', '§', '$', '%', '&', '=', '#', '~', '(', ')', '[', ']', '/', '\\','<', '>', '^', '.', ',', ':', ';', '*', '+', '-', '_', '|', '"', '\'','°'},
//                                                 {'à', 'á', 'â', 'ã', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ð', 'ì', 'í', 'î', 'ï', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ø', 'ù', 'ú', 'û', 'ý', 'ÿ', 'þ', 'µ', '×'},
//                                                 {'À', 'Á', 'Â', 'Ã', 'Å', 'Æ', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ð', 'Ì', 'Í', 'Î', 'Ï', 'Ñ', 'Ò', 'Ó', 'Ô', 'Õ', 'Ø', 'Ù', 'Ú', 'Û', 'Ý', ' ', 'Þ', '±', '÷'}};

tKeyPadMode             KeyPadMode = KPM_Letters;
bool                    KeyPadShiftState = FALSE;
bool                    KeyPadCursorMode = FALSE;
int                     KeyPadPosition = 0;
word                    OSDMenuKeyboard_rgn = 0;
bool                    OSDMenuKeyboard_ReturnToNormal;

void OSDMenuKeyboard_Setup(char *Titel, char *Variable, dword MaxLength)
{
  static bool FirstRun = TRUE;
  if(FirstRun)
  {
    OSDMenuKeyboard_Clipboard[0] = '\0';
    FirstRun = FALSE;
  }

  OSDMenuKeyboard_Title = TAP_MemAlloc(strlen(Titel) + 1);
  strcpy(OSDMenuKeyboard_Title, Titel);
  OSDMenuKeyboard_StringVar = TAP_MemAlloc(MaxLength + 4);
  memset(OSDMenuKeyboard_StringVar, 0, MaxLength + 4);
  strncpy(OSDMenuKeyboard_StringVar, Variable, MaxLength);

  OSDMenuKeyboard_TextStartPosition = 0;
  OSDMenuKeyboard_NrButtons = 0;
  OSDMenuKeyboard_ButtonsX[0] = 10;
  OSDMenuKeyboard_ButtonsX[1] = 10;
  OSDMenuKeyboard_ButtonsX[2] = 10;

  OSDMenuKeyboard_StringVarOrig = Variable;

  OSDMenuKeyboard_StringMaxLen = MaxLength;

  KeyPadMode = KPM_Letters;
  KeyPadShiftState = FALSE;
  KeyPadCursorMode = FALSE;
  KeyPadPosition = 0;
}
