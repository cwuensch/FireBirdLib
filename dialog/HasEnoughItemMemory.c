#include                "FBLib_dialog.h"

bool HasEnoughItemMemory(void)
{
  tDialogItem           *TempDialogItems  = NULL;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("HasEnoughItemMemory");
#endif

  if (FBDialogWindow && (FBDialogWindow->NrItems == FBDialogWindow->ReservedItems))
  {
    //Add additional entries
    TempDialogItems = TAP_MemAlloc_Chk("HasEnoughItemMemory", (FBDialogWindow->ReservedItems + ITEMS_TO_ADD) * sizeof (tDialogItem));

    if (!TempDialogItems)
    {

#ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
#endif

      return FALSE;
    }

    if (FBDialogWindow->DialogItems) memcpy (TempDialogItems, FBDialogWindow->DialogItems, FBDialogWindow->ReservedItems * sizeof (tDialogItem));
    memset (TempDialogItems + FBDialogWindow->ReservedItems, 0, ITEMS_TO_ADD * sizeof (tDialogItem));
    if (FBDialogWindow->DialogItems) TAP_MemFree (FBDialogWindow->DialogItems);

    FBDialogWindow->ReservedItems += ITEMS_TO_ADD;
    FBDialogWindow->DialogItems = TempDialogItems;
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return TRUE;
}
