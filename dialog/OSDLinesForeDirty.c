#include                "FBLib_dialog.h"

bool OSDLinesForeDirty(bool All)
{
  int                   i;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("OSDLinesForeDirty");
#endif

  if (!FBDialogWindow)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return FALSE;
  }

  for (i = 0; i < FBDialogWindow->NrItemLines; i++)
    if (!FBDialogWindow->OSDLineForeDirty[i] == All)
    {

#ifdef DEBUG_FIREBIRDLIB
      CallTraceExit(NULL);
#endif

      return !All;
    }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return All;
}
