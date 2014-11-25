# Swig ".i" files.
set (pygamma_ALLIFILES "")
include_directories (${PYTHON_INCLUDE_PATH})

###############################################################################
#                                                                             #
#                         GAMMA BASICS MODULE VARIABLES                       #
#                                                                             #
###############################################################################
# Basics
set (gamma_xx_SOURCES
  Basics/Gconstants.cc Basics/Gutils.cc Basics/Isotope.cc Basics/IsotopeData.cc
  Basics/ParamSet.cc Basics/SinglePar.cc Basics/StringCut.cc
  )
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Basics/basics.i
  Basics/Gconstants.i
  Basics/Gutils.i
  Basics/IsotopeData.i
  Basics/Isotope.i
  Basics/ParamSet.i
  Basics/SinglePar.i
  Basics/StringCut.i
  #  basics ParamSet SinglePar Isotope Gconstants StringCut IsotopeData Gutils
  )
#BASICSTBAS  = TestBasics TestGconst TestGconstA TestSingPar TestSingParA TestSingParB
#              TestIsoData TestStringCut
install (FILES GBasicsIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                          GAMMA MATRIX MODULE VARIABLES                      #
#                                                                             #
###############################################################################
# Matrix
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Matrix/col_vector.cc Matrix/complex.cc Matrix/d_matrix.cc Matrix/h_matrix.cc
  Matrix/i_matrix.cc Matrix/_matrix.cc Matrix/matrix.cc Matrix/MxModBas.cc
  Matrix/n_matrix.cc Matrix/row_vector.cc
  )
install (FILES MatrixIF.h DESTINATION include)
#MATRIXTBAS  = TestMatrix
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Matrix/matrix_inc.i Matrix/matrix.i Matrix/row_vector.i Matrix/col_vector.i
  Matrix/complex.i
  )

###############################################################################
#                                                                             #
#                           GAMMA BLOCH MODULE VARIABLES                      #
#                                                                             #
###############################################################################
# Bloch
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Bloch/MagVec.cc Bloch/DetVec.cc Bloch/BlochSys.cc Bloch/BlochAcq.cc
  Bloch/BlochB.cc Bloch/BlochR.cc Bloch/BlochK.cc Bloch/BlochTraj.cc 
  Bloch/BlochM.cc Bloch/BlochMx.cc Bloch/Bloch.cc
  )
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Bloch/bloch_inc.i Bloch/Bloch.i Bloch/BlochSys.i Bloch/MagVec.i Bloch/BlochAcq.i
  )
install (FILES BlochIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                     GAMMA BWR RELAXATION MODULE VARIABLES                   #
#                                                                             #
###############################################################################
# BWRRelax
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  BWRRelax/relaxanalyze.cc
  BWRRelax/relaxBWRexch.cc
  BWRRelax/relaxCSA.cc
  BWRRelax/relaxDCSA.cc
  BWRRelax/relaxDip.cc
  BWRRelax/relaxDQuad.cc
  BWRRelax/relaxExch.cc
  BWRRelax/relaxJ.cc
  BWRRelax/relaxNMR.cc
  BWRRelax/relaxProp.cc
  BWRRelax/relaxQCSA.cc
  BWRRelax/relaxQuad.cc
  BWRRelax/relaxRand.cc
  BWRRelax/relaxRF.cc
  #relaxCSA relaxDCSA relaxDip relaxExch relaxJ relaxQCSA relaxQuad relaxRand relaxNMR relaxProp relaxRF relaxBWRexch relaxanalyze
  )
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  BWRRelax/bwrrelax.i
  BWRRelax/relaxanalyze.i
  BWRRelax/relaxBWRexch.i
  BWRRelax/relaxCSA.i
  BWRRelax/relaxDCSA.i
  BWRRelax/relaxDip.i
  BWRRelax/relaxExch.i
  BWRRelax/relaxJ.i
  BWRRelax/relaxNMR.i
  BWRRelax/relaxProp.i
  BWRRelax/relaxQCSA.i
  BWRRelax/relaxQuad.i
  BWRRelax/relaxRand.i
  BWRRelax/relaxRF.i
  #  bwrrelax relaxCSA relaxDCSA relaxDip relaxExch relaxJ relaxQCSA relaxQuad relaxRand relaxNMR relaxProp relaxRF
  )
