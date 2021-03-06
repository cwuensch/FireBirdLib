#include                <stdio.h>
#include                <string.h>
#include                <stdarg.h>    //va_list
#include                <sys/stat.h>  //mkdir
#include                <utime.h>
#define                 FB_LOG_ENTRY_LIB_PRINTF
#include                "libFireBird.h"

void LogEntryFBLibPrintf(bool Console, char *format, ...)
{
  TRACEENTER();

  char                  Text[512];
  FILE                 *File;
  char                 *TS;
  byte                  Sec;
  char                  CRLF[] = {'\r', '\n'};
  struct utimbuf        times;

  #define FILENAME      TAPFSROOT "/ProgramFiles/Settings/FBLib.log"

  if(!format)
  {
    TRACEEXIT();
    return;
  }

  va_list args;
  va_start(args, format);
  vsnprintf(Text, sizeof(Text), format, args);
  va_end(args);

  mkdir("/mnt/hd/ProgramFiles/Settings", 0777);

  TS = TimeFormat(Now(&Sec), Sec, TIMESTAMP_YMDHMS);
  strcat(TS, " ");

  if((File = fopen(FILENAME, "a")) != NULL)
  {
    fwrite(TS, strlen(TS), 1, File);
    fwrite(Text, strlen(Text), 1, File);
    fwrite(CRLF, 2, 1, File);
    fclose(File);

    //As the log would receive the Linux time stamp (01.01.2000), adjust to the PVR's time
    times.actime = PvrTimeToLinux(Now(NULL));
    times.modtime = times.actime;
    utime(FILENAME, &times);
  }

  if(Console)
  {
    TAP_Print("%s FBLIB - %s\n", TS, Text);
  }

  TRACEEXIT();
}
