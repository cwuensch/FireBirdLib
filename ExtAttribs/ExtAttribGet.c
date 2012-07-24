#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/xattr.h>
#include "../libFireBird.h"

bool ExtAttribGet(char *FileName, char *AttrName, byte *Data, int MaxDataLen, int *DataLen)
{
  char                  AbsFileName[512];
  char                  FullAttrName[128];
  int                   f, i;

  if(!FileName || !*FileName || !TAP_Hdd_Exist(FileName) || !AttrName || !*AttrName)
  {
    if(DataLen) *DataLen = 0;
    return FALSE;
  }

  memset(AbsFileName, 0, sizeof(AbsFileName));
  strcpy(AbsFileName, TAPFSROOT);
  HDD_TAP_GetCurrentDir(&AbsFileName[strlen(AbsFileName)]);
  if(AbsFileName[strlen(AbsFileName) - 1] != '/') strcat(AbsFileName, "/");
  strcat(AbsFileName, FileName);

  f = open(AbsFileName, O_RDWR, 0600);
  if(f)
  {
    //Get the size of the data
    TAP_SPrint(FullAttrName, "user.%s", AttrName);
    if((i = fgetxattr(f, FullAttrName, NULL, 0)) >= 0)
    {
      //Read the data
      if(i > MaxDataLen) i = MaxDataLen;
      fgetxattr(f, FullAttrName, Data, i);
      if(DataLen) *DataLen = i;
      close(f);
      return TRUE;
    }
    close(f);
  }

  if(DataLen) *DataLen = 0;
  return FALSE;
}
