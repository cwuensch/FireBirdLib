#include "../flash/FBLib_flash.h"

inline dword FIS_vRECSlotAddress(byte Slot)
{
  static byte          *_pvrRecInfo = NULL;
  dword                 StructSize = sizeof(TYPE_Timer_TMSS);

  if (Slot > HDD_NumberOfRECSlots()) return 0;

  if(!_pvrRecInfo)
  {
    _pvrRecInfo = (byte*)TryResolve("_pvrRecInfo");

    switch(GetSystemType())
    {
      case ST_UNKNOWN:
      case ST_S:
      case ST_ST:
      case ST_T:
      case ST_C:
      case ST_CT:
      case ST_T5700:
      case ST_TUK:
        //No break to return any arbitrary value.

      case ST_TMSS:
      {
        StructSize = sizeof(TYPE_Timer_TMSS);
        break;
      }

      case ST_TMST:
      {
        StructSize = sizeof(TYPE_Timer_TMST);
        break;
      }

      case ST_TMSC:
      {
        StructSize = sizeof(TYPE_Timer_TMSC);
        break;
      }

      case ST_NRTYPES: break;
    }
  }

  if(!_pvrRecInfo) return 0;

  return (dword)&_pvrRecInfo[Slot * StructSize];
}
