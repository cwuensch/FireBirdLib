#ifndef FBLIB_REC_H
#define FBLIB_REC_H

#include                "../libFireBird.h"

#define PCRSECTORS  900

extern tRECSlot         *RECSlot[3];
extern bool             LibInitialized;

bool getRECSlotAddress (void);
word getWord(void *buffer, bool NeedsByteSwapping);
dword getDword(void *buffer, bool NeedsByteSwapping);

void HDD_DecodeRECHeader_Bookmarks(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_CryptInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_EventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_ExtendedEventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_Header(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_ServiceInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_TPInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);

#endif
