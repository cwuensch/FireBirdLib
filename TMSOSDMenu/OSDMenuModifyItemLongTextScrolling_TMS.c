#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuModifyItemLongTextScrolling(bool AllowScrollingOfLongText)
{
  Menu[CurrentMenuLevel].AllowScrollingOfLongText = AllowScrollingOfLongText;
}

#endif
