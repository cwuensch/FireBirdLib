#include "type.h"

byte _MsgBox_E_Text_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0xC8, 0x15, 0x66, 0xFF, 0xFF, 0x1E, 0x60, 
  0x00, 0x78, 0x53, 0x51, 0x80, 0x36, 0xBF, 0xD8, 0x44, 0xCA, 0x2A, 0x22, 0x62, 0x2B, 0xC0, 0x3C, 
  0x2B, 0xC0, 0x3A, 0x2A, 0x02, 0x02, 0x42, 0x05, 0x05, 0x01, 0x31, 0x13, 0x0A, 0x98, 0x89, 0x40, 
  0x68, 0x18, 0x0C, 0x05, 0x03, 0x01, 0x40, 0x40, 0xD2, 0xC4, 0x44, 0x17, 0x4D, 0x2C, 0xB2, 0xC6, 
  0x25, 0x69, 0xA6, 0x8C, 0x78, 0x16, 0x98, 0x80, 0xF0, 0x55, 0xE2, 0xBF, 0xF3, 0x60, 0x00, 0x74, 
  0xC0, 0x56, 0xC4, 0x42, 0xAD, 0xDC, 0xB8, 0x53, 0x9E, 0xCB, 0x26, 0xEF, 0x1A, 0x98, 0x5A, 0xA7, 
  0x62, 0x1A, 0x9B, 0x95, 0x75, 0x17, 0x57, 0xAF, 0x8A, 0xBD, 0x57, 0x15, 0x15, 0x15, 0x15, 0x15, 
  0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0xF8, 0xAD, 0x6A, 0x85, 0xAA, 
  0x77, 0xDB, 0x95, 0xDF, 0x9B, 0xC5, 0xDB, 0xC7, 0x56, 0x5C, 0x55, 0xDD, 0x93, 0x5E, 0x89, 0x72, 
  0x1E, 0xD8, 0x5F, 0x5F, 0x85, 0xFF, 0x9B, 0x96, 0xE6, 0xA4, 0xFF, 0x94, 0x54, 0x54, 0x54, 0x54, 
  0x54, 0x57, 0xFA, 0xB5, 0xAB, 0xD2, 0xAE, 0xA3, 0xF2, 0xAC, 0x47, 0xB5, 0x58, 0x8C, 0x15, 0xE8, 
  0xB5, 0xBA, 0xF5, 0x5F, 0xD4, 0xE1, 0xF5, 0x32, 0xD5, 0x27, 0x14, 0xE6, 0x9A, 0x3A, 0xBF, 0xE2, 
  0x99, 0x09, 0x29, 0x6F, 0x9D, 0x5F, 0x99, 0xB3, 0x4F, 0xDE, 0x36, 0xAA, 0x6F, 0x3E, 0xDF, 0x4A, 
  0xDC, 0x20, 
};

TYPE_GrData _MsgBox_E_Text_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _MsgBox_E_Text_Cpm,             //data
  7776,                           //size
    27,                           //width
   144                            //height
};

