#include                <string.h>
#include                "FBLib_TMSOSDKeyboard.h"
#include                "graphic/Keyb_Shift.gd"
#include                "graphic/Keyb_ScrollLeft.gd"
#include                "graphic/Keyb_ScrollRight.gd"
#include                "graphic/Keyb_SkipLeft.gd"
#include                "graphic/Keyb_SkipRight.gd"
#include                "graphic/Keyb_Slow.gd"

#define COLOR_KeybBorder      RGB( 70,  70,  70)
#define COLOR_KeybTitleArea   RGB( 32,  32,  32)
#define COLOR_KeybBackground  RGB( 40,  40,  40)
#define COLOR_KeybKeyBackgrd  RGB( 30,  30,  30)
#define COLOR_TextField       RGB( 45,  45,  45)
#define COLOR_LightText       COLOR_White       // RGB(232, 232, 232)
#define COLOR_DarkText        RGB(  8,   8,   8)
#define COLOR_TitleText       RGB(232, 146,  17)
#define COLOR_SelectionTop    RGB(255, 175,  14)
#define COLOR_SelectionBtm    RGB(255, 144,  27)
#define COLOR_Cursor          RGB(250, 139,  18)

#define KEYB_OffsetTop       -44
#define KEYB_KeyWidth         50
#define KEYB_KeyHeight        48
#define KEYB_KeyDist          2
#define KEYB_SelKeyWidth      30
#define KEYB_SelKeyHeight     32
#define KEYB_MarginHor        4
#define KEYB_MarginVert       5

#define KEYB_TitleAreaHeight  36
#define KEYB_TextAreaHeight   42

#define KEYB_KeyAreaLeft      (KEYB_MarginHor + 2)
#define KEYB_KeyAreaTop       (KEYB_TitleAreaHeight + KEYB_MarginVert)
#define KEYB_KeyAreaWidth     (NRKEYCOLS * KEYB_KeyWidth + (NRKEYCOLS-1) * KEYB_KeyDist)
#define KEYB_KeyAreaHeight    (NRKEYROWS * KEYB_KeyHeight + (NRKEYROWS-1) * KEYB_KeyDist - 4)

#define KEYB_TextAreaTop      (KEYB_KeyAreaTop + KEYB_KeyAreaHeight + KEYB_KeyDist)

#define KEYB_TextFieldTop     (KEYB_TextAreaTop + KEYB_MarginVert)
#define KEYB_TextFieldLeft    (KEYB_MarginHor + 52)
#define KEYB_TextFieldWidth   (KEYB_KeyAreaWidth - 52 - 27)
#define KEYB_TextFieldHeight  (KEYB_TextAreaHeight - 2*KEYB_MarginVert)

//#define KEYB_BtnAreaLeft      KEYB_KeyAreaLeft
#define KEYB_BtnAreaTop       (KEYB_TextAreaTop + KEYB_TextAreaHeight + KEYB_MarginVert)
//#define KEYB_BtnAreaWidth     KEYB_KeyAreaWidth
#define KEYB_BtnAreaHeight    26

#define KEYB_RegionWidth      (KEYB_KeyAreaWidth + 2*KEYB_MarginHor + 4)
#define KEYB_RegionHeight     (KEYB_TitleAreaHeight + KEYB_KeyAreaHeight + KEYB_TextAreaHeight + KEYB_BtnAreaHeight + KEYB_KeyDist + 3*KEYB_MarginVert + 2)

static int KEYB_SuggestionLeft = 0;

