#include                <sys/stat.h>
#include                <string.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

bool HDD_GetFileSizeAndInode(char *Directory, char *FileName, dword *CInode, __off64_t *FileSize)
{
  char                  AbsFileName[256];
  tstat64               statbuf;
  int                   status;

  TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, Directory, FileName);

  if((status = lstat64(AbsFileName, &statbuf))) return FALSE;

  *CInode = statbuf.st_ino;
  *FileSize = statbuf.st_size;

  return TRUE;
}
