#include "FBLib_tap.h"


void HDD_TAP_Terminate(dword TAPID)
{
#ifdef _TMS_

  int                   TAPIndex;
  tTMSTAPTaskTable     *TMSTAPTaskTable;

  //Return if that ID is not in use
  TAPIndex = HDD_TAP_GetIndexByID(TAPID);
  if (TAPIndex < 0) return;

  TMSTAPTaskTable = (tTMSTAPTaskTable*)FIS_vTAPTable();
  if(!TMSTAPTaskTable) return;

  //Be nice and send a stop event to the target TAP
  HDD_TAP_SendEvent(TAPID, FALSE, EVT_STOP, 1, 0);

  TMSTAPTaskTable[TAPIndex].Status = 2;

#else

  int                   TAPIndex;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return;

  //Return if that ID is not in use
  TAPIndex = HDD_TAP_GetIndexByID (TAPID);
  if (TAPIndex < 0) return;

  if (*(dword *)(TAP_TableAddress + (TAPIndex << 5) + 12) == 0) return;

  *(char*)(TAP_TableAddress + (TAPIndex << 5) + 28) |= 0x01;

#endif
}
