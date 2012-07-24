#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/xattr.h>
#include "../libFireBird.h"

bool ExtAttribSet(char *FileName, char *AttrName, byte *Data, int DataLen)
{
  char                  AbsFileName[512];
  char                  FullAttrName[128];
  int                   f;

  if(!FileName || !*FileName || !TAP_Hdd_Exist(FileName) || !AttrName || !*AttrName) return FALSE;

  memset(AbsFileName, 0, sizeof(AbsFileName));
  strcpy(AbsFileName, TAPFSROOT);
  HDD_TAP_GetCurrentDir(&AbsFileName[strlen(AbsFileName)]);
  if(AbsFileName[strlen(AbsFileName) - 1] != '/') strcat(AbsFileName, "/");
  strcat(AbsFileName, FileName);

  TAP_PrintNet("AbsFileName = '%s'\n", AbsFileName);

  f = open(AbsFileName, O_RDWR, 0600);
  if(f)
  {
    TAP_SPrint(FullAttrName, "user.%s", AttrName);

    if(fsetxattr(f, FullAttrName, Data, DataLen, XATTR_CREATE) == 0)
    {
      close(f);
      return TRUE;
    }
    else
    {
      //As the attribute may already exist, retry with the replace flag
      if(fsetxattr(f, FullAttrName, Data, DataLen, XATTR_REPLACE) == 0)
      {
        close(f);
        return TRUE;
      }
    }
    close(f);
  }

  return FALSE;
}
