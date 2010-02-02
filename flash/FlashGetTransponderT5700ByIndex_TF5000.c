#include "FBLib_flash.h"

#ifndef _TMS_

TYPE_TpInfoT5700 *FlashGetTransponderT5700ByIndex (word TpIdx)
{
  dword                 offset;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0 || SystemType != ST_DVBT5700)) return NULL;

  offset = FlashBlockOffset[Transponders] + 4;

  // sanity check of the parameter
  if ((dword) TpIdx >= *(dword *) offset) return NULL;

  return (TYPE_TpInfoT5700 *) (offset + 4 + TpIdx * sizeof(TYPE_TpInfoT5700));
}

#endif
