#include "../libFireBird.h"

//TAP_Osd_Copy(word srcRgnNum, word dstRgnNum, dword srcX, dword srcY, dword w, dword h, dword dstX, dword dstY,  bool sprite);

//Checks:
//* Get width and height of source region
//* Warning if srcX >= width
//* Warning if srcY >= height
//* Warning if (srcX + w) >= width
//* Warning if (srcY + h) >= height
//* Get width and height of destination region
//* Warning if dstX >= width
//* Warning if dstY >= height
//* Warning if (dstX + w) >= width
//* Warning if (dstY + h) >= height


int TAP_Osd_Copy_Chk(char *Comment, word srcRgnNum, word dstRgnNum, dword srcX, dword srcY, dword w, dword h, dword dstX, dword dstY,  bool sprite)
{
  dword                 RgnH, RgnW;

  RgnH = GetOSDRegionHeight(srcRgnNum);
  RgnW = GetOSDRegionWidth(srcRgnNum);

  if(srcX >= RgnW)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: srcX(%d) >= srcRgnW(%d) @ %s\n", srcX, RgnW, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: srcX(%d) >= srcRgnW(%d) @ %s\n", srcX, RgnW, Comment);
#endif

  if(srcY >= RgnH)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: srcY(%d) >= srcRgnH(%d) @ %s\n", srcY, RgnH, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: srcY(%d) >= srcRgnH(%d) @ %s\n", srcY, RgnH, Comment);
#endif

  if((srcX + w) > RgnW)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: (srcX(%d) + w(%d)) > srcRgnW(%d) @ %s\n", srcX, w, RgnW, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: (srcX(%d) + w(%d)) > srcRgnW(%d) @ %s\n", srcX, w, RgnW, Comment);
#endif

  if((srcY + h) > RgnH)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: (srcY(%d) + h(%d)) > srcRgnH(%d) @ %s\n", srcY, h, RgnH, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: (srcY(%d) + h(%d)) > srcRgnH(%d) @ %s\n", srcY, h, RgnH, Comment);
#endif

  RgnH = GetOSDRegionHeight(dstRgnNum);
  RgnW = GetOSDRegionWidth(dstRgnNum);

  if(dstX >= RgnW)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: dstX(%d) >= srcRgnW(%d) @ %s\n", dstX, RgnW, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: dstX(%d) >= srcRgnW(%d) @ %s\n", dstX, RgnW, Comment);
#endif

  if(srcY >= RgnH)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: srcY(%d) >= srcRgnH(%d) @ %s\n", srcY, RgnH, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: srcY(%d) >= srcRgnH(%d) @ %s\n", srcY, RgnH, Comment);
#endif

  if((dstX + w) > RgnW)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: (dstX(%d) + w(%d)) > dstRgnW(%d) @ %s\n", dstX, w, RgnW, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: (dstX(%d) + w(%d)) > dstRgnW(%d) @ %s\n", dstX, w, RgnW, Comment);
#endif

  if((dstY + h) > RgnH)
#ifdef _TMS_
    TAP_PrintNet("TAP_Osd_Copy_Chk Warning: (dstY(%d) + h(%d)) > dstRgnH(%d) @ %s\n", dstY, h, RgnH, Comment);
#else
    TAP_Print("TAP_Osd_Copy_Chk Warning: (dstY(%d) + h(%d)) > dstRgnH(%d) @ %s\n", dstY, h, RgnH, Comment);
#endif

  return TAP_Osd_Copy(srcRgnNum, dstRgnNum, srcX, srcY, w, h, dstX, dstY, sprite);
}
