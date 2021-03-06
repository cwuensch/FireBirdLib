#include                <sys/stat.h>
#include                <string.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

bool HDD_GetFileSizeAndInode(char *Directory, char *FileName, __ino64_t *CInode, __off64_t *FileSize)
{
  char                  AbsFileName[FBLIB_DIR_SIZE];
  tstat64               statbuf;
  int                   status;

  TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, Directory, FileName);

  if((status = lstat64(AbsFileName, &statbuf))) return FALSE;

  if(CInode) *CInode = statbuf.st_ino;
  if(FileSize) *FileSize = statbuf.st_size;

  return TRUE;
}
