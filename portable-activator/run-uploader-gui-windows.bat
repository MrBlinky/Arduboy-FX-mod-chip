@echo off
pushd "%~dp0"
Path = %CD%\Python;%CD%\Python\Scripts;%PATH%
start /MIN python.exe fx-activator.py uploader
popd
