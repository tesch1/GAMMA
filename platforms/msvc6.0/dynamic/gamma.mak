# Microsoft Developer Studio Generated NMAKE File, Based on gamma.dsp
!IF "$(CFG)" == ""
CFG=gamma - Win32 Debug
!MESSAGE No configuration specified. Defaulting to gamma - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "gamma - Win32 Release" && "$(CFG)" != "gamma - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gamma.mak" CFG="gamma - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "gamma - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "gamma - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "gamma - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release

ALL : "..\..\i686-pc-msvc\gamma.dll"


CLEAN :
	-@erase "$(INTDIR)\_matrix.obj"
	-@erase "$(INTDIR)\acquire.obj"
	-@erase "$(INTDIR)\acquire1D.obj"
	-@erase "$(INTDIR)\BaseDecomp.obj"
	-@erase "$(INTDIR)\Basis.obj"
	-@erase "$(INTDIR)\BinIOBase.obj"
	-@erase "$(INTDIR)\Bloch.obj"
	-@erase "$(INTDIR)\BlochAcq.obj"
	-@erase "$(INTDIR)\BlochB.obj"
	-@erase "$(INTDIR)\BlochK.obj"
	-@erase "$(INTDIR)\BlochM.obj"
	-@erase "$(INTDIR)\BlochMx.obj"
	-@erase "$(INTDIR)\BlochR.obj"
	-@erase "$(INTDIR)\BlochSys.obj"
	-@erase "$(INTDIR)\BlochTraj.obj"
	-@erase "$(INTDIR)\block_1D.obj"
	-@erase "$(INTDIR)\block_2D.obj"
	-@erase "$(INTDIR)\CartMx2A.obj"
	-@erase "$(INTDIR)\ClassTest.obj"
	-@erase "$(INTDIR)\col_vector.obj"
	-@erase "$(INTDIR)\complex.obj"
	-@erase "$(INTDIR)\CompRot.obj"
	-@erase "$(INTDIR)\ConstTest.obj"
	-@erase "$(INTDIR)\coord.obj"
	-@erase "$(INTDIR)\coord_vec.obj"
	-@erase "$(INTDIR)\CubicIon.obj"
	-@erase "$(INTDIR)\CubicIonData.obj"
	-@erase "$(INTDIR)\CubicSys.obj"
	-@erase "$(INTDIR)\d_matrix.obj"
	-@erase "$(INTDIR)\DensOp.obj"
	-@erase "$(INTDIR)\DetVec.obj"
	-@erase "$(INTDIR)\EAngles.obj"
	-@erase "$(INTDIR)\Exponential.obj"
	-@erase "$(INTDIR)\ExProcess.obj"
	-@erase "$(INTDIR)\ExProcessM.obj"
	-@erase "$(INTDIR)\Floq2Op.obj"
	-@erase "$(INTDIR)\FloqAcq.obj"
	-@erase "$(INTDIR)\FloqOp.obj"
	-@erase "$(INTDIR)\FrameMaker.obj"
	-@erase "$(INTDIR)\FrameMakerC.obj"
	-@erase "$(INTDIR)\FrameMakerM.obj"
	-@erase "$(INTDIR)\FrameMakerP.obj"
	-@erase "$(INTDIR)\FrameMakerS.obj"
	-@erase "$(INTDIR)\FrameMakerSph.obj"
	-@erase "$(INTDIR)\FrameMap.obj"
	-@erase "$(INTDIR)\GamTest.obj"
	-@erase "$(INTDIR)\Gascii.obj"
	-@erase "$(INTDIR)\Gconstants.obj"
	-@erase "$(INTDIR)\GenOp.obj"
	-@erase "$(INTDIR)\GenOpRep.obj"
	-@erase "$(INTDIR)\Ggnuplot.obj"
	-@erase "$(INTDIR)\Ggnuplot1D.obj"
	-@erase "$(INTDIR)\GgnuplotC.obj"
	-@erase "$(INTDIR)\GgnuplotSph.obj"
	-@erase "$(INTDIR)\Gradients2.obj"
	-@erase "$(INTDIR)\GrdAcquire.obj"
	-@erase "$(INTDIR)\GrdDeprec.obj"
	-@erase "$(INTDIR)\GrdEvolve.obj"
	-@erase "$(INTDIR)\GrdPulses.obj"
	-@erase "$(INTDIR)\Gutils.obj"
	-@erase "$(INTDIR)\h_matrix.obj"
	-@erase "$(INTDIR)\HDipolar.obj"
	-@erase "$(INTDIR)\HElectronG.obj"
	-@erase "$(INTDIR)\HQuadrup.obj"
	-@erase "$(INTDIR)\HSacquire.obj"
	-@erase "$(INTDIR)\HSanalyze.obj"
	-@erase "$(INTDIR)\HSauxil.obj"
	-@erase "$(INTDIR)\HSdecomp.obj"
	-@erase "$(INTDIR)\HSdetect.obj"
	-@erase "$(INTDIR)\HSham.obj"
	-@erase "$(INTDIR)\HShiftAnis.obj"
	-@erase "$(INTDIR)\HSprop.obj"
	-@erase "$(INTDIR)\i_matrix.obj"
	-@erase "$(INTDIR)\IntCSA.obj"
	-@erase "$(INTDIR)\IntCSAVec.obj"
	-@erase "$(INTDIR)\IntDip.obj"
	-@erase "$(INTDIR)\IntDipVec.obj"
	-@erase "$(INTDIR)\IntG.obj"
	-@erase "$(INTDIR)\IntGVec.obj"
	-@erase "$(INTDIR)\IntHF.obj"
	-@erase "$(INTDIR)\IntHFVec.obj"
	-@erase "$(INTDIR)\IntQuad.obj"
	-@erase "$(INTDIR)\IntQuadVec.obj"
	-@erase "$(INTDIR)\IntRank2.obj"
	-@erase "$(INTDIR)\IntRank2A.obj"
	-@erase "$(INTDIR)\IntRank2ACmp.obj"
	-@erase "$(INTDIR)\IntRank2T.obj"
	-@erase "$(INTDIR)\Isotope.obj"
	-@erase "$(INTDIR)\IsotopeData.obj"
	-@erase "$(INTDIR)\Lorentzian.obj"
	-@erase "$(INTDIR)\LSacquire.obj"
	-@erase "$(INTDIR)\LSanalyze.obj"
	-@erase "$(INTDIR)\LSAux.obj"
	-@erase "$(INTDIR)\LSprop.obj"
	-@erase "$(INTDIR)\MagIon.obj"
	-@erase "$(INTDIR)\MagVec.obj"
	-@erase "$(INTDIR)\MatLabFile.obj"
	-@erase "$(INTDIR)\matrix.obj"
	-@erase "$(INTDIR)\ML4DElem.obj"
	-@erase "$(INTDIR)\ML4Tag.obj"
	-@erase "$(INTDIR)\ML5AF.obj"
	-@erase "$(INTDIR)\ML5AN.obj"
	-@erase "$(INTDIR)\ML5DA.obj"
	-@erase "$(INTDIR)\ML5DElem.obj"
	-@erase "$(INTDIR)\ML5Hdr.obj"
	-@erase "$(INTDIR)\ML5Imags.obj"
	-@erase "$(INTDIR)\ML5Reals.obj"
	-@erase "$(INTDIR)\ML5SubE.obj"
	-@erase "$(INTDIR)\ML5Tag.obj"
	-@erase "$(INTDIR)\ModTest.obj"
	-@erase "$(INTDIR)\MultiAux.obj"
	-@erase "$(INTDIR)\MultiExch.obj"
	-@erase "$(INTDIR)\MultiHam.obj"
	-@erase "$(INTDIR)\MultiHSLib.obj"
	-@erase "$(INTDIR)\MultiIPul.obj"
	-@erase "$(INTDIR)\MultiLib.obj"
	-@erase "$(INTDIR)\MultiLOp.obj"
	-@erase "$(INTDIR)\MultiSOp.obj"
	-@erase "$(INTDIR)\MultiSys.obj"
	-@erase "$(INTDIR)\MultiWBR.obj"
	-@erase "$(INTDIR)\MutExch.obj"
	-@erase "$(INTDIR)\MxModBas.obj"
	-@erase "$(INTDIR)\n_matrix.obj"
	-@erase "$(INTDIR)\nmr_tensor.obj"
	-@erase "$(INTDIR)\ParamSet.obj"
	-@erase "$(INTDIR)\PulAuxil.obj"
	-@erase "$(INTDIR)\PulCHIRP.obj"
	-@erase "$(INTDIR)\PulComposite.obj"
	-@erase "$(INTDIR)\PulCycle.obj"
	-@erase "$(INTDIR)\PulDANTE.obj"
	-@erase "$(INTDIR)\PulGARP.obj"
	-@erase "$(INTDIR)\PulGauss.obj"
	-@erase "$(INTDIR)\PulMLEV.obj"
	-@erase "$(INTDIR)\Pulse.obj"
	-@erase "$(INTDIR)\PulseI.obj"
	-@erase "$(INTDIR)\PulseS.obj"
	-@erase "$(INTDIR)\PulseShp.obj"
	-@erase "$(INTDIR)\PulSinc.obj"
	-@erase "$(INTDIR)\PulSupCycle.obj"
	-@erase "$(INTDIR)\PulTrain.obj"
	-@erase "$(INTDIR)\PulTrainSCyc.obj"
	-@erase "$(INTDIR)\PulWALTZ.obj"
	-@erase "$(INTDIR)\PulWaveform.obj"
	-@erase "$(INTDIR)\Quaternion.obj"
	-@erase "$(INTDIR)\relaxanalyze.obj"
	-@erase "$(INTDIR)\relaxAux.obj"
	-@erase "$(INTDIR)\RelaxBas.obj"
	-@erase "$(INTDIR)\relaxBWRexch.obj"
	-@erase "$(INTDIR)\relaxCSA.obj"
	-@erase "$(INTDIR)\relaxDCSA.obj"
	-@erase "$(INTDIR)\relaxDip.obj"
	-@erase "$(INTDIR)\relaxExch.obj"
	-@erase "$(INTDIR)\relaxJ.obj"
	-@erase "$(INTDIR)\relaxNMR.obj"
	-@erase "$(INTDIR)\relaxProp.obj"
	-@erase "$(INTDIR)\relaxQCSA.obj"
	-@erase "$(INTDIR)\relaxQuad.obj"
	-@erase "$(INTDIR)\relaxRand.obj"
	-@erase "$(INTDIR)\relaxRF.obj"
	-@erase "$(INTDIR)\row_vector.obj"
	-@erase "$(INTDIR)\SectTest.obj"
	-@erase "$(INTDIR)\SinglePar.obj"
	-@erase "$(INTDIR)\SingleTest.obj"
	-@erase "$(INTDIR)\SolidSys.obj"
	-@erase "$(INTDIR)\SpaceT.obj"
	-@erase "$(INTDIR)\SphHarmic.obj"
	-@erase "$(INTDIR)\SpinMap.obj"
	-@erase "$(INTDIR)\SpinOp.obj"
	-@erase "$(INTDIR)\SpinOpCmp.obj"
	-@erase "$(INTDIR)\SpinOpRot.obj"
	-@erase "$(INTDIR)\SpinOpSng.obj"
	-@erase "$(INTDIR)\SpinSys.obj"
	-@erase "$(INTDIR)\SpinSystem.obj"
	-@erase "$(INTDIR)\SpinT.obj"
	-@erase "$(INTDIR)\StringCut.obj"
	-@erase "$(INTDIR)\SuperOp.obj"
	-@erase "$(INTDIR)\sys_dynamic.obj"
	-@erase "$(INTDIR)\sys_gradz.obj"
	-@erase "$(INTDIR)\TrnsTable1D.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\Wigner.obj"
	-@erase "$(INTDIR)\WindowFct.obj"
	-@erase "$(INTDIR)\XWin1D.obj"
	-@erase "$(INTDIR)\XWin2D.obj"
	-@erase "$(INTDIR)\XWinAcqPar.obj"
	-@erase "$(INTDIR)\XWinAcqu2s.obj"
	-@erase "$(INTDIR)\XWinAcqus.obj"
	-@erase "$(INTDIR)\XWinFid.obj"
	-@erase "$(INTDIR)\XWinMeta.obj"
	-@erase "$(INTDIR)\XWinOutd.obj"
	-@erase "$(INTDIR)\XWinProc2s.obj"
	-@erase "$(INTDIR)\XWinProcPar.obj"
	-@erase "$(INTDIR)\XWinProcs.obj"
	-@erase "$(INTDIR)\XWinPSet.obj"
	-@erase "$(INTDIR)\XWinSer.obj"
	-@erase "$(INTDIR)\XWinSpec.obj"
	-@erase "$(OUTDIR)\gamma.pdb"
	-@erase "..\..\i686-pc-msvc\gamma.dll"
	-@erase "..\..\i686-pc-msvc\gamma.dll.exp"
	-@erase "..\..\i686-pc-msvc\gamma.dll.lib"
	-@erase "..\..\i686-pc-msvc\gamma.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /GR /GX /O2 /I "..\..\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GAMMA_EXPORTS" /D MAKEDLL=1 /Fp"$(INTDIR)\gamma.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /TP /Zm200 /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\gamma.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\gamma.pdb" /debug /machine:I386 /out:"../../i686-pc-msvc/gamma.dll" /implib:"../../i686-pc-msvc/gamma.dll.lib" 
