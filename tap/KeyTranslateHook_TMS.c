#ifdef _TMS_

#include "libFireBird.h"

dword (*Original_TAP_EventHandler)(word event, dword param1, dword param2) = NULL;

dword KeyTranslateHook(word event, dword param1, dword param2)
{
  dword                 KeyFlags, NativeKeyCode, TranslatedKeyCode;
  dword                 ret;

  if(event == EVT_KEY)
  {
    KeyFlags =      param1 & 0xfffe0000;
    NativeKeyCode = param1 & 0x0001ffff;
    TranslatedKeyCode = NativeKeyCode;

    switch(TAP_GetSystemId())
    {
      //Type 1
      //Nothing to do with these machines as key.h originates from there

	    //Type 2
      case 32030:     //TF7100HD+
      case 33021:     //TRF7160
      case 22120:     //TF2401CI+
      {
        switch(NativeKeyCode)
        {
          case RKEY_Sleep:    TranslatedKeyCode = 0x10049;        break;
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
        break;
      }
    }

    ret = Original_TAP_EventHandler(EVT_KEY, TranslatedKeyCode | KeyFlags, param2);

    return (ret ? NativeKeyCode | KeyFlags : 0);
  }

  ret = Original_TAP_EventHandler(event, param1, param2);

  return ret;
}

bool KeyTranslate(bool Enable, void *EventHandler)
{
  tTMSTAPTaskTable     *TMSTAPTaskTable;
  dword                *curTAPTask;

  //Get the address to the TAP table
  TMSTAPTaskTable = (tTMSTAPTaskTable*)FIS_vTAPTable();
  if(!TMSTAPTaskTable) return FALSE;

  //Get the pointer to the currently active TAP index
  curTAPTask = (dword*)FIS_vcurTapTask();
  if(!curTAPTask) return FALSE;

  if(Enable && (TMSTAPTaskTable[*curTAPTask].TAP_EventHandler == (dword)EventHandler))
  {
    Original_TAP_EventHandler = (void*)TMSTAPTaskTable[*curTAPTask].TAP_EventHandler;
    TMSTAPTaskTable[*curTAPTask].TAP_EventHandler = (dword)&KeyTranslateHook;

    return TRUE;
  }
  else if(!Enable && (TMSTAPTaskTable[*curTAPTask].TAP_EventHandler == (dword)KeyTranslateHook))
  {
    TMSTAPTaskTable[*curTAPTask].TAP_EventHandler = (dword)Original_TAP_EventHandler;
    Original_TAP_EventHandler = NULL;

    return TRUE;
  }

  return FALSE;
}

#endif