install (FILES relaxBWRIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                         GAMMA DEPRECATED MODULE VARIABLES                   #
#                                                                             #
###############################################################################
# Deprecated
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Deprecated/block_1D.cc Deprecated/block_2D.cc Deprecated/acquire.cc
  )
install (FILES DeprecIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                            GAMMA ESR MODULE VARIABLES                       #
#                                                                             #
###############################################################################
# ESRLib
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  ESRLib/CubicIonData.cc ESRLib/CubicIon.cc
  )
# CubicSys ESRHam AngleSet Fibre
install (FILES ESRIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                         GAMMA FLOQUET MODULE VARIABLES                      #
#                                                                             #
###############################################################################
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Floquet/Floq2Op.cc Floquet/FloqAcq.cc Floquet/FloqOp.cc
  )
install (FILES FloquetIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                        GAMMA INPUT/OUTPUT MODULE VARIABLES                  #
#                                                                             #
###############################################################################
# GamIo
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  GamIO/BinIOBase.cc
  GamIO/FrameMaker.cc
  GamIO/FrameMakerC.cc
  GamIO/FrameMakerM.cc
  GamIO/FrameMakerP.cc
  GamIO/FrameMakerS.cc
  GamIO/FrameMakerSph.cc
  GamIO/Gascii.cc
  GamIO/Ggnuplot1D.cc
  GamIO/Ggnuplot.cc
  GamIO/GgnuplotC.cc
  GamIO/GgnuplotSph.cc
  GamIO/MatLabFile.cc
  GamIO/ML4DElem.cc
  GamIO/ML4Tag.cc
  GamIO/ML5AF.cc
  GamIO/ML5AN.cc
  GamIO/ML5DA.cc
  GamIO/ML5DElem.cc
  GamIO/ML5Hdr.cc
  GamIO/ML5Imags.cc
  GamIO/ML5Reals.cc
  GamIO/ML5SubE.cc
  GamIO/ML5Tag.cc
  GamIO/XWin1D.cc
  GamIO/XWin2D.cc
  GamIO/XWinAcqPar.cc
  GamIO/XWinAcqu2s.cc
  GamIO/XWinAcqus.cc
  GamIO/XWinFid.cc
  GamIO/XWinMeta.cc
  GamIO/XWinOutd.cc
  GamIO/XWinProc2s.cc
  GamIO/XWinProcPar.cc
  GamIO/XWinProcs.cc
  GamIO/XWinPSet.cc
  GamIO/XWinSer.cc
  GamIO/XWinSpec.cc
  #  BinIOBase Gascii GgnuplotC Ggnuplot1D GgnuplotSph Ggnuplot ML4DElem ML4Tag ML5Hdr ML5Tag ML5SubE ML5AF ML5DA ML5AN ML5Reals ML5Imags ML5DElem MatLabFile FrameMaker FrameMakerC FrameMakerM FrameMakerP FrameMakerS FrameMakerSph XWinPSet XWinAcqPar XWinAcqus XWinFid XWinProcPar XWinProcs XWinSpec XWinMeta XWinOutd XWin1D XWinAcqu2s XWinSer XWinProc2s XWin2D
  )
#              XWinProc2s XWin2D 
#              FTNMR Felix
install (FILES GammaIOIF.h DESTINATION include)

###############################################################################
#                                                                             #
#                      GAMMA FIELD GRADIENTS MODULE VARIABLES                 #
#                                                                             #
###############################################################################
# Gradients
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Gradients/Gradients2.cc
  Gradients/GrdAcquire.cc
  Gradients/GrdDeprec.cc
  Gradients/GrdEvolve.cc
  Gradients/GrdPulses.cc
  Gradients/sys_gradz.cc
  #  sys_gradz Gradients2 GrdPulses GrdEvolve GrdAcquire GrdDeprec
  )
install (FILES GradIF.h DESTINATION include)
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Gradients/Gradients2.i
  Gradients/gradients.i
  Gradients/GrdAcquire.i
  Gradients/GrdEvolve.i
  Gradients/GrdPulses.i
  Gradients/sys_gradz.i
  #  gradients sys_gradz Gradients2 GrdPulses GrdEvolve GrdAcquire
  )

