/* PyGamIOIF.h **************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Input/Output Interface             Interface		**
**									**
**      Copyright (c) 2002						**
**      Scott Smith							**
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
**									**
** This file is used ONLY for administrative purposes. It is used only  **
** when the GAMMA I/O module is built into a Python module without	**
** the rest of GAMMA exported. It is NOT used when PyGAMMA in its full  **
** splendor is made. In fact, this file should probably NOT be released **
**									**
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

// ____________________________________________________________________________
// i                       PyGAMMA Header Includes
// ____________________________________________________________________________

/* This will contain all of the headers that are required to build PyGAMMA.
   It's contents should be similar to the file GAMMAVER/src/gamma.h when the
   bulk of GAMMA is exported. For now some files are not included so we have
   specific includes rather than those for entire sections.                  */

#include <boost/python.hpp>

/* Note that because the boost.python headers include libstdc++ class complex
   (the header <complex>), we have problems because this supercedes the class
   complex defined in GAMMA (header <Matrix/complex.h> in <matrixIF.h>). This
   will produce many many errors with some compilers that cannot figure out
   the difference. The only way around this must be to use a namespace. All of
   the boost code properly uses std::complex for all complex declarations!
   GAMMA should do the same.....                                            */

#include <Basics/GBasicsIF.h>			// All of Basics module
#include <Matrix/MatrixIF.h>			// All of Matrix module
#include <HSLib/HSLibIF.h>			// All of HSLib module
#include <Level1/Level1IF.h>			// All of Level1 module
#include <LSLib/LSLibIF.h>			// All of LSLib module
#include <Level2/Level2IF.h>			// All of Level2 module
#include <GamIO/GammaIOIF.h>			// All of GamIO module
#include <string>				// The libstdc++ strings

#ifdef _MSC_VER					// If using MSVC++ then we
 #pragma warning (disable : 4190 4042)		//   Kill C-linkage & which warnings
 #pragma warning (disable : 4275 4251 4231)	//   Kill dll-interface and
#endif						//   extension warnings

using namespace boost::python;

// ____________________________________________________________________________
// iii                    PyGAMMA Special Functionality
// ____________________________________________________________________________

/* These functions are exclusively for PyGAMMA (as is this file).            */

void pyerror(std::string msg)
  {
  PyErr_SetString(PyExc_RuntimeError, msg.c_str());
  throw boost::python::argument_error();
  }

extern "C"
#ifdef _WIN32
__declspec(dllexport)
#endif


// ____________________________________________________________________________
// ____________________________________________________________________________
// ____________________________________________________________________________
// iv                            PyGAMMA Exports 
// ____________________________________________________________________________
// ____________________________________________________________________________
// ____________________________________________________________________________

BOOST_PYTHON_MODULE(GamIO)
  {

// ____________________________________________________________________________
// ____________________________________________________________________________
// A                     GAMMA Basics Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  PyGconstants();				// GAMMA constants
  PyGutils();					// Utility functions
  PySinglePar();				// Single parameters
  PySPlist();					// Parameter lists (base)
  PyParameterSet();				// Parameter sets
  PyIsotopeData();				// Isotope data
  PyIsotope();					// Spin isotopes

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
// G                     GAMMA Input/Output Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

  PyGgnuplot();
  PyGgnuplot1D();
  }


#if defined(_WIN32)					// Win32 DLL boilerplate

#include <windows.h>
  extern "C" BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID)
    { return 1; }

#endif							// _WIN32

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)
