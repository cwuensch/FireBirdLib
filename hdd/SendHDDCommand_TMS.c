#include "FBLib_hdd.h"
#include "../libFireBird.h"

#ifdef _TMS_

int SendHDDCommand(dword Command, byte *CommandBlock, int BufferSize)
{

#include                <sys/ioctl.h>
#include                <unistd.h>
#include                <linux/hdreg.h>
#include                <fcntl.h>
#include                <linux/fs.h>

  int                   fd, ret, i;
  unsigned short int    *p;

  //Open the hard drive
  fd = open("/dev/sda", O_RDONLY | O_NONBLOCK);
  //fd = open("/dev/sdb", O_RDONLY | O_NONBLOCK);
  if(fd < 0) return 1;

  //DumpMemory(CommandBlock, 7, 16);

  ret = ioctl(fd, Command, CommandBlock);

  //DumpMemory(CommandBlock, 7, 16);

  close(fd);

  if(ret) return 1;

  //Swap endianess of the whole buffer
  p = (unsigned short int*)&CommandBlock[4];
  i = BufferSize;
  while(i > 0)
  {
    endian_swap_word(p);
    p++;
    i -= 2;
  }

  return 0;
}

#endif
