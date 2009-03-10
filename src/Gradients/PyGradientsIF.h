/* PyGradientsIF.h **********************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Gradients Module Interface             Interface	**
**									**
**      Copyright (c) 2002						**
**      Scott Smith					 		**
**      National High Magnetic Field Laboratory				**
**      1800 E. Paul Dirac Drive					**
**      Tallahassee Florida, 32306-4005					**
**									**
**      $Header: $
**									**
*************************************************************************/

/*************************************************************************
**									**
** Description                                                          **
**									**
** PyGAMMA is GAMMA wrapped up into Python. To produce PyGAMMA the	**
** GAMMA codes are compiled with the BOOST.Python library which exposes	**
** C++ to Python. Prior to compilation the flag PYGAMMA set non-zero,	**
** this signals the preprocessor to include any additional code that is	**
** exclusive to PyGAMMA (beyond GAMMA).					**
**									**
** The PyGAMMA interface contains all of the needed definitions as to	**
** what should be/will be exported into Python from the sources. This	**
** is that file.							**
**                                                                      **
** This file is used ONLY for administrative purposes. It is used only  **
** when the GAMMA Gradients module is built into a Python module w/o	**
** the rest of GAMMA exported. It is NOT used when PyGAMMA in its full  **
** splendor is made. In fact, this file should probably NOT be released **
** in a GAMMA distribution.                                             **
**									**
*************************************************************************/


#ifdef PYGAMMA					// If we are compiling PyGAMMA
						// we will include this stuff
						// BUT INCLUDE NOTHING UNLESS
						// PYGAMMA DEFINED (build PyGAMMA)

// ____________________________________________________________________________
// i                         PyGAMMA Header Includes
// ____________________________________________________________________________

/* This section should contain all of the headers that are required to build
   the Python version of this GAMMA module's library. We need both the headers
   for Boost.Python, those of the GAMMA module being treated, & any additional
   GAMMA headers that the module depends on.                                 */

// ----------------------------------------------------------------------------
//                             Boost.Python Headers
// ----------------------------------------------------------------------------

/* All Boost.Python headers can be included through <boost/python.hpp>. Rather
   that use it, I perfer to use specific headers so that I know exactly what a
   module depends upon. I think that we only need the definitons of a BP
   module for this file.                                                     */

#include <boost/python/module.hpp>			// Boost.Python modules

// ----------------------------------------------------------------------------
//                             GAMMA Module(s) Headers
// ----------------------------------------------------------------------------

/* Remember that here we not only need the current module that the Pythonized
   library is to be based on, but we also need any modules that the current
   module depends upon too.                                                  */

#include <Basics/GBasicsIF.h>			// All of Basics module
#include <Matrix/MatrixIF.h>			// All of Matrix module
#include <HSLib/HSLibIF.h>			// All of HSLib module
#include <Level1/Level1IF.h>			// All of Level1 module
#include <LSLib/LSLibIF.h>			// All of LSLib module
#include <Level2/Level2IF.h>			// All of Level2 module
#include <GamIO/GammaIOIF.h>			// For plotting in demo
#include <Gradients/GradIF.h>			// All of Gradients module
#include <string>				// The libstdc++ strings

#ifdef _MSC_VER					// If using MSVC++ then we
 #pragma warning (disable : 4190 4042)		//   Kill C-linkage & which warnings
 #pragma warning (disable : 4275 4251 4231)	//   Kill dll-interface and
#endif						//   extension warnings

/
// ____________________________________________________________________________
// ii                             PyGAMMA Exports
// ____________________________________________________________________________

/* This is the section that actually exports GAMMA functionality into a Python
   module (library). Of particular importance is the module name as this is
   the name that will be needed when anything from the modules is used from
   within Python.                                                            */

// ----------------------------------------------------------------------------
//                Export The Module For A DLL (Windows Only!)
// ----------------------------------------------------------------------------

/* There was a time when one had to label this as a function to be exported
   into a Windows DLL. So, when macro _WIN32 is defined the C++ preprocessor
   would add the declspec stuff prior to the BP module function. This would
   appease the demands of MSVC++ and some other Windows based compilers and
   adhere to what Microsoft specified for DLLs. Nowadays, compilers like GCC
   (Cygwin or MinGW) on Windows do not need this stuff although they can use
   it. Anyway, I guess the function BOOST_PYTHON_MODULE now takes care of this
   issue internally so that it is not needed here. Note that none of this is
   applicable to any Unix based system which uses shared object libraries.   */
