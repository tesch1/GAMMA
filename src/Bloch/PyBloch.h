/* PyBloch.h ****************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Bloch Module	                         Interface	**
**									**
**      Copyright (c) 2002						**
**      Scott Smith, Khaled Khairy, Keven Chen, Mikolai Fajer		**
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
** The PyGAMMA interface will include this file. This file contains all **
** of the needed definitions as to what should be/will be exported	**
** into Python from the Bloch module sources. The only thing it will	**
** need in addition to PYGAMMA being set non-zero is the name PyModule  **
** set. The value of PyModule will be set in PyGAMMAIF.h to be pygamma. **
**									**
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyBloch_h_			// Is this file already included?
#define _PyBloch_h_ 1			// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// H                     GAMMA Bloch Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                                Bloch Systems
// ----------------------------------------------------------------------------

//                                  The Class

    boost::python::class_builder<BlochSys> (PyModule, "BlochSys");
 
//                                 Constructors

    .def(boost::python::constructor<>    ());
    .def(boost::python::constructor<int> ());

//                                Member Functions

    .def(&BlochSys::NIso,         "NIso");
    .def(&BlochSys::IsoMaxLength, "IsoMaxLength");
    .def(&BlochSys::NSpins,       "NSpins");

//                          Python Specialty Functions


// ----------------------------------------------------------------------------
//                           Bloch RF-Field Matrices
// ----------------------------------------------------------------------------

//                             Global Functions


    def((BlochMx (*)(double, double, double))                         &BlochB, "BlochB");
    def((BlochMx (*)(double, double, double, double))                 &BlochB, "BlochB");
    def((BlochMx (*)(double, double, double, double, double, double)) &BlochB, "BlochB");
//    def((BlochMx (*)(const BlochSys& sys))                  &BlochR, "BlochR");

//matrix R_matrix(double T1, double T2);
//matrix R_matrix(int argc, char* argv[], double& T1, double& T2, int& qn);
//matrix BlochR(int argc, char* argv[], double& T1, double& T2, int& qn, bool rate=false);

//                          Python Specialty Functions

    def((BlochMx (*)(double, double))                         &BlochBBB1, "BlochB");
    def((BlochMx (*)(double, double, double, double, double)) &BlochBBB2, "BlochB");



#endif					// End of PyBloch.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

