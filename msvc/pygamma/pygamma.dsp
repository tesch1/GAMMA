# Microsoft Developer Studio Project File - Name="pygamma" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=pygamma - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pygamma.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pygamma.mak" CFG="pygamma - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pygamma - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "pygamma - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pygamma - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PYGAMMA_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../../src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PYGAMMA_EXPORTS" /D PYGAMMA=1 /YX /FD /TP /Zm900 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib boost_python.lib /nologo /dll /incremental:yes /machine:I386 /out:"C:\Program Files\Python22\DLLs\pygamma.dll"

!ELSEIF  "$(CFG)" == "pygamma - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "PYGAMMA_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /ZI /Od /I "../../src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D PYGAMMA=1 /FR /YX /FD /GZ /TP /Zm700 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib boost_python.lib /nologo /dll /debug /machine:I386 /out:"C:/Program Files/Python22/DLLs/pygamma.dll" /pdbtype:sept /libpath:"c:\tools\python\libs"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "pygamma - Win32 Release"
# Name "pygamma - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter ".cc"
# Begin Group "Basics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\Basics\Gconstants.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\Gutils.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\Isotope.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\IsotopeData.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\ParamSet.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\SinglePar.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\StringCut.cc
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\PyGammaIF.cc

!IF  "$(CFG)" == "pygamma - Win32 Release"

# ADD CPP /D PYGAMMA=1

!ELSEIF  "$(CFG)" == "pygamma - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ".h"
# Begin Group "Basicsh"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\Basics\Gconstants.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\Gutils.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\Isotope.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\IsotopeData.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\ParamSet.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\SinglePar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Basics\StringCut.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\PyGammaIF.h
# End Source File
# End Group
# End Target
# End Project
