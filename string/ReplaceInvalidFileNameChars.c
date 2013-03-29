#include <string.h>
#include "FBLib_string.h"

void ReplaceInvalidFileNameChars(char *strName)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("ReplaceInvalidFileNameChars");
  #endif

  unsigned char         *s, *d;

  s = SkipCharTableBytes(strName);
  d = s;

  while(*s)
  {
    if(isLegalChar(s, InvalidFileNameChars))
    {
      *d = *s;
    }
    else
    {
      switch(*s)
      {
        // These characters are not allowed in Windows.
        case '*': *d = 'x'; break;
        case '"': *d = '\''; break;

        default:
          *d = '-';
          break;
      }
    }
    d++;
    s++;
  }
  *d = '\0';

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
