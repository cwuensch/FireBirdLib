#include                "FBLib_dialog.h"

tDialogProfile          *FBDialogProfile = NULL;

void ProfileInit(void)
{
  INILOCATION           INILocation;

#ifdef _TMS_
  char                  CurrentDir[FBLIB_DIR_SIZE];
#else
  dword                 CurrentDir;
#endif

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("ProfileInit");
#endif

  if (!FBDialogProfile)
  {

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif

    return;
  }

  FBDialogProfile->BorderColor                       = DEFAULTBorderColor;
  FBDialogProfile->TitleBackgroundColor              = DEFAULTTitleBackgroundColor;
  FBDialogProfile->TitleTextColor                    = DEFAULTTitleTextColor;
  FBDialogProfile->ItemsLineBackgroundColor          = DEFAULTItemsLineBackgroundColor;
  FBDialogProfile->ItemsLineBackgroundSelectedColor  = DEFAULTItemsLineBackgroundSelectedColor;
  FBDialogProfile->ItemsIconBackgroundColor          = DEFAULTItemsIconBackgroundColor;
  FBDialogProfile->ItemsIconBackgroundSelectedColor  = DEFAULTItemsIconBackgroundSelectedColor;
  FBDialogProfile->ItemsTextColor                    = DEFAULTItemsTextColor;
  FBDialogProfile->ItemsTextDisabledColor            = DEFAULTItemsTextDisabledColor;
  FBDialogProfile->ItemsTextSelectedColor            = DEFAULTItemsTextSelectedColor;
  FBDialogProfile->ItemsGridColor                    = DEFAULTItemsGridColor;
  FBDialogProfile->InfoBackgroundColor               = DEFAULTInfoBackgroundColor;
  FBDialogProfile->ScrollBarColor                    = DEFAULTScrollBarColor;
  FBDialogProfile->ScrollScreen                      = DEFAULTScrollScreen;
  FBDialogProfile->ScrollWrapAround                  = DEFAULTScrollWrapAround;
  FBDialogProfile->ProgressBarColor                  = DEFAULTProgressBarColor;
  FBDialogProfile->ButtonIn                          = DEFAULTButtonIn;
  FBDialogProfile->ButtonOut                         = DEFAULTButtonOut;
  FBDialogProfile->Fade                              = DEFAULTFade;
  FBDialogProfile->FontSize                          = DEFAULTFontSize;
  FBDialogProfile->HDDAccess                         = DEFAULTHDDAccess;

  FBDialogProfile->Magic                             = DIALOGPROFILE_MAGIC;

  //Remember the current directory
#ifdef _TMS_
  HDD_TAP_GetCurrentDir(CurrentDir);
#else
  CurrentDir = (dword)HDD_TAP_GetCurrentDirCluster();
#endif

  //Check if the default profile "DialogProfile.ini" exists
  INILocation = INILocateFile (DEFAULTPROFILE, NULL);
  if (INILocation == INILOCATION_NotFound) DialogProfileSave (DEFAULTPROFILE, INILOCATION_AtProgramFiles, NULL);
                                      else DialogProfileLoad (DEFAULTPROFILE, NULL);


#ifdef _TMS_
  if (*CurrentDir) HDD_ChangeDir(CurrentDir);
#else
  if ((int) CurrentDir != -1) HDD_TAP_SetCurrentDirCluster (CurrentDir);
#endif

  ProfileDirty();

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