/*
extern "C"
#  ifdef _WIN32
   __declspec(dllexport)
#  endif
*/

// ----------------------------------------------------------------------------
//                    The Python Module via Boost.Python
// ----------------------------------------------------------------------------

/* This is the function that specifies what will be exported into Python from
   GAMMA. Note that this function nearly spans the rest of this file! Also the
   keyword foo in BOOST_PYTHON_MODULE(foo) is normally associated with the
   name produced library, i.e. foo => foo.dll or foo.so. Of course that is set
   at compilation time. The name foo will be that know to Python, i.e. one
   may use "import foo" or "import from foo *".                              */

BOOST_PYTHON_MODULE(Gradients)
  {

// ____________________________________________________________________________
// ____________________________________________________________________________
// A                     GAMMA Basics Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  PyGconstants();				// GAMMA constants
  PyGutils();					// Utility functions
  PyIsotopeData();				// Isotope data
  PyIsotope();					// Spin isotopes
  PySinglePar();				// Single parameters
  PySPlist();					// Parameter lists (base)
  PyParameterSet();				// Parameter sets

// ____________________________________________________________________________
// ____________________________________________________________________________
// B                     GAMMA Matrix Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________
  
  PyComplex();					// GAMMA complex numbers
  PyMatrix();					// GAMMA matrices
  PyRowVector();				// Row vectors
  PyColVector();				// Column vectors

// ____________________________________________________________________________
// ____________________________________________________________________________
// C             GAMMA Hilbert Space Library Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________
  
  PySpinOpSng();				// Single spin operators
  PySpinSys();					// Base spin systems
  PySpinOp();					// Spin operators
  PySpinOpCmp();				// Composite spin operators
  PySpinOpRot();				// Rotation spin operators
  PySpinSystem();				// Isotropic spin systems
  PyBasis();					// Operator bases
  PyGenOp();					// Hilbert space operators
  PyHSHam();					// Common MR Hamiltonians
  PyHSProp();					// Hilbert space propagators
  PyHSAcquire();				// Hilbert space acquisitions
//PyPulseI();
//PyPulseS();
//PyPulseShp();
//PyHSDetect();
//PyHSDecomp();
//PyHSAuxil();
//PyHSAnalyze();
//PyGenOpRep();

// ____________________________________________________________________________
// ____________________________________________________________________________
// D                     GAMMA Level1 Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  PyCoord();					// 3D Coordinates
  PyCoordVec();					// Coordinate vectors
  PyExponential();				// Exponentials
  PyExchProcM();				// Mutual exchange processses
  PyLorentzian();				// Lorentzians
  PyNMRTensor();				// NMR spin tensors
  PySpaceT();					// Generic spatial tensors
  PySphHarmic();				// Spherical Harmonics
  PySpinT();					// Generic spin tensors
  PyWigner();					// Wigner rotation elements
  PyWindow();					// NMR window functions

// ____________________________________________________________________________
// ____________________________________________________________________________
// E                     GAMMA Liouville Space Library Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  PyLSAcquire();				// Liouville space acquisitions
  PyLSProp();					// Liouville space propagators
  PySuperOp();					// Liouville space superoperators
  PySysDynamic();				// Dynamic isotropic systems
//PyLSAnalyze();				// Relaxation analysis functions
//PyLSAuxil();					// Liouville auxiliary functions

// ____________________________________________________________________________
// ____________________________________________________________________________
// F                     GAMMA Level2 Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  PyTrnsTable();				// Transition tables (1D)
  PyAcquire1D();				// Acquisitions (1D)
  PyEAngles();					// Euler angles
  PyQuaternion();				// Quaternions
  PyMutExch();					// Mutual Exchange Superoperators
  PyBaseDecomp();				// Base Decompositions
//  PyRelaxBas();					// Primitive Relaxation

// ____________________________________________________________________________
// ____________________________________________________________________________
// L                      GAMMA Gradients Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  }

// ----------------------------------------------------------------------------
//                    The Windows DLL Entry Point Function
// ----------------------------------------------------------------------------

/* For a Windows based DLL there must be an "entry point" function used when
   the DLL is accessed. The function can be pretty simple, expecially since
   we will only use it within Python. For the time being it seems that we don't
   even need it. Either it is done by the compiler, not needed from Python, or
   taken care of in BOOST_PYTHON_MODULE. I don't even want to investigate
   this Microsoft specific issue any further so long as things work.         */

/*
#if defined(_WIN32) 					// Win32 DLL boilerplate
#  include <windows.h>
   extern "C" BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID)
     { return 1; }
#endif							// _WIN32
*/

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)