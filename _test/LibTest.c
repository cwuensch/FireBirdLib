#include                <string.h>
#include                "tap.h"
#include                "../libFireBird.h"

TAP_ID                  (0);
TAP_PROGRAM_NAME        ("FBLibTest");
TAP_AUTHOR_NAME         ("FireBird");
TAP_DESCRIPTION         ("Tests different FBLib functions");
TAP_ETCINFO             (__DATE__);

char                    s[1024];

//Allowed string types:
//text
//05 text
//10 00 05 text
//1f xx text
//UTF8Text

#define ASCII     "ABCdef"
#define STDTEXT   "ABCäöüdef"
#define ISOTEXT   "\x05""ABCäöüdef"
#define ISOTEXT2  "\x10\x00\x05""ABCäöüdef"
#define ISOTEXT3  "\x1f\x05""ABCäöüdef"
#define UTFTEXT   "ABC\u00e4\u00f6\u00fc""def"
#define MIXED     "ABC\u00e4""ö\u00f6\u00fc""def"

void PrintResultInt(int Expected, int Received, int Spaces)
{
  while(Spaces)
  {
    TAP_PrintNet(" ");
    Spaces--;
  }

  if(Received != Expected)
  {
    TAP_PrintNet("failed. expected=%d, received=%d\n", Expected, Received);
  }
  else
  {
    TAP_PrintNet("passed\n");
  }
}

void PrintResultArray(byte *Expected, int ExpectedLen, byte *Received, int ReceivedLen, int Spaces)
{
  while(Spaces)
  {
    TAP_PrintNet(" ");
    Spaces--;
  }

  if((ReceivedLen != ExpectedLen) || memcmp(Received, Expected, ReceivedLen))
  {
    TAP_PrintNet("failed. expectedLen=%d, receivedLen=%d\n", ExpectedLen, ReceivedLen);
    TAP_PrintNet("  expected data\n");
    DumpMemory(Expected, ExpectedLen, 16);
    TAP_PrintNet("  received data\n");
    DumpMemory(Received, ReceivedLen, 16);
  }
  else
  {
    TAP_PrintNet("passed\n");
  }
}

void PrintResultBool(bool Expected, bool Received, int Spaces)
{
  while(Spaces)
  {
    TAP_PrintNet(" ");
    Spaces--;
  }

  if(Received != Expected)
  {
    TAP_PrintNet("failed. expected=%s, received=%s\n", Expected ? "true" : "false", Received ? "true" : "false");
  }
  else
  {
    TAP_PrintNet("passed\n");
  }
}


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

