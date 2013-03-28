#include                <string.h>
#include                "../libFireBird.h"

byte *strcpyUC(byte *dest, const byte *src)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("strcpyUC");
  #endif

  const byte           *p;
  int                   CharTableBytes;

  if(!src || !dest)
  {
    #ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
    #endif

    return NULL;
  }

  p = SkipCharTableBytes(src);
  CharTableBytes = p - src;

  if(CharTableBytes == 0)
    strcpy(dest, src);
  else
  {
    memcpy(dest, src, CharTableBytes);
    strcpy(&dest[CharTableBytes], p);
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return dest;
}
