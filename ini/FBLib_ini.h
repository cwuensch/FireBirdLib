#ifndef FBLIB_INI_H
#define FBLIB_INI_H

#include "tap.h"

extern dword            LangNrStrings;
extern dword            *LangStringPtr;
extern char             *LangStrings;
extern char *INIBuffer, *INICommentBuffer;

extern dword BufferSize;

void INIFindStartEnd(char *, char **, char **, dword);

#endif
