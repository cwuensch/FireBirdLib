#include <tap.h>
#include "FBLib_rec.h"

bool infData_isAvail(char *infFileName, char *NameTag, dword *PayloadSize)
{
  bool                  ret;

  TRACEENTER();

  ret = infData_isAvailAbs(infData_LocToAbs(infFileName), NameTag, PayloadSize);

  TRACEEXIT();
  return ret;
}
