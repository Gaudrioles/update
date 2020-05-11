:: Script DLL pour GTK+
:: Bubi GAUDRIOLES
title DLL EXPORT
@echo off
color 6F

set REPERTOIRE_SRC=C:\msys64\mingw64
set REPERTOIRE_DEST=D:\CodeBlocksProjets\update\bin\Release
@echo off

xcopy /Y %REPERTOIRE_SRC%\bin\LIBGLIB-2.0-0.DLL			%REPERTOIRE_DEST%\
xcopy /Y %REPERTOIRE_SRC%\bin\LIBINTL-8.DLL				%REPERTOIRE_DEST%\
xcopy /Y %REPERTOIRE_SRC%\bin\LIBWINPTHREAD-1.DLL		%REPERTOIRE_DEST%\
xcopy /Y %REPERTOIRE_SRC%\bin\LIBPCRE-1.DLL				%REPERTOIRE_DEST%\
xcopy /Y %REPERTOIRE_SRC%\bin\LIBICONV-2.DLL				%REPERTOIRE_DEST%\


@echo off
color 0F
@echo off

echo Terminee !!
pause