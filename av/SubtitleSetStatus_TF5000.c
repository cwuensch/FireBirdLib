#include                "../libFireBird.h"

#ifndef _TMS_


// adapted from bdb's exTAP library
void SubtitleSetStatus(bool enable)
{
  dword                 addr;
  byte                  *petc_subt;

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("SubtitleSetStatus");
#endif

  if (!(addr = GetEEPROMAddress()))
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  // offset +2 to type_etc_structure due to initial CRC in EEPROM
  petc_subt = (byte *) (addr + 0x0f);

  if ((enable && (*petc_subt & 0x10)) || (!enable && ((*petc_subt & 0x10) == 0)))
  {
    *petc_subt ^= 0x10;
    TAP_WriteSystemVar();
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif

}

#endif
