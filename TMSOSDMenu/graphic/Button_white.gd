#include "tap.h"

byte _Button_white_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0xED, 0x81, 0xDB, 0xFF, 0xFF, 0x02, 0x88, 
  0x00, 0xBB, 0x5B, 0x57, 0xAE, 0x35, 0x20, 0xE3, 0x11, 0x29, 0xB8, 0x4C, 0x25, 0xF0, 0x13, 0x84, 
  0xA6, 0xA2, 0x22, 0x54, 0x44, 0x4C, 0x06, 0x01, 0x01, 0x02, 0x8B, 0x80, 0x40, 0xA0, 0x20, 0x70, 
  0x08, 0x14, 0x1E, 0x03, 0x01, 0xC0, 0x60, 0x30, 0x18, 0x0E, 0x91, 0xFA, 0x05, 0x02, 0x81, 0x40, 
  0xF8, 0x14, 0x0F, 0x81, 0xD2, 0x3D, 0x7E, 0xC9, 0xCB, 0x19, 0xB6, 0x8E, 0xD3, 0x01, 0x59, 0x81, 
  0x6D, 0xA1, 0x64, 0x6E, 0x3B, 0x57, 0xD2, 0x6E, 0x80, 0x29, 0x33, 0x00, 0xC0, 0x09, 0xCF, 0x47, 
  0xAE, 0xCA, 0xB8, 0x2F, 0x46, 0xC9, 0x98, 0xF0, 0x42, 0xBF, 0x3E, 0xDF, 0xB6, 0x17, 0x0F, 0xCE, 
  0xA7, 0xC1, 0xC0, 0xF2, 0x0F, 0x43, 0x00, 0xB1, 0xB9, 0x48, 0xCF, 0x2F, 0x33, 0x1C, 0x4B, 0xDB, 
  0x56, 0x63, 0x63, 0x8A, 0x8F, 0x80, 0xF4, 0x30, 0x07, 0xA3, 0x4F, 0x86, 0xAC, 0xC4, 0x12, 0x65, 
  0x02, 0x75, 0x8D, 0xBA, 0xB9, 0x38, 0x57, 0x42, 0x4E, 0xD9, 0xE2, 0x04, 0x2B, 0x8F, 0xF0, 0x2C, 
  0x7A, 0x1E, 0x89, 0xE1, 0x55, 0x01, 0x5C, 0x13, 0xFE, 0xC6, 0xF4, 0xDF, 0xBA, 0x2B, 0x82, 0xA8, 
  0x0A, 0xEF, 0x2B, 0x7B, 0x07, 0xBF, 0xAB, 0x1B, 0x2E, 0xAD, 0x90, 0x1E, 0xB0, 0x78, 0xAD, 0xB3, 
  0xB2, 0x3B, 0x6C, 0xA3, 0x2C, 0xE0, 0xBD, 0xC7, 0x59, 0xFC, 0xB5, 0xBD, 0x27, 0xC4, 0xF8, 0xF2, 
  0xD3, 0x81, 0x81, 0x65, 0x74, 0xD9, 0x0F, 0x74, 0x0B, 0x3F, 0x68, 0xCD, 0xE5, 0xBF, 0xE1, 0xDB, 
  0xAB, 0x8A, 0xA4, 0xE9, 0x87, 0x60, 0x67, 0xEE, 0x0A, 0xD7, 0x9E, 0xAE, 0x4A, 0xDC, 0xF7, 0x93, 
  0xD2, 0xF4, 0x81, 0x5D, 0x5F, 0xE6, 0xF8, 
};

TYPE_GrData _Button_white_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_white_Cpm,              //data
   648,                           //size
    18,                           //width
    18                            //height
};

