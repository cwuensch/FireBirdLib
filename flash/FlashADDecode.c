#include                <string.h>
#include                "FBLib_flash.h"

bool FlashADGetInfo(tAutoDescrambleTimer *ADTimer)
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

      return FlashADDecode(p, ADTimer);
    }

    case ST_TMST:
    {
      TYPE_AutoDescrambleTimer  *p;

      p = (TYPE_AutoDescrambleTimer*)(FIS_vFlashBlockAutoDec());
      if(!p) return FALSE;

      return FlashADDecode(p, ADTimer);
    }

    case ST_TMSC:
    {
      TYPE_AutoDescrambleTimer  *p;

      p = (TYPE_AutoDescrambleTimer*)(FIS_vFlashBlockAutoDec());
      if(!p) return FALSE;

      return FlashADDecode(p, ADTimer);
    }

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashADDecode(void *Data, tAutoDescrambleTimer *ADTimer)
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

    case ST_TMSS: return FlashADDecode_ST_TMSS(Data, ADTimer);
    case ST_TMST: return FlashADDecode_ST_TMST(Data, ADTimer);
    case ST_TMSC: return FlashADDecode_ST_TMSC(Data, ADTimer);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashADDecode_ST_TMSS(TYPE_AutoDescrambleTimer *Data, tAutoDescrambleTimer *ADTimer)
{
  int                        i;

  memset(ADTimer, 0, sizeof(tAutoDescrambleTimer));
  ADTimer->StartTime        = Data->StartTime;
  ADTimer->EndTime          = Data->EndTime;
  ADTimer->Duration         = Data->Duration;
  ADTimer->ReservationType  = Data->ReservationType;
  ADTimer->DelOrig          = Data->DelOrig;
  ADTimer->NrOfFiles        = Data->NrOfFiles;
  ADTimer->TotalTime        = Data->TotalTime;
  ADTimer->unknown1         = Data->unknown1;
  ADTimer->unknown2         = Data->unknown2;
  ADTimer->unknown3         = Data->unknown3;

  for(i = 0; i < 50; i++)
    strncpy(ADTimer->FileName[i], Data->FileName[i], MAX_FILE_NAME_SIZE);

  return TRUE;
}

bool FlashADDecode_ST_TMSC(TYPE_AutoDescrambleTimer *Data, tAutoDescrambleTimer *ADTimer)
{
  return FlashADDecode_ST_TMSS(Data, ADTimer);
}

bool FlashADDecode_ST_TMST(TYPE_AutoDescrambleTimer *Data, tAutoDescrambleTimer *ADTimer)
{
  return FlashADDecode_ST_TMSS(Data, ADTimer);
}
