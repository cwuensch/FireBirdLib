#ifdef _TMS_

#include                <sys/stat.h>
#include                "../libFireBird.h"

dword HDD_GetInodeByAbsFileName(char *FileName)
{
  struct stat           statbuf;
  int                   status;

  if(!FileName) return 0;

  if((status = lstat(FileName, &statbuf))) return 0;

  return statbuf.st_ino;
}

#endif
