#include                "../libFireBird.h"

dword HDD_GetFileTimeByTypeFile(TYPE_File *File)
{
  TRACEENTER();

  char                  AbsFileName[512];
  dword                 ret;

  if(HDD_GetAbsolutePathByTypeFile(File, AbsFileName))
    ret = HDD_GetFileTimeByAbsFileName(AbsFileName);
  else
    ret = 0;

  TRACEEXIT();
  return ret;
}
