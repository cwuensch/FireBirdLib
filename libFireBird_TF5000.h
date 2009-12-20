  extern dword                 BIOSAddress;                             //The address of the callBIOS routine
  extern dword                 EnqueueEventAddress;                     //The address of the EventDispatcherAddress routine
  extern dword                 TAPgp, FWgp, TAP_TableAddress, TAP_IndexAddress, TAP_TableIndex;
  extern dword                 pWD1, pWD2, pWD3, pWD4, pWD5, pFWWD, pFWWDBackup;


  /*****************************************************************************************************************************/
  /* EMMA Register                                                                                                             */
  /*****************************************************************************************************************************/

  // Scaler and OSD headers

  // Resizing parameters for vertical/horizontal luma & chroma
  typedef struct
  {
    dword       init;                               // resizing initial value
    dword       delta1;                             // resizing DDA delta1
    dword       limit;                              // resizing max delta
    dword       delta2;                             // resizing DDA delta2
    dword       delta3;                             // resizing DDA delta3
  } tEMMA_SCL_RESIZE_HEADER;

  typedef struct
  {
    dword       control;                            // scaler control
    dword       size;                               // scaler data size
    dword       y_even;                             // scaler Y-even start address
    dword       y_odd;                              // scaler Y-odd start address
    dword       y_chr_even;                         // scaler chroma-even start address
    dword       y_chr_odd;                          // scaler chroma-odd start address
    dword       src_start;                          // scaler source start X & Y
    dword       src_size;                           // scaler source X & Y size
    dword       dsp_start;                          // scaler display start X & Y
    dword       dsp_size;                           // scaler display X & Y size
    dword       clip_start;                         // scaler clip start X & Y
    dword       clip_size;                          // scaler clip X & Y size
    dword       empty1;
    dword       empty2;
    dword       flt_control;                        // scaler filter control
    dword       flt_horiz;                          // scaler filter horizontal parameter
    dword       flt_vertlum;                        // scaler filter vertical luma parameter
    dword       flt_vertchr;                        // scaler filter vertial chroma parameter
    tEMMA_SCL_RESIZE_HEADER  hy;                     // horizontal resizing luma parameters
    tEMMA_SCL_RESIZE_HEADER  hc;                     // horizontal resizing chroma parameters
    tEMMA_SCL_RESIZE_HEADER  vy;                     // vertical resizing luma parameters
    tEMMA_SCL_RESIZE_HEADER  vc;                     // vertical resizing chroma parameters
    dword       chkey_max;                          // chroma-key maximum and control
    dword       chkey_min;                          // chroma-key minimum setting
    dword       alpha;                              // scaler alpha blending control
    dword       linebuf;                            // scaler line buffer control
    dword       window;                             // scaler window header link control
  } tEMMA_SCL_HEADER;

  typedef struct
  {
    dword       alpha;                              // OSD alpha control
    dword       disp_start;                         // OSD display start X & Y
    dword       disp_size;                          // OSD display X & Y size
    dword       tile_size;                          // OSD tile cell size
    dword       clut_addr;                          // OSD color look-up table address
    dword       alph_addr;                          // OSD alpha lookup table address
    dword       data_ctl1;                          // OSD data control 1
    dword       data_ctl2;                          // OSD data control 2
    dword       chain_ctl;                          // OSD address chain control
    dword       alpha_sel1;                         // OSD alpha select #1
    dword       alpha_sel2;                         // OSD alpha select #2
    dword       alpha_sel3;                         // OSD alpha select #3
    dword       alpha_sel4;                         // OSD alpha select #4
    dword       alpha_sel5;                         // OSD alpha select #5
    dword       alpha_sel6;                         // OSD alpha select #6
    dword       alpha_sel7;                         // OSD alpha select #7
    dword       alpha_sel8;                         // OSD alpha select #8
    dword       not_used;
  } tEMMA_OSD_HEADER;

  // Short OSD header when alpha select words not used
  typedef struct
  {
    dword       alpha;                              // OSD alpha control
    dword       disp_start;                         // OSD display start X & Y
    dword       disp_size;                          // OSD display X & Y size
    dword       tile_size;                          // OSD tile cell size
    dword       clut_addr;                          // OSD color look-up table address
    dword       alph_addr;                          // OSD alpha lookup table address
    dword       data_ctl1;                          // OSD data control 1
    dword       data_ctl2;                          // OSD data control 2
    dword       chain_ctl;                          // OSD address chain control
    dword       not_used;
  } tEMMA_OSD_HEADER_S;


  /* Hardware cursor header is 20 words, 80 bytes */

  typedef struct
  {
    dword       curs_size;                          // HWC cursor size and timing
    dword       chain_ctl;                          // address of next HWC header
    dword       data_ctl1;                          // even line pointer & flags
    dword       data_ctl2;                          // odd line pointer
    dword       clut_tab[16];                       // cursor color lookup table data
  } tEMMA_HWC_HEADER;

  typedef struct
  {
#ifdef PC_BASED
    dword   Address:28;
    dword   unknown3:1;
    dword   unknown2:1;
    dword   Active:1;
    dword   unknown1:1;
#else
    dword   unknown1:1;
    dword   Active:1;
    dword   unknown2:1;
    dword   unknown3:1;
    dword   Address:28;
#endif
  } tpScalerSettings;

  typedef struct
  {
    byte    unknown1 [4];
    word    MPEGFrameHeight;
    word    MPEGFrameWidth;
    byte    unknown2 [20];
    word    MPEGFrameHeight2; //same as MPEGFrameHeight
    word    MPEGFrameWidth2;  //same as MPEGFrameWidth

#ifdef PC_BASED
    word    WindowY2:12;      //has an offset of up to 4 pixels; use WindowY
    word    unknown3:4;

    word    WindowX2:12;      //has an offset of up to 4 pixels; use WindowX
    word    unknown4:4;

    word    WindowHeight2:12; //has an offset of up to 4 pixels; use WindowHeight
    word    unknown5:4;

    word    WindowWidth2:12;  //has an offset of up to 4 pixels; use WindowWidth
    word    unknown6:4;

    word    WindowY:12;
    word    unknown7:4;

    word    WindowX:12;
    word    unknown8:4;

    word    WindowHeight:12;
    word    unknown9:4;

    word    WindowWidth:12;
    word    unknown10:4;
#else
    word    unknown3:4;
    word    WindowY2:12;      //has an offset of up to 4 pixels; use WindowY

    word    unknown4:4;
    word    WindowX2:12;      //has an offset of up to 4 pixels; use WindowX

    word    unknown5:4;
    word    WindowHeight2:12; //has an offset of up to 4 pixels; use WindowHeight

    word    unknown6:4;
    word    WindowWidth2:12;  //has an offset of up to 4 pixels; use WindowWidth

    word    unknown7:4;
    word    WindowY:12;

    word    unknown8:4;
    word    WindowX:12;

    word    unknown9:4;
    word    WindowHeight:12;

    word    unknown10:4;
    word    WindowWidth:12;
#endif

    byte    unknown11 [12];
    dword   pFrameData1;      //not sure what this is
    dword   pFrameData2;      //not sure what this is
    dword   pFrameData3;      //not sure what this is
  } tScalerSettings;          //72 Bytes

  //BHIF = Host Interface
  extern volatile dword   *EMMA_BHIF_Version;
  extern volatile dword   *EMMA_BHIF_Strap_1;
  extern volatile dword   *EMMA_BHIF_Strap_2;
  extern volatile dword   *EMMA_BHIF_Strap_Write_1;
  extern volatile dword   *EMMA_BHIF_Strap_Write_2;
  extern volatile dword   *EMMA_BHIF_Int_St_1;
  extern volatile dword   *EMMA_BHIF_Int_St_2;
  extern volatile dword   *EMMA_BHIF_Int_Enable_1;
  extern volatile dword   *EMMA_BHIF_Int_Enable_2;
  extern volatile dword   *EMMA_BHIF_NMI_St;
  extern volatile dword   *EMMA_BHIF_NMI_Enable;
  extern volatile dword   *EMMA_BHIF_Bus_Priority;
  extern volatile dword   *EMMA_BHIF_BErr_CLR;
  extern volatile dword   *EMMA_BHIF_BErr_RLS;
  extern volatile dword   *EMMA_BHIF_BErr_CAUSE;
  extern volatile dword   *EMMA_BHIF_BErr_ADR;
  extern volatile dword   *EMMA_BHIF_BErr_RW;
  extern volatile dword   *EMMA_BHIF_BErr_TARGET;
  extern volatile dword   *EMMA_BHIF_BErr_CPUMSK;
  extern volatile dword   *EMMA_BHIF_BERR_CMTRG;
  extern volatile dword   *EMMA_BHIF_CLK_SEL_1;
  extern volatile dword   *EMMA_BHIF_CLK_SEL_2;
  extern volatile dword   *EMMA_BHIF_CLK_SEL_3;
  extern volatile dword   *EMMA_BHIF_CLK_MSK;
  extern volatile dword   *EMMA_BHIF_CLK_MCLKDIV;
  extern volatile dword   *EMMA_BHIF_CLK_MCLKRST;

  //BARB
  extern volatile dword   *EMMA_BARB;

  //BROI = ROM Interface
  extern volatile dword   *EMMA_BROI_FN_FSM;
  extern volatile dword   *EMMA_BROI_OAT_FAT;
  extern volatile dword   *EMMA_BROI_WErr_WM;


  //OGIO = GIO INTERFACE
  extern volatile dword   *EMMA_OGIO_AC_CNT;
  extern volatile dword   *EMMA_OGIO_b0000808;
  extern volatile dword   *EMMA_OGIO_b000080c;
  extern volatile dword   *EMMA_OGIO_CS0_BASE;
  extern volatile dword   *EMMA_OGIO_CS1_BASE;

  #define EMMA_OGIO_AC_CNT_GAT0_6_HCLKS   = (dword *) 0x3
  #define EMMA_OGIO_AC_CNT_RWMOD      (1 << 8)
  #define EMMA_OGIO_AC_CNT_BENDIAN    (1 << 9)


  //MPEG = MPEG Decoder
  extern volatile dword   *EMMA_MPEG_RESET;
  extern volatile dword   *EMMA_MPEG_BS_CTL_MAIN_CH;
  extern volatile dword   *EMMA_MPEG_BS_PTR_MAIN_CH;
  extern volatile dword   *EMMA_MPEG_START_MODE;
  extern volatile dword   *EMMA_MPEG_START_CTL;
  extern volatile dword   *EMMA_MPEG_START_STATUS;
  extern volatile dword   *EMMA_MPEG_START_STATUS2;
  extern volatile dword   *EMMA_MPEG_b0002038;
  extern volatile dword   *EMMA_MPEG_b000203c;
  extern volatile dword   *EMMA_MPEG_DEC_OV;
  extern volatile dword   *EMMA_MPEG_DEC_MODE;
  extern volatile dword   *EMMA_MPEG_DEC_CTL;
  extern volatile dword   *EMMA_MPEG_WAIT_COND;
  extern volatile dword   *EMMA_MPEG_TIMEOUT_MAIN;
  extern volatile dword   *EMMA_MPEG_TIMEOUT_SUB;
  extern volatile dword   *EMMA_MPEG_MAIN_STATUS;
  extern volatile dword   *EMMA_MPEG_ZERO23_STATUS;
  extern volatile dword   *EMMA_MPEG_DEC_STATUS;
  extern volatile dword   *EMMA_MPEG_BRL_STATUS;
  extern volatile dword   *EMMA_MPEG_SUB_FIFO_STATUS;
  extern volatile dword   *EMMA_MPEG_TIMEOUT_STATUS;
  extern volatile dword   *EMMA_MPEG_VLC_ERROR;
  extern volatile dword   *EMMA_MPEG_BRL_RD;
  extern volatile dword   *EMMA_MPEG_BRL_SHIFT;
  extern volatile dword   *EMMA_MPEG_MATRIX_I;
  extern volatile dword   *EMMA_MPEG_MATRIX_N;
  extern volatile dword   *EMMA_MPEG_PARAM_SEQ;
  extern volatile dword   *EMMA_MPEG_PARAM_PICH;
  extern volatile dword   *EMMA_MPEG_PARAM_PICE;
  extern volatile dword   *EMMA_MPEG_MC_MODE;
  extern volatile dword   *EMMA_MPEG_CPU_INT;
  extern volatile dword   *EMMA_MPEG_CPU_MASK;

  //JPEG registers
  extern volatile dword   *EMMA_MPEG_JPEG_WADR;
  extern volatile dword   *EMMA_MPEG_JPEG_MODE;
  extern volatile dword   *EMMA_MPEG_JPEG_CTL;

  //EMMA_MPEG interrupt flags
  #define EMMA_MPEG_INT_START_MAIN    (1)
  #define EMMA_MPEG_INT_START_SUB     (1 << 1)
  #define EMMA_MPEG_INT_VLC_ERR       (1 << 2)
  #define EMMA_MPEG_INT_MPEG_DONE     (1 << 3)
  #define EMMA_MPEG_INT_JPEG_DONE     (1 << 4)
  #define EMMA_MPEG_INT_TIME_MAIN     (1 << 5)
  #define EMMA_MPEG_INT_TIME_SUB      (1 << 6)
  #define EMMA_MPEG_INT_WAIT          (1 << 7)


  //DSCL = Scaler Control
  extern volatile dword   *EMMA_DSCL_SCL1_HDRTOP;
  extern volatile dword   *EMMA_DSCL_SCL1_HDRBOT;
  extern volatile dword   *EMMA_DSCL_SCL2_HDRTOP;
  extern volatile dword   *EMMA_DSCL_SCL2_HDRBOT;
  extern volatile dword   *EMMA_DSCL_SCL3_HDRTOP;
  extern volatile dword   *EMMA_DSCL_SCL3_HDRBOT;
  extern volatile dword   *EMMA_DSCL_CUR_DSPLINE;

  //DGRP = Graphics processor control - OSD and cursor planes
  extern volatile dword   *EMMA_DGRP_RELCTR;
  extern volatile dword   *EMMA_DGRP_OSD1CTR;
  extern volatile dword   *EMMA_DGRP_OSD2CTR;
  extern volatile dword   *EMMA_DGRP_HWCCTR;
  extern volatile dword   *EMMA_DGRP_HWCSTART;
  extern volatile dword   *EMMA_DGRP_b0004120;
  extern volatile dword   *EMMA_DGRP_b0004138;
  extern volatile dword   *EMMA_DGRP_b0004148;
  extern volatile dword   *EMMA_DGRP_b000414c;
  extern volatile dword   *EMMA_DGRP_b0004150;
  extern volatile dword   *EMMA_DGRP_b0004154;

  //DALP = Alpha control
  extern volatile dword   *EMMA_DALP_ALPHA1;
  extern volatile dword   *EMMA_DALP_ALPHA2;
  extern volatile dword   *EMMA_DALP_ALPHA3;
  extern volatile dword   *EMMA_DALP_ALPHA4;
  extern volatile dword   *EMMA_DALP_ALPHA5;
  extern volatile dword   *EMMA_DALP_ALPHA6;
  extern volatile dword   *EMMA_DALP_ALPHA_CTR;
  extern volatile dword   *EMMA_DALP_BCKGND1;
  extern volatile dword   *EMMA_DALP_BORDER1;
  extern volatile dword   *EMMA_DALP_BCKGND2;
  extern volatile dword   *EMMA_DALP_BORDER2;
  extern volatile dword   *EMMA_DALP_FBLANK;
  extern volatile dword   *EMMA_DALP_ALPHALMT0;
  extern volatile dword   *EMMA_DALP_ALPHALMT1;
  extern volatile dword   *EMMA_DALP_ALPHALMT2;

  //DTCC = Display teletext and closed caption
  extern volatile dword   *EMMA_DTCC_TT_CC_CTR;
  extern volatile dword   *EMMA_DTCC_CC_DATA_CTR;
  extern volatile dword   *EMMA_DTCC_TT_CC_FIELD;


  //DSNC = Sync generator control
  extern volatile dword   *EMMA_DSNC_CTLFLG;
  extern volatile dword   *EMMA_DSNC_RELOAD;
  extern volatile dword   *EMMA_DSNC_SYNC1_HTOT;
  extern volatile dword   *EMMA_DSNC_SYNC1_HSYNC;
  extern volatile dword   *EMMA_DSNC_SYNC1_VTOT;
  extern volatile dword   *EMMA_DSNC_SYNC1_VSYNC;
  extern volatile dword   *EMMA_DSNC_SYNC1_V2SYNC;
  extern volatile dword   *EMMA_DSNC_SYNC1_HVOFF;
  extern volatile dword   *EMMA_DSNC_SYNC1_CTOFF;
  extern volatile dword   *EMMA_DSNC_SYNC1_HCUT1;
  extern volatile dword   *EMMA_DSNC_SYNC1_HCUT2;
  extern volatile dword   *EMMA_DSNC_SYNC2_HTOT;
  extern volatile dword   *EMMA_DSNC_SYNC2_HSYNC;
  extern volatile dword   *EMMA_DSNC_SYNC2_VTOT;
  extern volatile dword   *EMMA_DSNC_SYNC2_VSYNC;
  extern volatile dword   *EMMA_DSNC_SYNC2_V2SYNC;
  extern volatile dword   *EMMA_DSNC_SYNC2_HVOFF;
  extern volatile dword   *EMMA_DSNC_SYNC2_CTOFF;
  extern volatile dword   *EMMA_DSNC_SYNC2_HCUT1;
  extern volatile dword   *EMMA_DSNC_SYNC2_HCUT2;
  extern volatile dword   *EMMA_DSNC_SYNC_EXTRST;
  extern volatile dword   *EMMA_DSNC_SYNC3_HTOT;
  extern volatile dword   *EMMA_DSNC_SYNC3_HSYNC;
  extern volatile dword   *EMMA_DSNC_SYNC3_VTOT;
  extern volatile dword   *EMMA_DSNC_SYNC3_VSYNC;
  extern volatile dword   *EMMA_DSNC_SYNC3_V2SYNC;
  extern volatile dword   *EMMA_DSNC_VALID_TVC;
  extern volatile dword   *EMMA_DSNC_VALID_BVC;
  extern volatile dword   *EMMA_DSNC_VALID_HC;
  extern volatile dword   *EMMA_DSNC_SYNC1_VC12;
  extern volatile dword   *EMMA_DSNC_SYNC1_VC34;
  extern volatile dword   *EMMA_DSNC_SYNC2_VC12;
  extern volatile dword   *EMMA_DSNC_SYNC2_VC34;
  extern volatile dword   *EMMA_DSNC_SYNC3_VC12;
  extern volatile dword   *EMMA_DSNC_SYNC3_VC34;

  //DTOP = Timing, Global Control, and Interrupts
  extern volatile dword   *EMMA_DTOP_DSCL1_RELD;
  extern volatile dword   *EMMA_DTOP_DSCL2_RELD;
  extern volatile dword   *EMMA_DTOP_DSCL3_RELD;
  extern volatile dword   *EMMA_DTOP_DOSD1_RELD;
  extern volatile dword   *EMMA_DTOP_DOSD2_RELD;
  extern volatile dword   *EMMA_DTOP_DHWC_RELD;
  extern volatile dword   *EMMA_DTOP_DALP_RELD;
  extern volatile dword   *EMMA_DTOP_SYNC_SEL;
  extern volatile dword   *EMMA_DTOP_SYNC_SELST;
  extern volatile dword   *EMMA_DTOP_SYNC12_VFLD;
  extern volatile dword   *EMMA_DTOP_SYNC3_VFLD;
  extern volatile dword   *EMMA_DTOP_INT1_SEL;
  extern volatile dword   *EMMA_DTOP_INT1_EN;
  extern volatile dword   *EMMA_DTOP_STAT1_SEL;
  extern volatile dword   *EMMA_DTOP_INT2_SEL;
  extern volatile dword   *EMMA_DTOP_INT2_EN;
  extern volatile dword   *EMMA_DTOP_STAT2_SEL;
  extern volatile dword   *EMMA_DTOP_SOFT_RST;

  //GBLT
  extern volatile dword   *EMMA_GBLT_b0006000;
  extern volatile dword   *EMMA_GBLT_b0006004;
  extern volatile dword   *EMMA_GBLT_b0006008;
  extern volatile dword   *EMMA_GBLT_b000600c;
  extern volatile dword   *EMMA_GBLT_b0006010;
  extern volatile dword   *EMMA_GBLT_b0006014;
  extern volatile dword   *EMMA_GBLT_b0006018;
  extern volatile dword   *EMMA_GBLT_b000601c;
  extern volatile dword   *EMMA_GBLT_b0006020;
  extern volatile dword   *EMMA_GBLT_b0006024;
  extern volatile dword   *EMMA_GBLT_b0006028;
  extern volatile dword   *EMMA_GBLT_b000602c;
  extern volatile dword   *EMMA_GBLT_b0006030;
  extern volatile dword   *EMMA_GBLT_b0006034;
  extern volatile dword   *EMMA_GBLT_b0006038;
  extern volatile dword   *EMMA_GBLT_b000603c;
  extern volatile dword   *EMMA_GBLT_b0006040;
  extern volatile dword   *EMMA_GBLT_b0006044;
  extern volatile dword   *EMMA_GBLT_b0006048;
  extern volatile dword   *EMMA_GBLT_b000604c;
  extern volatile dword   *EMMA_GBLT_b0006050;
  extern volatile dword   *EMMA_GBLT_b0006054;
  extern volatile dword   *EMMA_GBLT_b0006058;
  extern volatile dword   *EMMA_GBLT_b000605c;
  extern volatile dword   *EMMA_GBLT_b0006060;
  extern volatile dword   *EMMA_GBLT_b0006064;
  extern volatile dword   *EMMA_GBLT_b0006068;
  extern volatile dword   *EMMA_GBLT_b000606c;
  extern volatile dword   *EMMA_GBLT_b0006074;
  extern volatile dword   *EMMA_GBLT_b0006078;
  extern volatile dword   *EMMA_GBLT_b000607c;
  extern volatile dword   *EMMA_GBLT_b0006080;
  extern volatile dword   *EMMA_GBLT_b0006084;
  extern volatile dword   *EMMA_GBLT_b0006088;
  extern volatile dword   *EMMA_GBLT_b000608c;

  extern volatile dword   *EMMA_GDVI;;

  //AUD = Audio Interface
  extern volatile dword   *EMMA_AUD_DDB0;
  extern volatile dword   *EMMA_AUD_ASM;
  extern volatile dword   *EMMA_AUD_RAMADR;
  extern volatile dword   *EMMA_AUD_RAMDAT;
  extern volatile dword   *EMMA_AUD_DPUTSTA0;
  extern volatile dword   *EMMA_AUD_DPUTSTA1;
  extern volatile dword   *EMMA_AUD_DPUTSTA2;
  extern volatile dword   *EMMA_AUD_DPUTSDA0;
  extern volatile dword   *EMMA_AUD_DPUTSDA1;
  extern volatile dword   *EMMA_AUD_DPUTSDA2;
  extern volatile dword   *EMMA_AUD_SPUTSTA0;
  extern volatile dword   *EMMA_AUD_SPUTSTA1;
  extern volatile dword   *EMMA_AUD_SPUTSTA2;
  extern volatile dword   *EMMA_AUD_SPUTSDA0;
  extern volatile dword   *EMMA_AUD_SPUTSDA1;
  extern volatile dword   *EMMA_AUD_SPUTSDA2;
  extern volatile dword   *EMMA_AUD_TSEN;
  extern volatile dword   *EMMA_AUD_RST;
  extern volatile dword   *EMMA_AUD_INT;
  extern volatile dword   *EMMA_AUD_INTEN;
  extern volatile dword   *EMMA_AUD_INTSTA;
  extern volatile dword   *EMMA_AUD_SICTRL;
  extern volatile dword   *EMMA_AUD_ESIFORM;
  extern volatile dword   *EMMA_AUD_ESICTRL;
  extern volatile dword   *EMMA_AUD_b0007138;
  extern volatile dword   *EMMA_AUD_SPDCTRL;
  extern volatile dword   *EMMA_AUD_SPDCHSTA1;
  extern volatile dword   *EMMA_AUD_SPDCHSTA2;


  //Video Encoder
  extern volatile dword   *EMMA_VENC_b0008000;
  extern volatile dword   *EMMA_VENC_b0008004;
  extern volatile dword   *EMMA_VENC_b0008008;
  extern volatile dword   *EMMA_VENC_b000800c;
  extern volatile dword   *EMMA_VENC_VEE_CTR1;
  extern volatile dword   *EMMA_VENC_VEE_CTR2;
  extern volatile dword   *EMMA_VENC_VEE_CTR3;
  extern volatile dword   *EMMA_VENC_VEE_CTR4;
  extern volatile dword   *EMMA_VENC_VEE_CTR5;
  extern volatile dword   *EMMA_VENC_VEE_CTR6;
  extern volatile dword   *EMMA_VENC_VEE_CTR7;
  extern volatile dword   *EMMA_VENC_VEE_TTE1;
  extern volatile dword   *EMMA_VENC_VEE_TTE2;
  extern volatile dword   *EMMA_VENC_VEE_SECAM1;
  extern volatile dword   *EMMA_VENC_VEE_SECAM2;
  extern volatile dword   *EMMA_VENC_VEE_CTR8_DBG;
  extern volatile dword   *EMMA_VENC_VEE_CTR9;
  extern volatile dword   *EMMA_VENC_VEE_CTR10;
  extern volatile dword   *EMMA_VENC_VEE_VID_WSS;
  extern volatile dword   *EMMA_VENC_VEE_CC1;
  extern volatile dword   *EMMA_VENC_VEE_CC2;
  extern volatile dword   *EMMA_VENC_VEE_TTE3;

  //XDMA = DMA Controller
  extern volatile dword   *EMMA_XDMA_SOFT_RST;
  extern volatile dword   *EMMA_XDMA_VBUF_RST;
  extern volatile dword   *EMMA_XDMA_ABUF_RST;
  extern volatile dword   *EMMA_XDMA_LIST_RST;
  extern volatile dword   *EMMA_XDMA_REQ_ENA_VBUF;
  extern volatile dword   *EMMA_XDMA_REQ_ENA_ABUF;
  extern volatile dword   *EMMA_XDMA_REQ_ENA_LIST;
  extern volatile dword   *EMMA_XDMA_REQ_MASK;
  extern volatile dword   *EMMA_XDMA_PRI_CHSEL1;
  extern volatile dword   *EMMA_XDMA_PRI_CHSEL2;
  extern volatile dword   *EMMA_XDMA_PRI_WAIT_LIMIT1;
  extern volatile dword   *EMMA_XDMA_PRI_WAIT_LIMIT2;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_PCM_R;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_PCM_W;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_IDE_R;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_IDE_W;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_GIO_R;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_GIO_W;
  extern volatile dword   *EMMA_XDMA_LIST_PTR_MEM;
  extern volatile dword   *EMMA_XDMA_VBUF0_ADR;
  extern volatile dword   *EMMA_XDMA_VBUF1_ADR;
  extern volatile dword   *EMMA_XDMA_VBUF_STILL_ADR;
  extern volatile dword   *EMMA_XDMA_VBUF_RPTR_MAIN;
  extern volatile dword   *EMMA_XDMA_VBUF_RPTR_SUB;
  extern volatile dword   *EMMA_XDMA_VBUF0_CUR_NUM;
  extern volatile dword   *EMMA_XDMA_VBUF0_NFUL_LVL;
  extern volatile dword   *EMMA_XDMA_VBUF0_FULL_LVL;
  extern volatile dword   *EMMA_XDMA_VBUF0_NEMP_LVL;
  extern volatile dword   *EMMA_XDMA_VBUF1_CUR_NUM;
  extern volatile dword   *EMMA_XDMA_VBUF1_NFUL_LVL;
  extern volatile dword   *EMMA_XDMA_VBUF1_FULL_LVL;
  extern volatile dword   *EMMA_XDMA_VBUF1_NEMP_LVL;
  extern volatile dword   *EMMA_XDMA_VBUF_CUR_NUM_ADJ;
  extern volatile dword   *EMMA_XDMA_VBUF0_V_WPTR;
  extern volatile dword   *EMMA_XDMA_VBUF1_V_WPTR;
  extern volatile dword   *EMMA_XDMA_ABUF0_ADR;
  extern volatile dword   *EMMA_XDMA_ABUF1_ADR;
  extern volatile dword   *EMMA_XDMA_ABUF0_RPTR;
  extern volatile dword   *EMMA_XDMA_ABUF1_RPTR;
  extern volatile dword   *EMMA_XDMA_ABUF0_CUR_NUM;
  extern volatile dword   *EMMA_XDMA_ABUF0_NFUL_LVL;
  extern volatile dword   *EMMA_XDMA_ABUF0_FULL_LVL;
  extern volatile dword   *EMMA_XDMA_ABUF0_NEMP_LVL;
  extern volatile dword   *EMMA_XDMA_ABUF1_CUR_NUM;
  extern volatile dword   *EMMA_XDMA_ABUF1_NFUL_LVL;
  extern volatile dword   *EMMA_XDMA_ABUF1_FULL_LVL;
  extern volatile dword   *EMMA_XDMA_ABUF1_NEMP_LVL;
  extern volatile dword   *EMMA_XDMA_TRANS_STAT;
  extern volatile dword   *EMMA_XDMA_PCM_R_COMMAND;
  extern volatile dword   *EMMA_XDMA_PCM_R_STATUS;
  extern volatile dword   *EMMA_XDMA_PCM_R_PTR;
  extern volatile dword   *EMMA_XDMA_PCM_R_BUF_STA_ADR;
  extern volatile dword   *EMMA_XDMA_PCM_R_BUF_END_ADR;
  extern volatile dword   *EMMA_XDMA_PCM_W_COMMAND;
  extern volatile dword   *EMMA_XDMA_PCM_W_STATUS;
  extern volatile dword   *EMMA_XDMA_PCM_W_PTR;
  extern volatile dword   *EMMA_XDMA_PCM_W_BUF_STA_ADR;
  extern volatile dword   *EMMA_XDMA_PCM_W_BUF_END_ADR;
  extern volatile dword   *EMMA_XDMA_PCM_R_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_PCM_W_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_IDE_R_COMMAND;
  extern volatile dword   *EMMA_XDMA_IDE_R_STATUS;
  extern volatile dword   *EMMA_XDMA_IDE_R_PTR;
  extern volatile dword   *EMMA_XDMA_IDE_R_BUF_STA_ADR;
  extern volatile dword   *EMMA_XDMA_IDE_R_BUF_END_ADR;
  extern volatile dword   *EMMA_XDMA_IDE_W_COMMAND;
  extern volatile dword   *EMMA_XDMA_IDE_W_STATUS;
  extern volatile dword   *EMMA_XDMA_IDE_W_PTR;
  extern volatile dword   *EMMA_XDMA_IDE_W_BUF_STA_ADR;
  extern volatile dword   *EMMA_XDMA_IDE_W_BUF_END_ADR;
  extern volatile dword   *EMMA_XDMA_IDE_R_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_IDE_W_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_GIO_R_COMMAND;
  extern volatile dword   *EMMA_XDMA_GIO_R_STATUS;
  extern volatile dword   *EMMA_XDMA_GIO_R_PTR;
  extern volatile dword   *EMMA_XDMA_GIO_R_BUF_STA_ADR;
  extern volatile dword   *EMMA_XDMA_GIO_R_BUF_END_ADR;
  extern volatile dword   *EMMA_XDMA_GIO_W_COMMAND;
  extern volatile dword   *EMMA_XDMA_GIO_W_STATUS;
  extern volatile dword   *EMMA_XDMA_GIO_W_PTR;
  extern volatile dword   *EMMA_XDMA_GIO_W_BUF_STA_ADR;
  extern volatile dword   *EMMA_XDMA_GIO_W_BUF_END_ADR;
  extern volatile dword   *EMMA_XDMA_GIO_R_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_GIO_W_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_MEM_DMA_START;
  extern volatile dword   *EMMA_XDMA_MEM_COMMAND;
  extern volatile dword   *EMMA_XDMA_MEM_STATUS;
  extern volatile dword   *EMMA_XDMA_MEM_SRC_PTR;
  extern volatile dword   *EMMA_XDMA_MEM_DEST_PTR;
  extern volatile dword   *EMMA_XDMA_MEM_SRC_STA_ADR;
  extern volatile dword   *EMMA_XDMA_MEM_DEST_STA_ADR;
  extern volatile dword   *EMMA_XDMA_MEM_END_ADR;
  extern volatile dword   *EMMA_XDMA_MEM_DEF_SIZE;
  extern volatile dword   *EMMA_XDMA_MEM_SRC_SKIP;
  extern volatile dword   *EMMA_XDMA_MEM_DEST_SKIP;
  extern volatile dword   *EMMA_XDMA_MEM_NEXT_LIST;
  extern volatile dword   *EMMA_XDMA_REQ_STAT_VBUF;
  extern volatile dword   *EMMA_XDMA_REQ_STAT_ABUF;
  extern volatile dword   *EMMA_XDMA_REQ_STAT_LIST;
  extern volatile dword   *EMMA_XDMA_LOAD_LIST;
  extern volatile dword   *EMMA_XDMA_LIST_END_STAT;
  extern volatile dword   *EMMA_XDMA_LIST_ERROR_STAT;
  extern volatile dword   *EMMA_XDMA_REQ_ERROR_STAT;
  extern volatile dword   *EMMA_XDMA_BUF_OVERFLOW;
  extern volatile dword   *EMMA_XDMA_INT;
  extern volatile dword   *EMMA_XDMA_INT_EN;
  extern volatile dword   *EMMA_XDMA_INT_STAT;

  //TTSD
  extern volatile dword   *EMMA_TTSD_CNT;
  extern volatile dword   *EMMA_TTSD_CHA_CNT;
  extern volatile dword   *EMMA_TTSD_CHB_CNT;
  extern volatile dword   *EMMA_TTSD_CHC_CNT;
  extern volatile dword   *EMMA_TTSD_HSD_CNT;
  extern volatile dword   *EMMA_TTSD_HSD_MODE;
  extern volatile dword   *EMMA_TTSD_ADAPTATION_SYNC_MODE;
  extern volatile dword   *EMMA_TTSD_CPU_STREAM_INPUT_PORT;
  extern volatile dword   *EMMA_TTSD_1ST_PCR_PID;
  extern volatile dword   *EMMA_TTSD_2ND_PCR_PID;
  extern volatile dword   *EMMA_TTSD_PID_0;
  extern volatile dword   *EMMA_TTSD_PID_1;
  extern volatile dword   *EMMA_TTSD_PID_2;
  extern volatile dword   *EMMA_TTSD_PID_3;
  extern volatile dword   *EMMA_TTSD_PID_4;
  extern volatile dword   *EMMA_TTSD_PID_5;
  extern volatile dword   *EMMA_TTSD_PID_6;
  extern volatile dword   *EMMA_TTSD_PID_7;
  extern volatile dword   *EMMA_TTSD_PID_8;
  extern volatile dword   *EMMA_TTSD_PID_9;
  extern volatile dword   *EMMA_TTSD_PID_10;
  extern volatile dword   *EMMA_TTSD_PID_11;
  extern volatile dword   *EMMA_TTSD_PID_12;
  extern volatile dword   *EMMA_TTSD_PID_13;
  extern volatile dword   *EMMA_TTSD_PID_14;
  extern volatile dword   *EMMA_TTSD_PID_15;
  extern volatile dword   *EMMA_TTSD_PID_16;
  extern volatile dword   *EMMA_TTSD_PID_17;
  extern volatile dword   *EMMA_TTSD_PID_18;
  extern volatile dword   *EMMA_TTSD_PID_19;
  extern volatile dword   *EMMA_TTSD_PID_20;
  extern volatile dword   *EMMA_TTSD_PID_21;
  extern volatile dword   *EMMA_TTSD_PID_22;
  extern volatile dword   *EMMA_TTSD_PID_23;
  extern volatile dword   *EMMA_TTSD_PID_24;
  extern volatile dword   *EMMA_TTSD_PID_25;
  extern volatile dword   *EMMA_TTSD_PID_26;
  extern volatile dword   *EMMA_TTSD_PID_27;
  extern volatile dword   *EMMA_TTSD_PID_28;
  extern volatile dword   *EMMA_TTSD_PID_29;
  extern volatile dword   *EMMA_TTSD_PID_30;
  extern volatile dword   *EMMA_TTSD_PID_31;
  extern volatile dword   *EMMA_TTSD_PID_32;
  extern volatile dword   *EMMA_TTSD_PID_33;
  extern volatile dword   *EMMA_TTSD_PID_34;
  extern volatile dword   *EMMA_TTSD_PID_35;
  extern volatile dword   *EMMA_TTSD_PID_36;
  extern volatile dword   *EMMA_TTSD_PID_37;
  extern volatile dword   *EMMA_TTSD_PID_38;
  extern volatile dword   *EMMA_TTSD_PID_39;
  extern volatile dword   *EMMA_TTSD_PID_40;
  extern volatile dword   *EMMA_TTSD_PID_41;
  extern volatile dword   *EMMA_TTSD_PID_42;
  extern volatile dword   *EMMA_TTSD_PID_43;
  extern volatile dword   *EMMA_TTSD_PID_44;
  extern volatile dword   *EMMA_TTSD_PID_45;
  extern volatile dword   *EMMA_TTSD_PID_46;
  extern volatile dword   *EMMA_TTSD_PID_47;
  extern volatile dword   *EMMA_TTSD_1ST_VIDEO_PID;
  extern volatile dword   *EMMA_TTSD_2ND_VIDEO_PID;
  extern volatile dword   *EMMA_TTSD_1ST_AUDIO_PID;
  extern volatile dword   *EMMA_TTSD_2ND_AUDIO_PID;
  extern volatile dword   *EMMA_TTSD_AV_PID_CNT;
  extern volatile dword   *EMMA_TTSD_CWP_CNT;
  extern volatile dword   *EMMA_TTSD_CWP_STORAGE_MODE;
  extern volatile dword   *EMMA_TTSD_CWP_STORAGE_LOCK;
  extern volatile dword   *EMMA_TTSD_SYNC_STATUS;
  extern volatile dword   *EMMA_TTSD_PWM_DATA;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT1;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT2;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT3;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT4;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_INTERRUPT1;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_INTERRUPT2;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_INTERRUPT3;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_INTERRUPT4;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT1;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT2;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT3;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT1;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT2;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT3;
  extern volatile dword   *EMMA_TTSD_OTHER_INTERRUPT1;
  extern volatile dword   *EMMA_TTSD_OTHER_INTERRUPT2;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK1;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK2;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK3;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK4;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_MASK1;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_MASK2;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_MASK3;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_MASK4;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK1;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK2;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK3;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK1;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK2;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK3;
  extern volatile dword   *EMMA_TTSD_OTHER_INTERRUPT_MASK1;
  extern volatile dword   *EMMA_TTSD_OTHER_INTERRUPT_MASK2;
  extern volatile dword   *EMMA_TTSD_SECF_MOD;
  extern volatile dword   *EMMA_TTSD_PID_STOP1;
  extern volatile dword   *EMMA_TTSD_PID_STOP2;
  extern volatile dword   *EMMA_TTSD_APG_HEADER_ERROR_DETECT_MODE;
  extern volatile dword   *EMMA_TTSD_APG_CHECK;
  extern volatile dword   *EMMA_TTSD_SECF_CNT;
  extern volatile dword   *EMMA_TTSD_SECF_DAT;
  extern volatile dword   *EMMA_TTSD_GPF_STARTBIT;
  extern volatile dword   *EMMA_TTSD_SEC_NOTEQ_CNT0;
  extern volatile dword   *EMMA_TTSD_SEC_NOTEQ_CNT1;
  extern volatile dword   *EMMA_TTSD_SEC_NOTEQ_CNT2;
  extern volatile dword   *EMMA_TTSD_SEC_NOTEQ_CNT3;
  extern volatile dword   *EMMA_TTSD_TS_HEADER0;
  extern volatile dword   *EMMA_TTSD_TS_HEADER1;
  extern volatile dword   *EMMA_TTSD_TS_HEADER2;
  extern volatile dword   *EMMA_TTSD_TS_HEADER3;
  extern volatile dword   *EMMA_TTSD_PESF_MODE;
  extern volatile dword   *EMMA_TTSD_PESF_CNT;
  extern volatile dword   *EMMA_TTSD_PESF_DAT;
  extern volatile dword   *EMMA_TTSD_PTS_DTS_MSB;
  extern volatile dword   *EMMA_TTSD_PS_PTS_CNT;
  extern volatile dword   *EMMA_TTSD_PS_PTSL;
  extern volatile dword   *EMMA_TTSD_PS_PTSH;
  extern volatile dword   *EMMA_TTSD_PS_PTS_ADR;
  extern volatile dword   *EMMA_TTSD_INTERNAL_STC_MATCH;
  extern volatile dword   *EMMA_TTSD_1ST_PCR_CNT;
  extern volatile dword   *EMMA_TTSD_1ST_PCR1;
  extern volatile dword   *EMMA_TTSD_1ST_PCR2;
  extern volatile dword   *EMMA_TTSD_1ST_STC1;
  extern volatile dword   *EMMA_TTSD_1ST_STC2;
  extern volatile dword   *EMMA_TTSD_LATCHED_1ST_STC1;
  extern volatile dword   *EMMA_TTSD_LATCHED_1ST_STC2;
  extern volatile dword   *EMMA_TTSD_2ND_PCR_CNT;
  extern volatile dword   *EMMA_TTSD_2ND_PCR1;
  extern volatile dword   *EMMA_TTSD_2ND_PCR2;
  extern volatile dword   *EMMA_TTSD_2ND_STC1;
  extern volatile dword   *EMMA_TTSD_2ND_STC2;
  extern volatile dword   *EMMA_TTSD_ELEMENTARY_SEARCH_CNT;
  extern volatile dword   *EMMA_TTSD_MATCH_CODEA;
  extern volatile dword   *EMMA_TTSD_MATCH_CODEB;
  extern volatile dword   *EMMA_TTSD_CODE1_ADDRESS_VBV1;
  extern volatile dword   *EMMA_TTSD_CODE2_ADDRESS_VBV1;
  extern volatile dword   *EMMA_TTSD_CODE3_ADDRESS_VBV1;
  extern volatile dword   *EMMA_TTSD_CODE4_ADDRESS_VBV1;
  extern volatile dword   *EMMA_TTSD_CODE5_ADDRESS_VBV1;
  extern volatile dword   *EMMA_TTSD_CODE6_ADDRESS_VBV1;
  extern volatile dword   *EMMA_TTSD_CODE1_ADDRESS_VBV2;
  extern volatile dword   *EMMA_TTSD_CODE2_ADDRESS_VBV2;
  extern volatile dword   *EMMA_TTSD_CODE3_ADDRESS_VBV2;
  extern volatile dword   *EMMA_TTSD_CODE4_ADDRESS_VBV2;
  extern volatile dword   *EMMA_TTSD_CODE5_ADDRESS_VBV2;
  extern volatile dword   *EMMA_TTSD_CODE6_ADDRESS_VBV2;
  extern volatile dword   *EMMA_TTSD_PICTURE_CODE_TYPE_VBV1;
  extern volatile dword   *EMMA_TTSD_PICTURE_CODE_TYPE_VBV2;
  extern volatile dword   *EMMA_TTSD_PICTURE_STRUCTURE_VBV12;
  extern volatile dword   *EMMA_TTSD_VPID_PTSDTS_CNT;
  extern volatile dword   *EMMA_TTSD_b000a342;
  extern volatile dword   *EMMA_TTSD_b000a343;
  extern volatile dword   *EMMA_TTSD_VPID_PTSDTS_STATUS;
  extern volatile dword   *EMMA_TTSD_PTS_1STVPIDL;
  extern volatile dword   *EMMA_TTSD_PTS_1STVPIDH;
  extern volatile dword   *EMMA_TTSD_DTS_1STVPIDL;
  extern volatile dword   *EMMA_TTSD_DTS_1STVPIDH;
  extern volatile dword   *EMMA_TTSD_1STVPID_PTSDTS_ADDRESS;
  extern volatile dword   *EMMA_TTSD_PTS_2NDVPIDL;
  extern volatile dword   *EMMA_TTSD_PTS_2NDVPIDH;
  extern volatile dword   *EMMA_TTSD_DTS_2NDVPIDL;
  extern volatile dword   *EMMA_TTSD_DTS_2NDVPIDH;
  extern volatile dword   *EMMA_TTSD_2NDVPID_PTSDTS_ADDRESS;
  extern volatile dword   *EMMA_TTSD_VPID_TRICK;
  extern volatile dword   *EMMA_TTSD_ELEMENTARY_INTERRUPT;
  extern volatile dword   *EMMA_TTSD_ELEMENTARY_INTERRUPT_MASK;
  extern volatile dword   *EMMA_TTSD_TIMER;
  extern volatile dword   *EMMA_TTSD_TIMER_CNT;
  extern volatile dword   *EMMA_TTSD_MIF_CNT;
  extern volatile dword   *EMMA_TTSD_POINTER_BASE;
  extern volatile dword   *EMMA_TTSD_SR_CMD;
  extern volatile dword   *EMMA_TTSD_SR_PKT_CNT;
  extern volatile dword   *EMMA_TTSD_SR_PID_0;
  extern volatile dword   *EMMA_TTSD_SR_PID_1;
  extern volatile dword   *EMMA_TTSD_SR_PID_2;
  extern volatile dword   *EMMA_TTSD_SR_PID_3;
  extern volatile dword   *EMMA_TTSD_SR_PID_4;
  extern volatile dword   *EMMA_TTSD_SR_PID_5;
  extern volatile dword   *EMMA_TTSD_SR_PID_6;
  extern volatile dword   *EMMA_TTSD_SR_PID_7;
  extern volatile dword   *EMMA_TTSD_SR_PID_8;
  extern volatile dword   *EMMA_TTSD_SR_PID_9;
  extern volatile dword   *EMMA_TTSD_SR_PID_10;
  extern volatile dword   *EMMA_TTSD_SR_PID_11;
  extern volatile dword   *EMMA_TTSD_SR_PID_12;
  extern volatile dword   *EMMA_TTSD_SR_PID_13;
  extern volatile dword   *EMMA_TTSD_SR_PID_14;
  extern volatile dword   *EMMA_TTSD_SR_PID_15;
  extern volatile dword   *EMMA_TTSD_SR_PID_16;
  extern volatile dword   *EMMA_TTSD_SR_PID_17;
  extern volatile dword   *EMMA_TTSD_SR_PID_18;
  extern volatile dword   *EMMA_TTSD_SR_PID_19;
  extern volatile dword   *EMMA_TTSD_SR_PID_20;
  extern volatile dword   *EMMA_TTSD_SR_PID_21;
  extern volatile dword   *EMMA_TTSD_SR_PID_22;
  extern volatile dword   *EMMA_TTSD_SR_PID_23;
  extern volatile dword   *EMMA_TTSD_SR_PID_24;
  extern volatile dword   *EMMA_TTSD_SR_PID_25;
  extern volatile dword   *EMMA_TTSD_SR_PID_26;
  extern volatile dword   *EMMA_TTSD_SR_PID_27;
  extern volatile dword   *EMMA_TTSD_SR_PID_28;
  extern volatile dword   *EMMA_TTSD_SR_PID_29;
  extern volatile dword   *EMMA_TTSD_SR_PID_30;
  extern volatile dword   *EMMA_TTSD_SR_PID_31;
  extern volatile dword   *EMMA_TTSD_SR_WRBUF_STRT;
  extern volatile dword   *EMMA_TTSD_SR_WRITE_POINTER0;
  extern volatile dword   *EMMA_TTSD_SR_TRANSFER_REQUEST_POINTER0;
  extern volatile dword   *EMMA_TTSD_SR_END_POINTER0;
  extern volatile dword   *EMMA_TTSD_SR_WRITE_POINTER1;
  extern volatile dword   *EMMA_TTSD_SR_TRANSFER_REQUEST_POINTER1;
  extern volatile dword   *EMMA_TTSD_SR_END_POINTER1;
  extern volatile dword   *EMMA_TTSD_SR_INTERRUPT;
  extern volatile dword   *EMMA_TTSD_SR_INTERRUPT_MASK;
  extern volatile dword   *EMMA_TTSD_SR_ADAPTATION;
  extern volatile dword   *EMMA_TTSD_EL_RTS_COUNTER;
  extern volatile dword   *EMMA_TTSD_EL_RTS_CNT;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_0;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_1;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_2;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_3;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_4;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_5;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_6;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_7;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_8;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_9;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_10;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_11;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_12;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_13;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_14;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_15;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_16;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_17;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_18;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_19;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_20;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_21;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_22;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_23;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_24;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_25;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_26;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_27;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_28;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_29;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_30;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EN_31;
  extern volatile dword   *EMMA_TTSD_EL_WRBUF_STRT;
  extern volatile dword   *EMMA_TTSD_EL_WRITE_POINTER0;
  extern volatile dword   *EMMA_TTSD_EL_NEARLY_FULL_POINTER0;
  extern volatile dword   *EMMA_TTSD_EL_END_POINTER0;
  extern volatile dword   *EMMA_TTSD_EL_WRITE_POINTER1;
  extern volatile dword   *EMMA_TTSD_EL_NEARLY_FULL_POINTER1;
  extern volatile dword   *EMMA_TTSD_EL_END_POINTER1;
  extern volatile dword   *EMMA_TTSD_EL_INTERRUPT;
  extern volatile dword   *EMMA_TTSD_EL_INTERRUPT_MASK;
  extern volatile dword   *EMMA_TTSD_PKT_COUNTER_0;
  extern volatile dword   *EMMA_TTSD_PKT_COUNTER_1;
  extern volatile dword   *EMMA_TTSD_PB_MODE0;
  extern volatile dword   *EMMA_TTSD_PB_MODE1;
  extern volatile dword   *EMMA_TTSD_PB_START_ADDRESS_A;
  extern volatile dword   *EMMA_TTSD_PB_LEN_A;
  extern volatile dword   *EMMA_TTSD_PB_START_ADDRESS_B;
  extern volatile dword   *EMMA_TTSD_PB_LEN_B;
  extern volatile dword   *EMMA_TTSD_PB_CURR_ADDRESS;
  extern volatile dword   *EMMA_TTSD_PB_STATUS;
  extern volatile dword   *EMMA_TTSD_PB_INTERRUPT;
  extern volatile dword   *EMMA_TTSD_PB_INTERRUPT_MASK;
  extern volatile dword   *EMMA_TTSD_PID_48;
  extern volatile dword   *EMMA_TTSD_PID_49;
  extern volatile dword   *EMMA_TTSD_PID_50;
  extern volatile dword   *EMMA_TTSD_PID_51;
  extern volatile dword   *EMMA_TTSD_PID_52;
  extern volatile dword   *EMMA_TTSD_PID_53;
  extern volatile dword   *EMMA_TTSD_PID_54;
  extern volatile dword   *EMMA_TTSD_PID_55;
  extern volatile dword   *EMMA_TTSD_PID_56;
  extern volatile dword   *EMMA_TTSD_PID_57;
  extern volatile dword   *EMMA_TTSD_PID_58;
  extern volatile dword   *EMMA_TTSD_PID_59;
  extern volatile dword   *EMMA_TTSD_PID_60;
  extern volatile dword   *EMMA_TTSD_PID_61;
  extern volatile dword   *EMMA_TTSD_PID_62;
  extern volatile dword   *EMMA_TTSD_PID_63;
  extern volatile dword   *EMMA_TTSD_PID_64;
  extern volatile dword   *EMMA_TTSD_PID_65;
  extern volatile dword   *EMMA_TTSD_PID_66;
  extern volatile dword   *EMMA_TTSD_PID_67;
  extern volatile dword   *EMMA_TTSD_PID_68;
  extern volatile dword   *EMMA_TTSD_PID_69;
  extern volatile dword   *EMMA_TTSD_PID_70;
  extern volatile dword   *EMMA_TTSD_PID_71;
  extern volatile dword   *EMMA_TTSD_PID_72;
  extern volatile dword   *EMMA_TTSD_PID_73;
  extern volatile dword   *EMMA_TTSD_PID_74;
  extern volatile dword   *EMMA_TTSD_PID_75;
  extern volatile dword   *EMMA_TTSD_PID_76;
  extern volatile dword   *EMMA_TTSD_PID_77;
  extern volatile dword   *EMMA_TTSD_PID_78;
  extern volatile dword   *EMMA_TTSD_PID_79;
  extern volatile dword   *EMMA_TTSD_PID_80;
  extern volatile dword   *EMMA_TTSD_PID_81;
  extern volatile dword   *EMMA_TTSD_PID_82;
  extern volatile dword   *EMMA_TTSD_PID_83;
  extern volatile dword   *EMMA_TTSD_PID_84;
  extern volatile dword   *EMMA_TTSD_PID_85;
  extern volatile dword   *EMMA_TTSD_PID_86;
  extern volatile dword   *EMMA_TTSD_PID_87;
  extern volatile dword   *EMMA_TTSD_PID_88;
  extern volatile dword   *EMMA_TTSD_PID_89;
  extern volatile dword   *EMMA_TTSD_PID_90;
  extern volatile dword   *EMMA_TTSD_PID_91;
  extern volatile dword   *EMMA_TTSD_PID_92;
  extern volatile dword   *EMMA_TTSD_PID_93;
  extern volatile dword   *EMMA_TTSD_PID_94;
  extern volatile dword   *EMMA_TTSD_PID_95;
  extern volatile dword   *EMMA_TTSD_PID_EXT_0;
  extern volatile dword   *EMMA_TTSD_PID_EXT_1;
  extern volatile dword   *EMMA_TTSD_PID_EXT_2;
  extern volatile dword   *EMMA_TTSD_PID_EXT_3;
  extern volatile dword   *EMMA_TTSD_PID_EXT_4;
  extern volatile dword   *EMMA_TTSD_PID_EXT_5;
  extern volatile dword   *EMMA_TTSD_PID_EXT_6;
  extern volatile dword   *EMMA_TTSD_PID_EXT_7;
  extern volatile dword   *EMMA_TTSD_PID_EXT_8;
  extern volatile dword   *EMMA_TTSD_PID_EXT_9;
  extern volatile dword   *EMMA_TTSD_PID_EXT_10;
  extern volatile dword   *EMMA_TTSD_PID_EXT_11;
  extern volatile dword   *EMMA_TTSD_PID_EXT_12;
  extern volatile dword   *EMMA_TTSD_PID_EXT_13;
  extern volatile dword   *EMMA_TTSD_PID_EXT_14;
  extern volatile dword   *EMMA_TTSD_PID_EXT_15;
  extern volatile dword   *EMMA_TTSD_PID_EXT_16;
  extern volatile dword   *EMMA_TTSD_PID_EXT_17;
  extern volatile dword   *EMMA_TTSD_PID_EXT_18;
  extern volatile dword   *EMMA_TTSD_PID_EXT_19;
  extern volatile dword   *EMMA_TTSD_PID_EXT_20;
  extern volatile dword   *EMMA_TTSD_PID_EXT_21;
  extern volatile dword   *EMMA_TTSD_PID_EXT_22;
  extern volatile dword   *EMMA_TTSD_PID_EXT_23;
  extern volatile dword   *EMMA_TTSD_PID_EXT_24;
  extern volatile dword   *EMMA_TTSD_PID_EXT_25;
  extern volatile dword   *EMMA_TTSD_PID_EXT_26;
  extern volatile dword   *EMMA_TTSD_PID_EXT_27;
  extern volatile dword   *EMMA_TTSD_PID_EXT_28;
  extern volatile dword   *EMMA_TTSD_PID_EXT_29;
  extern volatile dword   *EMMA_TTSD_PID_EXT_30;
  extern volatile dword   *EMMA_TTSD_PID_EXT_31;
  extern volatile dword   *EMMA_TTSD_PID_EXT_32;
  extern volatile dword   *EMMA_TTSD_PID_EXT_33;
  extern volatile dword   *EMMA_TTSD_PID_EXT_34;
  extern volatile dword   *EMMA_TTSD_PID_EXT_35;
  extern volatile dword   *EMMA_TTSD_PID_EXT_36;
  extern volatile dword   *EMMA_TTSD_PID_EXT_37;
  extern volatile dword   *EMMA_TTSD_PID_EXT_38;
  extern volatile dword   *EMMA_TTSD_PID_EXT_39;
  extern volatile dword   *EMMA_TTSD_PID_EXT_40;
  extern volatile dword   *EMMA_TTSD_PID_EXT_41;
  extern volatile dword   *EMMA_TTSD_PID_EXT_42;
  extern volatile dword   *EMMA_TTSD_PID_EXT_43;
  extern volatile dword   *EMMA_TTSD_PID_EXT_44;
  extern volatile dword   *EMMA_TTSD_PID_EXT_45;
  extern volatile dword   *EMMA_TTSD_PID_EXT_46;
  extern volatile dword   *EMMA_TTSD_PID_EXT_47;
  extern volatile dword   *EMMA_TTSD_PS_CNT;
  extern volatile dword   *EMMA_TTSD_PIC_HDR_CNT;
  extern volatile dword   *EMMA_TTSD_1STV_PIC0_COUNTER;
  extern volatile dword   *EMMA_TTSD_1STV_PIC1_COUNTER;
  extern volatile dword   *EMMA_TTSD_1STV_PIC2_COUNTER;
  extern volatile dword   *EMMA_TTSD_1STV_HDR0_COUNTER;
  extern volatile dword   *EMMA_TTSD_1STV_HDR1_COUNTER;
  extern volatile dword   *EMMA_TTSD_1STV_HDR2_COUNTER;
  extern volatile dword   *EMMA_TTSD_2NDV_PIC0_COUNTER;
  extern volatile dword   *EMMA_TTSD_2NDV_PIC1_COUNTER;
  extern volatile dword   *EMMA_TTSD_2NDV_PIC2_COUNTER;
  extern volatile dword   *EMMA_TTSD_2NDV_HDR0_COUNTER;
  extern volatile dword   *EMMA_TTSD_2NDV_HDR1_COUNTER;
  extern volatile dword   *EMMA_TTSD_2NDV_HDR2_COUNTER;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_0;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_1;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_2;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_3;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_4;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_5;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_6;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_7;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_8;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_9;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_10;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_11;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_12;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_13;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_14;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_15;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_16;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_17;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_18;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_19;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_20;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_21;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_22;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_23;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_24;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_25;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_26;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_27;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_28;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_29;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_30;
  extern volatile dword   *EMMA_TTSD_SR_PID_EXT_31;
  extern volatile dword   *EMMA_TTSD_GENERAL_PID_EL_EXT_EN_CNT;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EXT_EN_0;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EXT_EN_1;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EXT_EN_2;
  extern volatile dword   *EMMA_TTSD_EL_EVENT_EXT_EN_3;
  extern volatile dword   *EMMA_TTSD_PB_PKT_INTERVAL_TIMER_CNT;
  extern volatile dword   *EMMA_TTSD_PB_PKT_INTERVAL_TIMER;
  extern volatile dword   *EMMA_TTSD_HSD_JITTER_CNT;
  extern volatile dword   *EMMA_TTSD_HSD_JITTER_CNT_TIMER;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT5;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT6;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_INTERRUPT5;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_INTERRUPT6;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT4;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT5;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT6;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT4;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT5;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT6;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK5;
  extern volatile dword   *EMMA_TTSD_TS_DETECT_INTERRUPT_MASK6;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_MASK5;
  extern volatile dword   *EMMA_TTSD_PID_ERROR_MASK6;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK4;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK5;
  extern volatile dword   *EMMA_TTSD_SECTION_DETECT_INTERRUPT_MASK6;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK4;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK5;
  extern volatile dword   *EMMA_TTSD_NEARLY_FULL_INTERRUPT_MASK6;
  extern volatile dword   *EMMA_TTSD_PID_STOP3;
  extern volatile dword   *EMMA_TTSD_PID_STOP4;


  extern volatile dword   *EMMA_Hardware_b000b000;
  extern volatile dword   *EMMA_Hardware_b000b00c;
  extern volatile dword   *EMMA_Hardware_b000b09c;

  //WMIF = Memory Interface
  extern volatile dword   *EMMA_WMIF_SOFT_RST;
  extern volatile dword   *EMMA_WMIF_CONFIG;
  extern volatile dword   *EMMA_WMIF_INIT;
  extern volatile dword   *EMMA_WMIF_REFCNT;
  extern volatile dword   *EMMA_WMIF_DISP_CFG;
  extern volatile dword   *EMMA_WMIF_MPEG_CFG;
  extern volatile dword   *EMMA_WMIF_DMA_CFG;
  extern volatile dword   *EMMA_WMIF_IDE_CFG;
  extern volatile dword   *EMMA_WMIF_TS_CFG;
  extern volatile dword   *EMMA_WMIF_DVI_CFG;
  extern volatile dword   *EMMA_WMIF_CPU_CFG;
  extern volatile dword   *EMMA_WMIF_BLT_CFG;
  extern volatile dword   *EMMA_WMIF_CNT_CFG;
  extern volatile dword   *EMMA_WMIF_REQCNT;
  extern volatile dword   *EMMA_WMIF_INT;
  extern volatile dword   *EMMA_WMIF_INT_EN;

  //These registers hold pointers to the 8 EMMA_MPEG decode windows
  extern volatile dword   *EMMA_WMIF_ATBL0_Y;
  extern volatile dword   *EMMA_WMIF_ATBL0_C;
  extern volatile dword   *EMMA_WMIF_ATBL1_Y;
  extern volatile dword   *EMMA_WMIF_ATBL1_C;
  extern volatile dword   *EMMA_WMIF_ATBL2_Y;
  extern volatile dword   *EMMA_WMIF_ATBL2_C;
  extern volatile dword   *EMMA_WMIF_ATBL3_Y;
  extern volatile dword   *EMMA_WMIF_ATBL3_C;
  extern volatile dword   *EMMA_WMIF_ATBL4_Y;
  extern volatile dword   *EMMA_WMIF_ATBL4_C;
  extern volatile dword   *EMMA_WMIF_ATBL5_Y;
  extern volatile dword   *EMMA_WMIF_ATBL5_C;
  extern volatile dword   *EMMA_WMIF_ATBL6_Y;
  extern volatile dword   *EMMA_WMIF_ATBL6_C;
  extern volatile dword   *EMMA_WMIF_ATBL7_Y;
  extern volatile dword   *EMMA_WMIF_ATBL7_C;

  //The rest are still unexplained by NEC
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_T0;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_T1;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_T2;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_T3;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_T4;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_B0;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_B1;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_B2;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_B3;
  extern volatile dword   *EMMA_WMIF_YTBL_DISP_B4;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_T0;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_T1;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_T2;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_T3;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_T4;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_B0;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_B1;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_B2;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_B3;
  extern volatile dword   *EMMA_WMIF_YTBL_MPEG_B4;
  extern volatile dword   *EMMA_WMIF_DUMMY;
  extern volatile dword   *EMMA_WMIF_CLOCK_DELAY;

  extern volatile dword   *EMMA_ATA_CONTROL;
  extern volatile dword   *EMMA_ATA_INT_EN_ITOP_STATUS;
  extern volatile dword   *EMMA_ATA_InterruptFlag1;
  extern volatile dword   *EMMA_ATA_INT_STATUS;
  extern volatile dword   *EMMA_ATA_MODE;
  extern volatile dword   *EMMA_ATA_UNKNOWN;
  extern volatile dword   *EMMA_ATA_ATACFG_PIO_CONTROL;
  extern volatile dword   *EMMA_ATA_SWAP;
  extern volatile dword   *EMMA_ATA_SOFT_RESET;
  extern volatile dword   *EMMA_ATA_ATACFG_DMA_TIMING_MODE;
  extern volatile dword   *EMMA_ATA_ATACFG_UDMA_TIMING_MODE;
  extern volatile dword   *EMMA_ATA_ATACFG_SPEC_CONTROL;

  extern volatile dword   *EMMA_CU;

  extern volatile dword   *EMMA_HDD_IDE_DMAData_Reg;
  extern volatile dword   *EMMA_HDD_IDE_PIOData_Reg;
  extern volatile dword   *EMMA_HDD_IDE_Feature_Error_Reg;
  extern volatile dword   *EMMA_HDD_IDE_SectorCount_Reg;
  extern volatile dword   *EMMA_HDD_IDE_LBALow_Reg;
  extern volatile dword   *EMMA_HDD_IDE_LBAMid_Reg;
  extern volatile dword   *EMMA_HDD_IDE_LBAHigh_Reg;
  extern volatile dword   *EMMA_HDD_IDE_Device_Reg;
  extern volatile dword   *EMMA_HDD_IDE_Command_Status_Reg;
  extern volatile dword   *EMMA_HDD_IDE_Device_Control_Alternate_Status_Reg;

  //PCI = PCI INTERFACE
  extern volatile dword   *EMMA_PCI_RST;
  extern volatile dword   *EMMA_PCI_ARBEN;
  extern volatile dword   *EMMA_PCI_TENDIAN;
  extern volatile dword   *EMMA_PCI_DMACTRL;
  extern volatile dword   *EMMA_PCI_ERR;
  extern volatile dword   *EMMA_PCI_CTRL_L;
  extern volatile dword   *EMMA_PCI_CTRL_H;
  extern volatile dword   *EMMA_PCI_INIT0;
  extern volatile dword   *EMMA_PCI_INIT1;
  extern volatile dword   *EMMA_PCI_CMD_STS;
  extern volatile dword   *EMMA_PCI_BARC;
  extern volatile dword   *EMMA_PCI_BAR0;

  #define          EMMA_PCI_WIN0_BASE     0xb3000000;
  #define          EMMA_PCI_WIN0_SIZE     0x01000000;
  #define          EMMA_PCI_WIN1_BASE     0xb5000000;
  #define          EMMA_PCI_WIN1_SIZE     0x08000000;

  extern volatile dword   *EMMA_PBRD;

  //SIO1 is not used by the Toppy (also called PFUR0)
  extern volatile dword   *EMMA_SIO1_Data_DivLSB;
  extern volatile dword   *EMMA_SIO1_IE_DivMSB;
  extern volatile dword   *EMMA_SIO1_IID_FIFO;
  extern volatile dword   *EMMA_SIO1_LineControl;
  extern volatile dword   *EMMA_SIO1_ModemControl;
  extern volatile dword   *EMMA_SIO1_LineStatus;
  extern volatile dword   *EMMA_SIO1_ModemStatus;
  extern volatile dword   *EMMA_SIO1_Scratch;

  //SIO2 is used for the serial interface (INT2 ISR17)  (also called PFUR1)
  extern volatile dword   *EMMA_SIO2_Data_DivLSB;
  extern volatile dword   *EMMA_SIO2_IE_DivMSB;
  extern volatile dword   *EMMA_SIO2_IID_FIFO;
  extern volatile dword   *EMMA_SIO2_LineControl;
  extern volatile dword   *EMMA_SIO2_ModemControl;
  extern volatile dword   *EMMA_SIO2_LineStatus;
  extern volatile dword   *EMMA_SIO2_ModemStatus;
  extern volatile dword   *EMMA_SIO2_Scratch;

  //SIO3 is used for the front panel communication (INT2 ISR18)  (also called PURT0)
  extern volatile dword   *EMMA_SIO3_ASIM;
  extern volatile dword   *EMMA_SIO3_Err;
  extern volatile dword   *EMMA_SIO3_BaudRateControl;
  extern volatile dword   *EMMA_SIO3_BaudRateMode;
  extern volatile dword   *EMMA_SIO3_Data;
  extern volatile dword   *EMMA_SIO3_Int;
  extern volatile dword   *EMMA_SIO3_IntMask;

  //SIO4 is not used by the Toppy (also called PURT1)
  extern volatile dword   *EMMA_SIO4_ASIM;
  extern volatile dword   *EMMA_SIO4_Err;
  extern volatile dword   *EMMA_SIO4_BaudRateControl;
  extern volatile dword   *EMMA_SIO4_BaudRateMode;
  extern volatile dword   *EMMA_SIO4_Data;
  extern volatile dword   *EMMA_SIO4_Int;
  extern volatile dword   *EMMA_SIO4_IntMask;

  extern volatile dword   *EMMA_PSCI1_b2005000;
  extern volatile dword   *EMMA_PSCI1_b2005010;
  extern volatile dword   *EMMA_PSCI1_b2005020;
  extern volatile dword   *EMMA_PSCI1_b2005030;
  extern volatile dword   *EMMA_PSCI1_b2005040;
  extern volatile dword   *EMMA_PSCI1_b2005050;
  extern volatile dword   *EMMA_PSCI1_b2005070;
  extern volatile dword   *EMMA_PSCI1_b2005080;
  extern volatile dword   *EMMA_PSCI1_b20050a0;
  extern volatile dword   *EMMA_PSCI1_b20050b0;
  extern volatile dword   *EMMA_PSCI1_b20050c0;
  extern volatile dword   *EMMA_PSCI1_b20050d0;
  extern volatile dword   *EMMA_PSCI1_b20050e0;
  extern volatile dword   *EMMA_PSCI1_b2005140;
  extern volatile dword   *EMMA_PSCI1_b2005160;

  extern volatile dword   *EMMA_PSCI2_b2006060;
  extern volatile dword   *EMMA_PSCI2_b2006090;

  //IIC Bus Controller 1
  //Communicates with the EEPROM (addresses 0xA0/0xA1), the A/V-Matrix (addresses 0x96/0x97)
  //  and the first tuner (addresses 0x../0x..), Modulator?
  extern volatile dword   *EMMA_IIC1_00;
  extern volatile dword   *EMMA_IIC1_10;
  extern volatile dword   *EMMA_IIC1_20;
  extern volatile dword   *EMMA_IIC1_Data;
  extern volatile dword   *EMMA_IIC1_Cmd_Status;
  extern volatile dword   *EMMA_IIC1_60;

  //IIC Bus Controller 2
  //Communicates with the second tuner (addresses 0x../0x..)
  extern volatile dword   *EMMA_IIC2_00;
  extern volatile dword   *EMMA_IIC2_10;
  extern volatile dword   *EMMA_IIC2_20;
  extern volatile dword   *EMMA_IIC2_Data;
  extern volatile dword   *EMMA_IIC2_Cmd_Status;
  extern volatile dword   *EMMA_IIC2_60;

  extern volatile dword   *EMMA_PCIF1_RST;
  extern volatile dword   *EMMA_PCIF1_PCI_Int;
  extern volatile dword   *EMMA_PCIF1_IntEn;
  extern volatile dword   *EMMA_PCIF1_IntSta;
  extern volatile dword   *EMMA_PCIF1_IntEx;
  extern volatile dword   *EMMA_PCIF1_IntExen;
  extern volatile dword   *EMMA_PCIF1_Arben;
  extern volatile dword   *EMMA_PCIF1_Pdar_intreg;
  extern volatile dword   *EMMA_PCIF1_Pdar_brg;
  extern volatile dword   *EMMA_PCIF1_Pdar_PCIw0;
  extern volatile dword   *EMMA_PCIF1_Pdar_PCIw1;
  extern volatile dword   *EMMA_PCIF1_DMA_eadr;
  extern volatile dword   *EMMA_PCIF1_CBI_eadr;
  extern volatile dword   *EMMA_PCIF1_ArbCtrl;
  extern volatile dword   *EMMA_PCIF1_Tendian;
  extern volatile dword   *EMMA_PCIF1_DMACtrl;
  extern volatile dword   *EMMA_PCIF1_Stadr;
  extern volatile dword   *EMMA_PCIF1_Ctadr;
  extern volatile dword   *EMMA_PCIF1_Etadr;
  extern volatile dword   *EMMA_PCIF1_DMAsta;
  extern volatile dword   *EMMA_PCIF1_Brgctrl;

  extern volatile dword   *EMMA_PCIF2_Err;
  extern volatile dword   *EMMA_PCIF2_Ctrl_L;
  extern volatile dword   *EMMA_PCIF2_Ctrl_H;
  extern volatile dword   *EMMA_PCIF2_Arb_L;
  extern volatile dword   *EMMA_PCIF2_Arb_H;
  extern volatile dword   *EMMA_PCIF2_Init0;
  extern volatile dword   *EMMA_PCIF2_Init1;
  extern volatile dword   *EMMA_PCIF2_Vid_Did;
  extern volatile dword   *EMMA_PCIF2_Cmd_Sts;
  extern volatile dword   *EMMA_PCIF2_Revid_Class;
  extern volatile dword   *EMMA_PCIF2_Clsiz_Mltim_htype;
  extern volatile dword   *EMMA_PCIF2_Barc;
  extern volatile dword   *EMMA_PCIF2_Ssvid_Ssid;
  extern volatile dword   *EMMA_PCIF2_Intlin_Intpin;
  extern volatile dword   *EMMA_PCIF2_Bar0;
  extern volatile dword   *EMMA_PCIF2_Swp;

  extern volatile dword   *EMMA_PCSI_b200a000;

  extern volatile dword   *EMMA_TMR1_Timer_Command;
  extern volatile dword   *EMMA_TMR1_Timer_Mode;
  extern volatile dword   *EMMA_TMR1_Timer_Value;
  extern volatile dword   *EMMA_TMR1_Int_Status;
  extern volatile dword   *EMMA_TMR1_Event_Action;
  extern volatile dword   *EMMA_TMR1_Compare;

  //TMR2 is not used by the Toppy
  extern volatile dword   *EMMA_TMR2_Timer_Command;
  extern volatile dword   *EMMA_TMR2_Timer_Mode;
  extern volatile dword   *EMMA_TMR2_Timer_Value;
  extern volatile dword   *EMMA_TMR2_Int_Status;
  extern volatile dword   *EMMA_TMR2_Event_Action;
  extern volatile dword   *EMMA_TMR2_Compare;

  extern volatile dword   *EMMA_RTC_Timer_Command;
  extern volatile dword   *EMMA_RTC_Timer_Mode;
  extern volatile dword   *EMMA_RTC_Timer_Value;
  extern volatile dword   *EMMA_RTC_IntReason;
  extern volatile dword   *EMMA_RTC_Event_Action;
  extern volatile dword   *EMMA_RTC_Compare;

  extern volatile dword   *EMMA_ZECT_b2010600;
  extern volatile dword   *EMMA_ZECT_b2010604;
  extern volatile dword   *EMMA_ZECT_b2010608;

  //ZCCT = Capture Timers
  extern volatile dword   *EMMA_ZCCT1_TIMER_CMD;
  extern volatile dword   *EMMA_ZCCT1_TIMER_MODE;
  extern volatile dword   *EMMA_ZCCT1_TIMER_VALUE;
  extern volatile dword   *EMMA_ZCCT1_TIMER_STATUS;
  extern volatile dword   *EMMA_ZCCT1_INT_STATUS;
  extern volatile dword   *EMMA_ZCCT1_EVENT_ACT;
  extern volatile dword   *EMMA_ZCCT1_CAPCOM_0;
  extern volatile dword   *EMMA_ZCCT1_CAPCOM_1;
  extern volatile dword   *EMMA_ZCCT1_CAPCOM_2;
  extern volatile dword   *EMMA_ZCCT1_CAPCOM_3;

  extern volatile dword   *EMMA_ZCCT2_TIMER_CMD;
  extern volatile dword   *EMMA_ZCCT2_TIMER_MODE;
  extern volatile dword   *EMMA_ZCCT2_TIMER_VALUE;
  extern volatile dword   *EMMA_ZCCT2_TIMER_STATUS;
  extern volatile dword   *EMMA_ZCCT2_INT_STATUS;
  extern volatile dword   *EMMA_ZCCT2_EVENT_ACT;
  extern volatile dword   *EMMA_ZCCT2_CAPCOM_0;
  extern volatile dword   *EMMA_ZCCT2_CAPCOM_1;
  extern volatile dword   *EMMA_ZCCT2_CAPCOM_2;
  extern volatile dword   *EMMA_ZCCT2_CAPCOM_3;

  extern volatile dword   *EMMA_ZCCT3_TIMER_CMD;
  extern volatile dword   *EMMA_ZCCT3_TIMER_MODE;
  extern volatile dword   *EMMA_ZCCT3_TIMER_VALUE;
  extern volatile dword   *EMMA_ZCCT3_TIMER_STATUS;
  extern volatile dword   *EMMA_ZCCT3_INT_STATUS;
  extern volatile dword   *EMMA_ZCCT3_EVENT_ACT;
  extern volatile dword   *EMMA_ZCCT3_CAPCOM_0;
  extern volatile dword   *EMMA_ZCCT3_CAPCOM_1;
  extern volatile dword   *EMMA_ZCCT3_CAPCOM_2;
  extern volatile dword   *EMMA_ZCCT3_CAPCOM_3;

  extern volatile dword   *EMMA_ZCCT4_TIMER_CMD;
  extern volatile dword   *EMMA_ZCCT4_TIMER_MODE;
  extern volatile dword   *EMMA_ZCCT4_TIMER_VALUE;
  extern volatile dword   *EMMA_ZCCT4_TIMER_STATUS;
  extern volatile dword   *EMMA_ZCCT4_INT_STATUS;
  extern volatile dword   *EMMA_ZCCT4_EVENT_ACT;
  extern volatile dword   *EMMA_ZCCT4_CAPCOM_0;
  extern volatile dword   *EMMA_ZCCT4_CAPCOM_1;
  extern volatile dword   *EMMA_ZCCT4_CAPCOM_2;
  extern volatile dword   *EMMA_ZCCT4_CAPCOM_3;

  extern volatile dword   *EMMA_ZWDG_b2010a00;

  extern volatile dword   *EMMA_PIO1_PortData;
  extern volatile dword   *EMMA_PIO2_PortData;
  extern volatile dword   *EMMA_PIO1_PortDirection;
  extern volatile dword   *EMMA_PIO2_PortDirection;
  extern volatile dword   *EMMA_PIO1_Status;
  extern volatile dword   *EMMA_PIO2_Status;
  extern volatile dword   *EMMA_PIO1_Mode;
  extern volatile dword   *EMMA_PIO2_Mode;
  extern volatile dword   *EMMA_PIO1_ConditionA;
  extern volatile dword   *EMMA_PIO2_ConditionA;
  extern volatile dword   *EMMA_PIO1_ConditionB;
  extern volatile dword   *EMMA_PIO2_ConditionB;

  extern volatile dword   *EMMA_TDSC_b2010c30;
  extern volatile dword   *EMMA_TDSC_b2010c34;

  extern volatile dword   *EMMA_TSCA;
  extern volatile dword   *EMMA_TCAM;

  //CI = Common Interface
  extern volatile dword   *EMMA_CI_b4020000;
  extern volatile dword   *EMMA_CI_b4040000;
  extern volatile dword   *EMMA_CI_Slot1;
  extern volatile dword   *EMMA_CI_b40a0000;
  extern volatile dword   *EMMA_CI_Slot2;
  extern volatile dword   *EMMA_CI_b40e0000;


  extern volatile dword   *EMMA_USB_RegAddrPtr;
  extern volatile dword   *EMMA_USB_RegData;
  extern volatile dword   *EMMA_USB_IRQStat0;
  extern volatile dword   *EMMA_USB_IRQStat1;
  extern volatile dword   *EMMA_USB_PageSel;
  extern volatile dword   *EMMA_USB_EP_Data;
  extern volatile dword   *EMMA_USB_EP_Stat0;
  extern volatile dword   *EMMA_USB_EP_Stat1;
  extern volatile dword   *EMMA_USB_EP_Transfer0;
  extern volatile dword   *EMMA_USB_EP_Transfer1;
  extern volatile dword   *EMMA_USB_EP_Transfer2;
  extern volatile dword   *EMMA_USB_EP_IRQEnb;
  extern volatile dword   *EMMA_USB_EP_Avail0;
  extern volatile dword   *EMMA_USB_EP_Avail1;
  extern volatile dword   *EMMA_USB_EP_RspClr;
  extern volatile dword   *EMMA_USB_EP_RspSet;
  extern volatile dword   *EMMA_USB_Reserved1;
  extern volatile dword   *EMMA_USB_Reserved2;
  extern volatile dword   *EMMA_USB_Reserved3;
  extern volatile dword   *EMMA_USB_Reserved4;
  extern volatile dword   *EMMA_USB_Reserved5;
  extern volatile dword   *EMMA_USB_Reserved6;
  extern volatile dword   *EMMA_USB_Reserved7;
  extern volatile dword   *EMMA_USB_Reserved8;
  extern volatile dword   *EMMA_USB_USBCtl0;
  extern volatile dword   *EMMA_USB_USBCtl1;
  extern volatile dword   *EMMA_USB_Frame0;
  extern volatile dword   *EMMA_USB_Frame1;
  extern volatile dword   *EMMA_USB_DMAReq;
  extern volatile dword   *EMMA_USB_Scratch;
  extern volatile dword   *EMMA_USB_Reserved9;
  extern volatile dword   *EMMA_USB_Reserved10;

  extern volatile word    *FlashMemory_Base;
  extern volatile dword   *FlashMemory_Firmware;
  extern volatile dword   *FlashMemory_Settings;
  extern volatile dword   *FlashMemory_Defaults;
  extern volatile dword   *Hardware_bff00000;

  extern volatile tpScalerSettings   *pScalerSettingsMain;
  extern volatile tpScalerSettings   *pScalerSettingsPIP;
  extern volatile tpScalerSettings   *pScalerSettingsUnk1;
  extern volatile tpScalerSettings   *pScalerSettingsUnk2;
  extern volatile tScalerSettings    *ScalerSettings;

  typedef struct
  {
    dword               StartAddress;
    dword               EndIndex;
    dword               CurrentIndex;
    dword               unused [5];
  } tPIDBuffer;

  typedef enum
  {
    STREAMPATH_PathA,
    STREAMPATH_PathB,
    STREAMPATH_PathC,
    STREAMPATH_PathUnknown
  } STREAMPATH;

  typedef enum
  {
    STREAMSOURCE_Tuner1,
    STREAMSOURCE_Tuner2,
    STREAMSOURCE_Playback,
    STREAMSOURCE_CAM
  } STREAMSOURCE;


  /*****************************************************************************************************************************/
  /* Firmware & Low Level                                                                                                      */
  /*****************************************************************************************************************************/

  #define LE16(p)       ((((p&0x00ff))<<8) | ((p&0xff00)>>8))
  #define LE32(p)       ((((p&0x000000ff))<<24) | (((p&0x0000ff00))<<8) | (((p&0x00ff0000))>>8) | ((p&0xff000000)>>24))

  typedef struct
  {
    word                  InUse:1;
    word                  NrOfSegments:15;  //1 segment = 1280 Bytes

    word                  PrevIndex;
    word                  NextIndex;
  } tHeapMap;

  typedef enum
  {
    CRASHMODE_REBOOT,
    CRASHMODE_SHUTDOWN,
    CRASHMODE_FREEZE,
  } tCrashMode;

  typedef enum
  {
    HWRESOURCE_TS,
    HWRESOURCE_IIC,
    HWRESOURCE_HD,
    HWRESOURCE_DMA
  } HWRESOURCE;

  void  CallBIOS (dword Function, dword SubFunction, dword P1, dword P2, dword P3);
  dword CallFirmware(dword pFunction, dword p0, dword p1, dword p2, dword p3);
  bool  EnqueueEvent (word Event, dword Parameter);
  bool  AddEventHandler (word EventID, void *EventHandler, dword State, dword Priority);
  bool  DelEventHandler (word EventID, void *EventHandler);
  bool  PatchInstructionSequence (dword PatchAddress, char PatchPattern [200], char PatchMask [200]);
  void  GetFWInfo (dword *pSysID, word *pApplID, dword *pBIOSAddress, dword *pEnqueueEventAddress, dword *pTAPgp, dword *pFWgp, dword *pTAP_TableAddress, dword *pTAP_IndexAddress);
  bool  IdentifyFirmware (dword *UncompressedFirmware, char *Model, dword *FWDate, word *SysID, word *App, dword *FWgp);
  void  GetHeapParameter (tHeapMap *HeapMap, dword *HeapStart);
  bool  isMasterpiece(void);
  bool  SendToFP (byte *FPData);
  bool  SuppressedAutoStart(void);
  bool  SetCrashBehaviour(tCrashMode Mode);
  dword intLock(void);
  void  intUnlock(dword);

  #define isValidRAMPtr(p) (((dword)(p) >= 0x80000000 && (dword)(p) < 0x84000000)||((dword)(p) >= 0xA0000000 && (dword)(p) < 0xA4000000))

