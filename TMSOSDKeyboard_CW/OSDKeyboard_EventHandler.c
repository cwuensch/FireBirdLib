#include                <string.h>
#include                <stdlib.h>
#include                <ctype.h>
#include                "FBLib_TMSOSDKeyboard.h"

static dword            LastSuggestion = 0;
static bool             SelActive = FALSE;
static int              DoFinish = 0;

static int GetCurrentWord(char *const outCurWord, int maxLen)
{
  char                  tmp, *p;
  TRACEENTER();

  tmp = OSDKeyboard_StringVar[OSDKeyboard_CursorPosition];
  OSDKeyboard_StringVar[OSDKeyboard_CursorPosition] = '\0';

  p = strrchr(OSDKeyboard_StringVar, ' ');
  if(p)
    p++;
  else
    p = OSDKeyboard_StringVar;

  // Sonderzeichen am Anfang entfernen
  while (!( (*p >= '0' && *p <= '9') || (*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z') || (*p >= 'À' && *p != '÷' && *p != '×') || (*p == '\0') ))
    p++;

  if (outCurWord)
  {
    strncpy(outCurWord, p, maxLen);
    outCurWord[maxLen-1] = '\0';
  }
  OSDKeyboard_StringVar[OSDKeyboard_CursorPosition] = tmp;
  
  return (OSDKeyboard_CursorPosition - (p - OSDKeyboard_StringVar));
  TRACEEXIT();
}

static void ChangeCase(char *const curWord)
{
  int                   i, j;

  TRACEENTER();
  for (i = 0; i < NRKEYPADNORMALKEYS; i++)
  {
    for (j = 0; (j < NRKEYALTSYMBOLS && Keypad[KPM_LettersCAPS][i][j]); j++)
    {
      if (curWord[0] == Keypad[KPM_LettersCAPS][i][j])
      {
        curWord[0] = Keypad[KPM_Letters][i][j];
        return;
      }
    }
  }
  TRACEEXIT();
}

void AddWordToDict(const char* newWord)
{
  char                  curWord[MAXSUGGESTIONLENGTH];
  int                   len, cmp, i, j;
  TRACEENTER();
  
  if (!newWord)
  {
    char *p;
    GetCurrentWord(curWord, sizeof(curWord));

    // Sonderzeichen (insbes. Punkt) am Ende entfernen
    p = &curWord[strlen(curWord)];
    while (!( (*p >= '0' && *p <= '9') || (*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z') || (*p >= 'À' && *p != '÷' && *p != '×') ))
    {
      *p = '\0';
      if (p > curWord) p--;
    }
    ChangeCase(curWord);

    newWord = curWord;
  }

  // prüfen, ob newWord (jetzt) leer ist
  if (!*newWord)
  {
    TRACEEXIT();
    return;
  }
  len = strlen(newWord);

  // ggf. DictHeap vergrößern
  if (Keyb_DictHeapPos + len + 1 > Keyb_DictHeapSize)
  {
    Keyb_DictHeap = (char*) TAP_MemRealloc(Keyb_DictHeap, Keyb_DictHeapSize, Keyb_DictHeapSize + max(len+1, DICTHEAPSIZE), FALSE);
    if (Keyb_DictHeap)
      Keyb_DictHeapSize += max(len+1, DICTHEAPSIZE);
    else
    {
      Keyb_DictHeapSize = 0;
      Keyb_DictHeapPos = 0;
      Keyb_DictNrEntries = 0;
      TRACEEXIT();
      return;
    }
  }

  // Wort in DictHeap kopieren
  strcpy(&Keyb_DictHeap[Keyb_DictHeapPos], newWord);

  // ggf. Dictionary (Pointer Array) vergrößern
  if (Keyb_DictNrEntries >= Keyb_DictMaxEntries)
  {
    Keyb_Dictionary = (int*) TAP_MemRealloc(Keyb_Dictionary, Keyb_DictMaxEntries * sizeof(int), (Keyb_DictMaxEntries + DICTENTRIES) * sizeof(int), FALSE);
    if (Keyb_Dictionary)
      Keyb_DictMaxEntries += DICTENTRIES;
    else
    {
      Keyb_DictMaxEntries = 0;
      Keyb_DictNrEntries = 0;
      TRACEEXIT();
      return;
    }
  }

  // Pointer in Dictionary kopieren

  // - suche erstes Wort, das größer ist als newWord (-> Einfügestelle)
  for (i = 0; i < Keyb_DictNrEntries; i++)
  {
    cmp = strcmp(&Keyb_DictHeap[Keyb_Dictionary[i]], newWord);
    if (cmp >= 0)
    {
      if (cmp == 0)
      {
        // schon vorhanden
        TRACEEXIT();
        return;
      }
      break;
    }
  }

  // - verschiebe alle nachfolgenden Einträge um 1 nach hinten
  for (j = Keyb_DictNrEntries - 1; j >= i; j--)
    Keyb_Dictionary[j+1] = Keyb_Dictionary[j];

  // - jetzt Pointer eintragen
  Keyb_Dictionary[i] = Keyb_DictHeapPos;
  Keyb_DictHeapPos += len + 1;
  Keyb_DictNrEntries++;

  TRACEEXIT();
}

static void ShowSuggestions(bool NextSuggestion)
{
  TRACEENTER();

  if (NextSuggestion)
  {
    Keyb_CurSug++;
    if (Keyb_CurSug >= Keyb_NrSug)
      Keyb_CurSug = 0;
  }
  else
  {
    char                curWord[MAXSUGGESTIONLENGTH];
    int                 cmp;

    Keyb_SugOffset = GetCurrentWord(curWord, sizeof(curWord));
    ChangeCase(curWord);

    Keyb_NrSug = 0;
    if (Keyb_SugOffset > 0)
    {
      if (Keyb_FirstSug >= Keyb_DictNrEntries) Keyb_FirstSug = 0;

      if ((cmp = strncmp(&Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug]], curWord, Keyb_SugOffset)) >= 0)
      {
        // Wir sind bei oder hinter dem gesuchten Wort -> Suche nach oben bis zum ERSTEN Wort das größer/gleich dem gesuchten ist
        while (Keyb_FirstSug > 0)
        {
          int cmp2 = strncmp(&Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug-1]], curWord, Keyb_SugOffset);
          if (cmp2 < 0)  // das Wort ist (echt) kleiner -> nicht verwenden
            break;
          else cmp = cmp2;
          Keyb_FirstSug--;
        }
      }
      else
      {
        // Wir sind vor dem ersten Wort, das größer/gleich dem gesuchten ist -> suche nach unten
        while (Keyb_FirstSug < Keyb_DictNrEntries - 1)
        {
          Keyb_FirstSug++;
          if ((cmp = strncmp(&Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug]], curWord, Keyb_SugOffset)) >= 0)
            break;
        }
      }

      // Prüfe, ob das gefundene Wort nach dem Cursor überhaupt noch weiter geht (darf eigentlich nur 1x vorkommen)
      if ((cmp == 0) && (Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug] + Keyb_SugOffset] == '\0'))
      {
        Keyb_FirstSug++;
        cmp = strncmp(&Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug]], curWord, Keyb_SugOffset);
      }

      // Ermittle letztes passendes Wort
      if (cmp == 0)
      {
        while (Keyb_FirstSug + Keyb_NrSug < Keyb_DictNrEntries - 1)
        {
          Keyb_NrSug++;
          if (strncmp(&Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug + Keyb_NrSug]], curWord, Keyb_SugOffset) > 0)
            break;
        }
      }

      Keyb_CurSug = 0;
    }
  }

  OSDKeyboard_DrawSuggesion();
  TRACEEXIT();
}


