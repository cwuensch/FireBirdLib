#include                <string.h>
#include                "FBLib_TMSOSDKeyboard.h"

void OSDMenuKeyboard_SetShiftState(void)
{
  bool NewKeyPadShiftState = ((OSDMenuKeyboard_CursorPosition == 0) || (OSDMenuKeyboard_StringVar[OSDMenuKeyboard_CursorPosition-1] == ' '));
  if (NewKeyPadShiftState != KeyPadShiftState)
  {
    KeyPadShiftState = NewKeyPadShiftState;
    if (KeyPadMode == KPM_Special || KeyPadMode == KPM_SpecialCAPS)
      KeyPadMode = (KeyPadShiftState) ? KPM_SpecialCAPS : KPM_Special;
    else if (KeyPadMode == KPM_Letters || KeyPadMode == KPM_LettersCAPS)
      KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters;
    OSDMenuKeyboard_DrawKeys();
  }
}

static bool OSDMenuKeyboard_isEmpty(void)
{
  return ((!OSDMenuKeyboard_StringVar[0]) || (OSDMenuKeyboard_StringVar[0] < 0x20 && !OSDMenuKeyboard_StringVar[1]));
}

bool OSDMenuKeyboard_EventHandler(word *event, dword *param1, dword *param2)
{
  (void) param2;

  if(OSDMenuKeyboard_StringVarOrig == NULL) return FALSE;

  if(!OSDMenuKeyboard_rgn)
  {
    OSDMenuKeyboard_CursorPosition = strlen(OSDMenuKeyboard_StringVar);
    OSDMenuKeyboard_TextStartPosition = 0;
    KeyPadPosition = 0;

    OSDMenuKeyboard_DrawAll();
    OSDMenuKeyboard_TMSRemoteDirectMode(TRUE);
    return FALSE;
  }

  if(!event || !param1) return FALSE;

  switch(*event)
  {
    case EVT_KEY:
    {
      switch(*param1)
      {
        case RKEY_Right:      //Zeichenauswahl rechts
        case RKEY_VolUp:
        {
          if (KeyPadCursorMode)
            OSDMenuKeyboard_CursorRight();
          else
          {
            KeyPadPosition++;
            switch(KeyPadPosition)
            {
              case  8: KeyPadPosition =  0; break;
              case 16: KeyPadPosition =  8; break;
              case 24: KeyPadPosition = 16; break;
              case 29: KeyPadPosition = 24; break;
            }
            OSDMenuKeyboard_DrawKeys();
          }
          break;
        }

        case RKEY_Left:       //Zeichenauswahl links
        case RKEY_VolDown:
        {
          if (KeyPadCursorMode)
            OSDMenuKeyboard_CursorLeft();
          else
          {
            KeyPadPosition--;
            switch(KeyPadPosition)
            {
              case -1: KeyPadPosition =  7; break;
              case  7: KeyPadPosition = 15; break;
              case 15: KeyPadPosition = 23; break;
              case 23: KeyPadPosition = 28; break;
            }
            OSDMenuKeyboard_DrawKeys();
          }
          break;
        }

        case RKEY_Down:       //Zeichenauswahl hinunter
        case RKEY_ChUp:
        {
          if (KeyPadCursorMode)
          {
            KeyPadCursorMode = FALSE;
            KeyPadPosition = 0;
          }
          else
          {
            //Spezialbehandlung durch die 2 grossen Tasten
            switch(KeyPadPosition)
            {
              case 18:
              case 19: KeyPadPosition = 26; break;
              case 20:
              case 21: KeyPadPosition = 27; break;
              case 22:
              case 23: KeyPadPosition = 28; break;

              case 24:  // KeyPadPosition =  0; break;
              case 25:  // KeyPadPosition =  1; break;
              case 26:  // KeyPadPosition =  2; break;
              case 27:  // KeyPadPosition =  4; break;
              case 28:  // KeyPadPosition =  6; break;
                KeyPadCursorMode = TRUE;
                break;

              default: KeyPadPosition += 8;
            }
          }
          OSDMenuKeyboard_DrawKeys();
          break;
        }

        case RKEY_Up:         //Zeichenauswahl hoch
        case RKEY_ChDown:
        {
          if (KeyPadCursorMode)
          {
            KeyPadCursorMode = FALSE;
            KeyPadPosition = 24;
          }
          else
          {
            //Spezialbehandlung durch die 2 grossen Tasten
            switch(KeyPadPosition)
            {
              case  0:  // KeyPadPosition = 24; break;
              case  1:  // KeyPadPosition = 25; break;
              case  2:
              case  3:  // KeyPadPosition = 26; break;
              case  4:
              case  5:  // KeyPadPosition = 27; break;
              case  6:
              case  7:  // KeyPadPosition = 28; break;
                KeyPadCursorMode = TRUE;
                break;

              case 27: KeyPadPosition = 20; break;
              case 28: KeyPadPosition = 22; break;
              default: KeyPadPosition -= 8;
            }
          }
          OSDMenuKeyboard_DrawKeys();
          break;
        }

        case RKEY_Next:       //Cursor rechts
        {
          OSDMenuKeyboard_CursorRight();
          break;
        }

        case RKEY_Prev:       //Cursor links
        {
          OSDMenuKeyboard_CursorLeft();
          break;
        }

        case RKEY_Slow:       //Cursor ans Ende
        {
          OSDMenuKeyboard_CursorEnd();
          break;
        }

        case RKEY_Ok:         //Zeichen übernehmen
        {
          switch(KeyPadPosition)
          {
            case 26:
            {
              if(strlen(OSDMenuKeyboard_StringVar) < OSDMenuKeyboard_StringMaxLen)
              {
                InsertAt(OSDMenuKeyboard_StringVar, OSDMenuKeyboard_CursorPosition, " ");
                OSDMenuKeyboard_CursorPosition++;
                OSDMenuKeyboard_DrawText();
                OSDMenuKeyboard_SetShiftState();
              }
              break;
            }

            case 27:
            {
              KeyPadMode++;
              if(KeyPadMode >= KPM_Symbols) KeyPadMode = 0;
              KeyPadShiftState = (KeyPadMode == KPM_LettersCAPS);
              OSDMenuKeyboard_DrawKeys();
              break;
            }

            case 28:
            {
              if (!OSDMenuKeyboard_isEmpty())
              {
                OSDMenuKeyboard_SaveAndFinish();
                return TRUE;
              }
              break;
            }

            default:
            {
              if(strlen(OSDMenuKeyboard_StringVar) < OSDMenuKeyboard_StringMaxLen)
              {
                InsertAt(OSDMenuKeyboard_StringVar, OSDMenuKeyboard_CursorPosition, Keypad[KeyPadMode][KeyPadPosition]);
                OSDMenuKeyboard_CursorPosition++;
                OSDMenuKeyboard_DrawText();
                if (KeyPadMode != KPM_Letters)
                {
                  KeyPadShiftState = FALSE;
                  KeyPadMode = KPM_Letters;
                  OSDMenuKeyboard_DrawKeys();
                }
              }
            }
          }
          break;
        }

        case RKEY_0:
        case RKEY_1:
        case RKEY_2:
        case RKEY_3:
        case RKEY_4:
        case RKEY_5:
        case RKEY_6:
        case RKEY_7:
        case RKEY_8:
        case RKEY_9:
        {
          if(strlen(OSDMenuKeyboard_StringVar) < OSDMenuKeyboard_StringMaxLen)
          {
            char ToBeInserted[2];

            ToBeInserted[0] = '0' + (*param1 & 0x0f);
            ToBeInserted[1] = '\0';
            InsertAt(OSDMenuKeyboard_StringVar, OSDMenuKeyboard_CursorPosition, ToBeInserted);
            OSDMenuKeyboard_CursorPosition++;
            OSDMenuKeyboard_DrawText();
            OSDMenuKeyboard_SetShiftState();
          }
          break;
        }

        case RKEY_Info:       //Zeichensatz ändern
        case RKEY_Play:
        {
          KeyPadMode++;
          if ((KeyPadMode == KPM_Special) && KeyPadShiftState)
            KeyPadMode = KPM_SpecialCAPS;
          else if ((KeyPadMode == KPM_LettersCAPS) || (KeyPadMode == KPM_SpecialCAPS))
            KeyPadMode++;
          if (KeyPadMode >= KPM_NrModes)
            KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters;
          OSDMenuKeyboard_DrawKeys();
          break;
        }

        case RKEY_Pause:      //Zwischen normalen und CAPS Zeichen wechseln
        {
          if (KeyPadMode == KPM_Special || KeyPadMode == KPM_SpecialCAPS)
          {
            KeyPadShiftState = !KeyPadShiftState;
            KeyPadMode = (KeyPadShiftState) ? KPM_SpecialCAPS : KPM_Special;
          }
          else
          {
            if (KeyPadMode == KPM_Letters || KeyPadMode == KPM_LettersCAPS)
              KeyPadShiftState = !KeyPadShiftState;
            KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters;
          }

/*          KeyPadShiftState = !KeyPadShiftState;
          if (KeyPadMode == KPM_Special || KeyPadMode == KPM_SpecialCAPS)
            KeyPadMode = (KeyPadShiftState) ? KPM_SpecialCAPS : KPM_Special;
          else if (KeyPadMode == KPM_Letters || KeyPadMode == KPM_LettersCAPS)
            KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters; */

          OSDMenuKeyboard_DrawKeys();
          break;
        }

        case RKEY_Forward:    //Zeichen rechts löschen
        {
          OSDMenuKeyboard_DeleteRight();
          break;
        }

        case RKEY_Rewind:     //Zeichen links löschen
        {
          OSDMenuKeyboard_DeleteLeft();
          break;
        }

        case RKEY_Recall:     //Original wiederherstellen
        {
          memset(OSDMenuKeyboard_StringVar, 0, OSDMenuKeyboard_StringMaxLen + 4);
          strncpy(OSDMenuKeyboard_StringVar, OSDMenuKeyboard_StringVarOrig, OSDMenuKeyboard_StringMaxLen);
          OSDMenuKeyboard_TextStartPosition = 0;
          OSDMenuKeyboard_CursorPosition = strlen(OSDMenuKeyboard_StringVar);
          OSDMenuKeyboard_DrawText();
          OSDMenuKeyboard_SetShiftState();
          break;
        }

        case RKEY_Blue:       //Gesamten Text löschen
        {
          memset(OSDMenuKeyboard_StringVar, 0, OSDMenuKeyboard_StringMaxLen + 4);
          OSDMenuKeyboard_TextStartPosition = 0;
          OSDMenuKeyboard_CursorPosition = 0;
          OSDMenuKeyboard_DrawText();
          OSDMenuKeyboard_SetShiftState();
          break;
        }

        case RKEY_Green:     //In Zwischenablage kopieren
        {
//          snprintf(OSDMenuKeyboard_Clipboard, sizeof(OSDMenuKeyboard_Clipboard), "%s", OSDMenuKeyboard_StringVar);
          strncpy(OSDMenuKeyboard_Clipboard, OSDMenuKeyboard_StringVar, min(OSDMenuKeyboard_StringMaxLen, sizeof(OSDMenuKeyboard_Clipboard)));
          OSDMenuKeyboard_Clipboard[sizeof(OSDMenuKeyboard_Clipboard) - 1] = '\0';
          break;
        }
        case RKEY_Yellow:     //Aus Zwischenablage einfügen
        {
          if (*OSDMenuKeyboard_Clipboard)
          {
            strncpy(OSDMenuKeyboard_StringVar, OSDMenuKeyboard_Clipboard, min(OSDMenuKeyboard_StringMaxLen, sizeof(OSDMenuKeyboard_Clipboard)));
            OSDMenuKeyboard_Clipboard[OSDMenuKeyboard_StringMaxLen - 1] = '\0';
            OSDMenuKeyboard_TextStartPosition = 0;
            OSDMenuKeyboard_CursorPosition = strlen(OSDMenuKeyboard_StringVar);
            OSDMenuKeyboard_DrawText();
            OSDMenuKeyboard_SetShiftState();
          }
          break;
        }

        case RKEY_Stop:       //Speichern und beenden
        case RKEY_Exit:       //Beenden ohne Speichern
        {
          if (*param1 == RKEY_Exit) OSDMenuKeyboard_StringVar[0] = '\0';
          OSDMenuKeyboard_SaveAndFinish();
          return TRUE;
          break;
        }
      }
      *param1 = 0;
      break;
    }

    case EVT_TMSREMOTEASCII:
    {
      switch(*param1)
      {
        case 0x08:    //BS
        {
          OSDMenuKeyboard_DeleteLeft();
          break;
        }

        case 0x0D:    //CR
        {
          if (!OSDMenuKeyboard_isEmpty())
          {
            OSDMenuKeyboard_SaveAndFinish();
            return TRUE;
          }
          break;
        }

        case 0x1B:    //ESC
        {
          OSDMenuKeyboard_StringVar[0] = '\0';
          OSDMenuKeyboard_SaveAndFinish();
          return TRUE;
          break;
        }

        case 0x7f:    //Del
        {
          OSDMenuKeyboard_DeleteRight();
          break;
        }

        case 0x0124:  //Pos1
        {
          OSDMenuKeyboard_CursorPosition = 0;
          OSDMenuKeyboard_DrawText();
          OSDMenuKeyboard_SetShiftState();
          break;
        }

        case 0x0123:  //End
        {
          OSDMenuKeyboard_CursorPosition = strlen(OSDMenuKeyboard_StringVar);
          OSDMenuKeyboard_DrawText();
          OSDMenuKeyboard_SetShiftState();
          break;
        }

        case 0x0125:  //Left
        {
          OSDMenuKeyboard_CursorLeft();
          break;
        }

        case 0x0127:  //Right
        {
          OSDMenuKeyboard_CursorRight();
          break;
        }

        case 0x0170:   //F1 = RED
        {
          OSDMenuKeyboard_StringVar[0] = '\0';
          OSDMenuKeyboard_SaveAndFinish();
          return TRUE;
          break;
        }

        case 0x0171:   //F2 = GREEN
        {
          if (!OSDMenuKeyboard_isEmpty())
          {
            OSDMenuKeyboard_SaveAndFinish();
            return TRUE;
          }
          break;
        }

        case 0x0173:   //F4 = BLUE
        {
          memset(OSDMenuKeyboard_StringVar, 0, OSDMenuKeyboard_StringMaxLen + 4);
          OSDMenuKeyboard_TextStartPosition = 0;
          OSDMenuKeyboard_CursorPosition = 0;
          OSDMenuKeyboard_DrawText();
          OSDMenuKeyboard_SetShiftState();
          break;
        }

        default:
        {
          //ASCII Codes
          if((*param1 < 0x100) && (((*param1 >= 0x20) && (*param1 < 0x7f)) || (*param1 >= 0xa0)))
          {
            if(strlen(OSDMenuKeyboard_StringVar) < OSDMenuKeyboard_StringMaxLen)
            {
              char          ToBeInserted[2];

              ToBeInserted[0] = *param1;
              ToBeInserted[1] = '\0';
              InsertAt(OSDMenuKeyboard_StringVar, OSDMenuKeyboard_CursorPosition, ToBeInserted);
              OSDMenuKeyboard_CursorPosition++;
              OSDMenuKeyboard_DrawText();
//              OSDMenuKeyboard_SetShiftState();
            }
          }
        }
      }
      break;
    }
  }
  return FALSE;
}
