#ifndef FBLIB_MAIN_H
#define FBLIB_MAIN_H

#include "tap.h"
#include "../libFireBird.h"

#define DEFAULTMAGIC    0xFB1BB100

#ifdef _TMS_
  #define FIRMWAREDAT   "FirmwareTMS.dat"
#else
  #define FIRMWAREDAT   "Firmware.dat"
#endif

typedef struct
{
 dword                  SubCommand;
 dword                  P1;
 dword                  P2;
 dword                  P3;
} tBIOSType;

extern bool             LibInitialized;
extern int              _appl_version;
extern dword            CallLevel;
extern bool             CallTraceEnabled;

#endif
