#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

bool OSDMenuPush(void)
{
  if(CurrentMenuLevel >= (NRMENULEVELS - 1)) return FALSE;

  CurrentMenuLevel++;
  memset(&Menu[CurrentMenuLevel], 0, sizeof(tMenu));

  return TRUE;
}

#endif