###############################################################################
#                                                                             #
#                      GAMMA HILBERT SPACE MODULE VARIABLES                   #
#                                                                             #
###############################################################################
# HSLib
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  HSLib/Basis.cc
  HSLib/GenOp.cc
  HSLib/GenOpRep.cc
  HSLib/HSacquire.cc
  HSLib/HSanalyze.cc
  HSLib/HSauxil.cc
  HSLib/HSdecomp.cc
  HSLib/HSdetect.cc
  HSLib/HSham.cc
  HSLib/HSprop.cc
  HSLib/PulseI.cc
  HSLib/PulseS.cc
  HSLib/PulseShp.cc
  HSLib/SpinOp.cc
  HSLib/SpinOpCmp.cc
  HSLib/SpinOpRot.cc
  HSLib/SpinOpSng.cc
  HSLib/SpinSys.cc
  HSLib/SpinSystem.cc
  #  SpinOpSng SpinSys SpinOp SpinOpCmp SpinOpRot Basis GenOpRep GenOp SpinSystem HSacquire HSdetect HSdecomp HSprop HSham HSanalyze HSauxil PulseI PulseS PulseShp
  )
install (FILES HSLibIF.h DESTINATION include)
#HSPACETBAS  = TestHSLi1b
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  HSLib/Basis.i
  HSLib/GenOp.i
  HSLib/GenOpRep.i
  HSLib/HSacquire.i
  HSLib/HSanalyze.i
  HSLib/HSauxil.i
  HSLib/HSdecomp.i
  HSLib/HSdetect.i
  HSLib/HSham.i
  HSLib/hslib.i
  HSLib/HSprop.i
  HSLib/PulseI.i
  HSLib/PulseShp.i
  HSLib/PulseS.i
  HSLib/SpinOpCmp.i
  HSLib/SpinOp.i
  HSLib/SpinOpRot.i
  HSLib/SpinOpSng.i
  HSLib/SpinSys.i
  HSLib/SpinSystem.i
  #  hslib SpinSystem SpinSys GenOp HSham SpinOpCmp HSauxil PulseI PulseS Basis HSprop SpinOp HSanalyze HSdecomp PulseShp GenOpRep HSacquire HSdetect SpinOpRot SpinOpSng
  )

###############################################################################
#                                                                             #
#                     GAMMA RANK 2 INTERACTIONS MODULE VARIABLES              #
#                                                                             #
###############################################################################
# IntRank2
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  IntRank2/CartMx2A.cc
  #IntRank2/CDipT.cc
  IntRank2/CompRot.cc
  #IntRank2/CoordFrame.cc
  IntRank2/FrameMap.cc
  IntRank2/HDipolar.cc
  IntRank2/HElectronG.cc
  IntRank2/HQuadrup.cc
  IntRank2/HShiftAnis.cc
  IntRank2/IntCSA.cc
  IntRank2/IntCSAVec.cc
  IntRank2/IntDip.cc
  IntRank2/IntDipVec.cc
  IntRank2/IntG.cc
  IntRank2/IntGVec.cc
  IntRank2/IntHF.cc
  IntRank2/IntHFVec.cc
  IntRank2/IntQuad.cc
  IntRank2/IntQuadVec.cc
  IntRank2/IntRank2A.cc
  IntRank2/IntRank2ACmp.cc
  IntRank2/IntRank2.cc
  IntRank2/IntRank2T.cc
  #IntRank2/NSMinimize.cc
  #IntRank2/RefFrames.cc
  IntRank2/SolidSys.cc
  #IntRank2/STMinimize.cc
  #  IntRank2ACmp IntRank2A IntRank2T IntRank2 IntCSA IntDip IntQuad IntG IntHF IntDipVec IntCSAVec IntQuadVec IntGVec IntHFVec CompRot SolidSys CartMx2A FrameMap HDipolar HQuadrup HShiftAnis HElectronG
  )
install (FILES IntRank2IF.h DESTINATION include)

###############################################################################
#                                                                             #
#                          GAMMA LEVEL 1 MODULE VARIABLES                     #
#                                                                             #
###############################################################################
# Level1
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Level1/coord.cc
  Level1/coord_vec.cc
  Level1/Exponential.cc
  Level1/ExProcessM.cc
  Level1/Lorentzian.cc
  Level1/nmr_tensor.cc
  Level1/SpaceT.cc
  Level1/SphHarmic.cc
  Level1/SpinT.cc
  Level1/Wigner.cc
  Level1/WindowFct.cc
  #  coord coord_vec SphHarmic Wigner SpinT SpaceT nmr_tensor Exponential Lorentzian WindowFct ExProcessM
  )
