#include "tap.h"

static byte _MessageBoxSelectedButtonBackground_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x13, 0x17, 0x6E, 0xFF, 0xFF, 0x27, 0x10, 
  0x00, 0xEA, 0x5A, 0x9A, 0xEE, 0x15, 0x9F, 0xF7, 0x3A, 0xB5, 0x25, 0x82, 0xC1, 0x6B, 0x3D, 0x38, 
  0x48, 0xE2, 0x44, 0x6B, 0x5A, 0x52, 0x48, 0xA3, 0x36, 0x6A, 0xD2, 0x93, 0x83, 0x1C, 0x1E, 0x21, 
  0xAD, 0x6D, 0xC3, 0xE4, 0xBC, 0x51, 0xE8, 0x65, 0x1A, 0x33, 0x5B, 0x56, 0x8E, 0x02, 0x65, 0x8A, 
  0xDC, 0x07, 0x02, 0x70, 0x29, 0xC0, 0x9C, 0x07, 0x0B, 0x84, 0xE0, 0xC5, 0x1F, 0x01, 0xFF, 0x7A, 
  0x6F, 0x8D, 0x0B, 0xDA, 0xBF, 0xEF, 0x8C, 0x3F, 0x90, 0x02, 0x77, 0x3F, 0x27, 0x02, 0xA3, 0x4A, 
  0x58, 0xDA, 0xFD, 0xE5, 0x2D, 0x57, 0xEE, 0x68, 0x5E, 0x94, 0xC0, 0xBF, 0xD4, 0xD2, 0xD4, 0x7E, 
  0x78, 0xC2, 0xDF, 0x12, 0x99, 0x79, 0x0B, 0x51, 0xF7, 0xE1, 0x11, 0xBF, 0x99, 0x25, 0x69, 0x8F, 
  0xED, 0x20, 0x6A, 0x7A, 0xEF, 0x32, 0xC8, 0x2B, 0x4E, 0xAF, 0xA3, 0x01, 0x5F, 0x3D, 0xB6, 0x56, 
  0x0A, 0xD3, 0xA3, 0xE5, 0xB2, 0x21, 0xF8, 0xAE, 0xCB, 0xB0, 0x56, 0x9C, 0xFF, 0x0D, 0x61, 0x9B, 
  0xDE, 0xB1, 0x51, 0xCE, 0xEE, 0x8E, 0x21, 0x76, 0x96, 0xAB, 0x99, 0x46, 0x20, 0x7D, 0x43, 0x4C, 
  0xA8, 0xBF, 0x9E, 0xA8, 0xC1, 0x95, 0x08, 0xA8, 0xBB, 0x93, 0x04, 0x38, 0x8D, 0x80, 0x54, 0x6D, 
  0x22, 0xDF, 0x8A, 0xCD, 0x0B, 0xA2, 0xA2, 0xDA, 0x1D, 0xC8, 0x6D, 0xA5, 0x78, 0x54, 0x6B, 0x55, 
  0xBB, 0x15, 0xDA, 0xF7, 0xC5, 0x45, 0xBA, 0xD7, 0xA1, 0xBE, 0xEB, 0xC2, 0xA3, 0x60, 0xC3, 0xB1, 
  0x5F, 0xC1, 0x84, 0x54, 0x6C, 0x77, 0xDE, 0x8B, 0x29, 0x78, 0x85, 0x45, 0xC7, 0x16, 0x18, 0xB3, 
  0x9D, 0x8C, 0x54, 0x6D, 0x66, 0x62, 0x8B, 0x6E, 0x7C, 0x82, 0xA2, 0xE7, 0x9B, 0x1C, 0x39, 0xEA, 
  0x7E, 0x54, 0x5D, 0x74, 0x64, 0x87, 0x5D, 0x99, 0x65, 0x45, 0x49, 0xF9, 0x42, 0xDE, 0x8C, 0x12, 
  0xA2, 0xA7, 0x5C, 0x00, 0xA5, 0x08, 0x14, 0xF9, 0x7F, 0xDB, 0x8E, 0x97, 0xC0, 
};

static TYPE_GrData _MessageBoxSelectedButtonBackground_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _MessageBoxSelectedButtonBackground_Cpm,      //data
  10000,                           //size
   100,                           //width
    25                            //height
};

