#include "tap.h"

byte _MsgBox_C_Border_Cpm[] =
{
  0x00, 0x08, 0x1A, 0xD0, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x02, 
  0x00, 0xC4, 0x96, 0x95, 0xFF, 0xFF, 0x7F, 0xF8, 
  0x00, 0x93, 0x4C, 0x48, 0xA2, 0xC8, 0xBF, 0xD6, 0x97, 0x09, 0x22, 0xD9, 0x08, 0xEA, 0x28, 0xE0, 
  0x64, 0x19, 0x09, 0x11, 0x09, 0x26, 0x79, 0x1F, 0xC8, 0x27, 0xFD, 0x99, 0x11, 0xE9, 0x48, 0x00, 
  0x00, 0x3E, 0x66, 0xBA, 0xFD, 0xCF, 0xBC, 0x4E, 0xEB, 0xAD, 0xE7, 0x75, 0xCE, 0xD3, 0x39, 0x9C, 
  0xCE, 0x7F, 0x39, 0xF1, 0xAC, 0xEE, 0xB4, 0xCC, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 
  0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 
  0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 
  0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 
  0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 
  0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 
  0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 
  0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 
  0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x3F, 0x5C, 0xC0, 0x00, 0xA8, 
  0x11, 0xD4, 0xFF, 0xFF, 0x55, 0x88, 0x00, 0x78, 0x56, 0x4C, 0xC0, 0x4A, 0x97, 0xF9, 0xE0, 0xD1, 
  0x21, 0x3D, 0x89, 0xC8, 0x3C, 0x45, 0x80, 0x11, 0x88, 0x08, 0x88, 0x2F, 0xC7, 0xA4, 0xA4, 0x42, 
  0x42, 0x59, 0x35, 0x0A, 0x98, 0xE0, 0x3A, 0x04, 0x17, 0x78, 0xBF, 0xED, 0xA0, 0x00, 0x00, 0x87, 
  0x87, 0xED, 0x31, 0x85, 0xF1, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 
  0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x9F, 
  0x4E, 0x7F, 0x35, 0xAA, 0x63, 0x8B, 0x54, 0xFC, 0xF3, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 
  0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 
  0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x99, 0xCC, 0xE6, 
  0x73, 0x39, 0x9C, 0xCE, 0x67, 0x33, 0x9F, 0x6E, 0x7F, 0x6F, 0x8E, 0x7F, 0xDC, 0xFD, 0xE5, 0x54, 
  0xC7, 0x16, 0xA8, 0xE6, 0x73, 0x39, 0x9C, 0xCE, 0x7C, 0xB9, 0xEF, 0xA5, 0x53, 0x1B, 0x78, 0xAA, 
  0x63, 0x3F, 0x35, 0x4C, 0x7A, 0xC6, 0xA9, 0x80, 
};

TYPE_GrData _MsgBox_C_Border_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _MsgBox_C_Border_Cpm,           //data
  54656,                           //size
   122,                           //width
   224                            //height
};

