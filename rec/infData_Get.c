#include <tap.h>
#include "FBLib_rec.h"

bool infData_Get(char *infFileName, char *NameTag, dword *PayloadSize, byte **Payload)
{
  bool                  ret;

  TRACEENTER();

  ret = infData_GetAbs(infData_LocToAbs(infFileName), NameTag, PayloadSize, Payload);

  TRACEEXIT();
  return ret;
}
