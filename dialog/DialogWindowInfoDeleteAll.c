#include                "FBLib_dialog.h"

void DialogWindowInfoDeleteAll(void)
{
  tDialogInfoItem       *item, *next;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowInfoDeleteAll");
#endif

  if (!FBDialogWindow)
  {

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

    return;
  }

  item = FBDialogWindow->InfoItems;

  while (item)
  {
    next = item->next;
    TAP_MemFree(item);
    item = next;
  }

  FBDialogWindow->InfoItems = NULL;
  FBDialogWindow->InfoOwnForeColor = TRUE;
  FBDialogWindow->OSDInfoForeDirty = TRUE;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
