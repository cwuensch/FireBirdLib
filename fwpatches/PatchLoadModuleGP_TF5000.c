#include                "../libFireBird.h"

#ifndef _TMS_

static inline void copyLE32(dword *dest, byte *src, int len)
{
  for( ; len > 0; len --, src += 4, dest++)
  {
    byte *d = (byte*)dest;
    byte d0 = src[3], d1 = src[2], d2 = src[1], d3 = src[0];
    d[0] = d0; d[1] = d1; d[2] = d2; d[3] = d3;
  }
}

//Return codes: 1 = file not found
//              2 = failed to open the file
//              3 = failed to reserve memory
//              4 = invalid file
//              5 = unsupported tfp version
//   >=0x80000000 = Pointer to the patch module. Use TAP_MemFree after processing the patch
//
tPatchModule *PatchLoadModuleGP (char *FileName, dword JustGP)
{
  TYPE_File             *fp;
  byte                  *PatchFile = NULL;
  dword                 i, j, p;
  byte                  *FilePos, *BufferPos;
  tPatchModule          *PatchModule = NULL, *mod;
  dword                 BlockSize, totPatches = 0, totSegments = 0, totCodeLens = 0;

  tPatchDetails         *PatchDetails = NULL;
  tPatchSegment         *PatchSegment = NULL;

  //Load the patch file
  if (!TAP_Hdd_Exist (FileName)) return (void*)1;
  if ((fp = TAP_Hdd_Fopen (FileName)) == NULL) return (void*)2;
  i = TAP_Hdd_Flen (fp);

  if (!(PatchFile = TAP_MemAlloc (i)))
  {
    TAP_Hdd_Fclose (fp);
    return (void*)3;
  }
  TAP_Hdd_Fread (PatchFile, i, 1, fp);
  TAP_Hdd_Fclose (fp);

  FilePos = PatchFile;

  PatchModule = (tPatchModule*)FilePos;

  //The file has been created on an Intel/AMD PC, we need to swap endians
  PatchModule->FileVersion = LE32 (PatchModule->FileVersion);
  PatchModule->NrOfPatches = LE32 (PatchModule->NrOfPatches);

  if (PatchModule->Magic != 0x5446501a)
  {
    TAP_MemFree (PatchFile);
    return (void*)4;
  }

  if (PatchModule->FileVersion != 0x0004)
  {
    TAP_MemFree (PatchFile);
    return (void*)5;
  }

  // Count the number of segments and code lengths
  // Do a pre-pass to make a temporary PatchModule and PatchDetails pointing to loaded file
  // Convert needed data to big endian
  FilePos += sizeof (tPatchModule) - 4; //Subtract the *PatchDetails pointer;

  for (i = 0; i < PatchModule->NrOfPatches; i++)
  {
    int add;
    dword gp;
    PatchDetails = (tPatchDetails*)FilePos;
    gp = LE32 (PatchDetails->DestinationGP);
    add = (gp == 0 || JustGP == 0 || gp == JustGP);

    // Convert gp and NrOfSegments
    PatchDetails->DestinationGP = gp;
    PatchDetails->NrOfSegments = LE32 (PatchDetails->NrOfSegments);
    FilePos += sizeof (tPatchDetails) - 4;

    if(add)
    {
      totPatches++;
      totSegments += PatchDetails->NrOfSegments;
    }

    for (j = 0; j < PatchDetails->NrOfSegments; j++)
    {
      dword len;
      PatchSegment = (tPatchSegment*)FilePos;
      len = LE32 (PatchSegment->CodeLength);

      // Convert len
      PatchSegment->CodeLength = len;
      if(add)
      {
        PatchSegment->Address = LE32 (PatchSegment->Address);
        totCodeLens += len;
      }
      FilePos += sizeof (tPatchSegment) + (len << 4) - 16;
    }
  }

  //Calculate the block size to be allocated
  BlockSize = sizeof (tPatchModule) - 4
              + totPatches * (sizeof (tPatchDetails) + sizeof (dword)) //Leave space for the *PatchDetails pointers
              + totSegments * (sizeof (tPatchSegment) + sizeof (dword))              //Leave space for the *PatchSegment pointers
              + (totCodeLens << 4);

  mod = TAP_MemAlloc (BlockSize);
  if (!mod)
  {
    TAP_MemFree (PatchFile);
    return (void*)3;
  }
//  memset (mod, 0, BlockSize);   //Can be removed after debugging

  //Now we just have to fill the structure and direct all pointers to the correct location
  FilePos = PatchFile;
  PatchModule = (tPatchModule*)FilePos;
  // Now make real PatchModule with mod/det/seg
  BufferPos = (byte*)mod;
  memcpy (mod, PatchModule, sizeof (tPatchModule) - 4);
  mod->NrOfPatches = totPatches;

  FilePos   += (sizeof (tPatchModule) - 4);
  BufferPos += (sizeof (tPatchModule) - 4 + (totPatches << 2)); //Leave space for the *PatchDetails pointers

  for (i = 0, p = 0; p < totPatches; i++)
  {
    tPatchDetails *det=NULL;
    dword gp;
    int add;
    PatchDetails = (tPatchDetails*)FilePos;
    gp = PatchDetails->DestinationGP;
    add = (gp == 0 || JustGP == 0 || gp == JustGP);
    if(add)
    {
      det = mod->PatchDetails [p++] = (tPatchDetails*)BufferPos;
      // Copy details
      memcpy (det, PatchDetails, sizeof (tPatchDetails) - 4);
      BufferPos += (sizeof (tPatchDetails) - 4 + (PatchDetails->NrOfSegments << 2));  //Leave space for the *PatchSegment pointers
    }
    FilePos   += (sizeof (tPatchDetails) - 4);

    for (j = 0; j < PatchDetails->NrOfSegments; j++)
    {
      tPatchSegment *seg = (tPatchSegment*)BufferPos;
      dword len;
      PatchSegment = (tPatchSegment*)FilePos;
      len = PatchSegment->CodeLength;
      if(add)
      {
        det->PatchSegment [j] = seg;
        // Copy segment info
        memcpy (seg, PatchSegment, sizeof (tPatchSegment) - 16);
        seg->OriginalCode = (dword*)(BufferPos + sizeof (tPatchSegment));
        seg->SearchMask   = (dword*)(BufferPos + sizeof (tPatchSegment) + (     len << 2));
        seg->PatchedCode  = (dword*)(BufferPos + sizeof (tPatchSegment) + (2 * (len << 2)));
        seg->PatchMask    = (dword*)(BufferPos + sizeof (tPatchSegment) + (3 * (len << 2)));
        BufferPos +=  sizeof (tPatchSegment);
      }
      FilePos   += (sizeof (tPatchSegment) - 16);

      if(add)
      {
        copyLE32(seg->OriginalCode, FilePos,            len);
        if (det->DestinationGP == 0)
        {
          seg->Address = 0;  // Fix bug in TFPCompiler
          copyLE32(seg->SearchMask, FilePos+  (len<<2), len);
        }
        else
          memset(seg->SearchMask, 0xff, len<<2);
        copyLE32(seg->PatchedCode,  FilePos+2*(len<<2), len);
        copyLE32(seg->PatchMask,    FilePos+3*(len<<2), len);
        BufferPos += (len << 4);
      }
      FilePos   += (len << 4);
    }
  }

  TAP_MemFree (PatchFile);

  return mod;
}

#endif
