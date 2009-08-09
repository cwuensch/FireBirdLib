#ifndef FBLIB_TAP_H
#define FBLIB_TAP_H

#include "tap.h"
#include "../libFireBird.h"

#define MAGIC             0xf1eb1d1b
#define TAPDIR_MAX_STACK  16

#ifdef _TMS_
  extern char           TAPDirStack[TAPDIR_MAX_STACK][200];
#else
  extern dword          TAPDirStack[TAPDIR_MAX_STACK];
#endif

extern int TAPDirStackDepth;


#ifndef _TMS_
typedef struct
{
  dword                 TAPgp;
  dword                 OriginalEventHandler;
} tDisabledEvents;

typedef struct
{
  dword                 magic;
  dword                 id;
  bool                  batchmode;
} TYPE_Started_Tap;


typedef struct
{
  dword                 magic;
  dword                 id;
  dword                 pParameterBlock;
} TYPE_Parametered_Tap;


extern bool LibInitialized;
extern tDisabledEvents DisabledEvents [16];
extern bool DisabledEventsArrayInitialized;
extern TYPE_Started_Tap fbl_started_tap;
extern TYPE_Parametered_Tap fbl_parametered_tap;

dword HDD_TAP_DisabledEventHandler(word, dword, dword);
dword SendEventHelper (tTAPTable* tap, word event, dword param1, dword param2);
dword SendEvent (int Index, word event, dword param1, dword param2);
dword CallbackHelper (tTAPTable* tap, void *ProcedureAddress, dword param1, dword param2, dword param3, dword param4);
dword Callback (int Index, void *ProcedureAddress, dword param1, dword param2, dword param3, dword param4);
#endif

#endif
