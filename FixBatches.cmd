@echo off
cd /d %~dp0%

echo @echo off> .\_test\build_TMS.bat
echo cd /d %%~dp0>> .\_test\build_TMS.bat
echo set PATH=%%TFROOT%%\gccForTMS\crosstool\bin;%%TFROOT%%\Cygwin_mini\bin;%%PATH%%>> .\_test\build_TMS.bat
echo del /Q bin obj>> .\_test\build_TMS.bat
echo rem bash -i -c make>> .\_test\build_TMS.bat
echo make>> .\_test\build_TMS.bat
echo pause>> .\_test\build_TMS.bat

copy /y .\_test\build_TMS.bat .\devutils\
copy /y .\_test\build_TMS.bat .\_Demo\ColorPicker\
copy /y .\_test\build_TMS.bat .\_Demo\ConvertPathType\
copy /y .\_test\build_TMS.bat .\_Demo\CrashCheck\
copy /y .\_test\build_TMS.bat .\_Demo\DSTConfig\
copy /y .\_test\build_TMS.bat .\_Demo\EPG\
copy /y .\_test\build_TMS.bat .\_Demo\FIS_Test\
copy /y .\_test\build_TMS.bat .\_Demo\FlashDecode\
copy /y .\_test\build_TMS.bat .\_Demo\FontManager\
copy /y .\_test\build_TMS.bat .\_Demo\SDS_Demo\
copy /y .\_test\build_TMS.bat .\_Demo\TMSOSDKeyboard\
copy /y .\_test\build_TMS.bat .\_Demo\TMSOSDMenu\
