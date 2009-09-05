#ifdef _TMS_

#include                <sys/stat.h>
#include                "../libFireBird.h"

dword HDD_GetFileTimeByAbsFileName(char *FileName)
{
  struct stat           statbuf;
  int                   status;

  if(!FileName) return 0;

  if((status = lstat(FileName, &statbuf))) return 0;

  //TAP_PrintNet("st_mtime = 0x%8.8x\n", statbuf.st_mtime);

  return statbuf.st_mtime;
}

#endif
