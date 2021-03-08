@echo off

kodPowrotu2 %* /s

if %ERRORLEVEL% EQU 0 ( echo Prawidlowa wartosc )
if %ERRORLEVEL% EQU 1 ( echo Brak parametru )
if %ERRORLEVEL% EQU 2 ( echo Blad w postaci parametru )


pause>nul