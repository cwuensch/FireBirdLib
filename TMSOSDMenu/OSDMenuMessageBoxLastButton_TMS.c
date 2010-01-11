#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

dword OSDMenuMessageBoxLastButton(void)
{
  return MessageBox.CurrentButton;
}

#endif
