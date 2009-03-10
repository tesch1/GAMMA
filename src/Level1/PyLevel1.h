/* PyLevel1.h ****************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Level 1 Module				Interface	**
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
** into Python from the Level 1 module sources. The only thing it will	**
** need in addition to PYGAMMA being set non-zero is the name PyModule **
** set. The value of PyModule will be set in PyGAMMAIF.h to be pygamma. **
**									**
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyLevel1_h_			// Is this file already included?
#define _PyLevel1_h_ 1			// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// D                     GAMMA Level 1 Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ____________________________________________________________________________
//                              Coordinate Class
// ____________________________________________________________________________

//                                  The Class

    boost::python::class_builder<coord> coord_class(PyModule, "coord");

//                                Constructors

    coord_class.def(boost::python::constructor<>());
    coord_class.def(boost::python::constructor<double, double, double>());
    coord_class.def(boost::python::constructor<const coord&>());
    coord_class.def(boost::python::constructor<const ParameterSet&, int, int>());
    coord_class.def(boost::python::constructor<const SinglePar&>());

//                              Member Functions

    coord_class.def(&coord::get, "get");

    coord_class.def((double (coord::*)() const) &coord::x, "x");
    coord_class.def((double (coord::*)() const) &coord::y, "y");
    coord_class.def((double (coord::*)() const) &coord::z, "z");
    coord_class.def((void   (coord::*)(double)) &coord::x, "x");
    coord_class.def((void   (coord::*)(double)) &coord::y, "y");
    coord_class.def((void   (coord::*)(double)) &coord::z, "z");

    coord_class.def((void   (coord::*)(double, double, double)) &coord::xyz,   "xyz");
    coord_class.def((void   (coord::*)(const coord&))           &coord::xyz,   "xyz");
    coord_class.def((double (coord::*)() const)                 &coord::Rad,   "Rad");
    coord_class.def((double (coord::*)(const coord&) const)     &coord::Rad,   "Rad");
    coord_class.def((double (coord::*)() const)                 &coord::theta, "theta");
    coord_class.def((double (coord::*)(const coord&) const)     &coord::theta, "theta");
    coord_class.def((double (coord::*)() const)                 &coord::phi,   "phi");
    coord_class.def((double (coord::*)(const coord&) const)     &coord::phi,   "phi");

    coord_class.def(&coord::invert, "invert");

    coord_class.def((matrix (*)(double, int)) &coord::Rx, "Rx");	// static
    coord_class.def((matrix (*)(double, int)) &coord::Ry, "Ry");	// static
    coord_class.def((matrix (*)(double, int)) &coord::Rz, "Rz");	// static


// These next function produce duplicate comdat
//coord_class.def(&coord::xrotate, "xrotate");
//coord_class.def(&coord::yrotate, "yrotate");
//coord_class.def(&coord::zrotate, "zrotate");

    coord_class.def(&coord::Ralpha, "Ralpha");
    coord_class.def(&coord::Rbeta,  "Rbeta");
    coord_class.def(&coord::Rgamma, "Rgamma");
    coord_class.def(&coord::REuler, "REuler");


    coord_class.def((coord (coord::*)(double, double, double)) &coord::rotate, "rotate");
    coord_class.def((coord (coord::*)(coord&))                 &coord::rotate, "rotate");

    coord_class.def(&coord::trans_x, "trans_x");
    coord_class.def(&coord::trans_y, "trans_y");
    coord_class.def(&coord::trans_z, "trans_z");

    coord_class.def(&coord::trans_x_ip, "trans_x_ip");
    coord_class.def(&coord::trans_y_ip, "trans_y_ip");
    coord_class.def(&coord::trans_z_ip, "trans_z_ip");

    coord_class.def((coord (coord::*)(double, double, double)) &coord::translate, "translate");
    coord_class.def((coord (coord::*)(const coord&) const)     &coord::translate, "translate");
    coord_class.def((void  (coord::*)(double, double, double)) &coord::translate_ip, "translate_ip");
    coord_class.def((void  (coord::*)(const coord&))           &coord::translate_ip, "translate_ip");

//                                  Operators

    coord_class.def(boost::python::operators<boost::python::op_add>(), boost::python::right_operand<coord>());
    coord_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::right_operand<double>());
    coord_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::left_operand<double>());
    coord_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::left_operand<matrix>());
//    coord_class.def(boost::python::operators<boost::python::op_div>(), boost::python::right_operand<double>());

//                               Global Functions

    PyModule.def((double (*)(double, double, double))     &Rad,   "Rad");
    PyModule.def((double (*)(const coord&, const coord&)) &Rad,   "Rad");
    PyModule.def((double (*)(double, double, double))     &theta, "theta");
    PyModule.def((double (*)(const coord&, const coord&)) &theta, "theta");
    PyModule.def((double (*)(double, double, double))     &phi,   "phi");
    PyModule.def((double (*)(const coord&, const coord&)) &phi,   "phi");

    PyModule.def(Rmx1, "Rmx1");
    PyModule.def(Rmx2, "Rmx2");
    PyModule.def(Rmx3, "Rmx3");
    PyModule.def(Rmx,  "Rmx");

    PyModule.def(coord_setf, "coord_setf");
//    PyModule.def(coord_getf, "coord_getf"); // int references

//                             Python Specialty Functions

    coord_class.def(&coord::Print, "__str__");

// ______________________________________________________________________
//                        Coordinate Vectors Class
// ______________________________________________________________________

//                                 The Class

    boost::python::class_builder<coord_vec> coord_vec_class(PyModule, "coord_vec");

//                                Constructors

    coord_vec_class.def(boost::python::constructor<>());
    coord_vec_class.def(boost::python::constructor<int>());
    coord_vec_class.def(boost::python::constructor<const coord_vec>());
    coord_vec_class.def(boost::python::constructor<const ParameterSet&, int, int>());

//                            Member Functions

    coord_vec_class.def(&coord_vec::Print, "__str__");

// sosi - This is a problem. Produces duplicate comdat errors during the build

//    coord_vec_class.def(&coord_vec::xrotate, "xrotate");
//    coord_vec_class.def(&coord_vec::yrotate, "yrotate");
//    coord_vec_class.def(&coord_vec::zrotate, "zrotate");


    coord_vec_class.def((coord_vec (coord_vec::*)(const matrix&) const)          &coord_vec::rotate,    "rotate");
    coord_vec_class.def((coord_vec (coord_vec::*)(double, double, double) const) &coord_vec::rotate,    "rotate");
    coord_vec_class.def((coord_vec (coord_vec::*)(const coord&) const)           &coord_vec::rotate,    "rotate");
    coord_vec_class.def((void      (coord_vec::*)(double, double, double))       &coord_vec::rotate_ip, "rotate_ip");
    coord_vec_class.def((void      (coord_vec::*)(const coord&))                 &coord_vec::rotate_ip, "rotate_ip");

    coord_vec_class.def((coord_vec (coord_vec::*)(double, double, double) const) &coord_vec::translate,    "translate");
    coord_vec_class.def((coord_vec (coord_vec::*)(const coord&) const)           &coord_vec::translate,    "translate");
    coord_vec_class.def((void      (coord_vec::*)(double, double, double))       &coord_vec::translate_ip, "translate_ip");
    coord_vec_class.def((void      (coord_vec::*)(const coord&))                 &coord_vec::translate_ip, "translate_ip");

    coord_vec_class.def(&coord_vec::trans_x,    "trans_x");
    coord_vec_class.def(&coord_vec::trans_y,    "trans_y");
    coord_vec_class.def(&coord_vec::trans_z,    "trans_z");
    coord_vec_class.def(&coord_vec::trans_x_ip, "trans_x_ip");
    coord_vec_class.def(&coord_vec::trans_y_ip, "trans_y_ip");
    coord_vec_class.def(&coord_vec::trans_z_ip, "trans_z_ip");
    coord_vec_class.def(&coord_vec::project,    "project");
    coord_vec_class.def(&coord_vec::size,       "size");
    coord_vec_class.def(&coord_vec::max_x,      "max_x");
    coord_vec_class.def(&coord_vec::max_y,      "max_y");
    coord_vec_class.def(&coord_vec::max_z,      "max_z");

    coord_vec_class.def((coord (coord_vec::*)() const) &coord_vec::maxima, "maxima");
    coord_vec_class.def(&coord_vec::maxima_COORD_VEC_py1, "maxima");
    coord_vec_class.def((double (coord_vec::*)() const) &coord_vec::max_R, "maxima");
    coord_vec_class.def(&coord_vec::max_R_COORD_VEC_py1, "max_R");

    coord_vec_class.def(&coord_vec::vectors,   "vectors");
    coord_vec_class.def(&coord_vec::vectors_f, "vectors_f");
    coord_vec_class.def(&coord_vec::distances, "distances");
    coord_vec_class.def(&coord_vec::distance,  "distance");

// sosi - This is a problem. Produces duplicate comdat errors during the build

//    coord_vec_class.def(&coord_vec::thetas, "thetas");
//    coord_vec_class.def(&coord_vec::phis,   "phis");

    coord_vec_class.def((void (coord_vec::*)(const coord&, int))           &coord_vec::put, "put");
    coord_vec_class.def((void (coord_vec::*)(double, double, double, int)) &coord_vec::put, "put");
    coord_vec_class.def(&coord_vec::get, "put");

    coord_vec_class.def(&coord_vec::x, "x");
    coord_vec_class.def(&coord_vec::y, "y");
    coord_vec_class.def(&coord_vec::z, "z");

    coord_vec_class.def(&coord_vec::put_block, "put_block");
    coord_vec_class.def(&coord_vec::get_block, "get_block");
    coord_vec_class.def(&coord_vec::PSetAdd,   "PSetAdd");

// sosi - This is a problem. Produces duplicate comdat errors during the build

//    coord_vec_class.def(&coord_vec::Cart2Sph, "Cart2Sph");
//    coord_vec_class.def(&coord_vec::Sph2Cart, "Sph2Cart");

//    coord_vec_class.def(&coord_vec::Cart2Cyl, "Cart2Cyl");
//    coord_vec_class.def(&coord_vec::Cyl2Cart, "Cyl2Cart");

//    coord_vec_class.def(&coord_vec::Sph2Cyl,  "Sph2Cyl");
//    coord_vec_class.def(&coord_vec::Cyl2Sph,  "Cyl2Sph");

    coord_vec_class.def(&coord_vec::printCartesian_COORD_VEC_py1,   "printCartesian");
    coord_vec_class.def(&coord_vec::printCylindrical_COORD_VEC_py1, "printCylindrical");
    coord_vec_class.def(&coord_vec::printSpherical_COORD_VEC_py1,   "printSpherical");


//                                Operators

    coord_vec_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::right_operand<double>());
    coord_vec_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::left_operand<double>());
//    coord_vec_class.def(boost::python::operators<boost::python::op_div>(), boost::python::right_operand<double>());

//                             Python Specialty Functions

// ______________________________________________________________________
//                           Generic Spin Tensors
// ______________________________________________________________________

//                                  The Class
		
    boost::python::class_builder<spin_T> spin_T_class(PyModule, "spin_T");

//                                Constructors

    spin_T_class.def(boost::python::constructor<>());
    spin_T_class.def(boost::python::constructor<const spin_sys&>());
    spin_T_class.def(boost::python::constructor<const spin_T&>());
    spin_T_class.def(boost::python::constructor<const spin_T&, int>());

//                                Member Functions


    spin_T_class.def(&spin_T::component, "component");

    spin_T_class.def((spin_T  (spin_T::*)(double, double, double))           &spin_T::rotate, "rotate");
    spin_T_class.def((spin_T  (spin_T::*)(const coord&))                     &spin_T::rotate, "rotate");
    spin_T_class.def((spin_op (spin_T::*)(int, int, double, double, double)) &spin_T::rotate, "rotate");
    spin_T_class.def((spin_op (spin_T::*)(int, int, const coord&))           &spin_T::rotate, "rotate");

    spin_T_class.def(&spin_T::Rank, "Rank");

//                                Global Functions

    PyModule.def((spin_T  (*)(const spin_sys&, int))              &T1,  "T1");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int))    &T1,  "T1");
    PyModule.def((spin_op (*)(const spin_sys&, int, int))         &T10, "T10");
    PyModule.def((spin_op (*)(spin_op&, int))                     &T10, "T10");
    PyModule.def((spin_T  (*)(const spin_sys&, int))              &T11, "T11");
    PyModule.def((spin_op (*)(const spin_sys&, int, int))         &T11, "T11");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, int)) &T11, "T11");

    PyModule.def((spin_op (*)(const spin_sys&, int, int, int, int)) &T2,  "T2");
    PyModule.def((spin_T  (*)(const spin_sys&, int, const coord&))  &T2,  "T2");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int))      &T20, "T20");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int))      &T21, "T21");
    PyModule.def((spin_T  (*)(const spin_sys&, int, int))           &T22, "T22");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int))      &T22, "T22");
    PyModule.def((spin_T  (*)(const spin_sys&, int, const coord&))  &T22, "T22");

    PyModule.def((spin_T  (*)(const spin_sys&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&)) &T22, "T22");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, int, int)) &T2,  "T2");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, int))      &T20, "T20");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, int))      &T21, "T21");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, int))      &T22, "T22");

    PyModule.def((spin_T  (*)(const spin_sys&, spin_op&, spin_op&, spin_op&, const coord&)) &T2, "T2");
    PyModule.def((spin_T  (*)(const spin_sys&, int, const coord&, int)) &T2SS, "T2SS");
    PyModule.def((spin_T  (*)(const spin_sys&, spin_op&, spin_op&, spin_op&, const coord&, int)) &T2SS, "T2SS");

    PyModule.def((spin_T  (*)(const spin_sys&, spin_op&, spin_op&, spin_op&, const coord&)) &T22, "T22");
    PyModule.def((spin_T  (*)(const spin_sys&, int, const coord&, int)) &T22SSirr, "T22SSirr");
    PyModule.def((spin_T  (*)(const spin_sys&, spin_op&, spin_op&, spin_op&, const coord&, int)) &T22SSirr, "T22SSirr");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int, int)) &T2, "T2");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int, int)) &T2, "T2");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int)) &T20, "T20");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int)) &T20, "T20");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int)) &T21, "T21");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int)) &T21, "T21");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int)) &T22, "T22");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int)) &T22, "T22");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int, int, int)) &T2SS, "T2SS");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int, int, int)) &T2SS, "T2SS");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int, int)) &T20SS, "T20SS");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int, int)) &T20SS, "T20SS");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int, int )) &T21SS, "T21SS");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int, int)) &T21SS, "T21SS");
    PyModule.def((spin_op (*)(const spin_sys&, int, const coord&, int, int)) &T22SS, "T22SS");
    PyModule.def((spin_op (*)(spin_op&, spin_op&, spin_op&, const coord&, int, int)) &T22SS, "T22SS");
    PyModule.def((spin_T  (*)(const spin_sys&, int, int))         &T2,  "T2");

    PyModule.def(T22wh, "T22wh");

    PyModule.def((spin_T  (*)(spin_T&, spin_T&))            &T_mult, "T_mult");
    PyModule.def((spin_op (*)(spin_T&, spin_T&, int, int))  &T_mult, "T_mult");
    PyModule.def((spin_op (*)(spin_T&, space_T&, int, int)) &T_prod, "T_prod");
    PyModule.def((spin_op (*)(space_T&, spin_T&, int, int)) &T_prod, "T_prod");
    PyModule.def((spin_op (*)(spin_T&, space_T&, int))      &T_prod, "T_prod");
    PyModule.def((spin_op (*)(space_T&, spin_T&, int))      &T_prod, "T_prod");
    PyModule.def((spin_op (*)(spin_T&, space_T&))           &T_prod, "T_prod");
    PyModule.def((spin_op (*)(space_T&, spin_T&))           &T_prod, "T_prod");

    PyModule.def(Clebsch_Gordan, "Clebsch_Gordan");
    PyModule.def(Wigner_3j,      "Wigner_3j");

//                             Python Specialty Functions

    spin_T_class.def(&spin_T::Print,     "__str__");

// ______________________________________________________________________
//		        Generic Spatial Tensors
// ______________________________________________________________________

//                                  The Class

    boost::python::class_builder<space_T> space_T_class(PyModule, "space_T");

//                                 Constructors

    space_T_class.def(boost::python::constructor<>());
    space_T_class.def(boost::python::constructor<const space_T&>());
    space_T_class.def(boost::python::constructor<const space_T&, int>());
    space_T_class.def(boost::python::constructor<const SinglePar&>());

//                                Member Functions


    space_T_class.def(&space_T::PASys,    "PASys");
    space_T_class.def(&space_T::PASys_EA, "PASys_EA");

    space_T_class.def((double (space_T::*)() const) &space_T::iso,  "iso");
    space_T_class.def((double (space_T::*)() const) &space_T::eta,  "eta");
    space_T_class.def((double (space_T::*)() const) &space_T::delz, "delz");
    space_T_class.def((void   (space_T::*)(double)) &space_T::eta,  "eta");
    space_T_class.def((void   (space_T::*)(double)) &space_T::iso,  "iso");
    space_T_class.def((void   (space_T::*)(double)) &space_T::delz, "delz");

    space_T_class.def(&space_T::alpha, "alpha");
    space_T_class.def(&space_T::beta,  "beta");
    space_T_class.def(&space_T::gamma, "gamma");

    space_T_class.def((int (space_T::*)() const)    &space_T::exists, "exists");
    space_T_class.def((int (space_T::*)(int) const) &space_T::exists, "exists");

    space_T_class.def(&space_T::Rank,       "Rank");
    space_T_class.def(&space_T::component,  "component");
    space_T_class.def(&space_T::Ccomponent, "Ccomponent");

    space_T_class.def((space_T (space_T::*)(double, double, double) const)           &space_T::rotate, "rotate");
    space_T_class.def((space_T (space_T::*)(const coord&) const)                     &space_T::rotate, "rotate");
    space_T_class.def((complex (space_T::*)(int, int, double, double, double) const) &space_T::rotate, "rotate");
    space_T_class.def((complex (space_T::*)(int, int, const coord&) const)           &space_T::rotate, "rotate");

//                                         Operators

    space_T_class.def(boost::python::operators<boost::python::op_add>(), boost::python::right_operand<space_T>());
    space_T_class.def(boost::python::operators<boost::python::op_sub>(), boost::python::right_operand<space_T>());

    space_T_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::right_operand<complex>());
    space_T_class.def(boost::python::operators<boost::python::op_mul>(), boost::python::left_operand<complex>());
 
//                                      Global Functions

    PyModule.def((space_T (*)(double, double, double))      &A1,    "A1");
    PyModule.def((space_T (*)(coord&))                      &A1,    "A1");
    PyModule.def((complex (*)(double, double, double, int)) &A11,   "A11");
    PyModule.def((space_T (*)(complex, complex, complex))   &SphA1, "SphA1");
    PyModule.def((space_T (*)(coord&))                      &SphA1, "SphA1");

    PyModule.def((space_T (*)(double, double, double, double, double, double)) &A2, "A2");

    PyModule.def((space_T (*)(coord&))                           &A2, "A2");
    PyModule.def((space_T (*)(coord&, coord&))                   &A2, "A2");
    PyModule.def((space_T (*)(const matrix&, double))            &A2, "A2");
    PyModule.def((complex (*)(int, int, double, double, double)) &A2, "A2");
    PyModule.def((complex (*)(int, int, const matrix&))          &A2, "A2");

    PyModule.def((complex (*)(int, double, double, double)) &A20, "A20");
    PyModule.def((complex (*)(int, const matrix&))          &A20, "A20");
    PyModule.def((complex (*)(int, double, double, double)) &A21, "A21");
    PyModule.def((complex (*)(int, const matrix&))          &A21, "A21");
    PyModule.def((complex (*)(int, double, double, double)) &A22, "A22");
    PyModule.def((complex (*)(int, const matrix&))          &A22, "A22");

    PyModule.def((space_T (*)(const space_T&, const space_T&))                     &T_mult, "T_mult");
    PyModule.def((space_T (*)(const space_T&, int, const space_T&, int))           &T_mult, "T_mult");
    PyModule.def((space_T (*)(const space_T&, int, const space_T&, int, int))      &T_mult, "T_mult");
    PyModule.def((complex (*)(const space_T&, int, const space_T&, int, int, int)) &T_mult, "T_mult");

//                             Python Specialty Functions

    space_T_class.def(&space_T::Print,    "__str__");
    PyModule.def(Cartesian_SPACE_T_py1, "Cartesian");

// ______________________________________________________________________
//                          Exponential Functions
// ______________________________________________________________________

    PyModule.def((row_vector (*)(int, double, double))              &Exponential,  "Exponential");
    PyModule.def((row_vector (*)(int, double, double, double, int)) &Exponential,  "Exponential");
    PyModule.def((row_vector (*)(int, double, double))              &DExponential, "DExponential");
    PyModule.def((row_vector (*)(int, double, double, double, int)) &DExponential, "DExponential");
    PyModule.def((int (*)(int, double, double, double, double))     &Exponen_cut,  "Exponen_cut");

// sosi - We cannot allow the cut functions because of their use of array pointers
// ______________________________________________________________________
//                         Lorentzian Functions
// ______________________________________________________________________

    PyModule.def((complex    (*)(double, double, double))                                             &Lorentzian, "Lorentzian");
    PyModule.def((row_vector (*)(int, double, double, double, double))                                &Lorentzian, "Lorentzian");
    PyModule.def((row_vector (*)(int, double, double, int))                                           &Lorentzian, "Lorentzian");
    PyModule.def((row_vector (*)(double, double, double, double, int, complex&, double, int))         &Lorentzian, "Lorentzian");
    PyModule.def((void       (*)(row_vector&, double, double, double, double, complex&, double, int)) &Lorentzian, "Lorentzian");

// sosi - We cannot allow these functions because of their use of array pointers

//  PyModule.def(Lorentz_int_py1, "Lorentz_int");
//  PyModule.def(Lorentz_int_py1, "Lorentz_int");
//  PyModule.def(Lorentz_cut_py1, "Lorentz_cut");
//  PyModule.def(Lorentz_cut_py1, "Lorentz_cut");


//  PyModule.def((complex (*)(double, double, double))                 &DLorentzian, "DLorentzian");
//  PyModule.def((row_vector (*)(int, double, double, double, double)) &DLorentzian, "DLorentzian");
//  PyModule.def((row_vector (*)(int, double, double, int))            &DLorentzian, "DLorentzian");

// ______________________________________________________________________
//                          MR Tensor Functions
// ______________________________________________________________________

    PyModule.def((spin_T  (*)(const spin_sys&, int, int))      &T_D,   "T_D");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int)) &T_D,   "T_D");
    PyModule.def((spin_T  (*)(const spin_sys&, int))           &T_CS2, "T_CS2");
    PyModule.def((spin_T  (*)(const spin_sys&, int, coord&))   &T_CS2, "T_CS2");
    PyModule.def((spin_T  (*)(const spin_sys&, int))           &T_CS,  "T_CS2");
    PyModule.def((spin_op (*)(const spin_sys&, int, int))      &T_CS,  "T_CS2");
    PyModule.def((spin_T  (*)(const spin_sys&, int))           &T_RF,  "T_RF");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int)) &T_RF,  "T_RF");
    PyModule.def((spin_T  (*)(const spin_sys&, int))           &T_Q,   "T_Q");
    PyModule.def((spin_op (*)(const spin_sys&, int, int, int)) &T_Q,   "T_Q");

    PyModule.def((spin_T  (*)(const spin_sys&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&, spin_op&)) &T_D, "T_D");
    PyModule.def((spin_op (*)(const spin_sys&, int, coord&, int, int)) &T_CS2, "T_CS2");
    PyModule.def(T_CSA, "T_CSA");
// ______________________________________________________________________
//                    Spherical Harmonics Functions
// ______________________________________________________________________

    PyModule.def(Y00rad, "Y00rad");
    PyModule.def(Y10rad, "Y10rad");
    PyModule.def(Y11rad, "Y11rad");

    PyModule.def((double  (*)(double))         &Y20rad,  "Y20rad");
    PyModule.def((complex (*)(double, double)) &Y1m1rad, "Y1m1rad");
    PyModule.def((complex (*)(double, double)) &Y21rad,  "Y21rad");
    PyModule.def((complex (*)(double, double)) &Y2m1rad, "Y2m1rad");
    PyModule.def((complex (*)(double, double)) &Y22rad,  "Y22rad");
    PyModule.def((complex (*)(double, double)) &Y2m2rad, "Y2m2rad");
    PyModule.def((double  (*)(double))         &Y30rad,  "Y30rad");
    PyModule.def((complex (*)(double, double)) &Y31rad,  "Y31rad");
    PyModule.def((complex (*)(double, double)) &Y3m1rad, "Y3m1rad");
    PyModule.def((complex (*)(double, double)) &Y32rad,  "Y32rad");
    PyModule.def((complex (*)(double, double)) &Y3m2rad, "Y3m2rad");
    PyModule.def((complex (*)(double, double)) &Y33rad,  "Y33rad");
    PyModule.def((complex (*)(double, double)) Y3m3rad,  "Y3m3rad");

    PyModule.def((complex (*)(int, int, double, double)) &Ylmrad, "Ylmrad");

    PyModule.def(Y00, "Y00");
    PyModule.def(Y10, "Y10");
    PyModule.def(Y11, "Y11");

    PyModule.def((complex (*)(double, double)) &Y1m1, "Y1m1");
    PyModule.def((double  (*)(double))         &Y20,  "Y20");
    PyModule.def((complex (*)(double, double)) &Y21,  "Y21");
    PyModule.def((complex (*)(double, double)) &Y2m1, "Y2m1");
    PyModule.def((complex (*)(double, double)) &Y22,  "Y22");
    PyModule.def((complex (*)(double, double)) &Y2m2, "Y2m2");
    PyModule.def((double (*)(double))          &Y30,  "Y30");
    PyModule.def((complex (*)(double, double)) &Y31,  "Y31");
    PyModule.def((complex (*)(double, double)) &Y3m1, "Y3m1");
    PyModule.def((complex (*)(double, double)) &Y32,  "Y32");
    PyModule.def((complex (*)(double, double)) &Y3m2, "Y3m2");
    PyModule.def((complex (*)(double, double)) &Y33,  "Y33");
    PyModule.def((complex (*)(double, double)) &Y3m3, "Y3m3");

    PyModule.def((complex (*)(int, int, double, double)) &Ylm, "Ylm");

// ______________________________________________________________________
//                    Wigner Rotation Matrix Functions
// ______________________________________________________________________

    PyModule.def(d0, "d0");

    PyModule.def((double (*)(int, double))      &d1half,  "d1half");
    PyModule.def((double (*)(int, int, double)) &d1half,  "d1half");

    PyModule.def((double (*)(int, double))      &dm1half, "dm1half");

    PyModule.def((double (*)(int, double))      &d11,     "d11");
    PyModule.def((double (*)(int, double))      &d10,     "d10");
    PyModule.def((double (*)(int, double))      &d1m1,    "d1m1");

    PyModule.def((double (*)(int, int, double)) &d1,      "d1");

    PyModule.def((double (*)(int, double))      &d22,     "d22");
    PyModule.def((double (*)(int, double))      &d21,     "d21");
    PyModule.def((double (*)(int, double))      &d20,     "d20");
    PyModule.def((double (*)(int, double))      &d2m1,    "d2m1");
    PyModule.def((double (*)(int, double))      &d2m2,    "d2m2");
    PyModule.def((double (*)(int, int, double)) &d2,      "d2");

    PyModule.def(fact, "fact");

    PyModule.def((double (*)(int, int, int, double)) &dJ_int,      "dJ_int");
    PyModule.def((double (*)(int, int, int, double)) &dJ_half_int, "dJ_half_int");
    PyModule.def((double (*)(int, int, int, double)) &dJ,          "dJ");
    PyModule.def((matrix (*)(int, double))           &dJ,          "dJ");

    PyModule.def((complex (*)(int, int, int, double, double, double)) &DJ, "DJ");
    PyModule.def(D0,     "D0");
    PyModule.def(D1half, "D1half");

    PyModule.def((complex (*)(int, int, double, double, double)) &D1, "D1");
    PyModule.def((complex (*)(int, int, double, double, double)) &D2, "D2");
    PyModule.def((matrix  (*)(int, double, double, double))      &DJ, "DJ");
    PyModule.def((matrix  (*)(matrix&, int, double))             &DJ, "DJ");

// ______________________________________________________________________
//                        MR Windowing Functions
// ______________________________________________________________________


    PyModule.def((void (*)(col_vector&, double, int)) &exponential_multiply, "exponential_multiply");
    PyModule.def((void (*)(row_vector&, double, int)) &exponential_multiply, "exponential_multiply");
    PyModule.def((row_vector (*)(int, int, double)) &Lorentzian, "Lorentzian");


//    PyModule.def(exponential,  "exponential");
//    PyModule.def(Gaussian,     "Gaussian");
//    PyModule.def(Hamming,      "Hamming");
//    PyModule.def(Hanning,      "Hanning");
//    PyModule.def(hyperbol_sec, "hyperbol_sec");
//    PyModule.def(Kaiser,       "Kaiser");

    PyModule.def(sin_square,  "sin_square");
    PyModule.def(sinc,        "sinc");
    PyModule.def(square_wave, "square_wave");

    PyModule.def((row_vector (*)(int, double))         &Noise, "Noise");
    PyModule.def((void       (*)(row_vector&, double)) &Noise, "Noise");


#endif					// End of PyLevel1.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

