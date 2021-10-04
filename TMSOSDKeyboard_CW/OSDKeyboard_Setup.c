#define _GNU_SOURCE
#include                <stdio.h>
#include                <string.h>
#include                <sys/stat.h>
#include                "FBLib_TMSOSDKeyboard.h"
#include                "graphic/Keyb_Cut.gd"
#include                "graphic/Keyb_Ffwd.gd"
#include                "graphic/Keyb_Pause.gd"
#include                "graphic/Keyb_Play.gd"
#include                "graphic/Keyb_Rwd.gd"
#include                "graphic/Keyb_Stop.gd"
#include                "graphic/Keyb_Recall.gd"
//#include                "graphic/Button_Recall.gd"
#include                "graphic/Button_Blue.gd"
#include                "graphic/Button_Green.gd"
#include                "graphic/Button_Red.gd"
#include                "graphic/Button_Yellow.gd"

const char              Keypad[KPM_NrModes][NRKEYPADNORMALKEYS][NRKEYALTSYMBOLS]
                          = {{"AÄÁÀÂÃÅÆ", "B", "CÇ", "DÐ", "EÉÈÊË", "F", "G", "H", "IÍÌÎÏ", "J", "K", "L", "Mµ", "NÑ", "OÖÓÒÔÕØ", "P", "Q", "R", "", "Sß", "T", "UÜÚÙÛ", "V", "W", "X", "YÝÿ", "Z"},
                             {"aäáàâãåæ", "b", "cç", "dð", "eéèêë", "f", "g", "h", "iíìîï", "j", "k", "l", "mµ", "nñ", "oöóòôõø", "p", "q", "r", "", "sß", "t", "uüúùû", "v", "w", "x", "yýÿ", "z"},
                             {"\"'»«", "([{", ")]}", "&", "%", "$£¥¢", "§" , "#" , "@©®",
                              "+"    , "*"  , "×÷±", "=", "/", "\\"  , "<" , ">" , "°^~", 
                              ""     , "."  , ","  , ";", ":", "!"   , "?" , "-_", "|"}};

const char              SpecialChars[NRKEYALTSYMBOLS+1] = ".,;-_()&!\"";

const char              T9ArrayCaps[10][7]
                          = {"0 .,;\"", "1-_&()", "2ABCÄ", "3DEF", "4GHI", "5JKL", "6MNOÖ", "7PQRS",  "8TUVÜ", "9WXYZ"};
const char              T9Array[10][7]
                          = {"0 .,;\"", "1-_&()", "2abcä", "3def", "4ghi", "5jkl", "6mnoö", "7pqrsß", "8tuvü", "9wxyz"};

tKeyPadButton           SpecialKeys[NRKEYPADSPECIALKEYS]
                          = {{1, &_Keyb_Play_Gd, ""},
                             {1, &_Keyb_Rwd_Gd, "Lös"}, {1, &_Keyb_Ffwd_Gd, "chen"}, {1, &_Keyb_Pause_Gd, "#..."}, {2, &_Keyb_Cut_Gd, "Leer"}, 
                             {2, NULL, "Abbrechen"}, {2, &_Keyb_Stop_Gd, "Speichern"}};

tKeyPadButton           ColorButtons[NRKEYPADCOLORBUTTONS]
                          = {{0, &_Keyb_Recall_Gd, "Original"}, {0, &_Button_Red_Gd, "Leeren"}, {0, &_Button_Green_Gd, "Kopieren"}, {0, &_Button_Yellow_Gd, "Einfügen"}, {0, &_Button_Blue_Gd, ""}};

char                   *Keyb_Clipboard = NULL;

char                   *Keyb_DictHeap = NULL;
int                    *Keyb_Dictionary = NULL;  //= {"salat", "schatz", "schild", "schildkröte", "schildpatt", "straße", "ähre"};
int                     Keyb_DictHeapSize = 0, Keyb_DictHeapPos = 0;
int                     Keyb_DictNrEntries = 0, Keyb_DictMaxEntries = 0;

int                     Keyb_SugOffset = 0, Keyb_InsertedChars = 0;
int                     Keyb_NrSug = 0, Keyb_FirstSug = 0, Keyb_CurSug = 0;

char                   *OSDKeyboard_Title = NULL;
char                   *OSDKeyboard_StringVar = NULL;
char                   *OSDKeyboard_StringVarOrig = NULL;
dword                   OSDKeyboard_StringMaxLen;

