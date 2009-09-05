  /*****************************************************************************************************************************/
  /* Firmware & Low Level                                                                                                      */
  /*****************************************************************************************************************************/

  #define LE16(p)       (p)
  #define LE32(p)       (p)

  byte *GetMacAddress(void);

  char puffer[512];
  void PrintNet(char *puffer);

#define XDATA                                       //don't use XDATA on the TMS
#define TS_FILE_NAME_SIZE   MAX_FILE_NAME_SIZE      //the name has changed
#define ATTR_PARENT         0xf0                    //FindFirst/FindNext doesn't know about ..

#ifndef PC_BASED
  #define TAP_PrintNet(...) {sprintf(puffer, __VA_ARGS__); PrintNet(puffer);}
#endif


  /*****************************************************************************************************************************/
  /* FindInstuctionSequnces                                                                                                    */
  /*****************************************************************************************************************************/

  dword TryResolve(char *Function);

  inline dword FIS_fwApplVfdStart(void);
  inline dword FIS_fwApplVfdStop(void);
  inline dword FIS_fwPowerOff(void);
  inline dword FIS_fwApplVfdSendData(void);
  inline dword FIS_fwSetIrCode(void);
  inline dword FIS_vgrid(void);
  inline dword FIS_vMACAddress(void);


  /*****************************************************************************************************************************/
  /* Audio / Video / OSD                                                                                                       */
  /*****************************************************************************************************************************/
  //Forgotten keys
  #define RKEY_White    RKEY_Option

#ifndef TAP_ALPHA
  #define TAP_ALPHA     255
#endif

  bool CaptureScreen(int BMPwidth, int BMPheight, byte *BMPPixelBuffer, bool bOSD, int Alpha);


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
    word                SatAngle;
    byte                Unused2[8];
  }TYPE_SatInfoSTMS;

  typedef struct
  {
    byte                TunerIndex:1;
    byte                Unused1:7;

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

  TYPE_SatInfoSTMS     *FlashGetSatelliteByIndex (byte SatIdx);
  TYPE_ServiceTMS      *FlashGetServiceByIndex (word ServiceIdx, bool TVService);
  TYPE_ServiceTMS      *FlashGetServiceByName (char* ChannelName, bool TVService);
  TYPE_TpInfoSTMS      *FlashGetTransponderSByIndex (word TpIdx, byte SatIdx);
  word                  FlashServiceAddressToServiceIndex (TYPE_ServiceTMS *ServiceAddress);


  /*****************************************************************************************************************************/
  /* HDD Functions                                                                                                             */
  /*****************************************************************************************************************************/

  #define TAPFSROOT     "/mnt/hd"

  bool  HDD_GetAbsolutePathByTypeFile(TYPE_File *File, char *AbsFileName);
  dword HDD_GetInodeByAbsFileName(char *Filename);
  dword HDD_GetInodeByRelFileName(char *Filename);
  dword HDD_GetInodeByTypeFile(TYPE_File *File);
  dword HDD_GetFileTimeByAbsFileName(char *FileName);
  dword HDD_GetFileTimeByRelFileName(char *FileName);
  dword HDD_GetFileTimeByTypeFile(TYPE_File *File);


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

  tRECSlot   *HDD_RECSlotGetAddress (byte Slot);


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
    dword                 CurrentDir;
  } tTMSTAPTaskTable; //44 Bytes * 16 TAPs = 704 bytes

  dword HDD_TAP_Start (char *TAPFileName, bool BatchMode, void* ParameterBlock);


  /*****************************************************************************************************************************/
  /* TAP Comm                                                                                                                  */
  /*   Mainly developed by asrael                                                                                              */
  /*****************************************************************************************************************************/


  /*****************************************************************************************************************************/
  /* tapapifix                                                                                                                 */
  /*****************************************************************************************************************************/


  /*****************************************************************************************************************************/
  /* Firmware Patches                                                                                                          */
  /*****************************************************************************************************************************/


  /*****************************************************************************************************************************/
  /* TMS VFD Routines                                                                                                          */
  /*****************************************************************************************************************************/
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
