/* PyGradients.h ************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Gradients Module	               Interface	**
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
** The PyGAMMA interface will include this file. This file contains all **
** of the needed definitions as to what should be/will be exported	**
** into Python from the Gradients module sources. The only thing it will	**
** need in addition to PYGAMMA being set non-zero is the name PyModule **
** set. The value of PyModule will be set in PyGAMMAIF.h to be pygamma. **
**									**
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyGradients_h_			// Is this file already included?
#define _PyGradients_h_ 1		// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// H                     GAMMA Gradients Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                            Gradients Matrix Class
// ----------------------------------------------------------------------------
/*
//                                  The Class

    boost::python::class_builder<GradientsMx> GradientsMx_class(PyModule, "GradientsMx");

//                             Base Class Inheritance

    GradientsMx_class.declare_base(matrix_class, boost::python::without_downcast);

//                              Constructors

    GradientsMx_class.def(boost::python::constructor<> ());

//                            Member Functions

//                                      Operators

    GradientsMx_class.def(boost::python::operators<boost::python::op_add>(), boost::python::right_operand<GradientsMx>());
    GradientsMx_class.def(boost::python::operators<boost::python::op_sub>(), boost::python::right_operand<GradientsMx>());
    GradientsMx_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::right_operand<GradientsMx>());
    GradientsMx_class.def(boost::python::operators<boost::python::op_div>(), boost::python::right_operand<GradientsMx>());
    GradientsMx_class.def(boost::python::operators<boost::python::op_add>(), boost::python::left_operand<GradientsMx>());
    GradientsMx_class.def(boost::python::operators<boost::python::op_sub>(), boost::python::left_operand<GradientsMx>());
//  GradientsMx_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::left_operand<GradientsMx>());
    GradientsMx_class.def(boost::python::operators<boost::python::op_div>(), boost::python::left_operand<GradientsMx>());

//                          Python Specialty Functions

    GradientsMx_class.def(&GradientsMx::PyPrint, "__str__");


//                             Global Functions
*/

#endif					// End of PyGradients.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