LINK32_OBJS= \
	"$(INTDIR)\Gconstants.obj" \
	"$(INTDIR)\Gutils.obj" \
	"$(INTDIR)\Isotope.obj" \
	"$(INTDIR)\IsotopeData.obj" \
	"$(INTDIR)\ParamSet.obj" \
	"$(INTDIR)\SinglePar.obj" \
	"$(INTDIR)\StringCut.obj" \
	"$(INTDIR)\_matrix.obj" \
	"$(INTDIR)\col_vector.obj" \
	"$(INTDIR)\complex.obj" \
	"$(INTDIR)\d_matrix.obj" \
	"$(INTDIR)\h_matrix.obj" \
	"$(INTDIR)\i_matrix.obj" \
	"$(INTDIR)\matrix.obj" \
	"$(INTDIR)\MxModBas.obj" \
	"$(INTDIR)\n_matrix.obj" \
	"$(INTDIR)\row_vector.obj" \
	"$(INTDIR)\Basis.obj" \
	"$(INTDIR)\GenOp.obj" \
	"$(INTDIR)\GenOpRep.obj" \
	"$(INTDIR)\HSacquire.obj" \
	"$(INTDIR)\HSanalyze.obj" \
	"$(INTDIR)\HSauxil.obj" \
	"$(INTDIR)\HSdecomp.obj" \
	"$(INTDIR)\HSdetect.obj" \
	"$(INTDIR)\HSham.obj" \
	"$(INTDIR)\HSprop.obj" \
	"$(INTDIR)\PulseI.obj" \
	"$(INTDIR)\PulseS.obj" \
	"$(INTDIR)\PulseShp.obj" \
	"$(INTDIR)\SpinOp.obj" \
	"$(INTDIR)\SpinOpCmp.obj" \
	"$(INTDIR)\SpinOpRot.obj" \
	"$(INTDIR)\SpinOpSng.obj" \
	"$(INTDIR)\SpinSys.obj" \
	"$(INTDIR)\SpinSystem.obj" \
	"$(INTDIR)\coord.obj" \
	"$(INTDIR)\coord_vec.obj" \
	"$(INTDIR)\Exponential.obj" \
	"$(INTDIR)\ExProcessM.obj" \
	"$(INTDIR)\Lorentzian.obj" \
	"$(INTDIR)\nmr_tensor.obj" \
	"$(INTDIR)\SpaceT.obj" \
	"$(INTDIR)\SphHarmic.obj" \
	"$(INTDIR)\SpinT.obj" \
	"$(INTDIR)\Wigner.obj" \
	"$(INTDIR)\WindowFct.obj" \
	"$(INTDIR)\DensOp.obj" \
	"$(INTDIR)\LSacquire.obj" \
	"$(INTDIR)\LSanalyze.obj" \
	"$(INTDIR)\LSAux.obj" \
	"$(INTDIR)\LSprop.obj" \
	"$(INTDIR)\SuperOp.obj" \
	"$(INTDIR)\sys_dynamic.obj" \
	"$(INTDIR)\acquire1D.obj" \
	"$(INTDIR)\BaseDecomp.obj" \
	"$(INTDIR)\EAngles.obj" \
	"$(INTDIR)\MutExch.obj" \
	"$(INTDIR)\Quaternion.obj" \
	"$(INTDIR)\RelaxBas.obj" \
	"$(INTDIR)\TrnsTable1D.obj" \
	"$(INTDIR)\XWin1D.obj" \
	"$(INTDIR)\XWin2D.obj" \
	"$(INTDIR)\XWinAcqPar.obj" \
	"$(INTDIR)\XWinAcqu2s.obj" \
	"$(INTDIR)\XWinAcqus.obj" \
	"$(INTDIR)\XWinFid.obj" \
	"$(INTDIR)\XWinMeta.obj" \
	"$(INTDIR)\XWinOutd.obj" \
	"$(INTDIR)\XWinProc2s.obj" \
	"$(INTDIR)\XWinProcPar.obj" \
	"$(INTDIR)\XWinProcs.obj" \
	"$(INTDIR)\XWinPSet.obj" \
	"$(INTDIR)\XWinSer.obj" \
	"$(INTDIR)\XWinSpec.obj" \
	"$(INTDIR)\MatLabFile.obj" \
	"$(INTDIR)\ML4DElem.obj" \
	"$(INTDIR)\ML4Tag.obj" \
	"$(INTDIR)\ML5AF.obj" \
	"$(INTDIR)\ML5AN.obj" \
	"$(INTDIR)\ML5DA.obj" \
	"$(INTDIR)\ML5DElem.obj" \
	"$(INTDIR)\ML5Hdr.obj" \
	"$(INTDIR)\ML5Imags.obj" \
	"$(INTDIR)\ML5Reals.obj" \
	"$(INTDIR)\ML5SubE.obj" \
	"$(INTDIR)\ML5Tag.obj" \
	"$(INTDIR)\FrameMaker.obj" \
	"$(INTDIR)\FrameMakerC.obj" \
	"$(INTDIR)\FrameMakerM.obj" \
	"$(INTDIR)\FrameMakerP.obj" \
	"$(INTDIR)\FrameMakerS.obj" \
	"$(INTDIR)\FrameMakerSph.obj" \
	"$(INTDIR)\Ggnuplot.obj" \
	"$(INTDIR)\Ggnuplot1D.obj" \
	"$(INTDIR)\GgnuplotC.obj" \
	"$(INTDIR)\GgnuplotSph.obj" \
	"$(INTDIR)\BinIOBase.obj" \
	"$(INTDIR)\Gascii.obj" \
	"$(INTDIR)\Bloch.obj" \
	"$(INTDIR)\BlochAcq.obj" \
	"$(INTDIR)\BlochB.obj" \
	"$(INTDIR)\BlochK.obj" \
	"$(INTDIR)\BlochM.obj" \
	"$(INTDIR)\BlochMx.obj" \
	"$(INTDIR)\BlochR.obj" \
	"$(INTDIR)\BlochSys.obj" \
	"$(INTDIR)\BlochTraj.obj" \
	"$(INTDIR)\DetVec.obj" \
	"$(INTDIR)\MagVec.obj" \
	"$(INTDIR)\acquire.obj" \
	"$(INTDIR)\block_1D.obj" \
	"$(INTDIR)\block_2D.obj" \
	"$(INTDIR)\CubicIon.obj" \
	"$(INTDIR)\CubicIonData.obj" \
	"$(INTDIR)\CubicSys.obj" \
	"$(INTDIR)\MagIon.obj" \
	"$(INTDIR)\Floq2Op.obj" \
	"$(INTDIR)\FloqAcq.obj" \
	"$(INTDIR)\FloqOp.obj" \
	"$(INTDIR)\PulAuxil.obj" \
	"$(INTDIR)\PulCHIRP.obj" \
	"$(INTDIR)\PulComposite.obj" \
	"$(INTDIR)\PulCycle.obj" \
	"$(INTDIR)\PulDANTE.obj" \
	"$(INTDIR)\PulGARP.obj" \
	"$(INTDIR)\PulGauss.obj" \
	"$(INTDIR)\PulMLEV.obj" \
	"$(INTDIR)\Pulse.obj" \
	"$(INTDIR)\PulSinc.obj" \
	"$(INTDIR)\PulSupCycle.obj" \
	"$(INTDIR)\PulTrain.obj" \
	"$(INTDIR)\PulTrainSCyc.obj" \
	"$(INTDIR)\PulWALTZ.obj" \
	"$(INTDIR)\PulWaveform.obj" \
	"$(INTDIR)\Gradients2.obj" \
	"$(INTDIR)\GrdAcquire.obj" \
	"$(INTDIR)\GrdDeprec.obj" \
	"$(INTDIR)\GrdEvolve.obj" \
	"$(INTDIR)\GrdPulses.obj" \
	"$(INTDIR)\sys_gradz.obj" \
	"$(INTDIR)\CartMx2A.obj" \
	"$(INTDIR)\CompRot.obj" \
	"$(INTDIR)\FrameMap.obj" \
	"$(INTDIR)\HDipolar.obj" \
	"$(INTDIR)\HElectronG.obj" \
	"$(INTDIR)\HQuadrup.obj" \
	"$(INTDIR)\HShiftAnis.obj" \
	"$(INTDIR)\IntCSA.obj" \
	"$(INTDIR)\IntCSAVec.obj" \
	"$(INTDIR)\IntDip.obj" \
	"$(INTDIR)\IntDipVec.obj" \
	"$(INTDIR)\IntG.obj" \
	"$(INTDIR)\IntGVec.obj" \
	"$(INTDIR)\IntHF.obj" \
	"$(INTDIR)\IntHFVec.obj" \
	"$(INTDIR)\IntQuad.obj" \
	"$(INTDIR)\IntQuadVec.obj" \
	"$(INTDIR)\IntRank2.obj" \
	"$(INTDIR)\IntRank2A.obj" \
	"$(INTDIR)\IntRank2ACmp.obj" \
	"$(INTDIR)\IntRank2T.obj" \
	"$(INTDIR)\SolidSys.obj" \
	"$(INTDIR)\ExProcess.obj" \
	"$(INTDIR)\MultiAux.obj" \
	"$(INTDIR)\MultiExch.obj" \
	"$(INTDIR)\MultiHam.obj" \
	"$(INTDIR)\MultiHSLib.obj" \
	"$(INTDIR)\MultiIPul.obj" \
	"$(INTDIR)\MultiLib.obj" \
	"$(INTDIR)\MultiLOp.obj" \
	"$(INTDIR)\MultiSOp.obj" \
	"$(INTDIR)\MultiSys.obj" \
	"$(INTDIR)\MultiWBR.obj" \
	"$(INTDIR)\SpinMap.obj" \
	"$(INTDIR)\ClassTest.obj" \
	"$(INTDIR)\ConstTest.obj" \
	"$(INTDIR)\GamTest.obj" \
	"$(INTDIR)\ModTest.obj" \
	"$(INTDIR)\SectTest.obj" \
	"$(INTDIR)\SingleTest.obj" \
	"$(INTDIR)\relaxRand.obj" \
	"$(INTDIR)\relaxAux.obj" \
	"$(INTDIR)\relaxBWRexch.obj" \
	"$(INTDIR)\relaxCSA.obj" \
	"$(INTDIR)\relaxDCSA.obj" \
	"$(INTDIR)\relaxDip.obj" \
	"$(INTDIR)\relaxExch.obj" \
	"$(INTDIR)\relaxJ.obj" \
	"$(INTDIR)\relaxNMR.obj" \
	"$(INTDIR)\relaxProp.obj" \
	"$(INTDIR)\relaxQCSA.obj" \
	"$(INTDIR)\relaxQuad.obj" \
	"$(INTDIR)\relaxanalyze.obj" \
	"$(INTDIR)\relaxRF.obj"

