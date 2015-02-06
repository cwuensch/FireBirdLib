#include  <stdio.h>
#include  <fcntl.h>
#include  <sys/stat.h>
#include  <string.h>
#include "stdarg.h"    //va_list
#include  "../libFireBird.h"

int vsnprintf(char *str, size_t size, const char *format, va_list ap);   //define missing prototype

void LogEntryFBLibPrintf(bool Console, char *format, ...)
{
  TRACEENTER();

  char                  Text[512];
  FILE                 *File;
  char                  TimeResult[40];
  byte                  Sec;
  char                  CRLF[] = {'\r', '\n'};

  #define FILENAME      "/mnt/hd/ProgramFiles/Settings/FBLib.log"

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

  TimeFormat(Now(&Sec), Sec, TIMESTAMP_YMDHMS, TimeResult);
  strcat(TimeResult, " ");

  if((File = fopen(FILENAME, "r+")) != NULL)
  {
    fseek(File, 0, SEEK_END);
    fwrite(TimeResult, strlen(TimeResult), 1, File);
    fwrite(Text, strlen(Text), 1, File);
    fwrite(CRLF, 2, 1, File);
    fclose(File);
  }

  if(Console)
  {
    TAP_PrintNet("%s FBLIB - %s\n", TimeResult, Text);
  }

  TRACEEXIT();
}
