#include                <string.h>
#include                "tap.h"
#include                "../libFireBird.h"

TAP_ID                  (0);
TAP_PROGRAM_NAME        ("FBLibTest");
TAP_AUTHOR_NAME         ("FireBird");
TAP_DESCRIPTION         ("Tests different FBLib functions");
TAP_ETCINFO             (__DATE__);

char                    s[8192];

void CreateTestFiles(void)
{
  CallTraceEnter("CreateTestFiles");

  HDD_ChangeDir("/DataFiles");
  if(!TAP_Hdd_Exist("TestFiles")) TAP_Hdd_Create("TestFiles", ATTR_FOLDER);
  HDD_ChangeDir("TestFiles");

  TAP_SPrint(s, "\005Ansi_Ä");
  TAP_Hdd_Create(s, ATTR_FOLDER);

  HDD_ChangeDir(s);
  TAP_Hdd_Create("\005Ansi_Ü.rec", ATTR_NORMAL);
  TAP_Hdd_Create("\005Ansi_Ü.rec.inf", ATTR_NORMAL);
  TAP_Hdd_Create("\005Ansi_Ü.rec.nav", ATTR_NORMAL);

  TAP_Hdd_Create("UTF8_\u00DC.rec", ATTR_NORMAL);
  TAP_Hdd_Create("UTF8_\u00DC.rec.inf", ATTR_NORMAL);
  TAP_Hdd_Create("UTF8_\u00DC.rec.nav", ATTR_NORMAL);
  HDD_ChangeDir("..");

  TAP_Hdd_Create("UTF8_\u00C4", ATTR_FOLDER);

  TAP_Hdd_Create("\005Ansi_Ö.rec", ATTR_NORMAL);
  TAP_Hdd_Create("\005Ansi_Ö.rec.inf", ATTR_NORMAL);
  TAP_Hdd_Create("\005Ansi_Ö.rec.nav", ATTR_NORMAL);

  TAP_Hdd_Create("UTF8_\u00D6.rec", ATTR_NORMAL);
  TAP_Hdd_Create("UTF8_\u00D6.rec.inf", ATTR_NORMAL);
  TAP_Hdd_Create("UTF8_\u00D6.rec.nav", ATTR_NORMAL);

  CallTraceExit(NULL);
}


void RemoveNullCharacters(char *strName, int *TotalLength)
{
  unsigned char         *s;
  int                   i, strLength;

  CallTraceEnter("RemoveNullCharacters");

  if(!strName || !*strName || !TotalLength)
  {
    #if STACKTRACE == TRUE
      CallTraceExit(NULL);
    #endif
    return;
  }

  s = SkipCharTableBytes(strName);
  i = (dword)s - (dword)strName;
  strLength = *TotalLength;

  while(i < strLength)
  {
    if(*s == '\0') *s = ' ';
    s++;
    i++;
  }

  CallTraceExit(NULL);
}

void RemoveInvalidCharacters(char *strName)
{
  unsigned char        *s, *d;
  byte                  BytesPerChar;

  CallTraceEnter("RemoveInvalidCharacters");

  if(!strName || !*strName)
  {
    #if STACKTRACE == TRUE
      CallTraceExit(NULL);
    #endif
    return;
  }

  s = SkipCharTableBytes(strName);
  d = s;

  while(*s)
  {
    if(isUTF8Char(s, &BytesPerChar))
    {
      memcpy(d, s, BytesPerChar);
      d += BytesPerChar;
      s += (BytesPerChar - 1);
    }
    else if(*s == (unsigned char)'\x8a')
    {
      *d = '\x0a';
      d++;
    }
    else if(isLegalChar(s, ControlChars))
    {
      *d = *s;
      d++;
    }

    s++;
  }
  *d = '\0';

  CallTraceExit(NULL);
}

void Test(void)
{
  CallTraceEnter("Test");

  //char *a = "\005Sendezeit täglich von 18:00 bis 24:00 Uhr";
  char *a = "Sendezeit täglich von 18:00 bis 24:00 Uhr";
  char  s[512];
  int   Len;

  memset(s, 0, 512);
  Len = strlen(a);
  memcpy(s, a, Len);

  RemoveNullCharacters(s, &Len);
  RemoveInvalidCharacters(s);

  DumpMemory(s, strlen(s) + 1, 16);

  StrMkUTF8(s, 0);

  DumpMemory(s, strlen(s) + 1, 16);

  CallTraceExit(NULL);
}

dword TAP_EventHandler(word event, dword param1, dword param2)
{
  static bool Init = TRUE;

  (void) event;
  (void) param2;

  if(Init)
  {
    //CreateTestFiles();
    Test();
    Init = FALSE;
  }

  //if(!OSDMenuIsVisible())
  if(!OSDMenuMessageBoxIsVisible())
  {
    TAP_Exit();
    return param1;
  }

  if(OSDMenuEvent(&event, &param1, &param2)) return 0;
  if(event == EVT_KEY)
  {
    if(param1 == RKEY_Exit)
    {
      //OSDMenuDestroy();
      OSDMenuMessageBoxDestroy();
    }
    param1 = 0;
  }

  return param1;
}

int TAP_Main()
{
  CallTraceInit();
  CallTraceEnable(TRUE);

  Test();

  return 0;
}
