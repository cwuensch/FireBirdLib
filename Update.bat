@echo off
set Project=libFireBird

copy %Project%.h %TFROOT%\API\TMS\include
copy %Project%.a "%TFROOT%\gccForTMS\crosstool\lib\%Project%.a"
rem copy %Project%_tmsemu.a "%TFROOT%\gccForTMS\crosstool\lib\%Project%_tmsemu.a"

rem copy %Project%.h %TFROOT%\API\TF5000
rem copy %Project%.a %TFROOT%\API\TF5000

rem copy %Project%.h %TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\topfield-sdk\include
rem copy %Project%.a %TFROOT%\gccForTFBerlios\usr\local\topfield-gcc\topfield-sdk\lib
