#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuMessageBoxButtonSelect(dword SelectedButton)
{
  if(SelectedButton >= MessageBox.NrButtons) return;

  MessageBox.CurrentButton = SelectedButton;
  if(MessageBoxOSDRgn) OSDMenuMessageBoxShow();
}

#endif
