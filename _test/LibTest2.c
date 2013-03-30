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

void Test(void)
{
  TYPE_File            *f;
  int                   fl;
  tRECHeaderInfo        RECHeaderInfo;

  CallTraceEnter("Test");

  HDD_ChangeDir("/DataFiles/TestFiles");
  if(!HDD_ChangeDir("\005Ansi_Ä"))
  {
    TAP_PrintNet("Failed to change to the subdir\n");
  }

  f = TAP_Hdd_Fopen("cz.rec.inf");
  if(!f)
  {
    TAP_PrintNet("Failed to open test inf\n");
  }
  else
  {
    fl = TAP_Hdd_Flen(f);
    TAP_Hdd_Fread(s, fl, 1, f);
    TAP_Hdd_Fclose(f);

    HDD_DecodeRECHeader(s, &RECHeaderInfo, ST_UNKNOWN);
    OSDMemoInitialize(TRUE, "\005ANSI äöü", "UTF Text", RECHeaderInfo.ExtEventText);
    OSDMenuUpdate(FALSE);

    //OSDMenuMessageBoxInitialize("\u3187\u3184\u3140", RECHeaderInfo.EventEventName);
    //OSDMenuMessageBoxButtonAdd("\u3187\u3184\u3140  \u21af");
    //OSDMenuMessageBoxShow();
  }

  HDD_TAP_GetCurrentDir(s);
  DumpMemory(s, strlen(s) + 1, 16);

  CallTraceExit(NULL);
}

void rmdirTest(void)
{
  CallTraceEnter("rmdirTest");

  HDD_RemoveDir("/DataFiles/TestFiles/\005Ansi_Ä", TRUE);
  HDD_RemoveDir("/DataFiles/TestFiles/UTF8_\u00c4", TRUE);

  CallTraceExit(NULL);
}

void renameTest(void)
{
  char n1[256], n2[256];

  CallTraceEnter("renameTest");

  strcpy(n1, "\005Ansi_Ö.rec");
  strcpy(n2, "Ansi-UTF8_\u00D6.rec");

  HDD_ChangeDir("/DataFiles/TestFiles");
  HDD_Rename(n1, n2);

  CallTraceExit(NULL);
}

void LogoNameTest(void)
{
  char *LogoName;

  CallTraceEnter("LogoNameTest");

  LogoName = LogoManager_ChannelNameToLogoName("\005Ansi_Ö");
  DumpMemory(LogoName, strlen(LogoName) + 1, 16);

  LogoName = LogoManager_ChannelNameToLogoName("UTF8_\u00D6");
  DumpMemory(LogoName, strlen(LogoName) + 1, 16);

  CallTraceExit(NULL);
}

void FixInvalidTest(void)
{
  char n1[256], n2[256];

  CallTraceEnter("FixInvalidTest");

  strcpy(n1, "\005Ansi_Ö.rec");
  strcpy(n2, "Ansi-UTF8_\u00D6.rec");

  FixInvalidFileName(n1);
  FixInvalidFileName(n2);

  CallTraceExit(NULL);
}

void SvcFindTest(void)
{
  bool                  ret;
  TYPE_ServiceType      SvcType;
  int                   SvcNum;

  ret = FlashServiceFindNum(1, 1, 1007, 4911, &SvcType, &SvcNum);
  TAP_PrintNet("ORF1HD: %s, %d/%d\n", ret ? "T" : "F", SvcType, SvcNum);

  ret = FlashServiceFindNum(1, 1, 1007 , 4912, &SvcType, &SvcNum);
  TAP_PrintNet("ORF2HD: %s, %d/%d\n", ret ? "T" : "F", SvcType, SvcNum);

  ret = FlashServiceFindNum(1, 1, 1115 , 13134, &SvcType, &SvcNum);
  TAP_PrintNet("FN4: %s, %d/%d\n", ret ? "T" : "F", SvcType, SvcNum);
}

dword TAP_EventHandler(word event, dword param1, dword param2)
{
  static bool Init = TRUE;

  (void) event;
  (void) param2;

  if(Init)
  {
    CreateTestFiles();
    //LogoNameTest();
    FixInvalidTest();
    Init = FALSE;
  }

  if(!OSDMenuIsVisible())
  //if(!OSDMenuMessageBoxIsVisible())
  {
    TAP_Exit();
    return param1;
  }

  if(OSDMenuEvent(&event, &param1, &param2)) return 0;
  if(event == EVT_KEY)
  {
    if(param1 == RKEY_Exit)
    {
      OSDMenuDestroy();
      //OSDMenuMessageBoxDestroy();
    }
    param1 = 0;
  }

  return param1;
}

int TAP_Main()
{
  CallTraceInit();
  CallTraceEnable(TRUE);

  //rmdirTest();
  SvcFindTest();

  return 0;
}