"..\..\i686-pc-msvc\gamma.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "gamma - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "..\..\i686-pc-msvc\gamma.dll"


CLEAN :
	-@erase "$(INTDIR)\_matrix.obj"
	-@erase "$(INTDIR)\acquire.obj"
	-@erase "$(INTDIR)\acquire1D.obj"
	-@erase "$(INTDIR)\BaseDecomp.obj"
	-@erase "$(INTDIR)\Basis.obj"
	-@erase "$(INTDIR)\BinIOBase.obj"
	-@erase "$(INTDIR)\Bloch.obj"
	-@erase "$(INTDIR)\BlochAcq.obj"
	-@erase "$(INTDIR)\BlochB.obj"
	-@erase "$(INTDIR)\BlochK.obj"
	-@erase "$(INTDIR)\BlochM.obj"
	-@erase "$(INTDIR)\BlochMx.obj"
	-@erase "$(INTDIR)\BlochR.obj"
	-@erase "$(INTDIR)\BlochSys.obj"
	-@erase "$(INTDIR)\BlochTraj.obj"
	-@erase "$(INTDIR)\block_1D.obj"
	-@erase "$(INTDIR)\block_2D.obj"
	-@erase "$(INTDIR)\CartMx2A.obj"
	-@erase "$(INTDIR)\ClassTest.obj"
	-@erase "$(INTDIR)\col_vector.obj"
	-@erase "$(INTDIR)\complex.obj"
	-@erase "$(INTDIR)\CompRot.obj"
	-@erase "$(INTDIR)\ConstTest.obj"
	-@erase "$(INTDIR)\coord.obj"
	-@erase "$(INTDIR)\coord_vec.obj"
	-@erase "$(INTDIR)\CubicIon.obj"
	-@erase "$(INTDIR)\CubicIonData.obj"
	-@erase "$(INTDIR)\CubicSys.obj"
	-@erase "$(INTDIR)\d_matrix.obj"
	-@erase "$(INTDIR)\DensOp.obj"
	-@erase "$(INTDIR)\DetVec.obj"
	-@erase "$(INTDIR)\EAngles.obj"
	-@erase "$(INTDIR)\Exponential.obj"
	-@erase "$(INTDIR)\ExProcess.obj"
	-@erase "$(INTDIR)\ExProcessM.obj"
	-@erase "$(INTDIR)\Floq2Op.obj"
	-@erase "$(INTDIR)\FloqAcq.obj"
	-@erase "$(INTDIR)\FloqOp.obj"
	-@erase "$(INTDIR)\FrameMaker.obj"
	-@erase "$(INTDIR)\FrameMakerC.obj"
	-@erase "$(INTDIR)\FrameMakerM.obj"
	-@erase "$(INTDIR)\FrameMakerP.obj"
	-@erase "$(INTDIR)\FrameMakerS.obj"
	-@erase "$(INTDIR)\FrameMakerSph.obj"
	-@erase "$(INTDIR)\FrameMap.obj"
	-@erase "$(INTDIR)\GamTest.obj"
	-@erase "$(INTDIR)\Gascii.obj"
	-@erase "$(INTDIR)\Gconstants.obj"
	-@erase "$(INTDIR)\GenOp.obj"
	-@erase "$(INTDIR)\GenOpRep.obj"
	-@erase "$(INTDIR)\Ggnuplot.obj"
	-@erase "$(INTDIR)\Ggnuplot1D.obj"
	-@erase "$(INTDIR)\GgnuplotC.obj"
	-@erase "$(INTDIR)\GgnuplotSph.obj"
	-@erase "$(INTDIR)\Gradients2.obj"
	-@erase "$(INTDIR)\GrdAcquire.obj"
	-@erase "$(INTDIR)\GrdDeprec.obj"
	-@erase "$(INTDIR)\GrdEvolve.obj"
	-@erase "$(INTDIR)\GrdPulses.obj"
	-@erase "$(INTDIR)\Gutils.obj"
	-@erase "$(INTDIR)\h_matrix.obj"
	-@erase "$(INTDIR)\HDipolar.obj"
	-@erase "$(INTDIR)\HElectronG.obj"
	-@erase "$(INTDIR)\HQuadrup.obj"
	-@erase "$(INTDIR)\HSacquire.obj"
	-@erase "$(INTDIR)\HSanalyze.obj"
	-@erase "$(INTDIR)\HSauxil.obj"
	-@erase "$(INTDIR)\HSdecomp.obj"
	-@erase "$(INTDIR)\HSdetect.obj"
	-@erase "$(INTDIR)\HSham.obj"
	-@erase "$(INTDIR)\HShiftAnis.obj"
	-@erase "$(INTDIR)\HSprop.obj"
	-@erase "$(INTDIR)\i_matrix.obj"
	-@erase "$(INTDIR)\IntCSA.obj"
	-@erase "$(INTDIR)\IntCSAVec.obj"
	-@erase "$(INTDIR)\IntDip.obj"
	-@erase "$(INTDIR)\IntDipVec.obj"
	-@erase "$(INTDIR)\IntG.obj"
	-@erase "$(INTDIR)\IntGVec.obj"
	-@erase "$(INTDIR)\IntHF.obj"
	-@erase "$(INTDIR)\IntHFVec.obj"
	-@erase "$(INTDIR)\IntQuad.obj"
	-@erase "$(INTDIR)\IntQuadVec.obj"
	-@erase "$(INTDIR)\IntRank2.obj"
	-@erase "$(INTDIR)\IntRank2A.obj"
	-@erase "$(INTDIR)\IntRank2ACmp.obj"
	-@erase "$(INTDIR)\IntRank2T.obj"
	-@erase "$(INTDIR)\Isotope.obj"
	-@erase "$(INTDIR)\IsotopeData.obj"
	-@erase "$(INTDIR)\Lorentzian.obj"
	-@erase "$(INTDIR)\LSacquire.obj"
	-@erase "$(INTDIR)\LSanalyze.obj"
	-@erase "$(INTDIR)\LSAux.obj"
	-@erase "$(INTDIR)\LSprop.obj"
	-@erase "$(INTDIR)\MagIon.obj"
	-@erase "$(INTDIR)\MagVec.obj"
	-@erase "$(INTDIR)\MatLabFile.obj"
	-@erase "$(INTDIR)\matrix.obj"
	-@erase "$(INTDIR)\ML4DElem.obj"
	-@erase "$(INTDIR)\ML4Tag.obj"
	-@erase "$(INTDIR)\ML5AF.obj"
	-@erase "$(INTDIR)\ML5AN.obj"
	-@erase "$(INTDIR)\ML5DA.obj"
	-@erase "$(INTDIR)\ML5DElem.obj"
	-@erase "$(INTDIR)\ML5Hdr.obj"
	-@erase "$(INTDIR)\ML5Imags.obj"
	-@erase "$(INTDIR)\ML5Reals.obj"
	-@erase "$(INTDIR)\ML5SubE.obj"
	-@erase "$(INTDIR)\ML5Tag.obj"
	-@erase "$(INTDIR)\ModTest.obj"
	-@erase "$(INTDIR)\MultiAux.obj"
	-@erase "$(INTDIR)\MultiExch.obj"
	-@erase "$(INTDIR)\MultiHam.obj"
	-@erase "$(INTDIR)\MultiHSLib.obj"
	-@erase "$(INTDIR)\MultiIPul.obj"
	-@erase "$(INTDIR)\MultiLib.obj"
	-@erase "$(INTDIR)\MultiLOp.obj"
	-@erase "$(INTDIR)\MultiSOp.obj"
	-@erase "$(INTDIR)\MultiSys.obj"
	-@erase "$(INTDIR)\MultiWBR.obj"
	-@erase "$(INTDIR)\MutExch.obj"
	-@erase "$(INTDIR)\MxModBas.obj"
	-@erase "$(INTDIR)\n_matrix.obj"
	-@erase "$(INTDIR)\nmr_tensor.obj"
	-@erase "$(INTDIR)\ParamSet.obj"
	-@erase "$(INTDIR)\PulAuxil.obj"
	-@erase "$(INTDIR)\PulCHIRP.obj"
	-@erase "$(INTDIR)\PulComposite.obj"
	-@erase "$(INTDIR)\PulCycle.obj"
	-@erase "$(INTDIR)\PulDANTE.obj"
	-@erase "$(INTDIR)\PulGARP.obj"
	-@erase "$(INTDIR)\PulGauss.obj"
	-@erase "$(INTDIR)\PulMLEV.obj"
	-@erase "$(INTDIR)\Pulse.obj"
	-@erase "$(INTDIR)\PulseI.obj"
	-@erase "$(INTDIR)\PulseS.obj"
	-@erase "$(INTDIR)\PulseShp.obj"
	-@erase "$(INTDIR)\PulSinc.obj"
	-@erase "$(INTDIR)\PulSupCycle.obj"
	-@erase "$(INTDIR)\PulTrain.obj"
	-@erase "$(INTDIR)\PulTrainSCyc.obj"
	-@erase "$(INTDIR)\PulWALTZ.obj"
	-@erase "$(INTDIR)\PulWaveform.obj"
	-@erase "$(INTDIR)\Quaternion.obj"
	-@erase "$(INTDIR)\relaxanalyze.obj"
	-@erase "$(INTDIR)\relaxAux.obj"
	-@erase "$(INTDIR)\RelaxBas.obj"
	-@erase "$(INTDIR)\relaxBWRexch.obj"
	-@erase "$(INTDIR)\relaxCSA.obj"
	-@erase "$(INTDIR)\relaxDCSA.obj"
	-@erase "$(INTDIR)\relaxDip.obj"
	-@erase "$(INTDIR)\relaxExch.obj"
	-@erase "$(INTDIR)\relaxJ.obj"
	-@erase "$(INTDIR)\relaxNMR.obj"
	-@erase "$(INTDIR)\relaxProp.obj"
	-@erase "$(INTDIR)\relaxQCSA.obj"
	-@erase "$(INTDIR)\relaxQuad.obj"
	-@erase "$(INTDIR)\relaxRand.obj"
	-@erase "$(INTDIR)\relaxRF.obj"
	-@erase "$(INTDIR)\row_vector.obj"
	-@erase "$(INTDIR)\SectTest.obj"
	-@erase "$(INTDIR)\SinglePar.obj"
	-@erase "$(INTDIR)\SingleTest.obj"
	-@erase "$(INTDIR)\SolidSys.obj"
	-@erase "$(INTDIR)\SpaceT.obj"
	-@erase "$(INTDIR)\SphHarmic.obj"
	-@erase "$(INTDIR)\SpinMap.obj"
	-@erase "$(INTDIR)\SpinOp.obj"
	-@erase "$(INTDIR)\SpinOpCmp.obj"
	-@erase "$(INTDIR)\SpinOpRot.obj"
	-@erase "$(INTDIR)\SpinOpSng.obj"
	-@erase "$(INTDIR)\SpinSys.obj"
	-@erase "$(INTDIR)\SpinSystem.obj"
	-@erase "$(INTDIR)\SpinT.obj"
	-@erase "$(INTDIR)\StringCut.obj"
	-@erase "$(INTDIR)\SuperOp.obj"
	-@erase "$(INTDIR)\sys_dynamic.obj"
	-@erase "$(INTDIR)\sys_gradz.obj"
	-@erase "$(INTDIR)\TrnsTable1D.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\Wigner.obj"
	-@erase "$(INTDIR)\WindowFct.obj"
	-@erase "$(INTDIR)\XWin1D.obj"
	-@erase "$(INTDIR)\XWin2D.obj"
	-@erase "$(INTDIR)\XWinAcqPar.obj"
	-@erase "$(INTDIR)\XWinAcqu2s.obj"
	-@erase "$(INTDIR)\XWinAcqus.obj"
	-@erase "$(INTDIR)\XWinFid.obj"
	-@erase "$(INTDIR)\XWinMeta.obj"
	-@erase "$(INTDIR)\XWinOutd.obj"
	-@erase "$(INTDIR)\XWinProc2s.obj"
	-@erase "$(INTDIR)\XWinProcPar.obj"
	-@erase "$(INTDIR)\XWinProcs.obj"
	-@erase "$(INTDIR)\XWinPSet.obj"
	-@erase "$(INTDIR)\XWinSer.obj"
	-@erase "$(INTDIR)\XWinSpec.obj"
	-@erase "$(OUTDIR)\gamma.pdb"
	-@erase "..\..\i686-pc-msvc\gamma.dll"
	-@erase "..\..\i686-pc-msvc\gamma.dll.exp"
	-@erase "..\..\i686-pc-msvc\gamma.dll.lib"
	-@erase "..\..\i686-pc-msvc\gamma.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "GAMMA_EXPORTS" /D MAKEDLL=1 /Fp"$(INTDIR)\gamma.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /TP /Zm200 /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\gamma.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\gamma.pdb" /debug /machine:I386 /out:"../../i686-pc-msvc/gamma.dll" /implib:"../../i686-pc-msvc/gamma.dll.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Gconstants.obj" \
	"$(INTDIR)\Gutils.obj" \
	"$(INTDIR)\Isotope.obj" \
	"$(INTDIR)\IsotopeData.obj" \
	"$(INTDIR)\ParamSet.obj" \
	"$(INTDIR)\SinglePar.obj" \
	"$(INTDIR)\StringCut.obj" \
	"$(INTDIR)\_matrix.obj" \
	"$(INTDIR)\col_vector.obj" \
	"$(INTDIR)\complex.obj" \
	"$(INTDIR)\d_matrix.obj" \
	"$(INTDIR)\h_matrix.obj" \
	"$(INTDIR)\i_matrix.obj" \
	"$(INTDIR)\matrix.obj" \
	"$(INTDIR)\MxModBas.obj" \
	"$(INTDIR)\n_matrix.obj" \
	"$(INTDIR)\row_vector.obj" \
	"$(INTDIR)\Basis.obj" \
	"$(INTDIR)\GenOp.obj" \
	"$(INTDIR)\GenOpRep.obj" \
	"$(INTDIR)\HSacquire.obj" \
	"$(INTDIR)\HSanalyze.obj" \
	"$(INTDIR)\HSauxil.obj" \
	"$(INTDIR)\HSdecomp.obj" \
	"$(INTDIR)\HSdetect.obj" \
	"$(INTDIR)\HSham.obj" \
	"$(INTDIR)\HSprop.obj" \
	"$(INTDIR)\PulseI.obj" \
	"$(INTDIR)\PulseS.obj" \
	"$(INTDIR)\PulseShp.obj" \
	"$(INTDIR)\SpinOp.obj" \
	"$(INTDIR)\SpinOpCmp.obj" \
	"$(INTDIR)\SpinOpRot.obj" \
	"$(INTDIR)\SpinOpSng.obj" \
	"$(INTDIR)\SpinSys.obj" \
	"$(INTDIR)\SpinSystem.obj" \
	"$(INTDIR)\coord.obj" \
	"$(INTDIR)\coord_vec.obj" \
	"$(INTDIR)\Exponential.obj" \
	"$(INTDIR)\ExProcessM.obj" \
	"$(INTDIR)\Lorentzian.obj" \
	"$(INTDIR)\nmr_tensor.obj" \
	"$(INTDIR)\SpaceT.obj" \
	"$(INTDIR)\SphHarmic.obj" \
	"$(INTDIR)\SpinT.obj" \
	"$(INTDIR)\Wigner.obj" \
	"$(INTDIR)\WindowFct.obj" \
	"$(INTDIR)\DensOp.obj" \
	"$(INTDIR)\LSacquire.obj" \
	"$(INTDIR)\LSanalyze.obj" \
	"$(INTDIR)\LSAux.obj" \
	"$(INTDIR)\LSprop.obj" \
	"$(INTDIR)\SuperOp.obj" \
	"$(INTDIR)\sys_dynamic.obj" \
	"$(INTDIR)\acquire1D.obj" \
	"$(INTDIR)\BaseDecomp.obj" \
	"$(INTDIR)\EAngles.obj" \
	"$(INTDIR)\MutExch.obj" \
	"$(INTDIR)\Quaternion.obj" \
	"$(INTDIR)\RelaxBas.obj" \
	"$(INTDIR)\TrnsTable1D.obj" \
	"$(INTDIR)\XWin1D.obj" \
	"$(INTDIR)\XWin2D.obj" \
	"$(INTDIR)\XWinAcqPar.obj" \
	"$(INTDIR)\XWinAcqu2s.obj" \
	"$(INTDIR)\XWinAcqus.obj" \
	"$(INTDIR)\XWinFid.obj" \
	"$(INTDIR)\XWinMeta.obj" \
	"$(INTDIR)\XWinOutd.obj" \
	"$(INTDIR)\XWinProc2s.obj" \
	"$(INTDIR)\XWinProcPar.obj" \
	"$(INTDIR)\XWinProcs.obj" \
	"$(INTDIR)\XWinPSet.obj" \
	"$(INTDIR)\XWinSer.obj" \
	"$(INTDIR)\XWinSpec.obj" \
	"$(INTDIR)\MatLabFile.obj" \
	"$(INTDIR)\ML4DElem.obj" \
	"$(INTDIR)\ML4Tag.obj" \
	"$(INTDIR)\ML5AF.obj" \
	"$(INTDIR)\ML5AN.obj" \
	"$(INTDIR)\ML5DA.obj" \
	"$(INTDIR)\ML5DElem.obj" \
	"$(INTDIR)\ML5Hdr.obj" \
	"$(INTDIR)\ML5Imags.obj" \
	"$(INTDIR)\ML5Reals.obj" \
	"$(INTDIR)\ML5SubE.obj" \
	"$(INTDIR)\ML5Tag.obj" \
	"$(INTDIR)\FrameMaker.obj" \
	"$(INTDIR)\FrameMakerC.obj" \
	"$(INTDIR)\FrameMakerM.obj" \
	"$(INTDIR)\FrameMakerP.obj" \
	"$(INTDIR)\FrameMakerS.obj" \
	"$(INTDIR)\FrameMakerSph.obj" \
	"$(INTDIR)\Ggnuplot.obj" \
	"$(INTDIR)\Ggnuplot1D.obj" \
	"$(INTDIR)\GgnuplotC.obj" \
	"$(INTDIR)\GgnuplotSph.obj" \
	"$(INTDIR)\BinIOBase.obj" \
	"$(INTDIR)\Gascii.obj" \
	"$(INTDIR)\Bloch.obj" \
	"$(INTDIR)\BlochAcq.obj" \
	"$(INTDIR)\BlochB.obj" \
	"$(INTDIR)\BlochK.obj" \
	"$(INTDIR)\BlochM.obj" \
	"$(INTDIR)\BlochMx.obj" \
	"$(INTDIR)\BlochR.obj" \
	"$(INTDIR)\BlochSys.obj" \
	"$(INTDIR)\BlochTraj.obj" \
	"$(INTDIR)\DetVec.obj" \
	"$(INTDIR)\MagVec.obj" \
	"$(INTDIR)\acquire.obj" \
	"$(INTDIR)\block_1D.obj" \
	"$(INTDIR)\block_2D.obj" \
	"$(INTDIR)\CubicIon.obj" \
	"$(INTDIR)\CubicIonData.obj" \
	"$(INTDIR)\CubicSys.obj" \
	"$(INTDIR)\MagIon.obj" \
	"$(INTDIR)\Floq2Op.obj" \
	"$(INTDIR)\FloqAcq.obj" \
	"$(INTDIR)\FloqOp.obj" \
	"$(INTDIR)\PulAuxil.obj" \
	"$(INTDIR)\PulCHIRP.obj" \
	"$(INTDIR)\PulComposite.obj" \
	"$(INTDIR)\PulCycle.obj" \
	"$(INTDIR)\PulDANTE.obj" \
	"$(INTDIR)\PulGARP.obj" \
	"$(INTDIR)\PulGauss.obj" \
	"$(INTDIR)\PulMLEV.obj" \
	"$(INTDIR)\Pulse.obj" \
	"$(INTDIR)\PulSinc.obj" \
	"$(INTDIR)\PulSupCycle.obj" \
	"$(INTDIR)\PulTrain.obj" \
	"$(INTDIR)\PulTrainSCyc.obj" \
	"$(INTDIR)\PulWALTZ.obj" \
	"$(INTDIR)\PulWaveform.obj" \
	"$(INTDIR)\Gradients2.obj" \
	"$(INTDIR)\GrdAcquire.obj" \
	"$(INTDIR)\GrdDeprec.obj" \
	"$(INTDIR)\GrdEvolve.obj" \
	"$(INTDIR)\GrdPulses.obj" \
	"$(INTDIR)\sys_gradz.obj" \
	"$(INTDIR)\CartMx2A.obj" \
	"$(INTDIR)\CompRot.obj" \
	"$(INTDIR)\FrameMap.obj" \
	"$(INTDIR)\HDipolar.obj" \
	"$(INTDIR)\HElectronG.obj" \
	"$(INTDIR)\HQuadrup.obj" \
	"$(INTDIR)\HShiftAnis.obj" \
	"$(INTDIR)\IntCSA.obj" \
	"$(INTDIR)\IntCSAVec.obj" \
	"$(INTDIR)\IntDip.obj" \
	"$(INTDIR)\IntDipVec.obj" \
	"$(INTDIR)\IntG.obj" \
	"$(INTDIR)\IntGVec.obj" \
	"$(INTDIR)\IntHF.obj" \
	"$(INTDIR)\IntHFVec.obj" \
	"$(INTDIR)\IntQuad.obj" \
	"$(INTDIR)\IntQuadVec.obj" \
	"$(INTDIR)\IntRank2.obj" \
	"$(INTDIR)\IntRank2A.obj" \
	"$(INTDIR)\IntRank2ACmp.obj" \
	"$(INTDIR)\IntRank2T.obj" \
	"$(INTDIR)\SolidSys.obj" \
	"$(INTDIR)\ExProcess.obj" \
	"$(INTDIR)\MultiAux.obj" \
	"$(INTDIR)\MultiExch.obj" \
	"$(INTDIR)\MultiHam.obj" \
	"$(INTDIR)\MultiHSLib.obj" \
	"$(INTDIR)\MultiIPul.obj" \
	"$(INTDIR)\MultiLib.obj" \
	"$(INTDIR)\MultiLOp.obj" \
	"$(INTDIR)\MultiSOp.obj" \
	"$(INTDIR)\MultiSys.obj" \
	"$(INTDIR)\MultiWBR.obj" \
	"$(INTDIR)\SpinMap.obj" \
	"$(INTDIR)\ClassTest.obj" \
	"$(INTDIR)\ConstTest.obj" \
	"$(INTDIR)\GamTest.obj" \
	"$(INTDIR)\ModTest.obj" \
	"$(INTDIR)\SectTest.obj" \
	"$(INTDIR)\SingleTest.obj" \
	"$(INTDIR)\relaxRand.obj" \
	"$(INTDIR)\relaxAux.obj" \
	"$(INTDIR)\relaxBWRexch.obj" \
	"$(INTDIR)\relaxCSA.obj" \
	"$(INTDIR)\relaxDCSA.obj" \
	"$(INTDIR)\relaxDip.obj" \
	"$(INTDIR)\relaxExch.obj" \
	"$(INTDIR)\relaxJ.obj" \
	"$(INTDIR)\relaxNMR.obj" \
	"$(INTDIR)\relaxProp.obj" \
	"$(INTDIR)\relaxQCSA.obj" \
	"$(INTDIR)\relaxQuad.obj" \
	"$(INTDIR)\relaxanalyze.obj" \
	"$(INTDIR)\relaxRF.obj"

