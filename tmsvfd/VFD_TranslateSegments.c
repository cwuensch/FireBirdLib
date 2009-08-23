#include                "FBLib_tmsvfd.h"
#include                "VFDSegmentMap.inc"

#ifdef _TMS_

dword VFD_TranslateSegments(byte Character, DISPLAYSTYLE DisplayStyle)
{
  dword                 i = 0;

  switch (DisplayStyle)
  {
    case VFD_7:
    {
      while (VFDSegmentMap7[i << 1] && (Character >= VFDSegmentMap7[i << 1]))
      {
        if (VFDSegmentMap7[i << 1] == Character) return VFDSegmentMap7[(i << 1) + 1];
        i++;
      }
      break;
    }

    case VFD_14:
    {
      while (VFDSegmentMap14[i << 1] && (Character >= VFDSegmentMap14[i << 1]))
      {
        if (VFDSegmentMap14[i << 1] == Character) return VFDSegmentMap14[(i << 1) + 1];
        i++;
      }
      break;
    }

    case VFD_17:
    {
      while (VFDSegmentMap17[i << 1] && (Character >= VFDSegmentMap17[i << 1]))
      {
        if (VFDSegmentMap17[i << 1] == Character) return VFDSegmentMap17[(i << 1) + 1];
        i++;
      }
      break;
    }

    default:
      ;
  }

  return 0;
}

#endif
