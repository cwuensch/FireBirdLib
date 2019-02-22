#include "FBLib_TMSOSDMenu.h"

void OSDMenuSetMemo (void)
{
  tMenu *pMenu;

  TRACEENTER();

  pMenu = &Menu[CurrentMenuLevel];

  pMenu->AllowScrollingOfLongText = FALSE;
  pMenu->HasValueColumn = FALSE;
  pMenu->NumberedItems = FALSE;
  pMenu->OSDMenuDisplayMode = OMDM_Memo;

  TRACEEXIT();
}
