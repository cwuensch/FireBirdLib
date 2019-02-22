#include "tap.h"

byte _Cursor_Dark_Normal_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x9B, 0x5E, 0x40, 0xFF, 0xFF, 0x36, 0xB0, 
  0x00, 0x8B, 0x5A, 0x75, 0xC0, 0x0C, 0x67, 0xF9, 0xD4, 0xD3, 0xD9, 0x18, 0x13, 0x0F, 0x49, 0x84, 
  0xC5, 0xFE, 0x03, 0x17, 0x5D, 0x4A, 0x7F, 0x7F, 0xFA, 0x29, 0x30, 0x14, 0x97, 0x57, 0x75, 0xD1, 
  0x81, 0x47, 0xEC, 0x01, 0x29, 0x81, 0x81, 0x81, 0x4A, 0x60, 0x52, 0x66, 0x78, 0x26, 0xC8, 0x78, 
  0x12, 0xD1, 0xDE, 0x03, 0xF7, 0x8B, 0x4F, 0xBB, 0xC5, 0xCF, 0x80, 0xBC, 0x77, 0xB1, 0xFA, 0xFC, 
  0xFB, 0x44, 0xFC, 0xF9, 0xE9, 0x94, 0xCE, 0x86, 0x79, 0x66, 0x67, 0x8C, 0x8C, 0xF0, 0xC4, 0xCE, 
  0xFC, 0x2C, 0xEE, 0xFC, 0x67, 0x6F, 0xCB, 0x3B, 0x2F, 0x33, 0xAE, 0xE3, 0x3A, 0xAD, 0xB3, 0x9E, 
  0xCB, 0x39, 0x2B, 0x33, 0xF7, 0x4D, 0x98, 0xE6, 0xB3, 0x4B, 0xD1, 0x9F, 0x69, 0x4C, 0xD0, 0x7F, 
  0xF8, 0x25, 0xB3, 0xF1, 0xEA, 0xCC, 0x33, 0x19, 0xAF, 0x39, 0x9B, 0x53, 0xD9, 0xBB, 0x45, 0x9B, 
  0xF0, 0x33, 0xF5, 0x51, 0x9C, 0x1E, 0xEC, 0xE2, 0xAA, 0xCE, 0x38, 0x59, 0x92, 0x26, 0x72, 0xC6, 
  0xCF, 0x5E, 0x8D, 0xBF, 0xE8, 
};

TYPE_GrData _Cursor_Dark_Normal_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Cursor_Dark_Normal_Cpm,        //data
  14000,                           //size
   100,                           //width
    35                            //height
};

