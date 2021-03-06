#include                <stdio.h>
#include                "FBLib_TMSOSDKeyboard.h"


void OSDKeyboard_SetLegendStrings(char* StrSpace, char* StrDelete1, char* StrDelete2, char* StrOriginal, char* StrClearAll, char* StrCopy, char* StrPaste, char* StrCancel, char* StrSave)  // Strings müssen static sein!
{
  TRACEENTER();

  if(StrDelete1)  SpecialKeys[KEY_BackSp - NRKEYPADNORMALKEYS + 1].Text = StrDelete1;
  if(StrDelete2)  SpecialKeys[KEY_Del    - NRKEYPADNORMALKEYS + 1].Text = StrDelete2;
  if(StrSpace)    SpecialKeys[KEY_Space  - NRKEYPADNORMALKEYS + 1].Text = StrSpace;
  if(StrCancel)   SpecialKeys[KEY_Cancel - NRKEYPADNORMALKEYS + 1].Text = StrCancel;
  if(StrSave)     SpecialKeys[KEY_Save   - NRKEYPADNORMALKEYS + 1].Text = StrSave;
  if(StrOriginal) ColorButtons[0].Text                                  = StrOriginal;
  if(StrClearAll) ColorButtons[1].Text                                  = StrClearAll;
  if(StrCopy)     ColorButtons[2].Text                                  = StrCopy;
  if(StrPaste)    ColorButtons[3].Text                                  = StrPaste;

  TRACEEXIT();
}
