#include                "../libFireBird.h"

__ino64_t HDD_GetInodeByTypeFile(TYPE_File *File)
{
  TRACEENTER();

  char                  AbsFileName[512];
  __ino64_t             ret;

  if(HDD_GetAbsolutePathByTypeFile(File, AbsFileName))
    ret = HDD_GetInodeByAbsFileName(AbsFileName);
  else
    ret = 0;

  TRACEEXIT();
  return ret;
}
