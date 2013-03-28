#include                "../libFireBird.h"

dword ApplHdd_SelectFolder(tDirEntry *FolderStruct, const char *FolderPath)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("ApplHdd_SelectFolder");
  #endif

  dword                 (*__ApplHdd_SelectFolder)(tDirEntry *FolderStruct, const char *FolderPath);
  dword                 ret = 0;

  __ApplHdd_SelectFolder = (void*)FIS_fwApplHdd_SelectFolder();
  if(__ApplHdd_SelectFolder) ret = __ApplHdd_SelectFolder(FolderStruct, FolderPath);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
