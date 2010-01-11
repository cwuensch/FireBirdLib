#include "../libFireBird.h"

#ifdef _TMS_

bool isAnyOSDVisible(dword checkX, dword checkY, dword checkW, dword checkH)
{
  return isAnyOSDVisibleEx(checkX, checkY, checkW, checkH, TAP_PLANE);
}

#endif
