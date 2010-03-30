#include "tap.h"

byte _Button_sat_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0x0F, 0x4F, 0x5C, 0xFF, 0xFF, 0x0C, 0x80, 
  0x01, 0x62, 0x62, 0x76, 0xEE, 0xD1, 0xA7, 0x97, 0xB1, 0x37, 0x80, 0x36, 0x36, 0x82, 0xA1, 0xC5, 
  0x3A, 0xDB, 0x7A, 0xEA, 0xDC, 0x60, 0x60, 0x51, 0x60, 0x55, 0x60, 0x34, 0xCE, 0xDB, 0x5D, 0xA0, 
  0x5D, 0x79, 0x3B, 0xB9, 0x2A, 0x08, 0x85, 0x60, 0x29, 0x56, 0x13, 0xD0, 0xDE, 0x76, 0x85, 0x8C, 
  0x60, 0xD8, 0xC8, 0x6D, 0x83, 0x6A, 0x1B, 0x05, 0x44, 0x41, 0x81, 0x55, 0x55, 0x2B, 0x41, 0x45, 
  0xB0, 0x94, 0x44, 0x5A, 0x09, 0x50, 0x50, 0x56, 0x22, 0x7D, 0x7F, 0x7F, 0x4F, 0xB8, 0x2F, 0x40, 
  0x67, 0xE4, 0x37, 0x60, 0xB0, 0x30, 0x68, 0x0C, 0x07, 0xC1, 0x3D, 0xE0, 0x86, 0x87, 0xA0, 0xD8, 
  0x1D, 0xB8, 0x3B, 0x14, 0x8A, 0x41, 0x9D, 0x55, 0xF9, 0x86, 0x18, 0x37, 0xFE, 0x42, 0x5F, 0xB8, 
  0xE9, 0xD1, 0x97, 0x5D, 0x77, 0x24, 0x27, 0xE6, 0x4C, 0x98, 0xE4, 0x84, 0xFC, 0xB9, 0x72, 0xDC, 
  0x90, 0x9F, 0x95, 0x2A, 0x53, 0x92, 0x13, 0xE9, 0xA6, 0x9D, 0x79, 0xA3, 0x96, 0xA9, 0xB7, 0xB4, 
  0x96, 0x29, 0xDC, 0xCF, 0x59, 0xA2, 0xE7, 0x65, 0x28, 0x43, 0xCF, 0xFA, 0xAA, 0xC8, 0x74, 0xF5, 
  0x56, 0x66, 0xDE, 0x79, 0x16, 0x7F, 0xC6, 0x56, 0x13, 0xF1, 0xE3, 0xC7, 0x6E, 0x71, 0x2F, 0xFC, 
  0x06, 0xE8, 0xDB, 0xBE, 0x29, 0xE1, 0xA0, 0xA9, 0xB8, 0x35, 0x15, 0x68, 0xFA, 0x94, 0x55, 0x22, 
  0xF9, 0x36, 0x16, 0x64, 0x31, 0x63, 0x16, 0xB0, 0x3F, 0x1E, 0xBA, 0xC6, 0xDD, 0xD0, 0x50, 0xDF, 
  0x6F, 0x74, 0x9E, 0xBC, 0xBC, 0x27, 0xE3, 0x46, 0x8C, 0xDC, 0xFC, 0x7D, 0x57, 0x05, 0x93, 0xD1, 
  0x9C, 0x9F, 0x51, 0x6A, 0x49, 0xBC, 0x22, 0xF9, 0xE9, 0x2C, 0x5E, 0xF0, 0xF0, 0x7C, 0x6C, 0x97, 
  0xED, 0xC8, 0xF3, 0x90, 0x79, 0xDF, 0x29, 0x15, 0xF2, 0xF0, 0x9F, 0xEF, 0xC3, 0x86, 0x67, 0x6E, 
  0xDD, 0xF5, 0xC9, 0xF4, 0xFF, 0x7F, 0x46, 0x41, 0xA0, 0x23, 0xDD, 0x68, 0xBF, 0x62, 0xF6, 0xE4, 
  0x5F, 0xC1, 0x88, 0xA5, 0xEF, 0x2B, 0x26, 0x2F, 0x55, 0xDC, 0x37, 0xFF, 0x39, 0x58, 0x4B, 0x84, 
  0xFC, 0x3B, 0x4B, 0x46, 0xEE, 0x77, 0x36, 0xC8, 0x1B, 0x9B, 0x69, 0x4E, 0x9D, 0x27, 0xAB, 0xEF, 
  0x1F, 0x0A, 0xD5, 0x92, 0xF5, 0xBE, 0xFE, 0x42, 0x2C, 0x53, 0x1E, 0xC5, 0x7E, 0xD4, 0xF8, 0x4B, 
  0x84, 0xFC, 0x28, 0x50, 0x9B, 0xB9, 0x9D, 0x47, 0x4F, 0x53, 0xD0, 0x59, 0x7F, 0x2E, 0xCA, 0x85, 
  0x5C, 0x0E, 0x2B, 0x81, 0xC2, 0x2C, 0x6A, 0xF8, 0xAF, 0xDA, 0x9F, 0x09, 0x70, 0x9F, 0xEF, 0x41, 
  0x83, 0x5D, 0x3E, 0x24, 0x6E, 0xDF, 0x15, 0x14, 0xCB, 0x33, 0x19, 0xDE, 0x4E, 0x2C, 0x46, 0x7A, 
  0x6F, 0x5A, 0x40, 0xFD, 0x89, 0xF0, 0x97, 0x09, 0xF8, 0x29, 0x25, 0x5F, 0x8F, 0xF7, 0xBE, 0x54, 
  0x8A, 0x4F, 0xBC, 0xE0, 0x39, 0xFF, 0x3F, 0x09, 0x53, 0xCC, 0xF7, 0xDD, 0x92, 0x0F, 0x4E, 0x6F, 
  0x89, 0x9A, 0xFD, 0x89, 0xF0, 0x97, 0x09, 0xF4, 0xA0, 0x40, 0x6E, 0xE6, 0x7E, 0xDF, 0x9E, 0x47, 
  0x20, 0xC6, 0xA5, 0xD4, 0xA1, 0x24, 0xA6, 0xB5, 0xAC, 0x2F, 0xCE, 0x1F, 0xF1, 0x3E, 0x12, 0xE1, 
  0x3E, 0xFD, 0xFB, 0xF6, 0xEE, 0x63, 0x4D, 0xC6, 0x47, 0x4B, 0x37, 0xCC, 0x6D, 0x1F, 0xA5, 0xE1, 
  0x71, 0xEC, 0x27, 0xE6, 0xFA, 0xEE, 0x8D, 0xE9, 0xC6, 0x88, 0xD5, 0xAC, 0x57, 0x03, 0x9F, 0x96, 
  0x62, 0xEF, 0x80, 0x9F, 0xEB, 0xB1, 0x61, 0x2E, 0x13, 0xEF, 0x9F, 0x3E, 0xFD, 0xF1, 0xFF, 0xFB, 
  0x21, 0x2E, 0x13, 0xEF, 0x5E, 0xBD, 0xB0, 0x9F, 0x09, 0x70, 0x9F, 0x45, 0x14, 0x6C, 0x27, 0xC2, 
  0x5C, 0x27, 0xD0, 0x41, 0x0B, 0x09, 0xF0, 0x97, 0x09, 0xF1, 0xFB, 0x47, 0x78, 0xF1, 0xE1, 0xAC, 
  0xEC, 0xAC, 0xBF, 0xD2, 0x11, 0xE7, 0xFD, 0xEF, 0x80, 
};

TYPE_GrData _Button_sat_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_sat_Cpm,                //data
  3200,                           //size
    40,                           //width
    20                            //height
};

