#include "FBLib_tap.h"

dword HDD_TAP_GetIDByIndex(int TAPIndex)
{
#ifdef _TMS_

  tTMSTAPTaskTable     *TMSTAPTaskTable;
  char                  AbsFileName[100];
  tTAPInfo              pTAPInfo;

  if ((TAPIndex < 0) || (TAPIndex >= TAP_MAX)) return 0;

  TMSTAPTaskTable = (tTMSTAPTaskTable*)FIS_vTAPTable();
  if(TMSTAPTaskTable == NULL) return 0;

  if(!HDD_GetAbsolutePathByTypeFile(TMSTAPTaskTable[TAPIndex].file, AbsFileName)) return 0;

  if(!HDD_TAP_GetInfoByAbsPath(AbsFileName, &pTAPInfo)) return 0;

  return pTAPInfo.TAPID;

#else

  dword                 LoadAddress;

  if ((TAPIndex < 0) || (TAPIndex >= TAP_MAX)) return 0;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return 0;

  LoadAddress = *(dword *) (TAP_TableAddress + (TAPIndex << 5) + 12);
  if (LoadAddress == 0) return 0;

  return *(dword*)(LoadAddress + 0x0020);

#endif

}
