/* PyLevel2.h ***************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Level 2 Module		             Interface		**
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
*************************************************************************/

// sosi - Some functions are commented out because in MSVC++ they produce
//        "duplicate comdat errors during the build. This implies that the
//        munged names of the functions MSVC++ uses are the same for two or
//        more functions. Normally this is due to some imposed limits on the
//        lengths of the munged names, but here I have no idea what they are
//        caused from.

#ifdef PYGAMMA					// If we are compiling PyGAMMA
						// we will include this stuff
						// BUT INCLUDE NOTHING UNLESS
						// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyLevel2_h_			// Is this file already included?
#define _PyLevel2_h_ 1			// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// F                     GAMMA Level 2 Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                                 Quaternions
// ----------------------------------------------------------------------------

/
//                           Python Specialty Functions


#endif					// End of PyLevel2.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

