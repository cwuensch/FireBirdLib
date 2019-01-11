#include "tap.h"

static byte _Button_mute_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0x60, 0x73, 0x77, 0xFF, 0xFF, 0x07, 0x80, 
  0x00, 0xEB, 0x62, 0x7A, 0xDA, 0xAA, 0xB5, 0x59, 0xC7, 0xDB, 0x52, 0x38, 0x9D, 0x7D, 0xFC, 0x11, 
  0x15, 0x7A, 0xB3, 0xD6, 0xD3, 0x16, 0x38, 0x72, 0x39, 0x26, 0x08, 0xFE, 0x6C, 0x8E, 0x47, 0x2B, 
  0x91, 0xC7, 0x16, 0x3B, 0x54, 0x44, 0x41, 0xD0, 0x8B, 0x44, 0x10, 0x44, 0x16, 0x3B, 0xC0, 0x5C, 
  0x72, 0xF5, 0x2F, 0x98, 0xF9, 0x0E, 0x20, 0xC0, 0xC0, 0xC0, 0xD8, 0x2C, 0x08, 0x59, 0x2F, 0x00, 
  0x76, 0x0B, 0x0C, 0x16, 0x60, 0xC4, 0x8C, 0xDB, 0x72, 0x9E, 0x3F, 0x53, 0x4D, 0x28, 0xFC, 0x95, 
  0x3C, 0xBE, 0xA2, 0x8A, 0x11, 0xFD, 0x20, 0xFC, 0xF3, 0xCE, 0x8B, 0xE7, 0xC3, 0xBF, 0xFF, 0x54, 
  0xE1, 0x47, 0x85, 0x38, 0x3F, 0x34, 0xD3, 0x23, 0x09, 0x2B, 0xB2, 0xCF, 0xDD, 0xD3, 0xC1, 0x54, 
  0xDF, 0xBE, 0x72, 0x0F, 0xCB, 0x2C, 0xA8, 0xC6, 0x48, 0x1F, 0x6F, 0x46, 0xFD, 0x72, 0x7A, 0xE2, 
  0x6E, 0xB7, 0x07, 0xE4, 0x92, 0x44, 0x63, 0x26, 0x1F, 0xB3, 0x56, 0xF5, 0x52, 0x7A, 0xF7, 0xDB, 
  0x83, 0xF1, 0xC7, 0x1A, 0x13, 0x3D, 0x7C, 0xFB, 0xB6, 0xC9, 0x0B, 0x4E, 0x7B, 0xAF, 0xCA, 0x41, 
  0xF8, 0xA2, 0x89, 0x09, 0x9E, 0xAE, 0x6D, 0xCB, 0x64, 0x6B, 0x9F, 0x23, 0x89, 0xBA, 0xEC, 0xE4, 
  0x1F, 0xD8, 0x86, 0x14, 0x2E, 0xBA, 0xF6, 0x4F, 0x2F, 0x16, 0xD2, 0x35, 0x71, 0xED, 0xD5, 0x8F, 
  0x5B, 0x36, 0x6A, 0xF1, 0xA4, 0xF9, 0x57, 0x8A, 0x34, 0x83, 0x05, 0xC1, 0xF8, 0x74, 0xE9, 0xB7, 
  0x6F, 0x93, 0x87, 0x67, 0xCC, 0xFA, 0x8A, 0x59, 0x8C, 0x8D, 0x8C, 0x69, 0xB7, 0x39, 0x05, 0xC1, 
  0xF8, 0x20, 0x83, 0x23, 0xF7, 0xF1, 0xFD, 0xD2, 0x0B, 0x83, 0xFA, 0xEF, 0xBF, 0xEA, 0x7C, 0x49, 
  0x63, 0x32, 0xE7, 0x9E, 0xF3, 0xE0, 0xB8, 0x3E, 0xFB, 0xCF, 0x7A, 0x1F, 0x2E, 0xC1, 0x96, 0x32, 
  0x36, 0x5A, 0xE6, 0x7D, 0x55, 0x55, 0xB4, 0x18, 0x2E, 0x0F, 0xBD, 0xA3, 0x47, 0xB7, 0x33, 0x9F, 
  0x45, 0xCB, 0x94, 0xD3, 0xD2, 0xFB, 0xAC, 0xC1, 0x70, 0x7D, 0xD7, 0x5D, 0xF8, 0x36, 0x5E, 0x2B, 
  0x97, 0x1F, 0x8F, 0x0C, 0xCF, 0xA6, 0x6B, 0x2C, 0xB5, 0x96, 0xE0, 0xB8, 0x3E, 0xE3, 0x8E, 0x64, 
  0x7C, 0xFA, 0x77, 0x8F, 0x89, 0xE0, 0xB8, 0x3E, 0xDB, 0x6D, 0xE4, 0x6F, 0xE6, 0x9C, 0x17, 0x07, 
  0xDA, 0x69, 0xAF, 0x7B, 0xFF, 0xA9, 0x05, 0xC1, 0xF6, 0x18, 0x63, 0xF4, 0xF8, 0x2E, 0x5F, 0xD8, 
  0x7F, 0xEC, 0xF9, 0xD1, 0xF7, 0x2C, 0xB2, 0xCD, 0x66, 0xC0, 
};

static TYPE_GrData _Button_mute_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_mute_Cpm,               //data
  1920,                           //size
    24,                           //width
    20                            //height
};

