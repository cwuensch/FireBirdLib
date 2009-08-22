  extern dword                 SysID;
  extern word                  ApplID;


  /*****************************************************************************************************************************/
  /* MIPS OpCodes                                                                                                              */
  /*                                                                                                                           */
  /*                                                                                                                           */
  /*****************************************************************************************************************************/

  #define REL_ADDR(x)     (((dword)(x) & 0x0fffffff) >> 2)
  #define ABS_ADDR(x)     (((x & JMP_ADDRMASK) << 2) | 0x80000000)

  #define ADD_SP_CMD      0x27BD0000
  #define ADD_SP_MASK     0xFFFF0000
  #define ADDIU_A0_CMD    0x24040000
  #define ADDIU_GP_CMD    0x279C0000
  #define ADDIU_S1_CMD    0x24110000
  #define ADDIU_CMD       0x24000000
  #define BASE_MASK       0xFFE00000
  #define CMD_MASK        0xFC000000
  #define JAL_CMD         0x0C000000
  #define JMP_ADDRMASK    0x03FFFFFF
  #define JMP_CMD         0x08000000
  #define JR_RA_CMD       0x03E00008
  #define LBU_CMD         0x90000000
  #define LUI_A0_CMD      0x3c040000
  #define LUI_A1_CMD      0x3C050000
  #define LUI_A2_CMD      0x3C060000
  #define LUI_CMD         0x3C000000
  #define LUI_GP_CMD      0x3C1C0000
  #define LUI_S0_CMD      0x3C100000
  #define LUI_S1_CMD      0x3C110000
  #define LUI_S3_CMD      0x3C130000
  #define LUI_S4_CMD      0x3C140000
  #define LUI_S6_CMD      0x3C160000
  #define LUI_T0_CMD      0x3C080000
  #define LUI_T1_CMD      0x3C090000
  #define LUI_T8_CMD      0x3C180000
  #define LUI_T9_CMD      0x3C190000
  #define LW_GP_CMD       0x8F800000
  #define LW_S7T9_CMD     0x8F370000
  #define LW_T1_SP_CMD    0x8FA90000
  #define MOVE_A0_48      0x24040030
  #define MOVE_A0_CMD     0x34040000
  #define MOVE_A2_48      0x24060030
  #define MOVE_T9_RA      0x03E02020
  #define NOP_CMD         0x00000000
  #define OR_A1_CMD       0x34A50000
  #define OR_T8_CMD       0x37180000
  #define ORI_A0_CMD      0x34840000
  #define ORI_A1_CMD      0x34A50000
  #define ORI_A2_CMD      0x34C60000
  #define ORI_GP_CMD      0x379C0000
  #define ORI_S0_CMD      0x36100000
  #define ORI_S1_CMD      0x36310000
  #define ORI_S3_CMD      0x36730000
  #define ORI_S4_CMD      0x36940000
  #define ORI_S6_CMD      0x36D60000
  #define ORI_T0_CMD      0x35080000
  #define ORI_T1_CMD      0x35290000
  #define REG_MASK        0x03FF0000
  #define SB_0_GP_CMD     0xA3800000
  #define SW_RA_SP_CMD    0xAFBF0000
  #define SW_S5T9_CMD     0xAF350000
  #define SW_S7T9_CMD     0xAF370000


  /*****************************************************************************************************************************/
  /* Firmware & Low Level                                                                                                      */
  /*****************************************************************************************************************************/

  #define TAP_MAX       16
  #define LE16(p)       (p)
  #define LE32(p)       (p)

  typedef enum
  {
    BOOT_FRONT_PANEL,
    BOOT_REMOTE_CONTROL,
    BOOT_TIMER,
    BOOT_CRASH_REBOOT                  //applied by the AutoReboot TAP only
  } tBootReason;

  typedef enum
  {
    TIMESTAMP_NONE,
    TIMESTAMP_HM,
    TIMESTAMP_HMS,
    TIMESTAMP_YMD,
    TIMESTAMP_YMDHM,
    TIMESTAMP_YMDHMS,
    TIMESTAMP_FNYMDHM
  } eTimeStampFormat;

  bool  InitTAPex (void);
  void  InitTAPexFailedMsg(char *ProgramName);
  dword FindInstructionSequence (char SearchPattern [200], char SearchMask [200], dword StartAddress, dword EndAddress, int EntryPointOffset, bool SearchForPrevADDIUSP);
  word  GetSysID(void);
  tBootReason BootReason(void);
  char *GetToppyString (word SysID);
  dword Now (byte *Sec);
  void  LogEntry(char *FileName, char *ProgramName, bool Console, eTimeStampFormat TimeStampFormat, char *Text);
  void  FlushCache(dword *pAddr, int Size);
  char *iso639_1 (int OSDLan);
  void DumpMemory(unsigned char* p, dword size, int BytesPerLine);
  byte *GetMacAddress(void);

  void CallTraceInit (void);
  void CallTraceEnable (bool Enable);
  void CallTraceEnter (char *ProcName);
  void CallTraceExit (dword *Magic);
  void CallTraceExitResult (dword *Magic, char *Result);
  void CallTraceComment (char *Comment);

  char puffer[512];
  void PrintNet(char *puffer);
#ifndef PC_BASED
  #define TAP_PrintNet(...) {sprintf(puffer, __VA_ARGS__); PrintNet(puffer);}
#endif


  /*****************************************************************************************************************************/
  /* FindInstuctionSequnces                                                                                                    */
  /*****************************************************************************************************************************/

  dword TryResolve(char *Function);

  inline dword FIS_fwPowerOff(void);
  inline dword FIS_fwSetIrCode(void);
  inline dword FIS_vBootReason(void);
  inline dword FIS_vEEPROM (void);
  inline dword FIS_vEEPROMPin (void);
  inline dword FIS_vEtcInfo(void);
  inline dword FIS_vFlash (void);
  inline dword FIS_vMACAddress(void);
  inline dword FIS_vOSDMap (void);
  inline dword FIS_vParentalInfo(void);
  inline dword FIS_vRECSlotAddress (byte Slot);