void OSDKeyboard_DrawText(void)
{
  char                 *p, pc[2];
  dword                 x, w, i;
  int                   StringLen;
  dword                 StrWidth, StrWidthToCursor;

  TRACEENTER();
  if(OSDKeyboard_rgn)
  {
    // leeres Textfeld malen
    TAP_Osd_FillBox(OSDKeyboard_rgn, KEYB_TextFieldLeft, KEYB_TextFieldTop, KEYB_TextFieldWidth, KEYB_TextFieldHeight, COLOR_TextField);
    if (KeyPadCursorMode)
      TAP_Osd_DrawRectangle(OSDKeyboard_rgn, KEYB_TextFieldLeft, KEYB_TextFieldTop, KEYB_TextFieldWidth, KEYB_TextFieldHeight, 1, COLOR_Cursor);

    x = KEYB_TextFieldLeft + 6;
    w = KEYB_TextFieldWidth - 12;
    StringLen = strlen(OSDKeyboard_StringVar);

    // Wenn Cursor vor der TextStartPosition ist, TextStart nach links schieben
    if(OSDKeyboard_CursorPosition <= OSDKeyboard_TextStartPosition)
      OSDKeyboard_TextStartPosition = max(OSDKeyboard_CursorPosition - 1, 0);

    // Wenn Text links hinausgeschoben ist, Textfeld verkürzen
    if(OSDKeyboard_TextStartPosition > 0)
    {
      x += (_Keyb_ScrollLeft_Gd.width + 2);
      w -= (_Keyb_ScrollLeft_Gd.width + 2);
    }

    // Wenn Cursor hinter dem rechten Rand liegt, TextStart nach rechts verschieben
    p = &OSDKeyboard_StringVar[OSDKeyboard_CursorPosition];
    *pc = *p;
    pc[1] = '\0';
    for (i = 0; i <= 1; i++)
    {
      *p = '\0';
      while ((StrWidthToCursor = FMUC_GetStringWidth(&OSDKeyboard_StringVar[OSDKeyboard_TextStartPosition], &OSDMenuFont_14)) + FMUC_GetStringWidth(pc, &OSDMenuFont_14) > w)
      {
        if (OSDKeyboard_TextStartPosition >= StringLen) break;
        if (OSDKeyboard_TextStartPosition == 0)
        {
          x += (_Keyb_ScrollLeft_Gd.width + 2);
          w -= (_Keyb_ScrollLeft_Gd.width + 2);
        }
        OSDKeyboard_TextStartPosition++;
      }
      *p = *pc;
      
      // Wenn Text rechts abgeschnitten werden muss, Textfeld verkürzen und TextStart erneut anpassen...
      StrWidth = FMUC_GetStringWidth(&OSDKeyboard_StringVar[OSDKeyboard_TextStartPosition], &OSDMenuFont_14);
      if (i == 0)
      {
        if (StrWidth > w)
          w -= (_Keyb_ScrollRight_Gd.width + 2);
        else break;
      }
      else 
      {
        if (StrWidth <= w + _Keyb_ScrollRight_Gd.width + 2)
          w += (_Keyb_ScrollRight_Gd.width + 2);
      }
    }

    // < falls der Text bereits links hinausgeschoben ist
    if(OSDKeyboard_TextStartPosition > 0)
      TAP_Osd_PutGd(OSDKeyboard_rgn, KEYB_TextFieldLeft+2, KEYB_TextFieldTop + (KEYB_TextFieldHeight-_Keyb_ScrollLeft_Gd.height)/2, &_Keyb_ScrollLeft_Gd, TRUE);

    // > falls der Text rechts abgeschnitten ist
    if(StrWidth > w)
      TAP_Osd_PutGd(OSDKeyboard_rgn, KEYB_TextFieldLeft+KEYB_TextFieldWidth-_Keyb_ScrollRight_Gd.width-2, KEYB_TextFieldTop + (KEYB_TextFieldHeight-_Keyb_ScrollRight_Gd.height)/2, &_Keyb_ScrollRight_Gd, TRUE);

    // Ganzen Text malen
    FMUC_PutString(OSDKeyboard_rgn, x, KEYB_TextFieldTop+3, x+w, &OSDKeyboard_StringVar[OSDKeyboard_TextStartPosition], COLOR_LightText, COLOR_TextField, &OSDMenuFont_14, FALSE, ALIGN_LEFT);

    // Cursor malen
    TAP_Osd_FillBox(OSDKeyboard_rgn, x+StrWidthToCursor-1, KEYB_TextFieldTop+4,  1, 22, COLOR_Cursor); 
    TAP_Osd_FillBox(OSDKeyboard_rgn, x+StrWidthToCursor-5, KEYB_TextFieldTop+26, 9,  2, COLOR_Cursor); 
//      TAP_Osd_PutGd(OSDKeyboard_rgn, x + tw, 286, &_TextCursor14_Gd, TRUE);
    TAP_Osd_Sync();
  }
  TRACEEXIT();
}

