#include                <string.h>
#define FB_USE_UNICODE_OSD
#include                "libFireBird.h"

int strlenUC(const byte *s)
{
  TRACEENTER();

  byte                 *p, *pEnd;
  int                   Count;
  byte                  BPC;

  if(!s || !*s)
  {
    TRACEEXIT();
    return 0;
  }

  p = SkipCharTableBytes(s);
  pEnd = p + strlen(p);

  Count = 0;
  while(p < pEnd)
  {
    isUTF8Char(p, &BPC);
    Count++;
    p += BPC;
  }

  TRACEEXIT();
  return Count;
}
