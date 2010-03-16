#include <string.h>
#include "../libFireBird.h"

void FixInvalidFileName(char *FileName)
{
  char                  NewRecName[TS_FILE_NAME_SIZE];
  TYPE_PlayInfo         playInfo;
  TYPE_RecInfo          recInfo;

#ifdef _TMS_
  char                  Name[TS_FILE_NAME_SIZE], Ext[TS_FILE_NAME_SIZE];
  bool                  isRec, isDel;
  int                   fNumber;
  char                  OldInfName[TS_FILE_NAME_SIZE], NewInfName[TS_FILE_NAME_SIZE];
#endif

  if (TAP_Hdd_Exist(FileName) && (FileName[0] == 0x05))
  {
    //Check if the file is busy
    TAP_Hdd_GetPlayInfo(&playInfo);
    if(playInfo.file && playInfo.file->name[0] && !strstr(&FileName[1], playInfo.file->name)) return;

    TAP_Hdd_GetRecInfo(0, &recInfo);
    if(recInfo.fileName[0] && !strstr(&FileName[1], recInfo.fileName)) return;

    TAP_Hdd_GetRecInfo(1, &recInfo);
    if(recInfo.fileName[0] && !strstr(&FileName[1], recInfo.fileName)) return;

    strcpy(NewRecName, &FileName[1]);
    MakeUniqueFileName(NewRecName);
    TAP_Hdd_Rename(FileName, NewRecName);

#ifdef _TMS_

    if(isRec)
    {
      SeparateFileNameComponents(FileName, Name, Ext, &fNumber, &isRec, &isDel);
      if(fNumber)
        TAP_SPrint(OldInfName, "%s-%d%s.inf%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(OldInfName, "%s%s.inf%s", Name, Ext, isDel ? ".del" : "");

      SeparateFileNameComponents(NewRecName, Name, Ext, &fNumber, &isRec, &isDel);
      if(fNumber)
        TAP_SPrint(NewInfName, "%s-%d%s.inf%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(NewInfName, "%s%s.inf%s", Name, Ext, isDel ? ".del" : "");

      TAP_Hdd_Rename(OldInfName, NewInfName);

      SeparateFileNameComponents(FileName, Name, Ext, &fNumber, &isRec, &isDel);
      if(fNumber)
        TAP_SPrint(OldInfName, "%s-%d%s.nav%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(OldInfName, "%s%s.nav%s", Name, Ext, isDel ? ".del" : "");

      SeparateFileNameComponents(NewRecName, Name, Ext, &fNumber, &isRec, &isDel);
      if(fNumber)
        TAP_SPrint(NewInfName, "%s-%d%s.nav%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(NewInfName, "%s%s.nav%s", Name, Ext, isDel ? ".del" : "");

      TAP_Hdd_Rename(OldInfName, NewInfName);
    }

#endif

    strcpy(FileName, NewRecName);
    FileName[strlen(NewRecName)] = '\0';
  }
}

