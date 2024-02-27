@echo off
cls

color 80

:menu
cls

echo.
echo %date%
echo.
echo Computador: %computername%        Usuario: %username%
echo.
echo ^+---------------------------------------------^+
echo ^|                MENU TAREFAS                 ^|
echo ^+---------------------------------------------^+
echo ^| 1. Limpeza rapida                           ^|
echo ^| 2. Limpeza avançada                         ^|
echo ^| 3. Sair                                     ^|
echo ^+---------------------------------------------^+
echo.

set /p opcao= Escolha uma opcao: 

if %opcao% equ 1 goto opcao1
if %opcao% equ 2 goto opcao2
if %opcao% equ 3 goto opcao3
if %opcao% equ 4 goto opcao4
if %opcao% equ 5 goto end
if %opcao% GEQ 6 goto operror

:opcao1
cls

rd /s /q %temp%
rd /s /q temp

echo ^+---------------------------------------------^+
echo ^|              Limpeza concluida!             ^|
echo ^+---------------------------------------------^+
pause
goto menu

:opcao2
cls

rd /s /q %temp%
rd /s /q temp

echo ^+---------------------------------------------^+
echo ^|              Limpeza concluida!             ^|
echo ^+---------------------------------------------^+
pause
goto menu

:opcao3
exit

