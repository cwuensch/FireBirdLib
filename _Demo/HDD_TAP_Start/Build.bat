rem @echo off
set PATH_old=%PATH%
set PATH=%TFROOT%\gccForTF5000\usr\local\bin;%PATH_old%

set INCLUDE1=%TFROOT%\API\TF5000
set INCLUDE2=%TFROOT%\gccForTF5000\usr\local\include
rem set INCLUDE3=%TFROOT%\gccForTF5000\usr\include
rem set INCLUDE3=%TFROOT%\Cygwin\usr\include
set INCLUDE3=%TFROOT%\gccForTMS\crosstool\include


set Project=Caller
set API=%TFROOT%\API\TF5000

echo ---%Project%
mips-gcc.exe -W -Wall -D_TF5000_ -Wstrict-prototypes -Wmissing-prototypes -Wpointer-arith -O2 -c -mtap -mlong-calls -msoft-float -I %INCLUDE1% -I %INCLUDE2% -I %INCLUDE3% %Project%.c

echo ---Linker
mips-ld --cref -o %Project%.elf -T %API%\TAP.LD %Project%.o -l FireBird -l c -l tap -l gcc -l FireBird -Map %Project%.map
mips-objcopy -O binary %Project%.elf %Project%.tap
erase %Project%.o %Project%.elf %Project%.map

echo ------

set Project=Callee

echo ---%Project%
mips-gcc.exe -W -Wall -D_TF5000_ -Wstrict-prototypes -Wmissing-prototypes -Wpointer-arith -O2 -c -mtap -mlong-calls -msoft-float -I %INCLUDE1% -I %INCLUDE2% -I %INCLUDE3% %Project%.c

echo ---Linker
mips-ld --cref -o %Project%.elf -T %API%\TAP.LD %Project%.o -l FireBird -l c -l tap -l gcc -l FireBird -Map %Project%.map
mips-objcopy -O binary %Project%.elf %Project%.tap
erase %Project%.o %Project%.elf %Project%.map

echo ------
tapcheck /f
pause

set PATH=%PATH_old%
set PATH_old=