//TODO: They might be ported
#ifdef _FUTURE_TMS_

  inline dword FIS_fwAddEventHandler (void);
  inline dword FIS_fwBIOS (void);
  inline dword FIS_fwDelEventHandler (void);
  inline dword FIS_fwDSTCheck (void);
  inline dword FIS_fwEnqueueEvent (void);
  inline dword FIS_fwEventDispatcher (void);
  inline dword FIS_fwFlashEraseSector (void);
  inline dword FIS_fwFlashFindSectorAddressIndex (void);
  inline dword FIS_fwFlashGetSectorAddress (void);
  inline dword FIS_fwFWFlashProgram (void);
  inline dword FIS_fwGetMPVFDDataBuffer (void);
  inline dword FIS_fwMemMonitor (void);
  inline dword FIS_fwMHEGDisable (void);
  inline dword FIS_fwMHEGStatus (void);
  inline dword FIS_fwMoveOld (void);
  inline dword FIS_fwObtainResource (void);
  inline dword FIS_fwPIC2_ISR18 (void);
  inline dword FIS_fwReboot (void);
  inline dword FIS_fwReleaseResource (void);
  inline dword FIS_fwSendToFP (void);
  inline dword FIS_fwSendToLEDDisplay (void);
  inline dword FIS_fwSetLEDByMode (void);
  inline dword FIS_fwSetPlaybackMode (void);
  inline dword FIS_fwSetPlaybackSpeed (void);
  inline dword FIS_fwSetVFDByMode (void);
  inline dword FIS_fwShutdownHandler (void);
  inline dword FIS_fwStopDisplayUpdateTimers (void);
  inline dword FIS_fwTAPStart (void);
  inline dword FIS_fwUpdateMPVFD (void);
  inline dword FIS_fwWriteSectors (void);
  inline dword FIS_fwWriteSectorsDMA (void);
  inline dword FIS_GetGP (dword *UncompressedFirmware);
  inline dword FIS_vEventHandlerMap (void);
  inline dword FIS_vFlashFWMaxSize (void);
  inline dword FIS_vFlashFWStartOffset (void);
  inline dword FIS_vFlashInProgress (void);
  inline dword FIS_vGMT (void);
  inline dword FIS_vHddInfoStructure1 (void);
  inline dword FIS_vHddInfoStructure2 (void);
  inline dword FIS_vHDDLiveFSFAT1 (void);
  inline dword FIS_vHDDLiveFSRootDir (void);
  inline dword FIS_vHDDLiveFSSuperblock (void);
  inline dword FIS_vHDDShutdown (void);
  inline dword FIS_vHeapMap (void);
  inline dword FIS_vHeapStart (void);
  inline dword FIS_vIntVectorTable (void);
  inline dword FIS_vKeyMap (void);
  inline dword FIS_vLEDDisplayBuffer (void);
  inline dword FIS_vMPEGHeader (void);
  inline dword FIS_vMPVFD (void);
  inline dword FIS_vMPVFDBackup (void);
  inline dword FIS_vPinStatus (void);
  inline dword FIS_vPlaybackPaused (void);
  inline dword FIS_vPlaySlot (void);
  inline dword FIS_vRecFile (byte Slot);
  inline dword FIS_vSuppressedAutoStart (void);
  inline dword FIS_vSysOsdControl (void);
  inline dword FIS_vTAP_Vfd_Control (void);
  inline dword FIS_vTAP_Vfd_Status (void);
  inline dword FIS_vTAPTable (void);
  inline dword FIS_vTaskAddressTable (void);
  inline dword FIS_vVolume (void);
  inline dword FIS_vWD1 (void);

#endif


  /*****************************************************************************************************************************/
  /* Audio / Video / OSD                                                                                                       */
  /*****************************************************************************************************************************/
  //Forgotten keys
  #define RKEY_Red      RKEY_NewF1
  #define RKEY_Green    RKEY_F2
  #define RKEY_Yellow   RKEY_F3
  #define RKEY_Blue     RKEY_F4
  #define RKEY_Option   0x10049
  #define RKEY_White    RKEY_Option

  #define _Clip(a)      (a)>255 ? 255 : (a)<0 ? 0 : (a)

  #define YUVR(y,u,v)   ((0x2568*(y) + 0x3343*(u)) >>13)                //0x2000
  #define YUVG(y,u,v)   ((0x2568*(y) - 0x0c92*(v) - 0x1a1e*(u)) >>13)   //0x2000
  #define YUVB(y,u,v)   ((0x2568*(y) + 0x40cf*(v)) >>13)                //0x2000

  #define win_w(w)      ((w) + 51)
  #define win_h(h)      (((h) / 22 + ((h) % 22 ? 1 : 0)) * 22 + 83)
  #define win_l(h)      ((win_h(h) - 83) / 22)

  #define A1555(x)      (((x)>>15)&0x01)
  #define R1555(x)      (((x)>>10)&0x1f)
  #define G1555(x)      (((x)>> 5)&0x1f)
  #define B1555(x)      (((x)>> 0)&0x1f)

  #define A8888(x)      (((x)>>24)&0xff)
  #define R8888(x)      (((x)>>16)&0xff)
  #define G8888(x)      (((x)>> 8)&0xff)
  #define B8888(x)      (((x)>> 0)&0xff)

  #define ARGBtoTMS(a,r,g,b)  a*=0xff;r*=8.2258;g*=8.2258;b*=8.2258
  #define TMStoARGB(a,r,g,b)  a/=0xff;r/=8.2258;g/=8.2258;b/=8.2258

#ifndef TAP_ALPHA
  #define TAP_ALPHA     255
