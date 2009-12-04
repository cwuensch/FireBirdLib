/************************************************/
/* USE ONLY TO TEST LINKING AGAINST libFireBird */
/* CHECKS ALL libFireBird FUNCTIONS             */
/************************************************/

#include "tap.h"
#include "../av/FBLib_av.h"
#include "../dialog/FBLib_dialog.h"
#include "../flash/FBLib_flash.h"
#include "../hdd/FBLib_hdd.h"
#include "../hook/FBLib_hook.h"
#include "../imem/imem.h"
#include "../ini/FBLib_ini.h"
#include "../libFireBird.h"
#include "../main/FBLib_main.h"
#include "../mpvfd/FBLib_mpvfd.h"
#include "../rec/FBLib_rec.h"
#include "../shutdown/FBLib_shutdown.h"
#include "../string/FBLib_string.h"
#include "../tap/FBLib_tap.h"
#include "../tapcom/FBLib_tapcom.h"

TAP_ID(0);
TAP_PROGRAM_NAME("");
TAP_AUTHOR_NAME("");
TAP_DESCRIPTION("");
TAP_ETCINFO(__DATE__);


dword TAP_EventHandler (word event, dword param1, dword param2)
{
  (void) event;
  (void) param2;

  return param1;
}


int TAP_Main (void)
{
  //Generic function (TF5000 and TMS)
  AddSec(0, 0, 0);                                                      //flash, all
  AddTime(0, 0);                                                        //flash, all
  BMP_WriteHeader(NULL, 0, 0);                                          //av, all
  BootReason();                                                         //main, all
  BuildWindowBorder();                                                  //dialog, all
  BuildWindowInfo();                                                    //dialog, all
  BuildWindowLine();                                                    //dialog, all
  BuildWindowLineSelected();                                            //dialog, all
  BuildWindowScrollBar();                                               //dialog, all
  BuildWindowTitle();                                                   //dialog, all
  CalcPrepare();                                                        //dialog, all
  CalcTopIndex(0, 0);                                                   //dialog, all
  CallTraceComment(NULL);                                               //main, all
  CallTraceEnable(FALSE);                                               //main, all
  CallTraceEnter(NULL);                                                 //main, all
  CallTraceExit(NULL);                                                  //main, all
  CallTraceExitResult(NULL, NULL);                                      //main, all
  CallTraceInit();                                                      //main, all
  ChangeDirRoot();                                                      //hdd, all
  CheckSelectable(0, 0);                                                //dialog, all
  compact(NULL, 0);                                                     //imem, all
  CompressBlock(NULL, 0, NULL);                                         //compression, all
  CompressedTFDSize(NULL, 0, NULL);                                     //compression, all
  CompressTFD(NULL, 0, NULL, 0, 0, NULL);                               //compression, all
  CRC16(0, NULL, 0);                                                    //compression, all
  CRC32 (0, NULL, 0);                                                   //compression, all
  Delay(0);                                                             //hdd, all
  DialogEvent(NULL, NULL, NULL);                                        //dialog, all
  DialogMsgBoxButtonAdd(NULL, FALSE);                                   //dialog, all
  DialogMsgBoxExit();                                                   //dialog, all
  DialogMsgBoxInit(NULL, NULL, NULL, NULL);                             //dialog, all
  DialogMsgBoxShow();                                                   //dialog, all
  DialogMsgBoxShowInfo(0);                                              //dialog, all
  DialogMsgBoxShowOK();                                                 //dialog, all
  DialogMsgBoxShowOKCancel(0);                                          //dialog, all
  DialogMsgBoxShowYesNo(0);                                             //dialog, all
  DialogMsgBoxShowYesNoCancel(0);                                       //dialog, all
  DialogMsgBoxTitleSet(NULL, NULL);                                     //dialog, all
  DialogProfileChange(NULL);                                            //dialog, all
  DialogProfileCheck(NULL, NULL);                                       //dialog, all
  DialogProfileLoad(NULL, NULL);                                        //dialog, all
  DialogProfileLoadDefault();                                           //dialog, all
  DialogProfileLoadMy(NULL);                                            //dialog, all
  DialogProfileSave(NULL, 0, NULL);                                     //dialog, all
  DialogProfileSaveDefault();                                           //dialog, all
  DialogProfileScrollBehaviourChange(FALSE, FALSE);                     //dialog, all
  DialogProgressBarExit();                                              //dialog, all
  DialogProgressBarInit(NULL, NULL, 0, 0, NULL, 0, 0);                  //dialog, all
  DialogProgressBarSet(0, 0);                                           //dialog, all
  DialogProgressBarShow();                                              //dialog, all
  DialogProgressBarTitleSet(NULL);                                      //dialog, all
  DialogWindowAlpha(0);                                                 //dialog, all
  DialogWindowChange(NULL, FALSE);                                      //dialog, all
  DialogWindowCursorChange(FALSE);                                      //dialog, all
  DialogWindowCursorSet(0);                                             //dialog, all
  DialogWindowExit();                                                   //dialog, all
  DialogWindowHide();                                                   //dialog, all
  DialogWindowInfoAddIcon(0, 0, NULL);                                  //dialog, all
  DialogWindowInfoAddS(0, 0, 0, NULL, 0, 0, 0, 0, 0);                   //dialog, all
  DialogWindowInfoDeleteAll();                                          //dialog, all
  DialogWindowInit(NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, 0, 0, 0);  //dialog, all
  DialogWindowItemAdd(NULL, 0, NULL, 0, FALSE, FALSE, 0, NULL);         //dialog, all
  DialogWindowItemAddSeparator();                                       //dialog, all
  DialogWindowItemChangeFlags(0, FALSE, FALSE);                         //dialog, all
  DialogWindowItemChangeIcon(0, 0, NULL);                               //dialog, all
  DialogWindowItemChangeParameter(0, NULL, 0);                          //dialog, all
  DialogWindowItemChangeValue(0, NULL, 0);                              //dialog, all
  DialogWindowItemDelete(0);                                            //dialog, all
  DialogWindowItemDeleteAll();                                          //dialog, all
  DialogWindowRefresh();                                                //dialog, all
  DialogWindowReInit(0, 0, 0, 0, 0, 0);                                 //dialog, all
  DialogWindowScrollDown();                                             //dialog, all
  DialogWindowScrollDownPage();                                         //dialog, all
  DialogWindowScrollUp();                                               //dialog, all
  DialogWindowScrollUpPage();                                           //dialog, all
  DialogWindowShow();                                                   //dialog, all
  DialogWindowTabulatorSet(0, 0);                                       //dialog, all
  DialogWindowTitleChange(NULL, NULL, NULL);                            //dialog, all
  DialogWindowTypeChange(0);                                            //dialog, all
  DrawMsgBoxButtons();                                                  //dialog, all
  DrawMsgBoxTitle();                                                    //dialog, all
  DrawOSDLine(0, 0, 0, 0, 0, 0);                                        //av, all
  DrawProgressBarBar(0, 0);                                             //dialog, all
  DrawProgressBarTitle();                                               //dialog, all
  DrawWindowBorder();                                                   //dialog, all
  DrawWindowInfo();                                                     //dialog, all
  DrawWindowLine(0);                                                    //dialog, all
  DrawWindowLines();                                                    //dialog, all
  DrawWindowScrollBar();                                                //dialog, all
  DrawWindowTitle();                                                    //dialog, all
  DumpMemory(NULL, 0, 0);                                               //main, all
  EndMessageWin();                                                      //av, all
  ExtractLine(NULL, NULL);                                              //string, all
  FileSelector(NULL, NULL, NULL, 0);                                    //fs, all
  FileSelectorKey(0, 0);                                                //fs, all
  FIS_vBootReason();                                                    //fis, all
  FIS_vEEPROM();                                                        //fis, all
  FIS_vEEPROMPin();                                                     //fis, all
  FIS_vEtcInfo();                                                       //fis, all
  FIS_vFlash();                                                         //fis, all
  FIS_vOSDMap();                                                        //fis, all
  FIS_vRECSlotAddress(0);                                               //fis, all
  FixInvalidFileName(NULL);                                             //hdd, all
  FlashAddFavourite(NULL, 0, FALSE);                                    //flash, all
  FlashDeleteFavourites();                                              //flash, all
  FlashFindCASServices(FALSE, NULL, NULL);                              //flash, all
  FlashFindEndOfServiceNameTableAddress();                              //flash, all
  FlashFindEndOfServiceTableAddress(0);                                 //flash, all
  FlashFindServiceAddress(0, 0, 0, 0);                                  //flash, all
  FlashFindServiceByLCN(NULL, FALSE, NULL, NULL);                       //flash, all
  FlashFindServiceByName(NULL, FALSE, NULL, NULL);                      //flash, all
  FlashFindServiceByPartOfName(NULL, FALSE, NULL, NULL);                //flash, all
  FlashFindTransponderIndex(0, 0, 0);                                   //flash, all
  FlashGetBlockStartAddress(0);                                         //flash, all
  FlashGetSatelliteByIndex(0);                                          //flash, all
  FlashGetServiceByIndex(0, FALSE);                                     //flash, all
  FlashGetServiceByName (NULL, FALSE);                                  //flash, all
  FlashGetTransponderSByIndex(0, 0);                                    //flash, all
  FlashGetTrueLocalTime(0, 0);                                          //flash, all
  FlashGetType();                                                       //flash, all
  FlashInitialize(0);                                                   //flash, all
  FlashProgram();                                                       //flash, all
  FlashReindexFavourites(0, 0, 0);                                      //flash, all
  FlashReindexTimers(0, 0, 0);                                          //flash, all
  FlashRemoveCASServices(FALSE);                                        //flash, all
  FlashRemoveServiceByIndex(0, FALSE);                                  //flash, all
  FlashRemoveServiceByIndexString(NULL, FALSE);                         //flash, all
  FlashRemoveServiceByLCN(NULL, FALSE);                                 //flash, all
  FlashRemoveServiceByName(NULL, FALSE);                                //flash, all
  FlashRemoveServiceByPartOfName(NULL, FALSE);                          //flash, all
  FlashServiceAddressToServiceIndex(NULL);                              //flash, all
  FlushCache(NULL, 0);                                                  //main, all
  FreeOSDRegion(0);                                                     //av, all
  GetCurrentEvent(NULL);                                                //av, all
  GetEEPROMAddress();                                                   //flash, all
  GetEEPROMPin();                                                       //flash, all
  GetLine(NULL, 0);                                                     //string, all
  GetOSDMapAddress();                                                   //av, all
  GetOSDRegionHeight(0);                                                //av, all
  GetOSDRegionWidth(0);                                                 //av, all
  GetPIPPosition(NULL, NULL, NULL, NULL);                               //av, all
  GetSysID();                                                           //main, all
  GetToppyString(0);                                                    //main, all
  HasEnoughItemMemory();                                                //dialog, all
  HDD_AAM_Disable();                                                    //hdd, all
  HDD_AAM_Enable(0);                                                    //hdd, all
  HDD_APM_Disable();                                                    //hdd, all
  HDD_APM_Enable(0);                                                    //hdd, all
  HDD_ChangeDir(NULL);                                                  //hdd, all
  HDD_Delete(NULL);                                                     //hdd, all
  HDD_FappendOpen(NULL);                                                //hdd, all
  HDD_FappendWrite(NULL, NULL);                                         //hdd, all
  HDD_isFileInUse(NULL);                                                //hdd, all
  HDD_FindPCR(NULL, 0, 0);                                              //rec, all
  HDD_GetHddID(NULL, NULL, NULL);                                       //hdd, all
  HDD_IdentifyDevice(NULL);                                             //hdd, all
  HDD_isAnyRecording();                                                 //rec, all
  HDD_isCryptedStream(NULL, 0);                                         //rec, all
  HDD_isFileInUse(NULL);                                                //hdd
  HDD_isRecording(0);                                                   //rec, all
  HDD_MakeNewRecName(NULL, 0);                                          //rec, all
  HDD_Move(NULL, NULL, NULL);                                           //hdd, all
  HDD_RECSlotGetAddress(0);                                             //rec, all
  HDD_RECSlotSetDuration(0, 0);                                         //rec, all
  HDD_Recycle(NULL);                                                    //hdd, all
  HDD_Rename(NULL, NULL);                                               //hdd, all
  HDD_Smart_DisableAttributeAutoSave();                                 //hdd, all
  HDD_Smart_DisableOperations();                                        //hdd, all
  HDD_Smart_EnableAttributeAutoSave();                                  //hdd, all
  HDD_Smart_EnableOperations();                                         //hdd, all
  HDD_Smart_ReadData(0);                                                //hdd, all
  HDD_Smart_ReadThresholdData(0);                                       //hdd, all
  HDD_Smart_ReturnStatus();                                             //hdd, all
  HDD_TAP_GetCurrentDir(NULL);                                          //tap, all
  HDD_TAP_PopDir();                                                     //tap, all
  HDD_TAP_PushDir();                                                    //tap, all
  HDD_Unrecycle(NULL);                                                  //hdd, all
  HDD_Write(NULL, 0, NULL);                                             //hdd, all
  IMEM_Alloc(0);                                                        //imem, all
  IMEM_Compact();                                                       //imem, all
  IMEM_Free(NULL);                                                      //imem, all
  IMEM_GetInfo(NULL, NULL);                                             //imem, all
  IMEM_Init(0);                                                         //imem, all
  IMEM_isInitialized();                                                 //imem, all
  IMEM_Kill();                                                          //imem, all
  InfoTestGrid();                                                       //dialog, all
  INICloseFile();                                                       //ini, all
  INIFindStartEnd(NULL, NULL, NULL, 0);                                 //ini, all
  INIGetARGB(NULL, NULL, NULL, NULL, NULL, 0);                          //ini, all
  INIGetHexByte(NULL, 0, 0, 0);                                         //ini, all
  INIGetHexDWord(NULL, 0, 0, 0);                                        //ini, all
  INIGetHexWord(NULL, 0, 0, 0);                                         //ini, all
  INIGetInt(NULL, 0, 0, 0);                                             //ini, all
  INIGetRGB(NULL, NULL, NULL, NULL, 0);                                 //ini, all
  INIGetRGB8(NULL, NULL, NULL, NULL, 0);                                //ini, all
  INIGetString(NULL, NULL, NULL, 0);                                    //ini, all
  INIKeyExists(NULL);                                                   //ini, all
  INIKillKey(NULL);                                                     //ini, all
  INILocateFile(NULL, NULL);                                            //ini, all
  INIOpenFile(NULL, NULL);                                              //ini, all
  INISaveFile(NULL, 0, NULL);                                           //ini, all
  INISetARGB(NULL, 0, 0, 0, 0);                                         //ini, all
  INISetComment(NULL);                                                  //ini, all
  INISetHexByte(NULL, 0);                                               //ini, all
  INISetHexDWord(NULL, 0);                                              //ini, all
  INISetHexWord(NULL, 0);                                               //ini, all
  INISetInt(NULL, 0);                                                   //ini, all
  INISetRGB(NULL, 0, 0, 0);                                             //ini, all
  INISetRGB8(NULL, 0, 0, 0);                                            //ini, all
  INISetString(NULL, NULL);                                             //ini, all
  InitTAPex();                                                          //main, all
  InitTAPexFailedMsg(NULL);                                             //main, all
  isLegalChar(0, 0);                                                    //string, all
  iso639_1(0);                                                          //main, all
  LangGetString(0);                                                     //ini, all
  LangLoadStrings(NULL, 0, 0, NULL);                                    //ini, all
  LangUnloadStrings();                                                  //ini, all
  LoadFirmwareDat(NULL, NULL, NULL);                                    //main, all
  LogEntry(NULL, NULL, FALSE, 0, NULL);                                 //main, all
  LowerCase(NULL);                                                      //string, all
  MakeUniqueFileName(NULL);                                             //hdd, all
  MakeValidFileName(NULL, 0);                                           //string, all
  Now(NULL);                                                            //flash, all
  OATH(NULL, 0, 0);                                                     //compression, all
  OSDCopy(0, 0, 0, 0, 0, 0, 0);                                         //av, all
  OSDLinesForeDirty(FALSE);                                             //dialog, all
  ParseLine(NULL, NULL, 0);                                             //string, all
  ProfileDirty();                                                       //dialog, all
  ProfileInit();                                                        //dialog, all
  ProfileLoad(NULL, FALSE, NULL);                                       //dialog, all
  ProfileMayReload();                                                   //dialog, all
  Reboot(0);                                                            //shutdown, all
  RTrim(NULL);                                                          //string, all
  SaveBitmap(NULL, 0, 0, NULL);                                         //av, all
  SeparateFileNameComponents(NULL, NULL, NULL, NULL, NULL, NULL);       //hdd, all
  SeparatePathComponents(NULL, NULL, NULL, NULL);                       //string, all
  SetEEPROMPin(0);                                                      //flash, all
  SetRemoteMode(0, FALSE);                                              //av, all
  ShowMessageWin(NULL, NULL, NULL, 0);                                  //av, all
  ShowMessageWindow(NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0);                   //av, all
  Shutdown(0);                                                          //shutdown, all
  SoundSinus(0, 0, 0);                                                  //av, all
  StringEndsWith(NULL, NULL);                                           //string, all
  stricstr(NULL, NULL);                                                 //string, all
  SuperFastHash(NULL, 0, 0);                                            //compression, all
  SwapDWords(0);                                                        //hdd, all
  SwapWords(0);                                                         //hdd, all
  TAP_Osd_PutFreeColorGd(0, 0, 0, NULL, FALSE, 0);                      //av, all
  TFDSize(NULL);                                                        //compression, all
  TimeDiff(0, 0);                                                       //flash, all
  TimeFormat(0, 0, 0);                                                  //flash, all
  TunerGet(0);                                                          //av, all
  TunerSet(0);                                                          //av, all
  UncompressBlock(NULL, 0, NULL, 0);                                    //compression, all
  UncompressedFirmwareSize(NULL);                                       //compression, all
  UncompressedLoaderSize(NULL);                                         //compression, all
  UncompressedTFDSize(NULL);                                            //compression, all
  UncompressFirmware(NULL, NULL, NULL);                                 //compression, all
  UncompressLoader(NULL, NULL, NULL);                                   //compression, all
  UncompressTFD(NULL, NULL, NULL);                                      //compression, all
  UpperCase(NULL);                                                      //string, all
  ValidFileName(NULL, 0);                                               //string, all
  WindowDirty();                                                        //dialog, all
  YUV2RGB(0, 0, 0, NULL, NULL, NULL);                                   //av, all
  YUV2RGB2(0, 0, 0, NULL, NULL, NULL);                                  //av, all

  //TF5000 only
#ifndef _TMS_
  AddEventHandler(0, NULL, 0, 0);                                       //main, 5k
  busyWait();                                                           //hdd, 5k
  CalcAbsSectorFromFAT(NULL, 0);                                        //hdd, 5k
  Callback(0, NULL, 0, 0, 0, 0);                                        //tap, 5k
  CallbackHelper(NULL, NULL, 0, 0, 0, 0);                               //tap, 5k
  CallBIOS(0, 0, 0, 0, 0);                                              //main, 5k
  CallFirmware(0, 0, 0, 0, 0);                                          //main, 5k
  CaptureScreen(0, 0, 0, NULL, 0, 0);                                   //av, all but different parameters
  DelEventHandler(0, NULL);                                             //main, 5k
  EnqueueEvent(0, 0);                                                   //main, 5k
  exitHook();                                                           //hook, 5k
  FindDBTrack();                                                        //av, 5k
  FindInstructionSequence(NULL, NULL, 0, 0, 0, 0);                      //main, 5k
  findSendToVfdDisplay(0, 0);                                           //mpvfd, 5k
  FIS_fwAddEventHandler();                                              //fis, 5k
  FIS_fwBIOS();                                                         //fis, 5k
  FIS_fwDelEventHandler();                                              //fis, 5k
  FIS_fwDSTCheck();                                                     //fis, 5k
  FIS_fwEnqueueEvent();                                                 //fis, 5k
  FIS_fwEventDispatcher();                                              //fis, 5k
  FIS_fwFlashEraseSector();                                             //fis, 5k
  FIS_fwFlashFindSectorAddressIndex();                                  //fis, 5k
  FIS_fwFlashGetSectorAddress();                                        //fis, 5k
  FIS_fwFWFlashProgram();                                               //fis, 5k
  FIS_fwGetMPVFDDataBuffer();                                           //fis, 5k
  FIS_fwMemMonitor();                                                   //fis, 5k
  FIS_fwMHEGDisable();                                                  //fis, 5k
  FIS_fwMHEGStatus();                                                   //fis, 5k
  FIS_fwMoveOld();                                                      //fis, 5k
  FIS_fwObtainResource();                                               //fis, 5k
  FIS_fwPIC2_ISR18();                                                   //fis, 5k
  FIS_fwReboot();                                                       //fis, 5k
  FIS_fwReleaseResource();                                              //fis, 5k
  FIS_fwSendToFP();                                                     //fis, 5k
  FIS_fwSendToLEDDisplay();                                             //fis, 5k
  FIS_fwSetLEDByMode();                                                 //fis, 5k
  FIS_fwSetPlaybackMode();                                              //fis, 5k
  FIS_fwSetPlaybackSpeed();                                             //fis, 5k
  FIS_fwSetVFDByMode();                                                 //fis, 5k
  FIS_fwShutdownHandler();                                              //fis, 5k
  FIS_fwStopDisplayUpdateTimers();                                      //fis, 5k
  FIS_fwTAPStart();                                                     //fis, 5k
  FIS_fwUpdateMPVFD();                                                  //fis, 5k
  FIS_fwWriteSectors();                                                 //fis, 5k
  FIS_fwWriteSectorsDMA();                                              //fis, 5k
  FIS_GetGP(NULL);                                                      //fis, 5k
  FIS_vEventHandlerMap();                                               //fis, 5k
  FIS_vFlashFWMaxSize();                                                //fis, 5k
  FIS_vFlashFWStartOffset();                                            //fis, 5k
  FIS_vFlashInProgress();                                               //fis, 5k
  FIS_vGMT();                                                           //fis, 5k
  FIS_vHddInfoStructure1();                                             //fis, 5k
  FIS_vHddInfoStructure2();                                             //fis, 5k
  FIS_vHDDLiveFSFAT1();                                                 //fis, 5k
  FIS_vHDDLiveFSRootDir();                                              //fis, 5k
  FIS_vHDDLiveFSSuperblock();                                           //fis, 5k
  FIS_vHDDShutdown();                                                   //fis, 5k
  FIS_vHeapMap();                                                       //fis, 5k
  FIS_vHeapStart();                                                     //fis, 5k
  FIS_vIntVectorTable();                                                //fis, 5k
  FIS_vKeyMap();                                                        //fis, 5k
  FIS_vLEDDisplayBuffer();                                              //fis, 5k
  FIS_vMPEGHeader();                                                    //fis, 5k
  FIS_vMPVFD();                                                         //fis, 5k
  FIS_vMPVFDBackup();                                                   //fis, 5k
  FIS_vPinStatus();                                                     //fis, 5k
  FIS_vPlaybackPaused();                                                //fis, 5k
  FIS_vPlaySlot();                                                      //fis, 5k
  FIS_vRecFile(0);                                                      //fis, 5k
  FIS_vSuppressedAutoStart();                                           //fis, 5k
  FIS_vSysOsdControl();                                                 //fis, 5k
  FIS_vTAP_Vfd_Control();                                               //fis, 5k
  FIS_vTAP_Vfd_Status();                                                //fis, 5k
  FIS_vTAPTable();                                                      //fis, 5k
  FIS_vTaskAddressTable();                                              //fis, 5k
  FIS_vVolume();                                                        //fis, 5k
  FIS_vWD1();                                                           //fis, 5k
  FlashFindServiceByUHF(NULL, FALSE, FALSE, NULL, NULL);                //flash, 5k
  FlashGetChannelNumber(0, 0, 0, 0);                                    //flash, 5k
  FlashGetTransponderCByIndex(0);                                       //flash, 5k
  FlashGetTransponderTByIndex(0);                                       //flash, 5k
  FlashRemoveServiceByUHF(NULL, FALSE, FALSE);                          //flash, 5k
  FlashWrite(NULL, NULL, 0, NULL);                                      //flash, 5k
  fwHook(0);                                                            //mpvfd, 5k
  GetAudioTrackPID(0, NULL);                                            //av, 5k
  GetClusterPointer(0);                                                 //hdd, 5k
  GetFrameBufferPixel(0, 0);                                            //av, 5k
  GetFrameSize(0, 0);                                                   //av, 5k
  GetFWInfo(0, 0, 0, 0, 0, 0, 0, 0);                                    //main, 5k
  GetHeapParameter(NULL, 0);                                            //main, 5k
  GetPinStatus();                                                       //av, 5k
  GetSysOsdControl(0);                                                  //av, 5k
  HDD_BigFile_Read(NULL, 0, 0, NULL);                                   //hdd, 5k
  HDD_BigFile_Size(NULL);                                               //hdd, 5k
  HDD_BigFile_Write(NULL, 0, 0, NULL);                                  //hdd, 5k
  HDD_DecodeRECHeader(NULL, NULL);                                      //rec, 5k
  HDD_EncodeRECHeader(NULL, NULL, 0);                                   //rec, 5k
  HDD_FindPMT(NULL, 0, NULL);                                           //rec, 5k
  HDD_FreeSize();                                                       //hdd, 5k
  HDD_GetClusterSize();                                                 //hdd, 5k
  HDD_GetFileDir(NULL, 0, NULL);                                        //hdd, 5k
  HDD_GetFirmwareDirCluster();                                          //hdd, 5k
  HDD_GetHDDInfo(NULL);                                                 //hdd, 5k
  HDD_LiveFS_GetChainLength(0);                                         //hdd, 5k
  HDD_LiveFS_GetFAT1Address();                                          //hdd, 5k
  HDD_LiveFS_GetFAT2Address();                                          //hdd, 5k
  HDD_LiveFS_GetFirstCluster(0);                                        //hdd, 5k
  HDD_LiveFS_GetLastCluster(0);                                         //hdd, 5k
  HDD_LiveFS_GetNextCluster(0);                                         //hdd, 5k
  HDD_LiveFS_GetPreviousCluster(0);                                     //hdd, 5k
  HDD_LiveFS_GetRootDirAddress();                                       //hdd, 5k
  HDD_LiveFS_GetSuperBlockAddress();                                    //hdd, 5k
  HDD_PausePlayback(FALSE);                                             //rec, 5k
  HDD_PlaySlotGetAddress();                                             //rec, 5k
  HDD_ReadClusterDMA(0, NULL);                                          //hdd, 5k
  HDD_ReadSector(0, 0);                                                 //hdd, 5k
  HDD_ReadSectorDMA(0, 0, NULL);                                        //hdd, 5k
  HDD_RecalcPlaytime(NULL, NULL);                                       //rec, 5k
  HDD_SetCryptFlag(NULL, 0);                                            //hdd, 5k
  HDD_SetFileDateTime(NULL, 0, 0, 0);                                   //hdd, 5k
  HDD_SetSkipFlag (NULL, FALSE);                                        //hdd, 5k
  HDD_SetStandbyTimer(0);                                               //hdd, 5k
  HDD_RECSlotIsPaused(0);                                               //rec, 5k
  HDD_RECSlotPause(0, FALSE);                                           //rec, 5k
  HDD_Smart_ExecuteOfflineImmediate(0);                                 //hdd, 5k
  HDD_Stop();                                                           //hdd, 5k
  HDD_TAP_Callback(0, NULL, 0, 0, 0, 0);                                //tap, 5k
  HDD_TAP_Disable(0, 0);                                                //tap, 5k
  HDD_TAP_DisableAll(0);                                                //tap, 5k
  HDD_TAP_DisabledEventHandler(0, 0, 0);                                //tap, 5k
  HDD_TAP_GetCurrentDirCluster();                                       //tap, 5k
  HDD_TAP_GetIDByFileName(NULL);                                        //tap, 5k
  HDD_TAP_GetIDByIndex(0);                                              //tap, 5k
  HDD_TAP_GetIndexByID(0);                                              //tap, 5k
  HDD_TAP_GetInfo(0, NULL);                                             //tap, 5k
  HDD_TAP_GetStartParameter();                                          //tap, 5k
  HDD_TAP_isAnyRunning();                                               //tap, 5k
  HDD_TAP_isBatchMode();                                                //tap, 5k
  HDD_TAP_isDisabled(0);                                                //tap, 5k
  HDD_TAP_isDisabledAll();                                              //tap, 5k
  HDD_TAP_isRunning(0);                                                 //tap, 5k
  HDD_TAP_SendEvent(0, FALSE, 0, 0, 0);                                 //tap, 5k
  HDD_TAP_SetCurrentDirCluster(0);                                      //tap, 5k
  HDD_TAP_Start(NULL, FALSE, NULL, NULL);                               //tap, all
  HDD_TAP_StartedByTAP();                                               //tap, 5k
  HDD_TAP_Terminate(0);                                                 //tap, 5k
  HDD_TouchFile(NULL);                                                  //hdd, 5k
  HDD_TranslateDirCluster(0, NULL);                                     //hdd, 5k
  HDD_TruncateFile(NULL, 0);                                            //hdd, 5k
  HDD_WriteClusterDMA(0, NULL);                                         //hdd, 5k
  HDD_WriteSectorDMA(0, 0, NULL);                                       //hdd, 5k
  HookEnable(0, 0);                                                     //hook, 5k
  HookExit();                                                           //hook, 5k
  HookIsEnabled(0);                                                     //hook, 5k
  HookMIPS_Clear(0, 0, 0);                                              //hook, 5k
  HookMIPS_Set(0, 0, 0);                                                //hook, 5k
  HookSet(0, 0);                                                        //hook, 5k
  IdentifyFirmware (NULL, NULL, NULL, NULL, NULL , NULL);               //main, 5k
  initCodeWrapper(0);                                                   //mpvfd, 5k
  InitTAPAPIFix();                                                      //tapapifix, 5k
  InteractiveGetStatus();                                               //av, 5k
  InteractiveSetStatus(FALSE);                                          //av, 5k
  intLock();                                                            //main, 5k
  intUnlock(0);                                                         //main, 5k
  isAnyOSDVisible(0, 0, 0, 0);                                          //av, 5k
  isMasterpiece();                                                      //main, 5k
  isMPMenu();                                                           //av, 5k
  isOSDRegionAlive(0);                                                  //av, 5k
  isValidChannel(NULL);                                                 //tapcom, 5k
  MHEG_Status();                                                        //av, 5k
  MPDisplayClearDisplay();                                              //mpvfd, 5k
  MPDisplayClearSegments(0, 0);                                         //mpvfd, 5k
  MPDisplayDisplayLongString(NULL);                                     //mpvfd, 5k
  MPDisplayDisplayShortString(NULL);                                    //mpvfd, 5k
  MPDisplayGetDisplayByte(0);                                           //mpvfd, 5k
  MPDisplayGetDisplayMask(0);                                           //mpvfd, 5k
  MPDisplayInstallMPDisplayFwHook();                                    //mpvfd, 5k
  MPDisplaySetAmFlag(0);                                                //mpvfd, 5k
  MPDisplaySetColonFlag(0);                                             //mpvfd, 5k
  MPDisplaySetDisplayByte(0, 0);                                        //mpvfd, 5k
  MPDisplaySetDisplayMask(0, 0);                                        //mpvfd, 5k
  MPDisplaySetDisplayMemory(NULL);                                      //mpvfd, 5k
  MPDisplaySetDisplayMode(0);                                           //mpvfd, 5k
  MPDisplaySetPmFlag(0);                                                //mpvfd, 5k
  MPDisplaySetSegments(0, 0);                                           //mpvfd, 5k
  MPDisplayToggleSegments(0, 0);                                        //mpvfd, 5k
  MPDisplayUninstallMPDisplayFwHook();                                  //mpvfd, 5k
  MPDisplayUpdateDisplay();                                             //mpvfd, 5k
  PatchApply (NULL, NULL, NULL, FALSE);                                 //fwpatches, 5k
  PatchCleanList (NULL);                                                //fwpatches, 5k
  PatchFindType (NULL, 0, NULL, NULL);                                  //fwpatches, 5k
  PatchGetInstalled (NULL);                                             //fwpatches, 5k
  PatchInstallID (NULL, NULL);                                          //fwpatches, 5k
  PatchInstructionSequence (0, NULL, NULL);                             //main, 5k
  PatchIsInstalled (NULL, NULL);                                        //fwpatches, 5k
  PatchLoadModule (NULL);                                               //fwpatches, 5k
  PatchLoadModuleGP (NULL, 0);                                          //fwpatches, 5k
  PatchReinstallList (NULL);                                            //fwpatches, 5k
  PatchRemoveID (NULL, NULL);                                           //fwpatches, 5k
  PatchUnloadModule (NULL);                                             //fwpatches, 5k
  ReadEEPROM(0, 0, NULL);                                               //iic, 5k
  ReadIICRegister(0, 0, 0, 0, NULL);                                    //iic, 5k
  ReceiveSector(0);                                                     //hdd, 5k
  SendEvent(0, 0, 0, 0);                                                //tap, 5k
  SendEventHelper(NULL, 0, 0, 0);                                       //tap, 5k
  SendToFP(NULL);                                                       //main, 5k
  SetCrashBehaviour(0);                                                 //main, 5k
  setSymbol14(0, 0);                                                    //mpvfd, 5k
  setSymbol17(0, 0);                                                    //mpvfd, 5k
  SubtitleGetStatus();                                                  //av, 5k
  SubtitleSetStatus(FALSE);                                             //av, 5k
  SuppressedAutoStart();                                                //main, 5k
  TAPCOM_CloseChannel(NULL);                                            //tapcom, 5k
  TAPCOM_Finish(NULL, 0);                                               //tapcom, 5k
  TAPCOM_GetChannel(0, NULL, NULL, NULL, NULL);                         //tapcom, 5k
  TAPCOM_GetReturnValue(NULL);                                          //tapcom, 5k
  TAPCOM_GetStatus(NULL);                                               //tapcom, 5k
  TAPCOM_LastAlive(NULL);                                               //tapcom, 5k
  TAPCOM_OpenChannel(0, 0, 0, NULL);                                    //tapcom, 5k
  TAPCOM_Reject(NULL);                                                  //tapcom, 5k
  TAPCOM_StillAlive(NULL);                                              //tapcom, 5k
  WriteIICRegister(0, 0, 0, 0, NULL);                                   //iic, 5k
#endif

  //TMS only
#ifdef _TMS_
  CaptureScreen(0, 0, NULL, 0, 0);                                      //av, all but different parameters
  FIS_fwApplVfdStart();                                                 //fis, tms
  FIS_fwApplVfdStop();                                                  //fis, tms
  FIS_fwPowerOff();                                                     //fis, tms
  FIS_fwSetIrCode();                                                    //fis, tms
  FIS_vgrid();                                                          //fis, tms
  FIS_vMACAddress();                                                    //fis, tms
  GetMacAddress();                                                      //main, tms
  HDD_GetAbsolutePathByTypeFile(NULL, NULL);                            //hdd, tms
  HDD_GetInodeByAbsFileName(NULL);                                      //hdd, tms
  HDD_GetInodeByRelFileName(NULL);                                      //hdd, tms
  HDD_GetInodeByTypeFile(NULL);                                         //hdd, tms
  HDD_TAP_Start(NULL, FALSE,  NULL);                                    //tap, all
  PrintNet(NULL);                                                       //main, tms
  TryResolve(NULL);                                                     //fis, tms
  VFD_EnableCD(FALSE);                                                  //tmsvfd, tms
  VFD_EnableHDD(FALSE);                                                 //tmsvfd, tms
  VFD_SetCDValue(0);                                                    //tmsvfd, tms
  VFD_SetHDDValue(0);                                                   //tmsvfd, tms
#endif

  return 0;
}
