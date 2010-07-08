#include <string.h>
#include "FBLib_hdd.h"
#include "../libFireBird.h"


bool HDD_ChangeDir(char *Dir)
{
#ifdef _TMS_

  //The TMS supports absolute paths.
  //Starting with 2009-08-13 (version 0105), TF changed the return value
  //  of TAP_Hdd_ChangeDir() to the same type as the current TF5000 API
  if(TAP_GetVersion() > 0x0104)
    return TAP_Hdd_ChangeDir(Dir);
  else
    return !TAP_Hdd_ChangeDir(Dir);

#else

  char                  D [FBLIB_DIR_SIZE];
  char                  *d, *p;

  InitTAPAPIFix();

  strncpy (D, Dir, sizeof(D) - 1);  // we need 1 char for a terminating / later
  D[sizeof(D) - 2] = '\0';

  if (*D == '/')
  {
    if (!ChangeDirRoot()) return FALSE;
    strcpy (D, D + 1);
  }

  strcat (D, "/");
  d = D;

  while ((p = strchr (d, '/')))
  {
    *p = '\0';
    if (*d)
    {
      if (TAP_Hdd_ChangeDir(d) == 0) return FALSE;
    }
    d = p + 1;
  }

  return TRUE;

#endif
}
