#ifdef _TMS_

#include "libFireBird.h"


void KeyTranslate(dword *param1)
{
  dword                 Flags;

  if(!param1) return;

  Flags = *param1 & 0xfffe0000;
  *param1 = *param1 &  0x1ffff;

  switch(TAP_GetSystemId())
  {
    //Nothing to do with these machines as key.h originates from here
    //SRP-2100      (22010)
    //SRP-2400      (22020)
    //SRP-2411(CZ)  (22023)
    //SRP-2100      (22110)
    //SRP-2100      (22210)
    //TRF-2400      (32020)
    //TRF-2460      (32026)


    //Type 2
	  case 22121:     //SRP-2410
    case 22122:     //SRP-2411
    case 22241:     //SRP-2411(CZ)
    {
      switch(*param1)
      {
        case RKEY_F1   :    *param1 = RKEY_NewF1;     break;
      }
    }


	  //Type 3
    case 32030:     //TF7100HD+
    case 33021:     //TRF7160
    case 22120:     //TF2401CI+
    {
      switch(*param1)
      {
        case RKEY_Sleep:    *param1 = 0x10049;        break;
        case RKEY_Bookmark: *param1 = RKEY_VolDown;   break;
        case RKEY_Goto:     *param1 = RKEY_ChUp;      break;
        case RKEY_Check:    *param1 = RKEY_ChDown;    break;
        case RKEY_NewF1:    *param1 = RKEY_VolUp;     break;
        case RKEY_ChUp:     *param1 = RKEY_VFormat;   break;
        case RKEY_VolUp:    *param1 = RKEY_NewF1;     break;
        case RKEY_VolDown:  *param1 = RKEY_Bookmark;  break;
        case 0x10049:       *param1 = RKEY_Goto;      break;
        case 0x1004a:       *param1 = RKEY_Check;     break;
      }
    }
  }

  *param1 = *param1 | Flags;
}

#endif
