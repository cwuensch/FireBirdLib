#include "tap.h"

static byte _Button_option_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0xAD, 0x61, 0xDC, 0xFF, 0xFF, 0x0C, 0x80, 
  0x01, 0xF2, 0x62, 0x9B, 0xEE, 0xAD, 0x2C, 0xB3, 0xF0, 0x27, 0x6C, 0xE8, 0xA1, 0x1A, 0x71, 0x6B, 
  0x1B, 0x6C, 0xFB, 0x59, 0xD0, 0xCD, 0xC3, 0xA6, 0xAA, 0x8A, 0x0F, 0x32, 0xAD, 0xB5, 0x5B, 0x67, 
  0xD6, 0xDE, 0x36, 0xC3, 0xC1, 0x2E, 0xA2, 0x0B, 0x48, 0x43, 0xB3, 0x54, 0xBA, 0xA9, 0xAB, 0x34, 
  0x11, 0x1A, 0x68, 0x96, 0xA1, 0x04, 0xA9, 0x62, 0x20, 0x86, 0xA3, 0x41, 0x32, 0x68, 0x19, 0x8B, 
  0x86, 0xE1, 0xAE, 0x29, 0x07, 0x86, 0x9A, 0x23, 0xF7, 0xBF, 0x7F, 0xCF, 0xFC, 0x9E, 0xF4, 0x3E, 
  0x4D, 0xE8, 0x90, 0xB8, 0x5E, 0x3B, 0x82, 0xE4, 0xAE, 0x7B, 0x92, 0xE8, 0x7E, 0x00, 0x5F, 0x02, 
  0xEE, 0x3B, 0x85, 0x0D, 0xBC, 0x18, 0xA9, 0xB5, 0xA0, 0xEA, 0x04, 0x3F, 0x47, 0x8F, 0x1C, 0x3F, 
  0xF3, 0x41, 0x93, 0xFA, 0x34, 0x68, 0xC1, 0x3E, 0x45, 0x3F, 0x12, 0x24, 0x40, 0x9F, 0x22, 0x9F, 
  0x87, 0x0E, 0x18, 0x4F, 0x91, 0x4F, 0xC2, 0x85, 0x08, 0x3E, 0xD3, 0x65, 0xBC, 0x84, 0x16, 0xF1, 
  0x60, 0x84, 0x9E, 0x64, 0x10, 0xE3, 0xDA, 0xC1, 0x08, 0x76, 0x39, 0x94, 0x62, 0x39, 0x66, 0xD9, 
  0x0A, 0xBB, 0x4B, 0x38, 0x41, 0xBF, 0xDE, 0xE5, 0x1F, 0xBE, 0xB2, 0xF9, 0xD1, 0xE5, 0xCC, 0x5B, 
  0x3F, 0xA6, 0xEC, 0x53, 0xE7, 0x1C, 0x70, 0x7D, 0x67, 0xA9, 0x21, 0xF8, 0x64, 0x62, 0xC0, 0x0F, 
  0x97, 0xA7, 0x2A, 0x7D, 0xD8, 0x90, 0x02, 0x4D, 0xC3, 0xE4, 0xA9, 0xD1, 0x3D, 0x19, 0x95, 0x7C, 
  0x78, 0x1E, 0xFC, 0xE0, 0xB8, 0xE1, 0xBE, 0xCD, 0xA3, 0x19, 0xC3, 0xC0, 0x3D, 0x4D, 0xF8, 0xA7, 
  0xDC, 0xB9, 0x72, 0x13, 0xA6, 0x47, 0x19, 0xE1, 0x2E, 0xFE, 0x3E, 0x88, 0x01, 0x7F, 0x74, 0x70, 
  0x73, 0xAD, 0x9E, 0x07, 0x6B, 0xA5, 0x5E, 0x1F, 0x0C, 0x95, 0x78, 0x9E, 0x5A, 0xB2, 0xE9, 0xFA, 
  0xFC, 0xF7, 0xA4, 0x9E, 0xF5, 0xD9, 0xD3, 0x5A, 0xFD, 0x1E, 0x53, 0xC0, 0xB1, 0xB0, 0xDC, 0x05, 
  0xDD, 0xCB, 0xD2, 0x4E, 0x0F, 0x63, 0x76, 0x41, 0xFD, 0x72, 0x8F, 0x9A, 0x1F, 0x26, 0x33, 0xB5, 
  0x10, 0x62, 0x9F, 0x34, 0xD3, 0x43, 0x2E, 0x6B, 0x2B, 0x0D, 0x0C, 0x79, 0x67, 0x93, 0x0F, 0x1F, 
  0x84, 0xE5, 0x22, 0xF8, 0x9C, 0x1D, 0xB9, 0x07, 0xC6, 0xC3, 0x3C, 0x2B, 0xAB, 0x6A, 0x88, 0x19, 
  0x53, 0xE5, 0xF7, 0x19, 0xBC, 0xB9, 0xDD, 0x10, 0x3F, 0x15, 0xED, 0x7A, 0x57, 0xF6, 0xB1, 0x26, 
  0x5F, 0xF9, 0x3B, 0x27, 0x04, 0xED, 0xDA, 0x32, 0x29, 0xFD, 0x53, 0x76, 0xE0, 0xA9, 0x52, 0xA4, 
  0xA7, 0x6B, 0xAE, 0xD4, 0x13, 0x07, 0xEC, 0x94, 0xF4, 0x15, 0xAB, 0x54, 0x99, 0xFE, 0xAC, 0x17, 
  0x64, 0x3D, 0xC5, 0x42, 0xE2, 0x7B, 0x95, 0x3F, 0xA4, 0xD1, 0xD0, 0xCD, 0xA3, 0x91, 0x16, 0xA4, 
  0x81, 0xC9, 0xB7, 0xD8, 0x25, 0x76, 0xEE, 0xAD, 0x99, 0x07, 0xEE, 0xDD, 0x1A, 0x9E, 0x5D, 0x19, 
  0x14, 0xB8, 0xA7, 0xDB, 0xD3, 0x53, 0x26, 0x59, 0xEE, 0x8C, 0x26, 0x0F, 0xC3, 0xD6, 0xAB, 0x52, 
  0xEF, 0xBF, 0xD5, 0xDB, 0x10, 0xF7, 0xE8, 0x53, 0xA2, 0x9F, 0xE9, 0xF2, 0x36, 0x21, 0x79, 0xCB, 
  0xD9, 0x87, 0x81, 0x0B, 0x72, 0x87, 0xB9, 0xAA, 0x67, 0xFA, 0x4F, 0x8A, 0x5C, 0x53, 0xED, 0x9B, 
  0x36, 0x4C, 0xB7, 0x46, 0xB2, 0x26, 0x0F, 0x0A, 0xFA, 0xB9, 0x4B, 0xBF, 0x1D, 0xED, 0x69, 0x0F, 
  0x1D, 0x5A, 0x29, 0xF4, 0x67, 0xDB, 0x84, 0x70, 0x70, 0x2C, 0x29, 0xD3, 0xBB, 0xFB, 0xA7, 0xC5, 
  0x2E, 0x29, 0xFD, 0x4B, 0x56, 0xB9, 0x8B, 0xB3, 0x28, 0xC9, 0x83, 0xC7, 0x96, 0xF8, 0x28, 0xE8, 
  0x96, 0xA4, 0x58, 0xFD, 0x87, 0x8D, 0xE5, 0x99, 0xCE, 0x3A, 0x76, 0xDA, 0x54, 0x93, 0xF5, 0x0D, 
  0xF4, 0xC0, 0x63, 0x2A, 0x24, 0xEC, 0xFF, 0x29, 0xF1, 0x4B, 0x8A, 0x7D, 0xA9, 0x86, 0x26, 0x5A, 
  0xC5, 0x8A, 0xC2, 0x5F, 0x6E, 0x67, 0x65, 0xFA, 0x1C, 0x5D, 0x79, 0x3D, 0xCA, 0x5F, 0x36, 0xD3, 
  0x5A, 0x41, 0xFC, 0xD7, 0xEE, 0x66, 0x8F, 0x3B, 0x8F, 0xFF, 0xB4, 0xF8, 0xA5, 0xC5, 0x3E, 0x65, 
  0x2D, 0x2A, 0x87, 0xEC, 0x9C, 0x69, 0xC3, 0xDF, 0xE7, 0x99, 0xDC, 0x3C, 0x4E, 0xE3, 0xA2, 0x71, 
  0x5C, 0x52, 0x63, 0xEF, 0x91, 0x8A, 0x78, 0x6D, 0x2A, 0x57, 0xCD, 0xAB, 0xCF, 0x4F, 0x8A, 0x5C, 
  0x53, 0xED, 0x1A, 0x34, 0xCD, 0xA3, 0xD6, 0x21, 0xF5, 0x78, 0xF4, 0x8C, 0xAA, 0x71, 0x4B, 0x8F, 
  0x1E, 0xDC, 0x6A, 0xD7, 0x25, 0x4F, 0x9E, 0x9F, 0x14, 0xB8, 0xA7, 0xD9, 0xB3, 0x67, 0x9D, 0x93, 
  0x5B, 0x42, 0xAC, 0x1A, 0xA1, 0xC5, 0x7D, 0x12, 0xD5, 0x99, 0xD5, 0x7F, 0xC9, 0x14, 0xB8, 0xA7, 
  0xD9, 0x32, 0x65, 0xFD, 0xD9, 0xFE, 0x24, 0x52, 0xE2, 0x9F, 0x62, 0xC5, 0x8E, 0x82, 0x7C, 0x52, 
  0xE2, 0x9F, 0x5E, 0xBD, 0x7E, 0x82, 0x7C, 0x52, 0xE5, 0xFE, 0xD0, 0xD8, 0x30, 0x60, 0x0B, 0xA9, 
  0x29, 0x3F, 0xD2, 0x28, 0xF2, 0xA6, 0xC0, 
};

static TYPE_GrData _Button_option_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_option_Cpm,             //data
  3200,                           //size
    40,                           //width
    20                            //height
};

