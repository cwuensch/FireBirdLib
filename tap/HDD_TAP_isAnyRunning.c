#include "FBLib_tap.h"

bool HDD_TAP_isAnyRunning(void)
{
#ifdef _TMS_

  dword                 i;
  tTMSTAPTaskTable     *TMSTAPTaskTable;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  TMSTAPTaskTable = (tTMSTAPTaskTable*)FIS_vTAPTable();
  if(!TMSTAPTaskTable) return FALSE;

  for (i = 0; i < TAP_MAX; i++)
  {
    if ((TMSTAPTaskTable[i].Status != 0) && (i != TAP_TableIndex)) return TRUE;
  }

  return FALSE;

#else

  dword                 i, LoadAddress;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  //Use the $gp value (2nd dword in the the TAP table) instead of the TAP ID as this value is always available
  for (i = 0; i < TAP_MAX; i++)
  {
    LoadAddress = *(dword *) (TAP_TableAddress + (i << 5) + 12);
    if ((LoadAddress != 0) && (i != TAP_TableIndex)) return TRUE;
  }
  return FALSE;

#endif

}
