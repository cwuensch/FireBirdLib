#include "type.h"

byte _FileSelectorDir_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01,
  0x00, 0x61, 0x9C, 0x7E, 0xFF, 0xFF, 0x03, 0x00,
  0x00, 0x34, 0x4A, 0x72, 0xB5, 0x2E, 0x4D, 0xC1, 0x77, 0x1F, 0xB8, 0x31, 0xFE, 0x24, 0x5B, 0x7F,
  0xC0, 0x47, 0x47, 0xF0, 0x45, 0x89, 0x45, 0x12, 0x3F, 0x58, 0x18, 0x20, 0x91, 0xC5, 0x60, 0x83,
  0xE3, 0x8A, 0xE4, 0x2D, 0x71, 0x40, 0x02, 0x42, 0x4C, 0xBF, 0xC3, 0x2A, 0x1E, 0xAD, 0xD3, 0x38,
  0x6B, 0x11, 0x20, 0x9E, 0x31, 0x32, 0x7B, 0x94, 0xDA, 0xAF, 0xA7, 0x66, 0x52, 0x9B, 0xA8, 0x8F,
  0x77, 0x6B, 0xD3, 0x90, 0x32, 0xF1, 0x3D, 0xE2, 0x7C, 0x34, 0xF8, 0xFA, 0x7C, 0x34, 0xF8, 0xDF,
  0x77, 0x5E, 0x2A, 0xB6, 0xCB, 0xF8, 0xEA, 0xF5, 0x17, 0xDE, 0x60
};

TYPE_GrData _FileSelectorDir_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _FileSelectorDir_Cpm,           //data
  768,                            //size
  24,                             //width
  16                              //height
};
