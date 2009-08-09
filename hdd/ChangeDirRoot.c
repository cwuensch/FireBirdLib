#include <string.h>
#include "FBLib_hdd.h"
#include "../libFireBird.h"

bool ChangeDirRoot (void)
{
#ifdef _TMS_
  HDD_ChangeDir("/");
  return TRUE;
#else

  TYPE_File             fp;
  dword                 files;

  InitTAPAPIFix();

  files = TAP_Hdd_FindFirst (&fp);

  while (files && (strcmp (fp.name, "__ROOT__" ) != 0))
  {
    if (TAP_Hdd_ChangeDir("..") == 0) return FALSE;
    files = TAP_Hdd_FindFirst (&fp);
  }

  return (files != 0);
#endif
}
