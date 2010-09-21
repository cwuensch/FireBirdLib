#include                <sys/types.h>

  /*****************************************************************************************************************************/
  /* Firmware & Low Level                                                                                                      */
  /*****************************************************************************************************************************/

  #define LE16(p)       (p)
  #define LE32(p)       (p)

  byte *GetMacAddress(void);
  char *GetApplVer(void);

  char puffer[512];
  char tracePuffer[512];
  void PrintNet(char *puffer);

#define XDATA                                       //don't use XDATA on the TMS
#define TS_FILE_NAME_SIZE   MAX_FILE_NAME_SIZE      //the name has changed
#define ATTR_PARENT         0xf0                    //FindFirst/FindNext doesn't know about ..

#ifndef PC_BASED
  #define TAP_PrintNet(...) {sprintf(puffer, __VA_ARGS__); PrintNet(puffer);}

  #ifdef _TMS_
    #define TAP_Print   TAP_PrintNet
  #endif
#endif


  /*****************************************************************************************************************************/
  /* FindInstuctionSequnces                                                                                                    */
  /*****************************************************************************************************************************/

  dword TryResolve(char *Function);

  inline dword FIS_fwApplVfdSendData(void);
  inline dword FIS_fwApplVfdStart(void);
  inline dword FIS_fwApplVfdStop(void);
  inline dword FIS_fwPowerOff(void);
  inline dword FIS_fwSetIrCode(void);
  inline dword FIS_vAudioTrack(void);
  inline dword FIS_vMACAddress(void);
  inline dword FIS_vcurTapTask(void);
  inline dword FIS_vgrid(void);
  inline dword FIS_viboxTimerId(void);


  /*****************************************************************************************************************************/
  /* Audio / Video / OSD                                                                                                       */
  /*****************************************************************************************************************************/
  //Forgotten keys
  #define RKEY_White    RKEY_Option

#ifndef TAP_ALPHA
  #define TAP_ALPHA     255
