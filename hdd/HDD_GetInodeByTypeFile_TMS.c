#ifdef _TMS_

#include                  <sys/stat.h>
#include                "../libFireBird.h"

dword HDD_GetInodeByTypeFile(TYPE_File *File)
{
  char                  AbsFileName[MAX_FILE_NAME_SIZE];
  struct stat           statbuf;
  int                   status;

  if(!HDD_GetAbsolutePathByTypeFile(File, AbsFileName)) return 0;

  if((status = lstat(AbsFileName, &statbuf))) return 0;

  return statbuf.st_ino;
}

#endif
