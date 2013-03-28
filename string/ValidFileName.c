#include "FBLib_string.h"

char *ValidFileName(char *strName, eRemoveChars ControlCharacters)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("ValidFileName");
  #endif

  char                  *s, *p, *l;
  static char           validName[MAX_FILE_NAME_SIZE];

  s = strName;
  p = validName;
  l = p + MAX_FILE_NAME_SIZE - 1;

  while(*s)
  {
    if(isLegalChar(s, ControlCharacters)) *p++ = *s;

    if(p == l) break;

    s++;
  }

  *p = '\0';

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return validName;
}
