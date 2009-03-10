/* Py_matrix.cc *************************************************-*-c++-*-
**                                                                      **
**                             G A M M A				**
**                                                                      **
**	General Matrix PyGAMMA		          Implementation 	**
**                                                                      **
**      Copyright (c) 2002			                        **
**      Scott A. Smith							**
**                                                                      **
**      $Header: $
**                                                                      **
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
** matrix.cc.								**
**                                                                      **
*************************************************************************/

#ifndef   Gpymatrix_cc_			// Is file already included?
#  define Gpymatrix_cc_ 1		// No, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma implementation		// This is the implementation
#  endif

#include <Matrix/py_matrix.h>		// Include the interface
#include <Matrix/matrix.h>		// Include class matrix interface

#ifdef PYGAMMA				// Begin PyGAMMA code block

#include <boost/python/class.hpp>	// Boost.Python classes
#include <boost/python/operators.hpp>	// Boost.Python operators
#include <boost/python/def.hpp>
#include <boost/python/overloads.hpp>

using boost::python::class_;
using boost::python::def;
using boost::python::self;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(matrix_status, matrix::status, 0, 1)

void PyMatrixMore(class_<matrix>& PyMxClass)
  {

//                                The Class
  PyMxClass

//                          Matrix Operators

//    .def(     + self)
    .def(     - self)

    .def(self + self)
    .def(self - self)
    .def(self * self)
    .def(self * complex())
    .def(self * double())
    .def(self / self)
    .def(self / complex())
    .def(self / double())

    .def(complex() * self)
    .def(double()  * self)
//    .def(complex() / self)
//    .def(double()  / self)

    .def(self += self)
    .def(self -= self)
    .def(self *= self)
    .def(self *= complex())
    .def(self *= double())
    .def(self /= self)
    .def(self /= complex())
    .def(self /= double())
    ;

  }

#endif					  	// End PyGAMMA code block

#endif						// py_matrix.cc
