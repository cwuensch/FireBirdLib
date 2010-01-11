#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuModifyScrollLoop(bool ScrollLoop)
{
  Menu[CurrentMenuLevel].ScrollLoop = ScrollLoop;
}

#endif
