#include "tap.h"

static byte _Button_aux_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x03, 0x36, 0xFC, 0xD2, 0xFF, 0xFF, 0x0C, 0x80, 
  0x02, 0x65, 0x6A, 0xBB, 0xEE, 0xAD, 0x2B, 0x96, 0x7E, 0x04, 0xAE, 0x55, 0x49, 0x95, 0x56, 0xC6, 
  0x36, 0xCB, 0xB2, 0xEC, 0x9E, 0xA5, 0x26, 0x06, 0x5A, 0x9A, 0x3B, 0x34, 0xAE, 0xCB, 0x79, 0xDB, 
  0x3B, 0x6C, 0xB8, 0x59, 0x2B, 0x54, 0xC2, 0xAB, 0x28, 0xE5, 0x99, 0xB2, 0x94, 0xE8, 0x91, 0x06, 
  0x15, 0x88, 0x19, 0x3D, 0x78, 0xF7, 0x95, 0xF2, 0xD3, 0x14, 0x26, 0xAA, 0x59, 0x91, 0x66, 0x55, 
  0x82, 0x22, 0x88, 0xAA, 0xB8, 0x4D, 0x45, 0x4D, 0x1F, 0xB7, 0xEF, 0xFF, 0xED, 0xDA, 0x7B, 0x17, 
  0x71, 0x74, 0x24, 0x13, 0x9F, 0x71, 0x6E, 0x25, 0xC4, 0x82, 0xF8, 0x51, 0xEE, 0x1D, 0xC1, 0x41, 
  0xDE, 0x0C, 0x64, 0xDA, 0x94, 0x73, 0xE3, 0xBF, 0xCE, 0x1C, 0x38, 0x0F, 0xDC, 0xBE, 0x7B, 0xFF, 
  0x37, 0x6E, 0xDC, 0x35, 0x24, 0x53, 0xF4, 0xD4, 0xD4, 0xC1, 0xA9, 0x22, 0x9F, 0x6C, 0xD9, 0xB0, 
  0x6A, 0x48, 0xA7, 0xDA, 0xB5, 0x6A, 0x1A, 0x53, 0x45, 0x42, 0xD4, 0x2C, 0x6B, 0x68, 0x09, 0x3B, 
  0xCA, 0x37, 0xA7, 0xD6, 0x54, 0x94, 0xFE, 0x03, 0x6F, 0x90, 0xF5, 0x74, 0xE5, 0x1F, 0x83, 0xBF, 
  0x6A, 0x14, 0x3F, 0x1C, 0x1F, 0xCE, 0x9E, 0xBB, 0x84, 0x52, 0xEA, 0x69, 0x5E, 0xE6, 0xC5, 0x3E, 
  0xC1, 0x83, 0x00, 0xD2, 0x97, 0x35, 0xEC, 0x43, 0xDD, 0xDC, 0x9F, 0x24, 0xF2, 0xF9, 0x0C, 0x8F, 
  0x3F, 0x1E, 0xFD, 0x99, 0x0B, 0x73, 0xC4, 0x62, 0x70, 0xFD, 0x6F, 0xF0, 0xA3, 0xDB, 0x71, 0x8A, 
  0x3E, 0x1F, 0xFA, 0x5F, 0xBE, 0x33, 0xBA, 0xF7, 0x94, 0x75, 0x14, 0x93, 0xC1, 0x9F, 0x9B, 0x3E, 
  0x1E, 0xD7, 0x73, 0x55, 0x4B, 0x3C, 0x7E, 0x6C, 0x53, 0xEB, 0x16, 0x2C, 0x0D, 0x29, 0xC5, 0xBD, 
  0xF8, 0x27, 0xFB, 0xCE, 0x99, 0x1E, 0x7F, 0x66, 0xF8, 0xA7, 0xD8, 0xD6, 0x7F, 0x27, 0x0E, 0xEB, 
  0x9D, 0x3C, 0x41, 0xED, 0x2C, 0x27, 0x49, 0xF7, 0x9F, 0x64, 0xB4, 0x33, 0xB2, 0x1A, 0x1D, 0x57, 
  0x95, 0x82, 0x5B, 0xBB, 0xCB, 0x75, 0xE8, 0x6E, 0xC5, 0x3E, 0x61, 0x86, 0x07, 0xD6, 0x58, 0xAE, 
  0x97, 0x23, 0x6F, 0xC9, 0x88, 0xC8, 0x3B, 0xEE, 0x8B, 0x8B, 0xE0, 0x51, 0xCC, 0x1D, 0x47, 0xD8, 
  0xBC, 0x5E, 0x41, 0xEB, 0xEA, 0x16, 0x1C, 0x3E, 0x15, 0xDA, 0xE2, 0x0F, 0x67, 0x5A, 0xB4, 0xD0, 
  0xF8, 0xED, 0xD6, 0x90, 0x3F, 0x36, 0x2B, 0x30, 0xB5, 0xE2, 0xCD, 0x93, 0xE7, 0xE2, 0xC3, 0x64, 
  0x13, 0x53, 0x3B, 0x74, 0x37, 0xE2, 0x9F, 0x8F, 0x56, 0xAC, 0x1F, 0x5F, 0x5F, 0x50, 0x9A, 0xCD, 
  0xF4, 0x81, 0x5D, 0xF4, 0xF2, 0x41, 0x57, 0xBD, 0xD7, 0x17, 0xB8, 0xEC, 0xA5, 0x4E, 0xA3, 0xE7, 
  0xDC, 0x18, 0x41, 0xD7, 0xCC, 0xC6, 0x1C, 0x3F, 0xF5, 0xC9, 0x96, 0x20, 0xFB, 0xB6, 0x0A, 0x8E, 
  0x1F, 0xA5, 0xCC, 0x97, 0x37, 0xA3, 0xC6, 0x66, 0x76, 0xA9, 0x50, 0xDD, 0x8A, 0x5C, 0x53, 0xEA, 
  0xD5, 0x2A, 0xD1, 0x4F, 0xF7, 0x7A, 0x7B, 0xA2, 0x60, 0xF5, 0xAA, 0xA1, 0x81, 0x3A, 0x4D, 0x53, 
  0xBE, 0x4B, 0x68, 0x1E, 0x8E, 0xD3, 0x20, 0x86, 0xD5, 0xC0, 0x7D, 0xD3, 0xF2, 0x0A, 0xE1, 0xCD, 
  0x4D, 0xDF, 0x5B, 0x6D, 0xB4, 0x77, 0x62, 0x97, 0x14, 0xFC, 0x74, 0x74, 0x72, 0x07, 0x99, 0x28, 
  0x90, 0x98, 0x3E, 0xDE, 0x02, 0xD0, 0x87, 0x85, 0x81, 0x24, 0xF5, 0x2E, 0xF7, 0x24, 0x0F, 0x7E, 
  0xD2, 0x3C, 0xDA, 0x7B, 0xD7, 0x7A, 0x31, 0x0D, 0x8A, 0xC5, 0x07, 0x5F, 0xFF, 0x76, 0x85, 0x4F, 
  0xD0, 0x6E, 0xA3, 0x4E, 0x1E, 0xCE, 0xAB, 0x60, 0x6A, 0x7F, 0xCB, 0x88, 0xC0, 0x11, 0xC4, 0xC1, 
  0xA1, 0xBF, 0x14, 0xB8, 0xA7, 0xE3, 0x54, 0xA9, 0x40, 0xFB, 0xA7, 0x3B, 0x33, 0xBA, 0x1F, 0x42, 
  0x71, 0xEF, 0x96, 0x1B, 0x4F, 0x73, 0x63, 0x2A, 0x5E, 0x27, 0x5F, 0x1C, 0x87, 0x7B, 0xCD, 0x98, 
  0x98, 0xD0, 0xE4, 0xE4, 0x62, 0x83, 0x3F, 0x31, 0xA1, 0x3A, 0x1F, 0x23, 0xFE, 0x58, 0x43, 0xC5, 
  0x8F, 0xF4, 0xDF, 0x8A, 0x5C, 0x53, 0xEA, 0x54, 0x28, 0x3C, 0xB8, 0x87, 0x7C, 0x57, 0xE9, 0xC9, 
  0x64, 0x1E, 0xCC, 0xB6, 0x84, 0xBF, 0xD0, 0x9C, 0xEC, 0x72, 0xFA, 0x4E, 0x3A, 0xB1, 0xAB, 0xB2, 
  0xA8, 0x92, 0x27, 0xDF, 0x02, 0xDC, 0xC3, 0x6F, 0xE1, 0x61, 0x20, 0x03, 0xC5, 0xD7, 0x2F, 0xA6, 
  0xFB, 0x29, 0x2D, 0x61, 0x03, 0x81, 0x80, 0x44, 0x19, 0x37, 0xE5, 0xF4, 0x7E, 0xD6, 0xBA, 0x4C, 
  0x14, 0xA6, 0x84, 0x0F, 0x3E, 0x41, 0x71, 0x6B, 0xA6, 0x22, 0xCF, 0x41, 0x8A, 0x5C, 0x53, 0xEA, 
  0x23, 0x23, 0x0F, 0x2C, 0x7A, 0xFC, 0x6D, 0xFA, 0x17, 0x26, 0x1E, 0x5F, 0x2A, 0xC3, 0x62, 0x42, 
  0xEE, 0x1C, 0x4A, 0x1B, 0xE2, 0x78, 0xF0, 0x78, 0x87, 0x9B, 0xD1, 0x9C, 0x0E, 0x73, 0xBF, 0x1D, 
  0xFC, 0x3D, 0x55, 0xC6, 0xFD, 0xD1, 0x22, 0x7E, 0x25, 0x3F, 0x0E, 0x92, 0x44, 0x81, 0xF8, 0x1D, 
  0x4E, 0x91, 0x7E, 0x21, 0xD3, 0xD1, 0x7F, 0x04, 0x0F, 0xC7, 0x86, 0xBC, 0x22, 0xA2, 0x20, 0x8E, 
  0xD3, 0x8A, 0x5C, 0x53, 0xF1, 0x71, 0x6F, 0x57, 0x78, 0xD7, 0xB3, 0x44, 0xB7, 0x69, 0x38, 0xF7, 
  0xBE, 0xE5, 0x35, 0xF1, 0x44, 0x2C, 0x79, 0x1D, 0xE6, 0x9E, 0x62, 0x59, 0x28, 0x66, 0x60, 0xCD, 
  0x93, 0xAE, 0xC4, 0xBF, 0x5E, 0x5B, 0x30, 0xC2, 0xBA, 0xDC, 0x02, 0xB5, 0x10, 0xA6, 0xB0, 0xFD, 
  0x59, 0x4C, 0xCF, 0xEE, 0xF7, 0xF7, 0xF7, 0xE0, 0xC6, 0xBC, 0x2E, 0xAF, 0x9A, 0xE7, 0x68, 0x76, 
  0x9C, 0x52, 0xE2, 0x9F, 0x4E, 0x9D, 0x3E, 0x8F, 0xA8, 0x7F, 0x69, 0x83, 0x82, 0x44, 0x4E, 0xB7, 
  0x80, 0x7F, 0x7E, 0xFC, 0x62, 0xC5, 0x2E, 0x29, 0xF4, 0xC9, 0x93, 0x7E, 0x53, 0xFF, 0xA9, 0x14, 
  0xB8, 0xA7, 0xD2, 0xA5, 0x4B, 0xA6, 0x9F, 0x14, 0xB8, 0xA7, 0xD1, 0xA3, 0x47, 0xA6, 0x9F, 0x14, 
  0xBB, 0xCF, 0xED, 0x0D, 0x22, 0x44, 0x81, 0x13, 0x11, 0x11, 0xFF, 0xC8, 0xA3, 0xDE, 0x26, 0xC0, 
};

TYPE_GrData _Button_aux_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_aux_Cpm,                //data
  3200,                           //size
    40,                           //width
    20                            //height
};

