#include                <sys/stat.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

dword HDD_GetFileTimeByAbsFileName(char *FileName)
{
  TRACEENTER();

  tstat64               statbuf;
  dword                 ret;

  if(FileName)
  {
    if(lstat64(FileName, &statbuf))
      ret = 0;
    else
      ret = statbuf.st_mtime;
  }
  else
    ret = 0;

  TRACEEXIT();
  return ret;
}
