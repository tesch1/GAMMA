/* Pyy_matrix.cc ************************************************-*-c++-*-
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

#ifndef   Gpyymatrix_cc_		// Is file already included?
#  define Gpyymatrix_cc_ 1		// No, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma implementation		// This is the implementation
#  endif

#include <Matrix/pyy_matrix.h>		// Include the interface
#include <Matrix/matrix.h>		// Include class matrix interface

#ifdef PYGAMMA				// Begin PyGAMMA code block

#include <boost/python/class.hpp>			// Boost.Python classes
#include <boost/python/operators.hpp>			// Boost.Python operators
#include <boost/python/def.hpp>
#include <boost/python/overloads.hpp>

using boost::python::class_;
using boost::python::def;
using boost::python::self;
using boost::python::init;

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(matrix_status, matrix::status, 0, 1)

void PyMatrixEvenMore(class_<matrix>& PyMxClass)
  {

//                                The Class
  PyMxClass

    .def("resize",            &matrix::resize)
    .def("diagonal_form",     &matrix::diagonal_form)
    .def("same_reference_as", &matrix::same_reference_as)
    .def("status",            (void(matrix::*) (int) const)0, matrix_status())

//                 Matrix Diagonalization Functions

/* Note that BlockDiag returns std::vector<double> so we must have an
   export into Python which handles that. See PyBoost.{h,cc} in the
   GAMMA source directory.                                            */

    .def("BlockDiag", &matrix::BlockDiag)
    .def("SymTriDiag",  &matrix::SymTriDiag)
    .def("HermTriDiag", &matrix::HermTriDiag)
    .def("SymDiag",     &matrix::SymDiag)
    .def("Diagonalize", &matrix::Diagonalize)

//                    Matrix Testing Functions

/* Note that ColNorms and TestIdentity return std::vector<double> so
   we must have an export into Python which handles that. See 
   PyBoost.{h,cc} in the GAMMA source directory.                      */

    .def("TestEigenSystem", &matrix::TestEigenSystem)
    .def("TestTransform",   &matrix::TestTransform)
    .def("ColumnNorms",     &matrix::ColumnNorms)
    .def("TestIdentity",    &matrix::TestIdentity)
    .def("TestUnitary",     &matrix::TestUnitary)
    .def("TestUTransform",  &matrix::TestUTransform)

//                    Matrix Diag & Invert Functions

    .def("diag", diag)
    .def("inv",  inv)

//                      Container Support Functions

    .def(self == self)
    .def(self != self)
    .def(self <  self)
    .def(self >  self)

//                 Python Specialty Functions

    .def("__str__", &matrix::PyPrint)
//    .def("__str__", &matrix::PyPicture)

//            Additional Constructors To ByPass Enum

    .def(init<int, int,                 std::string>             ())
    .def(init<int, int, double,         std::string>             ())
    .def(init<int, int, const complex&, std::string>             ())
    .def(init<int, int, double,         std::string, std::string>())
    .def(init<int, int, const complex&, std::string, std::string>())

    ;

//                        Friend Functions

  def("adjoint_times",  adjoint_times);
  def("times_adjoint",  times_adjoint);
  def("tensor_product", tensor_product);

  }

#endif					  	// End PyGAMMA code block

#endif						// pyy_matrix.cc