word                    OSDKeyboard_rgn = 0;
bool                    OSDKeyboard_ReturnToNormal;
bool                    OSDKeyboard_AllowEmpty;
bool                    OSDKeyboard_SaveDict;
bool                    OSDKeyboard_SavedVar = FALSE;

int                     OSDKeyboard_CursorPosition;
int                     OSDKeyboard_TextStartPosition;

tKeyPadMode             KeyPadMode;
byte                    KeyPadShiftState;  // 0: FALSE, 1: TRUE, 2: CAPSLOCK
bool                    KeyPadCursorMode;
int                     KeyPadSelection;
tKeyPadKeys             KeyPadPosition;


static bool LoadDictFromFile()
{
  FILE                 *f = NULL;
  char                 *Buffer = NULL;
  int                   p;
  size_t                BufSize = 0;
  bool                  ret = TRUE;

  TRACEENTER();

  if ((f = fopen(DICTIONARYPATH, "rb")) != NULL)
  {
    struct stat statbuf;
    fstat(fileno(f), &statbuf);

    // Allocate memory for dictionary
    Keyb_DictHeap = (char*) TAP_MemAlloc(statbuf.st_size + DICTHEAPSIZE);
    if (Keyb_DictHeap)
      Keyb_DictHeapSize = DICTHEAPSIZE;
    else
      ret = FALSE;
    Keyb_DictHeapPos = 0;
    Keyb_Dictionary = (int*) TAP_MemAlloc(DICTENTRIES * sizeof(int));
    if (Keyb_Dictionary)
      Keyb_DictMaxEntries = DICTENTRIES;
    else
      ret = FALSE;
    Keyb_DictNrEntries = 0;

    if (ret)
    {
      while (getline(&Buffer, &BufSize, f) >= 0)
      {
        // Remove line breaks in the end
        p = strlen(Buffer);
        while (p && (Buffer[p-1] == '\r' || Buffer[p-1] == '\n'))
          Buffer[--p] = '\0';

        // Insert line into Dictionary
        if (*Buffer)
          AddWordToDict(Buffer);
      }
    }
    fclose(f);
  }
  else
    ret = FALSE;

  TRACEEXIT();
  return ret;
}


void OSDKeyboard_Setup(char *Title, char *Variable, dword MaxLength, bool AllowEmpty, bool SaveDict)
{
  TRACEENTER();

  OSDKeyboard_Title = (char*) TAP_MemAlloc(strlen(Title) + 1);
  strcpy(OSDKeyboard_Title, Title);

  OSDKeyboard_StringVar = (char*) TAP_MemAlloc(MaxLength + 1);
  memset(OSDKeyboard_StringVar, 0, MaxLength + 1);
  strncpy(OSDKeyboard_StringVar, Variable, MaxLength);

  OSDKeyboard_StringVarOrig = Variable;
  OSDKeyboard_StringMaxLen = MaxLength;

  OSDKeyboard_AllowEmpty = AllowEmpty;
  OSDKeyboard_SaveDict = SaveDict;
  OSDKeyboard_SavedVar = FALSE;
  OSDKeyboard_CursorPosition = 0;
  OSDKeyboard_TextStartPosition = 0;
  KeyPadMode = KPM_Letters;
  KeyPadShiftState = FALSE;
  KeyPadCursorMode = FALSE;
  KeyPadSelection = 0;
  KeyPadPosition = KEY_A;

  if (!Keyb_Dictionary)
  {
    if (!LoadDictFromFile())
    {
      Keyb_DictHeap = (char*) TAP_MemAlloc(DICTHEAPSIZE);
      if (Keyb_DictHeap)
        Keyb_DictHeapSize = DICTHEAPSIZE;
      Keyb_DictHeapPos = 0;
      Keyb_Dictionary = (int*) TAP_MemAlloc(DICTENTRIES * sizeof(int));
      if (Keyb_Dictionary)
        Keyb_DictMaxEntries = DICTENTRIES;
      Keyb_DictNrEntries = 0;
    }
  }
  Keyb_SugOffset = 0;
  Keyb_InsertedChars = 0;
  Keyb_NrSug = 0;
  Keyb_FirstSug = 0;
  Keyb_CurSug = 0;

  TRACEEXIT();
}
