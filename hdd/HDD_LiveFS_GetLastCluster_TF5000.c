#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifndef _TMS_

// Return value: 0..131071 = last cluster
//                      -1 = Unused or invalid cluster
//
int HDD_LiveFS_GetLastCluster (int Cluster)
{
  int                   PointsTo;
  static dword          pHDDLiveFSFAT1 = 0;

  if (!pHDDLiveFSFAT1) pHDDLiveFSFAT1 = HDD_LiveFS_GetFAT1Address();
  if (!pHDDLiveFSFAT1 || Cluster < 0 || Cluster > 131071) return -1;

  __asm__ __volatile__
  (
    "addu   $08, $00, %1\n"         // $t0 = Cluster

"Loop_GLC:\n"
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

    "lui    $09, 0x0002\n"          // if ($t3 < 131072) goto Cont3
    "sltu   $25, $11, $09\n"
    "bne    $25, $00, Cont3\n"

    "lui    $09, 0x00ff\n"          // if ($t3 != 0x00ffffff) goto Cont1
    "ori    $09, $09, 0xffff\n"
    "bne    $11, $09, Cont1\n"
    "lui    $11, 0xffff\n"          // else $t3 = -1
    "ori    $11, $11, 0xffff\n"
    "beq    $00, $00, Exit_GLC\n"   // goto Exit

"Cont1:\n"
    "lui    $09, 0x00ff\n"          // if ($t3 != 0x00fffffe) goto Cont2
    "ori    $09, $09, 0xfffe\n"
    "bne    $11, $09, Cont2\n"
    "addu   $11, $08, $00\n"        // else $t3 = $t0
    "beq    $00, $00, Exit_GLC\n"   // goto Exit

"Cont2:\n"
    "lui    $11, 0xffff\n"          // $t3 = -1
    "ori    $11, $11, 0xffff\n"
    "addu   $11, $08, $00\n"        // $t0 = $t3
    "beq    $00, $00, Exit_GLC\n"   // goto Exit

"Cont3:\n"
    "addu   $08, $11, $00\n"        // $t0 = $t3
    "beq    $00, $00, Loop_GLC\n"   // goto Loop


"Exit_GLC:\n"
    "addu   %0, $11, $00\n"         // PointsTo = $t3

    : "=r"(PointsTo)
    : "r"(Cluster),"r"(pHDDLiveFSFAT1)
    : "$2");

  return PointsTo;
}

#endif
