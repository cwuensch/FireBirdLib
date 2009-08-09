#include "FBLib_string.h"

char *ValidFileName (char *strName, eRemoveChars ControlCharacters)
{
  char                  *s, *p, *l;
#ifdef _TMS_
  static char           validName [MAX_FILE_NAME_SIZE];
#else
  static char           validName [TF_FILE_NAME_SIZE];
#endif

  s = strName;
  p = validName;
#ifdef _TMS_
  l = p + MAX_FILE_NAME_SIZE - 1;
#else
  l = p + TF_FILE_NAME_SIZE - 1;
#endif

  while (*s)
  {
    if (isLegalChar(*s, ControlCharacters)) *p++ = *s;

    if (p == l) break;

    s++;
  }

  *p = '\0';

  return validName;
}
