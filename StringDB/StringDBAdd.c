#include                <string.h>
#include                "../libFireBird.h"

dword StringDBAdd(tStringDB *StringDB, char *Text)
{
  char                 *p;

  if(!StringDB || !Text) return 0;

  p = StringDB->DB;
  while(p < StringDB->DBEnd)
  {
    if(!strcmp(p, Text)) return (dword)p - (dword)StringDB->DB;

    p += (strlen(p) + 1);
  }


  if(((StringDB->DBEnd - StringDB->DB) + strlen(Text) + 2) > StringDB->DBSize)
  {
    int                 NewStringDBSize;
    char               *NewStringDB;

    if(StringDB->DBSize == 0)
      NewStringDBSize = 2 * strlen(Text);
    else
      NewStringDBSize = StringDB->DBSize << 1;

    NewStringDB = TAP_MemAlloc(NewStringDBSize);
    if(!NewStringDB) return 0;
    memset(NewStringDB, 0, NewStringDBSize);
    memcpy(NewStringDB, StringDB->DB, NewStringDBSize);
    TAP_MemFree(StringDB->DB);

    StringDB->DBPtr = StringDB->DBPtr - StringDB->DB + NewStringDB;
    StringDB->DBEnd = StringDB->DBEnd - StringDB->DB + NewStringDB;

    StringDB->DB = NewStringDB;
    StringDB->DBSize = NewStringDBSize;
  }
  p = StringDB->DBEnd;
  strcpy(StringDB->DBEnd, Text);
  StringDB->DBEnd = StringDB->DBEnd + strlen(Text) + 1;

  return (dword)p - (dword)StringDB->DB;
}