#endif

  struct BMP_HEAD
  {
    byte                id[2];
    word                size_l;
    word                size_h;
    word                reserved[2];
    word                offset_l;
    word                offset_h;
  };

  struct BMP_INFO
  {
    long                info_size;
    long                width;
    long                height;
    word                plane;
    word                bits_per_pixel;
    long                compress;
    long                img_size;
    long                x_res;
    long                y_res;
    long                color;
    long                icolor;
  };

  typedef struct
  {
    word        x;
    word        y;
    word        Width;
    word        Height;
    dword       pMemoryOSD;
    byte        byteFormat;
    byte        lutIdx;
    byte        plane;
    byte        unknown;
  } tOSDMapInfo;

  // directions
  typedef enum
  {
    X,
    Y
  } eCopyDirection;

  TYPE_TapEvent *GetCurrentEvent(int *curEvent);
  void  DrawOSDLine (word OSDRgn, dword Ax, dword Ay, dword Bx, dword By, dword Color);
  void  EndMessageWin (void);
  void  FreeOSDRegion (word Region);
  dword GetOSDMapAddress (void);
  word  GetOSDRegionHeight (word Region);
  word  GetOSDRegionWidth (word Region);
  bool  GetPIPPosition (int *North, int *South, int *East, int *West);
  void  OSDCopy (word rgn, dword x, dword y, dword w, dword h, word items, eCopyDirection direction);
  bool  SaveBitmap (char *strName, int width, int height, byte* pBuffer );
  void  SetRemoteMode (byte Mode, bool Active);
  void  ShowMessageWin (char* title, char* lpMessage1, char* lpMessage2, dword dwDelay);
  void  ShowMessageWindow (char **content, dword pos_x, dword pos_y, byte fntSize, byte align, dword bdcolor, dword titlecolor, dword msgcolor, dword bgcolor, dword delay);
  void  SoundSinus (word freq, dword durationInMilliseconds, word Amplitude);
  int   TAP_Osd_PutFreeColorGd (word rgn, int x, int y, TYPE_GrData * gd, bool sprite, dword FilterColor);
  byte  TunerGet (int MainSub);
  bool  TunerSet (byte Tuner);
  bool CaptureScreen(int BMPwidth, int BMPheight, byte *BMPPixelBuffer, bool bOSD, int Alpha);


  /*****************************************************************************************************************************/
  /* Flash & EEPROM                                                                                                            */
  /*****************************************************************************************************************************/
  typedef enum
  {
    ST_UNKNOWN,
    ST_DVBS,
    ST_DVBT,
    ST_DVBC,
    ST_DVBT5700,
    ST_DVBSTMS
  } SYSTEM_TYPE;

  typedef enum
  {
    TVServices          =  1,
    RadioServices       =  2,
    Satellites          =  3,
    Transponders        =  4,
    Favourites          =  5,
    GameData            =  6,
    ClockSetup          =  7,
    Timers              =  8,
    ReserveEPG          =  9,
    ServiceNames        = 10,
    ProviderNames       = 11,
    OTA                 = 12,
    WLAN                = 14,     //Server Settings
    FirmwareServer      = 15,
    NetworkProfiles     = 16,
    AutoDescrambleTimer = 17,
    BLOCKS              = 18
  } TYPE_FlashBlock;

  typedef struct
  {
    char                FavName [12];
    word                ServiceIndex [100];
    byte                Flags [100];
    byte                NrOfEntries;
    char                Res1;
  }TYPE_Fav;

  typedef struct
  {
    dword               Money [4];
    dword               Win [4];
    dword               Lose [4];
    dword               exblockClearStage;
    byte                Res1 [16];
  }TYPE_GameData;

  //TODO: check this struct
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

  typedef enum
  {
    delete,
    insert
  } ReindexType;

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
    byte                Unknown1[12];
    word                EventID;
    word                Unused6;
    word                EventID2;
    word                Unused7;
    word                ServiceIndex;
    byte                Unused8[14];
    TYPE_TpInfoSTMS     TPInfo;
  }TYPE_TimerSTMS;


  /**********************************************************************************/

  #define DATE(mjd, h, m) ((dword) (((mjd) << 16) | ((h) << 8) | (m)))
  #define MJD(d) ((word) (((d) >> 16) & 0xffff))
  #define TIME(d) ((word) ((d) & 0xffff))
  #define HOUR(d) ((byte) (((d) >> 8) & 0xff))
  #define MINUTE(d) ((byte) ((d) & 0xff))

  dword                 AddSec (dword date, byte dateSec, int add);
  dword                 AddTime(dword date, int add);
  bool                  FlashAddFavourite (char *FavName, word Idx, bool TVService);
  void                  FlashDeleteFavourites (void);
  dword                 FlashFindCASServices (bool TVService, bool *FlagArray, dword *NewFlags);
  dword                 FlashFindEndOfServiceNameTableAddress (void);
  dword                 FlashFindEndOfServiceTableAddress(bool TVService);
  dword                 FlashFindServiceAddress (word ServiceID, word PMTPID, word PCRPID, bool TVService);    //Returns an address to the ServiceTable; -1 if not found
  dword                 FlashFindServiceByLCN (char* LCN, bool TVService, bool *FlagArray, dword *NewFlags);
  dword                 FlashFindServiceByName (char* ChannelName, bool TVService, bool *FlagArray, dword *NewFlags);
  dword                 FlashFindServiceByPartOfName (char* ChannelName, bool TVService, bool *FlagArray, dword *NewFlags);
  int                   FlashFindTransponderIndex (dword SatIndex, dword NetworkID, dword TSID);
  dword                 FlashGetBlockStartAddress (TYPE_FlashBlock BlockNumber);
  dword                 FlashGetTrueLocalTime (dword ToppyLocalDate, int StandardOffsetMin);
  SYSTEM_TYPE           FlashGetType (void);
  dword                 FlashInitialize (dword SystemID);
  void                  FlashProgram(void);
  void                  FlashReindexFavourites (word ServiceIndex, int ServiceType, ReindexType itype);
  void                  FlashReindexTimers (word ServiceIndex, int ServiceType, ReindexType itype);
  dword                 FlashRemoveCASServices (bool TVService);
  dword                 FlashRemoveServiceByIndex (int ChannelIndex, bool TVService);
  dword                 FlashRemoveServiceByIndexString (char* ChannelIndex, bool TVService);
  dword                 FlashRemoveServiceByLCN (char* LCN, bool TVService);
  dword                 FlashRemoveServiceByName (char* ChannelName, bool TVService);
  dword                 FlashRemoveServiceByPartOfName (char* ChannelName, bool TVService);
  dword                 FlashRemoveServiceByUHF (char* UHFChannel, bool TVService, bool UseAUSChannelCoding);
  dword                 GetEEPROMAddress(void);
  word                  GetEEPROMPin(void);
  bool                  SetEEPROMPin(word NewPin);
  long                  TimeDiff (dword FromTime, dword ToTime);
  char                 *TimeFormat(dword DateTime, byte Sec, eTimeStampFormat TimeStampFormat);
  TYPE_SatInfoSTMS     *FlashGetSatelliteByIndex (byte SatIdx);
  TYPE_ServiceTMS      *FlashGetServiceByIndex (word ServiceIdx, bool TVService);
  TYPE_ServiceTMS      *FlashGetServiceByName (char* ChannelName, bool TVService);
  TYPE_TpInfoSTMS      *FlashGetTransponderSByIndex (word TpIdx, byte SatIdx);
  word                  FlashServiceAddressToServiceIndex (TYPE_ServiceTMS *ServiceAddress);


  /*****************************************************************************************************************************/
  /* HDD Functions                                                                                                             */
  /*****************************************************************************************************************************/

  #define TAPFSROOT     "/mnt/hd"
  #define FBLIB_DIR_SIZE 256

  //TODO: check all structs
  typedef struct
  {
    dword       MagicNumber;    //0x54467263 (TFrc)
    word        Version;        //0x5000, 0x5010
    byte        reserved1 [2];
    word        Duration;       //in minutes
    word        ServiceNr;
    word        ServiceType;    //0=TV, 1=Radio
  } __attribute__((packed)) tRECHeader;                 //14 bytes

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

  typedef struct
  {
    word                ChannelNumber;
    byte                Bandwidth;      //in MHz
    byte                reserved1;
    dword               Frequency;      //in kHz
    word                TSID;
    byte                LPHPStream;     //0=LP, 1=HP
    byte                reserved2;
    word                OriginalNetworkID;
    byte                unknown1 [2];
  } __attribute__((packed)) tRECTPInfoTer;              //16 bytes

  typedef struct
  {
    dword       Frequency;
    word        SymbolRate;
    word        TSID;
    word        OriginalNetworkID;
    byte        Modulation;     //0=16QAM, 1=32QAM, ...
    byte        unused1;
  } __attribute__((packed)) tRECTPInfoCable;            //12 bytes

  typedef struct
  {
    byte        reserved1 [2];
    byte        DurationHour;
    byte        DurationMin;
    dword       EventID;
    word        StartTimeMJD;
    byte        StartTimeHour;
    byte        StartTimeMin;
    word        EndTimeMJD;
    byte        EndTimeHour;
    byte        EndTimeMin;
    byte        reserved2;
    byte        TextLength;
    byte        ParentalRate;
    char        EventNameAndDescription [275];  //EventName has no 0x00 terminator, use strncpy!
  } __attribute__((packed)) tRECEventInfo;              //294 bytes

  typedef struct
  {
    word        TextLength;
    dword       EventID;
    char        Text [1024];
  } __attribute__((packed)) tRECExtendedEventInfo;      //1030 bytes

  typedef struct
  {
    byte        reserved1 [4];
    byte        CryptFlag;
    byte        reserved2 [3];
  } __attribute__((packed)) tRECCryptInfo;              //8 bytes

  typedef struct
  {
    dword       Bookmark [64];
  } __attribute__((packed)) tRECBookmarks;              //256 bytes


