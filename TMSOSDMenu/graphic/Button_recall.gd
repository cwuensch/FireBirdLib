#include "tap.h"

byte _Button_recall_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x01, 0xC7, 0xFD, 0x80, 0xFF, 0xFF, 0x07, 0x80, 
  0x01, 0x3C, 0x62, 0xBD, 0x7D, 0xF7, 0xB3, 0x32, 0xAC, 0xFC, 0x07, 0xD6, 0xF5, 0x95, 0xAD, 0x6D, 
  0xB6, 0xD9, 0x99, 0x5A, 0x24, 0xB4, 0x4A, 0x2D, 0xF7, 0x77, 0x72, 0xBE, 0x1A, 0x36, 0x43, 0x37, 
  0x97, 0x79, 0x34, 0x52, 0x6F, 0x03, 0xC1, 0xF4, 0xEE, 0xEE, 0xBA, 0xD7, 0x5D, 0xE0, 0x22, 0x60, 
  0x22, 0xD3, 0xC0, 0x84, 0x6D, 0x40, 0x21, 0x28, 0x19, 0x11, 0xE0, 0x50, 0xF0, 0x3C, 0x0A, 0x13, 
  0xBB, 0xFE, 0xFF, 0x7F, 0x5D, 0xF6, 0xAD, 0xD5, 0xB5, 0x77, 0xD5, 0xBE, 0xF0, 0x7D, 0xE0, 0xD5, 
  0xBC, 0x3D, 0x5D, 0xE4, 0xEF, 0xC0, 0x0E, 0xF1, 0xBC, 0x2A, 0xD9, 0x83, 0xDC, 0xD9, 0xB7, 0x75, 
  0x07, 0x9F, 0x88, 0x20, 0x81, 0x7A, 0x4D, 0x07, 0xE7, 0xC8, 0x30, 0x60, 0x94, 0xF9, 0x07, 0xE0, 
  0x40, 0x80, 0x53, 0xE4, 0x1F, 0x7E, 0xFD, 0xF9, 0x4F, 0x90, 0x7D, 0xF3, 0xE7, 0xC5, 0x3A, 0x7E, 
  0x77, 0x6D, 0xCB, 0x72, 0x27, 0xBC, 0xD3, 0xAF, 0x93, 0xED, 0x2C, 0x5F, 0x83, 0x89, 0xBA, 0x60, 
  0xFB, 0xC7, 0x8F, 0x0A, 0x74, 0xC2, 0xBC, 0xA6, 0x22, 0xE4, 0xB9, 0x34, 0xFE, 0x23, 0xDC, 0x97, 
  0xDF, 0x8D, 0xE9, 0x6E, 0xC4, 0xAF, 0x2F, 0xAD, 0xED, 0x3A, 0x7A, 0x60, 0xF9, 0xE7, 0x9E, 0x5F, 
  0xE9, 0xCF, 0xC1, 0xAD, 0x32, 0xBE, 0x6D, 0x3B, 0x22, 0xF9, 0x5D, 0x37, 0x4B, 0x0C, 0x1F, 0x38, 
  0xE3, 0x8A, 0x64, 0xC5, 0xC4, 0x72, 0x59, 0x5F, 0x4A, 0xA4, 0xEF, 0xC6, 0x86, 0xE4, 0xC8, 0xF4, 
  0x70, 0xAB, 0x92, 0xBE, 0x0F, 0xD2, 0xB6, 0x6C, 0x4A, 0xD5, 0xAB, 0x97, 0x38, 0x68, 0x54, 0x9B, 
  0xA0, 0xFD, 0xBB, 0x76, 0xA9, 0x5F, 0x46, 0x46, 0x1F, 0x66, 0xCB, 0xB9, 0x75, 0xC1, 0x70, 0x7D, 
  0xB5, 0x25, 0x21, 0x2A, 0x54, 0xA8, 0xD4, 0xC7, 0xBA, 0x33, 0xCF, 0x15, 0xD1, 0x77, 0x6F, 0x5B, 
  0x1B, 0x87, 0xF5, 0x31, 0xCE, 0xFD, 0x5B, 0x93, 0x3C, 0xBA, 0x56, 0x25, 0xDF, 0xBF, 0x6F, 0x23, 
  0xF7, 0x44, 0xF8, 0x2E, 0x0F, 0xB5, 0x6A, 0xD5, 0x2E, 0x17, 0xC0, 0xBE, 0xA8, 0x31, 0xFE, 0x1C, 
  0xE3, 0xD4, 0xE3, 0xFE, 0x88, 0xCE, 0x8C, 0x7E, 0x55, 0x70, 0x5C, 0x1F, 0xA3, 0x68, 0xD1, 0x3D, 
  0xB1, 0xC3, 0x7D, 0x5A, 0xF6, 0x8A, 0x1F, 0xF1, 0xE0, 0xB8, 0x36, 0x3C, 0xAA, 0xE0, 0xB8, 0x3E, 
  0xD1, 0x9B, 0x34, 0xF6, 0xC7, 0x60, 0xC7, 0x47, 0xF6, 0xB2, 0xFD, 0xC9, 0x5F, 0x8F, 0xA1, 0x60, 
  0x6B, 0xF8, 0xDF, 0x17, 0x12, 0xED, 0x82, 0xE0, 0xFB, 0x36, 0x4C, 0x94, 0xE1, 0xFD, 0x6C, 0x8F, 
  0x64, 0x8F, 0x90, 0xF9, 0xBF, 0x6A, 0xC2, 0x87, 0x7E, 0xE0, 0xDF, 0x26, 0xFA, 0xF6, 0x1D, 0x9A, 
  0xB8, 0xBF, 0xFB, 0xD7, 0x05, 0xC1, 0xF6, 0x2C, 0x58, 0xA8, 0x7C, 0x4E, 0x64, 0x2A, 0xB2, 0xE9, 
  0xD5, 0xB3, 0x30, 0xFF, 0x0F, 0x3E, 0xB5, 0xF9, 0x71, 0x3D, 0x90, 0xBE, 0x66, 0x98, 0x2E, 0x0F, 
  0xB0, 0x60, 0xC2, 0x69, 0xF9, 0x3D, 0x2F, 0x1F, 0x43, 0xE7, 0x65, 0x82, 0xE0, 0xFA, 0xF5, 0xEB, 
  0xFF, 0x87, 0xFF, 0xB2, 0x0B, 0x83, 0xEB, 0x97, 0x2E, 0xF5, 0x3E, 0x0B, 0x83, 0xEB, 0x16, 0x2C, 
  0xF5, 0x3E, 0x0B, 0xA3, 0xFE, 0xC3, 0x5A, 0xB5, 0x69, 0x51, 0x50, 0xD0, 0xFF, 0xE4, 0x0F, 0x44, 
  0xD8, 
};

TYPE_GrData _Button_recall_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_8888,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Button_recall_Cpm,             //data
  1920,                           //size
    24,                           //width
    20                            //height
};

