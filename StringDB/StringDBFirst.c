#include                "../libFireBird.h"

char *StringDBFirst(tStringDB *StringDB)
{
  if(!StringDB) return '\0';

  StringDB->DBPtr = StringDB->DB;

  return StringDB->DBPtr;
}
