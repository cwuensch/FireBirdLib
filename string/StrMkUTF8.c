#include                <string.h>
#include                "../libFireBird.h"

char   _utf8string[512];

bool StrMkUTF8(byte *SourceString)
{
  if(!SourceString || (strlen(SourceString) > 511)) return FALSE;

  StrToUTF8(SourceString, _utf8string);
  strcpy(SourceString, _utf8string);

  return TRUE;
}
