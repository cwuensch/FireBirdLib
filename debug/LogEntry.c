#include  <stdio.h>
#include  <string.h>
#include  "../libFireBird.h"

void LogEntry(char *FileName, char *ProgramName, bool Console, eTimeStampFormat TimeStampFormat, char *Text)
{
  TYPE_File             *File;
  char                  *TS;
  char                  CRLF[] = {'\r', '\n'};
  byte                  Sec;

  TS = TimeFormat(Now (&Sec), Sec, TimeStampFormat);
  if (TS [0]) strcat (TS, " ");

  if (FileName && FileName [0])
  {
    TAP_Hdd_Create (FileName, ATTR_NORMAL);
    if((File = TAP_Hdd_Fopen (FileName)) != NULL)
    {
      TAP_Hdd_Fseek (File, 0, SEEK_END);
      TAP_Hdd_Fwrite (TS, strlen (TS), 1, File);
      if (Text && Text [0]) TAP_Hdd_Fwrite (Text, strlen (Text), 1, File);
      TAP_Hdd_Fwrite (CRLF, 2, 1, File);
      TAP_Hdd_Fclose (File);
    }
  }

  if (Console)
  {
    if (TimeStampFormat != TIMESTAMP_NONE) TAP_Print (TS);
    if (ProgramName && ProgramName [0]) TAP_Print ("%s: ", ProgramName);
    if (Text && Text [0]) TAP_Print ("%s", Text);
    TAP_Print ("\n");
  }
}
