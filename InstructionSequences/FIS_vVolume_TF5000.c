#include "../libFireBird.h"

#ifndef _TMS_

inline dword FIS_vVolume (void)
{
  static byte          *pvVolume = NULL;
  dword                *p;

  if (!pvVolume)
  {
    //Find the routine where several parameters are initialized. We're interested in the volume,
    // which is set in the 4th opcode (sw $??, ????($gp)) and the VCR2 input switch (4 bytes ahead of the volume byte)

    p = (dword*)FindInstructionSequence ("27bdffe8 afbf0014 2419001f a39997bb",
                                         "ffff0000 ffff0000 ffe0ffff ffe00000",
                                         0x80070000, 0x80100000, 0, FALSE);

    if (!p) p = (dword*)FindInstructionSequence ("27bdffe8 afbf0014 a380839a 24190055 a3999a53",
                                                 "ffff0000 ffff0000 ffff0000 ffe0ffff ffe00000",
                                                 0x80070000, 0x80100000, 1, FALSE);

    if (!p) p = (dword*)FindInstructionSequence ("27bdffe8 afbf0014 a380839a 2419001f a3999a53",
                                                 "ffff0000 ffff0000 ffff0000 ffe0ffff ffe00000",
                                                 0x80070000, 0x80100000, 1, FALSE);

    if (!p) p = (dword*)FindInstructionSequence ("27bdffe8 afbf0014 24190055 a39997bb",
                                                 "ffff0000 ffff0000 ffe0ffff ffe00000",
                                                 0x80070000, 0x80100000, 0, FALSE);

    if (!p) return 0;

    pvVolume = (byte*) (FIS_GetGP((dword*)0x80000000) + (short)(p [3] & 0x0000ffff));
  }

  return (dword)pvVolume;
}

#endif
