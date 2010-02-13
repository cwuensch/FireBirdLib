  extern dword          SysID;
  extern word           ApplID;

#ifdef _TMS_
  #define isTMS         1
#else
  #define isTMS         0
#endif

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
//  #define DEBUG_FIREBIRDLIB

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
  dword GetUptime(void);

  void CallTraceInit (void);
  void CallTraceEnable (bool Enable);
  void CallTraceEnter (char *ProcName);
  void CallTraceExit (dword *Magic);
  void CallTraceExitResult (dword *Magic, char *Result);
  void CallTraceComment (char *Comment);


  /*****************************************************************************************************************************/
  /* FindInstuctionSequences                                                                                                   */
  /*****************************************************************************************************************************/

  inline dword FIS_vBootReason(void);
  inline dword FIS_vEEPROM (void);
  inline dword FIS_vEEPROMPin (void);
  inline dword FIS_vEtcInfo(void);
  inline dword FIS_vFlash (void);
  inline dword FIS_vOSDMap (void);
  inline dword FIS_vParentalInfo(void);
  inline dword FIS_vRECSlotAddress (byte Slot);
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


  /*****************************************************************************************************************************/
  /* Audio / Video / OSD                                                                                                       */
  /*****************************************************************************************************************************/
  //Forgotten keys
  #define RKEY_Red      RKEY_NewF1
  #define RKEY_Green    RKEY_F2
  #define RKEY_Yellow   RKEY_F3
  #define RKEY_Blue     RKEY_F4
  #define RKEY_Option   0x10049

  #define _Clip(a)      (a)>255 ? 255 : (a)<0 ? 0 : (a)

  #define YUVR(y,u,v)   ((0x2568*(y) + 0x3343*(u)) >>13)                //0x2000
  #define YUVG(y,u,v)   ((0x2568*(y) - 0x0c92*(v) - 0x1a1e*(u)) >>13)   //0x2000
  #define YUVB(y,u,v)   ((0x2568*(y) + 0x40cf*(v)) >>13)                //0x2000

  #define win_w(w)      ((w) + 51)
  #define win_h(h)      (((h) / 22 + ((h) % 22 ? 1 : 0)) * 22 + 8)
  #define win_l(h)      ((win_h(h) - 8) / 22)

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
  bool  isAnyOSDVisible (dword checkX, dword checkY, dword checkW, dword checkH);
  bool  isOSDRegionAlive (word Region);
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


  /*****************************************************************************************************************************/
  /* Flash & EEPROM                                                                                                            */
  /*****************************************************************************************************************************/

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
    unused              = 13,     //unused on the TF5k, block reserved for downward comp.
    WLAN                = 14,     //Server Settings
    FirmwareServer      = 15,
    NetworkProfiles     = 16,
    AutoDescrambleTimer = 17,
    BLOCKS              = 18
  } TYPE_FlashBlock;

  typedef enum
  {
    ST_UNKNOWN,
    ST_DVBS,
    ST_DVBT,
    ST_DVBC,
    ST_DVBT5700,
    ST_DVBSTMS
  } SYSTEM_TYPE;

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

  typedef enum
  {
    delete,
    insert
  } ReindexType;

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
  char                 *DayOfWeek(byte WeekDay);


  /*****************************************************************************************************************************/
  /* HDD Functions                                                                                                             */
  /*****************************************************************************************************************************/

  #define FBLIB_DIR_SIZE 256

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

  //Some of them are missing in the TF5k hdd.h and alle are missing in the TMS hdd.h
  #ifndef SEEK_SET
    #define SEEK_SET  0	/* set file offset to offset */
  #endif

  #ifndef SEEK_CUR
    #define SEEK_CUR  1	/* set file offset to current plus offset */
  #endif

  #ifndef SEEK_END
    #define SEEK_END  2	/* set file offset to EOF plus offset */
  #endif

  typedef enum
  {
    FIU_No,
    FIU_Playback,
    FIU_PlayMP3,
    FIU_RecSlot1,
    FIU_RecSlot2
  }tFileInUse;

  void       FixInvalidFileName(char *FileName);
  int        HDD_AAM_Disable (void);
  int        HDD_AAM_Enable (byte AAMLevel);
  int        HDD_APM_Disable (void);
  int        HDD_APM_Enable (byte APMLevel);
  TYPE_File *HDD_FappendOpen (char *filename);
  bool       HDD_ChangeDir (char *Dir);
  void       HDD_Delete(char *FileName);
  bool       HDD_FappendWrite (TYPE_File *file, char *data);
  tFileInUse HDD_isFileInUse(char *FileName);
  bool       HDD_GetHddID (char *ModelNo, char *SerialNo, char *FirmwareNo);
  bool       HDD_IdentifyDevice (char *IdentifyDeviceBuffer);
  bool       HDD_Move(char *FileName, char *FromDir, char *ToDir);
  void       HDD_Recycle(char *FileName);
  void       HDD_Rename(char *FileName, char *NewFileName);
  int        HDD_Smart_DisableAttributeAutoSave (void);
  int        HDD_Smart_DisableOperations (void);
  int        HDD_Smart_EnableAttributeAutoSave (void);
  int        HDD_Smart_EnableOperations (void);
  int        HDD_Smart_ReadData (word *DataBuf);
  int        HDD_Smart_ReadThresholdData (word *DataBuf);
  int        HDD_Smart_ReturnStatus (void);                  ////if 20 is returned then one or more thresholds have been exceeded; -1 upon error
  void       HDD_Unrecycle(char *FileName);
  bool       HDD_Write (void *data, dword length, TYPE_File *f);
  void       MakeUniqueFileName(char *FileName);
  void       SeparateFileNameComponents(char *FileName, char *Name, char *Ext, int *Index, bool *isRec, bool *isDel);


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
    dword       MagicNumber;    //0x54467263 (TFrc)
    word        Version;        //0x8000
    byte        reserved1[2];
    dword       StartTime;
    word        Duration;       //in minutes
    byte        reserved2[2];
    byte        CryptFlag;
    byte        reserved3[11];
  } __attribute__((packed)) tRECHeaderTMS;              //28 bytes

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

  typedef struct
  {
    SYSTEM_TYPE         HeaderType;

    dword               HeaderMagic;
    word                HeaderVersion;
    byte                HeaderReserved1[2];
    byte                HeaderReserved2[2];   //TMS
    byte                HeaderReserved3[11];  //TMS
    dword               HeaderStartTime;      //TMS
    word                HeaderDuration;
    word                HeaderSvcNumber;
    word                HeaderSvcType;

    byte                SISatIndex;
    byte                SIReserved1;
    word                SITPIdx;
    byte                SITunerNum;
    byte                SIDelFlag;
    byte                SICASFlag;
    byte                SILockFlag;
    byte                SISkipFlag;
    word                SIServiceID;
    word                SIPMTPID;
    word                SIPCRPID;
    word                SIVideoPID;
    word                SIAudioPID;
    char                SISvcName[28];
    byte                SIVideoStreamType;    //TMS
    byte                SIAudioStreamType;    //TMS

    byte                TPSatIndex;           //S
    byte                TPPolarization;       //S
    byte                TPMode;               //S
    byte                TPSystem;             //TMS
    byte                TPModulation;         //C TMS
    byte                TPFEC;                //TMS
    byte                TPPilot;              //TMS
    word                TPChannelNumber;      //T
    byte                TPBandwidth;          //T
    byte                TPLPHPStream;         //T
    dword               TPFrequency;          //STC
    word                TPSymbolRate;         //SC
    word                TPTSID;               //STC
    word                TPOriginalNetworkID;  //STC
    byte                TPClockSync;          //TMS
    byte                TPReserved1[2];       //S
    byte                TPReserved2[2];       //S
    byte                TPReserved3;          //ST
    byte                TPReserved4;          //T
    byte                TPUnknown1[2];        //T
    byte                TPUnknown2[8];        //T (5700 only)
    byte                TPUnknown3[4];        //TMS
    byte                TPReserved5;          //C

    byte                EventDurationHour;
    byte                EventDurationMin;
    word                EventEventID;
    dword               EventStartTime;
    dword               EventEndTime;
    byte                EventRunningStatus;
    byte                EventTextLength;
    byte                EventParentalRate;
    char                EventEventName[257];
    char                EventEventDescription[257];
    byte                EventUnknown1[2];
    byte                EventUnknown2[2];
    byte                EventUnknown3[18];

    word                ExtEventServiceID;    //TMS
    word                ExtEventTextLength;
    word                ExtEventEventID;
    char                ExtEventText [1024];
    byte                ExtEventUnknown1[2];

    byte                CryptReserved1 [4];
    byte                CryptFlag;
    byte                CryptReserved2 [3];

    dword               Bookmark [64];

    dword               Resume;
  } tRECHeaderInfo;

  SYSTEM_TYPE HDD_DecodeRECHeader (char *Buffer, tRECHeaderInfo *RECHeaderInfo);
  void        HDD_EncodeRECHeader (char *Buffer, tRECHeaderInfo *RECHeaderInfo, SYSTEM_TYPE HeaderType);
  int         HDD_FindPCR (byte *pBuffer, dword BufferSize, word PID);   //Returns the PCR in minutes
  bool        HDD_isAnyRecording (void);
  bool        HDD_isCryptedStream (char *Buffer, dword BufferSize);
  bool        HDD_isRecording (byte RecSlot);
  char       *HDD_MakeNewRecName (char *fname, word sequence);
  bool        HDD_RECSlotSetDuration (byte Slot, word Duration);


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
  bool    StringEndsWith(char *text, char *postfix);
  void    UpperCase (char *string);
  char   *ValidFileName (char *strName, eRemoveChars ControlCharacters);


  /*****************************************************************************************************************************/
  /* TAPs                                                                                                                      */
  /*****************************************************************************************************************************/

  bool  HDD_TAP_PushDir (void);
  bool  HDD_TAP_PopDir (void);
  int   HDD_TAP_GetCurrentDir (char* CurrentDir);
  dword HDD_TAP_Start(char *TAPFileName, bool BatchMode, void* ParameterBlock, dword *TAPID);


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
  dword OATH(register unsigned char * data, int len, dword hash);
  dword SuperFastHash(register unsigned char * data, int len, dword hash);
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

  int  TAP_Osd_Create_Chk(char *Comment, dword x, dword y, dword w, dword h, byte lutIdx, int flag);
  int  TAP_Osd_Copy_Chk(char *Comment, word srcRgnNum, word dstRgnNum, dword srcX, dword srcY, dword w, dword h, dword dstX, dword dstY,  bool sprite);
  int  TAP_Osd_PutGd_Chk(char *Comment, word rgn, int x, int y, TYPE_GrData * gd, bool sprite);
  int  TAP_Osd_PutFreeColorGd_Chk(char *Comment, word rgn, int x, int y, TYPE_GrData * gd, bool sprite, dword FilterColor);
  int  TAP_Osd_FillBox_Chk(char *Comment, word rgn, dword x, dword y, dword w, dword h, dword color);
  byte* TAP_Osd_SaveBox_Chk(char *Comment, word rgn, dword x, dword y, dword w, dword h);
  void TAP_Osd_RestoreBox_Chk(char *Comment, word rgn, dword x, dword y, dword w, dword h, void *data);
  int  TAP_Osd_PutPixel_Chk(char *Comment, word rgn, dword x, dword y, dword pix);
  void* TAP_MemAlloc_Chk(char *Comment, dword size);


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

//Test
void RemoveTestDir(void);
