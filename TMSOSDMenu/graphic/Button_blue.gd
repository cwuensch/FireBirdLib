#include "tap.h"

static byte _Button_blue_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x02, 0x8E, 0x6C, 0xB0, 0xFF, 0xFF, 0x05, 0x10, 
  0x02, 0x64, 0x62, 0xBA, 0xE1, 0xD1, 0xA5, 0x33, 0x7C, 0x0C, 0xE5, 0x8D, 0xDB, 0x67, 0x65, 0x17, 
  0x65, 0x6B, 0x39, 0x9C, 0xAC, 0xBA, 0x6A, 0x95, 0x45, 0x8A, 0x90, 0xD4, 0x24, 0x92, 0xD4, 0x20, 
  0xC1, 0x0E, 0x15, 0xAA, 0x42, 0x9A, 0x98, 0x15, 0x45, 0x25, 0xD9, 0xE7, 0x28, 0xAE, 0xD3, 0x96, 
  0xD2, 0x3B, 0x67, 0x6C, 0xAE, 0x74, 0xF6, 0x69, 0x8D, 0x9A, 0x49, 0x7A, 0x30, 0x48, 0x92, 0x59, 
  0x58, 0x2B, 0xC1, 0x25, 0x11, 0x5F, 0x03, 0xBF, 0x7F, 0x53, 0x96, 0x16, 0xD0, 0x94, 0x10, 0x45, 
  0x57, 0xAA, 0xF1, 0xB9, 0x42, 0xAD, 0x38, 0x2C, 0xB0, 0x90, 0x78, 0x7C, 0xF9, 0x42, 0x7A, 0x6D, 
  0x48, 0xBA, 0x5B, 0x4C, 0x33, 0x3C, 0x56, 0x62, 0x03, 0xFB, 0xB1, 0xA2, 0x42, 0xFD, 0xED, 0xA0, 
  0xEF, 0xDE, 0x2C, 0x14, 0x5C, 0xA9, 0x91, 0x09, 0xFD, 0xE5, 0x07, 0x16, 0x50, 0x3E, 0x77, 0xD8, 
  0x1F, 0x3F, 0x66, 0x00, 0xF9, 0x7B, 0x5B, 0x8F, 0x7E, 0x9B, 0x61, 0xA9, 0xA2, 0xD0, 0x6A, 0x69, 
  0x34, 0x1F, 0x0F, 0x5B, 0x62, 0x2E, 0xD8, 0x7C, 0x74, 0xD9, 0x0C, 0x76, 0xB5, 0x42, 0x6F, 0x87, 
  0x23, 0xF8, 0xC3, 0xF9, 0xD4, 0x4A, 0x86, 0x99, 0xB6, 0x03, 0xDD, 0xA1, 0x74, 0x20, 0x79, 0xCB, 
  0x1E, 0xA3, 0x57, 0x08, 0x06, 0xAD, 0x38, 0xAE, 0x3A, 0x75, 0xC3, 0x49, 0xFD, 0xB9, 0x28, 0xEE, 
  0x06, 0x7E, 0x55, 0x60, 0xE4, 0xF1, 0xE5, 0x36, 0xB0, 0xB9, 0xF9, 0xC4, 0xE3, 0x3D, 0xF7, 0x54, 
  0x40, 0xF3, 0x57, 0x0C, 0xE7, 0xBD, 0x91, 0x9C, 0xFB, 0xF4, 0x48, 0xFF, 0xA1, 0xF7, 0x68, 0x40, 
  0xCC, 0xED, 0x83, 0x71, 0xE9, 0xC7, 0x02, 0x5E, 0x3F, 0x5B, 0x0B, 0x28, 0xA4, 0x03, 0x09, 0x85, 
  0x08, 0xF4, 0xE5, 0x55, 0x0C, 0xD3, 0x16, 0x03, 0x4C, 0xA7, 0xD6, 0x7F, 0xFC, 0x73, 0x71, 0xD6, 
  0x0D, 0x07, 0xD5, 0x02, 0xF6, 0xD6, 0x80, 0x23, 0x89, 0x44, 0x25, 0x64, 0xE3, 0x03, 0xF3, 0x29, 
  0x07, 0x97, 0x0E, 0x8C, 0x79, 0x1C, 0xFF, 0xCE, 0x5E, 0x25, 0x20, 0x37, 0x1B, 0x98, 0x15, 0xF1, 
  0x93, 0x8A, 0x8A, 0x55, 0x23, 0x37, 0x11, 0x58, 0xC9, 0xC1, 0xA0, 0xDC, 0x26, 0xBA, 0x56, 0x2B, 
  0x7A, 0x53, 0x02, 0xDA, 0xB6, 0x5C, 0x3D, 0xC1, 0x9C, 0x06, 0x5F, 0xF1, 0x0E, 0x33, 0x50, 0x63, 
  0x9A, 0x82, 0x9F, 0xD5, 0x7C, 0xA6, 0xB3, 0xA2, 0xF2, 0xC5, 0x50, 0x63, 0x65, 0x2A, 0x32, 0x2F, 
  0xD5, 0x07, 0x6C, 0x66, 0x37, 0x0E, 0x4B, 0x39, 0x90, 0xCE, 0xD7, 0x7E, 0x2E, 0xEB, 0xD4, 0x07, 
  0x97, 0xB2, 0xA1, 0xD5, 0xE4, 0xA0, 0xC6, 0x21, 0x75, 0x04, 0xFE, 0x53, 0xD7, 0x5F, 0xC3, 0x7F, 
  0x2C, 0x19, 0x59, 0xC9, 0x0B, 0x0E, 0x9A, 0x60, 0x63, 0x14, 0xE3, 0x0E, 0xE7, 0x7A, 0x42, 0x9F, 
  0x58, 0xE2, 0x5C, 0xEB, 0xCE, 0x72, 0x77, 0x1F, 0x46, 0xF0, 0xF6, 0x5B, 0x22, 0xF9, 0x17, 0xB2, 
  0x21, 0x6F, 0x5E, 0x38, 0x73, 0x55, 0xA4, 0x06, 0x30, 0x4C, 0x1B, 0x96, 0x94, 0xE3, 0x1A, 0x71, 
  0xD9, 0x8F, 0x6C, 0xB8, 0x3A, 0xBD, 0xE3, 0x14, 0xC2, 0xA7, 0x9F, 0x14, 0x37, 0x91, 0xC8, 0x43, 
  0x92, 0xD1, 0x86, 0xEB, 0x92, 0x06, 0xCB, 0x62, 0x86, 0x12, 0xE8, 0xBD, 0xB3, 0x6D, 0xB6, 0x9E, 
  0xAD, 0x5B, 0x92, 0xD2, 0x06, 0xB6, 0xA8, 0xC4, 0xDA, 0xA4, 0x21, 0x02, 0x04, 0x43, 0xAD, 0x4C, 
  0x50, 0x77, 0x72, 0x50, 0x69, 0x68, 0x88, 0x39, 0x5E, 0x98, 0x39, 0xB7, 0xFE, 0x17, 0x16, 0xF1, 
  0xC4, 0xAB, 0x42, 0x4B, 0x33, 0xE1, 0x65, 0x19, 0x5B, 0x1B, 0x1B, 0x4B, 0x18, 0x84, 0x5C, 0x56, 
  0x43, 0x8C, 0x52, 0xCF, 0x07, 0x0B, 0xE3, 0xC9, 0xE3, 0xF9, 0x31, 0x8B, 0x74, 0xA0, 0x86, 0x48, 
  0xE2, 0xA3, 0x60, 0xEA, 0xB6, 0xE0, 0xB4, 0xC1, 0xD1, 0x70, 0xC3, 0xB9, 0xD4, 0x88, 0x09, 0x11, 
  0xA1, 0xDA, 0xDB, 0x1A, 0x79, 0x04, 0x01, 0x75, 0x5C, 0x28, 0x76, 0xBE, 0x20, 0x3C, 0x65, 0x2C, 
  0x0C, 0x65, 0xC1, 0x1E, 0x0E, 0xEA, 0xA2, 0x19, 0x83, 0xBB, 0xAA, 0x0F, 0x2F, 0xB8, 0x44, 0xF6, 
  0xD9, 0x3D, 0x56, 0xBC, 0xF0, 0xB2, 0xA9, 0x85, 0x1A, 0xB9, 0xFF, 0xDF, 0x7E, 0x71, 0x69, 0x10, 
  0x0E, 0x8F, 0x2F, 0x74, 0x30, 0x2C, 0xB7, 0x61, 0xEB, 0x35, 0x23, 0x2F, 0x0A, 0x74, 0x65, 0xB7, 
  0x9E, 0x21, 0x9F, 0x24, 0x73, 0x83, 0xC7, 0xDE, 0xDF, 0x0B, 0xEA, 0xF8, 0x71, 0x4A, 0xAE, 0x18, 
  0x44, 0xA2, 0x43, 0xFB, 0xF9, 0x0E, 0x51, 0x48, 0x84, 0x82, 0x52, 0x85, 0x1F, 0x20, 0xF0, 0xB1, 
  0xAA, 0x40, 0x18, 0x57, 0x46, 0x86, 0x15, 0xE9, 0x45, 0xA5, 0x5C, 0x48, 0xE8, 0x50, 0x9E, 0x0A, 
  0x53, 0x9F, 0x07, 0xC9, 0x47, 0xF6, 0xF9, 0x96, 
};

TYPE_GrData _Button_blue_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_blue_Cpm,               //data
  1296,                           //size
    18,                           //width
    18                            //height
};

