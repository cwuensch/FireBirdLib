cd /d %~dp0
set CYGWIN=nodosfilewarning

set PATH_old=%PATH%
set PATH=%TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\bin;%PATH_old%

set Project=Caller
call gcc.bat Caller.c
mips-ld -o %Project%.elf Caller.o -T %TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\mips\lib\tap.ld -L %TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\topfield-sdk\lib -l tap -l c -Map %Project%.map
mips-objcopy -O binary %Project%.elf %Project%.tap
tapcheck /f
pause

set Project=Callee
call gcc.bat Callee.c
mips-ld -o %Project%.elf Callee.o -T %TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\mips\lib\tap.ld -L %TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\topfield-sdk\lib -l tap -l c -Map %Project%.map
mips-objcopy -O binary %Project%.elf %Project%.tap
tapcheck /f

set PATH=%PATH_old%
set PATH_old=

pause