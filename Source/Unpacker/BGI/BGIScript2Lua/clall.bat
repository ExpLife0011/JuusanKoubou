@echo off

for %%i in (k:\galgame\�x��Υ�`���ƥ���\data01000\*.lua) do (
    title %%i
    "%~dp0luajit.exe" "%%~fi"
)
