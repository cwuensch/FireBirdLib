#include                <string.h>
#include                "../libFireBird.h"

void InsertCharsAt(char *SourceString, int Pos, const char *NewString, int CharsToInsert)
{
  char                 *dst;
  char                 *Target;
  int                   OldLen;

  OldLen = strlen(SourceString);
  if(Pos >= OldLen)
  {
    memcpy(&SourceString[OldLen], (void*) NewString, CharsToInsert);
    SourceString[OldLen + CharsToInsert] = '\0';
    return;
  }

  if(Pos < 0) Pos = 0;

  dst = &SourceString[OldLen + CharsToInsert];
  *dst = '\0';
  dst--;

  Target = &SourceString[Pos];
  SourceString = &SourceString[OldLen - 1];

  while(SourceString >= Target)
  {
    *dst = *SourceString;
    dst--;
    SourceString--;
  }

  memcpy(Target, (void*) NewString, CharsToInsert);
}
