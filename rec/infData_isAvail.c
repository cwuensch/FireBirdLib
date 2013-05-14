#include <tap.h>
#include "FBLib_rec.h"

bool infData_isAvail(char *infFileName, char *NameTag, dword *PayloadSize)
{
  bool                  ret;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_isAvail");
  #endif

  ret = FALSE;

  if(infData_OpenFile(infFileName))
    ret = infData_LocateSig(NameTag, PayloadSize);

  infData_CloseFile();

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
