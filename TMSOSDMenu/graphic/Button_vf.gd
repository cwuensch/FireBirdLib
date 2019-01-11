#include "tap.h"

static byte _Button_vf_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0x0A, 0x7B, 0x52, 0xFF, 0xFF, 0x07, 0x80, 
  0x01, 0x82, 0x62, 0x9E, 0xBD, 0xDA, 0xB4, 0xAA, 0xCF, 0xF0, 0x27, 0x53, 0x0B, 0x49, 0x4E, 0xD5, 
  0x8D, 0x6D, 0xB3, 0xEC, 0xEF, 0x68, 0x18, 0xB8, 0x11, 0xE3, 0x48, 0x3C, 0x4A, 0x16, 0xA2, 0x45, 
  0xF6, 0xDE, 0xF3, 0x8F, 0x70, 0x60, 0x76, 0x1E, 0x1B, 0x56, 0x62, 0xBC, 0x11, 0x06, 0x87, 0x82, 
  0x04, 0xB8, 0x10, 0x8B, 0x86, 0x28, 0x27, 0x81, 0x22, 0x68, 0x2E, 0x35, 0x28, 0x49, 0x53, 0x22, 
  0x65, 0xE3, 0x44, 0x10, 0x41, 0x14, 0x50, 0x46, 0x63, 0xF3, 0xFF, 0xFB, 0xCF, 0xBE, 0x8B, 0xE8, 
  0xD8, 0x1E, 0x1B, 0x9E, 0xE4, 0xB8, 0x6E, 0x7B, 0xB2, 0xE0, 0xB8, 0x70, 0x6C, 0xC1, 0x66, 0xDA, 
  0x9B, 0xBA, 0xC3, 0x87, 0xCA, 0x34, 0x68, 0x97, 0xFC, 0xD8, 0x71, 0x78, 0xDB, 0x6D, 0x95, 0x72, 
  0x17, 0xE7, 0xCF, 0x9E, 0x55, 0xC8, 0x5F, 0x9D, 0x3A, 0x71, 0x57, 0x21, 0x7D, 0xA6, 0x9A, 0x20, 
  0x7C, 0x1D, 0xD6, 0x8B, 0xC3, 0xDE, 0x68, 0xB1, 0x27, 0xB9, 0x3D, 0x42, 0xDD, 0x07, 0x2F, 0xD0, 
  0xED, 0xB8, 0x44, 0x7C, 0x67, 0x0E, 0x6F, 0xDB, 0x4C, 0x2F, 0xAE, 0xBA, 0xE4, 0x0F, 0xCB, 0x25, 
  0x92, 0xFA, 0xEA, 0x4B, 0x2D, 0xCA, 0x52, 0xC9, 0x96, 0x1C, 0xA6, 0xE9, 0xC3, 0xC2, 0x92, 0x76, 
  0xC1, 0xF5, 0xE3, 0xB0, 0x5A, 0x19, 0x4C, 0xA2, 0x7A, 0x87, 0x1F, 0x16, 0x52, 0x35, 0xC2, 0xFC, 
  0x89, 0x12, 0x08, 0x1F, 0x16, 0x25, 0xF2, 0x30, 0xFC, 0x7D, 0xFB, 0xE2, 0x76, 0xB8, 0x3E, 0x8C, 
  0x6B, 0xF3, 0xAF, 0xC1, 0xC2, 0x66, 0x35, 0xD9, 0x2F, 0x9F, 0xB2, 0x51, 0xCF, 0xF4, 0xA7, 0x2C, 
  0xA9, 0xFC, 0x18, 0x49, 0x08, 0xEE, 0xEB, 0x85, 0xF5, 0x96, 0x58, 0x81, 0xBC, 0xBC, 0x58, 0xB6, 
  0x73, 0x9C, 0xE2, 0xF9, 0x99, 0x18, 0x04, 0xED, 0x70, 0x75, 0x72, 0xDC, 0x4F, 0xA5, 0xEE, 0x92, 
  0x73, 0xE6, 0xE4, 0xAE, 0x73, 0xED, 0x67, 0xB2, 0x9C, 0x7A, 0x84, 0x2F, 0xF4, 0xA3, 0xC7, 0x27, 
  0x8F, 0x1E, 0x19, 0xC6, 0x6E, 0xE8, 0xF5, 0xF7, 0xB4, 0x99, 0x27, 0xDC, 0xEB, 0x23, 0xA7, 0x75, 
  0xD4, 0xE7, 0xA3, 0xAB, 0xCC, 0x5D, 0x53, 0xA7, 0xEF, 0xF3, 0xAC, 0x73, 0xED, 0xE7, 0xCA, 0x2E, 
  0xD7, 0x5A, 0x1A, 0x4F, 0x32, 0xCE, 0xC4, 0xF0, 0xC2, 0xB8, 0x5F, 0x8E, 0xAA, 0xA8, 0x5F, 0xB9, 
  0xB8, 0x7C, 0x84, 0xB9, 0xAC, 0x47, 0x4B, 0x9E, 0xED, 0x26, 0x0B, 0x9B, 0x69, 0xCA, 0x4A, 0xFF, 
  0x19, 0x52, 0x15, 0xA1, 0xE1, 0x85, 0x70, 0xBF, 0x1A, 0x34, 0x64, 0x2F, 0x83, 0xA3, 0xED, 0xEC, 
  0x1E, 0x3E, 0x5F, 0xAA, 0xF4, 0xAC, 0x79, 0x3C, 0x82, 0xD7, 0xF8, 0xE0, 0x1C, 0xFE, 0x9F, 0x25, 
  0xDA, 0x30, 0xDD, 0x5F, 0x1D, 0x9F, 0x23, 0xCB, 0xD5, 0x49, 0xE8, 0x3E, 0xB3, 0x3C, 0x30, 0xAE, 
  0x17, 0xED, 0xE2, 0xC5, 0x4A, 0xFF, 0x72, 0x65, 0xC3, 0x9F, 0x65, 0xE9, 0xB9, 0xD0, 0xDD, 0xE2, 
  0xF7, 0xB7, 0x70, 0x6A, 0xAF, 0xEC, 0x66, 0xAE, 0x9D, 0xBF, 0xB9, 0x0A, 0xE1, 0x7E, 0x2A, 0x8A, 
  0x26, 0xBF, 0x45, 0xFF, 0x2C, 0xB7, 0xE9, 0xE0, 0xF1, 0x7E, 0x55, 0xB0, 0x7E, 0xFA, 0xD9, 0x97, 
  0xE7, 0xD2, 0xFF, 0x6B, 0xE1, 0x5C, 0x2F, 0xA9, 0x6D, 0x6D, 0x56, 0xDE, 0x57, 0x9B, 0xF1, 0xF2, 
  0xFE, 0x2D, 0x0B, 0x94, 0xDF, 0xFD, 0x2F, 0x85, 0x70, 0xBF, 0x12, 0x24, 0x4A, 0xB6, 0xE4, 0xF5, 
  0xD4, 0x4A, 0xFF, 0x4D, 0x5B, 0x5F, 0xE2, 0xF8, 0x57, 0x0B, 0xF0, 0xE1, 0xC3, 0xFC, 0xE1, 0xFF, 
  0x48, 0x57, 0x0B, 0xF0, 0xA1, 0x42, 0xAC, 0xBE, 0x15, 0xC2, 0xFC, 0x18, 0x30, 0x6B, 0x2F, 0x85, 
  0x70, 0xBE, 0xFD, 0xFB, 0xFA, 0xCB, 0xE1, 0x5D, 0xDF, 0xF6, 0x1B, 0xE7, 0xAF, 0x4B, 0xFC, 0x60, 
  0x40, 0x80, 0x85, 0xB0, 
};

static TYPE_GrData _Button_vf_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_vf_Cpm,                 //data
  1920,                           //size
    24,                           //width
    20                            //height
};

