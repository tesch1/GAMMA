/* PyBWR.h ******************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA BWR Module	                         Interface	**
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
** into Python from the BWR module sources. The only thing it will	**
** need in addition to PYGAMMA being set non-zero is the name PyModule **
** set. The value of PyModule will be set in PyGAMMAIF.h to be pygamma. **
**									**
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyBWR_h_			// Is this file already included?
#define _PyBWR_h_ 1			// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// H                     GAMMA BWR Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                            BWR Matrix Class
// ----------------------------------------------------------------------------

//                                  The Class

/*
    boost::python::class_builder<BWRMx> BWRMx_class(PyModule, "BWRMx");

//                             Base Class Inheritance

    BWRMx_class.declare_base(matrix_class, boost::python::without_downcast);

//                              Constructors

    BWRMx_class.def(boost::python::constructor<> ());

//                            Member Functions

//                                      Operators

    BWRMx_class.def(boost::python::operators<boost::python::op_add>(), boost::python::right_operand<BWRMx>());
    BWRMx_class.def(boost::python::operators<boost::python::op_sub>(), boost::python::right_operand<BWRMx>());
    BWRMx_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::right_operand<BWRMx>());
    BWRMx_class.def(boost::python::operators<boost::python::op_div>(), boost::python::right_operand<BWRMx>());
    BWRMx_class.def(boost::python::operators<boost::python::op_add>(), boost::python::left_operand<BWRMx>());
    BWRMx_class.def(boost::python::operators<boost::python::op_sub>(), boost::python::left_operand<BWRMx>());
//  BWRMx_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::left_operand<BWRMx>());
    BWRMx_class.def(boost::python::operators<boost::python::op_div>(), boost::python::left_operand<BWRMx>());
*/

    PyModule.def((super_op (*)(const sys_dynamic&, gen_op&, int, int)) &RQQ, "RQQ");

//                          Python Specialty Functions

    PyModule.def((super_op (*)(const sys_dynamic&, const gen_op&)) &RQQBWR1, "RQQ");

// ----------------------------------------------------------------------------
//                           BWR Exchange Matrices
// ----------------------------------------------------------------------------

//                             Global Functions


#endif					// End of PyBWR.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

