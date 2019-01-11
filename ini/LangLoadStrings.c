#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FBLib_ini.h"
#include "libFireBird.h"

dword                   LangNrStrings = 0;
dword                  *LangStringPtr = NULL;
char                   *LangStrings   = NULL;

int LangLoadStrings(char *AbsLangFile, dword NrStrings, int FallbackLang)
{
  FILE                 *f = NULL;
  char                 *OSDLang = iso639_1 (TAP_GetSystemVar(SYSVAR_OsdLan));
  char                 *SecLang = iso639_1 (FallbackLang);
  char                 *LangBuffer = NULL, *Buffer = NULL;
  size_t                BufSize = 0;
  char                 *c = NULL;
  char                  CurLang[3], CurText[200];
  dword                 CurNr, TotalLength;

  TRACEENTER();

  if(LangStringPtr || LangStrings) LangUnloadStrings();

  if((NrStrings > 999999) || !OSDLang || (FallbackLang > LAN_Bulgarian))
  {
    TRACEEXIT();
    return FALSE;
  }

  TotalLength = 1;
  LangNrStrings = 0;
  LangBuffer = TAP_MemAlloc(NrStrings * 200 + 1);
  LangStringPtr = TAP_MemAlloc(NrStrings * sizeof(dword));
  memset(LangBuffer, 0, NrStrings * 200 + 1);
  memset(LangStringPtr, 0, NrStrings * sizeof(dword));

  if ((f = fopen(AbsLangFile, "rb")) != NULL)
  {
    while (getline(&Buffer, &BufSize, f) >= 0)
    {
      // Remove line breaks in the end
/*      p = strlen(Buffer);
      while (p && (Buffer[p-1] == '\r' || Buffer[p-1] == '\n'))
        Buffer[--p] = '\0';

      // Kommentare und Sektionen
      switch (Buffer[0])
      {
        case '\0':
        case '%':
        case ';':
        case '#':
        case '/':
          continue;
      }
*/
      if (sscanf(Buffer, "%2[a-z]_%lu = %199[^\r\n]", CurLang, &CurNr, CurText) == 3)
      {
        if (CurNr < NrStrings)
        {
          if ((strncmp(CurLang, OSDLang, 2) == 0) || (!LangStringPtr[CurNr] && strncmp(CurLang, SecLang, 2) == 0))
          {
            c = CurText;
            while((c = strchr(c, '\\')))
            {
              if(c[1] == 'r') *c ='\r';
              else if(c[1] == 'n') *c ='\n';
              else continue;
              memmove(c + 1, c + 2, strchr(c, '\0') - c - 1);
            }
            strcpy(&LangBuffer[TotalLength], CurText);
            LangStringPtr[CurNr] = TotalLength;
            TotalLength += (strlen(CurText) + 1);
          }
        }
      }
    }
    fclose(f);
    LangStrings = TAP_MemAlloc(TotalLength);
    memcpy(LangStrings, LangBuffer, TotalLength);
    LangNrStrings = NrStrings;
  }

  TRACEEXIT();
  return LangNrStrings;
}
