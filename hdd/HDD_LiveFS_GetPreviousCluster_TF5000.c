#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

// Return value: 0..131071 = previous cluster
//                      -1 = Unused or invalid cluster
//                      -2 = Start of chain reached
//
int HDD_LiveFS_GetPreviousCluster (int Cluster)
{
  int                   PointsTo;
  static dword          pHDDLiveFSFAT1 = 0;

  if (!pHDDLiveFSFAT1) pHDDLiveFSFAT1 = HDD_LiveFS_GetFAT1Address();

  PointsTo = GetClusterPointer (Cluster);
  if (!pHDDLiveFSFAT1 || (PointsTo < 0) || (PointsTo == 0x00ffffff)) return -1;

    __asm__ __volatile__
  (
    "addu   $08, $00, $00\n"        // $t0 = 0

"Loop_GPC:\n"
    "sll    $09, $08, 1\n"          // $t1 = pHDDLiveFSFAT1 + (3 * $t0)
    "addu   $09, $09, $08\n"
    "addu   $09, $09, %2\n"

    "lb     $10, 0($09)\n"          // $t3 = (*($t1 + 0) << 16) | (*($t1 + 1) << 8) | *($t1 + 2)
    "andi   $10, $10, 0xff\n"
    "sll    $11, $10, 16\n"
    "lb     $10, 1($09)\n"
    "andi   $10, $10, 0xff\n"
    "sll    $10, $10, 8\n"
    "or     $11, $11, $10\n"
    "lb     $10, 2($09)\n"
    "andi   $10, $10, 0xff\n"
    "or     $11, $11, $10\n"        // $t3 now contains the next cluster

    "addu   $09, $00, %1\n"         // if ($t3 == Cluster) goto Exit
    "beq    $11, $09, Exit_GPC\n"

    "addiu  $08, $08, 1\n"          // $t0++
    "lui    $09, 0x0002\n"          // if ($t0 < 0x20000) goto Loop
    "sltu   $25, $08, $09\n"
    "bne    $25, $00, Loop_GPC\n"   // goto Loop
    "lui    $08, 0xffff\n"          // else $t0 = -2
    "ori    $08, $08, 0xfffe\n"

"Exit_GPC:\n"
    "addu   %0, $08, $00\n"         // PointsTo = $t0

    : "=r"(PointsTo)
    : "r"(Cluster), "r"(pHDDLiveFSFAT1)
    : "$2");

  return PointsTo;
}

#endif