static bool OSDKeyboard_isEmpty(void)
{
  bool ret;
  TRACEENTER();

  ret = ((!OSDKeyboard_StringVar[0]) || (OSDKeyboard_StringVar[0] < 0x20 && !OSDKeyboard_StringVar[1]));

  TRACEEXIT();
  return ret;
}

static void OSDKeyboard_SetShiftState(void)
{
  bool NewKeyPadShiftState = ((OSDKeyboard_CursorPosition == 0) || (OSDKeyboard_StringVar[OSDKeyboard_CursorPosition-1] == ' '));

  TRACEENTER();
  if ((KeyPadShiftState < 2) && (NewKeyPadShiftState != KeyPadShiftState))
  {
    KeyPadShiftState = NewKeyPadShiftState;
    if (KeyPadMode != KPM_Symbols)
      KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters;
    OSDKeyboard_DrawKeys(!SelActive);
    if(SelActive) OSDKeyboard_DrawKeySelection();
  }
  TRACEEXIT();
}

static void OSDKeyboard_ShiftKey(void)
{
  static dword LastShiftKey = 0;

  TRACEENTER();  
  if ((KeyPadShiftState == 1) && (labs(TAP_GetTick() - LastShiftKey) < 50))
    KeyPadShiftState = 2;
  else
    KeyPadShiftState = !KeyPadShiftState;
  LastShiftKey = TAP_GetTick();

  if (KeyPadMode != KPM_Symbols)
    KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters;
  OSDKeyboard_DrawKeys(!SelActive);
  if(SelActive) OSDKeyboard_DrawKeySelection();
  ShowSuggestions(FALSE);

  TRACEEXIT();
}

