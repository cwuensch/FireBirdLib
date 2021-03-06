#include "FBLib_tap.h"

dword (*Original_TAP_EventHandler)(word event, dword param1, dword param2) = NULL;

REMOTE_TYPE             RemoteType = RT_2100;

dword KeyTranslateHook(word event, dword param1, dword param2)
{
  TRACEENTER();

  dword                 KeyFlags, NativeKeyCode, TranslatedKeyCode;
  dword                 ret;

  if(event == EVT_KEY)
  {
    KeyFlags =      param1 & 0xfffe0000;
    NativeKeyCode = param1 & 0x0001ffff;
    TranslatedKeyCode = NativeKeyCode;

    //Nothing to do for RT_5000 and RT_2100
    if(RemoteType == RT_7100PLUS)
    {
      switch(NativeKeyCode)
      {
        case RKEY_Ab:       TranslatedKeyCode = 0x10049;        break;
        case RKEY_Bookmark: TranslatedKeyCode = RKEY_VolDown;   break;
        case RKEY_Goto:     TranslatedKeyCode = RKEY_ChUp;      break;
        case RKEY_Check:    TranslatedKeyCode = RKEY_ChDown;    break;
        case RKEY_NewF1:    TranslatedKeyCode = RKEY_VolUp;     break;
        case RKEY_ChUp:     TranslatedKeyCode = RKEY_VFormat;   break;
        case RKEY_VolUp:    TranslatedKeyCode = RKEY_NewF1;     break;
        case RKEY_VolDown:  TranslatedKeyCode = RKEY_Bookmark;  break;
        case 0x10049:       TranslatedKeyCode = RKEY_Goto;      break;
        case 0x1004a:       TranslatedKeyCode = RKEY_Check;     break;
      }
    }

    if(RemoteType == RT_7260PLUS)
    {
      switch(NativeKeyCode)
      {
        case RKEY_F1:       TranslatedKeyCode = RKEY_NewF1;     break;
      }
    }

    ret = Original_TAP_EventHandler(EVT_KEY, TranslatedKeyCode | KeyFlags, param2);

    TRACEEXIT();
    return (ret ? NativeKeyCode | KeyFlags : 0);
  }

  ret = Original_TAP_EventHandler(event, param1, param2);

  TRACEEXIT();
  return ret;
}

bool KeyTranslate(bool Enable, void *EventHandler)
{
  tTMSTAPTaskTable     *TMSTAPTaskTable;
  dword                 i;
  tToppyInfo           *ToppyInfo;
  tFWDATHeader         *FWDatHeader;

  TRACEENTER();

  //Get the address to the TAP table
  TMSTAPTaskTable = (tTMSTAPTaskTable*)FIS_vTAPTable();
  if(!TMSTAPTaskTable || (!LibInitialized && !InitTAPex()))
  {
    TRACEEXIT();
    return FALSE;
  }

  //Get toppy information
  if(Enable && LoadFirmwareDat(&FWDatHeader, &ToppyInfo, NULL))
  {
    for(i = 0; i < FWDatHeader->NrOfToppyInfoEntries; i++, ToppyInfo++)
    {
      if(ToppyInfo->SysID == TAP_GetSystemId())
      {
        RemoteType = ToppyInfo->RemoteType;
        break;
      }
    }

    if((RemoteType != RT_5000) && (RemoteType != RT_2100))
    {
      if(TMSTAPTaskTable[TAP_TableIndex].TAP_EventHandler == (dword)EventHandler)
      {
        Original_TAP_EventHandler = (void*)TMSTAPTaskTable[TAP_TableIndex].TAP_EventHandler;
        TMSTAPTaskTable[TAP_TableIndex].TAP_EventHandler = (dword)&KeyTranslateHook;

        TRACEEXIT();
        return TRUE;
      }
    }
  }

  if(!Enable && (TMSTAPTaskTable[TAP_TableIndex].TAP_EventHandler == (dword)KeyTranslateHook))
  {
    TMSTAPTaskTable[TAP_TableIndex].TAP_EventHandler = (dword)Original_TAP_EventHandler;
    Original_TAP_EventHandler = NULL;

    TRACEEXIT();
    return TRUE;
  }

  TRACEEXIT();
  return FALSE;
}
