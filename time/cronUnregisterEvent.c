#include                "FBLib_time.h"

extern int                  cronItemCount;
extern TYPE_CRONTAB         cronTable[MAX_CRON_EVENTS];
extern bool                 cronInit;

bool cronUnregisterEvent(int Index)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("cronUnregisterEvent");
  #endif

  bool                  ret = FALSE;

  if(!cronInit) cronUnregisterAllEvents();

  if((cronItemCount > 0) && (Index >= 0) && (Index < MAX_CRON_EVENTS))
  {
    if(cronTable[Index].active)
    {
      cronTable[Index].active = FALSE;
      cronItemCount--;
      ret = TRUE;
    }
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
