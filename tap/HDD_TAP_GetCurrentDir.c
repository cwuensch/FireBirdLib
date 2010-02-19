#include <string.h>
#include "../libFireBird.h"

//Return codes:     0: OK
//                 -1: not enough memory (from HDD_TAP_GetCurrentDirCluster)
//                 -2: buffer overrun in subdir search (from HDD_TAP_GetCurrentDirCluster)
//                 -3: Lib init failed (from HDD_TranslateDirCluster via HDD_TAP_GetCurrentDirCluster)

int HDD_TAP_GetCurrentDir(char *CurrentDir)
{
#ifdef _TMS_
  static dword               *_curTapTask = NULL;
  static tTMSTAPTaskTable    *TAPTaskTable = NULL;
  dword                *dw;

  //Get all needed variables
  if(!TAPTaskTable)
    TAPTaskTable = (tTMSTAPTaskTable*)TryResolve("_tapTask");

  if(!_curTapTask)
    _curTapTask = (dword*)TryResolve("_curTapTask");

  if(!TAPTaskTable || !_curTapTask)
  {
    if(CurrentDir) CurrentDir[0] = '\0';
    return -3;
  }

  //CurrentDir points to a struct, where the second dword points to NULL terminated string
  dw = (dword*)TAPTaskTable[*_curTapTask].CurrentDir;

  //Remove the systems mount point /mnt/hd from the directory
  if(CurrentDir && dw && dw[1])
    strcpy(CurrentDir, (char*)(dw[1] + 7));

  return 0;

#else
  return HDD_TranslateDirCluster((dword)HDD_TAP_GetCurrentDirCluster(), CurrentDir);
#endif
}
