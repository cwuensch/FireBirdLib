#include                <string.h>
#include                "FBLib_flash.h"

bool FlashServiceDecode(void *Data, tFlashService *Service)
{
  //Service is NULL
  if(!Data || !Service) return FALSE;

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
    case ST_T5800:
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS: return FlashServiceDecode_ST_TMSS(Data, Service);
    case ST_TMST: return FlashServiceDecode_ST_TMST(Data, Service);
    case ST_TMSC: return FlashServiceDecode_ST_TMSC(Data, Service);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceDecode_ST_TMSS(TYPE_Service_TMSS *Data, tFlashService *Service)
{

  char                 *Text;

  memset(Service, 0, sizeof(tFlashService));
  Service->SatIndex        = Data->SatIdx;
  Service->VideoStreamType = Data->VideoStreamType;
  Service->FlagDelete      = Data->DelFlag;
  Service->FlagCAS         = Data->CASFlag;
  Service->FlagLock        = Data->LockFlag;
  Service->FlagSkip        = Data->SkipFlag;
  Service->Tuner           = Data->TunerNum;
  Service->TransponderIndex= Data->TPIdx;
  Service->ServiceID       = Data->SVCID;
  Service->PMTPID          = Data->PMTPID;
  Service->PCRPID          = Data->PCRPID;
  Service->VideoPID        = Data->VideoPID;
  Service->AudioPID        = Data->AudioPID;
  Service->LCN             = Data->LCN;
  Service->AudioStreamType = Data->AudioStreamType;
  Service->unknown1        = Data->unknown1;
  memcpy(Service->unknown2, Data->unknown2, 6);

  Text = (char*)(FIS_vFlashBlockServiceName() + Data->NameOffset);
  strncpy(Service->ServiceName, Text, MAX_SvcName - 1);

  Text = (char*)(FIS_vFlashBlockProviderInfo() + 21 * Data->ProviderIdx);
  strncpy(Service->ProviderName, Text, 20);

  return TRUE;
}

bool FlashServiceDecode_ST_TMST(TYPE_Service_TMST *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceDecode_ST_TMSS(Data, Service);
}

bool FlashServiceDecode_ST_TMSC(TYPE_Service_TMSC *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceDecode_ST_TMSS(Data, Service);
}


bool FlashServiceEncode(void *Data, tFlashService *Service)
{
  //Service is NULL
  if(!Data || !Service) return FALSE;

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
    case ST_T5800:
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS: return FlashServiceEncode_ST_TMSS(Data, Service);
    case ST_TMST: return FlashServiceEncode_ST_TMST(Data, Service);
    case ST_TMSC: return FlashServiceEncode_ST_TMSC(Data, Service);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceEncode_ST_TMSS(TYPE_Service_TMSS *Data, tFlashService *Service)
{

  char                 *Text;

  memset(Data, 0, sizeof(TYPE_Service_TMSS));
  Data->SatIdx          = Service->SatIndex;
  Data->VideoStreamType = Service->VideoStreamType;
  Data->DelFlag         = Service->FlagDelete;
  Data->CASFlag         = Service->FlagCAS;
  Data->LockFlag        = Service->FlagLock;
  Data->SkipFlag        = Service->FlagSkip;
  Data->TunerNum        = Service->Tuner;
  Data->TPIdx           = Service->TransponderIndex;
  Data->SVCID           = Service->ServiceID;
  Data->PMTPID          = Service->PMTPID;
  Data->PCRPID          = Service->PCRPID;
  Data->VideoPID        = Service->VideoPID;
  Data->AudioPID        = Service->AudioPID;
  Data->LCN             = Service->LCN;
  Data->AudioStreamType = Service->AudioStreamType;
  Data->unknown1        = Service->unknown1;
  memcpy(Data->unknown2, Service->unknown2, 6);

  Text = (char*)FIS_vFlashBlockServiceName();
  while(Text[0])
  {
    if(strncmp(Text, Service->ServiceName, MAX_SvcName) == 0) break;
    Text += (strlen(Text) + 1);
  }
  if(!Text[0]) strncpy(Text, Service->ServiceName, MAX_SvcName);
  Data->NameOffset = (dword)Text - FIS_vFlashBlockServiceName();

  Text = (char*)FIS_vFlashBlockProviderInfo();
  Data->ProviderIdx = 0;
  while(Text[0])
  {
    if(strncmp(Text, Service->ProviderName, 20) == 0) break;
    Text += 21;
    Data->ProviderIdx = Data->ProviderIdx + 1;
  }
  if(!*Text) strncpy(Text, Service->ProviderName, 20);

  return TRUE;
}

bool FlashServiceEncode_ST_TMST(TYPE_Service_TMST *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceEncode_ST_TMSS(Data, Service);
}

bool FlashServiceEncode_ST_TMSC(TYPE_Service_TMSC *Data, tFlashService *Service)
{
  //The TV and radio service structures are identical
  return FlashServiceEncode_ST_TMSS(Data, Service);
}

bool FlashServiceDelete(void *Data)
{
  //Service is NULL
  if(!Data) return FALSE;

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
    case ST_T5800:
    case ST_TF7k7HDPVR: return FALSE;

    case ST_TMSS: return FlashServiceDelete_ST_TMSS(Data);
    case ST_TMST: return FlashServiceDelete_ST_TMST(Data);
    case ST_TMSC: return FlashServiceDelete_ST_TMSC(Data);

    case ST_NRTYPES: break;
  }

  return FALSE;
}

bool FlashServiceDelete_ST_TMSS(TYPE_Service_TMSS *Data)
{
  TYPE_Service_TMSS    *NextData;

  NextData = Data + 1;

  while(NextData->TunerNum != 0)
  {
    memcpy(Data, NextData, sizeof(TYPE_Service_TMSS));
    Data++;
    NextData++;
  }
  memset(Data, 0, sizeof(TYPE_Service_TMSS));

  return TRUE;
}

bool FlashServiceDelete_ST_TMST(TYPE_Service_TMST *Data)
{
  //The TV and radio service structures are identical
  return FlashServiceDelete_ST_TMSS(Data);
}

bool FlashServiceDelete_ST_TMSC(TYPE_Service_TMSC *Data)
{
  //The TV and radio service structures are identical
  return FlashServiceDelete_ST_TMSS(Data);
}

bool FlashServiceDelServiceName(dword ServiceNameOffset)
{
  int                   NrServices;
  char                 *Text, *d;
  int                   i, l;

  //Check that no TV service references this ServiceNameOffset
  NrServices = FlashServiceGetTotal(SVC_TYPE_Tv);
  for(i = 0; i < NrServices; i++)
  {
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
      case ST_T5800:
      case ST_TF7k7HDPVR: return FALSE;

      case ST_TMSS:
      {
        TYPE_Service_TMSS    *p;

        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockTVServices() + i * sizeof(TYPE_Service_TMSS));
        if(!p || (p->NameOffset == ServiceNameOffset)) return FALSE;
        break;
      }

      case ST_TMST:
      {
        TYPE_Service_TMST    *p;

        p = (TYPE_Service_TMST*)(FIS_vFlashBlockTVServices() + i * sizeof(TYPE_Service_TMST));
        if(!p || (p->NameOffset == ServiceNameOffset)) return FALSE;
        break;
      }

      case ST_TMSC:
      {
        TYPE_Service_TMSC    *p;

        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockTVServices() + i * sizeof(TYPE_Service_TMSC));
        if(!p || (p->NameOffset == ServiceNameOffset)) return FALSE;
        break;
      }

      case ST_NRTYPES: break;
    }
  }

  //Check that no radio service references this ServiceNameOffset
  NrServices = FlashServiceGetTotal(SVC_TYPE_Radio);
  for(i = 0; i < NrServices; i++)
  {
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
      case ST_T5800:
      case ST_TF7k7HDPVR: return FALSE;

      case ST_TMSS:
      {
        TYPE_Service_TMSS    *p;

        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockRadioServices() + i * sizeof(TYPE_Service_TMSS));
        if(!p || (p->NameOffset == ServiceNameOffset)) return FALSE;
        break;
      }

      case ST_TMST:
      {
        TYPE_Service_TMST    *p;

        p = (TYPE_Service_TMST*)(FIS_vFlashBlockRadioServices() + i * sizeof(TYPE_Service_TMST));
        if(!p || (p->NameOffset == ServiceNameOffset)) return FALSE;
        break;
      }

      case ST_TMSC:
      {
        TYPE_Service_TMSC    *p;

        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockRadioServices() + i * sizeof(TYPE_Service_TMSC));
        if(!p || (p->NameOffset == ServiceNameOffset)) return FALSE;
        break;
      }

      case ST_NRTYPES: break;
    }
  }

  //Find the end of the ServiceNameList
  Text = (char*)(FIS_vFlashBlockServiceName() + ServiceNameOffset);
  while(Text[0])
  {
    Text += (strlen(Text) + 1);
  }

  //Move all strings
  d = (char*)FIS_vFlashBlockServiceName() + ServiceNameOffset;
  l = strlen(d) + 1;
  memcpy(d, d + l, Text - d - l);

  //Reindex all TV services
  NrServices = FlashServiceGetTotal(SVC_TYPE_Tv);
  for(i = 0; i < NrServices; i++)
  {
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
      case ST_T5800:
      case ST_TF7k7HDPVR: return FALSE;

      case ST_TMSS:
      {
        TYPE_Service_TMSS    *p;

        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockTVServices() + i * sizeof(TYPE_Service_TMSS));
        if(p && (p->NameOffset > ServiceNameOffset)) p->NameOffset = p->NameOffset - l;
        break;
      }

      case ST_TMST:
      {
        TYPE_Service_TMST    *p;

        p = (TYPE_Service_TMST*)(FIS_vFlashBlockTVServices() + i * sizeof(TYPE_Service_TMST));
        if(p && (p->NameOffset > ServiceNameOffset)) p->NameOffset = p->NameOffset - l;

        break;
      }

      case ST_TMSC:
      {
        TYPE_Service_TMSC    *p;

        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockTVServices() + i * sizeof(TYPE_Service_TMSC));
        if(p && (p->NameOffset > ServiceNameOffset)) p->NameOffset = p->NameOffset - l;
        break;
      }

      case ST_NRTYPES: break;
    }
  }

  //Reindex all radio services
  NrServices = FlashServiceGetTotal(SVC_TYPE_Radio);
  for(i = 0; i < NrServices; i++)
  {
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
      case ST_T5800:
      case ST_TF7k7HDPVR: return FALSE;

      case ST_TMSS:
      {
        TYPE_Service_TMSS    *p;

        p = (TYPE_Service_TMSS*)(FIS_vFlashBlockRadioServices() + i * sizeof(TYPE_Service_TMSS));
        if(p && (p->NameOffset > ServiceNameOffset)) p->NameOffset = p->NameOffset - l;
        break;
      }

      case ST_TMST:
      {
        TYPE_Service_TMST    *p;

        p = (TYPE_Service_TMST*)(FIS_vFlashBlockRadioServices() + i * sizeof(TYPE_Service_TMST));
        if(p && (p->NameOffset > ServiceNameOffset)) p->NameOffset = p->NameOffset - l;
        break;
      }

      case ST_TMSC:
      {
        TYPE_Service_TMSC    *p;

        p = (TYPE_Service_TMSC*)(FIS_vFlashBlockRadioServices() + i * sizeof(TYPE_Service_TMSC));
        if(p && (p->NameOffset > ServiceNameOffset)) p->NameOffset = p->NameOffset - l;
        break;
      }
      case ST_NRTYPES: break;
    }
  }

  return TRUE;
}
