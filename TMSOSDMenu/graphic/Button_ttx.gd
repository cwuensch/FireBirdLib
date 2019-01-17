#include "tap.h"

byte _Button_ttx_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0xF8, 0xBA, 0xCC, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0xAC, 0x5A, 0x75, 0xC3, 0x44, 0xDD, 0x5A, 0xF8, 0x0E, 0x8C, 0xBB, 0x81, 0x11, 0x55, 0x5A, 
  0xD7, 0x78, 0x06, 0xC4, 0x62, 0xB0, 0xB0, 0xC5, 0x62, 0x31, 0x58, 0x8F, 0x86, 0xB7, 0xC0, 0xBA, 
  0x7F, 0xBE, 0x0D, 0xFD, 0x0E, 0xA1, 0xD4, 0x34, 0x0D, 0xA7, 0xD8, 0x1B, 0x07, 0x40, 0xD8, 0x2D, 
  0x0B, 0x22, 0xC0, 0xB0, 0x78, 0x2E, 0x50, 0x84, 0x98, 0xDA, 0x36, 0xAF, 0x7E, 0x69, 0xA6, 0x89, 
  0xE2, 0xEA, 0xF8, 0xE6, 0x79, 0xE6, 0x9E, 0x68, 0x7F, 0x2C, 0xB2, 0x46, 0xDD, 0xFB, 0xBD, 0xBF, 
  0x6F, 0xC8, 0x70, 0xFE, 0x38, 0xE2, 0x8B, 0x5C, 0x5D, 0xB5, 0x83, 0xC3, 0xF8, 0x61, 0x82, 0x2D, 
  0x37, 0xD9, 0x9F, 0xF2, 0xB7, 0xEF, 0x87, 0xEF, 0xBE, 0xF4, 0x2A, 0xBF, 0x66, 0x3E, 0x75, 0xA0, 
  0xCA, 0x1F, 0xBA, 0xEB, 0x90, 0xAB, 0xB6, 0xB9, 0xDD, 0x5A, 0x0C, 0x3F, 0x6D, 0xB6, 0xA1, 0x57, 
  0x6D, 0x73, 0xBA, 0xB4, 0x18, 0x7F, 0xD6, 0xCB, 0x12, 0x18, 0x61, 0xE1, 0xB6, 0xCC, 0x7C, 0xEB, 
  0x41, 0x85, 0xC3, 0xF6, 0x6D, 0xDB, 0xC7, 0x6E, 0x08, 0x20, 0xFF, 0xAC, 0x3E, 0x17, 0x0F, 0xD7, 
  0x5D, 0x7C, 0x9D, 0xFF, 0x56, 0x03, 0x0B, 0x87, 0xF6, 0x55, 0x53, 0xFC, 0x3E, 0x17, 0x0F, 0xD5, 
  0x4D, 0x2F, 0xEB, 0xF0, 0xB8, 0x7E, 0x9A, 0x28, 0x79, 0xF0, 0xB8, 0x7E, 0x79, 0xE7, 0x7F, 0x87, 
  0xC2, 0xE1, 0xF9, 0xA6, 0x9B, 0x8B, 0xFE, 0xDD, 0x7E, 0xB9, 0xC2, 0xE1, 0xF9, 0x65, 0x97, 0x97, 
  0x6F, 0xF4, 0xAA, 0x2C, 0x2E, 0x1F, 0x92, 0x49, 0x3E, 0xFC, 0x8E, 0xE2, 0xEB, 0x42, 0xE1, 0xF8, 
  0xA2, 0x8B, 0xAF, 0x84, 0xFE, 0xA8, 0x5D, 0x7F, 0xB0, 0xFD, 0x35, 0xEB, 0x4E, 0xF6, 0x38, 0xE3, 
  0xE0, 0x6C, 
};

TYPE_GrData _Button_ttx_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_ttx_Cpm,                //data
  1920,                           //size
    24,                           //width
    20                            //height
};

