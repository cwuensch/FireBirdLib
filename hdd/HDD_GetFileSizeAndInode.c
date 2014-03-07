#include                <sys/stat.h>
#include                <string.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

bool HDD_GetFileSizeAndInode(char *Directory, char *FileName, __ino64_t *CInode, __off64_t *FileSize)
{
  TRACEENTER();

  char                  AbsFileName[512];
  tstat64               statbuf;
  bool                  ret;

  ret = FALSE;
  if(Directory && FileName)
  {
    TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, Directory, FileName);
    if(!lstat64(AbsFileName, &statbuf))
    {
      if(CInode) *CInode = statbuf.st_ino;
      if(FileSize) *FileSize = statbuf.st_size;
      ret = TRUE;
    }
  }

  TRACEEXIT();
  return ret;
}
