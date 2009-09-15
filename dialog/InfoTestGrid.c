#include                "FBLib_dialog.h"

void InfoTestGrid(void)
{
  int                   x;
  dword                 y;
  dword                 ColHigh = 0, ColLow = 0;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("InfoTestGrid");
#endif

  if (!FBDialogWindow)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

#ifdef _TMS_
  ColHigh = ARGB(TAP_ALPHA, 255, 255, 255);
  ColLow  = ARGB(TAP_ALPHA, 82, 82, 255);
#else
  ColHigh = ARGB(TAP_ALPHA, 31, 31, 31);
  ColLow  = ARGB(TAP_ALPHA, 10, 10, 31);
#endif

  for (x = 10; x < Info_C_Gd->width * FBDialogWindow->NrInfoColumns; x += 10)
    DrawOSDLine (FBDialogWindow->OSDRgn, Border_Info_W_Gd->width + x, FBDialogWindow->InfoY, Border_Info_W_Gd->width + x, FBDialogWindow->InfoSY, (x % 100) ? ColHigh : ColLow);

  for (y = 10; y < FBDialogWindow->InfoSY - FBDialogWindow->InfoY; y += 10)
    DrawOSDLine (FBDialogWindow->OSDRgn, Border_Info_W_Gd->width, FBDialogWindow->InfoY + y, Border_Info_W_Gd->width + Info_C_Gd->width * FBDialogWindow->NrInfoColumns, FBDialogWindow->InfoY + y, (y % 100) ? ColHigh : ColLow);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
