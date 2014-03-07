#include                <string.h>
#include                "../libFireBird.h"

//Note: on the TMS, make sure that FileName points to .rec and not to .rec.inf

tFileInUse HDD_isFileInUse(char *FileName)
{
  TRACEENTER();

  TYPE_PlayInfo         PlayInfo;
  TYPE_RecInfo          RecInfo;
  char                  CorrectedFileName[TS_FILE_NAME_SIZE];
  int                   i, NrRecSlots;

  if(!FileName || !*FileName)
  {
    TRACEEXIT();
    return FIU_No;
  }

  TAP_Hdd_GetPlayInfo(&PlayInfo);
  if(PlayInfo.playMode && PlayInfo.totalBlock > 0)
  {
    strcpy(CorrectedFileName, PlayInfo.file->name);
    if(StringEndsWith(CorrectedFileName, ".rec.inf") || StringEndsWith(CorrectedFileName, ".mpg.inf")) CorrectedFileName[strlen(CorrectedFileName) - 4] = '\0';
    if(!strcmp(FileName, CorrectedFileName))
    {
      if(PlayInfo.playMode == PLAYMODE_Mp3)
      {
        TRACEEXIT();
        return FIU_PlayMP3;
      }
      else
      {
        TRACEEXIT();
        return FIU_Playback;
      }
    }
  }

  NrRecSlots = (int)HDD_NumberOfRECSlots();
  for(i = 0; i < NrRecSlots; i++)
  {
    TAP_Hdd_GetRecInfo(i, &RecInfo);
    if(RecInfo.fileName && RecInfo.fileName[0])
    {
      if(StringEndsWith(RecInfo.fileName, ".rec.inf") || StringEndsWith(RecInfo.fileName, ".mpg.inf")) RecInfo.fileName[strlen(RecInfo.fileName) - 4] = '\0';
      if(!strcmp(FileName, RecInfo.fileName))
      {
        TRACEEXIT();
        return (FIU_RecSlot1 + i);
      }
    }
  }

  TRACEEXIT();
  return FIU_No;
}
