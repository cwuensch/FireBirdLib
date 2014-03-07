#include <stdio.h>
#include <tap.h>
#include "FBLib_rec.h"

extern FILE            *infDatainfFileAbs;

void infData_CloseFileAbs(void)
{
  TRACEENTER();

  if(infDatainfFileAbs)
  {
    fclose(infDatainfFileAbs);
    infDatainfFileAbs = NULL;
  }

  TRACEEXIT();
}
