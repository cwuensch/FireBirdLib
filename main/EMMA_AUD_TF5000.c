#include "tap.h"

#ifndef _TMS_

//AUD = Audio Interface
volatile dword *EMMA_AUD_DDB0      = (dword *) 0xb0007000;
volatile dword *EMMA_AUD_ASM       = (dword *) 0xb0007008;
volatile dword *EMMA_AUD_RAMADR    = (dword *) 0xb0007018;
volatile dword *EMMA_AUD_RAMDAT    = (dword *) 0xb000701c;
volatile dword *EMMA_AUD_DPUTSTA0  = (dword *) 0xb0007020;
volatile dword *EMMA_AUD_DPUTSTA1  = (dword *) 0xb0007024;
volatile dword *EMMA_AUD_DPUTSTA2  = (dword *) 0xb0007028;
volatile dword *EMMA_AUD_DPUTSDA0  = (dword *) 0xb000702c;
volatile dword *EMMA_AUD_DPUTSDA1  = (dword *) 0xb0007030;
volatile dword *EMMA_AUD_DPUTSDA2  = (dword *) 0xb0007034;
volatile dword *EMMA_AUD_SPUTSTA0  = (dword *) 0xb0007038;
volatile dword *EMMA_AUD_SPUTSTA1  = (dword *) 0xb000703c;
volatile dword *EMMA_AUD_SPUTSTA2  = (dword *) 0xb0007040;
volatile dword *EMMA_AUD_SPUTSDA0  = (dword *) 0xb0007044;
volatile dword *EMMA_AUD_SPUTSDA1  = (dword *) 0xb0007048;
volatile dword *EMMA_AUD_SPUTSDA2  = (dword *) 0xb000704c;
volatile dword *EMMA_AUD_TSEN      = (dword *) 0xb0007050;
volatile dword *EMMA_AUD_RST       = (dword *) 0xb0007100;
volatile dword *EMMA_AUD_INT       = (dword *) 0xb0007110;
volatile dword *EMMA_AUD_INTEN     = (dword *) 0xb0007114;
volatile dword *EMMA_AUD_INTSTA    = (dword *) 0xb0007118;
volatile dword *EMMA_AUD_SICTRL    = (dword *) 0xb0007120;
volatile dword *EMMA_AUD_ESIFORM   = (dword *) 0xb0007130;
volatile dword *EMMA_AUD_ESICTRL   = (dword *) 0xb0007134;
volatile dword *EMMA_AUD_b0007138  = (dword *) 0xb0007138;
volatile dword *EMMA_AUD_SPDCTRL   = (dword *) 0xb0007170;
volatile dword *EMMA_AUD_SPDCHSTA1 = (dword *) 0xb0007174;
volatile dword *EMMA_AUD_SPDCHSTA2 = (dword *) 0xb0007178;

#endif
