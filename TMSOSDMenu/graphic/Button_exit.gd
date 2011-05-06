#include "tap.h"

byte _Button_exit_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0xEC, 0xF4, 0x62, 0xFF, 0xFF, 0x0C, 0x80, 
  0x01, 0x4A, 0x62, 0x9A, 0xF7, 0xBA, 0xA4, 0xF2, 0xCF, 0xC0, 0x97, 0x9A, 0xE1, 0xB0, 0x22, 0x79, 
  0x5F, 0x79, 0x95, 0xC4, 0x17, 0x15, 0x70, 0x55, 0x70, 0xA1, 0x11, 0x39, 0xC6, 0xCB, 0xE9, 0xF2, 
  0xA3, 0x45, 0xC2, 0xDC, 0x30, 0xF2, 0x5E, 0xE2, 0xA6, 0x1B, 0x82, 0x8C, 0x60, 0xC6, 0xD6, 0x1C, 
  0x1B, 0x6C, 0x08, 0x68, 0x81, 0x84, 0x24, 0xA8, 0x6A, 0xE1, 0xA1, 0xA8, 0x22, 0x28, 0x82, 0x81, 
  0xE2, 0x88, 0x28, 0xB8, 0xA3, 0xFD, 0xFE, 0xFC, 0xDE, 0x43, 0xCF, 0x07, 0x82, 0x82, 0x43, 0xD0, 
  0x6E, 0x17, 0x9F, 0x6E, 0x0D, 0xC1, 0xB9, 0xF7, 0x05, 0xC3, 0xBE, 0x07, 0x6F, 0x80, 0x9B, 0x8F, 
  0x70, 0xA1, 0xED, 0xC1, 0xEB, 0x23, 0x37, 0x0C, 0xCA, 0x9F, 0x92, 0x64, 0xC9, 0x2F, 0xFC, 0xB2, 
  0xEC, 0xF1, 0x34, 0xD3, 0x26, 0x24, 0x0F, 0xC8, 0x91, 0x20, 0x98, 0x90, 0x3F, 0x1E, 0x3C, 0x72, 
  0x62, 0x40, 0xFC, 0x68, 0xD1, 0x89, 0x89, 0x03, 0xE8, 0xA2, 0x89, 0x2F, 0x39, 0xB9, 0x30, 0x8B, 
  0x8F, 0x5A, 0x25, 0x69, 0x18, 0x74, 0x74, 0xA1, 0x9B, 0x8E, 0x5E, 0x72, 0x46, 0xD3, 0xCF, 0xF9, 
  0xD4, 0xE7, 0xFA, 0xFB, 0x92, 0xAB, 0xB3, 0xD0, 0xCF, 0xA9, 0x97, 0xCB, 0xAF, 0x11, 0x6A, 0x1A, 
  0x99, 0x6B, 0xC8, 0x1F, 0x7C, 0xF9, 0xF1, 0x2F, 0x3E, 0xDC, 0xC8, 0x05, 0xD7, 0xC1, 0x14, 0xB9, 
  0xB6, 0xA2, 0x17, 0x16, 0xA2, 0x46, 0x99, 0x49, 0xFA, 0x0B, 0x47, 0xDE, 0x89, 0xB1, 0xE8, 0xCD, 
  0x84, 0x58, 0x91, 0x5F, 0x97, 0x56, 0xF4, 0x43, 0x48, 0xE3, 0x53, 0x67, 0xA7, 0xF1, 0x44, 0xD4, 
  0x3E, 0x4A, 0x10, 0xCA, 0x96, 0xCC, 0x3A, 0xD4, 0x79, 0x9E, 0xC8, 0x25, 0xF6, 0xBD, 0x81, 0xF7, 
  0xAF, 0x5E, 0x92, 0xF3, 0xEB, 0xCA, 0x7E, 0x6A, 0xBC, 0xEF, 0x87, 0xA5, 0x6C, 0xBE, 0x7D, 0xBA, 
  0x97, 0x3E, 0x19, 0xF0, 0x8D, 0xEF, 0x42, 0x64, 0x1A, 0xFB, 0x35, 0xE8, 0xFD, 0xF2, 0x07, 0xFC, 
  0xAF, 0x1E, 0x13, 0x36, 0x6C, 0xEB, 0xCE, 0x3E, 0x1D, 0xB9, 0xAD, 0x72, 0xE5, 0x5E, 0x2D, 0x97, 
  0xEA, 0x4E, 0xE8, 0xD9, 0x62, 0x7A, 0x37, 0x12, 0x23, 0xCE, 0xB4, 0xAF, 0xB3, 0x5E, 0x8F, 0xDB, 
  0x20, 0x5C, 0x0F, 0xBC, 0x76, 0xEE, 0xC0, 0xFA, 0xB2, 0xAE, 0x7F, 0x4D, 0x31, 0x71, 0x87, 0xAB, 
  0xF2, 0xBF, 0xF0, 0x0B, 0xFB, 0x8F, 0x81, 0x70, 0x3E, 0xE9, 0xD3, 0xAB, 0x03, 0xFB, 0xB3, 0x7C, 
  0xC6, 0xB7, 0xFD, 0x33, 0xAF, 0xBB, 0x8E, 0xF7, 0xE7, 0x79, 0xFF, 0x83, 0xE0, 0x5C, 0x0F, 0xDB, 
  0x39, 0x73, 0xFA, 0xEE, 0xF8, 0x13, 0x17, 0x3A, 0x5B, 0x10, 0x4D, 0xEE, 0x00, 0xFC, 0x47, 0xC0, 
  0xB8, 0x1F, 0x72, 0x82, 0x1F, 0x91, 0xF5, 0x00, 0xC1, 0x1A, 0xBC, 0x7E, 0x23, 0xE0, 0x5C, 0x0F, 
  0xA0, 0x79, 0xFF, 0x8F, 0x8F, 0xE2, 0xFE, 0xA7, 0x4E, 0xD4, 0xE9, 0x9A, 0xBC, 0xFF, 0xB1, 0xF0, 
  0x2E, 0x07, 0xDC, 0x38, 0x71, 0xE1, 0xA7, 0xBD, 0xB9, 0x68, 0x6E, 0x83, 0xAB, 0x30, 0x30, 0x0F, 
  0x37, 0xC8, 0x7C, 0xFC, 0xBB, 0xBA, 0xBA, 0x7C, 0x2C, 0x14, 0x0D, 0x97, 0x91, 0x8D, 0x71, 0x57, 
  0x67, 0x8A, 0x8B, 0xB5, 0xA8, 0xEA, 0xE1, 0xAF, 0x20, 0x5C, 0x0F, 0xB7, 0x6E, 0xDE, 0xC6, 0xBF, 
  0xFB, 0x20, 0x5C, 0x0F, 0xB6, 0x6C, 0xDA, 0xC8, 0xF8, 0x17, 0x03, 0xE7, 0x1C, 0x75, 0x91, 0xF0, 
  0x2E, 0x07, 0xDA, 0x34, 0x69, 0x64, 0x7C, 0x0B, 0xA9, 0xFB, 0x43, 0x6A, 0xD5, 0xA9, 0x79, 0x2D, 
  0x6D, 0x7F, 0xD2, 0x03, 0xD4, 0x1B, 
};

TYPE_GrData _Button_exit_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_exit_Cpm,               //data
  3200,                           //size
    40,                           //width
    20                            //height
};

