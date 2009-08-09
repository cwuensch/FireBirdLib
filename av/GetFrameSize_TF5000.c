#include "../libFireBird.h"

#ifndef _TMS_

void GetFrameSize (dword *Width, dword *Height)
{
  *Width = (*EMMA_MPEG_PARAM_SEQ & 0x000000ff) << 4;
  *Height = (*EMMA_MPEG_PARAM_SEQ & 0x0000ff00) >> 4;
}

#endif
