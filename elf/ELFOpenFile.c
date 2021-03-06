#include                <stdio.h>
#include                <string.h>
#include                "../libFireBird.h"

bool ELFOpenFile(char *FileName)
{
  char                  CurrentFile[512];

  memset(CurrentFile, 0, 512);
  TAP_SPrint(CurrentFile, "%s", TAPFSROOT);
  HDD_TAP_GetCurrentDir(&CurrentFile[strlen(CurrentFile)]);
  TAP_SPrint(&CurrentFile[strlen(CurrentFile)], "/%s", FileName);

  return ELFOpenAbsFile(CurrentFile);
}
