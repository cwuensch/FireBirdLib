#include                <string.h>
#define FB_USE_UNICODE_OSD
#include                "libFireBird.h"

byte *strncpyUC(byte *dest, const byte *src, size_t n)
{
  TRACEENTER();

  byte                 *p;
  size_t                CharTableBytes;

  if(!src || !dest)
  {
    TRACEEXIT();
    return NULL;
  }

  p = SkipCharTableBytes(src);
  CharTableBytes = p - src;

  if(CharTableBytes == 0)
    strncpy(dest, src, n);
  else
  {
    memcpy(dest, (void *) src, CharTableBytes < n ? CharTableBytes : n);
    strncpy(&dest[CharTableBytes], p, n - CharTableBytes);
  }

  TRACEEXIT();
  return dest;
}
