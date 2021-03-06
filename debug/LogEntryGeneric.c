#include                <stdio.h>
#include                <string.h>
#include                <utime.h>
#include                "../libFireBird.h"

void LogEntryGeneric(char *ProgramName, bool Console, char *Text)
{
  char                 *s;
  int                   l;
  FILE                 *f;
  char                 *TS;
  char                  CRLF[] = {'\r', '\n'};
  byte                  Sec;
  struct utimbuf        times;

#define ABSFILENAME     TAPFSROOT "/ProgramFiles/Settings/TAPSystem.log"

  HDD_TAP_PushDir();
  if(!HDD_ChangeDir("/ProgramFiles/Settings"))
  {
    HDD_ChangeDir("/ProgramFiles");
    if(!TAP_Hdd_Exist("Settings")) TAP_Hdd_Create("Settings", ATTR_FOLDER);
    HDD_ChangeDir("Settings");
  }
  l = strlen(ProgramName) + strlen(Text) + 4;
  s = TAP_MemAlloc(l);
  memset(s, 0, l);
  TAP_SPrint(s, "%s: %s", ProgramName, Text);

  TS = TimeFormat(Now(&Sec), Sec, TIMESTAMP_YMDHMS);
  strcat(TS, " ");

  if((f = fopen(ABSFILENAME, "a")) != NULL)
  {
    fwrite(TS, strlen(TS), 1, f);
    fwrite(s, strlen(s), 1, f);
    fwrite(CRLF, 2, 1, f);
    fclose(f);

    //As the log would receive the Linux time stamp (01.01.2000), adjust to the PVR's time
    times.actime = PvrTimeToLinux(Now(NULL));
    times.modtime = times.actime;
    utime(ABSFILENAME, &times);
  }

  if (Console)
  {
    TAP_Print("%s%s\n", TS, s);
  }

  HDD_TAP_PopDir();
  TAP_MemFree(s);
}
