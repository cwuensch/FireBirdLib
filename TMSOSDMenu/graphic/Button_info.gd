#include "tap.h"

static byte _Button_info_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0xF7, 0x1A, 0x94, 0xFF, 0xFF, 0x07, 0x80, 
  0x01, 0x9B, 0x62, 0xBA, 0xEE, 0x11, 0xA5, 0x56, 0x7E, 0x04, 0xEE, 0x65, 0x93, 0x6F, 0x02, 0xE7, 
  0x63, 0x8D, 0xDB, 0x9E, 0xD6, 0x76, 0x4B, 0x09, 0x52, 0x62, 0x42, 0x48, 0xED, 0x98, 0xAE, 0x20, 
  0x51, 0xE3, 0x76, 0xDB, 0x68, 0xE2, 0x43, 0x86, 0xC1, 0x68, 0x2F, 0x03, 0xA9, 0x2A, 0xC4, 0x60, 
  0xA4, 0x2A, 0xBC, 0x30, 0x6F, 0x05, 0x14, 0x15, 0x04, 0x41, 0x50, 0x8A, 0x3E, 0x15, 0x43, 0x22, 
  0x99, 0x57, 0x67, 0xC1, 0x78, 0xE2, 0x08, 0xBC, 0x35, 0x21, 0x1B, 0xF6, 0xFF, 0xAB, 0x7A, 0x6F, 
  0x07, 0x21, 0xD1, 0x71, 0x0F, 0x82, 0x0E, 0xF8, 0x11, 0x78, 0xEF, 0x0C, 0x1B, 0x28, 0x63, 0x04, 
  0x6D, 0x1A, 0xDA, 0xBF, 0x27, 0xCF, 0x9E, 0x3F, 0xDB, 0x6D, 0xF7, 0xE4, 0xE9, 0xD3, 0x85, 0xAD, 
  0x23, 0xF3, 0x66, 0xCD, 0x16, 0xB4, 0x8F, 0xAC, 0xB2, 0xC1, 0xAD, 0xEB, 0xF5, 0x16, 0x15, 0x33, 
  0xD5, 0x1F, 0x2A, 0x72, 0x86, 0xB7, 0xA9, 0x56, 0x25, 0x91, 0xF9, 0x72, 0xE5, 0x86, 0xB7, 0xC1, 
  0x9A, 0xA8, 0x15, 0x63, 0x8D, 0xDD, 0x99, 0x23, 0x6B, 0x3B, 0x9C, 0xC4, 0xB2, 0x3E, 0x9A, 0x69, 
  0x86, 0xB7, 0x9E, 0xAC, 0x61, 0xDD, 0xEC, 0xC9, 0x14, 0x33, 0x24, 0x09, 0x8B, 0x28, 0xC4, 0xB2, 
  0x3E, 0x92, 0x49, 0x0B, 0x5A, 0x47, 0xD1, 0x45, 0x11, 0xFA, 0xD8, 0xB1, 0x11, 0x1D, 0x15, 0x92, 
  0x14, 0x7B, 0x58, 0xE3, 0xD9, 0xE1, 0x8C, 0x33, 0x7A, 0xD8, 0xC2, 0x27, 0xEE, 0xB9, 0x1F, 0x83, 
  0x02, 0x00, 0x6C, 0xD9, 0xB7, 0xE3, 0x78, 0x37, 0x3C, 0x01, 0x0F, 0x88, 0x68, 0xF1, 0x76, 0xE2, 
  0x0D, 0x1F, 0x1A, 0x43, 0xE9, 0x4E, 0x40, 0xAD, 0xB9, 0x1C, 0x79, 0x3B, 0x91, 0x57, 0xA7, 0x67, 
  0x48, 0xB9, 0x1F, 0x81, 0x7F, 0x7E, 0xBC, 0x3C, 0xBC, 0xAC, 0x21, 0xEB, 0xA3, 0xCC, 0x19, 0x2A, 
  0x70, 0xC6, 0x24, 0x33, 0x87, 0xC7, 0x55, 0x41, 0xF3, 0xD8, 0x50, 0x2A, 0x9C, 0x26, 0x4F, 0x91, 
  0x72, 0x3E, 0xFD, 0xFB, 0xFD, 0xE8, 0x68, 0x5D, 0x83, 0x8D, 0x71, 0x63, 0xE7, 0xD8, 0xE9, 0x61, 
  0x81, 0x5F, 0xAE, 0xE9, 0x7A, 0x31, 0x83, 0xBB, 0xD7, 0x0C, 0x9F, 0x22, 0xE4, 0x7F, 0x84, 0xF9, 
  0xF3, 0x32, 0xDD, 0x39, 0x6E, 0x35, 0xFD, 0x38, 0xF6, 0x0F, 0xE5, 0xF4, 0x21, 0xB3, 0x3C, 0xB4, 
  0x8B, 0x91, 0xF7, 0xC8, 0x20, 0xCC, 0xBC, 0x95, 0x30, 0x46, 0xED, 0x7F, 0x0B, 0xFC, 0x29, 0x46, 
  0x10, 0xA0, 0xBA, 0xDF, 0x3E, 0x45, 0xC8, 0xFA, 0x17, 0xD7, 0xCC, 0x47, 0xB7, 0xB7, 0x30, 0x79, 
  0x7B, 0xD8, 0xB6, 0x3A, 0xEE, 0x8D, 0x04, 0x77, 0xCD, 0x96, 0x91, 0x72, 0x3E, 0x79, 0xE7, 0xEF, 
  0x1B, 0x30, 0xC1, 0x83, 0x80, 0xE8, 0x7B, 0x74, 0x32, 0x05, 0x6A, 0xB2, 0x06, 0x2E, 0x27, 0xDB, 
  0xA2, 0xF9, 0x7C, 0x93, 0xC2, 0x38, 0x67, 0x87, 0x0D, 0xEE, 0x57, 0xB6, 0x45, 0xC8, 0xFB, 0xD7, 
  0xAF, 0x57, 0x86, 0xE1, 0xBD, 0xC0, 0xEA, 0xCC, 0xC2, 0x15, 0xAA, 0x48, 0x1F, 0x5D, 0xB9, 0x55, 
  0xFC, 0x4F, 0x08, 0x50, 0xE9, 0xF1, 0xC7, 0x9F, 0xBF, 0xCA, 0x11, 0x79, 0x08, 0x0B, 0xAB, 0xAB, 
  0x85, 0xED, 0x91, 0x72, 0x3E, 0x71, 0xC7, 0x30, 0x7F, 0x32, 0x67, 0x14, 0x7B, 0xF5, 0x13, 0x1E, 
  0xED, 0x2C, 0x81, 0xA7, 0xE6, 0xE6, 0x89, 0xD9, 0x5C, 0x61, 0x05, 0xF5, 0xD8, 0x30, 0xCF, 0xCF, 
  0x87, 0xC8, 0xB9, 0x1F, 0x78, 0xF1, 0xE7, 0xF3, 0xCA, 0x6D, 0x69, 0x17, 0x23, 0xEE, 0xDD, 0xBB, 
  0xFF, 0x9F, 0x22, 0xF6, 0x7F, 0xB0, 0xCD, 0x34, 0xD0, 0xE6, 0xF2, 0xF3, 0xFB, 0xA4, 0x3E, 0xC9, 
  0xB0, 
};

TYPE_GrData _Button_info_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_info_Cpm,               //data
  1920,                           //size
    24,                           //width
    20                            //height
};

