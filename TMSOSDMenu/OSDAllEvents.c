#include                "FBLib_TMSOSDMenu.h"

bool OSDAllEvents(word *event, dword *param1, dword *param2)
{
  TRACEENTER();

  (void) param2;

  if(InfoBoxOSDRgn && WaitSpinnerRgn)
    OSDMenuWaitSpinnerIdle();
  OSDMessageEvent(event, param1, param2);
  OSDColorPickerEvent(event, param1, param2);
  OSDMenuEvent(event, param1, param2);

  TRACEEXIT();
  return FALSE;
}
