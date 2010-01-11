#include  <string.h>
#include  "../libFireBird.h"

void DumpMemory(unsigned char* p, dword size, int BytesPerLine)
{
  unsigned char        *StartAddress = p;
  int                   CollectedBytes;
  char                  text[200], Header[20];
  char                  s[255];

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("DumpMemory");
#endif

  s[0] = '\0';
  text[0] = '\0';
  CollectedBytes = 0;

  TAP_SPrint(Header, "%8.8p 0x%4.4x: ", p, (dword)(p - StartAddress));

  while(size > 0)
  {
    TAP_SPrint(&s[strlen(s)], "%2.2x ", *p);
    if((*p >= 0x20) && (*p <= 0x7e))
      TAP_SPrint(&text[strlen(text)], "%c", *p);
    else
      TAP_SPrint(&text[strlen(text)], ".");

    CollectedBytes++;
    p++;
    size--;

    if(CollectedBytes >= BytesPerLine)
    {
      TAP_SPrint(&s[strlen(s)], "  %s\n", text);
      TAP_Print(Header);
      TAP_Print(s);
      s[0] = '\0';
      text[0] = '\0';
      TAP_SPrint(Header, "%8.8p 0x%4.4x: ", p, (dword)(p - StartAddress));
      CollectedBytes = 0;
    }
  }
  if(strlen(s))
  {
    TAP_SPrint(&s[strlen(s)], "  %s\n", text);
    TAP_Print(Header);
    TAP_Print(s);
  }

#ifdef DEBUG_FIREBIRDLIB
  CallTraceExit(NULL);
#endif
}
