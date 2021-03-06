#include "tap.h"

static byte _ScrollBarInvisible_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x2C, 0x82, 0xA6, 0xFF, 0xFF, 0x5C, 0x00, 
  0x00, 0x60, 0x30, 0x48, 0x6D, 0x7F, 0x8D, 0xEB, 0x6A, 0x5C, 0xB0, 0x18, 0x0A, 0xAC, 0xAA, 0xAA, 
  0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 
  0xAA, 0xAA, 0xAA, 0xAA, 0xAF, 0x80, 
};

TYPE_GrData _ScrollBarInvisible_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _ScrollBarInvisible_Cpm,        //data
  23552,                           //size
    16,                           //width
   368                            //height
};