static void OSDKeyboard_AltKey(void)
{
  TRACEENTER();
  if (KeyPadMode == KPM_Symbols)
  {
    KeyPadMode = (KeyPadShiftState) ? KPM_LettersCAPS : KPM_Letters;
    SpecialKeys[KEY_Alt - NRKEYPADNORMALKEYS + 1].Text = "#...";
  }
  else
  {
    KeyPadMode = KPM_Symbols;
    SpecialKeys[KEY_Alt - NRKEYPADNORMALKEYS + 1].Text = "abc";
  }
  SelActive = FALSE;
  KeyPadSelection = 0;
  OSDKeyboard_DrawKeys(TRUE);
  TRACEEXIT();
}

static void OSDKeyboard_CursorLeft(void)
{
  TRACEENTER();
  if(OSDKeyboard_CursorPosition > 0)
  {
    OSDKeyboard_CursorPosition--;
    OSDKeyboard_DrawText();
    OSDKeyboard_SetShiftState();
    ShowSuggestions(FALSE);
  }
  TRACEEXIT();
}
static void OSDKeyboard_CursorRight(void)
{
  TRACEENTER();
  if(OSDKeyboard_CursorPosition < (int)strlen(OSDKeyboard_StringVar))
  {
    OSDKeyboard_CursorPosition++;
    OSDKeyboard_DrawText();
    OSDKeyboard_SetShiftState();
    ShowSuggestions(FALSE);
  }
  TRACEEXIT();
}
static void OSDKeyboard_CursorEnd(void)
{
  TRACEENTER();
  OSDKeyboard_CursorPosition = (int)strlen(OSDKeyboard_StringVar);
  OSDKeyboard_DrawText();
  OSDKeyboard_SetShiftState();
  ShowSuggestions(FALSE);
  TRACEEXIT();
}

static void OSDKeyboard_DeleteLeft(int nr)
{
  TRACEENTER();
  if (OSDKeyboard_CursorPosition > 0)
  {
    OSDKeyboard_CursorPosition -= nr;
    DeleteAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, nr);
    OSDKeyboard_DrawText();
    OSDKeyboard_SetShiftState();
    ShowSuggestions(FALSE);
  }
  TRACEEXIT();
}
static void OSDKeyboard_DeleteRight(void)
{
  TRACEENTER();
  if(OSDKeyboard_CursorPosition < (int)strlen(OSDKeyboard_StringVar))
  {
    DeleteAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, 1);
    OSDKeyboard_DrawText();
    ShowSuggestions(FALSE);
  }
  TRACEEXIT();
}
static void OSDKeyboard_DeleteWord(void)
{
  TRACEENTER();
  
  // Falls im Wort -> gehe nach rechts zum Wort-Ende
  while ((OSDKeyboard_CursorPosition < (int)strlen(OSDKeyboard_StringVar)) && (OSDKeyboard_StringVar[OSDKeyboard_CursorPosition] != ' '))
    OSDKeyboard_CursorPosition++;
  
  // Falls Leerzeichen hinter dem Wort -> gehe nach links und lösche dieses
  if ((OSDKeyboard_CursorPosition > 0) && (OSDKeyboard_StringVar[OSDKeyboard_CursorPosition-1] == ' '))
  {
    OSDKeyboard_CursorPosition--;
    DeleteAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, 1);
  }

  if (OSDKeyboard_CursorPosition > 0)
  {
    int len = GetCurrentWord(NULL, 0);
    OSDKeyboard_DeleteLeft(len);
  }
  TRACEEXIT();
}

static void OSDKeyboard_ClearAll(void)
{
  TRACEENTER();
  memset(OSDKeyboard_StringVar, 0, OSDKeyboard_StringMaxLen + 4);
  OSDKeyboard_TextStartPosition = 0;
  OSDKeyboard_CursorPosition = 0;
  OSDKeyboard_DrawText();
  OSDKeyboard_SetShiftState();
  ShowSuggestions(FALSE);
  TRACEEXIT();
}

static void OSDKeyboard_RestoreOrig(void)
{
  TRACEENTER();
  memset(OSDKeyboard_StringVar, 0, OSDKeyboard_StringMaxLen + 4);
  strncpy(OSDKeyboard_StringVar, OSDKeyboard_StringVarOrig, OSDKeyboard_StringMaxLen);
  OSDKeyboard_TextStartPosition = 0;
  OSDKeyboard_CursorEnd();
  TRACEEXIT();
}

static void OSDKeyboard_CopyStr(void)
{
  TRACEENTER();
  if (Keyb_Clipboard)
    TAP_MemFree(Keyb_Clipboard);
  Keyb_Clipboard = (char*) TAP_MemAlloc(strlen(OSDKeyboard_StringVar) + 1);  // wird absichtlich nicht wieder freigegeben
  if (Keyb_Clipboard)
    strcpy(Keyb_Clipboard, OSDKeyboard_StringVar);
  TRACEEXIT();
}

