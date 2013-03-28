#include                <stdlib.h>
#include                <stdio.h>
#include                <string.h>
#include                "../libFireBird.h"

void HDD_UnrecycleSF(char *FileName)
{
  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("HDD_UnrecycleSF");
  #endif

  char                  AttribFileName[TS_FILE_NAME_SIZE];
  char                  CurrentPath[512], DelPath[512], CreateDelPath[512];
  char                  cmd[512];

  if(TAP_Hdd_Exist(FileName))
  {
    HDD_TAP_GetCurrentDir(CurrentPath);

    strcpy(AttribFileName, FileName);
    if(HDD_isRecFileName(AttribFileName)) strcat(AttribFileName, ".inf");

    if(ExtAttribGet(AttribFileName, "SF_Rec_OrgPath", DelPath, sizeof(DelPath), NULL))
    {
      ExtAttribRemove(AttribFileName, "SF_Rec_OrgPath");
      ExtAttribRemove(AttribFileName, "SF_Rec_DelTime");

      //Pfad neu anlegen für den Fall das er nicht mehr existiert
      strcpy(CreateDelPath, DelPath);
      StrReplace(CreateDelPath, "\"", "\\\"");
      StrReplace(CreateDelPath, "$", "\\$");
      TAP_SPrint(cmd, "mkdir -p \"/mnt/hd%s\"", CreateDelPath);
      system(cmd);

      //Verschieben nach DelPath
      HDD_Move(FileName, CurrentPath, DelPath);
    }
    else
    {
      //Verschieben nach Root
      HDD_Move(FileName, CurrentPath, "/DataFiles");
    }
  }

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif
}
