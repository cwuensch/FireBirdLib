#include                "../libFireBird.h"

char *StringDBNext(tStringDB *StringDB)
{
  char                 *p;

  if(!StringDB || !StringDB->DBPtr || (StringDB->DBPtr >= StringDB->DBEnd)) return '\0';

  p = StringDB->DBPtr;
  while(*p) p++;
  p++;
  StringDB->DBPtr = p;

  return p;
}
