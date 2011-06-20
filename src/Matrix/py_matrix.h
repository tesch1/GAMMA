/* py_matrix.h **************************************************-*-c++-*-
**									**
**                                G A M M A				**
**									**
**	General Matrix PyGAMMA                               Interface	**
**									**
**	Copyright (c) 2002						**
**	Scott A. Smith							**
**									**
**      $Header: $
**									**
*************************************************************************/

/*************************************************************************
**                                                                      **
** Description                                                          **
**                                                                      **
** This file exists only to appease MSVC++ V6 when used to build	**
** PyGAMMA. I don't know if other versions suffer from the same		**
** condition, but the compiler will die from reaching a compiler limit:	**
**									**
**   fatal error C1204: compiler limit : internal structure overflow	**
**                                                                      **
** Although the Boost.Python people are (slowly) looking into why this	**
** occurs, there is a way around this problem. I don't know how anyone	**
** discovered it, since MS has no dox on error C1204 AFAIK, but one can	**
** break up the Boost.Python class exports into multiple files to stop	**
** the error from occurring. So, while much of the class matrix Python	**
** exports are found in matrix.{cc,h}, we need to have some of them put	**
** into this additonal file.						**
**									**
** Note that this additonal file does nothing if NOT building PyGAMMA.	**
** Also, if Boost.Python finds the reason MSVC++ V6 is behaving badly,	**
** I can make this file go away by putting all the code herein into	**
** matrix.h.								**
**                                                                      **
*************************************************************************/

#ifndef   Gpymatrix_h_				// Is file already included?
#  define Gpymatrix_h_ 1			// If no, then remember it
#  if defined GAMPRAGMA				// Using the GNU compiler?
#    pragma interface				// This is the interface
#  endif

#ifdef PYGAMMA					// Begin PyGAMMA code block

#include <Matrix/matrix.h>			// Include GAMMA matrices
#include <boost/python/class.hpp>		// Boost.Python classes

void PyMatrixMore(boost::python::class_<matrix>& PyMxClass);

#endif						// End of PyGAMMA code block

#endif						// py_matrix.h
