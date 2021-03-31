@echo off
cd /d %~dp0
set PATH=%TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\bin;%TFROOT%\Cygwin\bin;%PATH%
rem bash -i -c make
make
pause
