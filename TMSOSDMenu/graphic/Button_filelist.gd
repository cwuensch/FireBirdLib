#include "tap.h"

static byte _Button_filelist_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x07, 0x77, 0x43, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0xB5, 0x5A, 0x75, 0xC3, 0x05, 0x15, 0x5B, 0xBC, 0x07, 0x47, 0x33, 0x87, 0xA0, 0x44, 0x55, 
  0xE5, 0x9E, 0x6F, 0x00, 0xDC, 0x8E, 0x57, 0x14, 0x39, 0x5C, 0x8E, 0x57, 0x23, 0xE1, 0xAF, 0x78, 
  0x17, 0xC7, 0xF7, 0xD1, 0x7F, 0xC1, 0xFE, 0x07, 0x05, 0xC1, 0x5A, 0x38, 0x28, 0x2C, 0x1F, 0xE4, 
  0xB0, 0xC1, 0x59, 0x2C, 0x76, 0x18, 0x3B, 0x30, 0x5B, 0x48, 0x6D, 0xEE, 0xD9, 0xE1, 0xE6, 0x9A, 
  0x68, 0x9F, 0xD7, 0x67, 0x97, 0x99, 0xE7, 0x9A, 0x75, 0xA1, 0xFC, 0xB2, 0xC9, 0x3A, 0xD0, 0xFE, 
  0x38, 0xE2, 0x8B, 0x78, 0xF0, 0xEF, 0xFC, 0xAC, 0x3C, 0x3F, 0x86, 0x18, 0x22, 0xD3, 0x3D, 0xBE, 
  0xEF, 0x75, 0xDF, 0x87, 0xEF, 0xBE, 0xF4, 0x5A, 0x67, 0xAF, 0xBB, 0xD6, 0xDF, 0xAD, 0x0F, 0xDD, 
  0x75, 0xC8, 0xB4, 0xCF, 0x6F, 0xBB, 0xDD, 0x77, 0xE1, 0xFB, 0x6D, 0xB5, 0x16, 0x99, 0xED, 0xF7, 
  0x7B, 0xAE, 0xFC, 0x3F, 0xDD, 0x65, 0x89, 0x14, 0x51, 0x24, 0x30, 0xC3, 0xE3, 0x9E, 0xBE, 0xEF, 
  0x5B, 0x7E, 0x50, 0xB8, 0x7E, 0xCD, 0xFB, 0xD2, 0x08, 0x20, 0xE5, 0x9E, 0x7C, 0xFE, 0x6B, 0x1F, 
  0x0B, 0x87, 0xEB, 0xAE, 0xBE, 0x58, 0x7E, 0x7C, 0x0F, 0xF1, 0x5B, 0x6E, 0x17, 0x0F, 0xF6, 0xD5, 
  0x57, 0x33, 0xFA, 0xA3, 0x7E, 0x8F, 0x85, 0xC3, 0xF5, 0x53, 0x4F, 0xA9, 0xF7, 0xE4, 0x76, 0x3E, 
  0x17, 0x0F, 0xD3, 0xBB, 0x77, 0x4E, 0x3F, 0x73, 0xE1, 0x70, 0xFD, 0x14, 0x51, 0xD3, 0xAF, 0xEF, 
  0xD1, 0xF0, 0xB8, 0x7E, 0x79, 0xE7, 0xE6, 0xFF, 0xEF, 0xBB, 0xE1, 0x70, 0xFC, 0xD3, 0x4D, 0xEF, 
  0xC4, 0x7E, 0xDF, 0xA0, 0xE5, 0x0B, 0x87, 0xE5, 0x96, 0x5F, 0xAE, 0x33, 0xF4, 0xA1, 0x70, 0xFC, 
  0x71, 0xC7, 0xFE, 0x7C, 0x2E, 0xBF, 0xEC, 0x39, 0x24, 0x91, 0x3B, 0x36, 0xED, 0xFD, 0xA0, 0xF5, 
  0x36, 
};

TYPE_GrData _Button_filelist_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_filelist_Cpm,           //data
  1920,                           //size
    24,                           //width
    20                            //height
};