#endif

  typedef struct
  {
    byte                  unused1[4677];
    byte                  NrOfTracks;
    byte                  CurrentTrack;
    byte                  unused2;
    word                  PID[64];
    byte                  StreamType[64];
    char                  StreamName[64][32];
    word                  unknown1[64];
    byte                  unused4[64 * 32];
    dword                 unknown2[64];
  } tAudioTrk;

  tAudioTrk *AudioTrackInfo(void);
  bool CaptureScreen(int BMPwidth, int BMPheight, byte *BMPPixelBuffer, bool bOSD, int Alpha);
  bool isAnyOSDVisibleEx(dword checkX, dword checkY, dword checkW, dword checkH, byte Plane);
  bool isInfoBoxVisible(void);

  /*****************************************************************************************************************************/
  /* Flash & EEPROM                                                                                                            */
  /*****************************************************************************************************************************/

  typedef struct
  {
    short               UTCOffset;
    word                SleepTimer;

    char                Res1:3;
    char                GMTCollection:3;        //0=Normal, 1=CAS Only, 2=User Select
    char                Mode:2;                 //0=Auto, 1=Manual

    char                Res2:7;
    char                TimeOffset:1;           //0=Manual, 1=Automatic

    char                DST:2;                  //0=off, 3=on
    char                Res3:6;

    char                Res4;
  }TYPE_ClockSetup;

  //TODO: really keep that one?
  typedef struct
  {
    word                etcCRC;
    word                TvSubSvcNum;
    word                TvSvcNum;
    word                RadioSvcNum;
    word                TvOldSvcNum;
    word                RadioOldSvcNum;
    byte                Volume;

    byte                ServiceType:1;
    byte                SoundMode:2;
    byte                ScartOutputSource:2;
    byte                VideoType:2;
    byte                AspectRatio:1;

    byte                Flags;

    byte                RFOutput:3;
    byte                DisableSubTitle:1;
    byte                DisableTeletext:1;
    byte                Format169:2;
    byte                Dolby:1;

    byte                InfoBoxTime;
    byte                ActiveFavNumber;
    byte                CurrentFavGroup;

    byte                InfoBoxPosition:6;
    byte                TVType:2;

    byte                OSDAlpha;

    byte                MovingConfirmBox:1;
    byte                SatDelete:1;
    byte                ScartType:1;
    byte                PIPPosition:2;
    byte                SvcHelpWindow:1;
    byte                TimeShift:1;
    byte                unused1:1;

    byte                CurrentTunerSub;
    byte                CurrentTunerMain;
    word                MultifeedServiceNum;
    byte                UHFChannel;

    byte                unused2 [3];

    byte                TimeFormat:1;
    byte                unused3:1;
    byte                MHEGDisable:1;
    byte                unused4:5;

    byte                unused5 [3];

    word                parentalCRC;
    word                PinCode;
    byte                Rating;

    byte                LockTimeSettings:1;
    byte                LockLanguageSettings:1;
    byte                LockAVSettings:1;
    byte                LockOrganizingServices:1;
    byte                LockOrganizingFavorites:1;
    byte                LockCommonInterface:1;
    byte                LockInstallation:1;
    byte                LockBootLock:1;

    word                languageCRC;
    byte                MenuLanguage;
    byte                TeletextLanguage;
    byte                SubtitleLanguage;
    byte                AudioLanguage;
  }EEPROMSTRUCT;

  dword UTCtoLocal(dword UTCTime);

  /**********************************************************************************/
  /* TMS specific definitions                                                       */
  /**********************************************************************************/

  //Warning: the TMS uses a little endian processor and therefore
  //bitfields start with the least significant bit
  typedef struct
  {
    byte                SatIdx;
    byte                VideoStreamType;

    word                TPIdx:10;
    word                TunerNum:2;
    word                SkipFlag:1;
    word                LockFlag:1;
    word                CASFlag:1;
    word                DelFlag:1;

    word                SVCID;
    word                PMTPID;
    word                PCRPID;
    word                VideoPID;
    word                AudioPID;
    word                Unknown2;
    dword               NameOffset;
    word                ProviderIdx;
    word                LCN;
    byte                Unknown3[6];
    word                AudioStreamType;
  }TYPE_ServiceTMS;

  typedef struct
  {
    byte                SatIdx;

    word                Polar:1;              // 0=V, 1=H
    word                Unused2:3;
    word                ModulationSystem:1;   // 0=DVBS, 1=DVBS2
    word                ModulationType:2;     // 0=Auto, 1=QPSK, 2=8PSK, 3=16QAM
    word                FECMode:4;            // 0x0 = AUTO, 0x1 = 1_2, 0x2 = 2_3, 0x3 = 3_4,
                                              // 0x4 = 5_6 , 0x5 = 7_8, 0x6 = 8_9, 0x7 = 3_5,
                                              // 0x8 = 4_5, 0x9 = 9_10, 0xa = reserved, 0xf = NO_CONV
    word                Pilot:1;
    word                Unused1:4;

    byte                Unused3;
    dword               Frequency;
    word                SymbolRate;
    word                TSID;

    word                AllowTimeSync:1;
    word                Unused4:15;

    word                OriginalNetworkID;
  }__attribute__((packed)) TYPE_TpInfoSTMS;

  //TODO: a copy of TYPE_LNBInfoS right now. needs to be checked
  typedef struct
  {
    byte                DiSEqC:6;       // 0=disable, 1..16, 17=MiniA, 18=MiniB
    byte                SW12V:1;        // 0=off, 1=on
    byte                Power:1;        // 0=off, 1=on

    byte                StabPosition:7;
    byte                MotorisedSys:1;

    word                LowFreq :14;
    word                kHz22:1;        // 22khz switch box
    word                Universal:1;    // 0=single,1=universal LNB

    word                HighFreq;

    byte                PosIdx:7;
    byte                Usals:1;

    char                SkewVer;
    char                SkewHor;

    byte                TunerConnectionType:2;
    byte                Magic:6;

    byte                DiSEqC11;
    byte                Res1 [5];
  }TYPE_LNBInfoSTMS;

  typedef struct
  {
    word                tpNum;
    word                Res1;
    char                SatName[16];
    TYPE_LNBInfoSTMS    LNB[2];

    byte                Unknown1[22];
    word                Position;
    byte                Unused2[8];
  }TYPE_SatInfoSTMS;

  typedef struct
  {
    byte                TunerIndex;

    byte                RecMode:3;
    byte                DemuxPath:2;
    byte                ManualRecording:1;
    byte                Unused2:2;

    byte                SatIndex;

    byte                ServiceType:1;
    byte                ReservationType:3;
    byte                Unused4:4;

    word                ServiceID;
    word                Duration;
    byte                Unused5;
    char                FileName[131];
    dword               StartTime;
    dword               EndTime;
    word                Unused6;
    byte                isRec;
    byte                SetName;
    byte                Unknown1[8];
    word                EventID;
    word                Unused7;
    word                EventID2;
    word                Unused8;
    word                ServiceIndex;
    byte                Unused9[14];
    TYPE_TpInfoSTMS     TPInfo;
  }TYPE_TimerSTMS;

  typedef struct
  {
    dword               StartTime;
    dword               EndTime;
    word                Duration;

    word                ReservationType:3;  //see TYPE_ReservationType
    word                unknown3:4;
    word                DelOrig:1;
    word                unknown2:1;         //always 1?
    word                NrOfFiles:6;
    word                unknown1:1;

    dword               TotalTime;
    char                FileName[50][128];
  } TYPE_AutoDescrambleTimer;

  TYPE_SatInfoSTMS     *FlashGetSatelliteByIndex (byte SatIdx);
  TYPE_ServiceTMS      *FlashGetServiceByIndex (word ServiceIdx, bool TVService);
  TYPE_ServiceTMS      *FlashGetServiceByName (char* ChannelName, bool TVService);
  TYPE_TpInfoSTMS      *FlashGetTransponderSByIndex (word TpIdx, byte SatIdx);
  word                  FlashServiceAddressToServiceIndex (TYPE_ServiceTMS *ServiceAddress);


  /*****************************************************************************************************************************/
  /* HDD Functions                                                                                                             */
  /*****************************************************************************************************************************/

  #define TAPFSROOT     "/mnt/hd"

  typedef struct
  {
    dword               Magic; //0xbacaed31
    char               *Path;
    dword               unknown1;
    dword               unknown2;
  }tDirEntry;

  bool  HDD_GetAbsolutePathByTypeFile(TYPE_File *File, char *AbsFileName);
  dword HDD_GetFileTimeByAbsFileName(char *FileName);
  dword HDD_GetFileTimeByRelFileName(char *FileName);
  dword HDD_GetFileTimeByTypeFile(TYPE_File *File);
  bool  HDD_GetFileSizeAndInode(char *Directory, char *FileName, dword *CInode, __off64_t *FileSize);
  dword HDD_GetInodeByAbsFileName(char *Filename);
  dword HDD_GetInodeByRelFileName(char *Filename);
  dword HDD_GetInodeByTypeFile(TYPE_File *File);
  void  HDD_RemoveDir(char *DirPath, bool Recursive);


  /*****************************************************************************************************************************/
  /* REC Stream functions                                                                                                      */
  /*****************************************************************************************************************************/

  //That's the same (at least until a DVBc version hits the market ;-) )
  #define tRECSlot      TYPE_TimerSTMS

  typedef struct
  {
    byte        SatIndex;
    byte        reserved1;

    word        TPIndex:10;
    word        TunerNum:2;
    word        DelFlag:1;
    word        CASFlag:1;
    word        LockFlag:1;
    word        SkipFlag:1;

    word        ServiceID;
    word        PMTPID;
    word        PCRPID;
    word        VideoPID;
    word        AudioPID;
    char        ServiceName [24];
  } __attribute__((packed)) tRECServiceInfo5000;        //38 bytes

  typedef struct
  {
    byte        SatIndex;
    byte        reserved1;

    word        TPIndex:10;
    word        TunerNum:2;
    word        DelFlag:1;
    word        CASFlag:1;
    word        LockFlag:1;
    word        SkipFlag:1;

    word        ServiceID;
    word        PMTPID;
    word        PCRPID;
    word        VideoPID;
    word        AudioPID;
    char        ServiceName [28];
  } __attribute__((packed)) tRECServiceInfo5010;        //42 bytes

  typedef struct
  {
    byte        SatIndex;

    byte        Polarization:1;
    byte        Mode:3;         //0=Normal, 1=SmaTV
    byte        reserved1:4;

    byte        reserved2 [2];
    dword       Frequency;      //in MHz
    word        SymbolRate;
    word        TSID;
    byte        reserved3 [2];
    word        OriginalNetworkID;
  } __attribute__((packed)) tRECTPInfoSat;              //16 bytes

  tRECSlot   *HDD_RECSlotGetAddress(byte Slot);


  /*****************************************************************************************************************************/
  /* TAPs                                                                                                                      */
  /*****************************************************************************************************************************/

  typedef struct
  {
    dword                 Status; //1 = Running, 2 = TAP_Exit(); ???
    dword                 unknown1;
    TYPE_File             *file;
    dword                 unknown3;
    dword                 TAP_Main;
    dword                 TAP_EventHandler;
    dword                 unknown6;
    dword                 unknown7;
    dword                 unknown8;
    dword                 unknown9;
    tDirEntry            *CurrentDir;
  } tTMSTAPTaskTable; //44 Bytes * 16 TAPs = 704 bytes

  typedef struct
  {
    dword               TAPID;
    dword               Date;
    char                TAPName[64];
    char                Author[64];
    char                Description[128];
  } tTAPInfo;

  bool HDD_TAP_GetInfo(char *FileName, tTAPInfo *pTAPInfo);
  bool HDD_TAP_GetInfoByAbsPath(char *AbsFileName, tTAPInfo *pTAPInfo);
  bool HDD_TAP_GetFileNameByIndex(int Index, char **TAPFileName);
  dword KeyTranslate(dword param1);


  /*****************************************************************************************************************************/
  /* tapapifix                                                                                                                 */
  /*****************************************************************************************************************************/


  /*****************************************************************************************************************************/
  /* Firmware Patches                                                                                                          */
  /*****************************************************************************************************************************/


  /*****************************************************************************************************************************/
  /* TMS VFD Routines                                                                                                          */
  /*****************************************************************************************************************************/

  typedef enum
  {
    VFD_AC3,
    VFD_AM,
    VFD_Attn,
    VFD_CDCenter,
    VFD_Clock,
    VFD_Colon,
    VFD_Dolby,
    VFD_Dollar,
    VFD_FFwd,
    VFD_HDD,
    VFD_HDDFull,
    VFD_JumpStart,
    VFD_JumpEnd,
    VFD_MP3,
    VFD_Mute,
    VFD_Network,
    VFD_Pause,
    VFD_Play,
    VFD_PM,
    VFD_Power,
    VFD_Radio,
    VFD_REC,
    VFD_Slot1,
    VFD_Slot2,
    VFD_RepeatLeft,
    VFD_RepeatRight,
    VFD_Rwd,
    VFD_Satellite,
    VFD_TimeShift,
    VFD_TV
  } tVFDIcon;


  bool VFD_GetControl(bool GiveControl);
  bool VFD_isInUseByTAP(void);
  bool VFD_Clear(void);
  bool VFD_SetLargeText(char *Text);
  bool VFD_SetSmallText(char *Text);
  bool VFD_Update(void);
  bool VFD_EnableCD(bool Enable);
  bool VFD_SetCDValue(int Percent);
  bool VFD_EnableHDD(bool Enable);
  bool VFD_SetHDDValue(int Percent);
  bool VFD_SetIcon(tVFDIcon VFDIcon, bool On);
  bool VFD_EnableCDAnimation(bool Enable);
  bool VFD_CDAnimation(bool Forward);

  /*****************************************************************************************************************************/
  /* FontManager                                                                                                               */
  /*****************************************************************************************************************************/

  typedef struct
  {
    dword                 Width;
    dword                 Height;
    dword                 BitmapIndex;
  } tFontDef;

  typedef struct
  {
    byte                 *pFontData;
    tFontDef              FontDef[191];
  } tFontData;

  dword FM_GetStringWidth(const char *Text, tFontData *FontData);
  dword FM_GetStringWidthAndRestrict(char *Text, tFontData *FontData, int MaxWidth, bool *pbRestricted);
  dword FM_GetStringHeight(const char *Text, tFontData *FontData);
  void  FM_PutString(word rgn, dword x, dword y, dword maxX, const char * str, dword fcolor, dword bcolor, tFontData *FontData, byte bDot, byte align);
  bool  FM_LoadFontFile(char *FontFileName, tFontData *FontData);
  void  FM_FreeFontFile(tFontData *FontData);


  /*****************************************************************************************************************************/
  /* TMS OSD Menu                                                                                                              */
  /*   Menu, dialog box and message box                                                                                        */
  /*****************************************************************************************************************************/

  //Main OSD
  void OSDMenuInitialize(bool AllowScrollingOfLongText, bool HasValueColumn, bool NumberedItems, bool ScrollLoop, char *TitleLeft, char *TitleRight);
  void OSDMenuUpdate(bool SuppressOSDSync);
  void OSDMenuModifyTitleLeft(char *Text);
  void OSDMenuModifyTitleRight(char *Text);
  void OSDMenuModifyItemLongTextScrolling(bool AllowScrollingOfLongText);
  void OSDMenuModifyItemValueColumn(bool HasValueColumn);
  void OSDMenuModifyItemNumbered(bool NumberedItems);
  void OSDMenuModifyScrollLoop(bool ScrollLoop);
  void OSDMenuLogo(dword X, dword Y, TYPE_GrData *LogoGd);
  void OSDMenuDestroy(void);
  bool OSDMenuIsVisible(void);

  //Buttons

  typedef enum
  {
    BI_None,
    BI_UserDefined,
    BI_Red,
    BI_Green,
    BI_Yellow,
    BI_Blue,
    BI_White,
    BI_Menu,
    BI_Info,
    BI_Ok,
    BI_Exit,
    BI_Record,
    BI_Select,
    BI_Ffwd,
    BI_Rwd,
    BI_JumpStart,
    BI_JumpEnd,
    BI_Sat,
    BI_FileList
  } tButtonIcon;


  void OSDMenuButtonsClear(void);
  void OSDMenuButtonAdd(dword Line, tButtonIcon ButtonIcon, TYPE_GrData *ButtonGd, char *Text);

  //Cursor Functions
  bool OSDMenuSelectItem(int ItemIndex);
  int  OSDMenuGetCurrentItem(void);
  int  OSDMenuScrollUp(void);
  int  OSDMenuScrollPageUp(void);
  int  OSDMenuScrollDown(void);
  int  OSDMenuScrollPageDown(void);
  int  OSDMenuScrollHome(void);
  int  OSDMenuScrollEnd(void);

  //Items
  void  OSDMenuItemsClear(void);
  bool  OSDMenuItemAdd(char *Name, char *Value, TYPE_GrData *pNameIconGd, TYPE_GrData *pValueIconGd, bool Selectable, bool ValueArrows, dword ID);
  bool  OSDMenuItemModifyName(int ItemIndex, char *Text);
  bool  OSDMenuItemModifyValue(int ItemIndex, char *Text);
  void  OSDMenuItemModifyValueXPos(dword NewValueXPos);
  bool  OSDMenuItemModifyNameIcon(int ItemIndex, TYPE_GrData *pNameIconGd);
  bool  OSDMenuItemModifyValueIcon(int ItemIndex, TYPE_GrData *pValueIconGd);
  bool  OSDMenuItemModifySelectable(int ItemIndex, bool Selectable);
  bool  OSDMenuItemModifyColorPatch(int ItemIndex, dword Color); //set to 0 to disable
  char *OSDMenuItemGetValue(int ItemIndex);
  char *OSDMenuItemGetName(int ItemIndex);
  dword OSDMenuItemGetID(int ItemIndex);
  char *OSDMenuItemGetCurrentValue(void);
  char *OSDMenuItemGetCurrentName(void);
  dword OSDMenuItemGetCurrentID(void);
  dword OSDMenuItemGetNrOfItems(void);

  //
  bool OSDMenuPush(void);
  bool OSDMenuPop(void);

  //Memo
  void OSDMemoInitialize(bool ScrollLoop, char *TitleLeft, char *TitleRight, char *Text);

  //Info box
  void OSDMenuInfoBoxShow(char *Title, char *Text, dword Timeout);
  void OSDMenuInfoBoxDestroy(void);
  bool OSDMenuInfoBoxIsVisible(void);

  //Message box
  void  OSDMenuMessageBoxInitialize(char *Title, char *Text);
  void  OSDMenuMessageBoxButtonAdd(char *Text);
  void  OSDMenuMessageBoxButtonSelect(dword SelectedButton);
  void  OSDMenuMessageBoxShow(void);
  void  OSDMenuMessageBoxDestroy(void);
  bool  OSDMenuMessageBoxIsVisible(void);
  dword OSDMenuMessageBoxLastButton(void);

  //Color Picker
  void  OSDMenuColorPickerShow(char *Title, dword DefaultColor);
  void  OSDMenuColorPickerDestroy(void);
  bool  OSDMenuColorPickerIsVisible(void);
  dword OSDMenuColorPickerColor(void);

  //Event handling
  bool OSDMenuEvent(word *event, dword *param1, dword *param2);
