/* Level2IF.h ***************************************************-*-c++-*-
**                                                                      **
**                               G A M M A                              **
**                                                                      **
**	GAMMA Level 2 Library				Interface 	**
**								 	**
**      Scott Smith                                                     **
**	Copyright (c) 1999						**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**						 			**
**      $Header: $
**								 	**
*************************************************************************/

/*************************************************************************
**								 	**
** Description							 	**
**								 	**
** This file contains all include statements associated with the GAMMA	**
** level 2 library.  This file includes classes and functions that are	**
** used in higher level GAMMA workings. Herein are 1D transition tables **
** 1D acquisitons, quaternions, etc.					**
**								 	**
*************************************************************************/

#ifndef __Level2IF_H__				// Is this already included?
#define __Level2IF_H__				// If no, then include it

#include <Level2/TrnsTable1D.h>			// Include 1D transitions table
#include <Level2/acquire1D.h>			// Include 1D acquisitions
#include <Level2/Quaternion.h>			// Include Quaternions
#include <Level2/EAngles.h>			// Include Euler angles
#include <Level2/MutExch.h>			// Include Exchange superops
#include <Level2/RelaxBas.h>			// Include Simple relaxation
#include <Level2/BaseDecomp.h>			// Include base decompositions

/* The Python interface file adds funtionality to Python via Boost.Python
   It does so by specifying which functions are exported into Python from
   a general Python module, PyModule. Since this module must first be built
   (see src/PyGAMMAIF.cc and src/PyGAMMAIF.h) we cannot use the header
   until after the compilation of PyGAMMAIF.cc.                          */

//#include <Level2/PyLevel2.h>			// Include Python interface

#endif 						// Level2IF
