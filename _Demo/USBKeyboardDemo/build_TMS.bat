@echo off
cd /d %~dp0
set PATH=%TFROOT%\gccForTMS\crosstool\bin;%TFROOT%\Cygwin\bin;%PATH%
del /Q bin obj
rem bash -i -c make
make
pause