"..\..\i686-pc-msvc\gamma.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("gamma.dep")
!INCLUDE "gamma.dep"
!ELSE 
!MESSAGE Warning: cannot find "gamma.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "gamma - Win32 Release" || "$(CFG)" == "gamma - Win32 Debug"
SOURCE=..\..\src\Basics\Gconstants.cc

"$(INTDIR)\Gconstants.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Basics\Gutils.cc

"$(INTDIR)\Gutils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Basics\Isotope.cc

"$(INTDIR)\Isotope.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Basics\IsotopeData.cc

"$(INTDIR)\IsotopeData.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Basics\ParamSet.cc

"$(INTDIR)\ParamSet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Basics\SinglePar.cc

"$(INTDIR)\SinglePar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Basics\StringCut.cc

"$(INTDIR)\StringCut.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\_matrix.cc

"$(INTDIR)\_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\col_vector.cc

"$(INTDIR)\col_vector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\complex.cc

"$(INTDIR)\complex.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\d_matrix.cc

"$(INTDIR)\d_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\h_matrix.cc

"$(INTDIR)\h_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\i_matrix.cc

"$(INTDIR)\i_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\matrix.cc

"$(INTDIR)\matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\MxModBas.cc

"$(INTDIR)\MxModBas.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\n_matrix.cc

