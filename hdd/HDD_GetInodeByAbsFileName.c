#include                <sys/stat.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

__ino64_t HDD_GetInodeByAbsFileName(const char *FileName)
{
  tstat64               statbuf;
  int                   status;

  if(!FileName) return 0;
  if((status = lstat64(FileName, &statbuf))) return 0;

  return statbuf.st_ino;
}
