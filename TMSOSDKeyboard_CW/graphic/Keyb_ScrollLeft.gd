#include "tap.h"

static byte _Keyb_ScrollLeft_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x30, 0xB5, 0x93, 0xFF, 0xFF, 0x01, 0x20, 
  0x00, 0x14, 0x43, 0x4D, 0x89, 0xC8, 0xD7, 0xD1, 0x8B, 0x54, 0x98, 0x24, 0x04, 0x06, 0x4D, 0xE0, 
  0x60, 0x3A, 0x58, 0xA0, 0x1B, 0x17, 0xB7, 0x24, 0xB3, 0xE3, 0xA7, 0x63, 0x87, 0x83, 0x67, 0xA3, 
  0x3D, 0xEF, 0xBC, 0xE7, 0xC8, 0x79, 0x3F, 0x2D, 0xEF, 0x00, 
};

TYPE_GrData _Keyb_ScrollLeft_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Keyb_ScrollLeft_Cpm,     
   288,                           //size
     6,                           //width
    12                            //height
};

