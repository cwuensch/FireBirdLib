#include                <string.h>
#include                "FBLib_dialog.h"

int DialogWindowItemAdd(char *Parameter, dword ParameterColor, char *Value, dword ValueColor, bool Selectable, bool Enabled, eDialogItemIcons IconType, TYPE_GrData *IconGd)
{
#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DialogWindowItemAdd");
#endif

  if (!FBDialogWindow)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return -1;
  }

  //Check if there is enough space for a new entry
  if (!HasEnoughItemMemory())
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return -1;
  }

  FBDialogWindow->NrItems++;

  DialogWindowItemChangeParameter(FBDialogWindow->NrItems - 1, Parameter, ParameterColor);
  DialogWindowItemChangeValue(FBDialogWindow->NrItems - 1, Value, ValueColor);
  DialogWindowItemChangeFlags(FBDialogWindow->NrItems - 1, Selectable, Enabled);
  DialogWindowItemChangeIcon(FBDialogWindow->NrItems - 1, IconType, IconGd);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return FBDialogWindow->NrItems - 1;
}
