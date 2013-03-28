#include "../libFireBird.h"

bool isAnyOSDVisible(dword checkX, dword checkY, dword checkW, dword checkH)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("isAnyOSDVisible");
  #endif

  bool ret = isAnyOSDVisibleEx(checkX, checkY, checkW, checkH, TAP_PLANE);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
