#include "tap.h"

byte _Button_select_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0xA0, 0x56, 0x37, 0xFF, 0xFF, 0x03, 0xC0, 
  0x00, 0x6B, 0x53, 0x53, 0x8D, 0xA9, 0x97, 0xF8, 0x78, 0x47, 0x81, 0x8F, 0x03, 0x1E, 0x02, 0x68, 
  0x7D, 0xF0, 0x11, 0x10, 0x10, 0x30, 0x14, 0x0C, 0x0E, 0x05, 0x0F, 0x00, 0x80, 0xCB, 0x10, 0x10, 
  0x50, 0x3C, 0x0C, 0x06, 0xE0, 0x26, 0x13, 0x1D, 0x65, 0x02, 0xCB, 0x3E, 0x7C, 0xC2, 0x31, 0x03, 
  0x46, 0x20, 0x31, 0x9E, 0x13, 0x1B, 0x08, 0x48, 0x0D, 0x82, 0x80, 0x61, 0xBB, 0xE4, 0x00, 0x42, 
  0x7B, 0x5A, 0x21, 0xEF, 0xB1, 0xA2, 0x1E, 0xD9, 0xB4, 0x43, 0xD7, 0x16, 0x88, 0x7A, 0x5E, 0xD1, 
  0x0F, 0x3E, 0x0B, 0x41, 0xC9, 0x9D, 0x22, 0x1B, 0xEB, 0x4A, 0x0E, 0x83, 0x97, 0x4C, 0xE2, 0x1B, 
  0xAA, 0xE3, 0xBE, 0x74, 0x43, 0x83, 0xB4, 0xD7, 0x2A, 0xEA, 0x90, 0xF9, 0x02, 0x87, 0xD1, 0x18, 
  0x9F, 0x6E, 0x4A, 0x6A, 0x9F, 0x34, 0x6D, 0xCA, 0x87, 0xFA, 0xF3, 0xEA, 0x7E, 0xBC, 0xFF, 0x43, 
  0xE4, 0x2A, 0xE9, 0xF2, 0x7C, 0x47, 0x4C, 0xF5, 0x3F, 0xC5, 0xFC, 0xF7, 0x9F, 0xD3, 0xDE, 0x7F, 
  0x8F, 0x00, 0x79, 0xD9, 0xCB, 0xDC, 0xF3, 0x8F, 0xF1, 0xE0, 
};

TYPE_GrData _Button_select_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_select_Cpm,             //data
   960,                           //size
    24,                           //width
    20                            //height
};