void OSDKeyboard_DrawKeys(bool DoSync)
{
  int                   row=0, col=0;
  dword                 x, xt, y, w, h, c;
  dword                 i;
  char                  KeyText[2]; KeyText[1] = '\0';
  char                 *pKeyText = KeyText;
  TYPE_GrData          *pKeyIcon = NULL;

  TRACEENTER();
  if(OSDKeyboard_rgn)
  {
    // Hintergrund übermalen
    TAP_Osd_FillBox(OSDKeyboard_rgn, KEYB_KeyAreaLeft, KEYB_KeyAreaTop, KEYB_KeyAreaWidth, KEYB_KeyAreaHeight, COLOR_KeybBackground);

    for (i = 0; i < NrKeyPadKeys; i++)
    {
      // Koordinaten berechnen
      x = KEYB_KeyAreaLeft + col * (KEYB_KeyWidth+KEYB_KeyDist);
      y = KEYB_KeyAreaTop + row * (KEYB_KeyHeight+KEYB_KeyDist);
      h = (row < NRKEYROWS-1) ? KEYB_KeyHeight : KEYB_KeyHeight-4;
      if (i==KeyPadPosition && !KeyPadCursorMode)
        c = COLOR_DarkText;
      else if (i == KEY_Alt)
        c = RGB(114, 206, 233);  // RGB(111, 221, 253)
      else
        c = COLOR_LightText;

      if (i < NRKEYPADNORMALKEYS)
      {
        w = KEYB_KeyWidth;
        KeyText[0] = Keypad[KeyPadMode][i][0];
        pKeyIcon = NULL;
        if(i==KEY_Shift) pKeyIcon = SpecialKeys[0].Icon;
      }
      else
      {
        w = KEYB_KeyWidth + (SpecialKeys[i - NRKEYPADNORMALKEYS + 1].ColSpan-1) * (KEYB_KeyWidth + KEYB_KeyDist);
        pKeyText = SpecialKeys[i - NRKEYPADNORMALKEYS + 1].Text;
        pKeyIcon = SpecialKeys[i - NRKEYPADNORMALKEYS + 1].Icon;
      }

      // Key zeichnen
      TAP_Osd_FillBox(OSDKeyboard_rgn, x, y, w, h, (((i==KEY_Shift && KeyPadShiftState) /*|| (i==KEY_Alt && KeyPadMode==KPM_Symbols)*/) ? COLOR_TextField : COLOR_KeybKeyBackgrd));
      if (i == KEY_BackSp)
        TAP_Osd_FillBox(OSDKeyboard_rgn, x, y, 2*KEYB_KeyWidth+KEYB_KeyDist, h, COLOR_KeybKeyBackgrd);

      // Markierung auf aktiver Taste zeichnen  
      if ((i == KeyPadPosition) && !KeyPadCursorMode)
      {
        if (i == KEY_Del)
        {
          TAP_Osd_FillBox(OSDKeyboard_rgn, x-2, y,    w+2, 21,   COLOR_SelectionTop);
          TAP_Osd_FillBox(OSDKeyboard_rgn, x-2, y+21, w+2, h-21, COLOR_SelectionBtm);
        }
        else
        {
          TAP_Osd_FillBox(OSDKeyboard_rgn, x,   y,    w,   21,   COLOR_SelectionTop);
          TAP_Osd_FillBox(OSDKeyboard_rgn, x,   y+21, w,   h-21, COLOR_SelectionBtm);
        }
      }

      // Icon zeichnen
      xt = 0;
      if (pKeyIcon)
      {
        xt = (w - FMUC_GetStringWidth(pKeyText,&OSDMenuFont_14) - pKeyIcon->width)/5;
        if (i == KEY_Del)
          TAP_Osd_PutGd(OSDKeyboard_rgn, x+w-pKeyIcon->width-1, y + (h - pKeyIcon->height)/2, pKeyIcon, TRUE);
        else
        {
          if(i == KEY_Shift) xt = 2;
          TAP_Osd_PutGd(OSDKeyboard_rgn, x+2*xt, y + (h - pKeyIcon->height)/2, pKeyIcon, TRUE);
        }
        xt += pKeyIcon->width - 1;
      }

      // Tastentext zeichnen
      if (i == KEY_Shift)
        TAP_Osd_PutGd(OSDKeyboard_rgn, x + 2*(w - _Keyb_Shift_Gd.width)/3, y + (h - _Keyb_Shift_Gd.height)/2, &_Keyb_Shift_Gd, TRUE);
      else if (i == KEY_Del || i == KEY_BackSp)
      {
        x -= 2;
        FMUC_PutString(OSDKeyboard_rgn, x-(i==KEY_Del ? 2 : 0), y+10, x + KEYB_KeyWidth, pKeyText, c, 0, &OSDMenuFont_14, FALSE, (i==KEY_BackSp ? ALIGN_RIGHT : ALIGN_LEFT));
        x += 2;
      }
      else
        FMUC_PutString(OSDKeyboard_rgn, x+xt, y+((row < NRKEYROWS-1) ? 12 : 10), x + w, pKeyText, c, 0, &OSDMenuFont_14, FALSE, ALIGN_CENTER);

      // Spezialbehandlung für Shift und Alt
      if (i == KEY_Shift && KeyPadShiftState)
      {
        TAP_Osd_FillBox(OSDKeyboard_rgn,   x,     y,     w, 1, COLOR_Black);
        TAP_Osd_FillBox(OSDKeyboard_rgn,   x,     y,     1, h, COLOR_Black);
        TAP_Osd_FillBox(OSDKeyboard_rgn,   x,     y+h-1, w, 1, COLOR_Gray);
        TAP_Osd_FillBox(OSDKeyboard_rgn,   x+w-1, y,     1, h, COLOR_Gray);
        if (KeyPadShiftState == 2)
          TAP_Osd_FillBox(OSDKeyboard_rgn, x+w-7, y+6,   3, 3, COLOR_Green);
      }

      // Koordinaten erhöhen (für nächsten Durchlauf)
      col += (i < NRKEYPADNORMALKEYS) ? 1 : SpecialKeys[i - NRKEYPADNORMALKEYS + 1].ColSpan;
      if (col >= NRKEYCOLS)
      {
        col -= NRKEYCOLS;
        row++;
      }
    }
    if(DoSync) TAP_Osd_Sync();
  }
  TRACEEXIT();
}

