#include <string.h>
#include "FBLib_string.h"

char *ValidFileName(char *strName, eRemoveChars ControlCharacters, char *Result, int ResultSize)
{
  TRACEENTER();

  char                  *s, *d, *l;
  byte                  BytesPerCharacter;

  d = Result;

  if(strName && *strName && Result && (ResultSize > (int)strlen(strName)))
  {
    strcpy(Result, strName);
    s = strName;
    l = d + MAX_FILE_NAME_SIZE;

    while(*s)
    {
      if(isLegalChar(s, ControlCharacters))
      {
        if(isUTF8Char(s, &BytesPerCharacter))
        {
          if(d + BytesPerCharacter >= l) break;

          //As this is a multibyte UTF character, copy all bytes
          memcpy(d, s, BytesPerCharacter);
          d += BytesPerCharacter;
          s += (BytesPerCharacter - 1);
        }
        else
        {
          if(d == l) break;

          *d = *s;
          d++;
        }
      }
      s++;
    }
  }
  if(ResultSize) *d = '\0';

  TRACEEXIT();
  return Result;
}
