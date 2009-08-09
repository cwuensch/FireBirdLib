#include "tap.h"

#ifndef _TMS_

//TTSD
volatile dword *EMMA_TTSD_CNT                            = (dword *) 0xb000a000;
volatile dword *EMMA_TTSD_CHA_CNT                        = (dword *) 0xb000a004;
volatile dword *EMMA_TTSD_CHB_CNT                        = (dword *) 0xb000a008;
volatile dword *EMMA_TTSD_CHC_CNT                        = (dword *) 0xb000a00c;
volatile dword *EMMA_TTSD_HSD_CNT                        = (dword *) 0xb000a010;
volatile dword *EMMA_TTSD_HSD_MODE                       = (dword *) 0xb000a014;
volatile dword *EMMA_TTSD_ADAPTATION_SYNC_MODE           = (dword *) 0xb000a018;
volatile dword *EMMA_TTSD_CPU_STREAM_INPUT_PORT          = (dword *) 0xb000a01c;
volatile dword *EMMA_TTSD_1ST_PCR_PID                    = (dword *) 0xb000a030;
volatile dword *EMMA_TTSD_2ND_PCR_PID                    = (dword *) 0xb000a034;
volatile dword *EMMA_TTSD_PID_0                          = (dword *) 0xb000a038;
volatile dword *EMMA_TTSD_PID_1                          = (dword *) 0xb000a03c;
volatile dword *EMMA_TTSD_PID_2                          = (dword *) 0xb000a040;
volatile dword *EMMA_TTSD_PID_3                          = (dword *) 0xb000a044;
volatile dword *EMMA_TTSD_PID_4                          = (dword *) 0xb000a048;
volatile dword *EMMA_TTSD_PID_5                          = (dword *) 0xb000a04c;
volatile dword *EMMA_TTSD_PID_6                          = (dword *) 0xb000a050;
volatile dword *EMMA_TTSD_PID_7                          = (dword *) 0xb000a054;
volatile dword *EMMA_TTSD_PID_8                          = (dword *) 0xb000a058;
volatile dword *EMMA_TTSD_PID_9                          = (dword *) 0xb000a05c;
volatile dword *EMMA_TTSD_PID_10                         = (dword *) 0xb000a060;
volatile dword *EMMA_TTSD_PID_11                         = (dword *) 0xb000a064;
volatile dword *EMMA_TTSD_PID_12                         = (dword *) 0xb000a068;
volatile dword *EMMA_TTSD_PID_13                         = (dword *) 0xb000a06c;
volatile dword *EMMA_TTSD_PID_14                         = (dword *) 0xb000a070;
volatile dword *EMMA_TTSD_PID_15                         = (dword *) 0xb000a074;
volatile dword *EMMA_TTSD_PID_16                         = (dword *) 0xb000a078;
volatile dword *EMMA_TTSD_PID_17                         = (dword *) 0xb000a07c;
volatile dword *EMMA_TTSD_PID_18                         = (dword *) 0xb000a080;
volatile dword *EMMA_TTSD_PID_19                         = (dword *) 0xb000a084;
volatile dword *EMMA_TTSD_PID_20                         = (dword *) 0xb000a088;
volatile dword *EMMA_TTSD_PID_21                         = (dword *) 0xb000a08c;
volatile dword *EMMA_TTSD_PID_22                         = (dword *) 0xb000a090;
volatile dword *EMMA_TTSD_PID_23                         = (dword *) 0xb000a094;
volatile dword *EMMA_TTSD_PID_24                         = (dword *) 0xb000a098;
volatile dword *EMMA_TTSD_PID_25                         = (dword *) 0xb000a09c;
volatile dword *EMMA_TTSD_PID_26                         = (dword *) 0xb000a0a0;
volatile dword *EMMA_TTSD_PID_27                         = (dword *) 0xb000a0a4;
volatile dword *EMMA_TTSD_PID_28                         = (dword *) 0xb000a0a8;
volatile dword *EMMA_TTSD_PID_29                         = (dword *) 0xb000a0ac;
volatile dword *EMMA_TTSD_PID_30                         = (dword *) 0xb000a0b0;
volatile dword *EMMA_TTSD_PID_31                         = (dword *) 0xb000a0b4;
volatile dword *EMMA_TTSD_PID_32                         = (dword *) 0xb000a0b8;
volatile dword *EMMA_TTSD_PID_33                         = (dword *) 0xb000a0bc;
volatile dword *EMMA_TTSD_PID_34                         = (dword *) 0xb000a0c0;
volatile dword *EMMA_TTSD_PID_35                         = (dword *) 0xb000a0c4;
volatile dword *EMMA_TTSD_PID_36                         = (dword *) 0xb000a0c8;
volatile dword *EMMA_TTSD_PID_37                         = (dword *) 0xb000a0cc;
volatile dword *EMMA_TTSD_PID_38                         = (dword *) 0xb000a0d0;
volatile dword *EMMA_TTSD_PID_39                         = (dword *) 0xb000a0d4;
volatile dword *EMMA_TTSD_PID_40                         = (dword *) 0xb000a0d8;
volatile dword *EMMA_TTSD_PID_41                         = (dword *) 0xb000a0dc;
volatile dword *EMMA_TTSD_PID_42                         = (dword *) 0xb000a0e0;
volatile dword *EMMA_TTSD_PID_43                         = (dword *) 0xb000a0e4;
volatile dword *EMMA_TTSD_PID_44                         = (dword *) 0xb000a0e8;
volatile dword *EMMA_TTSD_PID_45                         = (dword *) 0xb000a0ec;
volatile dword *EMMA_TTSD_PID_46                         = (dword *) 0xb000a0f0;
volatile dword *EMMA_TTSD_PID_47                         = (dword *) 0xb000a0f4;
volatile dword *EMMA_TTSD_1ST_VIDEO_PID                  = (dword *) 0xb000a0f8;
volatile dword *EMMA_TTSD_2ND_VIDEO_PID                  = (dword *) 0xb000a0fc;
volatile dword *EMMA_TTSD_1ST_AUDIO_PID                  = (dword *) 0xb000a100;
volatile dword *EMMA_TTSD_2ND_AUDIO_PID                  = (dword *) 0xb000a104;
volatile dword *EMMA_TTSD_AV_PID_CNT                     = (dword *) 0xb000a108;
volatile dword *EMMA_TTSD_CWP_CNT                        = (dword *) 0xb000a118;
volatile dword *EMMA_TTSD_CWP_STORAGE_MODE               = (dword *) 0xb000a11c;
volatile dword *EMMA_TTSD_CWP_STORAGE_LOCK               = (dword *) 0xb000a120;
volatile dword *EMMA_TTSD_SYNC_STATUS                    = (dword *) 0xb000a124;
volatile dword *EMMA_TTSD_PWM_DATA                       = (dword *) 0xb000a128;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT1           = (dword *) 0xb000a130;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT2           = (dword *) 0xb000a134;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT3           = (dword *) 0xb000a138;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT4           = (dword *) 0xb000a13c;
volatile dword *EMMA_TTSD_PID_ERROR_INTERRUPT1           = (dword *) 0xb000a140;
volatile dword *EMMA_TTSD_PID_ERROR_INTERRUPT2           = (dword *) 0xb000a144;
volatile dword *EMMA_TTSD_PID_ERROR_INTERRUPT3           = (dword *) 0xb000a148;
volatile dword *EMMA_TTSD_PID_ERROR_INTERRUPT4           = (dword *) 0xb000a14c;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT1      = (dword *) 0xb000a150;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT2      = (dword *) 0xb000a154;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT3      = (dword *) 0xb000a158;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT1         = (dword *) 0xb000a15c;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT2         = (dword *) 0xb000a160;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT3         = (dword *) 0xb000a164;
volatile dword *EMMA_TTSD_OTHER_INTERRUPT1               = (dword *) 0xb000a168;
volatile dword *EMMA_TTSD_OTHER_INTERRUPT2               = (dword *) 0xb000a16c;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK1      = (dword *) 0xb000a170;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK2      = (dword *) 0xb000a174;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK3      = (dword *) 0xb000a178;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK4      = (dword *) 0xb000a17c;
volatile dword *EMMA_TTSD_PID_ERROR_MASK1                = (dword *) 0xb000a180;
volatile dword *EMMA_TTSD_PID_ERROR_MASK2                = (dword *) 0xb000a184;
volatile dword *EMMA_TTSD_PID_ERROR_MASK3                = (dword *) 0xb000a188;
volatile dword *EMMA_TTSD_PID_ERROR_MASK4                = (dword *) 0xb000a18c;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK1 = (dword *) 0xb000a190;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK2 = (dword *) 0xb000a194;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK3 = (dword *) 0xb000a198;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK1    = (dword *) 0xb000a19c;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK2    = (dword *) 0xb000a1a0;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK3    = (dword *) 0xb000a1a4;
volatile dword *EMMA_TTSD_OTHER_INTERRUPT_MASK1          = (dword *) 0xb000a1a8;
volatile dword *EMMA_TTSD_OTHER_INTERRUPT_MASK2          = (dword *) 0xb000a1ac;
volatile dword *EMMA_TTSD_SECF_MOD                       = (dword *) 0xb000a1c0;
volatile dword *EMMA_TTSD_PID_STOP1                      = (dword *) 0xb000a1c4;
volatile dword *EMMA_TTSD_PID_STOP2                      = (dword *) 0xb000a1c8;
volatile dword *EMMA_TTSD_APG_HEADER_ERROR_DETECT_MODE   = (dword *) 0xb000a1cc;
volatile dword *EMMA_TTSD_APG_CHECK                      = (dword *) 0xb000a1d0;
volatile dword *EMMA_TTSD_SECF_CNT                       = (dword *) 0xb000a1d4;
volatile dword *EMMA_TTSD_SECF_DAT                       = (dword *) 0xb000a1d8;
volatile dword *EMMA_TTSD_GPF_STARTBIT                   = (dword *) 0xb000a1dc;
volatile dword *EMMA_TTSD_SEC_NOTEQ_CNT0                 = (dword *) 0xb000a1e0;
volatile dword *EMMA_TTSD_SEC_NOTEQ_CNT1                 = (dword *) 0xb000a1e4;
volatile dword *EMMA_TTSD_SEC_NOTEQ_CNT2                 = (dword *) 0xb000a1e8;
volatile dword *EMMA_TTSD_SEC_NOTEQ_CNT3                 = (dword *) 0xb000a1ec;
volatile dword *EMMA_TTSD_TS_HEADER0                     = (dword *) 0xb000a1f0;
volatile dword *EMMA_TTSD_TS_HEADER1                     = (dword *) 0xb000a1f4;
volatile dword *EMMA_TTSD_TS_HEADER2                     = (dword *) 0xb000a1f8;
volatile dword *EMMA_TTSD_TS_HEADER3                     = (dword *) 0xb000a1fc;
volatile dword *EMMA_TTSD_PESF_MODE                      = (dword *) 0xb000a200;
volatile dword *EMMA_TTSD_PESF_CNT                       = (dword *) 0xb000a204;
volatile dword *EMMA_TTSD_PESF_DAT                       = (dword *) 0xb000a208;
volatile dword *EMMA_TTSD_PTS_DTS_MSB                    = (dword *) 0xb000a20c;
volatile dword *EMMA_TTSD_PS_PTS_CNT                     = (dword *) 0xb000a220;
volatile dword *EMMA_TTSD_PS_PTSL                        = (dword *) 0xb000a224;
volatile dword *EMMA_TTSD_PS_PTSH                        = (dword *) 0xb000a228;
volatile dword *EMMA_TTSD_PS_PTS_ADR                     = (dword *) 0xb000a22c;
volatile dword *EMMA_TTSD_INTERNAL_STC_MATCH             = (dword *) 0xb000a240;
volatile dword *EMMA_TTSD_1ST_PCR_CNT                    = (dword *) 0xb000a244;
volatile dword *EMMA_TTSD_1ST_PCR1                       = (dword *) 0xb000a248;
volatile dword *EMMA_TTSD_1ST_PCR2                       = (dword *) 0xb000a24c;
volatile dword *EMMA_TTSD_1ST_STC1                       = (dword *) 0xb000a250;
volatile dword *EMMA_TTSD_1ST_STC2                       = (dword *) 0xb000a254;
volatile dword *EMMA_TTSD_LATCHED_1ST_STC1               = (dword *) 0xb000a258;
volatile dword *EMMA_TTSD_LATCHED_1ST_STC2               = (dword *) 0xb000a25c;
volatile dword *EMMA_TTSD_2ND_PCR_CNT                    = (dword *) 0xb000a260;
volatile dword *EMMA_TTSD_2ND_PCR1                       = (dword *) 0xb000a264;
volatile dword *EMMA_TTSD_2ND_PCR2                       = (dword *) 0xb000a268;
volatile dword *EMMA_TTSD_2ND_STC1                       = (dword *) 0xb000a26c;
volatile dword *EMMA_TTSD_2ND_STC2                       = (dword *) 0xb000a270;
volatile dword *EMMA_TTSD_ELEMENTARY_SEARCH_CNT          = (dword *) 0xb000a280;
volatile dword *EMMA_TTSD_MATCH_CODEA                    = (dword *) 0xb000a284;
volatile dword *EMMA_TTSD_MATCH_CODEB                    = (dword *) 0xb000a288;
volatile dword *EMMA_TTSD_CODE1_ADDRESS_VBV1             = (dword *) 0xb000a28c;
volatile dword *EMMA_TTSD_CODE2_ADDRESS_VBV1             = (dword *) 0xb000a290;
volatile dword *EMMA_TTSD_CODE3_ADDRESS_VBV1             = (dword *) 0xb000a294;
volatile dword *EMMA_TTSD_CODE4_ADDRESS_VBV1             = (dword *) 0xb000a298;
volatile dword *EMMA_TTSD_CODE5_ADDRESS_VBV1             = (dword *) 0xb000a29c;
volatile dword *EMMA_TTSD_CODE6_ADDRESS_VBV1             = (dword *) 0xb000a2a0;
volatile dword *EMMA_TTSD_CODE1_ADDRESS_VBV2             = (dword *) 0xb000a2a4;
volatile dword *EMMA_TTSD_CODE2_ADDRESS_VBV2             = (dword *) 0xb000a2a8;
volatile dword *EMMA_TTSD_CODE3_ADDRESS_VBV2             = (dword *) 0xb000a2ac;
volatile dword *EMMA_TTSD_CODE4_ADDRESS_VBV2             = (dword *) 0xb000a2b0;
volatile dword *EMMA_TTSD_CODE5_ADDRESS_VBV2             = (dword *) 0xb000a2b4;
volatile dword *EMMA_TTSD_CODE6_ADDRESS_VBV2             = (dword *) 0xb000a2b8;
volatile dword *EMMA_TTSD_PICTURE_CODE_TYPE_VBV1         = (dword *) 0xb000a2bc;
volatile dword *EMMA_TTSD_PICTURE_CODE_TYPE_VBV2         = (dword *) 0xb000a2c0;
volatile dword *EMMA_TTSD_PICTURE_STRUCTURE_VBV12        = (dword *) 0xb000a2c4;
volatile  word *EMMA_TTSD_VPID_PTSDTS_CNT                = ( word *) 0xb000a340;
volatile  byte *EMMA_TTSD_b000a342                       = ( byte *) 0xb000a342;
volatile  byte *EMMA_TTSD_b000a343                       = ( byte *) 0xb000a343;
volatile dword *EMMA_TTSD_VPID_PTSDTS_STATUS             = (dword *) 0xb000a344;
volatile dword *EMMA_TTSD_PTS_1STVPIDL                   = (dword *) 0xb000a348;
volatile dword *EMMA_TTSD_PTS_1STVPIDH                   = (dword *) 0xb000a34c;
volatile dword *EMMA_TTSD_DTS_1STVPIDL                   = (dword *) 0xb000a350;
volatile dword *EMMA_TTSD_DTS_1STVPIDH                   = (dword *) 0xb000a354;
volatile dword *EMMA_TTSD_1STVPID_PTSDTS_ADDRESS         = (dword *) 0xb000a358;
volatile dword *EMMA_TTSD_PTS_2NDVPIDL                   = (dword *) 0xb000a35c;
volatile dword *EMMA_TTSD_PTS_2NDVPIDH                   = (dword *) 0xb000a360;
volatile dword *EMMA_TTSD_DTS_2NDVPIDL                   = (dword *) 0xb000a364;
volatile dword *EMMA_TTSD_DTS_2NDVPIDH                   = (dword *) 0xb000a368;
volatile dword *EMMA_TTSD_2NDVPID_PTSDTS_ADDRESS         = (dword *) 0xb000a36c;
volatile dword *EMMA_TTSD_VPID_TRICK                     = (dword *) 0xb000a370;
volatile dword *EMMA_TTSD_ELEMENTARY_INTERRUPT           = (dword *) 0xb000a374;
volatile dword *EMMA_TTSD_ELEMENTARY_INTERRUPT_MASK      = (dword *) 0xb000a378;
volatile dword *EMMA_TTSD_TIMER                          = (dword *) 0xb000a390;
volatile dword *EMMA_TTSD_TIMER_CNT                      = (dword *) 0xb000a394;
volatile dword *EMMA_TTSD_MIF_CNT                        = (dword *) 0xb000a3a0;
volatile dword *EMMA_TTSD_POINTER_BASE                   = (dword *) 0xb000a3a4;
volatile dword *EMMA_TTSD_SR_CMD                         = (dword *) 0xb000a400;
volatile dword *EMMA_TTSD_SR_PKT_CNT                     = (dword *) 0xb000a404;
volatile dword *EMMA_TTSD_SR_PID_0                       = (dword *) 0xb000a408;
volatile dword *EMMA_TTSD_SR_PID_1                       = (dword *) 0xb000a40c;
volatile dword *EMMA_TTSD_SR_PID_2                       = (dword *) 0xb000a410;
volatile dword *EMMA_TTSD_SR_PID_3                       = (dword *) 0xb000a414;
volatile dword *EMMA_TTSD_SR_PID_4                       = (dword *) 0xb000a418;
volatile dword *EMMA_TTSD_SR_PID_5                       = (dword *) 0xb000a41c;
volatile dword *EMMA_TTSD_SR_PID_6                       = (dword *) 0xb000a420;
volatile dword *EMMA_TTSD_SR_PID_7                       = (dword *) 0xb000a424;
volatile dword *EMMA_TTSD_SR_PID_8                       = (dword *) 0xb000a428;
volatile dword *EMMA_TTSD_SR_PID_9                       = (dword *) 0xb000a42c;
volatile dword *EMMA_TTSD_SR_PID_10                      = (dword *) 0xb000a430;
volatile dword *EMMA_TTSD_SR_PID_11                      = (dword *) 0xb000a434;
volatile dword *EMMA_TTSD_SR_PID_12                      = (dword *) 0xb000a438;
volatile dword *EMMA_TTSD_SR_PID_13                      = (dword *) 0xb000a43c;
volatile dword *EMMA_TTSD_SR_PID_14                      = (dword *) 0xb000a440;
volatile dword *EMMA_TTSD_SR_PID_15                      = (dword *) 0xb000a444;
volatile dword *EMMA_TTSD_SR_PID_16                      = (dword *) 0xb000a448;
volatile dword *EMMA_TTSD_SR_PID_17                      = (dword *) 0xb000a44c;
volatile dword *EMMA_TTSD_SR_PID_18                      = (dword *) 0xb000a450;
volatile dword *EMMA_TTSD_SR_PID_19                      = (dword *) 0xb000a454;
volatile dword *EMMA_TTSD_SR_PID_20                      = (dword *) 0xb000a458;
volatile dword *EMMA_TTSD_SR_PID_21                      = (dword *) 0xb000a45c;
volatile dword *EMMA_TTSD_SR_PID_22                      = (dword *) 0xb000a460;
volatile dword *EMMA_TTSD_SR_PID_23                      = (dword *) 0xb000a464;
volatile dword *EMMA_TTSD_SR_PID_24                      = (dword *) 0xb000a468;
volatile dword *EMMA_TTSD_SR_PID_25                      = (dword *) 0xb000a46c;
volatile dword *EMMA_TTSD_SR_PID_26                      = (dword *) 0xb000a470;
volatile dword *EMMA_TTSD_SR_PID_27                      = (dword *) 0xb000a474;
volatile dword *EMMA_TTSD_SR_PID_28                      = (dword *) 0xb000a478;
volatile dword *EMMA_TTSD_SR_PID_29                      = (dword *) 0xb000a47c;
volatile dword *EMMA_TTSD_SR_PID_30                      = (dword *) 0xb000a480;
volatile dword *EMMA_TTSD_SR_PID_31                      = (dword *) 0xb000a484;
volatile dword *EMMA_TTSD_SR_WRBUF_STRT                  = (dword *) 0xb000a488;
volatile dword *EMMA_TTSD_SR_WRITE_POINTER0              = (dword *) 0xb000a48c;
volatile dword *EMMA_TTSD_SR_TRANSFER_REQUEST_POINTER0   = (dword *) 0xb000a490;
volatile dword *EMMA_TTSD_SR_END_POINTER0                = (dword *) 0xb000a494;
volatile dword *EMMA_TTSD_SR_WRITE_POINTER1              = (dword *) 0xb000a498;
volatile dword *EMMA_TTSD_SR_TRANSFER_REQUEST_POINTER1   = (dword *) 0xb000a49c;
volatile dword *EMMA_TTSD_SR_END_POINTER1                = (dword *) 0xb000a4a0;
volatile dword *EMMA_TTSD_SR_INTERRUPT                   = (dword *) 0xb000a4a4;
volatile dword *EMMA_TTSD_SR_INTERRUPT_MASK              = (dword *) 0xb000a4ac;
volatile dword *EMMA_TTSD_SR_ADAPTATION                  = (dword *) 0xb000a4b0;
volatile dword *EMMA_TTSD_EL_RTS_COUNTER                 = (dword *) 0xb000a500;
volatile dword *EMMA_TTSD_EL_RTS_CNT                     = (dword *) 0xb000a504;
volatile dword *EMMA_TTSD_EL_EVENT_EN_0                  = (dword *) 0xb000a508;
volatile dword *EMMA_TTSD_EL_EVENT_EN_1                  = (dword *) 0xb000a50c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_2                  = (dword *) 0xb000a510;
volatile dword *EMMA_TTSD_EL_EVENT_EN_3                  = (dword *) 0xb000a514;
volatile dword *EMMA_TTSD_EL_EVENT_EN_4                  = (dword *) 0xb000a518;
volatile dword *EMMA_TTSD_EL_EVENT_EN_5                  = (dword *) 0xb000a51c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_6                  = (dword *) 0xb000a520;
volatile dword *EMMA_TTSD_EL_EVENT_EN_7                  = (dword *) 0xb000a524;
volatile dword *EMMA_TTSD_EL_EVENT_EN_8                  = (dword *) 0xb000a528;
volatile dword *EMMA_TTSD_EL_EVENT_EN_9                  = (dword *) 0xb000a52c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_10                 = (dword *) 0xb000a530;
volatile dword *EMMA_TTSD_EL_EVENT_EN_11                 = (dword *) 0xb000a534;
volatile dword *EMMA_TTSD_EL_EVENT_EN_12                 = (dword *) 0xb000a538;
volatile dword *EMMA_TTSD_EL_EVENT_EN_13                 = (dword *) 0xb000a53c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_14                 = (dword *) 0xb000a540;
volatile dword *EMMA_TTSD_EL_EVENT_EN_15                 = (dword *) 0xb000a544;
volatile dword *EMMA_TTSD_EL_EVENT_EN_16                 = (dword *) 0xb000a548;
volatile dword *EMMA_TTSD_EL_EVENT_EN_17                 = (dword *) 0xb000a54c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_18                 = (dword *) 0xb000a550;
volatile dword *EMMA_TTSD_EL_EVENT_EN_19                 = (dword *) 0xb000a554;
volatile dword *EMMA_TTSD_EL_EVENT_EN_20                 = (dword *) 0xb000a558;
volatile dword *EMMA_TTSD_EL_EVENT_EN_21                 = (dword *) 0xb000a55c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_22                 = (dword *) 0xb000a560;
volatile dword *EMMA_TTSD_EL_EVENT_EN_23                 = (dword *) 0xb000a564;
volatile dword *EMMA_TTSD_EL_EVENT_EN_24                 = (dword *) 0xb000a568;
volatile dword *EMMA_TTSD_EL_EVENT_EN_25                 = (dword *) 0xb000a56c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_26                 = (dword *) 0xb000a570;
volatile dword *EMMA_TTSD_EL_EVENT_EN_27                 = (dword *) 0xb000a574;
volatile dword *EMMA_TTSD_EL_EVENT_EN_28                 = (dword *) 0xb000a578;
volatile dword *EMMA_TTSD_EL_EVENT_EN_29                 = (dword *) 0xb000a57c;
volatile dword *EMMA_TTSD_EL_EVENT_EN_30                 = (dword *) 0xb000a580;
volatile dword *EMMA_TTSD_EL_EVENT_EN_31                 = (dword *) 0xb000a584;
volatile dword *EMMA_TTSD_EL_WRBUF_STRT                  = (dword *) 0xb000a588;
volatile dword *EMMA_TTSD_EL_WRITE_POINTER0              = (dword *) 0xb000a58c;
volatile dword *EMMA_TTSD_EL_NEARLY_FULL_POINTER0        = (dword *) 0xb000a590;
volatile dword *EMMA_TTSD_EL_END_POINTER0                = (dword *) 0xb000a594;
volatile dword *EMMA_TTSD_EL_WRITE_POINTER1              = (dword *) 0xb000a598;
volatile dword *EMMA_TTSD_EL_NEARLY_FULL_POINTER1        = (dword *) 0xb000a59c;
volatile dword *EMMA_TTSD_EL_END_POINTER1                = (dword *) 0xb000a5a0;
volatile dword *EMMA_TTSD_EL_INTERRUPT                   = (dword *) 0xb000a5a4;
volatile dword *EMMA_TTSD_EL_INTERRUPT_MASK              = (dword *) 0xb000a5a8;
volatile dword *EMMA_TTSD_PKT_COUNTER_0                  = (dword *) 0xb000a5ac;
volatile dword *EMMA_TTSD_PKT_COUNTER_1                  = (dword *) 0xb000a5b0;
volatile dword *EMMA_TTSD_PB_MODE0                       = (dword *) 0xb000a600;
volatile dword *EMMA_TTSD_PB_MODE1                       = (dword *) 0xb000a604;
volatile dword *EMMA_TTSD_PB_START_ADDRESS_A             = (dword *) 0xb000a608;
volatile dword *EMMA_TTSD_PB_LEN_A                       = (dword *) 0xb000a60c;
volatile dword *EMMA_TTSD_PB_START_ADDRESS_B             = (dword *) 0xb000a610;
volatile dword *EMMA_TTSD_PB_LEN_B                       = (dword *) 0xb000a614;
volatile dword *EMMA_TTSD_PB_CURR_ADDRESS                = (dword *) 0xb000a618;
volatile dword *EMMA_TTSD_PB_STATUS                      = (dword *) 0xb000a61c;
volatile dword *EMMA_TTSD_PB_INTERRUPT                   = (dword *) 0xb000a620;
volatile dword *EMMA_TTSD_PB_INTERRUPT_MASK              = (dword *) 0xb000a624;
volatile dword *EMMA_TTSD_PID_48                         = (dword *) 0xb000a640;
volatile dword *EMMA_TTSD_PID_49                         = (dword *) 0xb000a644;
volatile dword *EMMA_TTSD_PID_50                         = (dword *) 0xb000a648;
volatile dword *EMMA_TTSD_PID_51                         = (dword *) 0xb000a64c;
volatile dword *EMMA_TTSD_PID_52                         = (dword *) 0xb000a650;
volatile dword *EMMA_TTSD_PID_53                         = (dword *) 0xb000a654;
volatile dword *EMMA_TTSD_PID_54                         = (dword *) 0xb000a658;
volatile dword *EMMA_TTSD_PID_55                         = (dword *) 0xb000a65c;
volatile dword *EMMA_TTSD_PID_56                         = (dword *) 0xb000a660;
volatile dword *EMMA_TTSD_PID_57                         = (dword *) 0xb000a664;
volatile dword *EMMA_TTSD_PID_58                         = (dword *) 0xb000a668;
volatile dword *EMMA_TTSD_PID_59                         = (dword *) 0xb000a66c;
volatile dword *EMMA_TTSD_PID_60                         = (dword *) 0xb000a670;
volatile dword *EMMA_TTSD_PID_61                         = (dword *) 0xb000a674;
volatile dword *EMMA_TTSD_PID_62                         = (dword *) 0xb000a678;
volatile dword *EMMA_TTSD_PID_63                         = (dword *) 0xb000a67c;
volatile dword *EMMA_TTSD_PID_64                         = (dword *) 0xb000a680;
volatile dword *EMMA_TTSD_PID_65                         = (dword *) 0xb000a684;
volatile dword *EMMA_TTSD_PID_66                         = (dword *) 0xb000a688;
volatile dword *EMMA_TTSD_PID_67                         = (dword *) 0xb000a68c;
volatile dword *EMMA_TTSD_PID_68                         = (dword *) 0xb000a690;
volatile dword *EMMA_TTSD_PID_69                         = (dword *) 0xb000a694;
volatile dword *EMMA_TTSD_PID_70                         = (dword *) 0xb000a698;
volatile dword *EMMA_TTSD_PID_71                         = (dword *) 0xb000a69c;
volatile dword *EMMA_TTSD_PID_72                         = (dword *) 0xb000a6a0;
volatile dword *EMMA_TTSD_PID_73                         = (dword *) 0xb000a6a4;
volatile dword *EMMA_TTSD_PID_74                         = (dword *) 0xb000a6a8;
volatile dword *EMMA_TTSD_PID_75                         = (dword *) 0xb000a6ac;
volatile dword *EMMA_TTSD_PID_76                         = (dword *) 0xb000a6b0;
volatile dword *EMMA_TTSD_PID_77                         = (dword *) 0xb000a6b4;
volatile dword *EMMA_TTSD_PID_78                         = (dword *) 0xb000a6b8;
volatile dword *EMMA_TTSD_PID_79                         = (dword *) 0xb000a6bc;
volatile dword *EMMA_TTSD_PID_80                         = (dword *) 0xb000a6c0;
volatile dword *EMMA_TTSD_PID_81                         = (dword *) 0xb000a6c4;
volatile dword *EMMA_TTSD_PID_82                         = (dword *) 0xb000a6c8;
volatile dword *EMMA_TTSD_PID_83                         = (dword *) 0xb000a6cc;
volatile dword *EMMA_TTSD_PID_84                         = (dword *) 0xb000a6d0;
volatile dword *EMMA_TTSD_PID_85                         = (dword *) 0xb000a6d4;
volatile dword *EMMA_TTSD_PID_86                         = (dword *) 0xb000a6d8;
volatile dword *EMMA_TTSD_PID_87                         = (dword *) 0xb000a6dc;
volatile dword *EMMA_TTSD_PID_88                         = (dword *) 0xb000a6e0;
volatile dword *EMMA_TTSD_PID_89                         = (dword *) 0xb000a6e4;
volatile dword *EMMA_TTSD_PID_90                         = (dword *) 0xb000a6e8;
volatile dword *EMMA_TTSD_PID_91                         = (dword *) 0xb000a6ec;
volatile dword *EMMA_TTSD_PID_92                         = (dword *) 0xb000a6f0;
volatile dword *EMMA_TTSD_PID_93                         = (dword *) 0xb000a6f4;
volatile dword *EMMA_TTSD_PID_94                         = (dword *) 0xb000a6f8;
volatile dword *EMMA_TTSD_PID_95                         = (dword *) 0xb000a6fc;
volatile dword *EMMA_TTSD_PID_EXT_0                      = (dword *) 0xb000a700;
volatile dword *EMMA_TTSD_PID_EXT_1                      = (dword *) 0xb000a704;
volatile dword *EMMA_TTSD_PID_EXT_2                      = (dword *) 0xb000a708;
volatile dword *EMMA_TTSD_PID_EXT_3                      = (dword *) 0xb000a70c;
volatile dword *EMMA_TTSD_PID_EXT_4                      = (dword *) 0xb000a710;
volatile dword *EMMA_TTSD_PID_EXT_5                      = (dword *) 0xb000a714;
volatile dword *EMMA_TTSD_PID_EXT_6                      = (dword *) 0xb000a718;
volatile dword *EMMA_TTSD_PID_EXT_7                      = (dword *) 0xb000a71c;
volatile dword *EMMA_TTSD_PID_EXT_8                      = (dword *) 0xb000a720;
volatile dword *EMMA_TTSD_PID_EXT_9                      = (dword *) 0xb000a724;
volatile dword *EMMA_TTSD_PID_EXT_10                     = (dword *) 0xb000a728;
volatile dword *EMMA_TTSD_PID_EXT_11                     = (dword *) 0xb000a72c;
volatile dword *EMMA_TTSD_PID_EXT_12                     = (dword *) 0xb000a730;
volatile dword *EMMA_TTSD_PID_EXT_13                     = (dword *) 0xb000a734;
volatile dword *EMMA_TTSD_PID_EXT_14                     = (dword *) 0xb000a738;
volatile dword *EMMA_TTSD_PID_EXT_15                     = (dword *) 0xb000a73c;
volatile dword *EMMA_TTSD_PID_EXT_16                     = (dword *) 0xb000a740;
volatile dword *EMMA_TTSD_PID_EXT_17                     = (dword *) 0xb000a744;
volatile dword *EMMA_TTSD_PID_EXT_18                     = (dword *) 0xb000a748;
volatile dword *EMMA_TTSD_PID_EXT_19                     = (dword *) 0xb000a74c;
volatile dword *EMMA_TTSD_PID_EXT_20                     = (dword *) 0xb000a750;
volatile dword *EMMA_TTSD_PID_EXT_21                     = (dword *) 0xb000a754;
volatile dword *EMMA_TTSD_PID_EXT_22                     = (dword *) 0xb000a758;
volatile dword *EMMA_TTSD_PID_EXT_23                     = (dword *) 0xb000a75c;
volatile dword *EMMA_TTSD_PID_EXT_24                     = (dword *) 0xb000a760;
volatile dword *EMMA_TTSD_PID_EXT_25                     = (dword *) 0xb000a764;
volatile dword *EMMA_TTSD_PID_EXT_26                     = (dword *) 0xb000a768;
volatile dword *EMMA_TTSD_PID_EXT_27                     = (dword *) 0xb000a76c;
volatile dword *EMMA_TTSD_PID_EXT_28                     = (dword *) 0xb000a770;
volatile dword *EMMA_TTSD_PID_EXT_29                     = (dword *) 0xb000a774;
volatile dword *EMMA_TTSD_PID_EXT_30                     = (dword *) 0xb000a778;
volatile dword *EMMA_TTSD_PID_EXT_31                     = (dword *) 0xb000a77c;
volatile dword *EMMA_TTSD_PID_EXT_32                     = (dword *) 0xb000a780;
volatile dword *EMMA_TTSD_PID_EXT_33                     = (dword *) 0xb000a784;
volatile dword *EMMA_TTSD_PID_EXT_34                     = (dword *) 0xb000a788;
volatile dword *EMMA_TTSD_PID_EXT_35                     = (dword *) 0xb000a78c;
volatile dword *EMMA_TTSD_PID_EXT_36                     = (dword *) 0xb000a790;
volatile dword *EMMA_TTSD_PID_EXT_37                     = (dword *) 0xb000a794;
volatile dword *EMMA_TTSD_PID_EXT_38                     = (dword *) 0xb000a798;
volatile dword *EMMA_TTSD_PID_EXT_39                     = (dword *) 0xb000a79c;
volatile dword *EMMA_TTSD_PID_EXT_40                     = (dword *) 0xb000a7a0;
volatile dword *EMMA_TTSD_PID_EXT_41                     = (dword *) 0xb000a7a4;
volatile dword *EMMA_TTSD_PID_EXT_42                     = (dword *) 0xb000a7a8;
volatile dword *EMMA_TTSD_PID_EXT_43                     = (dword *) 0xb000a7ac;
volatile dword *EMMA_TTSD_PID_EXT_44                     = (dword *) 0xb000a7b0;
volatile dword *EMMA_TTSD_PID_EXT_45                     = (dword *) 0xb000a7b4;
volatile dword *EMMA_TTSD_PID_EXT_46                     = (dword *) 0xb000a7b8;
volatile dword *EMMA_TTSD_PID_EXT_47                     = (dword *) 0xb000a7bc;
volatile dword *EMMA_TTSD_PS_CNT                         = (dword *) 0xb000a7e0;
volatile dword *EMMA_TTSD_PIC_HDR_CNT                    = (dword *) 0xb000a800;
volatile dword *EMMA_TTSD_1STV_PIC0_COUNTER              = (dword *) 0xb000a804;
volatile dword *EMMA_TTSD_1STV_PIC1_COUNTER              = (dword *) 0xb000a808;
volatile dword *EMMA_TTSD_1STV_PIC2_COUNTER              = (dword *) 0xb000a80c;
volatile dword *EMMA_TTSD_1STV_HDR0_COUNTER              = (dword *) 0xb000a810;
volatile dword *EMMA_TTSD_1STV_HDR1_COUNTER              = (dword *) 0xb000a814;
volatile dword *EMMA_TTSD_1STV_HDR2_COUNTER              = (dword *) 0xb000a818;
volatile dword *EMMA_TTSD_2NDV_PIC0_COUNTER              = (dword *) 0xb000a81c;
volatile dword *EMMA_TTSD_2NDV_PIC1_COUNTER              = (dword *) 0xb000a820;
volatile dword *EMMA_TTSD_2NDV_PIC2_COUNTER              = (dword *) 0xb000a824;
volatile dword *EMMA_TTSD_2NDV_HDR0_COUNTER              = (dword *) 0xb000a828;
volatile dword *EMMA_TTSD_2NDV_HDR1_COUNTER              = (dword *) 0xb000a82c;
volatile dword *EMMA_TTSD_2NDV_HDR2_COUNTER              = (dword *) 0xb000a830;
volatile dword *EMMA_TTSD_SR_PID_EXT_0                   = (dword *) 0xb000a900;
volatile dword *EMMA_TTSD_SR_PID_EXT_1                   = (dword *) 0xb000a904;
volatile dword *EMMA_TTSD_SR_PID_EXT_2                   = (dword *) 0xb000a908;
volatile dword *EMMA_TTSD_SR_PID_EXT_3                   = (dword *) 0xb000a90c;
volatile dword *EMMA_TTSD_SR_PID_EXT_4                   = (dword *) 0xb000a910;
volatile dword *EMMA_TTSD_SR_PID_EXT_5                   = (dword *) 0xb000a914;
volatile dword *EMMA_TTSD_SR_PID_EXT_6                   = (dword *) 0xb000a918;
volatile dword *EMMA_TTSD_SR_PID_EXT_7                   = (dword *) 0xb000a91c;
volatile dword *EMMA_TTSD_SR_PID_EXT_8                   = (dword *) 0xb000a920;
volatile dword *EMMA_TTSD_SR_PID_EXT_9                   = (dword *) 0xb000a924;
volatile dword *EMMA_TTSD_SR_PID_EXT_10                  = (dword *) 0xb000a928;
volatile dword *EMMA_TTSD_SR_PID_EXT_11                  = (dword *) 0xb000a92c;
volatile dword *EMMA_TTSD_SR_PID_EXT_12                  = (dword *) 0xb000a930;
volatile dword *EMMA_TTSD_SR_PID_EXT_13                  = (dword *) 0xb000a934;
volatile dword *EMMA_TTSD_SR_PID_EXT_14                  = (dword *) 0xb000a938;
volatile dword *EMMA_TTSD_SR_PID_EXT_15                  = (dword *) 0xb000a93c;
volatile dword *EMMA_TTSD_SR_PID_EXT_16                  = (dword *) 0xb000a940;
volatile dword *EMMA_TTSD_SR_PID_EXT_17                  = (dword *) 0xb000a944;
volatile dword *EMMA_TTSD_SR_PID_EXT_18                  = (dword *) 0xb000a948;
volatile dword *EMMA_TTSD_SR_PID_EXT_19                  = (dword *) 0xb000a94c;
volatile dword *EMMA_TTSD_SR_PID_EXT_20                  = (dword *) 0xb000a950;
volatile dword *EMMA_TTSD_SR_PID_EXT_21                  = (dword *) 0xb000a954;
volatile dword *EMMA_TTSD_SR_PID_EXT_22                  = (dword *) 0xb000a958;
volatile dword *EMMA_TTSD_SR_PID_EXT_23                  = (dword *) 0xb000a95c;
volatile dword *EMMA_TTSD_SR_PID_EXT_24                  = (dword *) 0xb000a960;
volatile dword *EMMA_TTSD_SR_PID_EXT_25                  = (dword *) 0xb000a964;
volatile dword *EMMA_TTSD_SR_PID_EXT_26                  = (dword *) 0xb000a968;
volatile dword *EMMA_TTSD_SR_PID_EXT_27                  = (dword *) 0xb000a96c;
volatile dword *EMMA_TTSD_SR_PID_EXT_28                  = (dword *) 0xb000a970;
volatile dword *EMMA_TTSD_SR_PID_EXT_29                  = (dword *) 0xb000a974;
volatile dword *EMMA_TTSD_SR_PID_EXT_30                  = (dword *) 0xb000a978;
volatile dword *EMMA_TTSD_SR_PID_EXT_31                  = (dword *) 0xb000a97c;
volatile dword *EMMA_TTSD_GENERAL_PID_EL_EXT_EN_CNT      = (dword *) 0xb000a9a0;
volatile dword *EMMA_TTSD_EL_EVENT_EXT_EN_0              = (dword *) 0xb000a9a4;
volatile dword *EMMA_TTSD_EL_EVENT_EXT_EN_1              = (dword *) 0xb000a9a8;
volatile dword *EMMA_TTSD_EL_EVENT_EXT_EN_2              = (dword *) 0xb000a9ac;
volatile dword *EMMA_TTSD_EL_EVENT_EXT_EN_3              = (dword *) 0xb000a9b0;
volatile dword *EMMA_TTSD_PB_PKT_INTERVAL_TIMER_CNT      = (dword *) 0xb000aa00;
volatile dword *EMMA_TTSD_PB_PKT_INTERVAL_TIMER          = (dword *) 0xb000aa04;
volatile dword *EMMA_TTSD_HSD_JITTER_CNT                 = (dword *) 0xb000aa10;
volatile dword *EMMA_TTSD_HSD_JITTER_CNT_TIMER           = (dword *) 0xb000aa14;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT5           = (dword *) 0xb000ab00;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT6           = (dword *) 0xb000ab04;
volatile dword *EMMA_TTSD_PID_ERROR_INTERRUPT5           = (dword *) 0xb000ab10;
volatile dword *EMMA_TTSD_PID_ERROR_INTERRUPT6           = (dword *) 0xb000ab14;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT4      = (dword *) 0xb000ab20;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT5      = (dword *) 0xb000ab24;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT6      = (dword *) 0xb000ab28;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT4         = (dword *) 0xb000ab30;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT5         = (dword *) 0xb000ab34;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT6         = (dword *) 0xb000ab38;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK5      = (dword *) 0xb000ab40;
volatile dword *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK6      = (dword *) 0xb000ab44;
volatile dword *EMMA_TTSD_PID_ERROR_MASK5                = (dword *) 0xb000ab50;
volatile dword *EMMA_TTSD_PID_ERROR_MASK6                = (dword *) 0xb000ab54;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK4 = (dword *) 0xb000ab60;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK5 = (dword *) 0xb000ab64;
volatile dword *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK6 = (dword *) 0xb000ab68;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK4    = (dword *) 0xb000ab70;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK5    = (dword *) 0xb000ab74;
volatile dword *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK6    = (dword *) 0xb000ab78;
volatile dword *EMMA_TTSD_PID_STOP3                      = (dword *) 0xb000ab90;
volatile dword *EMMA_TTSD_PID_STOP4                      = (dword *) 0xb000ab94;

#endif
