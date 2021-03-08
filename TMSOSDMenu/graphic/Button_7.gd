#include "tap.h"

static byte _Button_7_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x64, 0xBA, 0x42, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0xFF, 0x5A, 0x72, 0xDA, 0xB6, 0xAA, 0xDB, 0x81, 0x3A, 0xEC, 0x0B, 0x09, 0x32, 0x15, 0xA6, 
  0xBA, 0xED, 0x9B, 0xAA, 0x31, 0x51, 0x04, 0x41, 0x5A, 0x28, 0xE2, 0xA2, 0x55, 0xB4, 0x72, 0xE6, 
  0xE6, 0x13, 0x60, 0xA1, 0x58, 0x0C, 0x0A, 0x0C, 0x1C, 0xC2, 0x60, 0xB0, 0x11, 0x10, 0x60, 0xA0, 
  0xA0, 0x82, 0x2C, 0x14, 0x51, 0x84, 0xA0, 0xC0, 0x60, 0xA1, 0xB0, 0x31, 0xD9, 0x2C, 0x05, 0x3F, 
  0x7E, 0xAA, 0xD8, 0x0C, 0x7A, 0xE3, 0x58, 0x16, 0x07, 0xA0, 0x60, 0xDC, 0x0B, 0x60, 0x30, 0x70, 
  0x6C, 0xA1, 0x00, 0x19, 0xD6, 0xE8, 0xDF, 0x1C, 0xAB, 0x56, 0xA9, 0x7F, 0xD8, 0xDF, 0x5C, 0x75, 
  0xD7, 0x4A, 0xED, 0x07, 0xDC, 0x71, 0xC2, 0xBB, 0x41, 0xF6, 0xDB, 0x6C, 0xAE, 0xD0, 0x7D, 0xA6, 
  0x9A, 0x28, 0x2E, 0xB5, 0x46, 0x8B, 0x6F, 0x6A, 0xC5, 0xD9, 0xD8, 0xB1, 0xB6, 0x28, 0x3E, 0xCB, 
  0x2C, 0x94, 0x16, 0xA6, 0xAB, 0x25, 0xEF, 0x5E, 0x9F, 0xED, 0xED, 0xE4, 0xD3, 0x2B, 0x3B, 0xE0, 
  0xFA, 0xCB, 0x2C, 0x50, 0x5D, 0x15, 0xF3, 0x8B, 0xC7, 0xA7, 0x4B, 0xF2, 0xD6, 0xEB, 0xA4, 0xF9, 
  0xFE, 0x3D, 0xE6, 0x0A, 0xCE, 0xF8, 0x3E, 0xAA, 0xAA, 0x95, 0xBB, 0xC5, 0xBB, 0x9E, 0xF1, 0xBF, 
  0x5F, 0x2D, 0x42, 0x61, 0x7C, 0xB8, 0x72, 0xC1, 0xFC, 0x25, 0x14, 0x28, 0xF1, 0xE3, 0x9A, 0xDE, 
  0xDE, 0x49, 0x2F, 0x4E, 0xF6, 0x1E, 0x3F, 0xC3, 0xB9, 0x8D, 0x0E, 0x58, 0x2E, 0x0F, 0xA9, 0x42, 
  0x85, 0xA3, 0xFA, 0xF4, 0x94, 0x78, 0xDF, 0xB5, 0x6A, 0x65, 0x86, 0x9D, 0xF4, 0x39, 0x60, 0xB8, 
  0x3E, 0x9A, 0x69, 0x98, 0xDC, 0x83, 0x8E, 0x2A, 0xFD, 0x5F, 0x3D, 0x1B, 0xE8, 0xE0, 0xCA, 0x8B, 
  0x3C, 0x17, 0x07, 0xF0, 0x67, 0xCF, 0x31, 0xFD, 0x0C, 0xC4, 0x9F, 0xEE, 0xBE, 0x46, 0x2E, 0x04, 
  0x59, 0xE0, 0xB8, 0x3F, 0x3E, 0x74, 0xE3, 0x1F, 0xEE, 0xE5, 0xCD, 0x78, 0xDF, 0x87, 0x35, 0x13, 
  0x67, 0x82, 0xE0, 0xFC, 0xE9, 0xB3, 0x62, 0xCB, 0xC7, 0xC4, 0x3D, 0xFF, 0x9D, 0xB3, 0x46, 0x69, 
  0x8F, 0x82, 0xE0, 0xFA, 0x49, 0x25, 0x16, 0x5F, 0x3E, 0xFE, 0x4B, 0xC6, 0xFC, 0xFB, 0x17, 0x29, 
  0x32, 0x0E, 0x31, 0xF0, 0x5C, 0x1F, 0x99, 0x32, 0x65, 0xAF, 0x0F, 0xED, 0xD0, 0x5C, 0x1F, 0x45, 
  0x14, 0x6E, 0x1F, 0x05, 0xC1, 0xF9, 0x72, 0xE5, 0xDC, 0x3E, 0x0B, 0x83, 0xE7, 0x9E, 0x7D, 0xC3, 
  0xE0, 0xBF, 0xDF, 0xF6, 0x1D, 0xFC, 0xA9, 0x45, 0xFD, 0x50, 0x41, 0x07, 0xCD, 0x80, 
};

TYPE_GrData _Button_7_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_7_Cpm,                  //data
  1920,                           //size
    24,                           //width
    20                            //height
};

