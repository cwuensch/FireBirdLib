#include "tap.h"

#ifndef _TMS_

//DALP = Alpha control
volatile  word *EMMA_DALP_ALPHA1    = ( word *) 0xb0004200;
volatile  word *EMMA_DALP_ALPHA2    = ( word *) 0xb0004202;
volatile  word *EMMA_DALP_ALPHA3    = ( word *) 0xb0004204;
volatile  word *EMMA_DALP_ALPHA4    = ( word *) 0xb0004206;
volatile  word *EMMA_DALP_ALPHA5    = ( word *) 0xb0004208;
volatile  word *EMMA_DALP_ALPHA6    = ( word *) 0xb000420a;
volatile dword *EMMA_DALP_ALPHA_CTR = (dword *) 0xb000420c;
volatile dword *EMMA_DALP_BCKGND1   = (dword *) 0xb0004210;
volatile dword *EMMA_DALP_BORDER1   = (dword *) 0xb0004214;
volatile dword *EMMA_DALP_BCKGND2   = (dword *) 0xb0004218;
volatile dword *EMMA_DALP_BORDER2   = (dword *) 0xb000421c;
volatile dword *EMMA_DALP_FBLANK    = (dword *) 0xb0004220;
volatile dword *EMMA_DALP_ALPHALMT0 = (dword *) 0xb0004224;
volatile dword *EMMA_DALP_ALPHALMT1 = (dword *) 0xb0004228;
volatile dword *EMMA_DALP_ALPHALMT2 = (dword *) 0xb000422c;

#endif
