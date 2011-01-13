@echo off

set Project=libFireBird
set ZIEL=C:\sw\prgm\Topfield\API\TMS\include

copy %Project%.h %ZIEL%
copy %Project%.a "C:\sw\prgm\Topfield\gccForTMS\crosstool\lib\%Project%.a"
