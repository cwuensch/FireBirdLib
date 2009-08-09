#include <string.h>
#include "FBLib_tap.h"

#ifdef _TMS_

dword HDD_TAP_Start(char *TAPFileName, bool BatchMode, void* ParameterBlock)
{
  dword                *tempWorkFolder;
  dword                 ret;
  dword                _ownWorkFolder[4];
  char                  CurrentDir[FBLIB_DIR_SIZE];

  void* (*ApplHdd_GetWorkFolder)(void);
  void  (*ApplHdd_SetWorkFolder)(void*);
  dword (*ApplHdd_SelectFolder)(void*, char  const*);
  void  (*Appl_ExecProgram)(char*);

  (void)BatchMode;
  (void)ParameterBlock;

  Appl_ExecProgram = (void*)TryResolve("_Z16Appl_ExecProgramPc");
  ApplHdd_GetWorkFolder = (void*)TryResolve("_Z21ApplHdd_GetWorkFolderv");
  ApplHdd_SetWorkFolder = (void*)TryResolve("_Z21ApplHdd_SetWorkFolderPv");
  ApplHdd_SelectFolder  = (void*)TryResolve("_Z20ApplHdd_SelectFolderPvPKc");

  memset(_ownWorkFolder, 0, sizeof(_ownWorkFolder));
  _ownWorkFolder[0] = 0xbacaed31;
  tempWorkFolder = ApplHdd_GetWorkFolder();

  //"Calculate" the current absolute directory
  TAP_SPrint(CurrentDir, "mnt/hd");
  HDD_TAP_GetCurrentDir(&CurrentDir[strlen(CurrentDir)]);

  ret = ApplHdd_SelectFolder(&_ownWorkFolder, CurrentDir);
  if(!ret)
  {
    ApplHdd_SetWorkFolder(_ownWorkFolder);
    Appl_ExecProgram(TAPFileName);
  }
  ApplHdd_SetWorkFolder(tempWorkFolder);

  return 1;
}

#endif
