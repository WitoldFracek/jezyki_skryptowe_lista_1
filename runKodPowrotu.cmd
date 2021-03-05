@echo off

kodPowrotu %* /s

if %ERRORLEVEL% LSS 11 ( echo Prawidlowa wartosc )
if %ERRORLEVEL% EQU 11 ( echo Brak parametru )
if %ERRORLEVEL% GTR 11 ( echo Blad w postaci parametru )


pause