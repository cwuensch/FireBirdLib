#ifdef _TMS_
  #include <string.h>
#endif
#include "../libFireBird.h"

//Attention: this function will stay in the directory where it has found the file
//It is up to the caller to use HDD_TAP_PushDir() and HDD_TAP_PopDir()

INILOCATION INILocateFile (char *FileName, char *AppName)
{
  INILOCATION           location = INILOCATION_NotFound;

#ifdef _TMS_
  char                  dir[200] = "";
#else
  dword                 dir = (dword) -1;
#endif

  if (FileName)
  {
    //Current directory?
    if (TAP_Hdd_Exist(FileName)) location = INILOCATION_AtCurrentDir;
    //Else search (which automatically activates tapapifix)
    else
    {
#ifdef _TMS_
      HDD_TAP_GetCurrentDir(dir);
#else
      dir = HDD_TAP_GetCurrentDirCluster();
#endif

      if (HDD_ChangeDir("/ProgramFiles"))
      {
        //Try /ProgramFiles
        if (TAP_Hdd_Exist(FileName))
        {
          location = INILOCATION_AtProgramFiles;

#ifdef _TMS_
          strcpy(dir, "/ProgramFiles");
#else
          dir = HDD_TAP_GetCurrentDirCluster();
#endif
        }

        if (HDD_ChangeDir("Settings"))
        {
          //Try /ProgramFiles/Settings
          if (TAP_Hdd_Exist(FileName))
          {
            location = INILOCATION_AtSettings;
#ifdef _TMS_
            strcpy(dir, "/ProgramFiles/Settings");
#else
            dir = HDD_TAP_GetCurrentDirCluster();
#endif
          }

          //Try /ProgramFiles/Settings/<AppName>
          if (AppName && *AppName && (*AppName != '/') && HDD_ChangeDir(AppName) && TAP_Hdd_Exist(FileName))
          {
            location = INILOCATION_AtAppName;
#ifdef _TMS_
            dir[0] = '\0';
#else
            dir = (dword) -1;
#endif
          }
        }
      }
    }
  }

  //Restore the directory where the file has been found
#ifdef _TMS_
  if (*dir) HDD_ChangeDir(dir);
#else
  if ((int) dir != -1) HDD_TAP_SetCurrentDirCluster(dir);
#endif

  return location;
}
