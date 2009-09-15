#include                "FBLib_dialog.h"

void DialogWindowAlpha(byte Alpha)
{
  dword                 i, j;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowAlpha");
#endif

  if (!FBDialogWindow || !FBDialogWindow->isVisible || !FBDialogWindow->OSDRgn || !FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  if (FBDialogProfile->Fade && !FBDialogWindow->Multiple)
  {
    if (Alpha > FBDialogWindow->Transparency)
    {
      for (i = FBDialogWindow->Transparency; i < Alpha; i++)
      {
        TAP_Osd_SetTransparency(FBDialogWindow->OSDRgn, i);
        for (j = 0; j < FBDialogProfile->Fade; j++) TAP_Delay(0);
      }
    }

    if (Alpha < FBDialogWindow->Transparency)
    {
      for (i = FBDialogWindow->Transparency; i > Alpha; i--)
      {
        TAP_Osd_SetTransparency(FBDialogWindow->OSDRgn, i);
        for (j = 0; j < FBDialogProfile->Fade; j++) TAP_Delay(0);
      }
    }
  }

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

  FBDialogWindow->Transparency = Alpha;
  TAP_Osd_SetTransparency(FBDialogWindow->OSDRgn, FBDialogWindow->Transparency);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
