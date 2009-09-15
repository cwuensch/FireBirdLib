#include                "../libFireBird.h"

#ifndef _TMS_

// adapted from bdb's exTAP library
//
//this will return the current interactive setting, 0=off, 1=on, -1=error
//
int InteractiveGetStatus(void)
{
  dword                 addr;
  int                   ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("InteractiveGetStatus");
#endif

  if (!(addr = GetEEPROMAddress()))
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return -1;
  }

  // offset +2 to type_etc_structure due to initial CRC in EEPROM
  ret = (*(byte *) (addr + 0x1e) & 0x20 ? 0 : 1);

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

  return ret;
}

#endif
