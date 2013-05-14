/************************************************/
/* USE ONLY TO TEST LINKING AGAINST libFireBird */
/* CHECKS ALL libFireBird FUNCTIONS             */
/************************************************/

#include "tap.h"
#include "../av/FBLib_av.h"
#include "../EPG/FBLib_EPG.h"
#include "../flash/FBLib_flash.h"
#include "../FontManager/FBLib_FontManager.h"
#include "../hdd/FBLib_hdd.h"
#include "../ini/FBLib_ini.h"
#include "../libFireBird.h"
#include "../main/FBLib_main.h"
#include "../rec/FBLib_rec.h"
#include "../shutdown/FBLib_shutdown.h"
#include "../string/FBLib_string.h"
#include "../tap/FBLib_tap.h"
#include "../tapcom/FBLib_tapcom.h"
#include "../TMSOSDKeyboard/FBLib_TMSOSDKeyboard.h"
#include "../TMSOSDMenu/FBLib_TMSOSDMenu.h"
#include "../tmsvfd/FBLib_tmsvfd.h"

TAP_ID(0);
TAP_PROGRAM_NAME("");
TAP_AUTHOR_NAME("");
TAP_DESCRIPTION("");
TAP_ETCINFO(__DATE__);

dword TAP_EventHandler(word event, dword param1, dword param2)
{
  (void) event;
  (void) param2;

  return param1;
}

