/* PyGAMMAIF.h **************************************************-*-c++-*-
**                                                                      **
**                              G A M M A                               **
**                                                                      **
**      PyGAMMA Interface                          Interface 		**
**                                                                      **
**      Copyright (c) 2002                                              **
**      Scott Smith, Khaled Khairy, Keven Chen, Mikolai Fajer		**
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
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

// ____________________________________________________________________________
// i                      PyGAMMA Python Module Name
// ____________________________________________________________________________

/* It is essential that a name be assigned to the Python module we are to
   build. For example, if we are building the PyGAMMA Python module we use the
   module name "pygamma" and this is propagated and used in all GAMMA functions
   exported into Python using Boost.Python. The reason for this is that the
   GAMMA modules use the module name "PyModule" so that it may be set to
   anything (as should be done here), thus allowing the user to build smaller
   smaller Python modules if desired. Whatever name is set here should
   exactly match the name used (twice) in the module_builder below as well
   as match the output Python module name.                                   */

#define PyModule pygamma

// ____________________________________________________________________________
// ii                      PyGAMMA Header Includes
// ____________________________________________________________________________

/* This will contain all of the headers that are required to build PyGAMMA.
   It's contents should be similar to the file GAMMAVER/src/gamma.h when the
   bulk of GAMMA is exported. In addition will be headers for Boost.Python.  */

#include <boost/python/class_builder.hpp>		// Boost class stuff
#include <boost/python/reference.hpp>			// Boost referencing

#include <Basics/GBasicsIF.h>				// All of Basics module
#include <Matrix/MatrixIF.h>				// All of Matrix module
#include <HSLib/HSLibIF.h>				// All of HSLib  module
#include <Level1/Level1IF.h>				// All of Level1 module
#include <LSLib/LSLibIF.h>				// All of LSLib  module
#include <Level2/Level2IF.h>				// All of Level2 module
#include <Bloch/BlochIF.h>				// All of IO     module
#include <GamIO/GammaIOIF.h>				// All of Bloch  module
#include <string>					// The libstdc++ strings

#ifdef _MSC_VER					// If using MSVC++ then we
 #pragma warning (disable : 4190 4042)		//   Kill C-linkage & which warnings
 #pragma warning (disable : 4275 4251 4231)	//   Kill dll-interface and
#endif						//   extension warnings

// ____________________________________________________________________________
// iii                     PyGAMMA Special Functionality
// ____________________________________________________________________________

/* These functions are exclusively for PyGAMMA (as is this file).            */

void pyerror(std::string msg)
  {
  PyErr_SetString(PyExc_RuntimeError, msg.c_str());
  throw boost::python::argument_error();
  }

// ----------------------------------------------------------------------------
//                    Set Up DLL Function Exporting
// ----------------------------------------------------------------------------

extern "C"					// Stop C++ name mangling
#ifdef _WIN32					// If windows, we must state
__declspec(dllexport)				// that what follows is
#endif						// exported to our DLL

// ____________________________________________________________________________
// ____________________________________________________________________________
// ____________________________________________________________________________
// iv                            PyGAMMA Exports 
// ____________________________________________________________________________
// ____________________________________________________________________________
// ____________________________________________________________________________


/* This is the function that specifies what will be exported into Python from
   PyGAMMA. Note that this function nearly spans the rest of this file!
   Python requires an exported function called init<module-name> in every
   extension module.  This is where we build the module contents.
   Please not that the keyword "pygamma" here is associated with the name
   pygamma.dll when the WinTel build occurs                                  */

void initpygamma()
  {
  try
    {
    boost::python::module_builder pygamma("pygamma");	// Extension module

#   include <Basics/PyBasics.h>				// Basics module exports
#   include <Matrix/PyMatrix.h>				// Matrix module exports
#   include <HSLib/PyHSLib.h>				// HSLib  module exports
#   include <Level1/PyLevel1.h>				// Level1 module exports
#   include <LSLib/PyLSLib.h>				// LSLib  module exports
#   include <Level2/PyLevel2.h>				// Level2 module exports
#   include <GamIO/PyGamIO.h>				// GamIO  module exports
#   include <Bloch/PyBloch.h>				// Bloch  module exports

    }
  catch(...)
    {
    boost::python::handle_exception();			// Deal with exception for Python
    }
  }

// ----------------------------------------------------------------------------
//                         DLL Entry Point Function
// ----------------------------------------------------------------------------

#if defined(_WIN32) 					// Win32 DLL boilerplate

#include <windows.h>
  extern "C" BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID)
    { return 1; }

#endif							// _WIN32

#endif					// End PyGAMMA include. Note that
					// we will include file contents only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

