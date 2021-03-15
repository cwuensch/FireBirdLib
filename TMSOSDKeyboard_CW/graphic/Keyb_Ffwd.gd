#include "tap.h"

static byte _Keyb_Ffwd_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x42, 0x72, 0xC8, 0xFF, 0xFF, 0x03, 0x10, 
  0x00, 0x19, 0x44, 0x4D, 0x81, 0x29, 0xB5, 0x8B, 0x56, 0x2C, 0xB8, 0x17, 0x74, 0x12, 0x02, 0x04, 
  0x05, 0xDD, 0x22, 0x20, 0x20, 0x40, 0x40, 0x40, 0x78, 0x0D, 0xB1, 0x40, 0x22, 0xC6, 0xF0, 0x97, 
  0xCD, 0xB9, 0x21, 0x6E, 0xF9, 0x5E, 0xDF, 0xD5, 0xE9, 0xFE, 0x5B, 0x3F, 0xEB, 0x57, 0x8B, 0xAF, 
  0x4F, 0xDE, 0x75, 0xF2, 0xA7, 0x96, 0xFC, 0xC2, 0xF3, 0x27, 0xEA, 0x00, 
};

static TYPE_GrData _Keyb_Ffwd_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Keyb_Ffwd_Cpm,           
   784,                           //size
    14,                           //width
    14                            //height
};
