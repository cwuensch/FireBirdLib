#include                <string.h>
#include                "FBLib_flash.h"

bool FlashADSetInfo(tAutoDescrambleTimer *ADTimer)
{
  //ADTimer is NULL
  if(!ADTimer) return FALSE;

  switch(GetSystemType())
  {
    //Unknown and old 5k/6k systems are not supported
    case ST_UNKNOWN:
    case ST_S:
    case ST_ST:
    case ST_T:
    case ST_C:
    case ST_CT:
    case ST_T5700:
    case ST_TUK:  return FALSE;

    case ST_TMSS:
    {
      TYPE_AutoDescrambleTimer  *p;

      p = (TYPE_AutoDescrambleTimer*)(FIS_vFlashBlockAutoDec());
      if(!p) return FALSE;

      return FlashADEncode(p, ADTimer);
    }

    case ST_TMST:
    {
      TYPE_AutoDescrambleTimer  *p;

      p = (TYPE_AutoDescrambleTimer*)(FIS_vFlashBlockAutoDec());
      if(!p) return FALSE;

      return FlashADEncode(p, ADTimer);
    }

    case ST_TMSC:
    {
      TYPE_AutoDescrambleTimer  *p;

      p = (TYPE_AutoDescrambleTimer*)(FIS_vFlashBlockAutoDec());
      if(!p) return FALSE;

      return FlashADEncode(p, ADTimer);
    }

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashADEncode(void *Data, tAutoDescrambleTimer *ADTimer)
{
  //ADTimer is NULL
  if(!Data || !ADTimer) return FALSE;

  switch(GetSystemType())
  {
    //Unknown and old 5k/6k systems are not supported
    case ST_UNKNOWN:
    case ST_S:
    case ST_ST:
    case ST_T:
    case ST_C:
    case ST_CT:
    case ST_T5700:
    case ST_TUK:  return FALSE;

    case ST_TMSS: return FlashADEncode_ST_TMSS(Data, ADTimer);
    case ST_TMST: return FlashADEncode_ST_TMST(Data, ADTimer);
    case ST_TMSC: return FlashADEncode_ST_TMSC(Data, ADTimer);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashADEncode_ST_TMSS(TYPE_AutoDescrambleTimer *Data, tAutoDescrambleTimer *ADTimer)
{
  int                   i;

  memset(Data, 0, sizeof(TYPE_AutoDescrambleTimer));
  Data->StartTime        = ADTimer->StartTime;
  Data->EndTime          = ADTimer->EndTime;
  Data->Duration         = ADTimer->Duration;
  Data->ReservationType  = ADTimer->ReservationType;
  Data->DelOrig          = ADTimer->DelOrig;
  Data->NrOfFiles        = ADTimer->NrOfFiles;
  Data->TotalTime        = ADTimer->TotalTime;
  Data->unknown1         = ADTimer->unknown1;
  Data->unknown2         = ADTimer->unknown2;
  Data->unknown3         = ADTimer->unknown3;

  for(i = 0; i < 50; i++)
    strncpy(Data->FileName[i], ADTimer->FileName[i], MAX_FILE_NAME_SIZE);

  return TRUE;
}

bool FlashADEncode_ST_TMSC(TYPE_AutoDescrambleTimer *Data, tAutoDescrambleTimer *ADTimer)
{
  return FlashADEncode_ST_TMSS(Data, ADTimer);
}

bool FlashADEncode_ST_TMST(TYPE_AutoDescrambleTimer *Data, tAutoDescrambleTimer *ADTimer)
{
  return FlashADEncode_ST_TMSS(Data, ADTimer);
}
