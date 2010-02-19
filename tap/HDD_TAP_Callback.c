#include "FBLib_tap.h"


dword HDD_TAP_Callback(dword TAPID, void *ProcedureAddress, dword param1, dword param2, dword param3, dword param4)
{
  dword                 Ret = 0;

#ifdef _TMS_

  dword                *curTapTask;
  dword                 OrigCurTapTask;

  dword (*Callback)(dword param1, dword param2, dword param3, dword param4) = NULL;

  if(TAPID)
  {
    curTapTask = (dword*)FIS_vcurTapTask();
    if(!curTapTask) return 0;

    int Index = HDD_TAP_GetIndexByID(TAPID);
    if(Index < 0 || Index >= TAP_MAX) return 0;

    Callback = ProcedureAddress;
    OrigCurTapTask = *curTapTask;
    *curTapTask = Index;
    Ret = Callback(param1, param2, param3, param4);
    *curTapTask = OrigCurTapTask;
  }

  return Ret;

#else

  if (!LibInitialized) InitTAPex();
  if (!LibInitialized) return 0;

  if(TAPID)
  {
    int Index = HDD_TAP_GetIndexByID (TAPID);
    if (Index >= 0 && Index < TAP_MAX) Ret = Callback (Index, ProcedureAddress, param1, param2, param3, param4);
  }

  return Ret;

#endif
}
