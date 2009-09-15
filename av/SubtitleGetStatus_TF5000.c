#include                "../libFireBird.h"

#ifndef _TMS_

// adapted from bdb's exTAP library
int SubtitleGetStatus(void)
{
  dword                 addr;
  int                   ret;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("SubtitleGetStatus");
#endif

  if (!(addr = GetEEPROMAddress()))
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return -1;
  }

  // offset +2 to type_etc_structure due to initial CRC in EEPROM
  ret = (*(byte *) (addr + 0x0f) & 0x10 ? 0 : 1);

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

  return ret;
}

#endif
