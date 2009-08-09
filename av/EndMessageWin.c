#include "FBLib_av.h"
#include "../libFireBird.h"

void EndMessageWin (void)
{
  if (fbl_rgn) TAP_Osd_Delete(fbl_rgn);
  fbl_rgn = 0;

#ifdef _TMS_
  TAP_Osd_Sync();
#endif

}
