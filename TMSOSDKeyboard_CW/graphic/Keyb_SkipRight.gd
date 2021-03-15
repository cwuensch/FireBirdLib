#include "tap.h"

static byte _Keyb_SkipRight_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x45, 0xD4, 0x30, 0xFF, 0xFF, 0x03, 0x10, 
  0x00, 0x19, 0x43, 0x4F, 0x4A, 0xCC, 0xF2, 0xD5, 0xCB, 0x2F, 0x05, 0xDA, 0xCE, 0xCC, 0x04, 0x04, 
  0x05, 0xB2, 0x80, 0x90, 0x81, 0x00, 0x80, 0x91, 0x19, 0x70, 0x1B, 0x6C, 0x00, 0x19, 0x92, 0x40, 
  0x39, 0x71, 0xB6, 0x01, 0x21, 0x5B, 0x5B, 0xFE, 0xB7, 0xCB, 0xEE, 0xBE, 0xDB, 0xEA, 0xFA, 0x6E, 
  0x17, 0xCB, 0x72, 0xBB, 0x6F, 0x7F, 0xE5, 0xF5, 0xC9, 0xF5, 0xE2, 0xF9, 0xF4, 0xFC, 0x40, 
};

static TYPE_GrData _Keyb_SkipRight_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Keyb_SkipRight_Cpm,      
   784,                           //size
    14,                           //width
    14                            //height
};
