#include                <string.h>
#include                "FBLib_TMSOSDKeyboard.h"

extern tFontData        Calibri_14_FontData;
extern TYPE_GrData      _TextCursor14_Gd;

void OSDMenuKeyboard_DrawText(void)
{
  #define MAXX 438
  char                 *p, pc;
  dword                 tw;
  char                  CharAtCursor;
  dword                 x, w, i;
  int                   StringLen;
  char                 *StringVarStart;
  dword                 StrWidth, StrWidthToCursor;
  dword                 WidthThreePoints = FM_GetStringWidth("...", &Calibri_14_FontData);

  if(OSDMenuKeyboard_rgn)
  {
    //Aktuellen Text malen
    TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 0, 276, 444, 32, COLOR_Grey08, COLOR_Grey08, COLOR_Grey04);
    x = 6;
    w = 444 - 2*x - _TextCursor14_Gd.width;
    StringLen = strlen(OSDMenuKeyboard_StringVar);

    // Wenn Cursor vor der TextStartPosition ist, TextStart nach links schieben
    if(OSDMenuKeyboard_CursorPosition < OSDMenuKeyboard_TextStartPosition)
      OSDMenuKeyboard_TextStartPosition = OSDMenuKeyboard_CursorPosition;

    // Wenn Text links hinausgeschoben ist, Textfeld verkürzen
    if(OSDMenuKeyboard_TextStartPosition > 0)
    {
      x += WidthThreePoints;
      w -= WidthThreePoints;
    }

    // Wenn Cursor hinter dem rechten Rand liegt, TextStart nach rechts verschieben
    p = &OSDMenuKeyboard_StringVar[OSDMenuKeyboard_CursorPosition];
    pc = *p;
    for (i = 0; i <= 1; i++)
    {
      *p = '\0';
      while ((StrWidthToCursor = FM_GetStringWidth(&OSDMenuKeyboard_StringVar[OSDMenuKeyboard_TextStartPosition], &Calibri_14_FontData)) > w)
      {
        if (OSDMenuKeyboard_TextStartPosition >= StringLen) break;
        if (OSDMenuKeyboard_TextStartPosition == 0)
        {
          x += WidthThreePoints;
          w -= WidthThreePoints;
        }
        OSDMenuKeyboard_TextStartPosition++;
      }
      *p = pc;
      
      // Wenn Text rechts abgeschnitten werden muss, Textfeld verkürzen und TextStart erneut anpassen...
      StrWidth = FM_GetStringWidth(&OSDMenuKeyboard_StringVar[OSDMenuKeyboard_TextStartPosition], &Calibri_14_FontData);
      if (i == 0)
      {
        if (StrWidth > w)
          w -= WidthThreePoints;
        else break;
      }
      else 
      {
        if (StrWidth <= w + WidthThreePoints)
          w += WidthThreePoints;
      }
    }
    StringVarStart = &OSDMenuKeyboard_StringVar[OSDMenuKeyboard_TextStartPosition];

    TAP_Osd_FillBox(OSDMenuKeyboard_rgn, 4, 280, 436, 22, COLOR_Grey05);
    //..., falls der Text bereits links hinausgeschoben ist
    if(OSDMenuKeyboard_TextStartPosition > 0)
      FM_PutString(OSDMenuKeyboard_rgn, 6, 281, MAXX, "...", COLOR_Grey19, 0, &Calibri_14_FontData, FALSE, ALIGN_LEFT);

    if(OSDMenuKeyboard_CursorPosition == 0)
    {
      //Cursor malen
      TAP_Osd_PutGd(OSDMenuKeyboard_rgn, 6, 285, &_TextCursor14_Gd, TRUE);

      //Ganzen Text malen
      FM_PutString(OSDMenuKeyboard_rgn, x + _TextCursor14_Gd.width, 281, MAXX, OSDMenuKeyboard_StringVar, COLOR_Grey19, 0, &Calibri_14_FontData, TRUE, ALIGN_LEFT);
    }
    else if(OSDMenuKeyboard_CursorPosition == StringLen)
    {
      //Ganzen Text malen
      FM_PutString(OSDMenuKeyboard_rgn, x, 281, MAXX, StringVarStart, COLOR_Grey19, 0, &Calibri_14_FontData, FALSE, ALIGN_LEFT);

      //Cursor malen
      tw = FM_GetStringWidth(StringVarStart, &Calibri_14_FontData);
      TAP_Osd_PutGd(OSDMenuKeyboard_rgn, x + tw, 285, &_TextCursor14_Gd, TRUE);
    }
    else
    {
      //Ersten Teil des Textes malen
      CharAtCursor = OSDMenuKeyboard_StringVar[OSDMenuKeyboard_CursorPosition];
      OSDMenuKeyboard_StringVar[OSDMenuKeyboard_CursorPosition] = '\0';
      FM_PutString(OSDMenuKeyboard_rgn, x, 281, MAXX, StringVarStart, COLOR_Grey19, 0, &Calibri_14_FontData, FALSE, ALIGN_LEFT);

      //Cursor malen
      x += FM_GetStringWidth(StringVarStart, &Calibri_14_FontData);
      TAP_Osd_PutGd(OSDMenuKeyboard_rgn, x, 285, &_TextCursor14_Gd, TRUE);
      x += _TextCursor14_Gd.width;

      //Zweiten Teil des Textes malen
      OSDMenuKeyboard_StringVar[OSDMenuKeyboard_CursorPosition] = CharAtCursor;
      FM_PutString(OSDMenuKeyboard_rgn, x, 281, MAXX, &OSDMenuKeyboard_StringVar[OSDMenuKeyboard_CursorPosition], COLOR_Grey19, 0, &Calibri_14_FontData, TRUE, ALIGN_LEFT);
    }

    TAP_Osd_Sync();
  }
}

