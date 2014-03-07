#include                <string.h>
#include                "../libFireBird.h"

bool StringDBLoad(tStringDB *StringDB, char *FileName)
{
  TRACEENTER();

  TYPE_File            *f;
  bool                  ret;

  if(!StringDB || !FileName)
  {
    TRACEEXIT();
    return FALSE;
  }

  f = TAP_Hdd_Fopen(FileName);
  if(!f)
  {
    TRACEEXIT();
    return FALSE;
  }

  ret = StringDBLoadFromFile(StringDB, f);

  TAP_Hdd_Fclose(f);

  TRACEEXIT();
  return ret;
}