static void OSDKeyboard_PasteStr(void)
{
  TRACEENTER();
  if (*Keyb_Clipboard)
  {
    strncpy(OSDKeyboard_StringVar, Keyb_Clipboard, OSDKeyboard_StringMaxLen);
    Keyb_Clipboard[OSDKeyboard_StringMaxLen] = '\0';
    OSDKeyboard_TextStartPosition = 0;
    OSDKeyboard_CursorEnd();
  }
  TRACEEXIT();
}

static void OSDKeyboard_Suggestion(void)
{
  TRACEENTER();

  if (Keyb_InsertedChars > 0)
  {
    DeleteAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, Keyb_InsertedChars);
    Keyb_InsertedChars = 0;
//    OSDKeyboard_DrawText();
  }

  if ((Keyb_NrSug > 0) && (Keyb_CurSug < Keyb_NrSug))
  {
    int len = strlen(&Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug + Keyb_CurSug]]);
    if (strlen(OSDKeyboard_StringVar) + len - Keyb_SugOffset + 1 < OSDKeyboard_StringMaxLen)
    {
      InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, " ", 1);
      InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, &Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug + Keyb_CurSug] + Keyb_SugOffset], len - Keyb_SugOffset);
      Keyb_InsertedChars = len - Keyb_SugOffset + 1;
//      OSDKeyboard_DrawText();
    }

    LastSuggestion = TAP_GetTick();
    if(!LastSuggestion) LastSuggestion++;
  }
  else
    LastSuggestion = 0;

  OSDKeyboard_DrawText();
  ShowSuggestions(TRUE);
  TRACEEXIT();
}

static bool OSDKeyboard_Finish(bool DoSave)
{
  TRACEENTER();
  DoFinish = FALSE;
  if (DoSave)
  {
    if (OSDKeyboard_AllowEmpty || !OSDKeyboard_isEmpty())
    {
      strcpy(OSDKeyboard_StringVarOrig, OSDKeyboard_StringVar);
      OSDKeyboard_SavedVar = TRUE;
      OSDKeyboard_Destroy();
      TRACEEXIT();
      return TRUE;
    }
  }
  else
  {
    OSDKeyboard_StringVarOrig[0] = '\0';
    OSDKeyboard_Destroy();
    TRACEEXIT();
    return TRUE;
  }
  TRACEEXIT();
  return FALSE;
}


