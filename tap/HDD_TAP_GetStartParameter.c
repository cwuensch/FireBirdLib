#ifdef _TMS_

  #include              <sys/types.h>
  #include              <sys/shm.h>

#endif

#include "FBLib_tap.h"

void *HDD_TAP_GetStartParameter (void)
{
#ifdef _TMS_
  int                   shmidParameterBlock;

  shmidParameterBlock = shmget(PARAMBLOCKKEY, sizeof(TYPE_Parametered_Tap), 0);
  if(shmidParameterBlock == -1) return NULL;

  fbl_parametered_tap = (TYPE_Parametered_Tap*)shmat(shmidParameterBlock, 0, 0);
  if((int)fbl_parametered_tap == -1) return NULL;

  return (void*)fbl_parametered_tap->pParameterBlock;

#else

  tTAPTableInfo         TAPInfo;
  dword                 i, LoadAddress, ParameterBlockPointer;

  if (!LibInitialized) InitTAPex ();
  if (!LibInitialized) return NULL;

  //Get my own TAPID
  HDD_TAP_GetInfo (TAP_TableIndex, &TAPInfo);

  //Locate a launcher TAP
  for (i = 0; i < TAP_MAX; i++)
  {
    LoadAddress = *(dword *) (TAP_TableAddress + (i << 5) + 12);
    if (LoadAddress)
    {
      //Has the parameter block pointer being initialized
      ParameterBlockPointer = *(dword *) (LoadAddress + 0x28);
      if ((ParameterBlockPointer > 0x80000000) && (ParameterBlockPointer < 0x84000000) && (*(dword *) ParameterBlockPointer == MAGIC))
      {
        //Has this TAP being started with parameter?
        if (*(dword *) (ParameterBlockPointer + sizeof(dword)) == TAPInfo.TAPID)
        {
          return (void *) (*(dword *) (ParameterBlockPointer + sizeof(dword) * 2));
        }
      }
    }
  }

  //No launcher found
  return NULL;

#endif
}
