#ifndef FBLIB_FLASH_H
#define FBLIB_FLASH_H

#include "../libFireBird.h"

#define TIMER_NAME      "FireBirdLib.rec"
#define TIMER_DATE      0xffff0000          //22.04.2038 00:00
#define MAXFAVS         30

#ifdef _TMS_
  #define MAXSAT        255
#else
  #define MAXSAT        75
#endif

extern bool         LibInitialized;
extern dword        FlashBlockOffset[BLOCKS + 1];
extern dword        FlashOffset;
extern SYSTEM_TYPE  SystemType;

#endif
