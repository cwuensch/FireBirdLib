#include                <stdio.h>
#include                <string.h>
#include                "../libFireBird.h"

void HDD_RecycleSF(char *FileName)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("HDD_RecycleSF");
  #endif

  tFileInUse            FileInUse;
  char                  CurrentPath[512];
  char                  AttribFileName[TS_FILE_NAME_SIZE];
  dword                 CurrentTime;

  if(FileName && TAP_Hdd_Exist(FileName))
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

    HDD_TAP_PushDir();
    HDD_ChangeDir("/DataFiles");
    if(!TAP_Hdd_Exist("RecycleBin-")) TAP_Hdd_Create("RecycleBin-", ATTR_FOLDER);
    HDD_TAP_PopDir();

    HDD_TAP_GetCurrentDir(CurrentPath);

    strcpy(AttribFileName, FileName);
    if(HDD_isRecFileName(AttribFileName)) strcat(AttribFileName, ".inf");

    ExtAttribSet(AttribFileName, "SF_Rec_OrgPath", CurrentPath, sizeof(CurrentPath));

    CurrentTime = Now(NULL);
    ExtAttribSet(AttribFileName, "SF_Rec_DelTime", (byte*)&CurrentTime, sizeof(dword));

    HDD_Move(FileName, CurrentPath, "/DataFiles/RecycleBin-/");
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
