#include                <string.h>
#include                "FBLib_dialog.h"

void DialogWindowItemChangeIcon(int ItemIndex, eDialogItemIcons IconType, TYPE_GrData *IconGd)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowItemChangeIcon");
#endif

  if (!FBDialogWindow || !FBDialogWindow->DialogItems || ItemIndex < 0 || ItemIndex >= FBDialogWindow->NrItems)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  FBDialogWindow->DialogItems[ItemIndex].Icon = IconType;
  FBDialogWindow->DialogItems[ItemIndex].UserIcon = (IconType == DialogItemIcon_User ? IconGd : NULL);

  if (ItemIndex >= FBDialogWindow->TopItem && ItemIndex <= FBDialogWindow->TopItem + FBDialogWindow->NrItemLines - 1) FBDialogWindow->OSDLineForeDirty[ItemIndex - FBDialogWindow->TopItem] = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
