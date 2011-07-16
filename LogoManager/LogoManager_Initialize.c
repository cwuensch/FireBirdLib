#include                <string.h>
#include                <stdlib.h>
#include                "../libFireBird.h"
#include                "FBLib_LogoManager.h"

tLogoData              *LogoManager_LogoData = NULL;
int                     LogoManager_NrLogos = 0;
bool                    LogoManager_LUTInitialized = FALSE;

void (*LogoManager_CB)(int CallbackType, int Param1) = NULL;

void LogoManager_Initialize(void *Callback)
{
  char                  cmd[255];

  LogoManager_CB = Callback;

  HDD_TAP_PushDir();
  HDD_ChangeDir(LOGOROOT);

  if(!LogoManager_LUTInitialized || !TAP_Hdd_Exist(LOGOCACHE))
  {
    //Check if there's a packed logo file, unpack and erase the tar
    if(TAP_Hdd_Exist(LOGOPACK))
    {
      if(LogoManager_CB) LogoManager_CB(1, 0);
      TAP_SPrint(cmd, "cd %s%s; %s/ProgramFiles/busybox tar xf %s", TAPFSROOT, LOGOROOT, TAPFSROOT, LOGOPACK);
      system(cmd);
      TAP_Hdd_Delete(LOGOPACK);
      TAP_Hdd_Delete(LOGOCACHE);
    }

    //Check if the cache file already exists
    LogoManager_LogoCacheLoad();
    LogoManager_LUTInitialized = TRUE;
  }

  HDD_TAP_PopDir();
}
