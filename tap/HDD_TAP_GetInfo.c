#include                <string.h>
#include                "libFireBird.h"

bool HDD_TAP_GetInfo(const char *FileName, tTAPInfo *pTAPInfo)
{
  char                  CurrentFile[512];
  bool                  ret;

  TRACEENTER();

  memset(CurrentFile, 0, 512);
  TAP_SPrint(CurrentFile, "%s", TAPFSROOT);
  HDD_TAP_GetCurrentDir(&CurrentFile[strlen(CurrentFile)]);
  TAP_SPrint(&CurrentFile[strlen(CurrentFile)], "/%s", FileName);

  ret = HDD_TAP_GetInfoByAbsPath(CurrentFile, pTAPInfo);

  TRACEEXIT();
  return ret;
}
