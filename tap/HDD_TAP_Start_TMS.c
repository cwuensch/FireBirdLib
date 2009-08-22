#include <string.h>
#include "FBLib_tap.h"

#ifdef _TMS_

dword HDD_TAP_Start(char *TAPFileName, bool BatchMode, void* ParameterBlock)
{
  dword                 ret;
  dword                 _TempWorkFolder[4];
  dword                *_hddTapFolder;
  char                  CurrentDir[FBLIB_DIR_SIZE];

  void  (*ApplHdd_SetWorkFolder)(void*);
  dword (*ApplHdd_SelectFolder)(void*, char  const*);
  void  (*Appl_ExecProgram)(char*);

  (void)BatchMode;
  (void)ParameterBlock;

  Appl_ExecProgram      = (void*)TryResolve("_Z16Appl_ExecProgramPc");
  ApplHdd_SetWorkFolder = (void*)TryResolve("_Z21ApplHdd_SetWorkFolderPv");
  ApplHdd_SelectFolder  = (void*)TryResolve("_Z20ApplHdd_SelectFolderPvPKc");
  _hddTapFolder         = (dword*)TryResolve("_hddTapFolder");

  //"Calculate" the current absolute directory of the new TAP
  TAP_SPrint(CurrentDir, "mnt/hd");
  HDD_TAP_GetCurrentDir(&CurrentDir[strlen(CurrentDir)]);

  //Create a new folder structure
  memset(_TempWorkFolder, 0, sizeof(_TempWorkFolder));
  _TempWorkFolder[0] = 0xbacaed31;
  ret = ApplHdd_SelectFolder(&_TempWorkFolder, CurrentDir);
  if(!ret)
  {
    ApplHdd_SetWorkFolder(_TempWorkFolder);
    memcpy((void*)_hddTapFolder[0], &_TempWorkFolder[0], sizeof(_TempWorkFolder));
    Appl_ExecProgram(TAPFileName);
  }

  return 1;
}

#endif
