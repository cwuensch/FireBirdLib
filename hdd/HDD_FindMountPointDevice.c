#include                <stdio.h>
#include                <stdlib.h>
#include                <mntent.h>
#include                <string.h>
#include                "libFireBird.h"

bool HDD_FindMountPointDevice(const char *AbsPath, char *const OutMountPoint, char *const OutDeviceNode)  // OutMountPoint und OutDeviceNode: max. FBLIB_DIR_SIZE (inkl. Nullchar)
{
  TRACEENTER();

  struct mntent        *ent;
  FILE                 *aFile;
  char                  Root[FBLIB_DIR_SIZE], Dev[FBLIB_DIR_SIZE];
  char                 *x;

  Root[0] = '\0';
  Dev[0] = '\0';

  if(AbsPath && AbsPath[0])
  {
    aFile = setmntent("/proc/mounts", "r");
    if(aFile != NULL)
    {
      while((ent = getmntent(aFile)) != NULL)
      {
        x = ansicstr(ent->mnt_dir, strlen(ent->mnt_dir), 0, NULL, NULL);
        if(x)
        {
          if((strncmp(AbsPath, x, strlen(x)) == 0) && (strlen(x) > strlen(Root)))
          {
            snprintf(Root, sizeof(Root) - 1, x);
            snprintf(Dev, sizeof(Dev) - 1, ent->mnt_fsname);
          }
          TAP_MemFree(x);
        }
        else if((strncmp(AbsPath, ent->mnt_dir, strlen(ent->mnt_dir)) == 0) && (strlen(ent->mnt_dir) > strlen(Root)))
        {
          snprintf(Root, sizeof(Root) - 1, ent->mnt_dir);
          snprintf(Dev, sizeof(Dev) - 1, ent->mnt_fsname);
        }
      }
      endmntent(aFile);
    }
    if(Root[0] && (Root[strlen(Root) - 1] != '/')) strcat(Root, "/");
    if(Dev[0] && (Dev[strlen(Dev) - 1] != '/')) strcat(Dev, "/");
  }

  if(OutMountPoint) strcpy(OutMountPoint, Root);
  if(OutDeviceNode) strcpy(OutDeviceNode, Dev);

  TRACEEXIT();
  return (Root[0] != '\0');
}
