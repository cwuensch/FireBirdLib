#include <string.h>
#include <unistd.h>
#include <tap.h>
#include "FBLib_rec.h"

extern int truncate (__const char *__file, __off_t __length);

void infData_TruncateAbs(char *infFileName, dword Position)
{
  TRACEENTER();

  truncate(infFileName, Position);

  TRACEEXIT();
}
