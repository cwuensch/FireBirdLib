#include                "../libFireBird.h"

char *StringDBPrev(tStringDB *StringDB)
{
  char                 *p;

  if(!StringDB || !StringDB->DBPtr || (StringDB->DBPtr <= StringDB->DB)) return '\0';

  p = (StringDB->DBPtr - 2);
  while(*p || (p >= StringDB->DB)) p--;
  p++;
  StringDB->DBPtr = p;

  return p;
}