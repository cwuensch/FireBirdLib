#ifndef FBLIB_REC_H
#define FBLIB_REC_H

#include                "../libFireBird.h"

#define PCRSECTORS  900

extern tRECSlot         *RECSlot[3];
extern bool             LibInitialized;

bool getRECSlotAddress (void);
word getWord(void *buffer, bool NeedsByteSwapping);
dword getDword(void *buffer, bool NeedsByteSwapping);

                           //unknown 5kS     5kT     5kC     5kT5700 5kUK    TMSs
dword OffsetServiceInfo[] = {     0, 0x000e, 0x000e, 0x000e, 0x000e, 0x000e, 0x001c};
dword OffsetTPInfo[]      = {     0, 0x0034, 0x0034, 0x0034, 0x0038, 0x0038, 0x0570};
dword OffsetEventInfo[]   = {     0, 0x0044, 0x0044, 0x0040, 0x0050, 0x0048, 0x0044};
dword OffsetExtEventInfo[]= {     0, 0x0168, 0x0168, 0x0164, 0x0174, 0x016c, 0x0168};
dword OffsetCryptInfo[]   = {     0, 0x0570, 0x0570, 0x056c, 0x057c, 0x0574,      0};
dword OffsetBookmarks[]   = {     0, 0x0578, 0x0578, 0x0574, 0x0584, 0x057c, 0x0584};

void HDD_DecodeRECHeader_Bookmarks(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_CryptInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_EventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_ExtendedEventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_Header(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_ServiceInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_DecodeRECHeader_TPInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);

void HDD_EncodeRECHeader_Header(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_EncodeRECHeader_ServiceInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_EncodeRECHeader_TPInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_EncodeRECHeader_EventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_EncodeRECHeader_ExtendedEventInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_EncodeRECHeader_CryptInfo(char *Buffer, tRECHeaderInfo *RECHeaderInfo);
void HDD_EncodeRECHeader_Bookmarks(char *Buffer, tRECHeaderInfo *RECHeaderInfo);

#endif
