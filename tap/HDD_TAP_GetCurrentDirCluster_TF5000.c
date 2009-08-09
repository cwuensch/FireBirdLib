#include "FBLib_tap.h"

#ifndef _TMS_

int HDD_TAP_GetCurrentDirCluster (void)
{
  tTAPTableInfo         pTAPInfo;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return -1;

  //Get some information about ourselve
  HDD_TAP_GetInfo (TAP_TableIndex, &pTAPInfo);

  return pTAPInfo.LoadAddress ? *(int*)(pTAPInfo.pDotDirStructure + 8) : -1;
}

#endif