int TAP_Main()
{
  AddSec(0, 0, 0);
  AddTime(0, 0);
  Appl_CheckRecording(0, 0, FALSE);
  Appl_CheckRecording_Tuner(0, 0, 0, FALSE);
  Appl_ClrTimer(NULL);
  Appl_ExportChData(NULL);
  Appl_EvtProc_PincodeKey(0, 0);
  Appl_GetCurrentEvent(0, 0, 0, 0);
  Appl_GetEvtCount(0, 0, 0, 0);
  Appl_GetEvtCountInFreePool();
  Appl_GetEvtListHeadInHash(0, 0, 0);
  Appl_GetEvtListHeadInHashByChannelID(0);
  Appl_GetEvtListHeadInUsePool();
  Appl_GetFreeExtRecordSpace(NULL);
  Appl_GetIsExternal();
  Appl_ImportChData(NULL);
  Appl_PvrPause(FALSE);
  Appl_RestartTimeShiftSvc(FALSE, 0);
  Appl_SetIsExternal(FALSE);
  Appl_SetPlaybackSpeed(0, 0, FALSE);
  Appl_ShoutCast();
  Appl_StartPlaybackMedia(NULL, 0, FALSE, FALSE);
  Appl_StopPlaying();
  Appl_StopRecPlaying(FALSE);
  Appl_TimeToLocal(0);
  Appl_WaitEvt(0, NULL, 0, 0, 0);
  Appl_WriteRecInfo(0);
  ApplChannel_GetAgc(0, NULL);
  ApplChannel_GetBer(0, NULL);
  ApplHdd_FileCutPaste(NULL, 0, 0, NULL);
  ApplHdd_FreeSize(NULL, FALSE);
  ApplHdd_GetFileInfo(0, NULL, NULL, 0, 0);
  ApplHdd_GetInfoFromExternalDevice(NULL, NULL, NULL);
  ApplHdd_RestoreWorkFolder();
  ApplHdd_SaveWorkFolder();
  ApplHdd_SelectFolder(NULL, NULL);
  ApplHdd_SetWorkFolder(NULL);
  ApplNewVfd_Stop();
  ApplPin_Delete();
  ApplPin_IsLockPopup();
  ApplSvc_GetSvcIdx(0, 0, 0, 0, 0, 0);
  ApplSvc_GetTpIdx(0, 0, 0);
  ApplTap_GetEmptyTask();
  ApplTimer_OptimizeList();
  AudioTrackInfo();
  BMP_WriteHeader(NULL, 0, 0);
  BootReason();
  CallTraceComment(NULL);
  CallTraceEnable(FALSE);
  CallTraceEnter(NULL);
  CallTraceExit(NULL);
  CallTraceExitResult(NULL, NULL);
  CallTraceExportStats(NULL);
  CallTraceInit();
  CallTraceResetStats();
  CaptureScreen(0, 0, NULL, FALSE, 0);
  ChangeDirRoot();
  CompressBlock(NULL, 0, NULL);
  CompressedTFDSize(NULL, 0, NULL);
  CompressTFD(NULL, 0, NULL, 0, 0, NULL);
  CrashCheck_Shutdown(NULL);
  CrashCheck_Startup(NULL);
  CRC16(0, NULL, 0);
  CRC32(0, NULL, 0);
  curl_easy_cleanup(NULL);
  curl_easy_init();
  curl_easy_perform(NULL);
  curl_easy_setopt(NULL, 0, NULL);
  curl_global_cleanup();
  curl_global_init(0);
  DayOfWeek(0);
  DeleteAt(NULL, 0, 0);
  DevFront_SetIlluminate(0, 0);
  DevHdd_DeviceClose(NULL);
  DevHdd_DeviceOpen(NULL, NULL);
  DevService_Mute(FALSE);
  DrawOSDLine(0, 0, 0, 0, 0, 0);
  DST_CalcTransition(0, 0, 0, 0, 0);
  DST_FindNextTransition();
  DST_GetDefaultDSTRule();
  DST_GetNextTransition(0, 0, 0, 0, 0, 0);
  DST_GetTransitions_Europe(NULL, NULL);
  DST_GetTransitions_Manual(NULL, NULL);
  DST_ProcessRule(NULL, NULL);
  DST_SetDSTRule(0);
  DumpMemory(NULL, 0, 0);
  DumpMemoryDword(NULL, 0);
  ELFCleanup();
  ELFGetSectionAddress(0, NULL, NULL);
  ELFGetSectionIndex(NULL);
  ELFOpenAbsFile(NULL);
  ELFOpenFile(NULL);
  ELFReadData(0, NULL);
  ELFReadDWORD(0, NULL);
  ELFReadELFHeader();
  ELFReadSectionHeaders();
  ELFReadShstrtabSection();
  EndMessageWin();
  EPGInfo_AbortLoad();
  EPGInfo_CalculateStructSize();
  EPGInfo_CloneToCache(NULL, 0, NULL);
  EPGInfo_CountEvents(NULL);
  EPGInfo_CreateCache(0);
  EPGInfo_DestroyCache();
  EPGInfo_FilterCallback(NULL);
  EPGInfo_FilterChannelByIndex(0, 0, FALSE);
  EPGInfo_FilterDuration(0, 0);
  EPGInfo_FilterGenre(NULL, 0);
  EPGInfo_FilterReset();
  EPGInfo_FilterTime(0, 0);
  EPGInfo_FindFirst(NULL);
  EPGInfo_FindItem(NULL, 0, FALSE);
  EPGInfo_FindLast(NULL);
  EPGInfo_FindNext(NULL);
  EPGInfo_FindPrev(NULL);
  EPGInfo_Free();
  EPGInfo_GetNrFreeEntries();
  ExtAttribExists(NULL, NULL);
  ExtAttribExistsAbsPath(NULL, NULL);
  ExtAttribGet(NULL, NULL, NULL, 0, NULL);
  ExtAttribGetAbsPath(NULL, NULL, NULL, 0, NULL);
  ExtAttribRemove(NULL, NULL);
  ExtAttribRemoveAbsPath(NULL, NULL);
  ExtAttribSet(NULL, NULL, NULL, 0);
  ExtAttribSetAbsPath(NULL, NULL, NULL, 0);
  ExtractLine(NULL, NULL);
  ezxml_attr(NULL, NULL);
  ezxml_child(NULL, NULL);
  ezxml_error(NULL);
  ezxml_free(NULL);
  ezxml_idx(NULL, 0);
  ezxml_parse_file(NULL);
  ezxml_parse_str(NULL, 0);
  FindGotPointer(0);
  FindInstructionSequence(NULL, NULL, 0, 0, 0, FALSE);
  FirmwareDatMJD();
  FIS_fwAppl_AddSvcName();
  FIS_fwAppl_CheckRecording();
  FIS_fwAppl_CheckRecording_Tuner();
  FIS_fwAppl_CiMenu();
  FIS_fwAppl_CiplusMenu();
  FIS_fwAppl_ClrTimer();
  FIS_fwAppl_ConvertToValidUTF8Str();
  FIS_fwAppl_DeleteRadioSvcName();
  FIS_fwAppl_DeleteTvSvcName();
  FIS_fwAppl_EnterNormal();
  FIS_fwAppl_EvtProc_PincodeKey();
  FIS_fwAppl_ExecProgram();
  FIS_fwAppl_ExportChData();
  FIS_fwAppl_GetCurrentEvent();
  FIS_fwAppl_GetEvtCount();
  FIS_fwAppl_GetEvtCountInFreePool();
  FIS_fwAppl_GetEvtListHeadInHash();
  FIS_fwAppl_GetEvtListHeadInUsePool();
  FIS_fwAppl_GetFreeExtRecordSpace();
  FIS_fwAppl_GetIsExternal();
  FIS_fwAppl_GetStreamFormat();
  FIS_fwAppl_ImportChData();
  FIS_fwAppl_InitTempRec();
  FIS_fwAppl_IsTimeShifting();
  FIS_fwAppl_PvrList();
  FIS_fwAppl_PvrList_SetListType();
  FIS_fwAppl_PvrPause();
  FIS_fwAppl_RestartTimeShiftSvc();
  FIS_fwAppl_SetApplVer();
  FIS_fwAppl_SetIsExternal();
  FIS_fwAppl_SetPlaybackSpeed();
  FIS_fwAppl_SetProviderName();
  FIS_fwAppl_SetTimeShift();
  FIS_fwAppl_ShoutCast();
  FIS_fwAppl_StartPlaybackMedia();
  FIS_fwAppl_StartTempRec();
  FIS_fwAppl_StopPlaying();
  FIS_fwAppl_StopRecPlaying();
  FIS_fwAppl_StopTempRec();
  FIS_fwAppl_TimeToLocal();
  FIS_fwAppl_WaitEvt();
  FIS_fwAppl_WriteFlash();
  FIS_fwAppl_WriteRecInfo();
  FIS_fwApplChannel_GetAgc();
  FIS_fwApplChannel_GetBer();
  FIS_fwApplHdd_FileCutPaste();
  FIS_fwApplHdd_FreeSize();
  FIS_fwApplHdd_GetFileInfo();
  FIS_fwApplHdd_GetInfoFromExternalDevice();
  FIS_fwApplHdd_RestoreWorkFolder();
  FIS_fwApplHdd_SaveWorkFolder();
  FIS_fwApplHdd_SelectFolder();
  FIS_fwApplHdd_SetWorkFolder();
  FIS_fwApplIcelink_EitFromHdd();
  FIS_fwApplOsd_DrawJpeg();
  FIS_fwApplPin_Delete();
  FIS_fwApplPin_IsLockPopup();
  FIS_fwApplSvc_GetSvcIdx();
  FIS_fwApplSvc_GetTpIdx();
  FIS_fwApplTap_CallEventHandler();
  FIS_fwApplTap_GetEmptyTask();
  FIS_fwApplTimer_OptimizeList();
  FIS_fwApplVfdSendData();
  FIS_fwApplVfdStart();
  FIS_fwApplVfdStop();
  FIS_fwcurl_easy_cleanup();
  FIS_fwcurl_easy_init();
  FIS_fwcurl_easy_perform();
  FIS_fwcurl_easy_setopt();
  FIS_fwcurl_global_cleanup();
  FIS_fwcurl_global_init();
  FIS_fwDevEeprom_GetMacAddr();
  FIS_fwDevEeprom_Info();
  FIS_fwDevFront_PowerOffCancel();
  FIS_fwDevFront_PowerOffReply();
  FIS_fwDevFront_SetIlluminate();
  FIS_fwDevHdd_DeviceClose();
  FIS_fwDevHdd_DeviceOpen();
  FIS_fwDevService_Mute();
  FIS_fwEeprom_DirectWrite();
  FIS_fwezxml_attr();
  FIS_fwezxml_child();
  FIS_fwezxml_error();
  FIS_fwezxml_free();
  FIS_fwezxml_idx();
  FIS_fwezxml_parse_file();
  FIS_fwezxml_parse_str();
  FIS_fwPowerOff();
  FIS_fwPutDevEvt();
  FIS_fwSetIrCode();
  FIS_vApplState();
  FIS_vAudioTrack();
  FIS_vbookmarkTime();
  FIS_vBootReason();
  FIS_vCheckAutoDecTimerId();
  FIS_vciMenuMode();
  FIS_vciplusMenuMode();
  FIS_vCurTapTask();
  FIS_vDirectSvcNumTimerId();
  FIS_vdupEntry();
  FIS_vEEPROM();
  FIS_vEEPROMPin();
  FIS_vEtcInfo();
  FIS_vExtPartitionInfo();
  FIS_vExtTsFolder();
  FIS_vfavName();
  FIS_vFlash();
  FIS_vFlashBlockAutoDec();
  FIS_vFlashBlockDLNAData();
  FIS_vFlashBlockFavoriteGroup();
  FIS_vFlashBlockGameSaveData();
  FIS_vFlashBlockLanIPConfig();
  FIS_vFlashBlockNetwork();
  FIS_vFlashBlockNetworkUpdateConfig();
  FIS_vFlashBlockOTAInfo();
  FIS_vFlashBlockProviderInfo();
  FIS_vFlashBlockRadioServices();
  FIS_vFlashBlockSatInfo();
  FIS_vFlashBlockServerData();
  FIS_vFlashBlockServiceName();
  FIS_vFlashBlockTimeInfo();
  FIS_vFlashBlockTimer();
  FIS_vFlashBlockTransponderInfo();
  FIS_vFlashBlockTVServices();
  FIS_vGrid();
  FIS_vHddDivxFolder();
  FIS_vhddRecordFile();
  FIS_vHddTapFolder();
  FIS_vHddTsFolder();
  FIS_vIboxTimerId();
  FIS_vIsAllPartitionInvalid();
  FIS_vIsPipActive();
  FIS_vIsPopUpOn();
  FIS_vMACAddress();
  FIS_vnDupTimer();
  FIS_vnExtPartition();
  FIS_vnPipSvcNum();
  FIS_vnRadioSvc();
  FIS_vnTvSvc();
  FIS_vOsdMap();
  FIS_vOsdOutBuf();
  FIS_vParentalInfo();
  FIS_vPhotoAlbumInfo();
  FIS_vPipH();
  FIS_vPipSvcNum();
  FIS_vPipW();
  FIS_vPipX();
  FIS_vPipY();
  FIS_vPvrRecTsInfo();
  FIS_vPvrRecTsPlayInfo();
  FIS_vRECSlotAddress(0);
  FIS_vSelectedPartition();
  FIS_vShoutCastInfo();
  FIS_vShoutCastState();
  FIS_vTapSysOsdCtrl();
  FIS_vTAPTable();
  FIS_vTimerEditInfo();
  FIS_vTimerTempInfo();
  FIS_vTopEvent();
  FIS_vVfdBrightTimerId();
  FIS_vVfdTimerId();
  FixInvalidFileName(NULL);
  FlashADDecode(NULL, NULL);
  FlashADEncode(NULL, NULL);
  FlashADGetInfo(NULL);
  FlashADSetInfo(NULL);
  FlashFavoritesFindService(0, 0);
  FlashFavoritesGetInfo(0, NULL);
  FlashFavoritesGetInfoCurrent(NULL);
  FlashFavoritesGetParameters(NULL, NULL);
  FlashFavoritesGetSelectedGroupName();
  FlashFavoritesGetTotal();
  FlashFavoritesSetInfo(0, NULL);
  FlashProgram();
  FlashSatTablesDecode(NULL, NULL);
  FlashSatTablesGetInfo(0, NULL);
  FlashSatTablesGetTotal();
  FlashServiceAdd(0, NULL);
  FlashServiceDecode(NULL, NULL);
  FlashServiceDel(0, 0);
  FlashServiceEncode(NULL, NULL);
  FlashServiceFind(0, 0, 0, 0, NULL);
  FlashServiceFindNum(0, 0, 0, 0, NULL, NULL);
  FlashServiceGetInfo(0, 0, NULL);
  FlashServiceGetTotal(0);
  FlashServiceMove(0, 0, 0);
  FlashServiceSetInfo(0, 0, NULL);
  FlashTimeDecode(NULL, NULL);
  FlashTimeGetInfo(NULL);
  FlashTimerDecode(NULL, NULL);
  FlashTimerEncode(NULL, NULL);
  FlashTimerGetInfo(0, NULL);
  FlashTimerSetInfo(0, NULL);
  FlashTimerStructSize();
  FlashTransponderFindIndex(0, 0, 0);
  FlashTransponderFindIndex2(0, 0, 0, 0);
  FlashTransponderTablesAdd(0, NULL);
  FlashTransponderTablesDecode(NULL, NULL);
  FlashTransponderTablesDel(0, 0);
  FlashTransponderTablesEncode(NULL, NULL);
  FlashTransponderTablesGetInfo(0, 0, NULL);
  FlashTransponderTablesGetTotal(0);
  FlashTransponderTablesSetInfo(0, 0, NULL);
  FlushCache(NULL, 0);
  FM_AlphaBlend(0, 0, 0, 0);
  FM_AlphaBlendRGB(0, 0, 0, 0);
  FM_CharToIndex(0);
  FM_FreeFontFile(NULL);
  FM_GetStringHeight(NULL, NULL);
  FM_GetStringWidth(NULL, NULL);
  FM_InitAlphaLUT(0, 0, 0);
  FM_isValidCharacter(0);
  FM_LoadFontFile(NULL, NULL);
  FM_MakeFontDir();
  FM_PutString(0, 0, 0, 0, NULL, 0, 0, NULL, 0, 0);
  FM_PutStringAA(0, 0, 0, 0, NULL, 0, 0, NULL, 0, 0, 0);
  FMUC_FindNextUTF8(NULL);
  FMUC_FindUTF8Start(NULL);
  FMUC_FreeFontFile(NULL);
  FMUC_GetGlyphData(NULL, NULL, NULL);
  FMUC_GetStringHeight(NULL, NULL);
  FMUC_GetStringWidth(NULL, NULL);
  FMUC_IsDiacriticalMark(0);
  FMUC_LoadFontFile(NULL, NULL);
  FMUC_PutString(0, 0, 0, 0, NULL, 0, 0, NULL, 0, 0);
  FMUC_PutStringAA(0, 0, 0, 0, NULL, 0, 0, NULL, 0, 0, 0);
  FreeOSDRegion(0);
  GetApplVer();
  GetCurrentEvent(NULL);
  GetCurrentTimeZone(NULL, NULL);
  GetEEPROMAddress();
  GetEEPROMPin();
  GetLine(NULL, FALSE);
  GetMacAddress();
  GetOSDMapAddress();
  GetOSDRegionHeight(0);
  GetOSDRegionWidth(0);
  GetPIPPosition(NULL, NULL, NULL, NULL);
  GetRecExtension();
  GetStreamFormat(0);
  GetStringEncoding(NULL, NULL, NULL);
  GetSysID();
  GetSystemType();
  GetToppyString(0);
  GetUCPos(NULL, 0);
  GetUptime();
  HDD_AAM_Disable();
  HDD_AAM_Enable(0);
  HDD_APM_Disable();
  HDD_APM_Enable(0);
  HDD_ChangeDir(NULL);
  HDD_DecodeRECHeader(NULL, NULL, 0);
  HDD_Delete(NULL);
  HDD_EncodeRECHeader(NULL, NULL, 0);
  HDD_FappendOpen(NULL);
  HDD_FappendWrite(NULL, NULL);
  HDD_FindPCR(NULL, 0, 0);
  HDD_GetAbsolutePathByTypeFile(NULL, NULL);
  HDD_GetFileSizeAndInode(NULL, NULL, NULL, NULL);
  HDD_GetFileTimeByAbsFileName(NULL);
  HDD_GetFileTimeByRelFileName(NULL);
  HDD_GetFileTimeByTypeFile(NULL);
  HDD_GetHddID(NULL, NULL, NULL);
  HDD_GetInodeByAbsFileName(NULL);
  HDD_GetInodeByRelFileName(NULL);
  HDD_GetInodeByTypeFile(NULL);
  HDD_GetPvrRecTsInfoPointer(0);
  HDD_GetRecSlotFiles(0, NULL, NULL, NULL);
  HDD_IdentifyDevice(NULL);
  HDD_isAnyRecording();
  HDD_isCryptedStream(NULL, 0);
  HDD_isExtRecording();
  HDD_isFileInUse(NULL);
  HDD_isRecFileName(NULL);
  HDD_isRecording(0);
  HDD_MakeNewRecName(NULL, 0);
  HDD_Move(NULL, NULL, NULL);
  HDD_NumberOfRECSlots();
  HDD_RecSlotDecode(0, NULL);
  HDD_RecSlotEncode(0, NULL);
  HDD_RECSlotSetDuration(0, 0);
  HDD_Recycle(NULL);
  HDD_RecycleSF(NULL);
  HDD_RemoveDir(NULL, FALSE);
  HDD_Rename(NULL, NULL);
  HDD_SetExtRecording(FALSE);
  HDD_Smart_DisableAttributeAutoSave();
  HDD_Smart_DisableOperations();
  HDD_Smart_EnableAttributeAutoSave();
  HDD_Smart_EnableOperations();
  HDD_Smart_ReadData(NULL);
  HDD_Smart_ReadThresholdData(NULL);
  HDD_Smart_ReturnStatus();
  HDD_TAP_Callback(0, NULL, 0, 0, 0, 0);
  HDD_TAP_Disable(0, FALSE);
  HDD_TAP_DisableAll(FALSE);
  HDD_TAP_DisabledEventHandler(0, 0, 0);
  HDD_TAP_GetCurrentDir(NULL);
  HDD_TAP_GetFileNameByIndex(0, NULL);
  HDD_TAP_GetIDByFileName(NULL);
  HDD_TAP_GetIDByIndex(0);
  HDD_TAP_GetIndexByID(0);
  HDD_TAP_GetInfo(NULL, NULL);
  HDD_TAP_GetInfoByAbsPath(NULL, NULL);
  HDD_TAP_GetStartParameter();
  HDD_TAP_isAnyRunning();
  HDD_TAP_isBatchMode();
  HDD_TAP_isDisabled(0);
  HDD_TAP_isDisabledAll();
  HDD_TAP_isRunning(0);
  HDD_TAP_PopDir();
  HDD_TAP_PushDir();
  HDD_TAP_SendEvent(0, FALSE, 0, 0, 0);
  HDD_TAP_Start(NULL, FALSE, NULL, NULL);
  HDD_TAP_StartedByTAP();
  HDD_TAP_Terminate(0);
  HDD_Unrecycle(NULL);
  HDD_UnrecycleSF(NULL);
  HDD_Write(NULL, 0, NULL);
  HookFirmware(NULL, NULL, NULL);
  infData_CloseFile();
  infData_Delete(NULL, NULL);
  infData_Get(NULL, NULL, NULL, NULL);
  infData_GetNameByIndex(NULL, 0, NULL);
  infData_isAvail(NULL, NULL, NULL);
  infData_LocateSig(NULL, NULL);
  infData_OpenFile(NULL);
  infData_Set(NULL, NULL, 0, NULL);
  infData_Truncate(NULL, 0);
  INICloseFile();
  INIFindStartEnd(NULL, NULL, NULL, 0);
  INIGetARGB(NULL, NULL, NULL, NULL, NULL, 0);
  INIGetARGB8(NULL, NULL, NULL, NULL, NULL, 0);
  INIGetHexByte(NULL, 0, 0, 0);
  INIGetHexDWord(NULL, 0, 0, 0);
  INIGetHexWord(NULL, 0, 0, 0);
  INIGetInt(NULL, 0, 0, 0);
  INIGetRGB(NULL, NULL, NULL, NULL, 0);
  INIGetRGB8(NULL, NULL, NULL, NULL, 0);
  INIGetString(NULL, NULL, NULL, 0);
  INIKeyExists(NULL);
  INIKillKey(NULL);
  INILocateFile(NULL, NULL);
  INIOpenFile(NULL, NULL);
  INISaveFile(NULL, 0, NULL);
  INISetARGB(NULL, 0, 0, 0, 0);
  INISetARGB8(NULL, 0, 0, 0, 0);
  INISetHexByte(NULL, 0);
  INISetHexDWord(NULL, 0);
  INISetHexWord(NULL, 0);
  INISetInt(NULL, 0);
  INISetRGB(NULL, 0, 0, 0);
  INISetRGB8(NULL, 0, 0, 0);
  INISetString(NULL, NULL);
  InitTAPex();
  InitTAPexFailedMsg(NULL);
  InsertAt(NULL, 0, NULL);
  isAnyOSDVisible(0, 0, 0, 0);
  isAnyOSDVisibleEx(0, 0, 0, 0, 0);
  isDirectSvcNumVisible();
  isIceTVToppy();
  isInfoBoxVisible();
  isLegalChar(NULL, 0);
  isMJD(0);
  iso639_1(0);
  iso639_2(0);
  isOSDRegionAlive(0);
  isPIPActive();
  isUTF8Char(NULL, NULL);
  isUTFToppy();
  isValidChannel(0);
  KeyTranslate(FALSE, NULL);
  LangGetString(0);
  LangGetStringDefault(0, NULL);
  LangLoadStrings(NULL, 0, 0, NULL);
  LangUnloadStrings();
  LoadFirmwareDat(NULL, NULL, NULL);
  LocalTime2UTC(0, NULL);
  LogEntry(NULL, NULL, FALSE, 0, NULL);
  LogEntryFBLibPrintf(FALSE, NULL);
  LogEntryGeneric(NULL, FALSE, NULL);
  LogEntryGenericPrintf(NULL, FALSE, NULL);
  LogEntryPrintf(NULL, NULL, FALSE, 0, NULL);
  LogoManager_CalculateChannelID(0, 0, 0, 0);
  LogoManager_ChannelNameToLogoName(NULL);
  LogoManager_Cleanup();
  LogoManager_CleanupMemory();
  LogoManager_GetChannelID(0, 0);
  LogoManager_GetDirectory(0, 0);
  LogoManager_GetLogoByChannel(0, 0, 0, 0, 0);
  LogoManager_GetLogoByChannelID(0, 0, 0, 0);
  LogoManager_GetLogoByChannelName(NULL, 0, 0, 0);
  LogoManager_GetLogoByLogoName(NULL, 0, 0, 0);
  LogoManager_GetPathToLogoByChannelID(0, 0, 0, 0);
  LogoManager_Initialize(NULL);
  LogoManager_LogoCacheLoad();
  LogoManager_LogoCacheRebuild();
  LogoManager_LogosAvailable(0);
  LogoManager_MoveExternalUpdates();
  LogoManager_ProcessLILAdd(NULL);
  LogoManager_UpdateLIL();
  LowerCase(NULL);
  MakeUniqueFileName(NULL);
  MakeValidFileName(NULL, 0);
  MD5File(NULL, NULL);
  MD5String(NULL, NULL);
  NoAutoStartTAP();
  Now(NULL);
  OATH(NULL, 0, 0);
  OSDCalcIndices();
  OSDCopy(0, 0, 0, 0, 0, 0, 0);
  OSDDrawBackground();
  OSDDrawButtons();
  OSDDrawList();
  OSDDrawLogo();
  OSDDrawMemo();
  OSDDrawScrollBar();
  OSDDrawTitle();
  OSDMemoInitialize(FALSE, NULL, NULL, NULL);
  OSDMenuButtonAdd(0, 0, NULL, NULL);
  OSDMenuButtonColor(0);
  OSDMenuButtonsClear();
  OSDMenuColorPickerColor();
  OSDMenuColorPickerDestroy();
  OSDMenuColorPickerIsVisible();
  OSDMenuColorPickerShow(NULL, 0);
  OSDMenuDestroy();
  OSDMenuDestroyNoOSDUpdate();
  OSDMenuDrawCursor(0, 0, 0);
  OSDMenuEvent(NULL, NULL, NULL);
  OSDMenuFindNextSelectableEntry(0);
  OSDMenuFindPreviousSelectableEntry(0);
  OSDMenuFreeStdFonts();
  OSDMenuGetButtonIcon(0);
  OSDMenuGetCurrentItem();
  OSDMenuGetIconPointer(0, NULL);
  OSDMenuGetW(NULL, 0);
  OSDMenuInfoBoxDestroy();
  OSDMenuInfoBoxDestroyNoOSDUpdate();
  OSDMenuInfoBoxIsVisible();
  OSDMenuInfoBoxShow(NULL, NULL, 0);
  OSDMenuInitialize(FALSE, FALSE, FALSE, FALSE, NULL, NULL);
  OSDMenuIsVisible();
  OSDMenuItemAdd(NULL, NULL, NULL, NULL, FALSE, FALSE, 0);
  OSDMenuItemFindName(NULL);
  OSDMenuItemFindValue(NULL);
  OSDMenuItemGetCurrentID();
  OSDMenuItemGetCurrentName();
  OSDMenuItemGetCurrentValue();
  OSDMenuItemGetID(0);
  OSDMenuItemGetName(0);
  OSDMenuItemGetNrOfItems();
  OSDMenuItemGetTopIndex();
  OSDMenuItemGetValue(0);
  OSDMenuItemModifyColorPatch(0, 0);
  OSDMenuItemModifyID(0, 0);
  OSDMenuItemModifyName(0, NULL);
  OSDMenuItemModifyNameIcon(0, NULL);
  OSDMenuItemModifySelectable(0, FALSE);
  OSDMenuItemModifyTextColor(0, 0);
  OSDMenuItemModifyValue(0, NULL);
  OSDMenuItemModifyValueIcon(0, NULL);
  OSDMenuItemModifyValueXPos(0);
  OSDMenuItemsClear();
  OSDMenuItemSortID(FALSE);
  OSDMenuItemSortNameColumn(FALSE, FALSE);
  OSDMenuItemSortValueColumn(FALSE, FALSE);
  OSDMenuKeyboard_CursorEnd();
  OSDMenuKeyboard_CursorLeft();
  OSDMenuKeyboard_CursorRight();
  OSDMenuKeyboard_DeleteLeft();
  OSDMenuKeyboard_DeleteRight();
  OSDMenuKeyboard_Destroy();
  OSDMenuKeyboard_Draw();
  OSDMenuKeyboard_DrawLegendButton(0, 0, NULL);
  OSDMenuKeyboard_EventHandler(NULL, NULL, NULL);
  OSDMenuKeyboard_Finish();
  OSDMenuKeyboard_LegendButton(0, 0, NULL);
  OSDMenuKeyboard_SaveAndFinish();
  OSDMenuKeyboard_Setup(NULL, NULL, 0);
  OSDMenuKeyboard_TMSRemoteDirectMode(FALSE);
  OSDMenuLoadStdFonts();
  OSDMenuLogo(0, 0, NULL);
  OSDMenuMessageBoxButtonAdd(NULL);
  OSDMenuMessageBoxButtonSelect(0);
  OSDMenuMessageBoxDestroy();
  OSDMenuMessageBoxDestroyNoOSDUpdate();
  OSDMenuMessageBoxDoNotEnterNormalMode(FALSE);
  OSDMenuMessageBoxInitialize(NULL, NULL);
  OSDMenuMessageBoxIsVisible();
  OSDMenuMessageBoxLastButton();
  OSDMenuMessageBoxModifyText(NULL);
  OSDMenuMessageBoxShow();
  OSDMenuModifyItemLongTextScrolling(FALSE);
  OSDMenuModifyItemNumbered(FALSE);
  OSDMenuModifyItemValueColumn(FALSE);
  OSDMenuModifyScrollLoop(FALSE);
  OSDMenuModifyTitleLeft(NULL);
  OSDMenuModifyTitleRight(NULL);
  OSDMenuPop();
  OSDMenuProgressBarDestroy();
  OSDMenuProgressBarIsVisible();
  OSDMenuProgressBarShow(NULL, NULL, 0, 0, NULL);
  OSDMenuPush();
  OSDMenuPutS(0, 0, 0, 0, NULL, 0, 0, 0, 0, 0);
  OSDMenuSaveMyRegion(0);
  OSDMenuScrollDown();
  OSDMenuScrollEnd();
  OSDMenuScrollHome();
  OSDMenuScrollPageDown();
  OSDMenuScrollPageUp();
  OSDMenuScrollUp();
  OSDMenuSelectItem(0);
  OSDMenuSelectTopItem(0);
  OSDMenuSetCallback(NULL);
  OSDMenuSetCursor(0);
  OSDMenuSetFont(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
  OSDMenuUpdate(FALSE);
  OSDToBMP(NULL , 0, 0, NULL, 0);
  ParseLine(NULL, NULL, '\0');
  PlayMediaFile(NULL);
  PrintNet(NULL);
  PutDevEvent(0, 0);
  Reboot(FALSE);
  ReplaceInvalidFileNameChars(NULL);
  RTrim(NULL);
  SaveBitmap(NULL, 0, 0, NULL);
  SDS();
  SendHDDCommand(0, NULL, 0);
  SeparateFileNameComponents(NULL, NULL, NULL, NULL, NULL, NULL);
  SeparatePathComponents(NULL, NULL, NULL, NULL);
  SetEEPROMPin(0);
  SetRemoteMode(0, FALSE);
  ShowMessageWin(NULL, NULL, NULL, 0);
  ShowMessageWindow(NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  ShowPvrList(0);
  Shutdown(0);
  SkipCharTableBytes(NULL);
  SoundSinus(0, 0, 0);
  strcpyUC(NULL, NULL);
  stricstr(NULL, NULL);
  StringDBAdd(NULL, NULL);
  StringDBCountRecords(NULL);
  StringDBCurrent(NULL);
  StringDBDel(NULL);
  StringDBDestroy(NULL);
  StringDBEOF(NULL);
  StringDBFirst(NULL);
  StringDBGet(NULL, 0);
  StringDBInit(NULL, 0);
  StringDBLoad(NULL, NULL);
  StringDBLoadFromFile(NULL, NULL);
  StringDBNext(NULL);
  StringDBPrev(NULL);
  StringDBSave(NULL, NULL);
  StringDBSaveToFile(NULL, NULL);
  StringEndsWith(NULL, NULL);
  strlenUC(NULL);
  StrMkISO(NULL);
  StrMkUTF8(NULL, 0);
  strncpyUC(NULL, NULL, 0);
  StrReplace(NULL, NULL, NULL);
  StrToISO(NULL, NULL);
  StrToISOAlloc(NULL, NULL);
  StrToUTF8(NULL, NULL, 0);
  SuperFastHash(NULL, 0, 0);
  SwapDWords(NULL);
  SwapWords(NULL);
  TAP_EnterNormalNoInfo();
  TAP_GetSysOsdControl(0);
  TAP_MemAlloc_Chk(NULL, 0);
  TAP_MemRealloc(NULL, 0, 0, FALSE);
  TAP_Osd_Copy_Chk(NULL, 0, 0, 0, 0, 0, 0, 0, 0, FALSE);
  TAP_Osd_Create_Chk(NULL, 0, 0, 0, 0, 0, 0);
  TAP_Osd_FillBox_Chk(NULL, 0, 0, 0, 0, 0, 0);
  TAP_Osd_PutFreeColorGd(0, 0, 0, NULL, FALSE, 0);
  TAP_Osd_PutFreeColorGd_Chk(NULL, 0, 0, 0, NULL, FALSE, 0);
  TAP_Osd_PutGd_Chk(NULL, 0, 0, 0, NULL, FALSE);
  TAP_Osd_PutPixel_Chk(NULL, 0, 0, 0, 0);
  TAP_Osd_RestoreBox_Chk(NULL, 0, 0, 0, 0, 0, NULL);
  TAP_Osd_SaveBox_Chk(NULL, 0, 0, 0, 0, 0);
  TAPCOM_CloseChannel(0);
  TAPCOM_Finish(0, 0);
  TAPCOM_GetChannel(0, NULL, NULL, NULL, NULL);
  TAPCOM_GetReturnValue(0);
  TAPCOM_GetStatus(0);
  TAPCOM_LastAlive(0);
  TAPCOM_OpenChannel(0, 0, 0, NULL);
  TAPCOM_Reject(0);
  TAPCOM_StillAlive(0);
  TF2UnixTime(0);
  TFDSize(NULL);
  TimeDiff(0, 0);
  TimeFormat(0, 0, 0);
  TryResolve(NULL);
  TunerGet(0);
  TunerSet(0);
  UncompressBlock(NULL, 0, NULL, 0);
  UncompressedFirmwareSize(NULL);
  UncompressedLoaderSize(NULL);
  UncompressedTFDSize(NULL);
  UncompressFirmware(NULL, NULL, NULL);
  UncompressLoader(NULL, NULL, NULL);
  UncompressTFD(NULL, NULL, NULL);
  UnhookFirmware(NULL, NULL, NULL);
  Unix2TFTime(0);
  UpperCase(NULL);
  UTC2LocalTime(0, NULL);
  UTF32ToUTF8(0, NULL, NULL);
  UTF8ToUTF32(NULL, NULL);
  ValidFileName(NULL, 0);
  VFD_CDAnimation(FALSE);
  VFD_Clear();
  VFD_EnableCD(FALSE);
  VFD_EnableCDAnimation(FALSE);
  VFD_EnableHDD(FALSE);
  VFD_GetControl(FALSE);
  VFD_isInUseByTAP();
  VFD_SetCDValue(0);
  VFD_SetCharacterSet(0);
  VFD_SetDisplayDigit(NULL, 0, 0, 0);
  VFD_SetHDDValue(0);
  VFD_SetIcon(0, FALSE);
  VFD_SetLargeText(NULL);
  VFD_SetSmallText(NULL);
  VFD_TranslateSegments(0, 0);
  VFD_Update();
  VideoToBMP(NULL, 0, 0, NULL, 0, 0, 0, 0);
  YUV2RGB(0, 0, 0, NULL, NULL, NULL);
  YUV2RGB2(0, 0, 0, NULL, NULL, NULL);

  return 0;
}
