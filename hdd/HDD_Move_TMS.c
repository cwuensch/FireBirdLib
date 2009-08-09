#include                <stdio.h>
#include                <string.h>
#include                "FBLib_hdd.h"
#include                "../libFireBird.h"

#ifdef _TMS_

bool HDD_Move(char *FileName, char *FromDir, char *ToDir)
{
  char                  TempFromFile [FBLIB_DIR_SIZE << 1], TempToFile [FBLIB_DIR_SIZE << 1];

  if(!FileName || !FromDir || !ToDir) return FALSE;

  //Make a path absolute
  if(FromDir[0] != '/')
  {
    strcpy(TempFromFile, TAPFSROOT);
    HDD_TAP_GetCurrentDir(&TempFromFile[strlen(TempFromFile)]);
    if(TempFromFile[strlen(TempFromFile) - 1] != '/') strcat(TempFromFile, "/");
    strcat(TempFromFile, FromDir);
    if(TempFromFile[strlen(TempFromFile) - 1] != '/') strcat(TempFromFile, "/");
  }
  else
  {
    TAP_SPrint(TempFromFile, "%s%s", TAPFSROOT, FromDir);
    if(TempFromFile[strlen(TempFromFile) - 1] != '/') strcat(TempFromFile, "/");
  }
  strcat(TempFromFile, FileName);

  if(ToDir[0] != '/')
  {
    strcpy(TempToFile, TAPFSROOT);
    HDD_TAP_GetCurrentDir(&TempToFile[strlen(TempToFile)]);
    if(TempToFile[strlen(TempToFile) - 1] != '/') strcat(TempToFile, "/");
    strcat(TempToFile, ToDir);
    if(TempToFile[strlen(TempToFile) - 1] != '/') strcat(TempToFile, "/");
  }
  else
  {
    TAP_SPrint(TempToFile, "%s%s", TAPFSROOT, ToDir);
    if(TempToFile[strlen(TempToFile) - 1] != '/') strcat(TempToFile, "/");
  }
  strcat(TempToFile, FileName);

  return rename(TempFromFile, TempToFile) ? FALSE : TRUE;
}

#endif
