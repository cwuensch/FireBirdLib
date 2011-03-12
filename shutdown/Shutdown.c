#include "FBLib_shutdown.h"
#include "../libFireBird.h"

bool Shutdown(TaskEnum Task)
{
  void (*Appl_EvtProc_PowerOff)(unsigned int, unsigned int);

  Appl_EvtProc_PowerOff = (void*)FIS_fwPowerOff();
  if(!Appl_EvtProc_PowerOff) return FALSE;

  Appl_EvtProc_PowerOff(Task, 0);

  return TRUE;
}
