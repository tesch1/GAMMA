@echo off
rem
rem This is a Windows/DOS Batch File That May Be Used To Build The GAMMA DLL 
rem Using the Makefile Produced by the MSVC++ Project, gamma.mak. The Makefile
rem is Run with the Microsoft Supplied Make Program, NMAKE.  For the Build to
rem Work We Must Have the Proper Environment Set Up.  That is Accomplished 
rem Using This File Which is Derived From vcvars32.bat, the Batch File
rem Supplied with Visual Studio for Setting up the MSVC++ Environment. In
rem Addition, After the Environment is Set Up, We Run the NMAKE Program that
rem Executes the Makefile and Build the GAMMA DLL.

rem =========================================================================
rem    In A Dos/Windows Command Shell In This Directory Run "build.bat"
rem =========================================================================

rem =========================================================================
rem    In A CygWin Bash Shell In This Directory Run "cmd.exe /c build.bat"
rem =========================================================================

echo OK TO HERE 1
rem Root of Visual Developer Studio Common files.
set VSCommonDir=C:\PROGRA~1\MICROS~2\Common

rem
rem Root of Visual Developer Studio installed files.
rem
set MSDevDir=C:\PROGRA~1\MICROS~2\Common\msdev98

rem
rem Root of Visual C++ installed files.
rem
set MSVCDir=C:\PROGRA~1\MICROS~2\VC98

rem
rem VcOsDir is used to help create either a Windows 95 or Windows NT specific path.
rem
set VcOsDir=WIN95
if "%OS%" == "Windows_NT" set VcOsDir=WINNT

if "%OS%" == "Windows_NT" set PATH=%MSDevDir%\BIN;%MSVCDir%\BIN;%VSCommonDir%\TOOLS\%VcOsDir%;%VSCommonDir%\TOOLS;%PATH%
if "%OS%" == "" set PATH="%MSDevDir%\BIN";"%MSVCDir%\BIN";"%VSCommonDir%\TOOLS\%VcOsDir%";"%VSCommonDir%\TOOLS";"%windir%\SYSTEM";"%PATH%"

set INCLUDE=%MSVCDir%\ATL\INCLUDE;%MSVCDir%\INCLUDE;%MSVCDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSVCDir%\LIB;%MSVCDir%\MFC\LIB;%LIB%

set VcOsDir=
set VSCommonDir=

rem
rem Build GAMMA DLL Using the Makefile gamma.mak and the NMAKE program
rem
echo OK TO HERE
NMAKE /f "gamma.mak" CFG="gamma - Win32 Release"


