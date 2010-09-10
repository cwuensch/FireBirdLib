#include "FBLib_rec.h"

dword HDD_NumberOfRECSlots(void)
{
  switch(TAP_GetSystemId())
  {
    case 22120:
    case 22121:
    case 22122:
    case 32030:
    case 33021:
    case 32020:
    case 32026:
      return 4;
  }

  return 2;
}
