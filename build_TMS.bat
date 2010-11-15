@echo off
set Project=libFireBird

set ZIEL=C:\sw\prgm\Topfield\API\TMS\include

copy %Project%.h %ZIEL%

set TFROOT=C:\sw\prgm\Topfield
set PATH=%TFROOT%\gccForTMS\crosstool\bin;C:\sw\OS\cygwin\bin
bash -i -c make

copy %Project%.a "C:\sw\prgm\Topfield\gccForTMS\crosstool\lib\%Project%.a"
