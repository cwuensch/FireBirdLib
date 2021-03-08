#include "tap.h"

static byte _Cursor_Dark_Small_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x72, 0x78, 0x67, 0xFF, 0xFF, 0x23, 0xF0, 
  0x00, 0x5E, 0x53, 0x51, 0xA0, 0x54, 0xBF, 0xCD, 0xB3, 0xC0, 0x08, 0x28, 0x54, 0x16, 0x09, 0x02, 
  0x0E, 0x05, 0xD9, 0x73, 0x5A, 0x0A, 0x02, 0x81, 0xB4, 0x03, 0x9C, 0x82, 0x80, 0xFD, 0x09, 0xB5, 
  0xB4, 0x24, 0x04, 0x14, 0x04, 0x0C, 0x35, 0xC1, 0x38, 0x5B, 0x81, 0x31, 0x17, 0x1D, 0x6D, 0xEE, 
  0x2E, 0xF8, 0x0B, 0xEF, 0xCD, 0x9F, 0x9F, 0xFF, 0x9E, 0x51, 0x33, 0x8B, 0x3E, 0x20, 0xCF, 0x7B, 
  0x99, 0xED, 0x63, 0x3D, 0x78, 0xB3, 0xD3, 0x73, 0x3C, 0xF6, 0xB3, 0x7D, 0x0C, 0xD7, 0xA1, 0x9C, 
  0xF9, 0x19, 0x92, 0x26, 0x66, 0x8D, 0x9A, 0x72, 0xB3, 0xAF, 0x33, 0x3B, 0xE5, 0x67, 0x84, 0xCC, 
  0xDB, 0xA5, 0x9B, 0xA7, 0x66, 0x15, 0x33, 0x86, 0xA6, 0x7D, 0xFA, 0x64, 
};

TYPE_GrData _Cursor_Dark_Small_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Cursor_Dark_Small_Cpm,         //data
  9200,                           //size
   100,                           //width
    23                            //height
};

