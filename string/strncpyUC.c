#include                <string.h>
#include                "../libFireBird.h"

byte *strncpyUC(byte *dest, const byte *src, size_t n)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("strncpyUC");
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
    strncpy(dest, src, n);
  else
  {
    memcpy(dest, src, CharTableBytes < n ? CharTableBytes : n);
    strncpy(&dest[CharTableBytes], p, n - CharTableBytes);
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return dest;
}