#define WINFILEATTRIBUTE_READONLY                 0x01000000
#define WINFILEATTRIBUTE_HIDDEN                   0x02000000
#define WINFILEATTRIBUTE_SYSTEM                   0x04000000
#define WINFILEATTRIBUTE_DIRECTORY                0x10000000
#define WINFILEATTRIBUTE_ARCHIVE                  0x20000000
#define WINFILEATTRIBUTE_DEVICE                   0x40000000
#define WINFILEATTRIBUTE_NORMAL                   0x80000000
#define WINFILEATTRIBUTE_TEMPORARY                0x00010000
#define WINFILEATTRIBUTE_SPARSE_FILE              0x00020000
#define WINFILEATTRIBUTE_REPARSE_POINT            0x00040000
#define WINFILEATTRIBUTE_COMPRESSED               0x00080000
#define WINFILEATTRIBUTE_OFFLINE                  0x00100000
#define WINFILEATTRIBUTE_NOT_CONTENT_INDEXED      0x00200000
#define WINFILEATTRIBUTE_ENCRYPTED                0x00400000

  typedef struct
  {
    dword                 Attribute:8;
    dword                 FileDateTimeMJD:16;
    dword                 FileDateTimeHour:8;

    dword                 FileDateTimeMin :8;
    dword                 FileDateTimeSeconds :8;
    dword                 FileDateTimeOffset:16; //signed short!

    dword                 StartCluster;
    dword                 TotalCluster;
    dword                 UnusedByte;
    char                  FileName [MAX_FILE_NAME_SIZE];
    char                  ServiceName [31];
    byte                  unknown1;
    dword                 WinFileAttribute;

    byte                  reserved2:5;
    byte                  Scrambled:1;
    byte                  Skip:1;
    byte                  reserved3:1;

    byte                  CryptFlag;
    byte                  PlayList;
    byte                  reserved4;
    byte                  SlotCRC;          //CRC from Attribute to incl. WinFileAttribute
    byte                  BytesUsedCRC;     //ByteUsedCRC = ((ByteUsed >> 8) + (BytesUsed & 0xff) + 1) & 0xff;
    word                  BytesUsed;
  }__attribute__((packed)) tFileSlot;   //128 Bytes

  typedef struct // This is what a TYPE_File's "handle" points to
  {
    tFileSlot current; // Current (unsaved) file details
    tFileSlot saved;   // Saved file details
    dword dirCluster;  // Cluster of file's parent directory
    dword dirEntNum;   // Index of file's directory entry
  } tFileHandle;

  typedef struct
  {
    dword               SectorsPerCluster;
    dword               HddInterruptOccured;
    dword               pClusterBuffer;
    dword               NrFATSectors;
    dword               TSBufferSize;
    dword               TSUnknown;
    dword               NrOfSectors;
    dword               NrOfClusters;
  } HDDINFO;

  int        HDD_AAM_Disable (void);
  int        HDD_AAM_Enable (byte AAMLevel);
  int        HDD_APM_Disable (void);
  int        HDD_APM_Enable (byte APMLevel);
  TYPE_File *HDD_FappendOpen (char *filename);
  bool       HDD_ChangeDir (char *Dir);
  bool       HDD_FappendWrite (TYPE_File *file, char *data);
  bool       HDD_GetHddID (char *ModelNo, char *SerialNo, char *FirmwareNo);
  bool       HDD_IdentifyDevice (char *IdentifyDeviceBuffer);
  bool       HDD_Move(char *FileName, char *FromDir, char *ToDir);
  int        HDD_Smart_DisableAttributeAutoSave (void);
  int        HDD_Smart_DisableOperations (void);
  int        HDD_Smart_EnableAttributeAutoSave (void);
  int        HDD_Smart_EnableOperations (void);
  int        HDD_Smart_ReadData (word *DataBuf);
  int        HDD_Smart_ReadThresholdData (word *DataBuf);
  int        HDD_Smart_ReturnStatus (void);                  ////if 20 is returned then one or more thresholds have been exceeded; -1 upon error
  bool       HDD_Write (void *data, dword length, TYPE_File *f);


  /*****************************************************************************************************************************/
  /* IMEM                                                                                                                      */
  /*****************************************************************************************************************************/

  void *IMEM_Alloc( dword dwSize );
  bool  IMEM_Init( dword dwSize );
  bool  IMEM_isInitialized( void );
  void  IMEM_Compact( void );
  void  IMEM_Free( void *pPtr );
  void  IMEM_GetInfo( dword *pTotal, dword *pFree );
  void  IMEM_Kill( void );


  /*****************************************************************************************************************************/
  /* INI Files                                                                                                                 */
  /*****************************************************************************************************************************/

  typedef enum
  {
    INILOCATION_NotFound,
    INILOCATION_NewFile,           // returned by INIOpenFile only
    INILOCATION_AtCurrentDir,
    INILOCATION_AtAppName,
    INILOCATION_AtSettings,
    INILOCATION_AtProgramFiles,
    INILOCATION_NrENUMs
  } INILOCATION;

  INILOCATION INIOpenFile (char *FileName, char *AppName);
  bool        INISaveFile (char *FileName, INILOCATION INILocation, char *AppName);
  void        INICloseFile(void);
  bool        INIKeyExists (char *Key);
  bool        INIGetARGB (char *Key, byte *Alpha, byte *Red, byte *Green, byte *Blue, dword DefaultValue);
  bool        INIGetRGB (char *Key, byte *Red, byte *Green, byte *Blue, dword DefaultValue);
  bool        INIGetRGB8 (char *Key, byte *Red, byte *Green, byte *Blue, dword DefaultValue);
  byte        INIGetHexByte (char *Key, byte DefaultValue, byte MinValue, byte MaxValue);
  dword       INIGetHexDWord (char *Key, dword DefaultValue, dword MinValue, dword MaxValue);
  word        INIGetHexWord (char *Key, word DefaultValue, word MinValue, word MaxValue);
  long int    INIGetInt (char *Key, long int DefaultValue, long int MinValue, long int MaxValue);
  bool        INIGetString (char *Key, char *Value, char *DefaultValue, dword MaxLength);
  void        INIKillKey (char *Key);
  INILOCATION INILocateFile (char *FileName, char *AppName);
  void        INISetARGB (char *Key, byte Alpha, byte Red, byte Green, byte Blue);
  void        INISetRGB (char *Key, byte Red, byte Green, byte Blue);
  void        INISetRGB8 (char *Key, byte Red, byte Green, byte Blue);
  void        INISetComment (char *Comments);
  void        INISetHexByte (char *Key, byte Value);
  void        INISetHexDWord (char *Key, dword Value);
  void        INISetHexWord (char *Key, word Value);
  void        INISetInt (char *Key, long int Value);
  void        INISetString (char *Key, char *Value);

  INILOCATION LangLoadStrings (char *LangFile, dword NrStrings, int FallbackLang, char *AppName);
  void        LangUnloadStrings (void);
  char       *LangGetString (dword StringID);


  /*****************************************************************************************************************************/
  /* REC Stream functions                                                                                                      */
  /*****************************************************************************************************************************/

  //That's the same (at least until a DVBc version hits the market ;-) )
  #define tRECSlot      TYPE_TimerSTMS

  int         HDD_FindPCR (byte *pBuffer, dword BufferSize, word PID);   //Returns the PCR in minutes
  bool        HDD_isAnyRecording (void);
  bool        HDD_isCryptedStream (char *Buffer, dword BufferSize);
  bool        HDD_isRecording (byte RecSlot);
  char       *HDD_MakeNewRecName (char *fname, word sequence);
  tRECSlot   *HDD_RECSlotGetAddress (byte Slot);
  bool        HDD_RECSlotSetDuration (byte Slot, word Duration);

