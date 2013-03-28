#include                <string.h>
#include                "../libFireBird.h"

bool StrMkUTF8(byte *SourceString, byte DefaultISO8859CharSet)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("StrMkUTF8");
  #endif

  char                 *_utf8string;
  bool                  hasAnsiChars, hasUTFChars;

  if(!SourceString)
  {
    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return FALSE;
  }

  GetStringEncoding(SourceString, &hasAnsiChars, &hasUTFChars);

  if(hasAnsiChars && !hasUTFChars)
  {
    _utf8string = TAP_MemAlloc(strlen(SourceString) << 2);
    if(!_utf8string)
    {
      #ifdef DEBUG_FIREBIRDLIB
        CallTraceExit(NULL);
      #endif

      return FALSE;
    }

    StrToUTF8(SourceString, _utf8string, DefaultISO8859CharSet);
    strcpy(SourceString, _utf8string);
    TAP_MemFree(_utf8string);
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return TRUE;
}