"$(INTDIR)\n_matrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Matrix\row_vector.cc

"$(INTDIR)\row_vector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\Basis.cc

"$(INTDIR)\Basis.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\GenOp.cc

"$(INTDIR)\GenOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\GenOpRep.cc

"$(INTDIR)\GenOpRep.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSacquire.cc

"$(INTDIR)\HSacquire.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSanalyze.cc

"$(INTDIR)\HSanalyze.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSauxil.cc

"$(INTDIR)\HSauxil.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSdecomp.cc

"$(INTDIR)\HSdecomp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSdetect.cc

"$(INTDIR)\HSdetect.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSham.cc

"$(INTDIR)\HSham.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\HSprop.cc

"$(INTDIR)\HSprop.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\PulseI.cc

"$(INTDIR)\PulseI.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\PulseS.cc

"$(INTDIR)\PulseS.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\PulseShp.cc

"$(INTDIR)\PulseShp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\SpinOp.cc

"$(INTDIR)\SpinOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\SpinOpCmp.cc

"$(INTDIR)\SpinOpCmp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\SpinOpRot.cc

"$(INTDIR)\SpinOpRot.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\SpinOpSng.cc

"$(INTDIR)\SpinOpSng.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\SpinSys.cc

"$(INTDIR)\SpinSys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\HSLib\SpinSystem.cc

