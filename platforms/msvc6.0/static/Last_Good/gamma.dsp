# Microsoft Developer Studio Project File - Name="gamma" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=gamma - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gamma.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gamma.mak" CFG="gamma - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gamma - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "gamma - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "gamma - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "gamma___Win32_Release"
# PROP BASE Intermediate_Dir "gamma___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../../src" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /Fo"../../i686-pc-msvc/" /FD /TP /Zm200 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../i686-pc-msvc/gamma.lib"

!ELSEIF  "$(CFG)" == "gamma - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "gamma___Win32_Debug"
# PROP BASE Intermediate_Dir "gamma___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /TP /Zm200 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../../i686-pc-msvc/gamma.lib"

!ENDIF 

# Begin Target

# Name "gamma - Win32 Release"
# Name "gamma - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Basics"

# PROP Default_Filter ".cc"
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
# Begin Group "Matrix"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Matrix\_matrix.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\col_vector.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\complex.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\d_matrix.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\h_matrix.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\i_matrix.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\matrix.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\MxModBas.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\n_matrix.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\row_vector.cc
# End Source File
# End Group
# Begin Group "GamIO"

# PROP Default_Filter ""
# Begin Group "FrameMaker.cc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMaker.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerC.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerM.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerP.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerS.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerSph.cc
# End Source File
# End Group
# Begin Group "Matlab"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\MatLabFile.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML4DElem.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML4Tag.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5AF.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5AN.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5DA.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5DElem.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Hdr.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Imags.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Reals.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5SubE.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Tag.cc
# End Source File
# End Group
# Begin Group "XWinNMR"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\XWin1D.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWin2D.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinAcqPar.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinAcqu2s.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinAcqus.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinFid.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinMeta.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinOutd.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinProc2s.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinProcPar.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinProcs.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinPSet.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinSer.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinSpec.cc
# End Source File
# End Group
# Begin Group "Gnuplot"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\Ggnuplot.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\Ggnuplot1D.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\GgnuplotC.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\GgnuplotSph.cc
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\GamIO\BinIOBase.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\Gascii.cc
# End Source File
# End Group
# Begin Group "HSLib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\HSLib\Basis.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\GenOp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\GenOpRep.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSacquire.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSanalyze.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSauxil.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSdecomp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSdetect.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSham.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSprop.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\PulseI.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\PulseS.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\PulseShp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOpCmp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOpRot.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOpSng.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinSys.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinSystem.cc
# End Source File
# End Group
# Begin Group "Level1"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Level1\coord.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\coord_vec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\Exponential.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\ExProcessM.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\Lorentzian.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\nmr_tensor.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\SpaceT.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\SphHarmic.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\SpinT.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\Wigner.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\WindowFct.cc
# End Source File
# End Group
# Begin Group "Bloch"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Bloch\Bloch.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochAcq.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochB.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochK.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochM.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochMx.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochR.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochSys.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochTraj.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\DetVec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\MagVec.cc
# End Source File
# End Group
# Begin Group "BWR"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\WBR\relaxanalyze.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxAux.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxCSA.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxDCSA.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxDip.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxExch.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxJ.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxNMR.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxProp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxQCSA.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxQuad.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxRand.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxRF.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxWBRexch.cc
# End Source File
# End Group
# Begin Group "Pulses"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Pulses\PulAuxil.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulCHIRP.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulComposite.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulCycle.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulDANTE.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulGARP.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulGauss.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulMLEV.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\Pulse.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulSinc.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulSupCycle.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulTrain.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulTrainSCyc.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulWALTZ.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulWaveform.cc
# End Source File
# End Group
# Begin Group "LSLib"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\LSLib\DensOp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSacquire.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSanalyze.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSAux.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSprop.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\SuperOp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\sys_dynamic.cc
# End Source File
# End Group
# Begin Group "Level2"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Level2\acquire1D.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\BaseDecomp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\EAngles.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\Quaternion.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\RelaxBas.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\TrnsTable1D.cc
# End Source File
# End Group
# Begin Group "IntRank2"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\IntRank2\CartMx2A.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\CompRot.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\FrameMap.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HDipolar.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HElectronG.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HQuadrup.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HShiftAnis.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntCSA.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntCSAVec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntDip.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntDipVec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntG.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntGVec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntHF.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntHFVec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntQuad.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntQuadVec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2A.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2ACmp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2T.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\SolidSys.cc
# End Source File
# End Group
# Begin Group "Floquet"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Floquet\Floq2Op.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Floquet\FloqAcq.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Floquet\FloqOp.cc
# End Source File
# End Group
# Begin Group "Gradients"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Gradients\Gradients2.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdAcquire.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdDeprec.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdEvolve.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdPulses.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\sys_gradz.cc
# End Source File
# End Group
# Begin Group "Multisys"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\MultiSys\ExProcess.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiAux.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiExch.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiHam.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiHSLib.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiIPul.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiLib.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiLOp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiSOp.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiSys.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiWBR.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\SpinMap.cc
# End Source File
# End Group
# Begin Group "ESRLib"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\ESRLib\CubicIon.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\ESRLib\CubicIonData.cc
# End Source File
# End Group
# Begin Group "Deprecated"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Deprecated\acquire.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Deprecated\block_1D.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Deprecated\block_2D.cc
# End Source File
# End Group
# Begin Group "Testing"

# PROP Default_Filter ".cc"
# Begin Source File

SOURCE=..\..\src\Testing\ClassTest.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\ConstTest.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\GamTest.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\ModTest.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\SectTest.cc
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\SingleTest.cc
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\PyGammaIF.cc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Basicsh"