void OSDKeyboard_DrawKeySelection(void)
{
  dword                 x, y, w, h, c;
  int                   i, nr;
  char                  KeyText[2]; KeyText[1] = '\0';
  char                 *pKeyText = KeyText;

  TRACEENTER();
  if(OSDKeyboard_rgn)
  {
    // Koordinaten berechnen
    nr = min(strlen(Keypad[KeyPadMode][KeyPadPosition]), NRKEYALTSYMBOLS);
    x  = KEYB_KeyAreaLeft + (KeyPadPosition % NRKEYCOLS) * (KEYB_KeyWidth + KEYB_KeyDist) + 6;
    y  = KEYB_KeyAreaTop + (KeyPadPosition / NRKEYCOLS) * (KEYB_KeyHeight + KEYB_KeyDist) + KEYB_KeyHeight;
    h  = KEYB_SelKeyHeight;
    w  = nr * KEYB_SelKeyWidth;

    if (x + w + KEYB_MarginHor + 4 > KEYB_RegionWidth)
      x = KEYB_RegionWidth - w - KEYB_MarginHor - 4;

    // Box zeichnen
    TAP_Osd_DrawRectangle(OSDKeyboard_rgn, x-2, y-2, w+4, h+4, 2, COLOR_KeybBorder);
    TAP_Osd_FillBox(OSDKeyboard_rgn, x, y, w, h, COLOR_KeybKeyBackgrd);
    
    // alternative Buchstaben zeichnen
    w = KEYB_SelKeyWidth;
    for (i = 0; i < nr; i++)
    {
      if (i == KeyPadSelection)
      {
        TAP_Osd_FillBox(OSDKeyboard_rgn, x, y, w, h, COLOR_SelectionTop);
        c = COLOR_DarkText;
      }
      else
        c = COLOR_LightText;

      KeyText[0] = Keypad[KeyPadMode][KeyPadPosition][i];
      FMUC_PutString(OSDKeyboard_rgn, x, y+6, x + w-1, pKeyText, c, 0, &OSDMenuFont_12, FALSE, ALIGN_CENTER);
      x += w;
    }
    TAP_Osd_Sync();
  }
  TRACEEXIT();
}

