/* FloquetIF.h **************************************************-*-c++-*-
**                                                                      **
**                               G A M M A                              **
**                                                                      **
**	GAMMA Floquet Operators 			Interface 	**
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
** classes and functions supporting simulations using Floquet theory.	**
**								 	**
*************************************************************************/

#ifndef __FloquetIF_H__			// Is this already included?
#define __FloquetIF_H__			// If no, then include it

#include <Floquet/FloqOp.h>		// Include Floquet operators
#include <Floquet/Floq2Op.h>		// Include 2 rotation Floq. ops.
#include <Floquet/FloqAcq.h>		// Include Floquet acquisitions

/* The Python interface file adds funtionality to Python via Boost.Python
   It does so by specifying which functions are exported into Python from
   a general Python module, PyModule. Since this module must first be built
   (see src/PyGAMMAIF.cc and src/PyGAMMAIF.h) we cannot use the header
   until after the compilation of PyGAMMAIF.cc.                          */

//#include <Floquet/PyFloquet.h>		// Include Python interface

#endif 					// __FloquetIF_H__ 
