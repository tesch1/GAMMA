/* ESRIF.h ******************************************************-*-c++-*-
**                                                                      **
**                               G A M M A                              **
**                                                                      **
**	GAMMA ESR Library				Interface 	**
**								 	**
**      Scott Smith                                                     **
**	Copyright (c) 1999						**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**									**
**      $Header: $
**									**
*************************************************************************/

/*************************************************************************
**									**
** Description							 	**
**								 	**
** This file contains all include statements associated with the GAMMA	**
** ESR library.  This file includes classes and functions that are	**
** used in higher level GAMMA workings.  				**
**								 	**
*************************************************************************/

#ifndef __ESRIF_H__				// Is this already included?
#define __ESRIF_H__				// If no, then include it

#include <ESRLib/CubicIonData.h>		// Include cubic ion data
#include <ESRLib/CubicIon.h>			// Include cubic ions
//#include <ESRLib/MagIon.h>			// Include magnetic ions
//#include <ESRLib/CubicSys.h>			// Include cubic systems
//#include <ESRLib/ESRHam.h>			// Include ESR Hamiltonians
//#include <ESRLib/AngleSet.h>			// Include angle sets
//#include <ESRLib/Fibre.h>			// Include fibers

/* The Python interface file adds funtionality to Python via Boost.Python
   It does so by specifying which functions are exported into Python from
   a general Python module, PyModule. Since this module must first be built
   (see src/PyGAMMAIF.cc and src/PyGAMMAIF.h) we cannot use the header
   until after the compilation of PyGAMMAIF.cc.                          */

//#include <ESRLib/PyESRLib.h>			// Include Python interface

#endif 						// ESRIF.h
