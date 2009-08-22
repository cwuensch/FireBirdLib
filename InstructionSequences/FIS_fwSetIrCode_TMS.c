#include "../libFireBird.h"

#ifdef _TMS_

inline dword FIS_fwSetIrCode(void)
{
  static dword          fwSetIrCode = 0;

  if (!fwSetIrCode)
  {
    fwSetIrCode = TryResolve("DevFront_SetIrCode");
    if(!fwSetIrCode)
    {
      //fwSetIrCode = (FindInstructionSequence("3c058011 24a5aea0 3404ef00 00003025 0c054a82 24070064",
      //                                       "FFFF0000 FFFF0000 FFFFFFFF FFFFFFFF FC000000 FFFFFFFF",
      //                                        0x800C0000, 0x80180000, 0, FALSE);
    }
  }

  return fwSetIrCode;
}

#endif
