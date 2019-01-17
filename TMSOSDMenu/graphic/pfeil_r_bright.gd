#include "tap.h"

byte _pfeil_r_bright_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x44, 0x56, 0x76, 0xFF, 0xFF, 0x02, 0x58, 
  0x00, 0x1A, 0x44, 0x4E, 0x89, 0x51, 0xAC, 0x35, 0xB1, 0xD6, 0xC0, 0xA8, 0x8B, 0x90, 0x10, 0x3C, 
  0x04, 0x04, 0x04, 0x07, 0xB9, 0xF0, 0x1C, 0x0B, 0x80, 0x6E, 0x08, 0x00, 0x32, 0x37, 0xDE, 0x6F, 
  0xC9, 0xBD, 0x56, 0x28, 0xE4, 0xB0, 0x3C, 0x96, 0xC3, 0xC1, 0x6E, 0x3B, 0x97, 0x03, 0xB1, 0x72, 
  0x38, 0x2C, 0x8E, 0xA5, 0xFF, 0x8F, 0xCF, 0xDF, 0x92, 0x3E, 0xE6, 0xF9, 0xA2, 0xF0, 
};

TYPE_GrData _pfeil_r_bright_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _pfeil_r_bright_Cpm,            //data
   600,                           //size
    10,                           //width
    15                            //height
};

