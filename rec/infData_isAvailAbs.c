#include <tap.h>
#include "FBLib_rec.h"

bool infData_isAvailAbs(char *infFileName, char *NameTag, dword *PayloadSize)
{
  bool                  ret;

  TRACEENTER();

  ret = FALSE;

  if(infData_OpenFileAbs(infFileName))
    ret = infData_LocateSigAbs(NameTag, PayloadSize);

  infData_CloseFileAbs();

  TRACEEXIT();
  return ret;
}
