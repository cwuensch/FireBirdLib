#include "tap.h"

#ifndef _TMS_

//BHIF = Host Interface
volatile dword *EMMA_BHIF_Version       = (dword *) 0xb0000000;
volatile dword *EMMA_BHIF_Strap_1       = (dword *) 0xb0000010;
volatile dword *EMMA_BHIF_Strap_2       = (dword *) 0xb0000014;
volatile dword *EMMA_BHIF_Strap_Write_1 = (dword *) 0xb0000020;
volatile dword *EMMA_BHIF_Strap_Write_2 = (dword *) 0xb0000024;
volatile dword *EMMA_BHIF_Int_St_1      = (dword *) 0xb0000030;
volatile dword *EMMA_BHIF_Int_St_2      = (dword *) 0xb0000034;
volatile dword *EMMA_BHIF_Int_Enable_1  = (dword *) 0xb0000040;
volatile dword *EMMA_BHIF_Int_Enable_2  = (dword *) 0xb0000044;
volatile dword *EMMA_BHIF_NMI_St        = (dword *) 0xb0000050;
volatile dword *EMMA_BHIF_NMI_Enable    = (dword *) 0xb0000060;
volatile dword *EMMA_BHIF_Bus_Priority  = (dword *) 0xb0000070;
volatile dword *EMMA_BHIF_BErr_CLR      = (dword *) 0xb0000080;
volatile dword *EMMA_BHIF_BErr_RLS      = (dword *) 0xb0000084;
volatile dword *EMMA_BHIF_BErr_CAUSE    = (dword *) 0xb0000090;
volatile dword *EMMA_BHIF_BErr_ADR      = (dword *) 0xb00000a0;
volatile dword *EMMA_BHIF_BErr_RW       = (dword *) 0xb00000b0;
volatile dword *EMMA_BHIF_BErr_TARGET   = (dword *) 0xb00000b4;
volatile dword *EMMA_BHIF_BErr_CPUMSK   = (dword *) 0xb00000c0;
volatile dword *EMMA_BHIF_BERR_CMTRG    = (dword *) 0xb00000c4;
volatile dword *EMMA_BHIF_CLK_SEL_1     = (dword *) 0xb0000100;
volatile dword *EMMA_BHIF_CLK_SEL_2     = (dword *) 0xb0000104;
volatile dword *EMMA_BHIF_CLK_SEL_3     = (dword *) 0xb0000108;
volatile dword *EMMA_BHIF_CLK_MSK       = (dword *) 0xb0000110;
volatile dword *EMMA_BHIF_CLK_MCLKDIV   = (dword *) 0xb0000120;
volatile dword *EMMA_BHIF_CLK_MCLKRST   = (dword *) 0xb0000130;

#endif