"$(INTDIR)\SpinSystem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\coord.cc

"$(INTDIR)\coord.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\coord_vec.cc

"$(INTDIR)\coord_vec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\Exponential.cc

"$(INTDIR)\Exponential.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\ExProcessM.cc

"$(INTDIR)\ExProcessM.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\Lorentzian.cc

"$(INTDIR)\Lorentzian.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\nmr_tensor.cc

"$(INTDIR)\nmr_tensor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\SpaceT.cc

"$(INTDIR)\SpaceT.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\SphHarmic.cc

"$(INTDIR)\SphHarmic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\SpinT.cc

"$(INTDIR)\SpinT.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\Wigner.cc

"$(INTDIR)\Wigner.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level1\WindowFct.cc

"$(INTDIR)\WindowFct.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\DensOp.cc

"$(INTDIR)\DensOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\LSacquire.cc

"$(INTDIR)\LSacquire.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\LSanalyze.cc

"$(INTDIR)\LSanalyze.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\LSAux.cc

"$(INTDIR)\LSAux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\LSprop.cc

"$(INTDIR)\LSprop.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\SuperOp.cc

"$(INTDIR)\SuperOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\LSLib\sys_dynamic.cc

"$(INTDIR)\sys_dynamic.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\acquire1D.cc

"$(INTDIR)\acquire1D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\BaseDecomp.cc