install (FILES Level1IF.h DESTINATION include)
#LEVEL1TBAS  = TestLevel1
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Level1/coord.i
  Level1/coord_vec.i
  Level1/Exponential.i
  Level1/ExProcessM.i
  Level1/level1.i
  Level1/Lorentzian.i
  Level1/nmr_tensor.i
  Level1/SpaceT.i
  Level1/SphHarmic.i
  Level1/SpinT.i
  Level1/Wigner.i
  Level1/WindowFct.i
  #  level1 nmr_tensor SpinT SpaceT coord coord_vec SphHarmic Exponential ExProcessM Lorentzian Wigner WindowFct
  )

###############################################################################
#                                                                             #
#                          GAMMA LEVEL 2 MODULE VARIABLES                     #
#                                                                             #
###############################################################################
# Level2
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Level2/acquire1D.cc Level2/BaseDecomp.cc Level2/EAngles.cc Level2/MutExch.cc
  Level2/Quaternion.cc Level2/RelaxBas.cc Level2/TrnsTable1D.cc
  )
install (FILES Level2IF.h DESTINATION include)
#LEVEL2TBAS  = TestLevel2 TestTrnsTable1D Testacquire1D 
#              TestQuaternion TestQuaternionA TestQuaternionB TestQuaternionC
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Level2/acquire1D.i
  Level2/BaseDecomp.i
  Level2/EAngles.i
  Level2/level2.i
  Level2/MutExch.i
  Level2/Quaternion.i
  Level2/RelaxBas.i
  Level2/TrnsTable1D.i
  #  level2.i TrnsTable1D acquire1D Quaternion EAngles MutExch RelaxBas BaseDecomp 
  )

###############################################################################
#                                                                             #
#                     GAMMA LIOUVILLE SPACE MODULE VARIABLES                  #
#                                                                             #
###############################################################################
# LSLib
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  LSLib/DensOp.cc
  LSLib/LSacquire.cc
  LSLib/LSanalyze.cc
  LSLib/LSAux.cc
  LSLib/LSprop.cc
  LSLib/SuperOp.cc
  LSLib/sys_dynamic.cc
  #  SuperOp LSacquire LSprop sys_dynamic DensOp LSanalyze LSAux
  )
install (FILES LSLibIF.h DESTINATION include)
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  LSLib/DensOp.i
  LSLib/LSacquire.i
  LSLib/LSanalyze.i
  LSLib/LSAux.i
  LSLib/lslib.i
  LSLib/LSprop.i
  LSLib/SuperOp.i
  LSLib/sys_dynamic.i
  #  lslib SuperOp LSacquire LSprop DensOp sys_dynamic LSanalyze LSAux
  )

###############################################################################
#                                                                             #
#                      GAMMA MULTIPLE SYSTEM MODULE VARIABLES                 #
#                                                                             #
###############################################################################
# MultiSys
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  MultiSys/ExProcess.cc
  #MultiSys/MultiAux.cc
  #MultiSys/MultiExch0.cc
  MultiSys/MultiExch.cc
  MultiSys/MultiHam.cc
  MultiSys/MultiHSLib.cc
  MultiSys/MultiIPul.cc
  MultiSys/MultiLib.cc
  MultiSys/MultiLOp.cc
  MultiSys/MultiSOp.cc
  MultiSys/MultiSys.cc
  MultiSys/MultiWBR.cc
  MultiSys/SpinMap.cc
  #  SpinMap ExProcess MultiSys MultiLib MultiSOp MultiHam MultiIPul MultiHSLib MultiLOp MultiWBR MultiExch
  )
