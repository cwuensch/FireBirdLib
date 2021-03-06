#include                "FBLib_TMSOSDKeyboard.h"

bool OSDKeyboard_isVisible(void)
{
  TRACEENTER();
  bool ret = (OSDKeyboard_rgn != 0);
  TRACEEXIT();
  return ret;
}
