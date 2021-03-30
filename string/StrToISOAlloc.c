#include                <string.h>
#include                <stdlib.h>
#include                "libFireBird.h"

void StrToISOAlloc(const char *SourceString, char **DestString)
{
  TRACEENTER();

  if((SourceString == NULL) || (DestString == NULL))
  {
    if(DestString) *DestString =  NULL;

    TRACEEXIT();
    return;
  }

  *DestString = TAP_MemAlloc(strlenUC(SourceString) + 1);
  StrToISO(SourceString, *DestString);

  TRACEEXIT();
}
