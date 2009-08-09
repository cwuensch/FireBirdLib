#include "tap.h"

#ifndef _TMS_

//DSNC = Sync generator control
volatile dword *EMMA_DSNC_CTLFLG       = (dword *) 0xb0004400;
volatile dword *EMMA_DSNC_RELOAD       = (dword *) 0xb0004404;
volatile dword *EMMA_DSNC_SYNC1_HTOT   = (dword *) 0xb0004408;
volatile dword *EMMA_DSNC_SYNC1_HSYNC  = (dword *) 0xb000440c;
volatile dword *EMMA_DSNC_SYNC1_VTOT   = (dword *) 0xb0004410;
volatile dword *EMMA_DSNC_SYNC1_VSYNC  = (dword *) 0xb0004414;
volatile dword *EMMA_DSNC_SYNC1_V2SYNC = (dword *) 0xb0004418;
volatile dword *EMMA_DSNC_SYNC1_HVOFF  = (dword *) 0xb000441c;
volatile dword *EMMA_DSNC_SYNC1_CTOFF  = (dword *) 0xb0004420;
volatile dword *EMMA_DSNC_SYNC1_HCUT1  = (dword *) 0xb0004424;
volatile dword *EMMA_DSNC_SYNC1_HCUT2  = (dword *) 0xb0004428;
volatile dword *EMMA_DSNC_SYNC2_HTOT   = (dword *) 0xb000442c;
volatile dword *EMMA_DSNC_SYNC2_HSYNC  = (dword *) 0xb0004430;
volatile dword *EMMA_DSNC_SYNC2_VTOT   = (dword *) 0xb0004434;
volatile dword *EMMA_DSNC_SYNC2_VSYNC  = (dword *) 0xb0004438;
volatile dword *EMMA_DSNC_SYNC2_V2SYNC = (dword *) 0xb000443c;
volatile dword *EMMA_DSNC_SYNC2_HVOFF  = (dword *) 0xb0004440;
volatile dword *EMMA_DSNC_SYNC2_CTOFF  = (dword *) 0xb0004444;
volatile dword *EMMA_DSNC_SYNC2_HCUT1  = (dword *) 0xb0004448;
volatile dword *EMMA_DSNC_SYNC2_HCUT2  = (dword *) 0xb000444c;
volatile dword *EMMA_DSNC_SYNC_EXTRST  = (dword *) 0xb0004450;
volatile dword *EMMA_DSNC_SYNC3_HTOT   = (dword *) 0xb0004454;
volatile dword *EMMA_DSNC_SYNC3_HSYNC  = (dword *) 0xb0004458;
volatile dword *EMMA_DSNC_SYNC3_VTOT   = (dword *) 0xb000445c;
volatile dword *EMMA_DSNC_SYNC3_VSYNC  = (dword *) 0xb0004460;
volatile dword *EMMA_DSNC_SYNC3_V2SYNC = (dword *) 0xb0004464;
volatile dword *EMMA_DSNC_VALID_TVC    = (dword *) 0xb0004468;
volatile dword *EMMA_DSNC_VALID_BVC    = (dword *) 0xb000446c;
volatile dword *EMMA_DSNC_VALID_HC     = (dword *) 0xb0004470;
volatile dword *EMMA_DSNC_SYNC1_VC12   = (dword *) 0xb0004474;
volatile dword *EMMA_DSNC_SYNC1_VC34   = (dword *) 0xb0004478;
volatile dword *EMMA_DSNC_SYNC2_VC12   = (dword *) 0xb000447c;
volatile dword *EMMA_DSNC_SYNC2_VC34   = (dword *) 0xb0004480;
volatile dword *EMMA_DSNC_SYNC3_VC12   = (dword *) 0xb0004484;
volatile dword *EMMA_DSNC_SYNC3_VC34   = (dword *) 0xb0004488;

#endif