install (FILES MultiSysIF.h DESTINATION include)
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  MultiSys/ExProcess.i
  MultiSys/MultiAux.i
  MultiSys/MultiExch.i
  MultiSys/MultiHam.i
  MultiSys/MultiHSLib.i
  MultiSys/MultiIPul.i
  MultiSys/MultiLib.i
  MultiSys/MultiLOp.i
  MultiSys/MultiSOp.i
  MultiSys/MultiSys.i
  MultiSys/multisys_inc.i
  MultiSys/MultiWBR.i
  MultiSys/SpinMap.i
  #  multisys_inc ExProcess MultiSys MultiLib MultiSOp  MultiIPul MultiHSLib MultiLOp MultiExch MultiHam  MultiWBR SpinMap
  )

###############################################################################
#                                                                             #
#                           GAMMA PULSE MODULE VARIABLES                      #
#                                                                             #
###############################################################################
# Pulses
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Pulses/PulAuxil.cc
  Pulses/PulCHIRP.cc
  Pulses/PulComposite.cc
  Pulses/PulCycle.cc
  Pulses/PulDANTE.cc
  Pulses/PulGARP.cc
  Pulses/PulGauss.cc
  Pulses/PulMLEV.cc
  Pulses/Pulse.cc
  Pulses/PulSinc.cc
  Pulses/PulSupCycle.cc
  Pulses/PulTrain.cc
  Pulses/PulTrainSCyc.cc
  Pulses/PulWALTZ.cc
  Pulses/PulWaveform.cc
  #  PulGauss PulSinc PulAuxil Pulse PulComposite PulCycle PulDANTE PulGARP PulMLEV PulWALTZ PulCHIRP PulWaveform PulSupCycle PulTrain PulTrainSCyc
  )
install (FILES PulsesIF.h DESTINATION include)
set (pygamma_ALLIFILES ${pygamma_ALLIFILES}
  Pulses/PulAuxil.i
  Pulses/PulCHIRP.i
  Pulses/PulComposite.i
  Pulses/PulCycle.i
  Pulses/PulDANTE.i
  Pulses/PulGARP.i
  Pulses/PulGauss.i
  Pulses/PulMLEV.i
  Pulses/Pulse.i
  Pulses/pulses.i
  Pulses/PulSinc.i
  Pulses/PulSupCycle.i
  Pulses/PulTrain.i
  Pulses/PulTrainSCyc.i
  Pulses/PulWALTZ.i
  Pulses/PulWaveform.i
  #  pulses PulWaveform PulComposite PulGauss PulSinc PulCycle PulMLEV Pulse PulTrain PulSupCycle PulCHIRP PulTrainSCyc PulGARP PulWALTZ PulDANTE PulAuxil
  )

###############################################################################
#                                                                             #
#                         GAMMA TESTING MODULE VARIABLES                      #
#                                                                             #
###############################################################################
# Testing
set (gamma_xx_SOURCES ${gamma_xx_SOURCES}
  Testing/ClassTest.cc
  Testing/ConstTest.cc
  Testing/GamTest.cc
  Testing/ModTest.cc
  Testing/SectTest.cc
  Testing/SingleTest.cc
  )
install (FILES TestingIF.h DESTINATION include)

#include_directories (Basics Bloch BWRRelax Deprecated ESRLib Floquet
#  GamIO Gradients HSLib IntRank2 Level1 Level2 LSLib Matrix MultiSys
#  Pulses Solids)
include_directories (${CMAKE_SOURCE_DIR}/src)

#add_library (_pygamma SHARED ${gamma_SOURCES})
add_library (gamma ${gamma_xx_SOURCES})

#
# SWIG setup
#

set_source_files_properties (pygamma.i PROPERTIES OBJECT_DEPENDS ${pygamma_ALLIFILES})
set_source_files_properties (pygamma.i PROPERTIES CPLUSPLUS ON)
swig_add_module (pygamma python pygamma.i)
#swig_link_libraries (pygamma ${PYTHON_LIBRARIES})

###############################################################################
#                                                                             #
#                              GAMMA TEST PROGS                               #
#                                                                             #
###############################################################################
set (TESTPROGS runtests homo_stat sl_exchange7_L par_xixA xix_dec)
foreach (testp ${TESTPROGS})
  add_executable (${testp} Tests/${testp}.cc Tests/testsuite.cc)
  target_link_libraries (${testp} gamma)
endforeach (testp)

###############################################################################
#                                                                             #
#                                 GAMMA TESTS                                 #
#                                                                             #
###############################################################################
add_subdirectory (Tests)
add_subdirectory (pyTests)

