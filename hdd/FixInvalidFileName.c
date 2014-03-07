#include <stdio.h>
#include <string.h>
#include "../libFireBird.h"

void FixInvalidFileName(char *FileName)
{
  TRACEENTER();

  char                  NewRecName[TS_FILE_NAME_SIZE+1];

  if(FileName && *FileName && TAP_Hdd_Exist(FileName))
  {
    //Check if the file is busy
    if(HDD_isFileInUse(FileName) != FIU_No)
    {
      TRACEEXIT();

      return;
    }

    strcpy(NewRecName, FileName);

    //If necessary, convert to UTF8
    if(isUTFToppy())
    {
      //Use ISO 8859-9 as the default encoding table
      StrMkUTF8(NewRecName, 9);
    }
    else
    {
      MakeValidFileName(NewRecName, ControlChars);
    }

    if(!strcmp(FileName, NewRecName))
    {
      //No need to rename
      TRACEEXIT();
      return;
    }

    MakeUniqueFileName(NewRecName);
    HDD_Rename(FileName, NewRecName);
    strcpy(FileName, NewRecName);
    FileName[strlen(NewRecName)] = '\0';
  }

  TRACEEXIT();
}