"$(INTDIR)\BaseDecomp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\EAngles.cc

"$(INTDIR)\EAngles.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\MutExch.cc

"$(INTDIR)\MutExch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\Quaternion.cc

"$(INTDIR)\Quaternion.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\RelaxBas.cc

"$(INTDIR)\RelaxBas.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Level2\TrnsTable1D.cc

"$(INTDIR)\TrnsTable1D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWin1D.cc

"$(INTDIR)\XWin1D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWin2D.cc

"$(INTDIR)\XWin2D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinAcqPar.cc

"$(INTDIR)\XWinAcqPar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinAcqu2s.cc

"$(INTDIR)\XWinAcqu2s.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinAcqus.cc

"$(INTDIR)\XWinAcqus.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinFid.cc

"$(INTDIR)\XWinFid.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinMeta.cc

"$(INTDIR)\XWinMeta.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinOutd.cc

"$(INTDIR)\XWinOutd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinProc2s.cc

"$(INTDIR)\XWinProc2s.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinProcPar.cc

"$(INTDIR)\XWinProcPar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinProcs.cc

"$(INTDIR)\XWinProcs.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinPSet.cc

"$(INTDIR)\XWinPSet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinSer.cc

"$(INTDIR)\XWinSer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\XWinSpec.cc

"$(INTDIR)\XWinSpec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\MatLabFile.cc

"$(INTDIR)\MatLabFile.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML4DElem.cc

"$(INTDIR)\ML4DElem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML4Tag.cc

"$(INTDIR)\ML4Tag.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5AF.cc

"$(INTDIR)\ML5AF.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5AN.cc

"$(INTDIR)\ML5AN.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5DA.cc

"$(INTDIR)\ML5DA.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5DElem.cc

"$(INTDIR)\ML5DElem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5Hdr.cc

"$(INTDIR)\ML5Hdr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5Imags.cc

