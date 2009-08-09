#include "type.h"

byte _Scroll_Cursor_Cpm[] =
{
  0x00, 0x08, 0x1B, 0x90, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x1B, 0x9B, 0xF0, 0xFF, 0xFF, 0x00, 0xB4, 
  0x00, 0x08, 0x30, 0x65, 0x6A, 0xF0, 0x33, 0xF1, 0x7F, 0xEC, 0xB5, 0x40, 0x04, 0x20, 0x4C, 0x88, 
  0x01, 0x4D, 0x27, 0xCD, 0x28, 
};

TYPE_GrData _Scroll_Cursor_Gd =
{
  1,                              //version
  0,                              //reserved
  OSD_1555,                       //data format
  COMPRESS_Tfp,                   //compressed method
  _Scroll_Cursor_Cpm,             //data
   180,                           //size
    10,                           //width
     9                            //height
};

