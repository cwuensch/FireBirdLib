#include                <string.h>
#include                "../libFireBird.h"

bool StringDBSave(tStringDB *StringDB, char *FileName)
{
  TRACEENTER();

  TYPE_File            *f;
  bool                  ret;

  if(!StringDB || !FileName || !StringDB->DB)
  {
    TRACEEXIT();
    return FALSE;
  }

  if(TAP_Hdd_Exist(FileName)) TAP_Hdd_Delete(FileName);
  TAP_Hdd_Create(FileName, ATTR_NORMAL);
  f = TAP_Hdd_Fopen(FileName);
  if(!f)
  {
    TRACEEXIT();
    return FALSE;
  }

  ret = StringDBSaveToFile(StringDB, f);

  TAP_Hdd_Fclose(f);

  TRACEEXIT();
  return ret;
}
