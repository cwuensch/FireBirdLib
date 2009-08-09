#include "FBLib_tap.h"

#ifdef _TMS_
  char                  TAPDirStack[TAPDIR_MAX_STACK][200];
#else
  dword                 TAPDirStack[TAPDIR_MAX_STACK];
#endif

int                     TAPDirStackDepth = -1;

bool HDD_TAP_PushDir (void)
{
  if (++TAPDirStackDepth < TAPDIR_MAX_STACK)
  {
#ifdef _TMS_
    if (HDD_TAP_GetCurrentDir(TAPDirStack[TAPDirStackDepth]) == 0) return TRUE;
#else
    if ((int)(TAPDirStack[TAPDirStackDepth] = (dword)HDD_TAP_GetCurrentDirCluster()) >= 0) return TRUE;
#endif
  }
  TAPDirStackDepth--;
  return FALSE;
}
