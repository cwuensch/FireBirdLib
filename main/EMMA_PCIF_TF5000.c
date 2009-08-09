#include "tap.h"

#ifndef _TMS_

volatile dword *EMMA_PCIF1_RST               = (dword *) 0xb2009000;
volatile dword *EMMA_PCIF1_PCI_Int           = (dword *) 0xb2009010;
volatile dword *EMMA_PCIF1_IntEn             = (dword *) 0xb2009014;
volatile dword *EMMA_PCIF1_IntSta            = (dword *) 0xb2009018;
volatile dword *EMMA_PCIF1_IntEx             = (dword *) 0xb2009020;
volatile dword *EMMA_PCIF1_IntExen           = (dword *) 0xb2009024;
volatile dword *EMMA_PCIF1_Arben             = (dword *) 0xb2009030;
volatile dword *EMMA_PCIF1_Pdar_intreg       = (dword *) 0xb2009040;
volatile dword *EMMA_PCIF1_Pdar_brg          = (dword *) 0xb2009044;
volatile dword *EMMA_PCIF1_Pdar_PCIw0        = (dword *) 0xb2009048;
volatile dword *EMMA_PCIF1_Pdar_PCIw1        = (dword *) 0xb200904c;
volatile dword *EMMA_PCIF1_DMA_eadr          = (dword *) 0xb2009050;
volatile dword *EMMA_PCIF1_CBI_eadr          = (dword *) 0xb2009054;
volatile dword *EMMA_PCIF1_ArbCtrl           = (dword *) 0xb2009060;
volatile dword *EMMA_PCIF1_Tendian           = (dword *) 0xb2009070;
volatile dword *EMMA_PCIF1_DMACtrl           = (dword *) 0xb2009080;
volatile dword *EMMA_PCIF1_Stadr             = (dword *) 0xb2009084;
volatile dword *EMMA_PCIF1_Ctadr             = (dword *) 0xb2009088;
volatile dword *EMMA_PCIF1_Etadr             = (dword *) 0xb200908c;
volatile dword *EMMA_PCIF1_DMAsta            = (dword *) 0xb2009090;
volatile dword *EMMA_PCIF1_Brgctrl           = (dword *) 0xb20090a0;

volatile dword *EMMA_PCIF2_Err               = (dword *) 0xb200915c;
volatile dword *EMMA_PCIF2_Ctrl_L            = (dword *) 0xb2009184;
volatile dword *EMMA_PCIF2_Ctrl_H            = (dword *) 0xb2009188;
volatile dword *EMMA_PCIF2_Arb_L             = (dword *) 0xb200918c;
volatile dword *EMMA_PCIF2_Arb_H             = (dword *) 0xb2009190;
volatile dword *EMMA_PCIF2_Init0             = (dword *) 0xb2009194;
volatile dword *EMMA_PCIF2_Init1             = (dword *) 0xb200919c;
volatile dword *EMMA_PCIF2_Vid_Did           = (dword *) 0xb20092a4;
volatile dword *EMMA_PCIF2_Cmd_Sts           = (dword *) 0xb20092a8;
volatile dword *EMMA_PCIF2_Revid_Class       = (dword *) 0xb20092ac;
volatile dword *EMMA_PCIF2_Clsiz_Mltim_htype = (dword *) 0xb20092b0;
volatile dword *EMMA_PCIF2_Barc              = (dword *) 0xb20092b4;
volatile dword *EMMA_PCIF2_Ssvid_Ssid        = (dword *) 0xb20092d0;
volatile dword *EMMA_PCIF2_Intlin_Intpin     = (dword *) 0xb20092e0;
volatile dword *EMMA_PCIF2_Bar0              = (dword *) 0xb20092e4;
volatile dword *EMMA_PCIF2_Swp               = (dword *) 0xb2009354;

#endif
