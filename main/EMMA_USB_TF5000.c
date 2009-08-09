#include "tap.h"

#ifndef _TMS_

volatile  word *EMMA_USB_RegAddrPtr                               = ( word *) 0xbf400000;
volatile  word *EMMA_USB_RegData                                  = ( word *) 0xbf400002;
volatile  word *EMMA_USB_IRQStat0                                 = ( word *) 0xbf400004;
volatile  word *EMMA_USB_IRQStat1                                 = ( word *) 0xbf400006;
volatile  word *EMMA_USB_PageSel                                  = ( word *) 0xbf400008;
volatile  word *EMMA_USB_EP_Data                                  = ( word *) 0xbf40000a;
volatile  word *EMMA_USB_EP_Stat0                                 = ( word *) 0xbf40000c;
volatile  word *EMMA_USB_EP_Stat1                                 = ( word *) 0xbf40000e;
volatile  word *EMMA_USB_EP_Transfer0                             = ( word *) 0xbf400010;
volatile  word *EMMA_USB_EP_Transfer1                             = ( word *) 0xbf400012;
volatile  word *EMMA_USB_EP_Transfer2                             = ( word *) 0xbf400014;
volatile  word *EMMA_USB_EP_IRQEnb                                = ( word *) 0xbf400016;
volatile  word *EMMA_USB_EP_Avail0                                = ( word *) 0xbf400018;
volatile  word *EMMA_USB_EP_Avail1                                = ( word *) 0xbf40001a;
volatile  word *EMMA_USB_EP_RspClr                                = ( word *) 0xbf40001c;
volatile  word *EMMA_USB_EP_RspSet                                = ( word *) 0xbf40001e;
volatile  word *EMMA_USB_Reserved1                                = ( word *) 0xbf400020;
volatile  word *EMMA_USB_Reserved2                                = ( word *) 0xbf400022;
volatile  word *EMMA_USB_Reserved3                                = ( word *) 0xbf400024;
volatile  word *EMMA_USB_Reserved4                                = ( word *) 0xbf400026;
volatile  word *EMMA_USB_Reserved5                                = ( word *) 0xbf400028;
volatile  word *EMMA_USB_Reserved6                                = ( word *) 0xbf40002a;
volatile  word *EMMA_USB_Reserved7                                = ( word *) 0xbf40002c;
volatile  word *EMMA_USB_Reserved8                                = ( word *) 0xbf40002e;
volatile  word *EMMA_USB_USBCtl0                                  = ( word *) 0xbf400030;
volatile  word *EMMA_USB_USBCtl1                                  = ( word *) 0xbf400032;
volatile  word *EMMA_USB_Frame0                                   = ( word *) 0xbf400034;
volatile  word *EMMA_USB_Frame1                                   = ( word *) 0xbf400036;
volatile  word *EMMA_USB_DMAReq                                   = ( word *) 0xbf400038;
volatile  word *EMMA_USB_Scratch                                  = ( word *) 0xbf40003a;
volatile  word *EMMA_USB_Reserved9                                = ( word *) 0xbf40003c;
volatile  word *EMMA_USB_Reserved10                               = ( word *) 0xbf40003e;

#endif
