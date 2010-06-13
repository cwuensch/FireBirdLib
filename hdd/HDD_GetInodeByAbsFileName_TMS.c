#ifdef _TMS_

#include                <sys/stat.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

dword HDD_GetInodeByAbsFileName(char *FileName)
{
  tstat64               statbuf;
  int                   status;
  char                  AbsFileNameUTF8[256];

  if(!FileName) return 0;

  if(TAP_GetVersion() >= 0x0108)
  {
    StrToUTF8(FileName, AbsFileNameUTF8);
    if((status = lstat64(AbsFileNameUTF8, &statbuf))) return 0;
  }
  else
  {
    if((status = lstat64(FileName, &statbuf))) return 0;
  }

  return (dword)statbuf.st_ino;
}

#endif
