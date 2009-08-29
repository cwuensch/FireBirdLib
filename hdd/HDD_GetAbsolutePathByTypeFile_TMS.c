#ifdef _TMS_

#include                <string.h>
#include                "../libFireBird.h"

bool HDD_GetAbsolutePathByTypeFile(TYPE_File *File, char *AbsFileName)
{
  dword   *d;

  if(!File || !AbsFileName) return FALSE;

  //TYPE_File->handle points to a structure with 4 dwords. The third one points to the absolute path
  d = File->handle;
  if(!d || !d[2]) return FALSE;

  AbsFileName[0] = '\0';
  strcpy(AbsFileName, (char*)d[2]);

  return TRUE;
}

#endif
