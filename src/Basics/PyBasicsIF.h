/* PyBasicsIF.h *************************************************-*-c++-*-
**                                                                      **
**                              G A M M A                               **
**                                                                      **
**      PyGAMMA Basics Interface                     Interface 		**
**                                                                      **
**      Copyright (c) 2002                                              **
**      Scott Smith							**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
** Description                                                          **
**                                                                      **
** PyGAMMA is GAMMA wrapped up into Python. To produce PyGAMMA the 	**
** GAMMA codes are compiled with the BOOST.Python library which exposes	**
** C++ to Python. Prior to compilation the flag PYGAMMA set non-zero,	**
** this signals the preprocessor to include any additional code that is	**
** exclusive to PyGAMMA (beyond GAMMA).					**
**                                                                      **
** The PyGAMMA interface contains all of the needed definitions as to	**
** what should be/will be exported into Python from the sources. This	**
** is that file.							**
**                                                                      **
** This file is used ONLY for administrative purposes. It is used only  **
** when the GAMMA Basics module is built into a Python module without   **
** the rest of GAMMA exported. It is NOT used when PyGAMMA in its full  **
** splendor is made. In fact, this file should probably NOT be released **
** in a GAMMA distribution.                                             **
**                                                                      **
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
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

#include <Basics/GBasicsIF.h>				// All of Basics module

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

BOOST_PYTHON_MODULE(Basics)
  {
  PyGconstants();				// GAMMA constants
  PyGutils();					// Utility functions
  PySinglePar();				// Single parameters
  PySPlist();					// Parameter lists (base)
  PyParameterSet();				// Parameter sets
  PyIsotopeData();				// Isotope data
  PyIsotope();					// Spin isotopes
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

