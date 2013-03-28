#include                "../libFireBird.h"

bool isUTFToppy(void)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("isUTFToppy");
  #endif

  bool ret;

  ret = FIS_fwAppl_ConvertToValidUTF8Str() != 0;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
