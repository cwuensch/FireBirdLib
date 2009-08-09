#include "FBLib_flash.h"

#ifdef _TMS_

TYPE_SatInfoSTMS *FlashGetSatelliteByIndex(byte SatIdx)
{
  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0 || SystemType != ST_DVBSTMS)) return NULL;

  return (TYPE_SatInfoSTMS *) (FlashBlockOffset[Satellites] + 4 + SatIdx * sizeof(TYPE_SatInfoSTMS));
}

#endif
