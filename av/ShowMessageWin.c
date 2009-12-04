#include "../libFireBird.h"

void ShowMessageWin(char *title, char *lpMessage1, char *lpMessage2, dword dwDelay)
{
  char *content[4];

#ifdef DEBUG_FIREBIRDLIB
  CallTraceEnter("ShowMessageWin");
#endif

  content[0] = title;
  content[1] = lpMessage1;
  content[2] = lpMessage2;
  content[3] = NULL;

#ifdef _TMS_
  ShowMessageWindow(content, 720, 576, FNT_Size_1926, ALIGN_CENTER, RGB(156,156,156), RGB(255,255,82), RGB(230,255,230), RGB(25,41,82), dwDelay);
#else
  ShowMessageWindow(content, 720, 576, FNT_Size_1926, ALIGN_CENTER, RGB(19,19,19), RGB(31,31,10), RGB(28,31,28), RGB(3,5,10), dwDelay);
#endif

#ifdef DEBUG_FIREBIRDLIB
    CallTraceExit(NULL);
#endif
}
