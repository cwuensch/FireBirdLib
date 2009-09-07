#include "FBLib_shutdown.h"
#include "../libFireBird.h"

bool Shutdown(TaskEnum Task)
{
#ifdef _TMS_

  void (*Appl_EvtProc_PowerOff)(unsigned int, unsigned int);

  Appl_EvtProc_PowerOff = (void*)FIS_fwPowerOff();
  if(!Appl_EvtProc_PowerOff) return FALSE;
  Appl_EvtProc_PowerOff(Task, 0);

#else

  dword          EventDispatcherAddress;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return FALSE;

  EventDispatcherAddress = FIS_fwEventDispatcher();

  //2008-10-05: Topfield has stripped down the event routines on the new (2008) TF6000ES firmware
  //which now only accepts key events. Try to inject the shutdown directly
  // SysID 2457 == Topfield TF6000PVR ES
  // SysID 1416 == Topfield TF5000PVR Masterpiece



  if (((SysID == 2457) || (SysID == 1416) || ((SysID == 416) && (ApplID >= 0x1500)) ) && EventDispatcherAddress)
  {
    CallFirmware (EventDispatcherAddress, Task, 0, 0, 0);
  }
  else
  {
    //2008-01-20: EnqueueEventA is a new routine. Lets try it again.
    CallFirmware ((dword)EnqueueEventAddress, Task, 0, 0, 0);
  }
#endif

  return TRUE;
}
