#include "tap.h"

byte _Button_rwd_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0xF0, 0xF7, 0x82, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0xA9, 0x5A, 0x59, 0xC0, 0x44, 0xED, 0x5E, 0x53, 0xC3, 0xF1, 0x2D, 0x23, 0x60, 0x88, 0xAA, 
  0xAB, 0xD6, 0xB7, 0xC0, 0x39, 0x49, 0x59, 0x2C, 0x4A, 0xCA, 0x4A, 0xCA, 0x5F, 0x0D, 0x77, 0xC0, 
  0xBF, 0x1D, 0xEF, 0xF0, 0x76, 0x0E, 0xC1, 0x64, 0x32, 0x10, 0x6C, 0x1A, 0x4F, 0x21, 0x21, 0x21, 
  0xB0, 0xFE, 0x4F, 0x23, 0x21, 0xD9, 0x42, 0x01, 0xC2, 0x00, 0xAC, 0x7F, 0xFA, 0xFB, 0xEF, 0x47, 
  0xDA, 0x17, 0xFC, 0x61, 0x84, 0x5D, 0x75, 0xCB, 0xA1, 0xFB, 0x6D, 0xB5, 0x74, 0x3F, 0x65, 0x96, 
  0x2E, 0x87, 0xEB, 0xAE, 0xB5, 0xD0, 0xFD, 0x55, 0x55, 0x95, 0xFE, 0xE1, 0xBF, 0xDE, 0xB0, 0xFD, 
  0x34, 0xD3, 0xDE, 0x9D, 0xF2, 0xE9, 0xAC, 0xA1, 0xFA, 0x28, 0xA3, 0x1A, 0x9E, 0xF9, 0x73, 0xD6, 
  0x9A, 0x1F, 0xDD, 0x3C, 0xE8, 0x69, 0xA6, 0xB9, 0x56, 0xDB, 0x6F, 0x8D, 0x57, 0x7C, 0xA9, 0xCF, 
  0xDB, 0x5A, 0x81, 0x85, 0xC3, 0xF3, 0xED, 0xDB, 0xCC, 0xFB, 0x2C, 0xB3, 0xD3, 0xBE, 0x53, 0x3F, 
  0x8D, 0x6A, 0x06, 0x17, 0x0F, 0xCD, 0x34, 0xDC, 0xCF, 0xA6, 0xE0, 0x0F, 0xCE, 0xB4, 0xD0, 0xB8, 
  0x7F, 0xF6, 0x59, 0x7A, 0xEF, 0xC0, 0x3E, 0x7A, 0xCA, 0x17, 0x0F, 0xCB, 0x24, 0x98, 0x9F, 0x50, 
  0x7D, 0x35, 0x85, 0xC3, 0xF2, 0x47, 0x1F, 0x73, 0xE9, 0x0F, 0xA6, 0xB0, 0xB8, 0x7E, 0x28, 0xA2, 
  0xC8, 0xFF, 0xAA, 0x17, 0x0F, 0xC3, 0x0C, 0x3A, 0x9F, 0x0B, 0x87, 0xE0, 0x82, 0x0D, 0x4F, 0x85, 
  0xC3, 0xEF, 0xBE, 0xFE, 0xA7, 0xC2, 0xE1, 0xF7, 0x5D, 0x77, 0x53, 0xE1, 0x70, 0xF9, 0xFB, 0x1D, 
  0xE7, 0x9E, 0x46, 0xC7, 0x1C, 0xF9, 0x41, 0xE9, 0xFE, 0x3E, 
};

TYPE_GrData _Button_rwd_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_rwd_Cpm,                //data
  1920,                           //size
    24,                           //width
    20                            //height
};

