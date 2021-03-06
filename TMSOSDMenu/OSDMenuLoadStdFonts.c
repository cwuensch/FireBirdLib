#define FB_USE_UNICODE_OSD
#include                "FBLib_TMSOSDMenu.h"

tFontDataUC           OSDMenuFont_10;
tFontDataUC           OSDMenuFont_12;
tFontDataUC           OSDMenuFont_14;
tFontDataUC           OSDMenuFont_16;
tFontDataUC           OSDMenuFont_18;
tFontDataUC           OSDMenuFont_20;
tFontDataUC           OSDMenuFont_20B;

void OSDMenuLoadStdFonts(void)
{
  TRACEENTER();

  if(OSDMenuFont_10.FileHandle == 0) FMUC_LoadFontFile("Calibri_10.ufnt", &OSDMenuFont_10);
  if(OSDMenuFont_12.FileHandle == 0) FMUC_LoadFontFile("Calibri_12.ufnt", &OSDMenuFont_12);
  if(OSDMenuFont_14.FileHandle == 0) FMUC_LoadFontFile("Calibri_14.ufnt", &OSDMenuFont_14);
  if(OSDMenuFont_16.FileHandle == 0) FMUC_LoadFontFile("Calibri_16.ufnt", &OSDMenuFont_16);
  if(OSDMenuFont_18.FileHandle == 0) FMUC_LoadFontFile("Calibri_18.ufnt", &OSDMenuFont_18);
  if(OSDMenuFont_20.FileHandle == 0) FMUC_LoadFontFile("Calibri_20.ufnt", &OSDMenuFont_20);
  if(OSDMenuFont_20B.FileHandle == 0) FMUC_LoadFontFile("Calibri_20B.ufnt", &OSDMenuFont_20B);

  TRACEEXIT();
}