void OSDKeyboard_DrawSuggesion(void)
{
  char curSuggestion[64];
  int PosX = KEYB_SuggestionLeft;
  TRACEENTER();

  TAP_Osd_FillBox(OSDKeyboard_rgn, PosX, KEYB_BtnAreaTop, KEYB_RegionWidth-KEYB_SuggestionLeft-2, KEYB_BtnAreaHeight, COLOR_KeybBackground);
  if (Keyb_NrSug > 0)
  {
    TAP_Osd_PutGd(OSDKeyboard_rgn, PosX, KEYB_BtnAreaTop + 5, ColorButtons[NRKEYPADCOLORBUTTONS-1].Icon, TRUE);
    if (Keyb_CurSug < Keyb_NrSug)
    {
      PosX += ColorButtons[NRKEYPADCOLORBUTTONS-1].Icon->width + 2;
      if (Keyb_NrSug > 1)
        snprintf(curSuggestion, sizeof(curSuggestion), "%c%s (%d)", OSDKeyboard_StringVar[OSDKeyboard_CursorPosition-Keyb_SugOffset], &(Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug+Keyb_CurSug] + 1]), Keyb_NrSug);
      else
        snprintf(curSuggestion, sizeof(curSuggestion), "%c%s",      OSDKeyboard_StringVar[OSDKeyboard_CursorPosition-Keyb_SugOffset], &(Keyb_DictHeap[Keyb_Dictionary[Keyb_FirstSug+Keyb_CurSug] + 1]));
      FMUC_PutString(OSDKeyboard_rgn, PosX, KEYB_BtnAreaTop + 4, KEYB_KeyAreaWidth, curSuggestion, COLOR_White, COLOR_KeybBackground, &OSDMenuFont_12, TRUE, ALIGN_LEFT);
    }
  }
  TAP_Osd_Sync();

  TRACEEXIT();
}

