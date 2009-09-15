#include                "FBLib_dialog.h"

tDialogMsgBox           *FBDialogMsgBox  = NULL;

void DialogMsgBoxInit(tDialogMsgBox *DialogMsgBox, tDialogProfile *DialogProfile, char *Title, char *SubTitle)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogMsgBoxInit");
#endif

  if (FBDialogMsgBox || !(FBDialogMsgBox = DialogMsgBox))
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  memset(FBDialogMsgBox, 0, sizeof(tDialogMsgBox));

  DialogMsgBoxTitleSet(Title, SubTitle);

  if (!FBDialogProfile)
  {
    FBDialogProfile = DialogProfile;
    ProfileInit();
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
