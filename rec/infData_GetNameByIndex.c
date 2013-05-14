#include <string.h>
#include <tap.h>
#include "FBLib_rec.h"

bool infData_GetNameByIndex(char *infFileName, dword NameIndex, char *NameTag)
{
  bool                  ret;
  tTFRPlusHdr           TFRPlusHdr;
  char                  NameTagHdr[256];
  dword                 CurrentIndex;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_GetNameByIndex");
  #endif

  ret = FALSE;

  if(NameTag && infData_OpenFile(infFileName))
  {
    CurrentIndex = 0;
    TAP_Hdd_Fseek(infDatainfFile, INFDATASTART, SEEK_SET);

    while(TAP_Hdd_Ftell(infDatainfFile) < TAP_Hdd_Flen(infDatainfFile))
    {
      TAP_Hdd_Fread(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFile);

      //Stop parsing if the magic is invalid
      if(memcmp(TFRPlusHdr.Magic, INFDATMAGIC, 4) != 0) break;

      TAP_Hdd_Fread(NameTagHdr, TFRPlusHdr.NameTagLen, 1, infDatainfFile);

      if(NameIndex == CurrentIndex)
      {
        ret = TRUE;
        strcpy(NameTag, NameTagHdr);
        break;
      }

      CurrentIndex++;
      TAP_Hdd_Fseek(infDatainfFile, TFRPlusHdr.PayloadSize, SEEK_CUR);
    }
  }

  infData_CloseFile();

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
