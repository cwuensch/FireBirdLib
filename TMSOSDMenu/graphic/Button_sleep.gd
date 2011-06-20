#include "tap.h"

byte _Button_sleep_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0xF5, 0xB1, 0x21, 0xFF, 0xFF, 0x07, 0x80, 
  0x01, 0x59, 0x62, 0x79, 0xE1, 0xD6, 0x34, 0xEA, 0xCF, 0xC0, 0x9A, 0xB9, 0x60, 0x68, 0x57, 0x05, 
  0x2B, 0x6F, 0x56, 0xDD, 0xD6, 0xD8, 0x4C, 0xA6, 0x05, 0x82, 0x85, 0x76, 0xC6, 0xCF, 0x03, 0x75, 
  0x78, 0x54, 0x12, 0xA3, 0x01, 0xA3, 0x09, 0xB6, 0x02, 0x36, 0x0A, 0x0B, 0xA2, 0x6D, 0xA3, 0x6D, 
  0x83, 0x68, 0x58, 0xD0, 0x32, 0x18, 0xC6, 0xBB, 0x42, 0xC3, 0x02, 0xAA, 0x2C, 0x04, 0x10, 0x58, 
  0x48, 0xC3, 0x55, 0x3F, 0xDF, 0xDD, 0x6F, 0x94, 0xEE, 0x4F, 0x50, 0xE4, 0x2A, 0x1A, 0x83, 0x05, 
  0x80, 0xC3, 0xDF, 0x01, 0x34, 0x3D, 0x07, 0x06, 0xCC, 0x1D, 0xAD, 0x29, 0x2E, 0xBA, 0xAF, 0xF5, 
  0x4A, 0x95, 0x13, 0xFB, 0x37, 0x56, 0x7E, 0xA5, 0x4A, 0x92, 0x7F, 0xE4, 0x5F, 0xA3, 0x46, 0x8A, 
  0x7E, 0xA7, 0xD9, 0xE9, 0xCC, 0x4A, 0xDF, 0x3C, 0x94, 0xE2, 0xD7, 0x6D, 0x39, 0x76, 0x67, 0xB9, 
  0xCC, 0xEF, 0x2B, 0xF6, 0x1B, 0x17, 0xE8, 0x50, 0xA0, 0x8F, 0xCE, 0x95, 0x3C, 0xB4, 0xDC, 0xFA, 
  0x36, 0x9C, 0xDB, 0x53, 0xFA, 0xE4, 0xBE, 0x07, 0xB6, 0x86, 0x2F, 0xB6, 0xDB, 0x68, 0xB9, 0xD0, 
  0xCF, 0x6D, 0x38, 0x7F, 0x36, 0x10, 0xF7, 0xAA, 0xCF, 0x4F, 0x5E, 0xA6, 0x3A, 0x67, 0x66, 0xB6, 
  0x9C, 0x95, 0xF1, 0xFE, 0xDE, 0xB3, 0x4E, 0x77, 0x95, 0xCB, 0xE0, 0x70, 0x7B, 0xE8, 0xE2, 0xFB, 
  0x4D, 0x34, 0x8B, 0x9D, 0x9D, 0x6F, 0x3B, 0x86, 0xFE, 0xDE, 0xF9, 0xC9, 0x8D, 0x8D, 0xD1, 0x5C, 
  0xA7, 0x91, 0xE6, 0x65, 0xCE, 0xB2, 0xB9, 0x7C, 0xA6, 0x0F, 0x7D, 0x1C, 0x5F, 0x9B, 0x36, 0x6A, 
  0x3B, 0x3A, 0xBA, 0x3E, 0x57, 0x09, 0xEE, 0xFD, 0x67, 0x27, 0x93, 0xC7, 0xD3, 0x6D, 0x4B, 0xEA, 
  0xEF, 0x2F, 0x81, 0xCA, 0xE1, 0x75, 0xA5, 0x8B, 0xF3, 0x26, 0x4C, 0x47, 0x67, 0xF1, 0xF0, 0xC5, 
  0x70, 0x7E, 0x9D, 0x3C, 0x44, 0x5D, 0xB5, 0x2F, 0xBB, 0x4C, 0x0E, 0x57, 0x0B, 0xAC, 0x78, 0xBF, 
  0x2E, 0x54, 0xA4, 0x81, 0x02, 0x07, 0x3C, 0xF0, 0x7D, 0xEC, 0x2F, 0xB1, 0x7F, 0xDF, 0x7A, 0xB9, 
  0x2A, 0x5F, 0x76, 0x40, 0xE5, 0x70, 0xBB, 0xA2, 0xC5, 0x71, 0x7E, 0x54, 0x99, 0x2F, 0x57, 0xE3, 
  0xD8, 0xB1, 0xAF, 0x7D, 0xEB, 0xCB, 0xBE, 0xA5, 0xF5, 0xCA, 0x87, 0x9C, 0xDD, 0x16, 0x2B, 0x8B, 
  0xEC, 0xB2, 0xCF, 0x76, 0x3F, 0x7E, 0x6D, 0xE3, 0xF1, 0x5C, 0x5F, 0xF0, 0xC8, 0x90, 0xF5, 0x7F, 
  0x8F, 0xAA, 0xC6, 0xB3, 0xE5, 0x62, 0xB3, 0xDA, 0xBE, 0x07, 0x07, 0x85, 0xDD, 0xAE, 0x2B, 0x8B, 
  0xF2, 0x23, 0xC7, 0x7A, 0xB9, 0xAA, 0x60, 0xFA, 0xDF, 0x2F, 0x12, 0x5F, 0x5E, 0xDE, 0x5C, 0x5B, 
  0x2F, 0x81, 0xD5, 0xB2, 0xEE, 0xDB, 0x15, 0xC5, 0xF8, 0xF8, 0x18, 0x16, 0x8B, 0xD5, 0xF7, 0x61, 
  0xB8, 0x4F, 0xDB, 0xE8, 0xC2, 0xEB, 0x63, 0x2B, 0x97, 0xC0, 0xE0, 0xF5, 0xDF, 0x15, 0xC5, 0xF8, 
  0xD1, 0xA3, 0x5A, 0xB7, 0x83, 0x2E, 0x0A, 0x6F, 0xD9, 0xD8, 0x73, 0x0F, 0x9A, 0x06, 0x6B, 0x39, 
  0xBE, 0x67, 0x33, 0xBD, 0x58, 0xDC, 0x0E, 0x0F, 0x5A, 0x18, 0xAE, 0x2F, 0xB0, 0xC3, 0x1D, 0x58, 
  0x7C, 0x26, 0xAC, 0x8F, 0x6E, 0x4B, 0xEF, 0xAD, 0xB9, 0xBE, 0xF5, 0xD5, 0xC5, 0xF8, 0xB1, 0x62, 
  0xDC, 0xD6, 0x33, 0x55, 0xCD, 0xBB, 0x3C, 0x1F, 0x3C, 0x83, 0x39, 0x9D, 0xEB, 0xD6, 0xF5, 0xC8, 
  0xAE, 0x2F, 0xC4, 0x89, 0x13, 0xB7, 0xC2, 0x7F, 0xDC, 0x8A, 0xE2, 0xFC, 0x28, 0x50, 0xBF, 0xCB, 
  0xE2, 0xBA, 0xBF, 0xB0, 0xE1, 0xC3, 0x86, 0x9E, 0x08, 0x30, 0x7F, 0x92, 0x27, 0xA9, 0x6C, 
};

TYPE_GrData _Button_sleep_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_sleep_Cpm,              //data
  1920,                           //size
    24,                           //width
    20                            //height
};

