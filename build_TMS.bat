@echo off
cd /d %~dp0
set Project=libFireBird
if "%TFROOT%"=="" set TFROOT=C:\sw\prgm\Topfield
set PATH=%TFROOT%\gccForTMS\crosstool\bin;%TFROOT%\Cygwin\bin;C:\sw\OS\cygwin\bin;%PATH%

copy %Project%.h %TFROOT%\API\TMS\include

if exist Compile_TMSEMU goto Compile_TMSEMU

echo Building MIPS FBLib
rem bash -i -c "make -j 8"
make -j 8
set BuildState=%errorlevel%
goto Compile_Done

:Compile_TMSEMU
echo Building Intel FBLib
rem bash -i -c "make -j 8 --file=Makefile_tmsemu"
make -j 8 --file=Makefile_tmsemu
set BuildState=%errorlevel%

:Compile_Done
if not "%1"=="/quiet" (
  if not "%2"=="/quiet" (
    pause
  )
)

rem copy %Project%.a "%TFROOT%\gccForTMS\crosstool\lib\%Project%.a"
rem copy %Project%_tmsemu.a "%TFROOT%\gccForTMS\crosstool\lib\%Project%_tmsemu.a"
call update.bat

exit %BuildState%
