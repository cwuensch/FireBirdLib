#include <string.h>
#include "FBLib_tap.h"

#ifdef _TMS_

dword HDD_TAP_Start(char *TAPFileName, bool BatchMode, void* ParameterBlock)
{
  dword                 ret;
  dword                 _TempWorkFolder[4];
  static dword          *_hddTapFolder = NULL;
  char                  CurrentDir[FBLIB_DIR_SIZE];

  static void  (*ApplHdd_SetWorkFolder)(void*);
  static dword (*ApplHdd_SelectFolder)(void*, char  const*);
  static void  (*Appl_ExecProgram)(char*);

  (void)BatchMode;
  (void)ParameterBlock;

  if(!Appl_ExecProgram)
    Appl_ExecProgram      = (void*)TryResolve("_Z16Appl_ExecProgramPc");

  if(!ApplHdd_SetWorkFolder)
    ApplHdd_SetWorkFolder = (void*)TryResolve("_Z21ApplHdd_SetWorkFolderPv");

  if(!ApplHdd_SelectFolder)
    ApplHdd_SelectFolder  = (void*)TryResolve("_Z20ApplHdd_SelectFolderPvPKc");

  if(!_hddTapFolder)
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
