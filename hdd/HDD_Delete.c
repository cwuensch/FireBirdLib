#include                <stdio.h>
#include                <string.h>
#include                "../libFireBird.h"

void HDD_Delete(char *FileName)
{
  TRACEENTER();

  char                  Name[TS_FILE_NAME_SIZE], Ext[TS_FILE_NAME_SIZE];
  char                  TempName[TS_FILE_NAME_SIZE];
  bool                  isRec, isDel;
  int                   fNumber;

  tFileInUse            FileInUse;

  if(TAP_Hdd_Exist(FileName))
  {
    FileInUse = HDD_isFileInUse(FileName);
    switch(FileInUse)
    {
      case FIU_No: break;

       //Do not differentiate because of a firmware bug
      case FIU_Playback:
      case FIU_PlayMP3:
      {
        TAP_Hdd_StopTs();
        TAP_Hdd_StopMp3();
        break;
      }

      case FIU_RecSlot1: TAP_Hdd_StopRecord(0); break;
      case FIU_RecSlot2: TAP_Hdd_StopRecord(1); break;
      case FIU_RecSlot3: TAP_Hdd_StopRecord(2); break;
      case FIU_RecSlot4: TAP_Hdd_StopRecord(3); break;
    }

    if(StringEndsWith(FileName, ".inf")) Name[strlen(Name) - 4] = '\0';
    if(StringEndsWith(FileName, ".nav")) Name[strlen(Name) - 4] = '\0';

    TAP_Hdd_Rename(FileName, "FBLibDelete.tmp");
    TAP_Hdd_Delete("FBLibDelete.tmp");

    SeparateFileNameComponents(FileName, Name, Ext, &fNumber, &isRec, &isDel);
    if(isRec && HDD_isRecFileName(FileName))
    {
      if(fNumber)
        TAP_SPrint(TempName, "%s-%d%s.inf%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(TempName, "%s%s.inf%s", Name, Ext, isDel ? ".del" : "");

      TAP_Hdd_Rename(TempName, "FBLibDelete.tmp");
      TAP_Hdd_Delete("FBLibDelete.tmp");

      if(fNumber)
        TAP_SPrint(TempName, "%s-%d%s.nav%s", Name, fNumber, Ext, isDel ? ".del" : "");
      else
        TAP_SPrint(TempName, "%s%s.nav%s", Name, Ext, isDel ? ".del" : "");

      TAP_Hdd_Rename(TempName, "FBLibDelete.tmp");
      TAP_Hdd_Delete("FBLibDelete.tmp");
    }
  }

  TRACEEXIT();
}
