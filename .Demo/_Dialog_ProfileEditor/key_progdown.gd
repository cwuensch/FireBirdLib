#include "type.h"

byte _key_progdown_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x15, 0x51, 0x63, 0xFF, 0xFF, 0x03, 0x2A, 
  0x00, 0xD8, 0x5C, 0x57, 0xAD, 0x37, 0x28, 0xA2, 0x3E, 0x02, 0x22, 0x6C, 0x1C, 0x12, 0x9A, 0xD0, 
  0xD1, 0x11, 0x68, 0x88, 0x94, 0x44, 0x56, 0x86, 0xBD, 0xC8, 0x10, 0x08, 0x02, 0x0A, 0x02, 0x02, 
  0x02, 0xF7, 0x20, 0x40, 0x28, 0x10, 0x59, 0x7B, 0x90, 0x10, 0x10, 0x20, 0x14, 0x0A, 0x2C, 0x01, 
  0x02, 0x01, 0x80, 0xC0, 0x50, 0x23, 0xFB, 0x2C, 0xDB, 0x77, 0x3D, 0x70, 0x3B, 0xB6, 0xC0, 0x5E, 
  0x42, 0xC0, 0x6B, 0x68, 0x00, 0xD4, 0x76, 0xEA, 0xEB, 0x08, 0x73, 0x8B, 0x92, 0x34, 0x0C, 0xA1, 
  0xD3, 0xAB, 0xDA, 0x5C, 0xFA, 0xA2, 0xE4, 0x84, 0x17, 0xC1, 0x80, 0xF0, 0x19, 0xC5, 0x3A, 0x5A, 
  0xCF, 0x18, 0x10, 0x53, 0x88, 0xCA, 0xF0, 0x70, 0xBC, 0xB6, 0x5B, 0x2D, 0x70, 0x83, 0x72, 0x1D, 
  0x51, 0x03, 0x3E, 0x17, 0xDB, 0x2A, 0xA2, 0x5F, 0x69, 0xEA, 0x64, 0xEB, 0x38, 0xAD, 0x93, 0xB9, 
  0x5C, 0x35, 0x3D, 0x43, 0x91, 0xBA, 0x1A, 0x7F, 0x56, 0x79, 0x51, 0xC6, 0x0F, 0x49, 0xCE, 0x20, 
  0x2F, 0xDD, 0xD3, 0x9F, 0x4E, 0x65, 0xB2, 0xB8, 0x7B, 0x95, 0x3C, 0x4E, 0x32, 0x6D, 0x0D, 0x3C, 
  0xCA, 0x0E, 0xE4, 0x1A, 0xE3, 0x03, 0x6E, 0xDF, 0xB9, 0x6B, 0x38, 0xBE, 0x59, 0xEC, 0xA7, 0xC8, 
  0x87, 0x9A, 0x3E, 0xCD, 0x64, 0xCD, 0xA9, 0x6C, 0x4E, 0xB5, 0xAC, 0xCA, 0xFE, 0x6A, 0xBF, 0x89, 
  0x80, 0xF3, 0xA2, 0x82, 0xFD, 0xB5, 0x6E, 0xAE, 0xDC, 0x6F, 0xF5, 0xAE, 0x03, 0x67, 0x82, 0xF3, 
  0xD5, 0xFE, 0x8A, 0x9E, 0x63, 0x53, 0x2B, 0xFD, 0xAE, 0x5D, 0x4F, 0x9D, 0x0E, 0x0E, 0x99, 0x36, 
  0xCD, 0xBF, 0x2F, 0x4B, 0xCA, 0xCA, 0x77, 0x3F, 0x73, 0xF5, 0x6C, 0xFC, 0x1E, 0x6B, 0x30, 0xF8, 
  0x6E, 0x74, 0x87, 0x72, 0x1D, 0xDE, 0x83, 0x19, 0xC6, 0xEB, 0x3E, 0x53, 0x9D, 0x34, 0x38, 0x4E, 
  0x24, 0x3E, 0x84, 0xDB, 0xFD, 0xD9, 0x84, 0x8D, 0xDC, 0xB2, 0xB8, 0xF4, 0x19, 0x8D, 0x84, 
};

TYPE_GrData _key_progdown_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _key_progdown_Cpm,              //data
   810,                           //size
    27,                           //width
    15                            //height
};

