#include <string.h>
#include "../libFireBird.h"

bool PlayMediaFile(char *MediaFileName)
{
  TRACEENTER();

  dword                 ret;
  char                  CurrentDir[FBLIB_DIR_SIZE];

  strcpy(CurrentDir, "/mnt/hd");
  HDD_TAP_GetCurrentDir(&CurrentDir[strlen(CurrentDir)]);
  ret = PlayMediaFileAbs(MediaFileName, CurrentDir);

  TRACEEXIT();
  return ret;
}
