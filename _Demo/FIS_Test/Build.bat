@echo off
set PATH_old=%PATH%
set PATH=%TFROOT%\gccForTF5000\usr\local\bin;%PATH_old%

set Project=FIS_Test
set API=%TFROOT%\API\TF5000

echo ---%Project%
call gcc.bat -I %TFROOT%\gccForTMS\crosstool\include %Project%.c

echo ---Linker
mips-ld --cref -o %Project%.elf -T %API%\TAP.LD %Project%.o -l FireBird -l c -l tap -l gcc -l FireBird -Map %Project%.map
mips-objcopy -O binary %Project%.elf %Project%.tap
erase %Project%.o %Project%.elf %Project%.map

echo ------
tapcheck /f
pause

set PATH=%PATH_old%
set PATH_old=