# PROP Default_Filter ".h"
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
# Begin Group "Matrixh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Matrix\_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\col_vector.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\complex.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\d_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\h_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\i_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\MxModBas.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\n_matrix.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Matrix\row_vector.h
# End Source File
# End Group
# Begin Group "GamIOh"

# PROP Default_Filter ".h"
# Begin Group "FrameMakerHdr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMaker.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerC.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerM.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerP.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerS.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\FrameMakerSph.h
# End Source File
# End Group
# Begin Group "Matlab.Hdr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\MatLabFile.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML4DElem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML4Tag.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5AF.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5AN.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5DA.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5DElem.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Hdr.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Imags.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Reals.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5SubE.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\ML5Tag.h
# End Source File
# End Group
# Begin Group "XWinNMRHdr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\XWin1D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWin2D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinAcqPar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinAcqu2s.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinAcqus.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinFid.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinMeta.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinOutd.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinProc2s.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinProcPar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinProcs.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinPSet.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinSer.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\XWinSpec.h
# End Source File
# End Group
# Begin Group "GnuplotHdr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\GamIO\Ggnuplot.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\Ggnuplot1D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\GgnuplotC.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\GgnuplotSph.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\GamIO\BinIOBase.h
# End Source File
# Begin Source File

SOURCE=..\..\src\GamIO\Gascii.h
# End Source File
# End Group
# Begin Group "HSLibh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\HSLib\Basis.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\GenOp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\GenOpRep.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSacquire.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSanalyze.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSauxil.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSdecomp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSdetect.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSham.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSLibIF.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\HSprop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\PulseI.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\PulseS.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\PulseShp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOpCmp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOpRot.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinOpSng.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinSys.h
# End Source File
# Begin Source File

SOURCE=..\..\src\HSLib\SpinSystem.h
# End Source File
# End Group
# Begin Group "Level1h"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Level1\coord.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\coord_vec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\Exponential.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\ExProcessM.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\Lorentzian.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\nmr_tensor.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\SpaceT.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\SphHarmic.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\SpinT.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\Wigner.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level1\WindowFct.h
# End Source File
# End Group
# Begin Group "Blochh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Bloch\Bloch.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochAcq.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochB.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochIF.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochK.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochM.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochMx.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochR.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochSys.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\BlochTraj.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\DetVec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Bloch\MagVec.h
# End Source File
# End Group
# Begin Group "BWRh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\WBR\relaxanalyze.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxAux.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxCSA.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxDCSA.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxDip.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxExch.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxJ.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxNMR.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxProp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxQCSA.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxQuad.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxRand.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxRF.h
# End Source File
# Begin Source File

SOURCE=..\..\src\WBR\relaxWBRexch.h
# End Source File
# End Group
# Begin Group "Pulsesh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Pulses\PulAuxil.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulCHIRP.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulComposite.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulCycle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulDANTE.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulGARP.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulGauss.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulMLEV.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\Pulse.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulSinc.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulSupCycle.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulTrain.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulTrainSCyc.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulWALTZ.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Pulses\PulWaveform.h
# End Source File
# End Group
# Begin Group "LSLibh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\LSLib\DensOp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSacquire.h
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSanalyze.h
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSAux.h
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\LSprop.h
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\SuperOp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\LSLib\sys_dynamic.h
# End Source File
# End Group
# Begin Group "Level2h"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Level2\acquire1D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\BaseDecomp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\EAngles.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\MutExch.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\Quaternion.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\RelaxBas.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Level2\TrnsTable1D.h
# End Source File
# End Group
# Begin Group "Floqueth"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=..\..\src\Floquet\Floq2Op.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Floquet\FloqAcq.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Floquet\FloqOp.h
# End Source File
# End Group
# Begin Group "IntRank2h"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\IntRank2\CartMx2A.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\CompRot.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\FrameMap.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HDipolar.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HElectronG.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HQuadrup.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\HShiftAnis.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntCSA.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntCSAVec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntDip.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntDipVec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntG.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntGVec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntHF.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntHFVec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntQuad.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntQuadVec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2A.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2ACmp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\IntRank2T.h
# End Source File
# Begin Source File

SOURCE=..\..\src\IntRank2\SolidSys.h
# End Source File
# End Group
# Begin Group "Gradientsh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Gradients\Gradients2.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdAcquire.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdDeprec.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdEvolve.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\GrdPulses.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Gradients\sys_gradz.h
# End Source File
# End Group
# Begin Group "MultiSysh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\MultiSys\ExProcess.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiAux.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiExch.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiHam.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiHSLib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiIPul.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiLib.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiLOp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiSOp.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiSys.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\MultiWBR.h
# End Source File
# Begin Source File

SOURCE=..\..\src\MultiSys\SpinMap.h
# End Source File
# End Group
# Begin Group "ESRLibh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\ESRLib\CubicIon.h
# End Source File
# Begin Source File

SOURCE=..\..\src\ESRLib\CubicIonData.h
# End Source File
# End Group
# Begin Group "Deprecatedh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Deprecated\acquire.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Deprecated\block_1D.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Deprecated\block_2D.h
# End Source File
# End Group
# Begin Group "Testingh"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\src\Testing\ClassTest.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\ConstTest.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\GamTest.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\ModTest.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\SectTest.h
# End Source File
# Begin Source File

SOURCE=..\..\src\Testing\SingleTest.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\src\GamGen.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gamma.h
# End Source File
# Begin Source File

SOURCE=..\..\src\PyGammaIF.h
# End Source File
# End Group
# End Target
# End Project
