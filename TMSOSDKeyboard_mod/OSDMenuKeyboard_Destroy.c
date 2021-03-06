#include                "FBLib_TMSOSDKeyboard.h"

void OSDMenuKeyboard_Destroy(void)
{
  if(OSDMenuKeyboard_rgn)
  {
    OSDMenuKeyboard_TMSRemoteDirectMode(FALSE);
    TAP_Osd_Delete(OSDMenuKeyboard_rgn);
    OSDMenuKeyboard_rgn = 0;
    TAP_MemFree(OSDMenuKeyboard_Title);
    OSDMenuKeyboard_Title = NULL;
    TAP_MemFree(OSDMenuKeyboard_StringVar);
    OSDMenuKeyboard_StringVar = NULL;
    OSDMenuKeyboard_StringVarOrig = NULL;
    if(OSDMenuKeyboard_ReturnToNormal) TAP_EnterNormalNoInfo();
  }
}
