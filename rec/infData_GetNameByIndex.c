#include <string.h>
#include <tap.h>
#include "FBLib_rec.h"

bool infData_GetNameByIndex(char *infFileName, dword NameIndex, char *NameTag)
{
  bool                  ret;

  TRACEENTER();

  ret = infData_GetNameByIndexAbs(infData_LocToAbs(infFileName), NameIndex, NameTag);

  TRACEEXIT();
  return ret;
}
