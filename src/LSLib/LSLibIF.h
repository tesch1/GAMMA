/* LSLib2IF.h ***************************************************-*-c++-*-
**                                                                      **
**                              G A M M A                               **
**                                                                      **
**      MR Liouville Space Library 		  Interface 		**
**                                                                      **
**      Copyright (c) 1999						**
**      Scott A. Smith							**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**						 			**
**      $Header: $
**								 	**
*************************************************************************/

/*************************************************************************
**                                                                      **
** Description                                                          **
**                                                                      **
** The GAMMA Platform Provides Functions for Simulation of Magnetic     **
** Resonance Experiments and Other Associated   Mathematical            **
** Capabilities.  This file contains all include statements associated	**
** with the GAMMA module supporting computation in Liouville space.	**
**								 	**
*************************************************************************/

#ifndef __LSLibIF_H__			// Is this already included?
#define __LSLibIF_H__			// If no, then include it

#include <LSLib/SuperOp.h>		// Superoperators
#include <LSLib/LSacquire.h>		// Acquisitions in Liouville space
#include <LSLib/LSprop.h>		// Superoperator propagators
#include <LSLib/LSanalyze.h>		// System Analysis
#include <LSLib/sys_dynamic.h>		// Anisotropic spin systems
#include <LSLib/DensOp.h>		// Density operators

/* The Python interface file adds funtionality to Python via Boost.Python
   It does so by specifying which functions are exported into Python from
   a general Python module, PyModule. Since this module must first be built
   (see src/PyGAMMAIF.cc and src/PyGAMMAIF.h) we cannot use the header
   until after the compilation of PyGAMMAIF.cc.                          */

#endif 					// __LSLibIF_H__ 
