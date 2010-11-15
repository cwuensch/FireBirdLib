#include                "../libFireBird.h"

char *StringDBCurrent(tStringDB *StringDB)
{
  if(!StringDB) return '\0';

  return StringDB->DBPtr;
}