"$(INTDIR)\ML5Imags.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5Reals.cc

"$(INTDIR)\ML5Reals.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5SubE.cc

"$(INTDIR)\ML5SubE.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\ML5Tag.cc

"$(INTDIR)\ML5Tag.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\FrameMaker.cc

"$(INTDIR)\FrameMaker.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\FrameMakerC.cc

"$(INTDIR)\FrameMakerC.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\FrameMakerM.cc

"$(INTDIR)\FrameMakerM.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\FrameMakerP.cc

"$(INTDIR)\FrameMakerP.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\FrameMakerS.cc

"$(INTDIR)\FrameMakerS.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\FrameMakerSph.cc

"$(INTDIR)\FrameMakerSph.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\Ggnuplot.cc

"$(INTDIR)\Ggnuplot.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\Ggnuplot1D.cc

"$(INTDIR)\Ggnuplot1D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\GgnuplotC.cc

"$(INTDIR)\GgnuplotC.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\GgnuplotSph.cc

"$(INTDIR)\GgnuplotSph.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\BinIOBase.cc

"$(INTDIR)\BinIOBase.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\GamIO\Gascii.cc

"$(INTDIR)\Gascii.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\Bloch.cc

"$(INTDIR)\Bloch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochAcq.cc

"$(INTDIR)\BlochAcq.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochB.cc

"$(INTDIR)\BlochB.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochK.cc

"$(INTDIR)\BlochK.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochM.cc

"$(INTDIR)\BlochM.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochMx.cc

"$(INTDIR)\BlochMx.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochR.cc

"$(INTDIR)\BlochR.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochSys.cc

"$(INTDIR)\BlochSys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\BlochTraj.cc

"$(INTDIR)\BlochTraj.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\DetVec.cc

"$(INTDIR)\DetVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Bloch\MagVec.cc

"$(INTDIR)\MagVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxanalyze.cc

"$(INTDIR)\relaxanalyze.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxAux.cc

"$(INTDIR)\relaxAux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxBWRexch.cc

"$(INTDIR)\relaxBWRexch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxCSA.cc

"$(INTDIR)\relaxCSA.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxDCSA.cc

"$(INTDIR)\relaxDCSA.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxDip.cc

"$(INTDIR)\relaxDip.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxExch.cc

"$(INTDIR)\relaxExch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxJ.cc

"$(INTDIR)\relaxJ.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxNMR.cc

"$(INTDIR)\relaxNMR.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxProp.cc

"$(INTDIR)\relaxProp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxQCSA.cc

"$(INTDIR)\relaxQCSA.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxQuad.cc

"$(INTDIR)\relaxQuad.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxRand.cc

"$(INTDIR)\relaxRand.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\BWRRelax\relaxRF.cc

"$(INTDIR)\relaxRF.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Deprecated\acquire.cc

"$(INTDIR)\acquire.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Deprecated\block_1D.cc

"$(INTDIR)\block_1D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Deprecated\block_2D.cc

"$(INTDIR)\block_2D.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\ESRLib\CubicIon.cc

"$(INTDIR)\CubicIon.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\ESRLib\CubicIonData.cc

"$(INTDIR)\CubicIonData.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\ESRLib\CubicSys.cc

"$(INTDIR)\CubicSys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\ESRLib\MagIon.cc

"$(INTDIR)\MagIon.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Floquet\Floq2Op.cc

"$(INTDIR)\Floq2Op.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Floquet\FloqAcq.cc

"$(INTDIR)\FloqAcq.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Floquet\FloqOp.cc

"$(INTDIR)\FloqOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulAuxil.cc

"$(INTDIR)\PulAuxil.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulCHIRP.cc

"$(INTDIR)\PulCHIRP.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulComposite.cc

"$(INTDIR)\PulComposite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulCycle.cc

"$(INTDIR)\PulCycle.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulDANTE.cc

"$(INTDIR)\PulDANTE.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulGARP.cc

"$(INTDIR)\PulGARP.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulGauss.cc

"$(INTDIR)\PulGauss.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulMLEV.cc

"$(INTDIR)\PulMLEV.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\Pulse.cc

"$(INTDIR)\Pulse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulSinc.cc

"$(INTDIR)\PulSinc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulSupCycle.cc

"$(INTDIR)\PulSupCycle.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulTrain.cc

"$(INTDIR)\PulTrain.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulTrainSCyc.cc

"$(INTDIR)\PulTrainSCyc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulWALTZ.cc

"$(INTDIR)\PulWALTZ.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Pulses\PulWaveform.cc

"$(INTDIR)\PulWaveform.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Gradients\Gradients2.cc

"$(INTDIR)\Gradients2.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Gradients\GrdAcquire.cc

"$(INTDIR)\GrdAcquire.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Gradients\GrdDeprec.cc

"$(INTDIR)\GrdDeprec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Gradients\GrdEvolve.cc

"$(INTDIR)\GrdEvolve.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Gradients\GrdPulses.cc

"$(INTDIR)\GrdPulses.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Gradients\sys_gradz.cc

"$(INTDIR)\sys_gradz.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\CartMx2A.cc

"$(INTDIR)\CartMx2A.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\CompRot.cc

"$(INTDIR)\CompRot.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\FrameMap.cc

"$(INTDIR)\FrameMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\HDipolar.cc

"$(INTDIR)\HDipolar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\HElectronG.cc

"$(INTDIR)\HElectronG.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\HQuadrup.cc

"$(INTDIR)\HQuadrup.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\HShiftAnis.cc

"$(INTDIR)\HShiftAnis.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntCSA.cc

"$(INTDIR)\IntCSA.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntCSAVec.cc

"$(INTDIR)\IntCSAVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntDip.cc

"$(INTDIR)\IntDip.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntDipVec.cc

"$(INTDIR)\IntDipVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntG.cc

"$(INTDIR)\IntG.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntGVec.cc

"$(INTDIR)\IntGVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntHF.cc

"$(INTDIR)\IntHF.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntHFVec.cc

"$(INTDIR)\IntHFVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntQuad.cc

"$(INTDIR)\IntQuad.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntQuadVec.cc

"$(INTDIR)\IntQuadVec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntRank2.cc

"$(INTDIR)\IntRank2.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntRank2A.cc

"$(INTDIR)\IntRank2A.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntRank2ACmp.cc

"$(INTDIR)\IntRank2ACmp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\IntRank2T.cc

"$(INTDIR)\IntRank2T.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\IntRank2\SolidSys.cc

"$(INTDIR)\SolidSys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\ExProcess.cc

"$(INTDIR)\ExProcess.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiAux.cc

"$(INTDIR)\MultiAux.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiExch.cc

"$(INTDIR)\MultiExch.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiHam.cc

"$(INTDIR)\MultiHam.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiHSLib.cc

"$(INTDIR)\MultiHSLib.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiIPul.cc

"$(INTDIR)\MultiIPul.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiLib.cc

"$(INTDIR)\MultiLib.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiLOp.cc

"$(INTDIR)\MultiLOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiSOp.cc

"$(INTDIR)\MultiSOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiSys.cc

"$(INTDIR)\MultiSys.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\MultiWBR.cc

"$(INTDIR)\MultiWBR.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\MultiSys\SpinMap.cc

"$(INTDIR)\SpinMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Testing\ClassTest.cc

"$(INTDIR)\ClassTest.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Testing\ConstTest.cc

"$(INTDIR)\ConstTest.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Testing\GamTest.cc

"$(INTDIR)\GamTest.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Testing\ModTest.cc

"$(INTDIR)\ModTest.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Testing\SectTest.cc

"$(INTDIR)\SectTest.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\src\Testing\SingleTest.cc

"$(INTDIR)\SingleTest.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

