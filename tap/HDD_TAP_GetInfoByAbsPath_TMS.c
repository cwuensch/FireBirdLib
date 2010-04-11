#include                <string.h>
#include                "../libFireBird.h"

#ifdef _TMS_

bool HDD_TAP_GetInfoByAbsPath(char *AbsFileName, tTAPInfo *pTAPInfo)
{
  bool                  ret;
  char                 *p, *Slash;

  if(!AbsFileName || !pTAPInfo) return FALSE;

  //Let Slash point to the last /
  Slash = AbsFileName;
  do
  {
    p = strstr(Slash + 1, "/");
    if(p) Slash = p;
  }while(p);

  //Terminate the string. AbsFileName now contains the full path, Slash+1 the file name
  *Slash = '\0';

  HDD_TAP_PushDir();
  TAP_Hdd_ChangeDir(&AbsFileName[strlen(TAPFSROOT)]);
  ret = HDD_TAP_GetInfo(&Slash[1], pTAPInfo);
  HDD_TAP_PopDir();

  return ret;
}

#endif