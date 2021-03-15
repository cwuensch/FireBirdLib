#include "tap.h"

static byte _Keyb_ScrollRight_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x2F, 0x2C, 0x7F, 0xFF, 0xFF, 0x01, 0x20, 
  0x00, 0x14, 0x42, 0x52, 0x4E, 0x4A, 0x77, 0x0C, 0x6E, 0x52, 0x63, 0xD0, 0xC8, 0x48, 0x41, 0xF2, 
  0x19, 0xC8, 0x34, 0xB0, 0xC0, 0x21, 0xB0, 0x05, 0xD7, 0xE7, 0x8E, 0xD7, 0x87, 0x4B, 0x27, 0x2B, 
  0x47, 0xC5, 0xB3, 0xED, 0xCC, 0xFC, 0xEF, 0xEB, 0xA0, 
};

TYPE_GrData _Keyb_ScrollRight_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Keyb_ScrollRight_Cpm,    
   288,                           //size
     6,                           //width
    12                            //height
};
