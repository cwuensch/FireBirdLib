#include <stdio.h>
#include "FBLib_hdd.h"

bool HDD_Exist(const char *AbsPath)
{
  TRACEENTER();

  tstat64               statbuf;
  bool                  ret;

  if(!AbsPath || !*AbsPath)
  {
    TRACEEXIT();
    return FALSE;
  }

  ret = (stat64(AbsPath, &statbuf) == 0);

  TRACEEXIT();
  return ret;
}