//TODO: At least some of them will be ported
#ifdef _FUTURE_TMS_
  SYSTEM_TYPE HDD_DecodeRECHeader (char *Buffer, tRECHeaderInfo *RECHeaderInfo);
  void        HDD_EncodeRECHeader (char *Buffer, tRECHeaderInfo *RECHeaderInfo, SYSTEM_TYPE HeaderType);
  bool        HDD_FindPMT (byte *pBuffer, dword BufferSize, tRECHeaderInfo *RECHeaderInfo);
  bool        HDD_PausePlayback (bool Pause);
  bool        HDD_RECSlotPause (byte Slot, bool Pause);
  bool        HDD_RECSlotIsPaused (byte Slot);
  tPlaySlot  *HDD_PlaySlotGetAddress (void);
  int         HDD_RecalcPlaytime (TYPE_File *f, tRECHeaderInfo *Header);
#endif


  /*****************************************************************************************************************************/
  /* Shutdown                                                                                                                  */
  /*****************************************************************************************************************************/
  typedef enum
  {
    TaskPlayback   = 0xe601,
    TaskRecordings = 0xe602,
    TaskVideo      = 0xe503,
    TaskAudio      = 0xe603,
    TaskPower      = 0xef00
  } TaskEnum;

  bool Shutdown (TaskEnum Task);
  bool Reboot (bool StopRecordings);


  /*****************************************************************************************************************************/
  /* Strings                                                                                                                   */
  /*****************************************************************************************************************************/
  typedef enum
  {
    ControlChars         = 1,
    LFChars              = 2,
    InvalidFileNameChars = 4,
    NonPrintableChars    = 8
  } eRemoveChars;

  void    ExtractLine (char *Text, char *Line);
  size_t  GetLine (char *data, bool strip);
  void    LowerCase (char *string);
  void    MakeValidFileName (char *strName, eRemoveChars ControlCharacters);
  char   *ParseLine (char *zeile, size_t *n, char delim);
  char   *RTrim (char *s);
  void    SeparatePathComponents (char *FullName, char *Path, char *FileName, char *FileExt);
  bool    StrEndsWith (char *text, char *postfix);
  void    UpperCase (char *string);
  char    *ValidFileName (char *strName, eRemoveChars ControlCharacters);


  /*****************************************************************************************************************************/
  /* TAPs                                                                                                                      */
  /*****************************************************************************************************************************/

  bool  HDD_TAP_PushDir (void);
  bool  HDD_TAP_PopDir (void);
  int   HDD_TAP_GetCurrentDir (char* CurrentDir);

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


//TODO: Some of them will be ported for the TAPCOM block
#ifdef _FUTURE_TMS_
  dword HDD_TAP_Callback (dword TAPID, void *ProcedureAddress, dword param1, dword param2, dword param3, dword param4);
  bool  HDD_TAP_Disable (dword TAPID, bool DisableEvents);
  dword HDD_TAP_DisableAll (bool DisableEvents);
  int   HDD_TAP_GetCurrentDirCluster (void);
  bool  HDD_TAP_SetCurrentDirCluster (dword DirCluster);
  dword HDD_TAP_GetIDByFileName (char *TAPFileName);
  dword HDD_TAP_GetIDByIndex (int TAPIndex);
  int   HDD_TAP_GetIndexByID (dword TAPID);
  void  HDD_TAP_GetInfo (int TAPIndex, tTAPTableInfo *pTAPInfo);
  void* HDD_TAP_GetStartParameter (void);
  bool  HDD_TAP_isAnyRunning (void);
  bool  HDD_TAP_isBatchMode (void);
  dword HDD_TAP_isDisabled (dword TAPID);
  bool  HDD_TAP_isDisabledAll (void);
  bool  HDD_TAP_isRunning (dword TAPID);
  dword HDD_TAP_SendEvent (dword TAPID, bool AllowParamInterception, word event, dword param1, dword param2);
  dword HDD_TAP_Start(char *TAPFileName, bool BatchMode, void* ParameterBlock, dword *TAPID);
  bool  HDD_TAP_StartedByTAP (void);
  void  HDD_TAP_Terminate (dword TAPID);
#endif


  /*****************************************************************************************************************************/
  /* TAP Comm                                                                                                                  */
  /*   Mainly developed by asrael                                                                                              */
  /*****************************************************************************************************************************/

