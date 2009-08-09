#include "FBLib_flash.h"

#ifdef _TMS_

TYPE_TpInfoSTMS *FlashGetTransponderSByIndex(word TpIdx, byte SatIdx)

#else

TYPE_TpInfoS *FlashGetTransponderSByIndex(word TpIdx, byte SatIdx)

#endif

{
  dword                 offset, tpCount;

#ifdef _TMS_
  TYPE_TpInfoSTMS       *transponder;
#else
  TYPE_TpInfoS          *transponder;
#endif

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized || (FlashOffset == 0 || ((SystemType != ST_DVBS) && (SystemType != ST_DVBSTMS)))) return NULL;

  offset = FlashBlockOffset[Transponders] + 4;
  tpCount = *(dword *) offset;

#ifdef _TMS_
  transponder = (TYPE_TpInfoSTMS *) (offset + 4);
#else
  transponder = (TYPE_TpInfoS *) (offset + 4);
#endif

  // search start of transponders for satellite
  while (tpCount)
  {
    if (transponder->SatIdx == SatIdx) break;

    transponder++;
    tpCount--;
  }

  if (tpCount == 0 || TpIdx >= tpCount) return NULL;
  else
  {
    transponder += TpIdx;
    return transponder;
  }
}
