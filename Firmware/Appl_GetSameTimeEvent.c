#include                "../libFireBird.h"

void *Appl_GetSameTimeEvent(byte SatIndex, word NetID, word TSID, word ServiceID)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("Appl_GetSameTimeEvent");
  #endif

  void *(*__Appl_GetSameTimeEvent)(byte SatIndex, word NetID, word TSID, word ServiceID);
  void *ret = NULL;

  __Appl_GetSameTimeEvent = (void*)FIS_fwAppl_GetSameTimeEvent();
  if(__Appl_GetSameTimeEvent) ret = __Appl_GetSameTimeEvent(SatIndex, NetID, TSID, ServiceID);

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
