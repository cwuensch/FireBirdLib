#include                "../libFireBird.h"

word ApplSvc_GetTpIdx(byte SatIdx, word NetworkID, word TSID)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("ApplSvc_GetTpIdx");
  #endif

  word (*__ApplSvc_GetTpIdx)(byte, word, word);
  word ret = 0xffff;

  __ApplSvc_GetTpIdx = (void*)FIS_fwApplSvc_GetTpIdx();
  if(__ApplSvc_GetTpIdx) ret = __ApplSvc_GetTpIdx(SatIdx, NetworkID, TSID);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
