#include <tap.h>
#include "FBLib_rec.h"

bool infData_Delete(char *infFileName, char *NameTag)
{
  bool                  ret;

  TRACEENTER();

  ret = infData_DeleteAbs(infData_LocToAbs(infFileName), NameTag);

  TRACEEXIT();
  return ret;
}
