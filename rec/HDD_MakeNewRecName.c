#include <string.h>
#include <stdlib.h>
#include "../libFireBird.h"

char *HDD_MakeNewRecName (char *fname, word sequence)
{
#ifdef _TMS_
  static char           try[MAX_FILE_NAME_SIZE + 1];
#else
  static char           try[TS_FILE_NAME_SIZE + 1];
#endif

  size_t                len;
  char                  *p;
  int                   j;
  char                  c1, c2;

  memset(try, 0, sizeof(try));
  strncpy(try, fname, sizeof(try));

  len = strlen(try);

  if (!(p = strrchr(try, '.'))) p = try + len;

#ifdef _TMS_
  if ((j = MAX_FILE_NAME_SIZE - len - 4) < 0)
#else
  if ((j = TS_FILE_NAME_SIZE - len - 4) < 0)
#endif
  {
    strcpy(p + j, p);
    p += j;
  }

  memmove(p + 3, p, strlen(p) + 1);

  if (sequence)
  {
    c1 = sequence / 10 % 10 + '0';
    c2 = sequence % 10 + '0';
    p[0] = '-';
  }
  else
  {
    srand(TAP_GetTick());
    c1 = rand() % 26 + 'A';
    c2 = rand() % 26 + 'A';
    p[0] = ' ';
  }

  p[1] = c1;
  p[2] = c2;

  return try;
}
