#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

inline dword getNextCluster(dword c)
{
  dword d;
  byte *p = (byte*)FIS_vHDDLiveFSFAT1() + FATENTRYSIZE * c;

  __asm__ __volatile__ ("lwl %0,0(%1)\nlwr %0,3(%1)\n" : "=&r"(d) : "r"(p));

  return d >> 8;
}


// Return value: 0..131071 = cluster pointer
//              0x00fffffe = Last cluster in the chain
//              0x00ffffff = Empty cluster
//                      -1 = Cluster is invalid
//                      -2 = The cluster pointer is invalid
//
int GetClusterPointer (int Cluster)
{
  int                   PointsTo;

  if ((Cluster > 131071) || (Cluster < 0)) return -1;

  PointsTo = getNextCluster(Cluster);

  if ((PointsTo > 131071) && (PointsTo != 0x00fffffe) && (PointsTo != 0x00ffffff)) PointsTo = -2;

  return PointsTo;
}

#endif
