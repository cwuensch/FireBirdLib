@echo off
set Project=libFireBird

copy %Project%.h "C:\sw\prgm\Topfield\API\TMS\include"
copy %Project%_TMS.h "C:\sw\prgm\Topfield\API\TMS\include"

set TFROOT=C:\sw\prgm\Topfield
set PATH=%TFROOT%\gccForTMS\crosstool\bin;C:\sw\OS\cygwin\bin
bash -i -c make

copy %Project%_TMS.a "C:\sw\prgm\Topfield\gccForTMS\crosstool\lib\%Project%.a"
