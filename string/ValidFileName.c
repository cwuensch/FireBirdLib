#include "FBLib_string.h"

char *ValidFileName(char *strName, eRemoveChars ControlCharacters)
{
  TRACEENTER();

  char                  *s, *d, *l;
  static char           validName[MAX_FILE_NAME_SIZE];

  s = strName;
  d = validName;
  l = d + MAX_FILE_NAME_SIZE - 1;

  while(*s)
  {
    if(isLegalChar(s, ControlCharacters)) *d++ = *s;

    if(d == l) break;

    s++;
  }

  *d = '\0';

  TRACEEXIT();
  return validName;
}
