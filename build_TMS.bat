@echo off
set Project=libFireBird

set ZIEL=C:\sw\prgm\Topfield\API\TMS\include

copy %Project%.h %ZIEL%
copy %Project%_generic.h %ZIEL%
copy %Project%_TMS.h %ZIEL%

set TFROOT=C:\sw\prgm\Topfield
set PATH=%TFROOT%\gccForTMS\crosstool\bin;C:\sw\OS\cygwin\bin
bash -i -c make

copy %Project%_TMS.a "C:\sw\prgm\Topfield\gccForTMS\crosstool\lib\%Project%.a"
