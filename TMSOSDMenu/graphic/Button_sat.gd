#include "tap.h"

static byte _Button_sat_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0x0E, 0xA9, 0x60, 0xFF, 0xFF, 0x0C, 0x80, 
  0x01, 0x66, 0x62, 0x9A, 0xF7, 0x7A, 0xB4, 0xB2, 0xCF, 0xC0, 0x9D, 0xCC, 0xF0, 0xB0, 0x78, 0xC7, 
  0xB6, 0xDB, 0xD9, 0xCE, 0x88, 0x2E, 0x0C, 0x4F, 0x06, 0x57, 0x81, 0xC2, 0xD5, 0x6A, 0xE0, 0xD6, 
  0xF4, 0x7B, 0xDE, 0x4C, 0x82, 0x21, 0x9E, 0x05, 0x32, 0xF1, 0x3B, 0x8D, 0xCD, 0x71, 0x44, 0x41, 
  0x44, 0x85, 0x41, 0x58, 0x28, 0x34, 0x44, 0x17, 0x06, 0xAD, 0x4A, 0x67, 0x02, 0x8B, 0xB8, 0x94, 
  0x44, 0x5C, 0x09, 0x90, 0x50, 0x57, 0x91, 0x3F, 0x6F, 0xEF, 0xCD, 0xFF, 0xE0, 0xDE, 0xE0, 0x7B, 
  0xEC, 0x1B, 0x42, 0xF0, 0x41, 0x70, 0x3C, 0x0F, 0xC1, 0x3B, 0xE0, 0x85, 0xC7, 0x70, 0xE0, 0xF6, 
  0xE0, 0xEC, 0x52, 0x29, 0x06, 0xB6, 0xAB, 0xF4, 0xB9, 0x72, 0xCB, 0xFF, 0x36, 0xDF, 0x8F, 0xA5, 
  0x4A, 0x94, 0x4D, 0xC8, 0x4F, 0xC9, 0x93, 0x24, 0x9B, 0x90, 0x9F, 0x91, 0x22, 0x41, 0x37, 0x21, 
  0x3F, 0x1E, 0x3C, 0x72, 0x6E, 0x42, 0x7D, 0x55, 0x55, 0x2E, 0x69, 0xA3, 0xF0, 0x5C, 0xB6, 0x7E, 
  0xCC, 0x1C, 0xEB, 0xFD, 0x18, 0x68, 0xB9, 0xB9, 0xCB, 0x18, 0xF3, 0xBD, 0xAB, 0xB2, 0x1D, 0x3D, 
  0x06, 0x19, 0xB7, 0xA2, 0x45, 0x9F, 0xF3, 0x95, 0x84, 0xFC, 0x48, 0x91, 0x0A, 0xC4, 0xE4, 0x61, 
  0xF5, 0x8B, 0x8F, 0x5B, 0x08, 0xE7, 0x72, 0x82, 0xE5, 0xB7, 0x9E, 0xBB, 0x47, 0xD4, 0xA2, 0xB9, 
  0x97, 0xBF, 0xA6, 0xC3, 0x21, 0x8B, 0x18, 0xB5, 0x81, 0xF7, 0xB4, 0x98, 0x2D, 0x8F, 0xAA, 0xC5, 
  0xEE, 0xF3, 0x46, 0xAF, 0x97, 0x84, 0xFC, 0x38, 0x70, 0xCA, 0xC4, 0xFA, 0x7C, 0x57, 0x87, 0x93, 
  0xD1, 0x9A, 0xAF, 0x29, 0x6B, 0x46, 0xC1, 0x32, 0xF8, 0xA9, 0x30, 0x7E, 0xF1, 0xF1, 0x7B, 0x4C, 
  0x97, 0xE5, 0xCC, 0xEF, 0x18, 0x7F, 0x3F, 0x54, 0x52, 0xE6, 0xCB, 0xC2, 0x7F, 0xAB, 0x02, 0x01, 
  0x38, 0x70, 0xE2, 0xBC, 0xA3, 0x4F, 0xF6, 0xA7, 0xC5, 0x27, 0xA9, 0xDB, 0xB4, 0x5F, 0x92, 0x55, 
  0xD9, 0x97, 0xE8, 0x97, 0x08, 0xFD, 0xE7, 0x66, 0xC2, 0xE5, 0xBB, 0x86, 0xFD, 0x8C, 0xAC, 0x25, 
  0xC2, 0x7E, 0x05, 0xD5, 0xD5, 0x9B, 0x9D, 0xEF, 0x61, 0x22, 0xE1, 0xD5, 0x5B, 0x93, 0x49, 0xEA, 
  0xFB, 0xCB, 0xC6, 0xEB, 0xB2, 0x5E, 0x8F, 0xBF, 0xB6, 0x65, 0x8A, 0x63, 0xD8, 0xAF, 0xD2, 0x9F, 
  0x09, 0x70, 0x9F, 0x7E, 0xFD, 0xFD, 0x9B, 0x9A, 0x14, 0x74, 0xF3, 0xFB, 0xE7, 0x97, 0xF0, 0x6A, 
  0x2C, 0x75, 0xC0, 0xE2, 0xB8, 0x1C, 0x22, 0xC6, 0xAF, 0x8A, 0xFD, 0x29, 0xF0, 0x97, 0x09, 0xFB, 
  0x97, 0xCF, 0xB9, 0xD3, 0xE2, 0x46, 0xED, 0xEE, 0xD1, 0x54, 0xF3, 0x31, 0x9D, 0xE6, 0xE4, 0xC1, 
  0x67, 0xA6, 0xF5, 0xA4, 0x0F, 0xD0, 0x9F, 0x09, 0x70, 0x9F, 0x7C, 0xA2, 0x9C, 0xFC, 0x7F, 0xF0, 
  0x77, 0x14, 0x39, 0x46, 0xF3, 0x80, 0xE7, 0x7A, 0xF0, 0x0E, 0x9F, 0xC7, 0xCF, 0x7E, 0x68, 0x3F, 
  0xBC, 0xCE, 0xCB, 0x35, 0xFA, 0x13, 0xE1, 0x2E, 0x13, 0xEA, 0x3D, 0x7B, 0x66, 0xE6, 0x8E, 0xDF, 
  0xA2, 0x47, 0x20, 0xC6, 0xA5, 0xD4, 0xA1, 0x18, 0xE6, 0xB5, 0xAC, 0x2F, 0xD0, 0x1F, 0xF1, 0x3E, 
  0x12, 0xE1, 0x3E, 0xF1, 0xE3, 0xCB, 0x37, 0x31, 0xA6, 0xE3, 0x23, 0xA5, 0xF2, 0xEE, 0x94, 0xFF, 
  0x66, 0x09, 0xF1, 0xEC, 0x27, 0xE6, 0x78, 0xEF, 0x8B, 0xC3, 0x95, 0x05, 0xAB, 0x58, 0xAE, 0x07, 
  0x47, 0x2C, 0xC5, 0xDF, 0x11, 0x5F, 0xD7, 0x62, 0xC2, 0x5C, 0x27, 0xDD, 0xBB, 0x77, 0xFB, 0xE3, 
  0xFF, 0xF6, 0x42, 0x5C, 0x27, 0xDD, 0x3A, 0x75, 0x69, 0x3E, 0x12, 0xE1, 0x3E, 0x9A, 0x69, 0xDA, 
  0x4F, 0x84, 0xB8, 0x4F, 0xA4, 0x92, 0x56, 0x93, 0xE1, 0x2E, 0x8F, 0xDA, 0x1B, 0x97, 0x2E, 0x4B, 
  0xA9, 0x71, 0x71, 0xFE, 0x90, 0x8F, 0x42, 0x6C, 
};

static TYPE_GrData _Button_sat_Gd =
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

