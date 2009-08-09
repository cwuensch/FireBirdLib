#include "tap.h"

#ifndef _TMS_

//DGRP = Graphics processor control - OSD and cursor planes
volatile dword *EMMA_DGRP_OSD1CTR = (dword *) 0xb0004104;
volatile dword *EMMA_DGRP_OSD2CTR = (dword *) 0xb0004108;

#endif