void OSDMenuKeyboard_DrawKeys(void)
{
  int                   i=0;
  int                   j=0;
  int                   k=0;
  char                  KeyText[2]; KeyText[1] = '\0';
  char                 *pKeyText = KeyText;

  if(OSDMenuKeyboard_rgn)
  {
    // Tastenbox erzeugen
    TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 0, 34, 444, 244, COLOR_Grey08, COLOR_Grey08, COLOR_Grey04);
    for (i=0;i<NRKEYPADKEYS;i++)
    {
      if (i < 26)
      {
        KeyText[0] = Keypad[KeyPadMode][i];
        if ((i == KeyPadPosition) && !KeyPadCursorMode)
        {
          TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 22+k*50, 56+(j*50), 50, 50, COLOR_Grey08, COLOR_Grey12, COLOR_Orange03);
          TAP_Osd_FillBox(OSDMenuKeyboard_rgn, 24+k*50, 81+(j*50), 46, 23, COLOR_Orange02);
          FM_PutString(OSDMenuKeyboard_rgn, 22+k*50, 70+(j*50), 70+(k*50), KeyText, COLOR_Grey00, 0, &Calibri_14_FontData, FALSE, ALIGN_CENTER);
        }
        else
        {
          TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 22+k*50, 56+(j*50), 50, 50, COLOR_Grey12, COLOR_Grey08, COLOR_Grey04);
          FM_PutString(OSDMenuKeyboard_rgn, 22+k*50, 70+(j*50), 70+(k*50), KeyText, COLOR_Grey19, 0, &Calibri_14_FontData, FALSE, ALIGN_CENTER);
        }

        k++;
        if (k == 8)
        {
          k=0;
          j++;
        }
      }
      else
      {
        if (i == 26) pKeyText = "Space";
        else if (i == 27) pKeyText = "Shift";
        else pKeyText = "OK";

        if ((i == KeyPadPosition) && !KeyPadCursorMode)
        {
          TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 22+k*50, 56+(j*50), 100, 50, COLOR_Grey08, COLOR_Grey12, COLOR_Orange03);
          TAP_Osd_FillBox(OSDMenuKeyboard_rgn, 24+k*50, 81+(j*50), 96, 23, COLOR_Orange02);
          FM_PutString(OSDMenuKeyboard_rgn, 22+k*50, 70+(j*50), 120+(k*50), pKeyText, COLOR_Grey00, 0, &Calibri_14_FontData, FALSE, ALIGN_CENTER);
        }
        else
        {
          if (i == 27 && KeyPadShiftState)
            TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 22+k*50, 56+(j*50), 100, 50, COLOR_Grey08, COLOR_Grey12, COLOR_Grey04);
          else
            TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 22+k*50, 56+(j*50), 100, 50, COLOR_Grey12, COLOR_Grey08, COLOR_Grey04);
          FM_PutString(OSDMenuKeyboard_rgn, 22+k*50, 70+(j*50), 120+(k*50), pKeyText, COLOR_Grey19, 0, &Calibri_14_FontData, FALSE, ALIGN_CENTER);
        }
        k+=2;
      }
    }

    TAP_Osd_Sync();
  }
}