bool OSDKeyboard_EventHandler(word *event, dword *param1, dword *param2)
{
  static dword          LastKey = 0, LastT9Pressed = 0, OkLongPressed = 1;
//  static int            SugInserted = 0;
  static const char    *T9Cur = NULL;
  static bool           IgnoreOk = FALSE;
  bool                  ret = FALSE;
  (void)                param2;

  TRACEENTER();
  if(OSDKeyboard_StringVarOrig == NULL)
  { 
    TRACEEXIT();
    return FALSE;
  }

  if(!OSDKeyboard_rgn)
  {
#ifdef FB_USE_UNICODE_OSD
    OSDMenuLoadStdFonts();
#endif
    OkLongPressed = 1;
    OSDKeyboard_CursorPosition = strlen(OSDKeyboard_StringVar);
    OSDKeyboard_DrawAll();
    ShowSuggestions(FALSE);
    OSDKeyboard_TMSRemoteDirectMode(TRUE);
    USBKeyboardRedirect(TRUE, TRUE);
    TRACEEXIT();
    return FALSE;
  }

  if(!event || !param1)
  {
    TRACEEXIT();
    return FALSE;
  }

  // Finish im IDLE-Event (nötig, wenn Finish über USB-Keyboard ausgelöst)
  if (DoFinish && (*event == EVT_IDLE))
  {
    TRACEEXIT();
    return OSDKeyboard_Finish((DoFinish >= 2));
  }


/*if (*event == EVT_KEY)
{
  char *ptype;
  if (*param1 & Keyflag_Push) ptype = "DAUER";
  else if (*param1 & Keyflag_Click) ptype = "RELEASE";
  else ptype = "NORMAL";
  TAP_PrintNet("FBKEY Event: type=%s, param1=0x%lx, param2=0x%lx, LastKey=0x%lx, LastT9=%lu, OkLongPressed=%lu\n", ptype, *param1 % Keyflag_Push, *param2, LastKey, LastT9Pressed, OkLongPressed);
}
else if (*event == EVT_TMSREMOTEASCII)
  TAP_PrintNet("TMSREMOTE Event: param1=0x%lx, param2=0x%lx\n", *param1, *param2);
else if (*event == EVT_USBKEYBOARD)
  TAP_PrintNet("USBKEYB Event: param1=0x%lx, param2=0x%lx\n", *param1, *param2); */


  // Anderer Knopf gedrückt -> OkLongPressed zurücksetzen (kann nur passieren, wenn Release-Event verpasst wird)
  if (OkLongPressed && (((*event==EVT_KEY && (*param1&0xFFFFFF)!=RKEY_Ok) && (*event==EVT_KEY && (*param1&0xFFFFFF)!=RKEY_Pause)) || *event==EVT_TMSREMOTEASCII || *event==EVT_USBKEYBOARD))
  {
    OkLongPressed = 0;  // eigentlich unnötig?
  }

  // Wenn Ok-Button lang genug gedrückt -> Selection einblenden
  if ((*event==EVT_IDLE || (*event==EVT_KEY && *param1==RKEY_Ok) || (*event==EVT_KEY && *param1==RKEY_Pause)) && OkLongPressed && (OkLongPressed != 1) && (labs(TAP_GetTick() - OkLongPressed) > 50))
  {
    if (!SelActive && (((KeyPadPosition < NRKEYPADNORMALKEYS) && (strlen(Keypad[KeyPadMode][KeyPadPosition]) > 1)) || KeyPadPosition == KEY_Alt))
    {
      SelActive = TRUE;
      KeyPadSelection = 1;
      OSDKeyboard_DrawKeySelection();
    }
  }

  // T9-Behandlung
  if (LastT9Pressed && ((labs(TAP_GetTick()-LastT9Pressed) > 100) || (*event==EVT_KEY && (*param1&0xFFFFFF)!=LastKey) || *event==EVT_TMSREMOTEASCII || *event==EVT_USBKEYBOARD))
  {
//TAP_PrintNet("Auslöser: event=%d, param1=%d, LastKey=%d\n", *event, *param1, LastKey);
    LastT9Pressed = 0;
    if (OSDKeyboard_StringVar[OSDKeyboard_CursorPosition] == ' ')
      AddWordToDict(NULL);
    OSDKeyboard_CursorPosition++;
    OSDKeyboard_DrawText();
    OSDKeyboard_SetShiftState();
    ShowSuggestions(FALSE);
  }

  // Suggestions
  if (LastSuggestion)
  {
    if ((*event==EVT_KEY && ((*param1&0xFFFFFF)==RKEY_Rewind || (*param1&0xFFFFFF)==RKEY_Forward || (*param1&0xFFFFFF)==RKEY_Record)) || ((*event==EVT_TMSREMOTEASCII || *event==EVT_USBKEYBOARD) && (*param1==0x08 || *param1==0x7f)))
    {
      if (Keyb_InsertedChars > 0)
      {
        DeleteAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, Keyb_InsertedChars);
        Keyb_InsertedChars = 0;
        OSDKeyboard_DrawText();
        ShowSuggestions(FALSE);
      }
      *param1 = 0;
//      TRACEEXIT();
//      return ret;
    }
    else if ((labs(TAP_GetTick()-LastSuggestion) > 200) || (*event==EVT_KEY && (*param1&0xFFFFFF)!=LastKey) || *event==EVT_TMSREMOTEASCII || *event==EVT_USBKEYBOARD)
    {
//TAP_PrintNet("Auslöser: event=%d, param1=%d, LastKey=%d\n", *event, *param1, LastKey);
      LastSuggestion = 0;
      if (Keyb_InsertedChars > 0)
      {
        OSDKeyboard_CursorPosition += Keyb_InsertedChars;
        OSDKeyboard_DrawText();
        OSDKeyboard_SetShiftState();
        Keyb_InsertedChars = 0;
        ShowSuggestions(FALSE);
      }
    }
  }

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
            OSDKeyboard_CursorRight();
          else if (SelActive)
          {
            const char *pAltKeys = ((KeyPadPosition < NRKEYPADNORMALKEYS) ? Keypad[KeyPadMode][KeyPadPosition] : SpecialChars);
            KeyPadSelection++;
            if ((KeyPadSelection >= NRKEYALTSYMBOLS) || !pAltKeys[KeyPadSelection])
              KeyPadSelection = 0;
            OSDKeyboard_DrawKeySelection();
          }
          else
          {
            switch(KeyPadPosition)
            {
              case KEY_I:
              case KEY_R:
              case KEY_Z:
                KeyPadPosition -= (NRKEYCOLS-1); break;
              case KEY_Save:   KeyPadPosition = KEY_BackSp; break;
              default:         KeyPadPosition++;
            }
            OSDKeyboard_DrawKeys(TRUE);
          }
          break;
        }

        case RKEY_Left:       //Zeichenauswahl links
        case RKEY_VolDown:
        {
          if (KeyPadCursorMode)
            OSDKeyboard_CursorLeft();
          else if (SelActive)
          {
            const char *pAltKeys = ((KeyPadPosition < NRKEYPADNORMALKEYS) ? Keypad[KeyPadMode][KeyPadPosition] : SpecialChars);
            if (KeyPadSelection > 0)
              KeyPadSelection--;
            else
              KeyPadSelection = min(strlen(pAltKeys), NRKEYALTSYMBOLS) - 1;
            OSDKeyboard_DrawKeySelection();
          }
          else
          {
            switch(KeyPadPosition)
            {
              case KEY_A:
              case KEY_J:
              case KEY_Shift:
                KeyPadPosition += (NRKEYCOLS-1); break;
              case KEY_BackSp: KeyPadPosition = KEY_Save; break;
              default:         KeyPadPosition--;
            }
            OSDKeyboard_DrawKeys(TRUE);
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
            OSDKeyboard_DrawText();
          }
          else
          {
            //Spezialbehandlung durch die großen Tasten
            switch(KeyPadPosition)
            {
              case KEY_U:
              case KEY_V:        KeyPadPosition = KEY_Space;   break;
              case KEY_W:
              case KEY_X:        KeyPadPosition = KEY_Cancel;  break;
              case KEY_Y:
              case KEY_Z:        KeyPadPosition = KEY_Save;    break;
              case KEY_BackSp:
              case KEY_Del:
              case KEY_Alt:
              case KEY_Space:
              case KEY_Cancel:
              case KEY_Save:     KeyPadCursorMode = TRUE; OSDKeyboard_DrawText(); break;
              default:           KeyPadPosition += NRKEYCOLS;  break;
            }
            SelActive = FALSE;
            KeyPadSelection = 0;
          }
          OSDKeyboard_DrawKeys(TRUE);
          break;
        }

        case RKEY_Up:         //Zeichenauswahl hoch
        case RKEY_ChDown:
        {
          if (KeyPadCursorMode)
          {
            KeyPadCursorMode = FALSE;
            KeyPadPosition = KEY_BackSp;
            OSDKeyboard_DrawText();
          }
          else
          {
            //Spezialbehandlung durch die großen Tasten
            if (KeyPadPosition < NRKEYCOLS)
            {
              KeyPadCursorMode = TRUE;
              OSDKeyboard_DrawText();
            }
            else
            {
              switch(KeyPadPosition)
              {
                case KEY_Cancel:   KeyPadPosition = KEY_W;       break;
                case KEY_Save:     KeyPadPosition = KEY_Y;       break;
                default:           KeyPadPosition -= NRKEYCOLS;  break;
              }
            }
            SelActive = FALSE;
            KeyPadSelection = 0;
          }
          OSDKeyboard_DrawKeys(TRUE);
          break;
        }

        case RKEY_Next:       //Cursor rechts
        {
          OSDKeyboard_CursorRight();
          break;
        }

        case RKEY_Prev:       //Cursor links
        {
          OSDKeyboard_CursorLeft();
          break;
        }

        case RKEY_Slow:       //Cursor ans Ende
        {
          OSDKeyboard_CursorEnd();
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
          if (LastT9Pressed)
          {
            DeleteAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, 1);
            *T9Cur++;
          }
          if (!LastT9Pressed || !T9Cur || !*T9Cur)
            T9Cur = (KeyPadShiftState) ? T9ArrayCaps[(*param1 & 0x0f)] : T9Array[(*param1 & 0x0f)];
            
          if (strlen(OSDKeyboard_StringVar) < OSDKeyboard_StringMaxLen)
          {
            InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, T9Cur, 1);
