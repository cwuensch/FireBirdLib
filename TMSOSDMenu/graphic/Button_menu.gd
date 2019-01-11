#include "tap.h"

static byte _Button_menu_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0x4D, 0x91, 0xE8, 0xFF, 0xFF, 0x0C, 0x80, 
  0x01, 0x92, 0x63, 0x9C, 0xF0, 0xEE, 0xAD, 0x9C, 0xB6, 0xF8, 0x09, 0xBC, 0xCE, 0x1C, 0x92, 0xCB, 
  0x2D, 0xB6, 0xDB, 0xAE, 0xA8, 0x91, 0xC1, 0xA1, 0xC0, 0x12, 0x35, 0x22, 0x14, 0x8C, 0x3D, 0xAD, 
  0xD5, 0x2B, 0x92, 0xA2, 0x44, 0xAD, 0xB8, 0x77, 0xB8, 0x8B, 0x99, 0xC0, 0x44, 0x10, 0x9A, 0x01, 
  0x26, 0xE0, 0x46, 0xD9, 0x12, 0x31, 0x88, 0x70, 0x18, 0x5D, 0x04, 0x22, 0x07, 0x29, 0x22, 0x4C, 
  0xD2, 0x38, 0x93, 0xFE, 0xFB, 0xFE, 0xBF, 0x59, 0x3F, 0x7A, 0x4B, 0xB8, 0x3D, 0x22, 0xC9, 0xBB, 
  0x52, 0x38, 0x77, 0xC1, 0xD3, 0x85, 0xC6, 0xE1, 0xB2, 0x5D, 0xE0, 0xEC, 0x6A, 0x29, 0xBD, 0xEB, 
  0x8D, 0x1F, 0xD5, 0x2A, 0x54, 0x67, 0xFE, 0x6E, 0x3F, 0x3F, 0x9D, 0x75, 0xD6, 0x5B, 0x91, 0x3F, 
  0x4E, 0x9D, 0x36, 0x5B, 0x91, 0x3F, 0x4A, 0x95, 0x26, 0x5B, 0x91, 0x3F, 0x46, 0x8D, 0x16, 0x5B, 
  0x91, 0x3E, 0xE3, 0x8E, 0x31, 0x67, 0x97, 0xC7, 0x9C, 0xCF, 0x97, 0x8A, 0x83, 0x64, 0xC6, 0x95, 
  0xFC, 0xF9, 0x58, 0x0D, 0xA6, 0x7B, 0xB0, 0x1D, 0x47, 0xA5, 0x7F, 0x6F, 0x7A, 0x83, 0xC6, 0xD0, 
  0xBE, 0x46, 0x34, 0xF7, 0xB5, 0xB4, 0x1E, 0x57, 0xB0, 0x8B, 0x13, 0xF3, 0x66, 0xCD, 0x62, 0xCF, 
  0x4B, 0x95, 0xBF, 0x67, 0xE3, 0xDD, 0xC1, 0x6C, 0xE5, 0xF5, 0xDC, 0xAF, 0x5D, 0x29, 0xFC, 0x3C, 
  0x33, 0xDE, 0x0F, 0xF5, 0xF4, 0x50, 0x6D, 0x32, 0x71, 0x5D, 0xBE, 0x78, 0xFE, 0x17, 0x13, 0x7A, 
  0xD1, 0x69, 0x7C, 0xC7, 0xDF, 0xEC, 0x38, 0xDB, 0x60, 0x75, 0xD1, 0xCA, 0xF6, 0x11, 0x62, 0x7E, 
  0x64, 0xC9, 0x8C, 0x59, 0xE7, 0x72, 0x37, 0x95, 0xF5, 0xFF, 0x66, 0x5D, 0xFE, 0x95, 0x3F, 0x7E, 
  0x64, 0xE7, 0xA9, 0xF7, 0x7A, 0xBB, 0xEB, 0x27, 0xFC, 0xD9, 0x2E, 0x36, 0xD8, 0x4D, 0x0B, 0x83, 
  0xCB, 0x60, 0x7D, 0x3D, 0x1C, 0x91, 0x3F, 0xAC, 0x97, 0x2D, 0x90, 0x20, 0x40, 0xAF, 0x3C, 0x5E, 
  0x16, 0xB5, 0xA3, 0xF3, 0xEA, 0xCE, 0x66, 0x87, 0xA6, 0x7B, 0x69, 0xE3, 0xF3, 0x36, 0x8D, 0xC6, 
  0x57, 0xCE, 0xCA, 0x9A, 0xF0, 0x7E, 0xA6, 0x2E, 0xC9, 0xF3, 0xFF, 0x6C, 0xE9, 0xCC, 0xF9, 0xF9, 
  0x38, 0x0D, 0xA6, 0x13, 0x42, 0xE0, 0xF2, 0xF8, 0x1F, 0x4F, 0x47, 0x12, 0xE2, 0x7E, 0x5D, 0xDD, 
  0xDB, 0xFA, 0xFD, 0x5C, 0x9A, 0xDD, 0xA7, 0x7F, 0xBA, 0x90, 0xCF, 0x57, 0x73, 0x76, 0xCF, 0x2F, 
  0x67, 0x72, 0xFA, 0x7D, 0x65, 0x6B, 0xF6, 0xB9, 0xFB, 0x56, 0xFB, 0xC4, 0xE3, 0x5E, 0x6A, 0x27, 
  0xC4, 0xB8, 0x9F, 0x95, 0x2A, 0x53, 0xE9, 0xF3, 0x57, 0x3D, 0xE4, 0x74, 0x2B, 0x6C, 0xFC, 0xD7, 
  0x76, 0x0F, 0xA7, 0xC5, 0xD9, 0xAD, 0x9C, 0xC6, 0xB5, 0xCF, 0x7F, 0x4C, 0xD7, 0x19, 0x99, 0xD6, 
  0xDB, 0xEA, 0x27, 0xC4, 0xB8, 0x9F, 0xBA, 0x93, 0x25, 0xF4, 0xF9, 0xEF, 0xE3, 0xE0, 0xBE, 0x67, 
  0xDF, 0xD7, 0x80, 0xDC, 0xFB, 0x3D, 0x7C, 0x1F, 0xDF, 0x6F, 0x87, 0xF1, 0xB1, 0x36, 0x2D, 0xC6, 
  0x68, 0xE8, 0x9F, 0x18, 0xEA, 0x9F, 0x47, 0xB8, 0x2D, 0x50, 0xE2, 0x5C, 0x4F, 0xC9, 0x91, 0x22, 
  0xCE, 0xBF, 0xDB, 0xE8, 0xDE, 0xB7, 0x1A, 0x7C, 0x47, 0xFE, 0x27, 0xE3, 0xC3, 0xD5, 0x57, 0xEF, 
  0xB4, 0x4F, 0xE1, 0xF0, 0xF5, 0xD5, 0xBF, 0x81, 0xBE, 0x9E, 0xD9, 0xB9, 0xCE, 0x5F, 0x55, 0x7A, 
  0x48, 0x97, 0x13, 0xF2, 0x23, 0xC7, 0xB3, 0xAF, 0xA7, 0x71, 0x8A, 0x7F, 0xD2, 0x7D, 0x64, 0x26, 
  0xA7, 0xC2, 0x76, 0x3E, 0x5B, 0x92, 0x77, 0xBA, 0x97, 0x33, 0xAA, 0x0C, 0x91, 0x2E, 0x27, 0xE3, 
  0x46, 0x8C, 0xF5, 0x73, 0xB1, 0xCF, 0x81, 0x67, 0xB1, 0xFE, 0x74, 0x79, 0xF4, 0x8D, 0x3A, 0x6F, 
  0x93, 0x83, 0x78, 0xF0, 0x75, 0x92, 0x9A, 0x9F, 0x03, 0x86, 0xCC, 0xE8, 0x5D, 0x0D, 0xF8, 0xF1, 
  0xF7, 0x0D, 0x59, 0xE6, 0xE8, 0xAF, 0xD0, 0x5A, 0xC8, 0x97, 0x13, 0xF1, 0x62, 0xC5, 0xD2, 0xB7, 
  0xFD, 0x91, 0x2E, 0x27, 0xE2, 0x44, 0x89, 0x69, 0x3E, 0x25, 0xC4, 0xFC, 0x38, 0x70, 0xED, 0x27, 
  0xC4, 0xB8, 0x9F, 0x83, 0x06, 0x0D, 0xA4, 0xF8, 0x97, 0x4F, 0xF6, 0x87, 0x0A, 0x14, 0x26, 0x6A, 
  0xEE, 0x6E, 0x7F, 0xD2, 0x23, 0xD1, 0x36, 
};

static TYPE_GrData _Button_menu_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_menu_Cpm,               //data
  3200,                           //size
    40,                           //width
    20                            //height
};

