#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuModifyItemNumbered(bool NumberedItems)
{
  Menu[CurrentMenuLevel].NumberedItems = NumberedItems;
  ListDirty = TRUE;
}

#endif