//            OSDKeyboard_CursorPosition++;
            OSDKeyboard_DrawText();
          }

          LastT9Pressed = TAP_GetTick();
          if(!LastT9Pressed) LastT9Pressed++;
          break;
        }

        case RKEY_Ab:
        case RKEY_Option:
        {
          if(strlen(OSDKeyboard_StringVar) < OSDKeyboard_StringMaxLen)
          {
            InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, " ", 1);
            AddWordToDict(NULL);
            OSDKeyboard_CursorPosition++;
            OSDKeyboard_DrawText();
            OSDKeyboard_SetShiftState();
            ShowSuggestions(FALSE);
          }
          break;
        }

        case RKEY_Ok + Keyflag_Push:
        case RKEY_Pause + Keyflag_Push:
        {
          IgnoreOk = TRUE;
          break;
        }

        case RKEY_Pause:      // Aktive Taste auf ALT setzen
        {
          if (KeyPadPosition != KEY_Alt)
          {
            KeyPadPosition = KEY_Alt;
            KeyPadCursorMode = FALSE;
            OSDKeyboard_DrawText();
            OSDKeyboard_DrawKeys(TRUE);
          }
          // break;   // weitermachen mit RKEY_Ok...
        }

        case RKEY_Ok:         // Zeichen übernehmen
        {
          if (IgnoreOk) break;

          if (KeyPadCursorMode)
          {
            KeyPadPosition = KEY_Save;
            KeyPadCursorMode = FALSE;
            OSDKeyboard_DrawText();
            OSDKeyboard_DrawKeys(TRUE);
            break;
          }

          switch(KeyPadPosition)
          {
            case KEY_Shift:
              OSDKeyboard_ShiftKey();
              break;

            case KEY_BackSp:
              OSDKeyboard_DeleteLeft(1);
              break;

            case KEY_Del:
              OSDKeyboard_DeleteRight();
              break;

            case KEY_Cancel:
              ret = OSDKeyboard_Finish(FALSE);
              break;

            case KEY_Save:
              ret = OSDKeyboard_Finish(TRUE);
              break;

            case KEY_Space:
            {
              if(strlen(OSDKeyboard_StringVar) < OSDKeyboard_StringMaxLen)
              {
                InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, " ", 1);
                AddWordToDict(NULL);
                OSDKeyboard_CursorPosition++;
                OSDKeyboard_DrawText();
                OSDKeyboard_SetShiftState();
                ShowSuggestions(FALSE);
              }
              break;
            }

            default:
            {
              // BEI KEY_DOWN:

              // Wenn SelActive oder keine Alternativen Zeichen vorhanden
              // -> Zeichen sofort einfügen (springe zu nächstem Case)
              if (!SelActive && (((KeyPadPosition < NRKEYPADNORMALKEYS) && (strlen(Keypad[KeyPadMode][KeyPadPosition]) > 1)) || KeyPadPosition == KEY_Alt))
              {
                // Sonst: Timer für "Ok lang gedrückt" starten (und aufhören)
                if (!OkLongPressed || OkLongPressed == 1)
                {
                  OkLongPressed = TAP_GetTick();
                  if (OkLongPressed == 0) OkLongPressed++;
                  if (OkLongPressed == 1) OkLongPressed++;
                  break;
                }
                break;
              }

              // Wenn extrem langer Tastendruck (z.B. weil kein Release-Event) -> diesen beenden (als neuen, kurzen werten)
              if ((OkLongPressed && labs(TAP_GetTick() - OkLongPressed) > 200) || OkLongPressed == 1)
              {
                OkLongPressed = 0;
                // Fortsetzen mit Ok-Button released (kurzer Tastendruck)...
              }

              // Else: Fortsetzen mit Ok-Button released...
              // (Zeichen sofort einfügen)
//              break;
            }  // End default case (Keypad_Position)
          }
