#include                "../libFireBird.h"

void StrToISO(byte *SourceString, byte *DestString)
{
  if(!SourceString || !DestString) return;

  while(*SourceString)
  {
    *DestString = CharToISO(SourceString);
    if(*SourceString >= 0xc0) SourceString++;
    SourceString++;
    DestString++;
  }
  *DestString = '\0';
}
