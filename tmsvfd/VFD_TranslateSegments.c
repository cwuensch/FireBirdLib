#include                "FBLib_tmsvfd.h"
#include                "VFDSegmentMap.h"

#ifdef _TMS_

dword VFD_TranslateSegments(byte Character, DISPLAYSTYLE DisplayStyle)
{
  switch (DisplayStyle)
  {
    case VFD_7:  return VFDSegmentMap7[Character];
    case VFD_14: return VFDSegmentMap14[Character];
    case VFD_17: return VFDSegmentMap17[Character];

    default:
      ;
  }

  return 0;
}

#endif