//          break;
        }  // End case RKEY_Ok

        case (RKEY_Ok + Keyflag_Click):     // Ok-Button released
        case (RKEY_Pause + Keyflag_Click):  // Pause-Button released (für Sonderzeichen auf ALT-Taste)
        {
          // Release bei allen Sondertasten (alles außer default-case) ignorieren
          if (KeyPadCursorMode || (KeyPadPosition >= NRKEYPADNORMALKEYS && KeyPadPosition != KEY_Alt) || (KeyPadPosition == KEY_Shift))
            break;

//TAP_PrintNet("Ok-Button released (RELEASE = %d, OkLongPressed = %lu)!\n", (*param1 != RKEY_Ok), OkLongPressed);

          // kurzer Tastendruck -> wurde noch nicht verarbeitet
          if (*param1 == (RKEY_Ok + Keyflag_Click) || *param1 == (RKEY_Pause + Keyflag_Click))
            if (OkLongPressed && (OkLongPressed != 1) && (labs(TAP_GetTick() - OkLongPressed) < 50))
              OkLongPressed = 0;

          // Wenn Key NICHT mehr gedrückt
          if (!OkLongPressed)
          {
            // Release bei ALT-Taste nachholen
            if ((KeyPadPosition == KEY_Alt) && !SelActive)
            {
              OSDKeyboard_AltKey();
            }
            else
            {
              // Zeichen einfügen
              if (strlen(OSDKeyboard_StringVar) < OSDKeyboard_StringMaxLen)
              {
                const char *pAltKeys = ((KeyPadPosition < NRKEYPADNORMALKEYS) ? Keypad[KeyPadMode][KeyPadPosition] : SpecialChars);
                InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, &pAltKeys[KeyPadSelection], 1);
                OSDKeyboard_CursorPosition++;
                OSDKeyboard_DrawText();
              }
              if (KeyPadShiftState == 1)
              {
                SelActive = FALSE;
                KeyPadShiftState = FALSE;
                if(KeyPadMode == KPM_LettersCAPS) KeyPadMode = KPM_Letters;
                OSDKeyboard_DrawKeys(TRUE);
              }
              else if (SelActive)
              {
                SelActive = FALSE;
                OSDKeyboard_DrawKeys(TRUE);
              }
              KeyPadSelection = 0;
              OkLongPressed = 1;  // damit beim Release nicht ein zweites Mal ausgelöst wird
            }
          }

          // BEI RELEASE
          if (*param1 == (RKEY_Ok + Keyflag_Click) || *param1 == (RKEY_Pause + Keyflag_Click))
          {
            OkLongPressed = 0;  // Release - jetzt ist der lange Tastendruck erledigt
            IgnoreOk = FALSE;
          }
          break;
        }

        case RKEY_Play:      //Zwischen normalen und CAPS Zeichen wechseln
        {
          OSDKeyboard_ShiftKey();
          break;
        }

        case RKEY_Info:      //Zeichensatz ändern
