#include <stdio.h>
#include <tap.h>
#include "FBLib_rec.h"

FILE                   *infDatainfFileAbs = NULL;

bool infData_OpenFileAbs(char *infFileName)
{
  TRACEENTER();

  infDatainfFileAbs = fopen(infFileName, "r+");

  TRACEEXIT();
  return (infDatainfFileAbs != NULL);
}
