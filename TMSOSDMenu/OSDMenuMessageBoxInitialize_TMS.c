#include                <string.h>
#include                "FBLib_TMSOSDMenu.h"

#ifdef _TMS_

void OSDMenuMessageBoxInitialize(char *Title, char *Text)
{
  if(MessageBoxOSDRgn) OSDMenuMessageBoxDestroy();
  MessageBox.NrButtons = 0;
  MessageBox.CurrentButton = 0;

  strncpy(MessageBox.Title, Title, STDSTRINGSIZE);
  MessageBox.Title[STDSTRINGSIZE - 1] = '\0';

  strncpy(MessageBox.Text, Text, STDSTRINGSIZE);
  MessageBox.Text[STDSTRINGSIZE - 1] = '\0';
}

#endif
