#include                <stdio.h>
#include                <string.h>
#include                <utime.h>
#include                "../libFireBird.h"

void LogEntry(char *FileName, char *ProgramName, bool Console, eTimeStampFormat TimeStampFormat, char *Text)
{
  char                  AbsFileName[FBLIB_DIR_SIZE], CurDir[FBLIB_DIR_SIZE];
  FILE                 *f;
  char                 *TS;
  char                  CRLF[] = {'\r', '\n'};
  byte                  Sec;
  struct utimbuf        times;

  TS = TimeFormat(Now (&Sec), Sec, TimeStampFormat);
  if (TS [0]) strcat (TS, " ");

  if (FileName && FileName [0])
  {
    HDD_TAP_GetCurrentDir(CurDir);
    TAP_SPrint(AbsFileName, "%s%s/%s", TAPFSROOT, CurDir, FileName);
    f = fopen(AbsFileName, "a");
    if(f)
    {
      fwrite(TS, strlen(TS), 1, f);
      if(Text && Text[0]) fwrite(Text, strlen(Text), 1, f);
      fwrite(CRLF, 2, 1, f);
      fclose(f);

      //As the log would receive the Linux time stamp (01.01.2000), adjust to the PVR's time
      times.actime = PvrTimeToLinux(Now(NULL));
      times.modtime = times.actime;
      utime(AbsFileName, &times);
    }
  }

  if (Console)
  {
    if (TimeStampFormat != TIMESTAMP_NONE) TAP_Print(TS);
    if (ProgramName && ProgramName [0]) TAP_Print("%s: ", ProgramName);

    //Max length is 512. If above, a buffer overflow may occur
    if(Text && Text [0])
    {
      if(strlen(Text) < 510)
      {
        TAP_Print("%s", Text);
      }
      else
      {
        char *p = Text;

        while(*p)
        {
          int     l;
          char    q;

          l = strlen(p);
          if(l > 510) l = 510;

          q = p[l];
          p[l] = '\0';
          TAP_Print("%s", p);
          p[l] = q;
          p += l;
        }
      }
    }
    TAP_Print("\n");
  }
}
