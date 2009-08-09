#include "tap.h"

#ifndef _TMS_

//DTCC = Display teletext and closed caption
volatile dword *EMMA_DTCC_TT_CC_CTR   = (dword *) 0xb0004300;
volatile dword *EMMA_DTCC_CC_DATA_CTR = (dword *) 0xb0004304;
volatile dword *EMMA_DTCC_TT_CC_FIELD = (dword *) 0xb0004308;

#endif