//TODO: would be nice on the TMS :-)
#ifdef _FUTURE_TMS_
  #define EVT_TAPCOM           0xFFF
  // Ergänzt die event codes in tap.h, da dort alle auf 00 enden, besteht die Hoffnung,
  // dass 0xFFF auch in zukünftigen API-Versionen nicht verwendet wird.

  // Die folgenden Konstanten werden in TAPCOM_OpenChannel und TAPCOM_GetChannel
  // verwendet, um die Anwendung zu identifizieren, für die eine Nachricht
  // bestimmt ist.

  #define TAPCOM_App_BROADCAST      0
  // Kann verwendet werden, um eine Nachricht an alle TAPs zu schicken, die TAPCOM
  // unterstützen.

  #define TAPCOM_NO_RETURN_VALUE 0x80000000


  typedef enum
  {
    TAPCOM_Status_OPEN,                   //Sobald der Block angelegt wird
    TAPCOM_Status_SERVER_NOT_AVAILABLE,   //Falls das Server-TAP nicht geladen ist (statt OPEN)
    TAPCOM_Status_ACKNOWLEDGED,           //Sobald der Server via ProcessEvent zugreift
    TAPCOM_Status_REJECTED,               //Dem Server unbekannter Befehl oder gerade nicht ausführbar
    TAPCOM_Status_FINISHED,               //Von Server abgeschlossen
    TAPCOM_Status_VERSIONMISMATCH,        //Die TAPCOM-Versionen des Servers und des Clients passen nicht zusammen
    TAPCOM_Status_NO_CHANNEL              //Keine gültige Verbindung
  } TAPCOM_Status;

  typedef void* TAPCOM_Channel;           // Zeiger, der intern als Kommunikationskanal verwendet wird


  //Client Funktionen

  TAPCOM_Channel TAPCOM_OpenChannel (     // setzt Remote Procedure Call an andere Anwendung ab

    dword TargetID,                       // ID der gewählten Anwendung (siehe oben)
    dword ServiceID,                      // Service-ID der gewählten Anwendung
    dword ParamBlockVersion,              // Version des Parameterblocks
    void *ParamBlock                      // Pointer auf die zu übertragenden Daten.

  );                                      // Rückgabewert: Pointer auf (internen) Kommunikationskanal. Dieser muss an die


  TAPCOM_Status TAPCOM_GetStatus (        // Liefert den Status des Kommunikationskanals

    TAPCOM_Channel Channel                // der von TAPCOM_OpenChannel zurückgegebene Kanal

  );                                      // Rückgabewert: Status des Kanals


  dword TAPCOM_LastAlive (                // Liefert den Zeitpunkt der letzten Serveraktivität (siehe: TAPCOM_StillAlive)

    TAPCOM_Channel Channel                // der von TAPCOM_OpenChannel zurückgegebene Kanal

  );                                      // Rückgabewert: Tickcount der letzten Serveraktivität


  int TAPCOM_GetReturnValue (             // Kann vom Client aus aufgerufen werden, um abzufragen,
                                          // ob der Server den RPC ausgeführt oder zurückgewiesen hat.

    TAPCOM_Channel Channel                // der von TAPCOM_OpenChannel zurückgegebene Kanal

  );                                      // Rückgabewert: der vom Server gesetzte Rückgabewert


  void TAPCOM_CloseChannel (              // Kann vom Client aufgerufen werden, um Message-Puffer nach Abschluss der
                                          // Kommunikation freizugeben.

    TAPCOM_Channel Channel                // der von TAPCOM_OpenChannel zurückgegebene Kanal

  );



  //Server-Funktionen
  TAPCOM_Channel TAPCOM_GetChannel (      // Liefert Informationen über den vom Client gesendeten Befehl

    dword param1,                         // Wird vom Event geliefert und enthält die Adresse zum Messagebuffer
    dword *CallerID,                      // ID der aufrufenden Clients (siehe oben)
    dword *ServiceID,                     // ID des gewünschten Services, frei definierbar
    dword *ParamBlockVersion,             // Version des Parameterblocks
    void  **ParamBlock                    // Rückgabe der Adresse, an der eventuelle Parameter für den Service stehen

  );                                      // Rückgabewert: Pointer auf (internen) Kommunikationskanal.


  void TAPCOM_Reject (                    // Der Server kennt den Befehl nicht oder kann diesen gerade nicht abarbeiten

    TAPCOM_Channel Channel                // der von TAPCOM_GetChannel zurückgegebene Kanal

  );

  void TAPCOM_Finish (                    // Kann vom Server aus aufgerufen werden, um dem Client ein Ergebnis vom Typ int
                                          // des RPCs zu übermitteln.

    TAPCOM_Channel Channel,               // der von TAPCOM_GetChannel zurückgegebene Kanal
    int            val                    // der Rückgabewert vom Server

  );


  void TAPCOM_StillAlive (                // Dauert die Befehlsverarbeitung länger, kann der Server dem Client mitteilen,
                                          // dass er noch aktiv ist (siehe: TAPCOM_LastAlive)

    TAPCOM_Channel Channel                // der von TAPCOM_GetChannel zurückgegebene Kanal

  );
