@echo off

set Project=libFireBird
set ZIEL=C:\sw\prgm\Topfield\API\TF5000

copy %Project%.h %ZIEL%
copy %Project%_generic.h %ZIEL%
copy %Project%_TF5000.h %ZIEL%
copy %Project%.a %ZIEL%

set ZIEL=C:\sw\prgm\Topfield\API\TMS\include

copy %Project%.h %ZIEL%
copy %Project%_generic.h %ZIEL%
copy %Project%_TMS.h %ZIEL%
copy %Project%_TMS.a "C:\sw\prgm\Topfield\gccForTMS\crosstool\lib\%Project%.a"


set Project=
set ZIEL=

