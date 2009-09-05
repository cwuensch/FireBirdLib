#include <string.h>
#include "../libFireBird.h"

void HDD_Recycle(char *FileName)
{
  char                  Name[TS_FILE_NAME_SIZE], Ext[TS_FILE_NAME_SIZE];
  char                  OldName[TS_FILE_NAME_SIZE], NewName[TS_FILE_NAME_SIZE];
  bool                  isRec, isDel;
  int                   fNumber;

  if (TAP_Hdd_Exist(FileName))
  {
    SeparateFileNameComponents(FileName, Name, Ext, &fNumber, &isRec, &isDel);

    if(!isDel)
    {
      if(fNumber)
        TAP_SPrint(OldName, "%s-%d%s", Name, fNumber, Ext);
      else
        TAP_SPrint(OldName, "%s%s", Name, Ext);

      TAP_SPrint(NewName, "%s.del", OldName);
      MakeUniqueFileName(NewName);
      TAP_Hdd_Rename(OldName, NewName);

      if(isRec)
      {
        strcat(OldName, ".inf");
        NewName[strlen(NewName) - 4] = '\0';
        strcat(NewName, ".inf.del");
        TAP_Hdd_Rename(OldName, NewName);

        OldName[strlen(OldName) - 4] = '\0';
        strcat(OldName, ".nav");
        NewName[strlen(NewName) - 8] = '\0';
        strcat(NewName, ".nav.del");
        TAP_Hdd_Rename(OldName, NewName);
      }
    }
  }
}
