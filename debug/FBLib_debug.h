#ifndef FBLIB_DEBUG_H
#define FBLIB_DEBUG_H

#include "tap.h"
#include "../libFireBird.h"

#define DEFAULTMAGIC    0xFB1BB100

extern dword            CallLevel;
extern bool             CallTraceEnabled;
extern bool             CallTraceInitialized;

#endif
