#include <tap.h>
#include "FBLib_rec.h"

bool infData_Delete(char *infFileName, char *NameTag)
{
  bool                  ret;
  dword                 SourcePos, DestPos, Len;
  tTFRPlusHdr           TFRPlusHdr;
  char                  NameTagHdr[512], s[256];
  byte                  *Data;

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceEnter("infData_Delete");
  #endif

  ret = FALSE;

  if(NameTag && *NameTag && infData_OpenFile(infFileName) && infData_LocateSig(NameTag, NULL))
  {
    ret = TRUE;

    //Now the file pointer is located at the beginning of the data block
    //which should be deleted.
    DestPos = TAP_Hdd_Ftell(infDatainfFile);
    TAP_Hdd_Fread(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFile);
    Len = sizeof(tTFRPlusHdr) + TFRPlusHdr.NameTagLen + TFRPlusHdr.PayloadSize;
    SourcePos = DestPos + Len;
    TAP_Hdd_Fseek(infDatainfFile, SourcePos, SEEK_SET);

    while(SourcePos < TAP_Hdd_Flen(infDatainfFile))
    {
      //Stop if we're unable to read the whole header
      if(TAP_Hdd_Fread(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFile) == 0) break;

      //Stop parsing if the magic is invalid
      if(memcmp(TFRPlusHdr.Magic, INFDATMAGIC, 4) != 0) break;

      Len = sizeof(tTFRPlusHdr) + TFRPlusHdr.NameTagLen + TFRPlusHdr.PayloadSize;

      TAP_Hdd_Fread(NameTagHdr, TFRPlusHdr.NameTagLen, 1, infDatainfFile);

      if(TFRPlusHdr.PayloadSize)
      {
        Data = TAP_MemAlloc(TFRPlusHdr.PayloadSize);
        if(Data)
        {
          TAP_Hdd_Fread(Data, TFRPlusHdr.PayloadSize, 1, infDatainfFile);
        }
        else
        {
          TAP_SPrint(s, "failed to reserve %d bytes for deletion of %s:%s\n", TFRPlusHdr.PayloadSize, infFileName, NameTagHdr);
          LogEntryFBLibPrintf(TRUE, "infData: %s", s);
          TFRPlusHdr.PayloadSize = 0;
        }
      }
      else
        Data = NULL;

      TAP_Hdd_Fseek(infDatainfFile, DestPos, SEEK_SET);
      TAP_Hdd_Fwrite(&TFRPlusHdr, sizeof(tTFRPlusHdr), 1, infDatainfFile);
      TAP_Hdd_Fwrite(NameTagHdr, TFRPlusHdr.NameTagLen, 1, infDatainfFile);

      if(Data)
      {
        TAP_Hdd_Fwrite(Data, TFRPlusHdr.PayloadSize, 1, infDatainfFile);
        TAP_MemFree(Data);
      }

      DestPos += Len;
      SourcePos += Len;

      TAP_Hdd_Fseek(infDatainfFile, SourcePos, SEEK_SET);
    }
    infData_Truncate(infFileName, DestPos);
  }

  infData_CloseFile();

  #ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
  #endif

  return ret;
}