#endif


  /*****************************************************************************************************************************/
  /* tapapifix                                                                                                                 */
  /*****************************************************************************************************************************/

  // missing items
  #define ATTR_PARENTFOLDER     0xf0
  #define ATTR_THISFOLDER       0xf1
  #define ATTR_RECYCLEFOLDER    0xf3
  #define ATTR_DELETEDFILE      0xff

  #define LAN_Persian           LAN_Iran
  #define LAN_Suomi             (LAN_Persian + 1)
  #define LAN_Slovak            (LAN_Persian + 2)
  #define LAN_Thai              (LAN_Persian + 3)
  #define LAN_Czech             (LAN_Persian + 4)
  #define LAN_Bulgarian         (LAN_Persian + 5)


  /*****************************************************************************************************************************/
  /* Compression                                                                                                               */
  /*****************************************************************************************************************************/

  typedef enum
  {
    TFDTYPE_LoaderPgm,
    TFDTYPE_ApplPgm,
    TFDTYPE_FlashData,
    TFDTYPE_EepromData,
    TFDTYPE_FactoryData,
    TFDTYPE_BackgndPict,
  } TFDTYPE;

  word  CRC16 (word StartValue, void *StartAddress, dword Length);
  dword CRC32 (dword StartValue, void *StartAddress, dword Length);
  word  UncompressBlock (byte *pInput, word compCount, byte *pOutput, word bufSize);
  dword UncompressLoader (byte *pSrc, byte *pDest, void *pPercentFinishedCallback);
  dword UncompressedLoaderSize (byte *pSrc);
  dword UncompressFirmware (byte *pSrc, byte *pDest, void *pPercentFinishedCallback);
  dword UncompressedFirmwareSize (byte *pSrc);
  dword UncompressTFD (byte *pSrc, byte *pDest, void *pPercentFinishedCallback);
  dword UncompressedTFDSize (byte *pSrc);
  dword TFDSize (byte *pTFD);

  word  CompressBlock (byte *pInput, word InBufferSize, byte *pOutput);
  dword CompressTFD (byte *pSrc, dword SourceBufferSize, byte *pDest, word TFDType, word SysID, void *pPercentFinishedCallback);
  dword CompressedTFDSize (byte *pSrc, dword SourceBufferSize, void *pPercentFinishedCallback);


  /*****************************************************************************************************************************/
  /* Dialog                                                                                                                    */
  /*****************************************************************************************************************************/

  typedef struct
  {
    dword               BorderColor;
    dword               TitleBackgroundColor;
    dword               TitleTextColor;
    dword               ItemsLineBackgroundColor;
    dword               ItemsLineBackgroundSelectedColor;
    dword               ItemsIconBackgroundColor;
    dword               ItemsIconBackgroundSelectedColor;
    dword               ItemsTextColor;
    dword               ItemsTextDisabledColor;
    dword               ItemsTextSelectedColor;
    dword               ItemsGridColor;
    dword               InfoBackgroundColor;
    dword               ScrollBarColor;
    dword               ButtonIn;
    dword               ButtonOut;
    dword               ProgressBarColor;
    bool                ScrollScreen;
    bool                ScrollWrapAround;
    word                Fade;
    word                FontSize;
    word                HDDAccess;
    dword               Magic;
    // this is a copy of the latest profile values in order to determine changes
    dword               OldBorderColor;
    dword               OldTitleBackgroundColor;
    dword               OldTitleTextColor;
    dword               OldItemsLineBackgroundColor;
    dword               OldItemsLineBackgroundSelectedColor;
    dword               OldItemsIconBackgroundColor;
    dword               OldItemsIconBackgroundSelectedColor;
    dword               OldItemsTextColor;
    dword               OldItemsTextDisabledColor;
    dword               OldItemsTextSelectedColor;
    dword               OldItemsGridColor;
    dword               OldInfoBackgroundColor;
    dword               OldScrollBarColor;
    word                OldFontSize;
  } tDialogProfile;

  typedef enum
  {
    DialogWindowType_NormalLines,
    DialogWindowType_NormalLinesNoIcons,
    DialogWindowType_NoLinesSmallIcons,
    DialogWindowType_NoLinesNoIcons,
    DialogWindowType_NR_OF_TYPES
  } eDialogWindowTypes;

  typedef enum
  {
    DialogItemIcon_None,
    DialogItemIcon_Checkbox_Checked,
    DialogItemIcon_Checkbox_Unchecked,
    DialogItemIcon_Exclamation,
    DialogItemIcon_Wait,
    DialogItemIcon_OK,
    DialogItemIcon_User
  } eDialogItemIcons;

  typedef enum
  {
    PARAMETER,
    VALUE
  } eDialogItemArea;

  typedef struct
  {
    char                Parameter [128];
    dword               ParameterColor;
    char                Value [128];
    dword               ValueColor;
    eDialogItemIcons    Icon;
    TYPE_GrData         *UserIcon;
    bool                Selectable;
    bool                Enabled;
    int                 UserData;
  } tDialogItem;

  typedef enum
  {
    InfoString,
    InfoIcon
  } eDialogInfoItemType;

  typedef struct sDialogInfoItem
  {
    eDialogInfoItemType    ItemType;
    dword                  X;
    dword                  Y;
    dword                  MaxX;
    dword                  FColor;
    dword                  BColor;
    byte                   FontSize;
    byte                   bDot;
    byte                   Align;
    void                   *data;
    struct sDialogInfoItem *next;
  } tDialogInfoItem;

  #define DIALOGWINDOW_MAX_NR_ITEM_LINES 30
  #define DIALOGWINDOW_MAX_TABS           8

  typedef struct
  {
    dword               OSDX;               //OSD region parameter
    dword               OSDY;
    dword               OSDWidth;
    dword               OSDHeight;
    word                OSDRgn;
    word                MemOSDBorderN;
    word                MemOSDBorderW;
    word                MemOSDBorderE;
    word                MemOSDBorderS;
    word                MemOSDTitle;
    word                MemOSDLines;
    word                MemOSDLineSelected;
    word                MemOSDScrollBar;
    word                MemOSDInfoN;
    word                MemOSDInfo;
    word                MemOSDInfoS;
    bool                OSDBorderBackDirty;
    bool                OSDTitleForeDirty;
    bool                OSDTitleBackDirty;
    bool                OSDLineForeDirty[DIALOGWINDOW_MAX_NR_ITEM_LINES];
    bool                OSDLineBackDirty;
    bool                OSDLineSelectedBackDirty;
    bool                OSDScrollBarForeDirty;
    bool                OSDScrollBarBackDirty;
    bool                OSDInfoForeDirty;
    bool                OSDInfoBackDirty;
    dword               Transparency;
    bool                isVisible;
    bool                isNormalMode;
    bool                Multiple;
    byte                *MultipleOSDSaveBox;
    bool                hasCursor;

    dword               TitleY;             //Graphical elements
    dword               ItemsY;
    dword               InfoNY;
    dword               InfoY;
    dword               InfoSY;
    int                 NrTitleColumns;
    int                 NrItemLines;
    int                 NrItemColumns;
    int                 NrInfoNColumns;
    int                 NrInfoColumns;
    int                 NrInfoSColumns;
    dword               ParameterWidth;
    int                 NrInfoLines;
    dword               ItemLineWidth;

    char                LTitle [128];        //Title
    char                CTitle [128];
    char                RTitle [128];

    int                 NrItems;            //Items
    int                 ReservedItems;
    int                 TopItem;
    int                 SelectedItem;
    tDialogItem         *DialogItems;
    tDialogInfoItem     *InfoItems;
    bool                InfoOwnForeColor;
    eDialogWindowTypes  Type;
    dword               TabsParameter[DIALOGWINDOW_MAX_TABS];
    dword               TabsValue[DIALOGWINDOW_MAX_TABS];
  } tDialogWindow;

  typedef struct
  {
    char                DialogTitle [128];
    char                DialogSubTitle [256];
    char                ButtonText [5][20];
    dword               DefaultButton;
    bool                isVisible;
    bool                isNormalMode;
    int                 SelectedButton;

    word                OSDRgn;
    word                MemOSDRgn;
    byte                *OSDSaveBox;
    int                 NrButtons;
    dword               DialogWidth;
    dword               InfoBoxTimeout;
    bool                ExpandedBox;
    int                 VirtualButtonCount;
  } tDialogMsgBox;

  typedef struct
  {
    dword               OSDX;
    dword               OSDY;
    word                OSDRgn;
    word                MemOSDRgn;
    byte                *OSDSaveBox;
    bool                isVisible;
    bool                isNormalMode;
    char                Title [128];
    int                 Min;
    int                 Max;
    int                 Value;
    int                 Perc;
    word                BarColor;
  } tDialogProgressBar;

  #define info_h(l)     ((l) * 20)

  void DialogWindowInit   (tDialogWindow *DialogWindow, tDialogProfile *DialogProfile, dword X, dword Y, dword Width, dword NrItemLines, char *LTitle, char *CTitle, char *RTitle, dword ParameterWidth, dword InfoHeight, eDialogWindowTypes WindowType);
  void DialogWindowReInit (dword X, dword Y, dword Width, dword NrItemLines, dword ParameterWidth, dword InfoHeight);
  void DialogWindowChange (tDialogWindow *DialogWindow, bool Redraw);
  void DialogWindowExit   (void);
  void DialogWindowShow   (void);
  void DialogWindowAlpha  (byte Alpha);
  void DialogWindowHide   (void);
  void DialogWindowRefresh (void);
  void DialogWindowTitleChange (char *LTitle, char *CTitle, char *RTitle);
  void DialogWindowInfoAddS (dword X, dword Y, dword MaxX, char *Text, dword FColor, dword BColor, byte FontSize, byte bDot, byte Align);
  void DialogWindowInfoAddIcon (dword X, dword Y, TYPE_GrData *IconGd);
  void DialogWindowInfoDeleteAll (void);
  void InfoTestGrid (void);

  void        DialogProfileChange  (tDialogProfile *DialogProfile);
  void        DialogProfileCheck (tDialogProfile *DialogProfile, char *AppName);
  void        DialogProfileScrollBehaviourChange (bool ScrollScreen, bool WrapAround);
  INILOCATION DialogProfileLoad (char *FileName, char *AppName);
  void        DialogProfileLoadDefault (void);
  INILOCATION DialogProfileLoadMy (char *AppName);
  bool        DialogProfileSave (char *FileName, INILOCATION INILocation, char *AppName);
  bool        DialogProfileSaveDefault (void);

  int  DialogWindowItemAdd             (char *Parameter, dword ParameterColor, char *Value, dword ValueColor, bool Selectable, bool Enabled, eDialogItemIcons IconType, TYPE_GrData *IconGd);
  void DialogWindowItemAddSeparator    (void);
  void DialogWindowItemChangeFlags     (int ItemIndex, bool Selectable, bool Enabled);
  void DialogWindowItemChangeIcon      (int ItemIndex, eDialogItemIcons IconType, TYPE_GrData *IconGd);
  void DialogWindowItemChangeParameter (int ItemIndex, char *Parameter, dword ParameterColor);
  void DialogWindowItemChangeValue     (int ItemIndex, char *Value, dword ValueColor);
  void DialogWindowItemDelete          (int ItemIndex);
  void DialogWindowItemDeleteAll       (void);

  void DialogWindowScrollDown       (void);
  void DialogWindowScrollUp         (void);
  void DialogWindowScrollDownPage   (void);
  void DialogWindowScrollUpPage     (void);

  void DialogWindowCursorChange (bool visible);
  void DialogWindowCursorSet    (int ItemIndex);
  void DialogWindowTabulatorSet (dword Pos, eDialogItemArea Which);
  void DialogWindowTypeChange   (eDialogWindowTypes WindowType);

  void DialogMsgBoxInit (tDialogMsgBox *DialogMsgBox, tDialogProfile *DialogProfile, char *Title, char *SubTitle);
  void DialogMsgBoxButtonAdd (char *ButtonText, bool Default);
  void DialogMsgBoxShow (void);
  void DialogMsgBoxShowInfo (dword ms);
  void DialogMsgBoxShowOK (void);
  void DialogMsgBoxShowOKCancel (dword DefaultButton);
  void DialogMsgBoxShowYesNo (dword DefaultButton);
  void DialogMsgBoxShowYesNoCancel (dword DefaultButton);
  void DialogMsgBoxTitleSet (char *Title, char *SubTitle);
  void DialogMsgBoxExit (void);

  void DialogEvent (word *event, dword *param1, dword *param2);

  void DialogProgressBarInit (tDialogProgressBar *DialogProgressBar, tDialogProfile *DialogProfile, dword X, dword Y, char *Title, int Minimum, int Maximum);
  void DialogProgressBarShow (void);
  void DialogProgressBarTitleSet (char *Title);
  void DialogProgressBarSet (int Value, dword BarColor);
  void DialogProgressBarExit (void);

  int  TAP_Osd_Copy_Chk(char *Comment, word srcRgnNum, word dstRgnNum, dword srcX, dword srcY, dword w, dword h, dword dstX, dword dstY,  bool sprite);
  int  TAP_Osd_PutGd_Chk(char *Comment, word rgn, int x, int y, TYPE_GrData * gd, bool sprite);
  int  TAP_Osd_PutFreeColorGd_Chk(char *Comment, word rgn, int x, int y, TYPE_GrData * gd, bool sprite, dword FilterColor);


  /*****************************************************************************************************************************/
  /* Firmware Patches                                                                                                          */
  /*****************************************************************************************************************************/

  //Firmware.dat structure
  typedef struct
  {
    dword                 Magic;                  //0x12345678
    dword                 CompileDate;            //yymd
    word                  ToppyInfoLayoutVersion;
    word                  FWInfoLayoutVersion;
    dword                 NrOfToppyInfoEntries;
    dword                 NrOfFWInfoEntries;
  } tFWDATHeader;

  typedef enum
  {
    DT_LED,
    DT_VFD5500,
    DT_VFDMP
  } DISPLAY_TYPE;

  typedef struct
  {
    word                  SysID;
    word                  unused1;
    char                  Device [256];
    char                  AppType [32];
    SYSTEM_TYPE           SystemType;
    dword                 FlashBase;
    bool                  EMMA;
    bool                  BigEndian;
    bool                  PVR;
    bool                  TAPs;
    DISPLAY_TYPE          DisplayType;
    byte                  unused2 [28];
  } tToppyInfo;

  typedef struct
  {
    word                  SysID;
    word                  unused1;
    dword                 FWgp;
    dword                 FWDate;
    word                  AppVersion;
    word                  unused2;
    dword                 unused3;
    bool                  Beta;
    byte                  MD5 [16];
    byte                  unused4 [32];
  } tFWInfo;

  bool          LoadFirmwareDat (tFWDATHeader **FWDatHeader, tToppyInfo **ToppyInfo, tFWInfo **FWInfo);

  /*****************************************************************************************************************************/
  /* FileSelector                                                                                                              */
  /*   Developed by ibbi                                                                                                       */
  /*****************************************************************************************************************************/

  // Aufruf des File-Selectors
  bool FileSelector (dword *key, char *filename, char *filter, dword flags);

  // liefert den Wert zurück, den FileSelector in *key eintragen würde
  dword FileSelectorKey (dword key, dword flags);


  // Flags:

  #define FS_SHOW_ALL         1   // zeigt alle Dateien, auch versteckte und Systemdateien
  #define FS_STRIP_EXTENSION  2   // Anzeige (und Rückgabe!) ohne Dateityp
  #define FS_SORT_BY_NAME     4   // alphabetische Sortierung
  #define FS_SORT_BY_DATE     8   // Sortierung nach Datum
  #define FS_WIDE            16   // breites Fenster
  #define FS_NOCASE_FILTER   32   // ignoriert Groß-/Kleinschreibung beim Filter
  #define FS_NOCASE_SORT     64   // ignoriert Groß-/Kleinschreibung beim Sortieren
  #define FS_DIALOGWINDOW   128   // Fenster in Dialog-Grafik aus der FireBirdLib


  /*
  Benutzung:

  1. Es muss eine statische boolsche Variable (z. B. fileselector)
     definiert werden, die mit FALSE initialisiert ist.

  2. Der FileSelector wird mit

       fileselector = FileSelector(NULL, NULL, filter, flags);

     im Event-Handler gestartet, wobei filter (ohne Leerzeichen) die
     (durch Semikolon getrennten) gewünschten Dateiendungen (mit Punkt)
     enthält (Beispiel: ".rec" oder ".txt;.ini") und flags die gewünschten
     Einstellungen (ODER-verknüpft).

  3. Ebenfalls im Event-Handler reicht man Tasten wie folgt durch:

      if (fileselector)
      {
        fileselector = FileSelector(&key, filename, NULL, 0);

        if (key == 0)
        {
          if (!fileselector)
          {
            if (*filename) // ausgewählte Datei steht in filename;
            else // Abbruch wurde gewählt;
          }
        }
      }

    Ist key != 0, war die Taste dem FileSelector unbekannt und muss ggf. vom
    TAP behandelt werden.

    Der Rückgabewert fileselector wird im Fall eines Abbruchs oder einer
    Auswahl automatisch auf FALSE gesetzt. Während der Navigation o. ä. bleibt
    er auf TRUE.

    Unterstütze Tasten:

      V+          eine Zeile hoch
      V-          eine Zeile runter
      P+          zum Anfang der Liste
      P-          zum Ende der Liste
      OK          Auswahl
      EXIT        Abbruch
  */
