#include                <string.h>
#include                "../libFireBird.h"

bool StringDBLoad(tStringDB *StringDB, char *FileName)
{
  TYPE_File            *f;
  dword                 l, p;

  if(!StringDB || !FileName) return FALSE;

  f = TAP_Hdd_Fopen(FileName);
  if(!f) return FALSE;

  if(StringDB->DB) TAP_MemFree(StringDB->DB);

  //DB Size
  TAP_Hdd_Fread(&l, sizeof(dword), 1, f);
  StringDB->DB = TAP_MemAlloc(l);
  if(!StringDB->DB)
  {
    TAP_Hdd_Fclose(f);
    return FALSE;
  }
  StringDB->DBEnd = l + StringDB->DB - 1;

  //Current pointer
  TAP_Hdd_Fread(&p, sizeof(dword), 1, f);
  StringDB->DBPtr = p + StringDB->DB;

  TAP_Hdd_Fread(StringDB->DB, 1, l, f);
  TAP_Hdd_Fclose(f);

  return TRUE;
}
