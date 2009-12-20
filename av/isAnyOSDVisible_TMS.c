#include "../libFireBird.h"

#ifdef _TMS_

bool isAnyOSDVisible(dword checkX, dword checkY, dword checkW, dword checkH)
{
  TYPE_OsdBaseInfo      OSDBaseInfo;
  dword                *pOSD;
  dword                 x, y;

  TAP_Osd_GetPlaneBaseInfo(&OSDBaseInfo, TAP_PLANE);

  for(y = checkY; y < (checkY + checkH); y++)
  {
    pOSD = (dword*)(OSDBaseInfo.frameBuffer);
    pOSD = (dword*)&pOSD[720*y + checkX];
    for(x = checkX; x < (checkX + checkW); x++)
    {
      if(*pOSD != 0x00000000) return TRUE;
      pOSD++;
    }
  }
  return FALSE;
}

#endif
