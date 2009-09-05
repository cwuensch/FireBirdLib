#include "../libFireBird.h"

void HDD_Delete(char *FileName)
{
#ifdef _TMS_
  char                  Name[TS_FILE_NAME_SIZE], Ext[TS_FILE_NAME_SIZE];
  char                  TempName[TS_FILE_NAME_SIZE];
  bool                  isRec, isDel;
  int                   fNumber;
#endif

  if (TAP_Hdd_Exist(FileName))
  {
    TAP_Hdd_Rename(FileName, "FilerDelete.tmp");
    TAP_Hdd_Delete("FilerDelete.tmp");

#ifdef _TMS_

    SeparateFileNameComponents(FileName, Name, Ext, &fNumber, &isRec, &isDel);
    if(isRec)
    {
      if(fNumber)
        TAP_SPrint(TempName, "%s-%d%s.inf%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(TempName, "%s%s.inf%s", Name, Ext, isDel ? ".del" : "");

      TAP_Hdd_Rename(TempName, "FilerDelete.tmp");
      TAP_Hdd_Delete("FilerDelete.tmp");

      if(fNumber)
        TAP_SPrint(TempName, "%s-%d%s.nav%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(TempName, "%s%s.nav%s", Name, Ext, isDel ? ".del" : "");

      TAP_Hdd_Rename(TempName, "FilerDelete.tmp");
      TAP_Hdd_Delete("FilerDelete.tmp");
    }

#endif

  }
}
