#include <string.h>
#include <tap.h>
#include "FBLib_rec.h"

bool infData_Set(char *infFileName, char *NameTag, dword PayloadSize, byte *Payload)
{
  bool                  ret;

  TRACEENTER();

  ret = infData_SetAbs(infData_LocToAbs(infFileName), NameTag, PayloadSize, Payload);

  TRACEEXIT();
  return ret;
}
