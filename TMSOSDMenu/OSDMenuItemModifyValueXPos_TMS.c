#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuItemModifyValueXPos(dword NewValueXPos)
{
  tMenu                *pMenu;

  pMenu = &Menu[CurrentMenuLevel];

  if(NewValueXPos)
    pMenu->ValueXPos = NewValueXPos;
  else
    pMenu->ValueXPos = 350;

  ListDirty = TRUE;
}

#endif
