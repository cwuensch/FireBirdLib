#include "tap.h"

byte _Button_select_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0xD8, 0xD5, 0x5A, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0x9B, 0x52, 0x71, 0xC3, 0x54, 0xAA, 0xCF, 0x02, 0x5D, 0x6C, 0x08, 0x8A, 0xAA, 0xCC, 0xDC, 
  0x03, 0x72, 0x39, 0x5C, 0x50, 0xE5, 0x72, 0x39, 0x5C, 0x8F, 0x0D, 0x6E, 0x05, 0xC7, 0xF7, 0xC1, 
  0x7B, 0x03, 0x82, 0xC0, 0xC0, 0xC0, 0xA1, 0xE4, 0x2D, 0x97, 0x00, 0x2C, 0x76, 0x1F, 0x07, 0xB2, 
  0x84, 0x2C, 0x86, 0xE1, 0x9C, 0xEF, 0xCC, 0x71, 0xC5, 0x3F, 0xD7, 0x3C, 0x73, 0x0C, 0x30, 0x46, 
  0xD0, 0xFD, 0xF7, 0xDE, 0x8D, 0xA1, 0xFB, 0xAE, 0xB9, 0x1B, 0x43, 0xF6, 0xDB, 0x6A, 0x36, 0x87, 
  0xEC, 0xB2, 0xC4, 0x6D, 0x0F, 0xD7, 0x5D, 0x68, 0xBB, 0xDB, 0xAF, 0x4D, 0xBB, 0xF4, 0xA1, 0xFA, 
  0xAA, 0xA9, 0x35, 0xA0, 0xB2, 0xAF, 0x0F, 0x3A, 0x1F, 0xE7, 0x4D, 0x28, 0xEB, 0xAE, 0xFA, 0xAA, 
  0x0E, 0x5F, 0x98, 0xF9, 0x50, 0xB8, 0x7E, 0x9E, 0x5C, 0xB7, 0x37, 0xA9, 0xFD, 0x11, 0x85, 0xC3, 
  0xF4, 0x51, 0x46, 0xE6, 0xD6, 0x7F, 0x34, 0x61, 0x70, 0xFF, 0x19, 0xE7, 0x67, 0x9F, 0x85, 0xC3, 
  0xF3, 0xCD, 0x33, 0x3E, 0x7F, 0x0B, 0x87, 0xE6, 0x96, 0x5F, 0x7A, 0x3C, 0x85, 0xAF, 0x0F, 0xCD, 
  0x0B, 0x87, 0xE4, 0x92, 0x4D, 0xB4, 0xEA, 0x1F, 0xAF, 0x7E, 0x74, 0x2E, 0x1F, 0x8E, 0x38, 0xF7, 
  0xD5, 0xFD, 0xA1, 0x70, 0xFC, 0x51, 0x44, 0xC3, 0xE1, 0x70, 0xFC, 0x30, 0xC2, 0xC3, 0xE1, 0x70, 
  0xFB, 0xEF, 0xBE, 0xC3, 0xE1, 0x75, 0x7F, 0x61, 0xC1, 0x04, 0x09, 0xC1, 0xE7, 0xBF, 0x50, 0x7A, 
  0x8D, 0x80, 
};

TYPE_GrData _Button_select_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_select_Cpm,             //data
  1920,                           //size
    24,                           //width
    20                            //height
};