void OSDKeyboard_DrawAll(void)
{
  dword                 State, SubState;
  int                   PosX, i;

  TRACEENTER();
  if(OSDKeyboard_rgn == 0)
  {
    TAP_GetState(&State, &SubState);
    OSDKeyboard_ReturnToNormal = (SubState != 0);  // (State == STATE_Normal) && (SubState == SUBSTATE_Normal);
    TAP_ExitNormal();
    OSDKeyboard_rgn = TAP_Osd_Create((720-KEYB_RegionWidth) / 2, (576-KEYB_RegionHeight) / 2 + KEYB_OffsetTop, KEYB_RegionWidth, KEYB_RegionHeight, 0, 0);
  }

  // Titelbox erzeugen
  TAP_Osd_DrawRectangle(OSDKeyboard_rgn, 0, 0, KEYB_RegionWidth,   KEYB_TitleAreaHeight, 2, COLOR_KeybBorder);
  TAP_Osd_FillBox      (OSDKeyboard_rgn, 2, 2, KEYB_RegionWidth-4, KEYB_TitleAreaHeight-4,  COLOR_KeybTitleArea);
  FMUC_PutString(OSDKeyboard_rgn, 2, 6, KEYB_RegionWidth-3, OSDKeyboard_Title, COLOR_TitleText, COLOR_KeybTitleArea, &OSDMenuFont_14, TRUE, ALIGN_CENTER);

  // Tastaturbox erzeugen
  TAP_Osd_DrawRectangle(OSDKeyboard_rgn, 0, KEYB_TitleAreaHeight-2, KEYB_RegionWidth,   KEYB_RegionHeight-KEYB_TitleAreaHeight+2, 2, COLOR_KeybBorder);
  TAP_Osd_FillBox      (OSDKeyboard_rgn, 2, KEYB_TitleAreaHeight,   KEYB_RegionWidth-4, KEYB_RegionHeight-KEYB_TitleAreaHeight-2,    COLOR_KeybBackground);
  OSDKeyboard_DrawKeys(FALSE);

  // Textbox erzeugen
  TAP_Osd_FillBox(OSDKeyboard_rgn, KEYB_KeyAreaLeft,                             KEYB_TextAreaTop,  KEYB_KeyAreaWidth, KEYB_TextAreaHeight,  COLOR_KeybKeyBackgrd);
  TAP_Osd_FillBox(OSDKeyboard_rgn, KEYB_TextFieldLeft-1,                         KEYB_TextFieldTop, 1,                 KEYB_TextFieldHeight, COLOR_Black);
  TAP_Osd_FillBox(OSDKeyboard_rgn, KEYB_TextFieldLeft+KEYB_TextFieldWidth,       KEYB_TextFieldTop, 1,                 KEYB_TextFieldHeight, COLOR_Black);
  TAP_Osd_PutGd  (OSDKeyboard_rgn, KEYB_KeyAreaLeft+8,                           KEYB_TextAreaTop+(KEYB_TextAreaHeight-_Keyb_SkipLeft_Gd.height)/2,  &_Keyb_SkipLeft_Gd,  TRUE);
  TAP_Osd_PutGd  (OSDKeyboard_rgn, KEYB_KeyAreaLeft+8+_Keyb_SkipLeft_Gd.width+5, KEYB_TextAreaTop+(KEYB_TextAreaHeight-_Keyb_SkipRight_Gd.height)/2, &_Keyb_SkipRight_Gd, TRUE);
  TAP_Osd_PutGd  (OSDKeyboard_rgn, KEYB_TextFieldLeft+KEYB_TextFieldWidth+10,    KEYB_TextAreaTop+(KEYB_TextAreaHeight-_Keyb_Slow_Gd.height)/2,      &_Keyb_Slow_Gd,      TRUE);
  OSDKeyboard_DrawText();

  // ColorButtons zeichnen
  PosX = KEYB_KeyAreaLeft + 2;
  for (i = 0; i < NRKEYPADCOLORBUTTONS-1; i++)
  {
    TAP_Osd_PutGd(OSDKeyboard_rgn, PosX, KEYB_BtnAreaTop + 5, ColorButtons[i].Icon, TRUE);
    PosX += ColorButtons[i].Icon->width + 2;
    FMUC_PutString(OSDKeyboard_rgn, PosX, KEYB_BtnAreaTop + 4, KEYB_KeyAreaWidth, ColorButtons[i].Text, COLOR_White, COLOR_KeybBackground, &OSDMenuFont_12, TRUE, ALIGN_LEFT);
    PosX += FMUC_GetStringWidth(ColorButtons[i].Text, &OSDMenuFont_12) + 4;
  }
  KEYB_SuggestionLeft = PosX;
  TAP_Osd_Sync();
  TRACEEXIT();
}
