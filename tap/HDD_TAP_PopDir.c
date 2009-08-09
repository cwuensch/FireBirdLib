#include "FBLib_tap.h"

bool HDD_TAP_PopDir (void)
{
#ifdef _TMS_
  if (TAPDirStackDepth >= 0) return HDD_ChangeDir(TAPDirStack[TAPDirStackDepth--]);
#else
  if (TAPDirStackDepth >= 0) return HDD_TAP_SetCurrentDirCluster(TAPDirStack[TAPDirStackDepth--]);
#endif
  else return FALSE;
}