void TestStringFunctions(void)
{
  bool                  hasAnsiChars, hasUTFChars, ret;
  byte                  bpc, *p;
  int                   i, Exp, Rcv;

  CallTraceEnter("TestStringFunctions");

  //isUTFToppy
  TAP_PrintNet("isUTFToppy 01: %s\n", isUTFToppy() ? "yes" : "no");


  //isUTF8Char
  TAP_PrintNet("isUTF8Char 01: ");
  ret = isUTF8Char(NULL, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("isUTF8Char 02: ");
  ret = isUTF8Char(MIXED, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("isUTF8Char 03: ");
  ret = isUTF8Char(&MIXED[1], &bpc);
  PrintResultBool(FALSE, ret, 0);
  PrintResultInt(1, bpc, 15);

  TAP_PrintNet("isUTF8Char 04: ");
  ret = isUTF8Char(&MIXED[3], &bpc);
  PrintResultBool(TRUE, ret, 0);
  PrintResultInt(2, bpc, 15);

  TAP_PrintNet("isUTF8Char 05: ");
  ret = isUTF8Char(&MIXED[5], &bpc);
  PrintResultBool(FALSE, ret, 0);
  PrintResultInt(1, bpc, 15);


  //UTF8ToUTF32
  TAP_PrintNet("UTF8ToUTF32 01: ");
  UTF8ToUTF32(NULL, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("UTF8ToUTF32 02: ");
  UTF8ToUTF32(&MIXED[0], NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("UTF8ToUTF32 03: ");
  Rcv = UTF8ToUTF32(&MIXED[0], &bpc);
  PrintResultInt(0x41, Rcv, 0);
  PrintResultInt(1, bpc, 16);

  TAP_PrintNet("UTF8ToUTF32 04: ");
  Rcv = UTF8ToUTF32(&MIXED[1], &bpc);
  PrintResultInt(0x42, Rcv, 0);
  PrintResultInt(1, bpc, 16);

  TAP_PrintNet("UTF8ToUTF32 05: ");
  Rcv = UTF8ToUTF32(&MIXED[3], &bpc);
  PrintResultInt(0xe4, Rcv, 0);
  PrintResultInt(2, bpc, 16);


  //UTF32ToUTF8


  //SkipCharTableBytes
  TAP_PrintNet("SkipCharTableBytes 01: ");
  SkipCharTableBytes(NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("SkipCharTableBytes 02: ");
  p = SkipCharTableBytes(ASCII);
  PrintResultInt(0, (byte*)p - (byte*)&ASCII[0], 0);

  TAP_PrintNet("SkipCharTableBytes 03: ");
  p = SkipCharTableBytes(STDTEXT);
  PrintResultInt(0, (byte*)p - (byte*)&STDTEXT[0], 0);

  TAP_PrintNet("SkipCharTableBytes 04: ");
  p = SkipCharTableBytes(ISOTEXT);
  PrintResultInt(1, (byte*)p - (byte*)&ISOTEXT[0], 0);

  TAP_PrintNet("SkipCharTableBytes 05: ");
  p = SkipCharTableBytes(ISOTEXT2);
  PrintResultInt(3, (byte*)p - (byte*)&ISOTEXT2[0], 0);

  TAP_PrintNet("SkipCharTableBytes 06: ");
  p = SkipCharTableBytes(ISOTEXT3);
  PrintResultInt(2, (byte*)p - (byte*)&ISOTEXT3[0], 0);

  TAP_PrintNet("SkipCharTableBytes 07: ");
  p = SkipCharTableBytes(UTFTEXT);
  PrintResultInt(0, (byte*)p - (byte*)&UTFTEXT[0], 0);

  TAP_PrintNet("SkipCharTableBytes 08: ");
  p = SkipCharTableBytes(MIXED);
  PrintResultInt(0, (byte*)p - (byte*)&MIXED[0], 0);


  //GetUCPos
  TAP_PrintNet("GetUCPos 01: ");
  GetUCPos(NULL, 0);
  TAP_PrintNet("passed\n");

  for(i = -1; i < 11; i++)
  {
    TAP_PrintNet("GetUCPos %02d: ", i + 3);
    Exp = 0;

    p = GetUCPos(ISOTEXT2, i);
    switch(i)
    {
      case -1: Exp = 3; break;
      case  0: Exp = 3; break;
      case  1: Exp = 4; break;
      case  2: Exp = 5; break;
      case  3: Exp = 6; break;
      case  4: Exp = 7; break;
      case  5: Exp = 8; break;
      case  6: Exp = 9; break;
      case  7: Exp = 10; break;
      case  8: Exp = 11; break;
      case  9: Exp = 12; break;
      case 10: Exp = 12; break;
    }
    PrintResultInt(Exp, (int)(p - (byte*)&ISOTEXT2[0]), 0);

  }

  for(i = 0; i < 9; i++)
  {
    TAP_PrintNet("GetUCPos %02d: ", i + 14);
    Exp = 0;

    p = GetUCPos(UTFTEXT, i);
    switch(i)
    {
      case  0: Exp = 0; break;
      case  1: Exp = 1; break;
      case  2: Exp = 2; break;
      case  3: Exp = 3; break;
      case  4: Exp = 5; break;
      case  5: Exp = 7; break;
      case  6: Exp = 9; break;
      case  7: Exp = 10; break;
      case  8: Exp = 11; break;
    }
    PrintResultInt(Exp, (int)(p - (byte*)&UTFTEXT[0]), 0);
  }

  //strlenUC
  TAP_PrintNet("strlenUC 01: ");
  strlenUC(NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("strlenUC 02: ");
  PrintResultInt(6, strlenUC(ASCII), 0);

  TAP_PrintNet("strlenUC 03: ");
  PrintResultInt(9, strlenUC(STDTEXT), 0);

  TAP_PrintNet("strlenUC 04: ");
  PrintResultInt(9, strlenUC(ISOTEXT), 0);

  TAP_PrintNet("strlenUC 05: ");
  PrintResultInt(9, strlenUC(ISOTEXT2), 0);

  TAP_PrintNet("strlenUC 06: ");
  PrintResultInt(9, strlenUC(ISOTEXT3), 0);

  TAP_PrintNet("strlenUC 07: ");
  PrintResultInt(9, strlenUC(UTFTEXT), 0);

  TAP_PrintNet("strlenUC 08: ");
  PrintResultInt(10, strlenUC(MIXED), 0);


  //GetStringEncoding
  TAP_PrintNet("GetStringEncoding 01: ");
  GetStringEncoding(NULL, NULL, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("GetStringEncoding 02: ");
  GetStringEncoding(STDTEXT, NULL, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("GetStringEncoding 03: ");
  GetStringEncoding(ASCII, &hasAnsiChars, &hasUTFChars);
  PrintResultBool(FALSE, hasAnsiChars, 0);
  PrintResultBool(FALSE, hasUTFChars, 22);

  TAP_PrintNet("GetStringEncoding 04: ");
  GetStringEncoding(ISOTEXT, &hasAnsiChars, &hasUTFChars);
  PrintResultBool(TRUE, hasAnsiChars, 0);
  PrintResultBool(FALSE, hasUTFChars, 22);

  TAP_PrintNet("GetStringEncoding 05: ");
  GetStringEncoding(ISOTEXT2, &hasAnsiChars, &hasUTFChars);
  PrintResultBool(TRUE, hasAnsiChars, 0);
  PrintResultBool(FALSE, hasUTFChars, 22);

  TAP_PrintNet("GetStringEncoding 06: ");
  GetStringEncoding(ISOTEXT3, &hasAnsiChars, &hasUTFChars);
  PrintResultBool(TRUE, hasAnsiChars, 0);
  PrintResultBool(FALSE, hasUTFChars, 22);

  TAP_PrintNet("GetStringEncoding 07: ");
  GetStringEncoding(UTFTEXT, &hasAnsiChars, &hasUTFChars);
  PrintResultBool(FALSE, hasAnsiChars, 0);
  PrintResultBool(TRUE, hasUTFChars, 22);

  TAP_PrintNet("GetStringEncoding 08: ");
  GetStringEncoding(MIXED, &hasAnsiChars, &hasUTFChars);
  PrintResultBool(TRUE, hasAnsiChars, 0);
  PrintResultBool(TRUE, hasUTFChars, 22);


  //DeleteAt
  TAP_PrintNet("DeleteAt 01: ");
  DeleteAt(NULL, 0, 0);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("DeleteAt 02: ");
  strcpy(s, STDTEXT);
  DeleteAt(s, 0, 2);
  PrintResultArray("Cäöüdef", 8, s, strlen(s) + 1, 0);

  TAP_PrintNet("DeleteAt 03: ");
  strcpy(s, STDTEXT);
  DeleteAt(s, 4, 1);
  PrintResultArray("ABCäüdef", 9, s, strlen(s) + 1, 0);

  TAP_PrintNet("DeleteAt 04: ");
  strcpy(s, STDTEXT);
  DeleteAt(s, 6, 5);
  PrintResultArray("ABCäöü", 7, s, strlen(s) + 1, 0);

  TAP_PrintNet("DeleteAt 05: ");
  strcpy(s, STDTEXT);
  DeleteAt(s, 9, 1);
  PrintResultArray("ABCäöüdef", 10, s, strlen(s) + 1, 0);

  TAP_PrintNet("DeleteAt 06: ");
  strcpy(s, ISOTEXT);
  DeleteAt(s, 4, 1);
  PrintResultArray("\x05""ABCäüdef", 10, s, strlen(s) + 1, 0);

  TAP_PrintNet("DeleteAt 07: ");
  memcpy(s, ISOTEXT2, 12);
  s[12] = '\0';
  DeleteAt(s, 4, 1);
  PrintResultArray("\x10\x00\x05""ABCäüdef", 12, s, 12, 0);

  TAP_PrintNet("DeleteAt 08: ");
  strcpy(s, ISOTEXT3);
  DeleteAt(s, 4, 1);
  PrintResultArray("\x1f\x05""ABCäüdef", 11, s, strlen(s) + 1, 0);

  TAP_PrintNet("DeleteAt 09: ");
  strcpy(s, UTFTEXT);
  DeleteAt(s, 4, 1);
  PrintResultArray("ABC\u00e4\u00fc""def", 11, s, strlen(s) + 1, 0);


  //InsertAt
  TAP_PrintNet("InsertAt 01: ");
  InsertAt(NULL, 0, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("InsertAt 02: ");
  InsertAt(STDTEXT, 0, NULL);
  TAP_PrintNet("passed\n");

  TAP_PrintNet("InsertAt 03: ");
  strcpy(s, ASCII);
  InsertAt(s, 0, "X");
  PrintResultArray("XABCdef", 8, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 04: ");
  strcpy(s, ASCII);
  InsertAt(s, 3, "X");
  PrintResultArray("ABCXdef", 8, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 05: ");
  strcpy(s, ASCII);
  InsertAt(s, -5, "X");
  PrintResultArray("XABCdef", 8, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 06: ");
  strcpy(s, ASCII);
  InsertAt(s, 255, "X");
  PrintResultArray("ABCdefX", 8, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 07: ");
  strcpy(s, ISOTEXT);
  InsertAt(s, 5, "X");
  PrintResultArray("\x05""ABCäöXüdef", 12, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 08: ");
  memcpy(s, ISOTEXT2, 13);
  InsertAt(s, 5, "X");
  PrintResultArray("\x10\x00\x05""ABCäöXüdef", 14, s, 14, 0);

  TAP_PrintNet("InsertAt 09: ");
  strcpy(s, ISOTEXT3);
  InsertAt(s, 5, "X");
  PrintResultArray("\x1f\x05""ABCäöXüdef", 13, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 10: ");
  strcpy(s, ISOTEXT3);
  InsertAt(s, -1, "X");
  PrintResultArray("\x1f\x05""XABCäöüdef", 13, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 11: ");
  strcpy(s, UTFTEXT);
  InsertAt(s, 5, "X");
  PrintResultArray("ABC\u00e4\u00f6""X\u00fc""def", 14, s, strlen(s) + 1, 0);

  TAP_PrintNet("InsertAt 12: ");
  strcpy(s, UTFTEXT);
  InsertAt(s, 6, "X");
  PrintResultArray("ABC\u00e4\u00f6\u00fc""Xdef", 14, s, strlen(s) + 1, 0);

  CallTraceExit(NULL);
}

void TestDebugFunctions()
{
  CallTraceEnter("TestDebugFunctions");

  TAP_SPrint(s, "CallTraceComment ASCII   : %s", ASCII);
  CallTraceComment(s);

  TAP_SPrint(s, "CallTraceComment STDTEXT : %s", STDTEXT);
  CallTraceComment(s);

  TAP_SPrint(s, "CallTraceComment ISOTEXT : %s", ISOTEXT);
  CallTraceComment(s);

  TAP_SPrint(s, "CallTraceComment ISOTEXT2: %s", ISOTEXT2);
  CallTraceComment(s);

  TAP_SPrint(s, "CallTraceComment ISOTEXT3: %s", ISOTEXT3);
  CallTraceComment(s);

  TAP_SPrint(s, "CallTraceComment UTFTEXT : %s", UTFTEXT);
  CallTraceComment(s);

  TAP_SPrint(s, "CallTraceComment MIXED   : %s", MIXED);
  CallTraceComment(s);

  TAP_SPrint(s, "LogEntry UTFTEXT : %s", UTFTEXT);
  LogEntry(NULL, NULL, TRUE, TIMESTAMP_YMDHMS, s);

  CallTraceExit(NULL);
}

void TestHDDFunctions(void)
{
  CallTraceEnter("TestHDDFunctions");

  //HDD_ChangeDir("/DataFiles/TestFiles/\005Ansi_Ä");
  HDD_ChangeDir("/DataFiles/RecycleBin-");
  HDD_UnrecycleSF("\005Ansi_Ü.rec");

  CallTraceExit(NULL);
}

dword TAP_EventHandler(word event, dword param1, dword param2)
{
  (void) event;
  (void) param2;

  return param1;
}



int TAP_Main()
{
  CallTraceInit();
  CallTraceEnable(TRUE);

  CreateTestFiles();

  TestStringFunctions();
  TestDebugFunctions();
  TestHDDFunctions();

  return 0;
}
