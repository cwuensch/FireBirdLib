#include "tap.h"

byte _Messagebox_Cpm[] =
{
  0x00, 0x08, 0x19, 0x10, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x07, 
  0x00, 0x68, 0xD7, 0xF9, 0xFF, 0xFF, 0x7F, 0xF8, 
  0x00, 0x89, 0x38, 0x04, 0x61, 0xAF, 0xF0, 0x19, 0xC1, 0x1E, 0x52, 0x40, 0x4C, 0x07, 0xC1, 0xA4, 
  0x2F, 0x6C, 0x00, 0x80, 0x00, 0x00, 0x1B, 0x6E, 0x12, 0x49, 0x24, 0x92, 0x79, 0x92, 0x12, 0x49, 
  0xF5, 0x67, 0xC9, 0x25, 0x67, 0xC9, 0x24, 0xAC, 0xF9, 0x24, 0xAC, 0xF9, 0x24, 0x95, 0x9F, 0x24, 
  0x92, 0xB3, 0xE4, 0x92, 0xB3, 0xE4, 0x92, 0x56, 0x7C, 0x92, 0x4A, 0xCF, 0x92, 0x4A, 0xCF, 0x92, 
  0x49, 0x59, 0xF2, 0x49, 0x59, 0xF2, 0x49, 0x2B, 0x3E, 0x49, 0x25, 0x67, 0xC9, 0x25, 0x67, 0xC9, 
  0x24, 0xAC, 0xF9, 0x24, 0x95, 0x9F, 0x24, 0x95, 0x9F, 0x24, 0x92, 0xB3, 0xE4, 0x92, 0xB3, 0xE4, 
  0x93, 0xA8, 0x00, 0x90, 0xBD, 0x41, 0xFF, 0xFF, 0x7F, 0xF8, 0x00, 0xA0, 0x4C, 0x68, 0xA0, 0x54, 
  0xBF, 0xC0, 0x31, 0x7F, 0xF7, 0x02, 0x02, 0x51, 0x48, 0xF4, 0xF7, 0x58, 0x60, 0x3D, 0x00, 0x78, 
  0x0B, 0xD8, 0x6C, 0xE8, 0x2B, 0x80, 0x9F, 0xB0, 0x03, 0x04, 0x00, 0x30, 0xA9, 0x4A, 0x64, 0xF8, 
  0xE3, 0x18, 0xE9, 0x60, 0xF2, 0x49, 0x4C, 0xF9, 0x24, 0x94, 0xCF, 0x92, 0x4A, 0x67, 0xC9, 0x24, 
  0xA6, 0x7C, 0x92, 0x4A, 0x67, 0xC9, 0x25, 0x33, 0xE4, 0x92, 0x53, 0x3E, 0x4E, 0xDA, 0xD6, 0xB9, 
  0x99, 0x9D, 0x36, 0xB5, 0xB5, 0xDC, 0x44, 0x6B, 0xDD, 0x86, 0xCA, 0x67, 0xC9, 0xF5, 0xE2, 0x63, 
  0xF9, 0x58, 0x2C, 0xA6, 0x7C, 0x92, 0x53, 0x3E, 0x49, 0x27, 0x73, 0x3E, 0x49, 0x24, 0x92, 0x49, 
  0xED, 0xBD, 0xEE, 0x49, 0x27, 0xE5, 0x33, 0xE4, 0x92, 0x99, 0xF2, 0x49, 0x29, 0x9F, 0x24, 0x94, 
  0xCF, 0x92, 0x49, 0x4C, 0xF9, 0x24, 0x94, 0xCF, 0x92, 0x4A, 0x67, 0xC9, 0x24, 0xA6, 0x7C, 0x92, 
  0x4A, 0x67, 0xCF, 0xE8, 0x00, 0x70, 0x2A, 0x87, 0xFF, 0xFF, 0x7F, 0xF8, 0x00, 0x89, 0x38, 0x48, 
  0x61, 0xAF, 0xF2, 0x14, 0xE8, 0x27, 0xAA, 0x48, 0x78, 0xF9, 0x47, 0xC8, 0x9F, 0x60, 0x04, 0x00, 
  0x00, 0x41, 0x49, 0x30, 0x9F, 0x6D, 0xBA, 0xA0, 0xF2, 0x49, 0x6C, 0xF9, 0x24, 0x96, 0xCF, 0x92, 
  0x4B, 0x67, 0xC9, 0x24, 0xB6, 0x7C, 0x92, 0x4B, 0x67, 0xC9, 0x25, 0xB3, 0xE4, 0x92, 0x5B, 0x3E, 
  0x49, 0x2D, 0x9F, 0x41, 0xE4, 0x92, 0xD9, 0xF2, 0x49, 0x2D, 0x9F, 0x24, 0x96, 0xCF, 0x92, 0x49, 
  0x6C, 0xF9, 0x24, 0x96, 0xCF, 0x92, 0x4B, 0x67, 0xC9, 0x24, 0xB6, 0x7C, 0x92, 0x5B, 0x3E, 0x83, 
  0xC9, 0x25, 0xB3, 0xE4, 0x92, 0x5B, 0x3E, 0x49, 0x2D, 0x9F, 0x24, 0x92, 0xD9, 0xF2, 0x49, 0x2D, 
  0x9F, 0x24, 0x96, 0xCF, 0x9E, 0x40, 0x00, 0x70, 0x0A, 0x6D, 0xFF, 0xFF, 0x7F, 0xF8, 0x00, 0x89, 
  0x38, 0x84, 0x81, 0xAF, 0xF0, 0x29, 0x80, 0x9C, 0x52, 0x5C, 0xF0, 0x15, 0x0E, 0xF0, 0x67, 0xF8, 
  0x01, 0x00, 0x00, 0x10, 0x52, 0x4C, 0x24, 0x9E, 0x6D, 0xBA, 0xA0, 0xF2, 0x49, 0x6C, 0xF9, 0x24, 
  0x96, 0xCF, 0x92, 0x4B, 0x67, 0xC9, 0x24, 0xB6, 0x7C, 0x92, 0x4B, 0x67, 0xC9, 0x25, 0xB3, 0xE4, 
  0x92, 0x5B, 0x3E, 0x49, 0x2D, 0x9F, 0x41, 0xE4, 0x92, 0xD9, 0xF2, 0x49, 0x2D, 0x9F, 0x24, 0x96, 
  0xCF, 0x92, 0x49, 0x6C, 0xF9, 0x24, 0x96, 0xCF, 0x92, 0x4B, 0x67, 0xC9, 0x24, 0xB6, 0x7C, 0x92, 
  0x5B, 0x3E, 0x83, 0xC9, 0x25, 0xB3, 0xE4, 0x92, 0x5B, 0x3E, 0x49, 0x2D, 0x9F, 0x24, 0x92, 0xD9, 
  0xF2, 0x49, 0x2D, 0x9F, 0x24, 0x9F, 0xD9, 0xF0, 0x00, 0x71, 0x3A, 0xEB, 0xFF, 0xFF, 0x7F, 0xF8, 
  0x00, 0x8A, 0x44, 0x88, 0x61, 0xA7, 0xFE, 0x02, 0x94, 0x04, 0xD1, 0x48, 0xF6, 0xF0, 0xC0, 0xED, 
  0x04, 0x08, 0x5E, 0x98, 0x01, 0x00, 0x00, 0x00, 0x36, 0xDC, 0xF3, 0x24, 0x24, 0x93, 0xCF, 0xEC, 
  0xBA, 0xCF, 0x92, 0x4A, 0xCF, 0x92, 0x49, 0x59, 0xF2, 0x49, 0x59, 0xF2, 0x49, 0x2B, 0x3E, 0x49, 
  0x25, 0x67, 0xC9, 0x25, 0x67, 0xC9, 0x24, 0xAC, 0xF9, 0x24, 0xAC, 0xFA, 0xCF, 0x92, 0x4A, 0xCF, 
  0x92, 0x49, 0x59, 0xF2, 0x49, 0x59, 0xF2, 0x49, 0x2B, 0x3E, 0x49, 0x25, 0x67, 0xC9, 0x25, 0x67, 
  0xC9, 0x24, 0xAC, 0xF9, 0x24, 0xAC, 0xFA, 0xCF, 0x92, 0x4A, 0xCF, 0x92, 0x49, 0x59, 0xF2, 0x49, 
  0x59, 0xF2, 0x49, 0x2B, 0x3E, 0x49, 0x25, 0x67, 0xC9, 0x3A, 0x80, 0x00, 0x70, 0xB6, 0xF3, 0xFF, 
  0xFF, 0x7F, 0xF8, 0x00, 0x89, 0x38, 0x84, 0x81, 0xAF, 0xF0, 0x29, 0x80, 0x9C, 0x52, 0x5C, 0xF0, 
  0x75, 0x02, 0xF0, 0xC7, 0xF8, 0x01, 0x00, 0x00, 0x10, 0x52, 0x4C, 0x3C, 0xDB, 0x75, 0x41, 0xE4, 
  0x92, 0xD9, 0xF2, 0x49, 0x2D, 0x9F, 0x24, 0x96, 0xCF, 0x92, 0x49, 0x6C, 0xF9, 0x24, 0x96, 0xCF, 
  0x92, 0x4B, 0x67, 0xC9, 0x24, 0xB6, 0x7C, 0x92, 0x5B, 0x3E, 0x83, 0xC9, 0x25, 0xB3, 0xE4, 0x92, 
  0x5B, 0x3E, 0x49, 0x2D, 0x9F, 0x24, 0x92, 0xD9, 0xF2, 0x49, 0x2D, 0x9F, 0x24, 0x96, 0xCF, 0x92, 
  0x49, 0x6C, 0xF9, 0x24, 0xB6, 0x7D, 0x07, 0x92, 0x4B, 0x67, 0xC9, 0x24, 0xB6, 0x7C, 0x92, 0x5B, 
  0x3E, 0x49, 0x25, 0xB3, 0xE4, 0x92, 0x5B, 0x3E, 0x49, 0x2D, 0x9F, 0x27, 0xD0, 0x00, 0x5E, 0xFD, 
  0x39, 0xFF, 0xFF, 0x68, 0x10, 0x00, 0x71, 0x38, 0x84, 0x81, 0xAF, 0xF0, 0x29, 0x80, 0x9C, 0x52, 
  0x5C, 0xF0, 0x2D, 0x0E, 0xF0, 0x4F, 0xF8, 0x01, 0x00, 0x00, 0x10, 0x52, 0x4C, 0x27, 0xDB, 0x6E, 
  0xA8, 0x3C, 0x92, 0x5B, 0x3E, 0x49, 0x25, 0xB3, 0xE4, 0x92, 0xD9, 0xF2, 0x49, 0x2D, 0x9F, 0x24, 
  0x92, 0xD9, 0xF2, 0x49, 0x6C, 0xF9, 0x24, 0x96, 0xCF, 0x92, 0x4B, 0x67, 0xD0, 0x79, 0x24, 0xB6, 
  0x7C, 0x92, 0x4B, 0x67, 0xC9, 0x25, 0xB3, 0xE4, 0x92, 0x5B, 0x3E, 0x49, 0x25, 0xB3, 0xE4, 0x92, 
  0xD9, 0xF2, 0x49, 0x2D, 0x9F, 0x24, 0x96, 0xCF, 0x92, 0x49, 0x24, 0x92, 0x79, 
};

TYPE_GrData _Messagebox_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Messagebox_Cpm,                //data
  223200,                           //size
   360,                           //width
   155                            //height
};

