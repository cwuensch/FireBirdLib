#include                "FBLib_TMSOSDKeyboard.h"

void OSDMenuKeyboard_Finish(void)
{
  if(OSDMenuKeyboard_rgn)
  {
    TAP_MemFree(OSDMenuKeyboard_StringVar);
    OSDMenuKeyboard_StringVar = NULL;
    if(OSDMenuKeyboard_Title) TAP_MemFree(OSDMenuKeyboard_Title);
    OSDMenuKeyboard_Title = NULL;
    TAP_Osd_Delete(OSDMenuKeyboard_rgn);
    OSDMenuKeyboard_rgn = 0;
    if(OSDMenuKeyboard_ReturnToNormal) TAP_EnterNormalNoInfo();
    OSDMenuKeyboard_TMSRemoteDirectMode(FALSE);
    OSDMenuKeyboard_StringVarOrig = NULL;
  }
}
