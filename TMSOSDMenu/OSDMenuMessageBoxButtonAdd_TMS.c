#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuMessageBoxButtonAdd(char *Text)
{
  if(MessageBox.NrButtons < MAXMBBUTTONS)
  {
    strncpy(MessageBox.Button[MessageBox.NrButtons], Text, STDSTRINGSIZE);
    MessageBox.Button[MessageBox.NrButtons][STDSTRINGSIZE - 1] = '\0';
    MessageBox.NrButtons++;
  }
}

#endif
