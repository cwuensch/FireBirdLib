#include "FBLib_main.h"

#ifndef _TMS_

bool EnqueueEvent (word Event, dword Parameter)
{
  if (!LibInitialized) InitTAPex();
  if (!LibInitialized) return FALSE;

  return (CallFirmware ((dword) EnqueueEventAddress, Event, Parameter, 0, 0) != 0);
}

#endif