//        case RKEY_Pause:
        {
          OSDKeyboard_AltKey();
          break;
        }

        case RKEY_Forward:   //Zeichen rechts löschen
        {
          OSDKeyboard_DeleteRight();
          break;
        }

        case RKEY_Rewind:    //Zeichen links löschen
        {
          OSDKeyboard_DeleteLeft(1);
          break;
        }

        case RKEY_Record:    //Letztes Wort löschen
        {
          OSDKeyboard_DeleteWord();
          break;
        }

        case RKEY_Recall:    //Original wiederherstellen
        {
          OSDKeyboard_RestoreOrig();
          break;
        }

        case RKEY_Red:       //Gesamten Text löschen
        {
          OSDKeyboard_ClearAll();
          break;
        }

        case RKEY_Green:     //In Zwischenablage kopieren
        {
          OSDKeyboard_CopyStr();
          break;
        }
        case RKEY_Yellow:    //Aus Zwischenablage einfügen
        {
          OSDKeyboard_PasteStr();
          break;
        }

        case RKEY_Blue:      //Suggestion einfügen
        {
          OSDKeyboard_Suggestion();
          break;
        }

        case RKEY_Sleep:
        case RKEY_Exit:      //Beenden ohne Speichern
        {
          if (SelActive && (*param1 != RKEY_Sleep))
          {
            SelActive = FALSE;
            KeyPadSelection = 0;
            OSDKeyboard_DrawKeys(TRUE);
          }
          else
            ret = OSDKeyboard_Finish(FALSE);
          break;
        }

        case RKEY_Stop:      //Speichern und beenden
        {
          ret = OSDKeyboard_Finish(TRUE);
          break;
        }
      }
      LastKey = *param1 & 0xFFFFFF;
      *param1 = 0;
      break;
    }

    case EVT_TMSREMOTEASCII:
    case EVT_USBKEYBOARD:
    {
      //Key down events only
      if (*event == EVT_USBKEYBOARD && ((*param2 & 0x03) == 0x01))
        break;

      switch(*param1)
      {
        case 0x0D:     //CR
        case 0x0175:   //F6
        {
          DoFinish = 2;
          break;
        }

        case 0x1B:     //ESC
        {
          DoFinish = 1;
          break;
        }

        case 0x08:     //BS
        {
          OSDKeyboard_DeleteLeft(1);
          break;
        }

        case 0x7f:     //Del
        {
          OSDKeyboard_DeleteRight();
          break;
        }

        case 0x0124:   //Pos1
        {
          OSDKeyboard_CursorPosition = 0;
          OSDKeyboard_DrawText();
          OSDKeyboard_SetShiftState();
          break;
        }

        case 0x0123:   //End
        {
          OSDKeyboard_CursorEnd();
          break;
        }

        case 0x0125:   //Left
        {
          OSDKeyboard_CursorLeft();
          break;
        }

        case 0x0127:   //Right
        {
          OSDKeyboard_CursorRight();
          break;
        }

        case 0x0170:   //F1 = RED
        {
          OSDKeyboard_ClearAll();
          break;
        }

        case 0x0171:   //F2 = GREEN
        {
          OSDKeyboard_CopyStr();
          break;
        }

        case 0x0172:   //F3 = YELLOW
        {
          OSDKeyboard_ClearAll();
          break;
        }

        case 0x0173:   //F4 = BLUE
        {
          OSDKeyboard_Suggestion();
          break;
        }

        case 0x0174:   //F5
        {
          OSDKeyboard_RestoreOrig();
          break;
        }

        default:
        {
          //ASCII Codes
          if((*param1 < 0x100) && (((*param1 >= 0x20) && (*param1 < 0x7f)) || (*param1 >= 0xa0)))
          {
            if(strlen(OSDKeyboard_StringVar) < OSDKeyboard_StringMaxLen)
            {
              InsertCharsAt(OSDKeyboard_StringVar, OSDKeyboard_CursorPosition, (char*)param1, 1);
              if (OSDKeyboard_StringVar[OSDKeyboard_CursorPosition] == ' ')
                AddWordToDict(NULL);
              OSDKeyboard_CursorPosition++;
              OSDKeyboard_DrawText();
              OSDKeyboard_SetShiftState();
              ShowSuggestions(FALSE);
            }
          }
        }
      }
      LastKey = 0;
      *param1 = 0;
      break;
    }
  }
  TRACEEXIT();
  return ret;
}