#ifndef PC_BASED
  #define CallFirmwareT(fw, type, ...) \
  ({ \
    type res = 0; \
    if (InitTAPex()) \
    { \
      type (*f)() = (type (*)())fw; \
      dword gp = TAPgp; \
      __asm__ __volatile__ ( \
        "lw $28,%0\n" \
      : : "m"(FWgp)); \
      res = f(__VA_ARGS__); \
      __asm__ __volatile__ ( \
        "or $28,%0,$0\n" \
      : : "r"(gp)); \
    } \
    res; \
  })
  #define CallFirmwareA(fw, ...) CallFirmwareT(fw, dword, __VA_ARGS__)
  #define CallFirmwareA64(fw, ...) CallFirmwareT(fw, ulong64, __VA_ARGS__)
#endif


  /*****************************************************************************************************************************/
  /* FindInstuctionSequnces                                                                                                    */
  /*****************************************************************************************************************************/


  /*****************************************************************************************************************************/
  /* Audio / Video / OSD                                                                                                       */
  /*****************************************************************************************************************************/
  //Forgotten keys
  #define RKEY_White    RKEY_Ab

#ifndef TAP_ALPHA
  #define TAP_ALPHA     1
#endif

  typedef struct
  {
    word                res1;
#ifdef PC_BASED
    word                unknown1:12;
    word                BitmapType:4;
#else
    word                BitmapType:4;
    word                unknown1:12;
#endif
    dword               unused;
    word                Height;
    word                Width;
    word                unknown2;
    word                unknown3;
    dword               pAYVULUT;
    dword               punknown4;
    dword               pBitmapEven;
    dword               pBitmapOdd;
    dword               pStructAddress;
  } tOSDInfo;

  bool  CaptureScreen ( byte mainSub, int width, int height, byte *pBuffer, bool bOSD, int alpha );
  int   FindDBTrack (void);
  word  GetAudioTrackPID (byte Channel, char *Lang);
  dword GetFrameBufferPixel (dword x, dword y);
  void  GetFrameSize (dword *Width, dword *Height);
  int   GetPinStatus(void);
  bool  GetSysOsdControl (TYPE_TapSysOsdId OSDID);
  int   InteractiveGetStatus (void);
  void  InteractiveSetStatus (bool enable);
  bool  isMPMenu (void);
  int   MHEG_Status (void);
  int   SubtitleGetStatus (void);
  void  SubtitleSetStatus (bool enable);


  /*****************************************************************************************************************************/
  /* Flash & EEPROM                                                                                                            */
  /*****************************************************************************************************************************/

  typedef struct
  {
    byte                SatIdx;
    byte                polar;
    word                reserved;
    word                freq;
    word                videoPid;
    word                audioPid;
    word                pcrPid;
  } TYPE_DefaultChannel;

  typedef struct
  {
    byte                SatIdx;                 //DVB-s only
    byte                Res1;

#ifdef PC_BASED
    word                SkipFlag:1;
    word                LockFlag:1;
    word                CASFlag:1;
    word                DelFlag:1;
    word                TunerNum:2;
    word                TPIdx:10;
#else
    word                TPIdx:10;
    word                TunerNum:2;
    word                DelFlag:1;
    word                CASFlag:1;
    word                LockFlag:1;
    word                SkipFlag:1;
#endif

    word                SVCID;
    word                PMTPID;
    word                PCRPID;
    word                VideoPID;
    word                AudioPID;

#ifdef PC_BASED
    byte                SoundMode:2;
    byte                Res2:5;
    byte                RenameFlag:1;
#else
    byte                RenameFlag:1;
    byte                Res2:5;
    byte                SoundMode:2;
#endif

    byte                NVODIdx;
    dword               NameOffset;
    word                ProviderIdx;

    word                LCN;                    //DVB-t & DVB-c only
    byte                Res3 [8];
  }TYPE_Service;

  typedef struct
  {
    short               UTCOffset;
    word                SleepTimer;

#ifdef PC_BASED
    char                Mode:2;                 //0=Auto, 1=Manual
    char                GMTCollection:3;        //0=Normal, 1=CAS Only, 2=User Select
    char                Res1:3;

    char                TimeOffset:1;           //0=Manual, 1=Automatic
    char                Res2:7;

    char                Res3:6;
    char                DST:2;                  //0=off, 3=on
#else
    char                Res1:3;
    char                GMTCollection:3;        //0=Normal, 1=CAS Only, 2=User Select
    char                Mode:2;                 //0=Auto, 1=Manual

    char                Res2:7;
    char                TimeOffset:1;           //0=Manual, 1=Automatic

    char                DST:2;                  //0=off, 3=on
    char                Res3:6;
#endif

    char                Res4;
  }TYPE_ClockSetup;

  typedef struct
  {
    word                etcCRC;
    word                TvSubSvcNum;
    word                TvSvcNum;
    word                RadioSvcNum;
    word                TvOldSvcNum;
    word                RadioOldSvcNum;
    byte                Volume;

#ifdef PC_BASED
    byte                AspectRatio:1;
    byte                VideoType:2;
    byte                ScartOutputSource:2;
    byte                SoundMode:2;
    byte                ServiceType:1;
#else
    byte                ServiceType:1;
    byte                SoundMode:2;
    byte                ScartOutputSource:2;
    byte                VideoType:2;
    byte                AspectRatio:1;
#endif

    byte                Flags;

#ifdef PC_BASED
    byte                Dolby:1;
    byte                Format169:2;
    byte                DisableTeletext:1;
    byte                DisableSubTitle:1;
    byte                RFOutput:3;
#else
    byte                RFOutput:3;
    byte                DisableSubTitle:1;
    byte                DisableTeletext:1;
    byte                Format169:2;
    byte                Dolby:1;
#endif

    byte                InfoBoxTime;
    byte                ActiveFavNumber;
    byte                CurrentFavGroup;

#ifdef PC_BASED
    byte                TVType:2;
    byte                InfoBoxPosition:6;
#else
    byte                InfoBoxPosition:6;
    byte                TVType:2;
#endif

    byte                OSDAlpha;

#ifdef PC_BASED
    byte                unused1:1;
    byte                TimeShift:1;
    byte                SvcHelpWindow:1;
    byte                PIPPosition:2;
    byte                ScartType:1;
    byte                SatDelete:1;
    byte                MovingConfirmBox:1;
#else
    byte                MovingConfirmBox:1;
    byte                SatDelete:1;
    byte                ScartType:1;
    byte                PIPPosition:2;
    byte                SvcHelpWindow:1;
    byte                TimeShift:1;
    byte                unused1:1;
#endif

    byte                CurrentTunerSub;
    byte                CurrentTunerMain;
    word                MultifeedServiceNum;
    byte                UHFChannel;

    byte                unused2 [3];

#ifdef PC_BASED
    byte                unused4:5;
    byte                MHEGDisable:1;
    byte                unused3:1;
    byte                TimeFormat:1;
#else
    byte                TimeFormat:1;
    byte                unused3:1;
    byte                MHEGDisable:1;
    byte                unused4:5;
#endif

    byte                unused5 [3];

    word                parentalCRC;
    word                PinCode;
    byte                Rating;

#ifdef PC_BASED
    byte                LockBootLock:1;
    byte                LockInstallation:1;
    byte                LockCommonInterface:1;
    byte                LockOrganizingFavorites:1;
    byte                LockOrganizingServices:1;
    byte                LockAVSettings:1;
    byte                LockLanguageSettings:1;
    byte                LockTimeSettings:1;
#else
    byte                LockTimeSettings:1;
    byte                LockLanguageSettings:1;
    byte                LockAVSettings:1;
    byte                LockOrganizingServices:1;
    byte                LockOrganizingFavorites:1;
    byte                LockCommonInterface:1;
    byte                LockInstallation:1;
    byte                LockBootLock:1;
#endif

    word                languageCRC;
    byte                MenuLanguage;
    byte                TeletextLanguage;
    byte                SubtitleLanguage;
    byte                AudioLanguage;
  }EEPROMSTRUCT;

  /**********************************************************************************/
  /* Flash & EEPROM DVB-s definitions                                               */
  /**********************************************************************************/

  typedef struct
  {
    byte                SatIdx;

#ifdef PC_BASED
    byte                Res1:4;
    byte                Mode:3;
    byte                Polar:1; // 0=V, 1=H
#else
    byte                Polar:1; // 0=V, 1=H
    byte                Mode:3;
    byte                Res1:4;
#endif

    byte                Res2 [2];
    dword               Frequency;
    word                SymbolRate;
    word                TSID;

#ifdef PC_BASED
    byte                Res3:7;
    byte                AllowTimeSync:1;
#else
    byte                AllowTimeSync:1;
    byte                Res3:7;
#endif

    byte                Res4;
    word                OriginalNetworkID;
  }TYPE_TpInfoS;

  typedef struct
  {
#ifdef PC_BASED
    byte                DiSEqC:6;       // 0=disable, 1..16, 17=MiniA, 18=MiniB
    byte                SW12V:1;        // 0=off, 1=on
    byte                Power:1;        // 0=off, 1=on

    byte                StabPosition:7;
    byte                MotorisedSys:1;

    word                LowFreq :14;
    word                kHz22:1;        // 22khz switch box
    word                Universal:1;    // 0=single,1=universal LNB
#else
    byte                Power:1;        // 0=off, 1=on
    byte                SW12V:1;        // 0=off, 1=on
    byte                DiSEqC:6;       // 0=disable, 1..16, 17=MiniA, 18=MiniB

    byte                MotorisedSys:1;
    byte                StabPosition:7;

    word                Universal:1;    // 0=single,1=universal LNB
    word                kHz22:1;        // 22khz switch box
    word                LowFreq :14;
#endif

    word                HighFreq;

#ifdef PC_BASED
    byte                PosIdx:7;
    byte                Usals:1;
#else
    byte                Usals:1;
    byte                PosIdx:7;
#endif

    char                SkewVer;
    char                SkewHor;

#ifdef PC_BASED
    char                TunerConnectionType:2;
    char                Magic:6;
#else
    char                Magic:6;
    char                TunerConnectionType:2;
#endif

    byte                DiSEqC11;
    byte                Res1 [5];
  }TYPE_LNBInfoS;

  typedef struct
  {
    word                tpNum;
    word                Res1;
    char                SatName [16];
    TYPE_LNBInfoS       LNB[2];
    TYPE_DefaultChannel DefaultChannel;
    dword               SatAngle;
    word                Position;
    byte                Res2 [6];
  }TYPE_SatInfoS;

  typedef struct
  {
    byte                TunerIndex;

#ifdef PC_BASED
    byte                Res1:1;
    byte                ManualRecording:2;
    byte                DemuxChannel:2;
    byte                RecMode:3;
#else
    byte                RecMode:3;
    byte                DemuxChannel:2;
    byte                ManualRecording:2;
    byte                Res1:1;
#endif

    byte                SatIndex;

#ifdef PC_BASED
    byte                ReservationType:7;
    byte                ServiceType:1;
#else
    byte                ServiceType:1;
    byte                ReservationType:7;
#endif

    word                Duration;
    word                ServiceIndex;
    dword               StartTime;
    dword               EndTime;
    byte                isRec;
    byte                SetName;                //has to be the same value as isRec
    word                ServiceID;
    char                FileName [98];
    word                EventID;
    TYPE_TpInfoS        TPInfo;
  }TYPE_TimerS;

  typedef struct
  {
#ifdef PC_BASED
    byte                ServceIndex:6;
    byte                ServiceType:1;          //0=TV, 1=Radio
    byte                Res1:2;
#else
    byte                Res1:2;
    byte                ServiceType:1;          //0=TV, 1=Radio
    byte                ServceIndex:6;
#endif

    word                EventID;
    dword               StartTime;
  }TYPE_ReserveEPG;


  /**********************************************************************************/
  /* Flash & EEPROM DVB-t definitions (incl. special case TF5700t)                  */
  /**********************************************************************************/

  typedef struct
  {
    word                tpNum;
    char                SatName [30];
  }TYPE_SatInfoT;

  typedef struct
  {
    byte                SatIdx;
    byte                ChannelNr;
    byte                Bandwidth;
    byte                Res1;
    dword               Frequency;
    word                TSID;
    byte                StreamType;             //0=LP Stream, 1=HP Stream
    byte                Res2;
    word                OriginalNetworkID;
    word                NetworkID;
  }TYPE_TpInfoT;

  typedef struct
  {
    word                ChannelNr;
    byte                Bandwidth;
    byte                Res1;
    dword               Frequency;
    word                TSID;
    byte                StreamType;             //0=LP Stream, 1=HP Stream
    byte                Res2;
    word                OriginalNetworkID;
    byte                Res3 [2];
    byte                Res4 [8];               //TF5700t only.
  }TYPE_TpInfoT5700;

  typedef struct
  {
    byte                TunerIndex;

#ifdef PC_BASED
    byte                Res1:1;
    byte                ManualRecording:2;
    byte                DemuxChannel:2;
    byte                RecMode:3;
#else
    byte                RecMode:3;
    byte                DemuxChannel:2;
    byte                ManualRecording:2;
    byte                Res1:1;
#endif

    byte                SatIndex;

#ifdef PC_BASED
    byte                ReservationType:7;
    byte                ServiceType:1;
#else
    byte                ServiceType:1;
    byte                ReservationType:7;
#endif

    word                Duration;
    word                ServiceIndex;
    dword               StartTime;
    dword               EndTime;
    byte                isRec;
    byte                SetName;                //has to be the same value as isRec
    word                ServiceID;
    char                FileName [98];
    word                EventID;
    TYPE_TpInfoT        TPInfo;
  }TYPE_TimerT;

  typedef struct
  {
    byte                TunerIndex;

#ifdef PC_BASED
    byte                Res1:1;
    byte                ManualRecording:2;
    byte                DemuxChannel:2;
    byte                RecMode:3;
#else
    byte                RecMode:3;
    byte                DemuxChannel:2;
    byte                ManualRecording:2;
    byte                Res1:1;
#endif

    byte                SatIndex;

#ifdef PC_BASED
    byte                ReservationType:7;
    byte                ServiceType:1;
#else
    byte                ServiceType:1;
    byte                ReservationType:7;
#endif

    word                Duration;
    word                ServiceIndex;
    dword               StartTime;
    dword               EndTime;
    byte                isRec;
    byte                SetName;                //has to be the same value as isRec
    word                ServiceID;
    char                FileName [98];
    word                EventID;
    TYPE_TpInfoT5700    TPInfo;
  }TYPE_TimerT5700;


  /**********************************************************************************/
  /* Flash & EEPROM DVB-c definitions                                               */
  /**********************************************************************************/

  typedef struct
  {
    word                tpNum;
    byte                Res [30];
  }TYPE_SatInfoC;

  typedef struct
  {
    dword               Frequency;              //[kHz]
    word                SymbolRate;
    word                TSID;
    word                OriginalNetworkID;
    byte                Modulation;             //0=16QAM, 1=32QAM, 2=64QAM, 3=128QAM, 4=256QAM
    byte                Res1 [1];
  }TYPE_TpInfoC;

  typedef struct
  {
    byte                TunerIndex;

#ifdef PC_BASED
    byte                Res1:1;
    byte                ManualRecording:2;
    byte                DemuxChannel:2;
    byte                RecMode:3;
#else
    byte                RecMode:3;
    byte                DemuxChannel:2;
    byte                ManualRecording:2;
    byte                Res1:1;
#endif

    byte                SatIndex;

#ifdef PC_BASED
    byte                ReservationType:7;
    byte                ServiceType:1;
#else
    byte                ServiceType:1;
    byte                ReservationType:7;
#endif

    word                Duration;
    word                ServiceIndex;
    dword               StartTime;
    dword               EndTime;
    byte                isRec;
    byte                SetName;                //has to be the same value as isRec
    word                ServiceID;
    char                FileName [98];
    word                EventID;
    TYPE_TpInfoC        TPInfo;
  }TYPE_TimerC;

  dword                 FlashFindServiceByUHF (char* UHFChannel, bool TVService, bool UseAUSChannelCoding, bool *FlagArray, dword *NewFlags);  //DVB-t only
  void                  FlashGetChannelNumber (int chType, int chNum, dword *Frequency, dword *ChannelNumber);   //for DVB-t only
  TYPE_SatInfoS        *FlashGetSatelliteByIndex (byte SatIdx);
  TYPE_Service         *FlashGetServiceByIndex (word ServiceIdx, bool TVService);
  TYPE_Service         *FlashGetServiceByName (char* ChannelName, bool TVService);
  TYPE_TpInfoC         *FlashGetTransponderCByIndex (word TpIdx);
  TYPE_TpInfoS         *FlashGetTransponderSByIndex (word TpIdx, byte SatIdx);
  TYPE_TpInfoT         *FlashGetTransponderTByIndex (word TpIdx);
  word                  FlashServiceAddressToServiceIndex (TYPE_Service *ServiceAddress);
  bool                  FlashWrite (byte *SourceAddress, byte *FlashAddress, dword DataSize, void *pPercentFinishedCallback);


  /*****************************************************************************************************************************/
  /* HDD Functions                                                                                                             */
  /*****************************************************************************************************************************/

  #define TF_FILE_NAME_SIZE    95
  #define TF_RECFILE_NAME_SIZE 64

  typedef enum
  {
    DIR_ROOT,
    DIR_DATA_FILES,
    DIR_PROGRAM_FILES,
    DIR_MP3
  } eRootDirs;

  typedef struct
  {
    byte        SatIndex;
    byte        reserved1;

#ifdef PC_BASED
    word        SkipFlag:1;
    word        LockFlag:1;
    word        CASFlag:1;
    word        DelFlag:1;
    word        TunerNum:2;
    word        TPIndex:10;
#else
    word        TPIndex:10;
    word        TunerNum:2;
    word        DelFlag:1;
    word        CASFlag:1;
    word        LockFlag:1;
    word        SkipFlag:1;
#endif

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

#ifdef PC_BASED
    word        SkipFlag:1;
    word        LockFlag:1;
    word        CASFlag:1;
    word        DelFlag:1;
    word        TunerNum:2;
    word        TPIndex:10;
#else
    word        TPIndex:10;
    word        TunerNum:2;
    word        DelFlag:1;
    word        CASFlag:1;
    word        LockFlag:1;
    word        SkipFlag:1;
#endif

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

#ifdef PC_BASED
    byte        reserved1:4;
    byte        Mode:3;         //0=Normal, 1=SmaTV
    byte        Polarization:1;
#else
    byte        Polarization:1;
    byte        Mode:3;         //0=Normal, 1=SmaTV
    byte        reserved1:4;
#endif

    byte        reserved2 [2];
    dword       Frequency;      //in MHz
    word        SymbolRate;
    word        TSID;
    byte        reserved3 [2];
    word        OriginalNetworkID;
  } __attribute__((packed)) tRECTPInfoSat;              //16 bytes

  typedef struct
  {
#ifdef PC_BASED
    dword                 FileDateTimeHour:8;
    dword                 FileDateTimeMJD:16;
    dword                 Attribute:8;

    dword                 FileDateTimeOffset:16; //signed short!
    dword                 FileDateTimeSeconds :8;
    dword                 FileDateTimeMin :8;
#else
    dword                 Attribute:8;
    dword                 FileDateTimeMJD:16;
    dword                 FileDateTimeHour:8;

    dword                 FileDateTimeMin :8;
    dword                 FileDateTimeSeconds :8;
    dword                 FileDateTimeOffset:16; //signed short!
#endif

    dword                 StartCluster;
    dword                 TotalCluster;
    dword                 UnusedByte;
    char                  FileName [TF_RECFILE_NAME_SIZE];
    char                  ServiceName [31];
    byte                  unknown1;
    dword                 WinFileAttribute;

#ifdef PC_BASED
    byte                  reserved3:1;
    byte                  Skip:1;
    byte                  Scrambled:1;
    byte                  reserved2:5;
#else
    byte                  reserved2:5;
    byte                  Scrambled:1;
    byte                  Skip:1;
    byte                  reserved3:1;
#endif

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

  void       HDD_BigFile_Read (void *buf, dword SectorNr, dword NrSectors, TYPE_File *fp);
  dword      HDD_BigFile_Size (TYPE_File *fp);     //Returns the number of sectors
  void       HDD_BigFile_Write (void *buf, dword SectorNr, dword NrSectors, TYPE_File *fp);  //!!!Write doesn't append to a file!!! It may only be used in a read-modify-write manner!!!
  dword      HDD_FreeSize (void);
  dword      HDD_GetClusterSize (void);
  bool       HDD_GetFileDir (char *FileName, eRootDirs Root, char *Dir);
  int        HDD_GetFirmwareDirCluster (void);
  bool       HDD_GetHDDInfo (HDDINFO *HddInfo);
  dword      HDD_LiveFS_GetChainLength (int Cluster);
  dword      HDD_LiveFS_GetFAT1Address (void);
  dword      HDD_LiveFS_GetFAT2Address (void);
  int        HDD_LiveFS_GetFirstCluster (int Cluster);
  int        HDD_LiveFS_GetLastCluster (int Cluster);
  int        HDD_LiveFS_GetNextCluster (int Cluster);
  int        HDD_LiveFS_GetPreviousCluster (int Cluster);
  dword      HDD_LiveFS_GetRootDirAddress (void);
  dword      HDD_LiveFS_GetSuperBlockAddress (void);
  void       HDD_ReadClusterDMA (dword Cluster, byte *DataBuffer);
  int        HDD_ReadSector (dword SectorNr, word *DataBuf);
  void       HDD_ReadSectorDMA (dword StartSector, dword NrSectors, byte *DataBuffer);

  bool       HDD_SetCryptFlag (TYPE_File *fp, byte CryptFlag);
  void       HDD_SetFileDateTime (TYPE_File *fp, dword FileDateTime, byte Sec, int LocalOffset);
  void       HDD_TouchFile (TYPE_File *fp);
  void       HDD_SetSkipFlag (TYPE_File *fp, bool SkipFlag);

  int        HDD_SetStandbyTimer(dword TimeoutSec);
  byte       HDD_Smart_ExecuteOfflineImmediate (byte TestMode);
  int        HDD_Stop(void);
  int        HDD_TranslateDirCluster (dword DirClusterNr, char* CurrentDir);
  void       HDD_WriteClusterDMA (dword Cluster, byte *DataBuffer);;
  void       HDD_WriteSectorDMA (dword StartSector, dword NrSectors, byte *DataBuffer);
  bool       HDD_TruncateFile (TYPE_File *File, dword Size);


  //SMART Test Modes are:
  // 0 Execute SMART off-line routine immediately in off-line mode
  // 1 Execute SMART Short self-test routine immediately in off-line mode
  // 2 Execute SMART Extended self-test routine immediately in off-line mode
  // 3 Execute SMART Conveyance self-test routine immediately in off-line mode
  // 4 Execute SMART Selective self-test routine immediately in off-line mode
  // 127 Abort off-line mode self-test routine
  // 129 Execute SMART Short self-test routine immediately in captive mode
  // 130 Execute SMART Extended self-test routine immediately in captive mode
  // 131 Execute SMART Conveyance self-test routine immediately in captive mode
  // 132 Execute SMART Selective self-test routine immediately in captive mode


  /*****************************************************************************************************************************/
  /* Firmware Hooks                                                                                                            */
  /*****************************************************************************************************************************/

  typedef struct
  {
    dword               at;
    dword               v0;
    dword               v1;
    dword               a0;
    dword               a1;
    dword               a2;
    dword               a3;
    dword               t0;
    dword               t1;
    dword               t2;
    dword               t3;
    dword               t4;
    dword               t5;
    dword               t6;
    dword               t7;
    dword               s0;
    dword               s1;
    dword               s2;
    dword               s3;
    dword               s4;
    dword               s5;
    dword               s6;
    dword               s7;
    dword               t8;
    dword               t9;
    dword               k0;
    dword               k1;
    dword               gp;
    dword               sp;
    dword               fp;
    dword               ra;
  } tCPURegs;

  int   HookSet (dword *pFWSource, dword *pTAPHandler);
  void  HookEnable (dword HookIndex, bool Enable);
  void  HookExit (void);
  bool  HookIsEnabled (dword HookIndex);
  void  HookMIPS_Set (dword *pFirmware, dword *pHook, dword *pHookReturn);
  void  HookMIPS_Clear (dword *pFirmware, dword *pHook, dword *pHookReturn);


  /*****************************************************************************************************************************/
  /* I2C Functions                                                                                                             */
  /*                                                                                                                           */
  /* The following chips are known (TF5000 Masterpiece):                                                                       */
  /*   Tuner TDA10085HT                     @ controller 0, address 0x1C/1D                                                    */
  /*   Audio & Video Switch Matrix STV6412A @ controller 0, address 0x96/97                                                    */
  /*   EEPROM 24WC02                        @ controller 0, address 0xA0/A1                                                    */
  /*   Tuner TDA10085HT                     @ controller 1, address 0x1C/1D                                                    */
  /*                                                                                                                           */
  /*****************************************************************************************************************************/

  bool ReadEEPROM (dword EEPROMStart, dword NrOfBytes, char *DestinationAddress);
  bool ReadIICRegister (dword Controller, dword ChipAddress, dword ChipRegister, dword NrOfRegisters, char *DestinationAddress);
  bool WriteIICRegister (dword Controller, dword ChipAddress, dword ChipRegister, dword NrOfRegisters, char *DestinationAddress);


  /*****************************************************************************************************************************/
  /* Masterpiece Display Functions                                                                                             */
  /*   Mainly developed by DeadBeef                                                                                            */
  /*****************************************************************************************************************************/

  typedef enum
  {
    DISPLAY_FW,     // display is fully controlled by the FW
    DISPLAY_SHORT,  // 4-symbol display is controlled by the TAP
    DISPLAY_LONG,   // 8-symbol display is controlled by the TAP
    DISPLAY_BOTH,   // both 4-symbol display and 8-symbol display are controlled by the TAP
    DISPLAY_FULL,   // full control by the TAP (including the icons)
    DISPLAY_LAST
  } DISPLAY_MODE;

  bool MPDisplayInstallMPDisplayFwHook(void);
  void MPDisplayUninstallMPDisplayFwHook(void);
  void MPDisplayClearDisplay (void);
  void MPDisplayClearSegments (byte MemoryAddress, byte MemoryData);
  void MPDisplayDisplayLongString(char *pString);
  void MPDisplayDisplayShortString(char *pString);
  byte MPDisplayGetDisplayByte (byte MemoryAddress);
  byte MPDisplayGetDisplayMask (byte MaskAddress);
  void MPDisplaySetAmFlag(bool active);
  void MPDisplaySetColonFlag(bool active);
  void MPDisplaySetDisplayByte (byte MemoryAddress, byte MemoryData);
  void MPDisplaySetDisplayMask (byte MaskAddress, byte MaskData);
  void MPDisplaySetDisplayMemory (byte *pData);
  void MPDisplaySetDisplayMode(DISPLAY_MODE mode);
  void MPDisplaySetPmFlag(bool active);
  void MPDisplaySetSegments (byte MemoryAddress, byte MemoryData);
  void MPDisplayToggleSegments (byte MemoryAddress, byte MemoryData);
  void MPDisplayUpdateDisplay (void);


  /*****************************************************************************************************************************/
  /* REC Stream functions                                                                                                      */
  /*****************************************************************************************************************************/

  typedef struct
  {
    byte                TunerIndex;               //see Timer block [8] in the PDF

#ifdef PC_BASED
    byte                unused1:1;                //TS          = 60     011 00 00 0
    byte                ManualReservation:2;      //copy        = 82     100 00 01 0
    byte                DemuxPath:2;              //playback    = 00     000 00 00 0
    byte                RecMode:3;                //RecMode:             RM  DP MR u
#else
    byte                RecMode:3;                //RecMode:             RM  DP MR u
    byte                DemuxPath:2;              //playback    = 00     000 00 00 0
    byte                ManualReservation:2;      //copy        = 82     100 00 01 0
    byte                unused1:1;                //TS          = 60     011 00 00 0
#endif
                                                  //REC         = 22     001 00 01 0
    byte                SatIndex;                 //No TS       = 00     000 00 00 0
                                                  //REC via EPG = 20     001 00 00 0
#ifdef PC_BASED
    byte                ReservationType:7;
    byte                ServiceType:1;
#else
    byte                ServiceType:1;
    byte                ReservationType:7;
#endif

    word                Duration;
    word                ServiceNumber;
    dword               StartTime;
    dword               EndTime;
    byte                isRec;
    byte                setName;
    word                ServiceID;
    byte                FileName [80];

#ifdef PC_BASED
    word                unknown6:15;
    word                Pause:1;
#else
    word                Pause:1;
    word                unknown6:15;
#endif

    word                PMTPID;
    byte                unknown7 [16];
    byte                Transponder [16];         //This array is 12 bytes long on a DVB-c!
                                                  //Let a TYPE_TpInfo* pointer point to this address.
  } tRECSlot; //136 bytes

  typedef struct
  {
    byte                playMode;     //(0=not, 1=?starting?, 2=play, 3=TS, 4=chase, 5=MP3)
    byte                Flags;        //(bottom bit = oldSvcType)
    word                oldSvcNum;
    dword               TrickMode;    //(0=norm,1=fwd,2=rwd,3=slow,4=pause)
    dword               Speed;
    char                unknown1 [3];
    byte                Playing;

    tFileSlot           FileSlot;     //The following 5 entries are the updated version of Topfield's TYPE_File struct
    tFileHandle        *FileHandle;
    char                unknown2 [4]; //filler to align the next ulong64
    ulong64             FileSize;
    char                unknown3 [8];

    tRECHeader          RecHdr;       //1400 Bytes, system dependent.
  }tPlaySlot; //1568 Bytes

  bool        HDD_FindPMT (byte *pBuffer, dword BufferSize, tRECHeaderInfo *RECHeaderInfo);
  bool        HDD_PausePlayback (bool Pause);
  bool        HDD_RECSlotPause (byte Slot, bool Pause);
  bool        HDD_RECSlotIsPaused (byte Slot);
  tRECSlot   *HDD_RECSlotGetAddress (byte Slot);
  tPlaySlot  *HDD_PlaySlotGetAddress (void);
  int         HDD_RecalcPlaytime (TYPE_File *f, tRECHeaderInfo *Header);


  /*****************************************************************************************************************************/
  /* TAPs                                                                                                                      */
  /*****************************************************************************************************************************/

  typedef struct
  {
    char                  Signature   [32];
    dword                 TAPID;
    byte                  padding1    [28];
    char                  Name       [ 64];
    char                  AuthorName [ 64];
    char                  Description[128];
    char                  EtcStr     [192];
  } tTAPHeader;

  typedef struct
  {
    // From libtap.a
    dword                 _initData;
    dword                 TAP_Main;
    dword                 _tap_gotStart;
    dword                 _tap_gotEnd;
    dword                 _tap_textEnd;
    dword                 _tap_fixupStart;
    dword                 _tap_fixupEnd;
    dword                 TAP_EventHandler;
    dword                 _gp;
    dword                 _end;
    dword                 TAP_SystemProc;
    dword                 FirmwareVersion;
    dword                 unused_0c;
    dword                 TAP_GetState;
    dword                 TAP_ExitNormal;
    dword                 TAP_EnterNormal;
    dword                 unused_10;
    dword                 unused_11;
    dword                 TAP_Exit;
    dword                 TAP_KbHit;
    dword                 TAP_GetCh;
    dword                 TAP_PutCh;
    dword                 TAP_Print;
    dword                 unknown_17;
    dword                 TAP_SysOsdControl;
    dword                 TAP_SetBaudRate;
    dword                 TAP_PutByte;
    dword                 TAP_PrintSys;
    dword                 unused_1c;
    dword                 unused_1d;
    dword                 unused_1e;
    dword                 unused_1f;
    dword                 unused_20;
    dword                 TAP_SetSoundLevel;
    dword                 TAP_GetTime;
    dword                 TAP_MemInfo;
    dword                 TAP_MemAlloc;
    dword                 TAP_MemFree;
    dword                 TAP_GetTick;
    dword                 TAP_Delay;
    dword                 TAP_ExtractMjd;
    dword                 TAP_MakeMjd;
    dword                 TAP_Sin;
    dword                 TAP_Cos;
    dword                 TAP_SPrint;
    dword                 TAP_GetSignalLevel;
    dword                 TAP_GetSignalQuality;
    dword                 TAP_SetInfoboxTime;
    dword                 TAP_PlayPCM;
    dword                 TAP_CaptureScreen;
    dword                 TAP_GetSystemVar;
    dword                 TAP_SetSystemVar;
    dword                 TAP_WriteSystemVar;
    dword                 TAP_GenerateEvent;
    dword                 unused_36;
    dword                 TAP_Osd_Create;
    dword                 TAP_Osd_Delete;
    dword                 TAP_Osd_Move;
    dword                 TAP_Osd_FillBox;
    dword                 TAP_Osd_PutBox;
    dword                 TAP_Osd_GetBox;
    dword                 TAP_Osd_SetLut;
    dword                 TAP_Osd_Ctrl;
    dword                 TAP_Osd_SetTransparency;
    dword                 TAP_Osd_Draw3dBox;
    dword                 TAP_Osd_Draw3dBoxFill;
    dword                 TAP_Osd_DrawRectangle;
    dword                 unknown_43;
    dword                 TAP_Osd_DrawPixmap;
    dword                 TAP_Osd_Zoom;
    dword                 TAP_Osd_GetBaseInfo;
    dword                 unknown_47;
    dword                 unknown_48;
    dword                 unknown_49;
    dword                 TAP_Osd_Copy;
    dword                 TAP_Osd_SaveBox;
    dword                 TAP_Osd_RestoreBox;
    dword                 TAP_Osd_GetPixel;
    dword                 TAP_Osd_PutPixel;
    dword                 unknown_4f;
    dword                 unused_50;
    dword                 unused_51;
    dword                 unused_52;
    dword                 unused_53;
    dword                 unused_54;
    dword                 unused_55;
    dword                 unused_56;
    dword                 unused_57;
    dword                 unused_58;
    dword                 unused_59;
    dword                 TAP_Hdd_Fopen;
    dword                 TAP_Hdd_Fread;
    dword                 TAP_Hdd_Fwrite;
    dword                 TAP_Hdd_Fclose;
    dword                 TAP_Hdd_FindFirst;
    dword                 TAP_Hdd_FindNext;
    dword                 TAP_Hdd_Fseek;
    dword                 TAP_Hdd_Flen;
    dword                 TAP_Hdd_Ftell;
    dword                 TAP_Hdd_TotalSize;
    dword                 TAP_Hdd_FreeSize;
    dword                 TAP_Hdd_Delete;
    dword                 TAP_Hdd_Exist;
    dword                 TAP_Hdd_Create;
    dword                 TAP_Hdd_ChangeDir;
    dword                 TAP_Hdd_PlayTs;
    dword                 TAP_Hdd_StopTs;
    dword                 TAP_Hdd_PlayMp3;
    dword                 TAP_Hdd_StopMp3;
    dword                 TAP_Hdd_Rename;
    dword                 TAP_Hdd_StartRecord;
    dword                 TAP_Hdd_StopRecord;
    dword                 TAP_Hdd_GetRecInfo;
    dword                 TAP_Hdd_GetPlayInfo;
    dword                 TAP_Hdd_GetHddID;
    dword                 TAP_Osd_PutS;
    dword                 TAP_Osd_GetW;
    dword                 TAP_Osd_PutString;
    dword                 TAP_Osd_DrawString;
    dword                 TAP_Osd_PutStringAf;
    dword                 TAP_Win_SetTitle;
    dword                 TAP_Win_SetColor;
    dword                 TAP_Win_SetDefaultColor;
    dword                 TAP_Win_Draw;
    dword                 TAP_Win_Create;
    dword                 TAP_Win_Delete;
    dword                 TAP_Win_SetFont;
    dword                 TAP_Win_AddItem;
    dword                 TAP_Win_GetSelection;
    dword                 TAP_Win_SetSelection;
    dword                 TAP_Win_Action;
    dword                 unused_83;
    dword                 unused_84;
    dword                 unused_85;
    dword                 unused_86;
    dword                 unused_87;
    dword                 unknown_88;
    dword                 TAP_Win_SetActive;
    dword                 unknown_8a;
    dword                 unknown_8b;
    dword                 unknown_8c;
    dword                 unknown_8d;
    dword                 unknown_8e;
    dword                 unknown_8f;
    dword                 unknown_90;
    dword                 unused_91;
    dword                 unused_92;
    dword                 unused_93;
    dword                 unused_94;
    dword                 unused_95;
    dword                 unused_96;
    dword                 unused_97;
    dword                 unused_98;
    dword                 unused_99;
    dword                 unused_9a;
    dword                 TAP_Channel_GetTotalNum;
    dword                 TAP_Channel_GetFirstInfo;
    dword                 TAP_Channel_GetNextInfo;
    dword                 TAP_Channel_GetInfo;
    dword                 TAP_Channel_GetCurrent;
    dword                 TAP_Channel_Start;
    dword                 TAP_Channel_Scale;
    dword                 TAP_Channel_IsPlayable;
    dword                 TAP_Channel_Move;
    dword                 TAP_Channel_Stop;
    dword                 TAP_Channel_GetTotalAudioTrack;
    dword                 TAP_Channel_GetAudioTrackName;
    dword                 TAP_Channel_SetAudioTrack;
    dword                 TAP_Channel_GetTotalSubtitleTrack;
    dword                 TAP_Channel_GetSubtitleTrackName;
    dword                 TAP_Channel_SetSubtitleTrack;
    dword                 TAP_Channel_GetCurrentSubTV;
    dword                 unused_ac;
    dword                 unused_ad;
    dword                 unused_ae;
    dword                 unused_af;
    dword                 unused_b0;
    dword                 unused_b1;
    dword                 unused_b2;
    dword                 unused_b3;
    dword                 unused_b4;
    dword                 TAP_GetEvent;
    dword                 TAP_GetCurrentEvent;
    dword                 TAP_PutEvent;
    dword                 unused_b8;
    dword                 unused_b9;
    dword                 TAP_Timer_GetTotalNum;
    dword                 TAP_Timer_GetInfo;
    dword                 TAP_Timer_Add;
    dword                 TAP_Timer_Modify;
    dword                 TAP_Timer_Delete;
    dword                 unused_bf;
    dword                 unused_c0;
    dword                 TAP_Usb_Read;
    dword                 TAP_Usb_Write;
    dword                 TAP_Usb_PacketRead;
    dword                 TAP_Usb_PacketWrite;
    dword                 TAP_Usb_Cancel;
    dword                 unused_c6;
    dword                 unused_c7;
    dword                 unused_c8;
    dword                 unused_c9;
    dword                 unused_ca;
    dword                 unused_cb;
    dword                 unused_cc;
    dword                 unused_cd;
    dword                 unused_ce;
    dword                 unused_cf;
    dword                 unused_d0;
    dword                 unused_d1;
    dword                 unused_d2;
    dword                 unused_d3;
    dword                 unused_d4;
    dword                 unused_d5;
    dword                 unused_d6;
    dword                 unused_d7;
    dword                 unused_d8;
    dword                 unused_d9;
    dword                 unused_da;
    dword                 unused_db;
    dword                 unused_dc;
    dword                 unused_dd;
    dword                 unused_de;
    dword                 unused_df;
    dword                 unused_e0;
    dword                 unused_e1;
    dword                 unused_e2;
    dword                 unused_e3;
    dword                 unused_e4;
    dword                 unused_e5;
    dword                 unused_e6;
    dword                 unused_e7;
    dword                 unused_e8;
    dword                 unused_e9;
    dword                 unused_ea;
    dword                 unused_eb;
    dword                 unused_ec;
    dword                 unused_ed;
    dword                 unused_ee;
    dword                 unused_ef;
    dword                 unused_f0;
    dword                 unused_f1;
    dword                 unused_f2;
    dword                 unused_f3;
    dword                 unused_f4;
    dword                 unused_f5;
    dword                 unused_f6;
    dword                 unused_f7;
    dword                 unused_f8;
    dword                 unused_f9;
    dword                 unused_fa;
    dword                 unused_fb;
    dword                 unused_fc;
    dword                 unused_fd;
    dword                 unused_fe;
    dword                 unused_ff;
  } tTAPEntryPoints;

  typedef struct
  {
    dword               FWgp;
    dword               TAPgp;
    dword               HeapAlloc;
    tTAPHeader          *TAPHeader;
    tTAPEntryPoints     *EntryPoints;
    dword               LoadAddress;
    dword               pActDir;
    byte                Flags [3];
  } tTAPTable;

  typedef struct
  {
    dword               FWgp;
    dword               TAPgp;
    dword               HeapAlloc;
    dword               LoadAddress;
    dword               AddressTableAddress;
    dword               LoadAddress2;
    dword               pDotDirStructure;
    byte                ExitFlag;
    byte                unused [3];
    char                TAPName        [ 64];
    char                TAPAuthor      [ 64];
    char                TAPDescription [128];
    dword               TAPID;
    dword               AddressTable   [256];
  } tTAPTableInfo;


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
  bool  HDD_TAP_StartedByTAP (void);
  void  HDD_TAP_Terminate (dword TAPID);


  /*****************************************************************************************************************************/
  /* TAP Comm                                                                                                                  */
  /*   Mainly developed by asrael                                                                                              */
  /*****************************************************************************************************************************/

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


  /*****************************************************************************************************************************/
  /* tapapifix                                                                                                                 */
  /*****************************************************************************************************************************/

  #ifdef  __cplusplus
  extern "C" {
  #endif

  void InitTAPAPIFix(void);

  // missing prototypes
  dword TAP_EventHandler(word, dword, dword);
  int TAP_Main(void);

  #ifdef  __cplusplus
  }
  #endif


  /*****************************************************************************************************************************/
  /* Firmware Patches                                                                                                          */
  /*****************************************************************************************************************************/

  typedef struct
  {
    dword                 Address;            //use 0 to scan the whole binary (generic patch)
    dword                 CodeLength;         //in dword instructions
    dword                 *OriginalCode;
    dword                 *SearchMask;        //not used if DestinationGP<>0 (specific patch)
    dword                 *PatchedCode;
    dword                 *PatchMask;
  } __attribute__((packed)) tPatchSegment;

  typedef struct
  {
    dword                 DestinationGP;      //use 0 for a generic patch
    dword                 NrOfSegments;
    char                  Comment [80];
    tPatchSegment         *PatchSegment[1];
  } __attribute__((packed)) tPatchDetails;

  typedef struct
  {
    dword                Magic;               //Offset 0x000
    dword                FileVersion;         //Offset 0x004
    char                 Author [80];         //Offset 0x008
    char                 Name   [80];         //Offset 0x058
    char                 email  [76];         //Offset 0x0a8
    char                 PatchID [2];         //Offset 0x0f4
    byte                 Flags;               //Offset 0x0f5
    byte                 unused1;             //Offset 0x0f6
    char                 EnglishDescr [256];  //Offset 0x0f8
    char                 GermanDescr  [256];  //Offset 0x1f8
    byte                 Version;             //Offset 0x2f8, 0 will be displayed as version 1
    byte                 unused2 [3];
    dword                NrOfPatches;         //Offset 0x2f9
    tPatchDetails        *PatchDetails[1];    //Offset 0x2fd
  } __attribute__((packed)) tPatchModule;

  typedef struct
  {
    dword                OriginalCount;
    dword                PatchedCount;
    dword                PatchType;
    dword                PatchSubindex;
  } tPatchData;

  tPatchModule *PatchLoadModule (char *FileName);
  tPatchModule *PatchLoadModuleGP (char *FileName, dword JustGP);
  void          PatchUnloadModule (tPatchModule *PatchModule);
  dword         PatchFindType (dword *UncompressedFirmware, dword SizeOfFirmware, tPatchModule *PatchModule, tPatchData *PatchData);
  dword         PatchApply (dword *UncompressedFirmware, tPatchModule *PatchModule, tPatchData *PatchData, bool Install);

  char          *PatchGetInstalled (dword *UncompressedFirmware);
  bool          PatchIsInstalled (dword *UncompressedFirmware, char *PatchID);
  void          PatchCleanList (dword *UncompressedFirmware);
  void          PatchReinstallList (dword *UncompressedFirmware);
  bool          PatchInstallID (dword *UncompressedFirmware, char *PatchID);
  bool          PatchRemoveID (dword *UncompressedFirmware, char *PatchID);