void OSDMenuKeyboard_DrawAll(void)
{
  dword                 State, SubState;
  int                   i;
  const int             w = 444, h = 383;

  if(OSDMenuKeyboard_rgn == 0)
  {
    TAP_GetState(&State, &SubState);
    OSDMenuKeyboard_ReturnToNormal = (State == STATE_Normal) && (SubState == SUBSTATE_Normal);
    TAP_ExitNormal();
    OSDMenuKeyboard_rgn = TAP_Osd_Create((720 - w) >> 1, (576 - h) >> 1, w, h, 0, 0);
  }
  TAP_Osd_FillBox(OSDMenuKeyboard_rgn, 0, 0, w, h, COLOR_Grey01);

  // Titelbox erzeugen
  TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 0, 0, 444, 36, COLOR_Grey08, COLOR_Grey08, COLOR_Grey03);
  FM_PutString(OSDMenuKeyboard_rgn, 5, 6, 440, OSDMenuKeyboard_Title, COLOR_Orange01, 0, &Calibri_14_FontData, FALSE, ALIGN_CENTER);

  // Tastaturbox erzeugen
  OSDMenuKeyboard_DrawKeys();

  // Textbox erzeugen
  OSDMenuKeyboard_DrawText();

  //Legende
  OSDMenuKeyboard_ButtonsX[0] = 10;
  OSDMenuKeyboard_ButtonsX[1] = 10;
  OSDMenuKeyboard_ButtonsX[2] = 10;
  TAP_Osd_Draw3dBoxFill(OSDMenuKeyboard_rgn, 0, 306, 444, 77, COLOR_Grey08, COLOR_Grey08, COLOR_Grey04);
  for(i = 0; i < OSDMenuKeyboard_NrButtons; i++)
    OSDMenuKeyboard_DrawLegendButton(OSDMenuKeyboard_Buttons[i].Line, OSDMenuKeyboard_Buttons[i].ButtonGd, OSDMenuKeyboard_Buttons[i].Text);

  TAP_Osd_Sync();
}

void OSDMenuKeyboard_DrawLegendButton(dword Line, TYPE_GrData *ButtonGd, char *Text)
{
//  TYPE_GrData          *IconGd = NULL;
  extern tFontData      Calibri_12_FontData;
  int                   y;

  if(Line > 0 && Line < 4)
  {
    switch(Line - 1)
    {
      case 0:  y = 312; break;
      case 1:  y = 336; break;
      case 2:  y = 360; break;
      default: y = 312; break;
    }

//    IconGd = OSDMenuGetIconPointer(ButtonIcon, NULL);
    TAP_Osd_PutGd(OSDMenuKeyboard_rgn, OSDMenuKeyboard_ButtonsX[Line - 1], y, ButtonGd, TRUE);
    FM_PutString(OSDMenuKeyboard_rgn, OSDMenuKeyboard_ButtonsX[Line - 1] + ButtonGd->width + 2, y, 430, Text, COLOR_Grey18, 0, &Calibri_12_FontData, FALSE, ALIGN_LEFT);
    OSDMenuKeyboard_ButtonsX[Line - 1] = OSDMenuKeyboard_ButtonsX[Line - 1] + ButtonGd->width + FM_GetStringWidth(Text, &Calibri_12_FontData) + 6;
  }
}
