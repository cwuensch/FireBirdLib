#include <stdio.h>
#include <tap.h>
#include "FBLib_rec.h"

extern FILE            *infDatainfFileAbs;

dword infData_FlenAbs(void)
{
  long    tempPos=0;
  long    tempLen=0;

  TRACEENTER();

  //This may be better with a stat() function
  tempPos = ftell(infDatainfFileAbs);
  fseek(infDatainfFileAbs, 0, SEEK_END);
  tempLen = ftell(infDatainfFileAbs);
  fseek(infDatainfFileAbs, tempPos, SEEK_SET);

  TRACEEXIT();
  return tempLen;
}
