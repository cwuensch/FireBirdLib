#include "tap.h"

byte _Border_Items_W_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x2F, 0xCB, 0x1F, 0xFF, 0xFF, 0x02, 0x68, 
  0x00, 0x12, 0x44, 0x4A, 0x89, 0xFF, 0x91, 0xF6, 0x13, 0x22, 0xDF, 0x40, 0x99, 0x00, 0x44, 0x42, 
  0x44, 0xC2, 0x78, 0x90, 0x17, 0x74, 0x0C, 0x8B, 0x72, 0x9F, 0xF6, 0x48, 0x00, 0x6F, 0x2A, 0x82, 
  0x37, 0x9E, 0xBF, 0x9B, 0x84, 0x25, 0xA5, 0xFD, 0x60, 
};

TYPE_GrData _Border_Items_W_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Border_Items_W_Cpm,            //data
   616,                           //size
    14,                           //width
    22                            //height
};

