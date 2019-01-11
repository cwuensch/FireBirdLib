#include "tap.h"

static byte _Button_progplus_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x3A, 0x88, 0xCD, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0xCF, 0x5A, 0x72, 0xA2, 0xB6, 0xAB, 0x6F, 0x02, 0x6C, 0x76, 0x06, 0xC1, 0x43, 0x5B, 0x6E, 
  0xB7, 0x5B, 0x58, 0x1A, 0x0A, 0x30, 0x98, 0x77, 0x30, 0x5B, 0x8B, 0x81, 0x6A, 0xA8, 0x96, 0x16, 
  0x0B, 0x0D, 0xA2, 0x30, 0x1B, 0x05, 0x0A, 0x2C, 0x0D, 0x05, 0x81, 0x8D, 0x03, 0x68, 0x1A, 0x16, 
  0x0C, 0x1A, 0x06, 0x80, 0x8C, 0x85, 0x82, 0xC3, 0x47, 0x81, 0x29, 0xF7, 0xDF, 0x0A, 0x87, 0xE8, 
  0x6A, 0x97, 0x03, 0x41, 0x42, 0xB0, 0xD9, 0xAC, 0x07, 0x80, 0x5A, 0x0D, 0x06, 0xE7, 0x05, 0x7A, 
  0x43, 0x68, 0xDA, 0xDE, 0xBF, 0xA1, 0x86, 0x12, 0x6A, 0xA0, 0xDC, 0x10, 0x40, 0x4F, 0xFA, 0xFB, 
  0xEF, 0xD3, 0x5E, 0x79, 0xEA, 0x6B, 0xAE, 0xBB, 0x4D, 0x71, 0xC7, 0x24, 0xB7, 0xBA, 0x78, 0x49, 
  0xE3, 0x9F, 0x8E, 0x3B, 0x8F, 0xB3, 0x8B, 0x4E, 0xAE, 0x7A, 0xD3, 0x4D, 0x49, 0x70, 0xDE, 0xDE, 
  0x27, 0xA7, 0x97, 0x24, 0x97, 0x25, 0xFD, 0xF8, 0xF4, 0xFD, 0x1C, 0xB7, 0x0B, 0x65, 0x07, 0x15, 
  0x65, 0x96, 0x64, 0xB8, 0x3A, 0xDB, 0x28, 0xFF, 0x0C, 0xCE, 0x11, 0xBB, 0x7B, 0x85, 0xE7, 0x12, 
  0x33, 0x69, 0xE5, 0xC3, 0xD1, 0x76, 0x18, 0x60, 0x87, 0x1C, 0x74, 0x77, 0x9E, 0xED, 0x92, 0xED, 
  0xFB, 0x71, 0x5A, 0x2F, 0xFF, 0xD5, 0xCD, 0xB3, 0xEC, 0x2C, 0xDA, 0x79, 0x70, 0xCD, 0x41, 0xB6, 
  0x17, 0x5E, 0x63, 0xFE, 0x7D, 0xD7, 0x23, 0x36, 0x17, 0xDD, 0xE0, 0x5C, 0xBC, 0xC5, 0x36, 0x3C, 
  0x59, 0x66, 0x0E, 0x0D, 0xAC, 0xB2, 0xD3, 0x1F, 0x35, 0xEF, 0xCB, 0xBA, 0x4D, 0xAB, 0x35, 0x74, 
  0xE5, 0xC5, 0x46, 0x59, 0x83, 0x83, 0x76, 0x15, 0x56, 0x63, 0xE0, 0x9D, 0xAD, 0xBA, 0xC5, 0x2F, 
  0x2F, 0x7F, 0xCF, 0xE1, 0xF0, 0x6D, 0x55, 0x14, 0xFB, 0xF3, 0xFF, 0xC5, 0x9C, 0xF8, 0x36, 0xA5, 
  0x7A, 0xFF, 0xA7, 0xC7, 0x73, 0xE8, 0xF0, 0x99, 0xA8, 0x36, 0x9A, 0x69, 0xFB, 0xF6, 0xBA, 0x5A, 
  0xFF, 0x5E, 0x17, 0xFC, 0xA0, 0xDA, 0x49, 0x25, 0xFC, 0x0F, 0xE6, 0x83, 0x68, 0xA2, 0x8D, 0x07, 
  0xC1, 0xB4, 0x10, 0x42, 0x83, 0xE0, 0xD9, 0xE7, 0x9F, 0x41, 0xF0, 0x6C, 0x7D, 0x61, 0xD5, 0xA9, 
  0x50, 0x9A, 0xA8, 0x36, 
};

static TYPE_GrData _Button_progplus_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_progplus_Cpm,           //data
  1920,                           //size
    24,                           //width
    20                            //height
};

