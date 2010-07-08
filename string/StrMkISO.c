#include                <string.h>
#include                "../libFireBird.h"

char   _isostring[512];

bool StrMkISO(byte *SourceString)
{
  if(!SourceString || (strlen(SourceString) > 511)) return FALSE;

  StrToISO(SourceString, _isostring);
  strcpy(SourceString, _isostring);

  return TRUE;
}
