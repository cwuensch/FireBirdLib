#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuModifyItemValueColumn(bool HasValueColumn)
{
  Menu[CurrentMenuLevel].HasValueColumn = HasValueColumn;
  ListDirty = TRUE;
}

#endif
