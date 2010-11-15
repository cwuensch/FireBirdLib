#include                <string.h>
#include                "../libFireBird.h"

bool StringDBSave(tStringDB *StringDB, char *FileName)
{
  TYPE_File            *f;
  dword                 l, p;

  if(!StringDB || !FileName || !StringDB->DB) return FALSE;

  if(TAP_Hdd_Exist(FileName)) TAP_Hdd_Delete(FileName);
  TAP_Hdd_Create(FileName, ATTR_NORMAL);
  f = TAP_Hdd_Fopen(FileName);
  if(!f) return FALSE;

  //DB Size
  l = StringDB->DBEnd - StringDB->DB + 1;
  TAP_Hdd_Fwrite(&l, sizeof(dword), 1, f);

  //Current pointer
  p = StringDB->DBPtr - StringDB->DB;
  TAP_Hdd_Fwrite(&p, sizeof(dword), 1, f);

  TAP_Hdd_Fwrite(StringDB->DB, 1, l, f);
  TAP_Hdd_Fclose(f);

  return TRUE;
}
