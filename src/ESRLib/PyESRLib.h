/* PyESRLib.h ***************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA ESR Library Module Python Interface    Interface	**
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
** The PyGAMMA interface contains all of the needed definitions as to	**
** what should be/will be exported into Python from the sources. This	**
** is that file.							**
**									**
*************************************************************************/

// sosi - Some functions are commented out because in MSVC++ they produce
//        "duplicate comdat errors during the build. This implies that the
//        munged names of the functions MSVC++ uses are the same for two or
//        more functions. Normally this is due to some imposed limits on the
//        lengths of the munged names, but here I have no idea what they are
//        caused from.

#ifdef PYGAMMA					// If we are compiling PyGAMMA
						// we will include this stuff
						// BUT INCLUDE NOTHING UNLESS
						// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyESRLib_h_			// Is this file already included?
#define _PyESRLib_h_ 1			// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// F                     GAMMA Level 2 Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                        1D Transition Tables
// ----------------------------------------------------------------------------

/*
//                                  The Class

    boost::python::class_builder<TTable1D> TTable1D_class(PyModule, "TTable1D");
	   	
//                                 Constructors

    TTable1D_class.def(boost::python::constructor<>            ());
    TTable1D_class.def(boost::python::constructor<matrix>      ());
    TTable1D_class.def(boost::python::constructor<matrix, int> ());
    TTable1D_class.def(boost::python::constructor<TTable1D>    ());

//                                Member Functions

    TTable1D_class.def((void (TTable1D::*)(bool))                &TTable1D::center,  "center");
    TTable1D_class.def((void (TTable1D::*)(double, int))         &TTable1D::offset,  "offset");
    TTable1D_class.def((void (TTable1D::*)(double, int, int))    &TTable1D::offset,  "offset");
    TTable1D_class.def((void (TTable1D::*)(double))              &TTable1D::FRscale, "FRscale");
    TTable1D_class.def((void (TTable1D::*)(double, int))         &TTable1D::FRscale, "FRscale");
    TTable1D_class.def((void (TTable1D::*)(double))              &TTable1D::BC,      "BC");

    TTable1D_class.def((void (TTable1D::*)(double))              &TTable1D::Iscale,  "Iscale");
    TTable1D_class.def((void (TTable1D::*)(double, int))         &TTable1D::Iscale,  "Iscale");
    TTable1D_class.def((void (TTable1D::*)(const complex&))      &TTable1D::Iscale,  "Iscale");
    TTable1D_class.def((void (TTable1D::*)(const complex&, int)) &TTable1D::Iscale,  "Iscale");
    TTable1D_class.def((void (TTable1D::*)(double))              &TTable1D::Iremove, "Iremove");

    TTable1D_class.def((void (TTable1D::*)(double, int))         &TTable1D::broaden,    "broaden");
    TTable1D_class.def((void (TTable1D::*)(double, int, int))    &TTable1D::broaden,    "broaden");
    TTable1D_class.def((void (TTable1D::*)(double))              &TTable1D::resolution, "resolution");

    TTable1D_class.def((row_vector (TTable1D::*)(int, double)              const) &TTable1D::T, "T");
    TTable1D_class.def((void       (TTable1D::*)(row_vector& data, double) const) &TTable1D::T, "T");
//std::vector<row_vector> TTable1D::Ts(int npts,        double tinc) const;
//std::vector<int>        TTable1D::TCutoffs(int npts,  double tinc) const;

    TTable1D_class.def((row_vector (TTable1D::*)(int, double, double)         const) &TTable1D::F, "F");
    TTable1D_class.def((void       (TTable1D::*)(row_vector&, double, double) const) &TTable1D::F, "F");
//std::vector<row_vector> TTable1D::Fs(int npts,       double Fst,double Ffi) const;

    TTable1D_class.def((row_vector (TTable1D::*)(int, double, double)         const) &TTable1D::FD, "FD");
    TTable1D_class.def((void       (TTable1D::*)(row_vector&, double, double) const) &TTable1D::FD, "FD");

    TTable1D_class.def(&TTable1D::R2,    "R2");
    TTable1D_class.def(&TTable1D::Fr,    "Fr");
    TTable1D_class.def(&TTable1D::I,     "I");
    TTable1D_class.def(&TTable1D::Tr,    "Tr");


    TTable1D_class.def(&TTable1D::LineWidths,  "LineWidths");
    TTable1D_class.def(&TTable1D::Intensities, "Intensities");
    TTable1D_class.def(&TTable1D::Phases,      "Phases");
    TTable1D_class.def(&TTable1D::size,        "size");
    TTable1D_class.def(&TTable1D::FRmax,       "FRmax");
    TTable1D_class.def(&TTable1D::FRmin,       "FRmin");
    TTable1D_class.def(&TTable1D::Tdmin,       "Tdmin");
    TTable1D_class.def(&TTable1D::LWmax,       "LWmax");
    TTable1D_class.def(&TTable1D::LWmin,       "LWmin");
    TTable1D_class.def(&TTable1D::Imax,        "Imax");
    TTable1D_class.def(&TTable1D::Noisemax,    "Noisemax");
    TTable1D_class.def(&TTable1D::mx,          "mx");

    TTable1D_class.def(&TTable1D::setType,        "setType");
    TTable1D_class.def(&TTable1D::setSort,        "setSort");
    TTable1D_class.def(&TTable1D::setConv,        "setConv");
    TTable1D_class.def(&TTable1D::setIcut,        "setIcut");
//    TTable1D_class.def(&TTable1D::setInorm,       "setInorm");
    TTable1D_class.def(&TTable1D::setSN,          "setSN");
    TTable1D_class.def(&TTable1D::setHprint,      "setHprint");
    TTable1D_class.def(&TTable1D::setRprint,      "setRprint");
    TTable1D_class.def(&TTable1D::setLWprint,     "setLWprint");
    TTable1D_class.def(&TTable1D::setT2print,     "setT2print");
    TTable1D_class.def(&TTable1D::setPHprint,     "setPHprint");
    TTable1D_class.def(&TTable1D::setFreqRev,     "setFreqRev");

    TTable1D_class.def(&TTable1D::getType,        "getType");
    TTable1D_class.def(&TTable1D::getSort,        "getSort");
    TTable1D_class.def(&TTable1D::getConv,        "getConv");
    TTable1D_class.def(&TTable1D::getIcut,        "getIcut");
    TTable1D_class.def(&TTable1D::getInorm,       "getInorm");
    TTable1D_class.def(&TTable1D::getSN,          "getSN");
    TTable1D_class.def(&TTable1D::getHprint,      "getHprint");
    TTable1D_class.def(&TTable1D::getRprint,      "getRprint");
    TTable1D_class.def(&TTable1D::getLWprint,     "getLWprint");
    TTable1D_class.def(&TTable1D::getT2print,     "getT2print");
    TTable1D_class.def(&TTable1D::getPHprint,     "getPHprint");
    TTable1D_class.def(&TTable1D::getFreqRev,     "getFreqRev");

//                              Global Functions

//friend TTable1D sum(const TTable1D& TT1, const TTable1D& TT2, double res=1.e-6);
//std::vector<int> TTable1D::Sort(int k, int type, int colf) const;

//                           Python Specialty Functions

    TTable1D_class.def(&TTable1D::PyPrint, "__str__");
*/

// ----------------------------------------------------------------------------
//                              1 D Acquisitions
// ----------------------------------------------------------------------------

//                                  The Class

/*
    boost::python::class_builder<acquire1D> acquire1D_class(PyModule, "acquire1D");
	   	
//                                 Constructors

    acquire1D_class.def(boost::python::constructor<>());
    acquire1D_class.def(boost::python::constructor<gen_op&, gen_op&, double>());

//                                Member Functions

    acquire1D_class.def(&acquire1D::L,        "L");
    acquire1D_class.def(&acquire1D::D,        "D");
    acquire1D_class.def(&acquire1D::S,        "S");
    acquire1D_class.def(&acquire1D::Sinv,     "Sinv");
    acquire1D_class.def(&acquire1D::TTable,   "TTable");
    acquire1D_class.def(&acquire1D::Detector, "Detector");

    acquire1D_class.def((row_vector (acquire1D::*)(const gen_op&, double,      int))    &acquire1D::T,  "T");
    acquire1D_class.def((row_vector (acquire1D::*)(const gen_op&, int,         double)) &acquire1D::T,  "T");
    acquire1D_class.def((void       (acquire1D::*)(const gen_op&, row_vector&, double)) &acquire1D::T,  "T");

    acquire1D_class.def((row_vector (acquire1D::*)(const gen_op&, int,         double, double)) &acquire1D::F,  "F");
    acquire1D_class.def((void       (acquire1D::*)(const gen_op&, row_vector&, double, double)) &acquire1D::F,  "F");

    acquire1D_class.def((row_vector (acquire1D::*)(const gen_op&, int,         double, double)) &acquire1D::FD, "FD");
    acquire1D_class.def((void       (acquire1D::*)(const gen_op&, row_vector&, double, double)) &acquire1D::FD, "FD");

    acquire1D_class.def((const TTable1D& (acquire1D::*)(const gen_op&)) &acquire1D::table, "table");
//    acquire1D_class.def((const TTable1D& (acquire1D::*)())              &acquire1D::table, "table");

    acquire1D_class.def((void    (acquire1D::*)(double,          int)) &acquire1D::offset,     "offset");
    acquire1D_class.def((void    (acquire1D::*)(double, int,     int)) &acquire1D::offset,     "offset");
    acquire1D_class.def((void    (acquire1D::*)(double))               &acquire1D::FRscale,    "FRscale");
    acquire1D_class.def((void    (acquire1D::*)(double,          int)) &acquire1D::FRscale,    "FRscale");
    acquire1D_class.def((void    (acquire1D::*)(double))               &acquire1D::Iscale,     "Iscale");
    acquire1D_class.def((void    (acquire1D::*)(double,          int)) &acquire1D::Iscale,     "Iscale");
    acquire1D_class.def((void    (acquire1D::*)(double,          int)) &acquire1D::broaden,    "broaden");
    acquire1D_class.def((void    (acquire1D::*)(double, int,     int)) &acquire1D::broaden,    "broaden");
    acquire1D_class.def((void    (acquire1D::*)(double))               &acquire1D::resolution, "resolution");
    acquire1D_class.def((void    (acquire1D::*)(double, complex&))     &acquire1D::pcorrect,   "pcorrect");
//    acquire1D_class.def((complex (acquire1D::*)(double&, double, int)) &acquire1D::pcorrect,   "pcorrect");

    acquire1D_class.def(&acquire1D::ls,          "ls");
    acquire1D_class.def(&acquire1D::size,        "size");
    acquire1D_class.def(&acquire1D::full_size,   "ls");
    acquire1D_class.def(&acquire1D::transitions, "ls");
*/

// ----------------------------------------------------------------------------
//                                   Euler Angles
// ----------------------------------------------------------------------------

//                                  The Class

//    boost::python::class_builder<acquire1D> EAngles_class(PyModule, "EAngles");
	   	
//                                 Constructors

    EAngles_class.def(boost::python::constructor<>());
//    EAngles_class.def(boost::python::constructor<double, double, double, bool>());
   // EAngles_class.def(boost::python::constructor<const coord&, bool>());

//                                Member Functions

/*
    EAngles_class.def((double (EAngles::*)() const) &EAngles::alpha, "alpha");
    EAngles_class.def((double (EAngles::*)() const) &EAngles::beta,  "beta");
    EAngles_class.def((double (EAngles::*)() const) &EAngles::gamma, "gamma");
    EAngles_class.def((void   (EAngles::*)(double)) &EAngles::alpha, "alpha");
    EAngles_class.def((void   (EAngles::*)(double)) &EAngles::beta,  "beta");
    EAngles_class.def((void   (EAngles::*)(double)) &EAngles::gamma, "gamma");
*/

//    EAngles_class.def(&EAngles::equal,   "equal");
//    EAngles_class.def(&EAngles::inverse, "inverse");
//    EAngles_class.def(&EAngles::RMx,     "RMx");

//                              Global Functions

//                           Python Specialty Functions

// ----------------------------------------------------------------------------
//                                 Quaternions
// ----------------------------------------------------------------------------

//                                  The Class

//    boost::python::class_builder<acquire1D> Quatern_class(PyModule, "quatern");
	   	
//                                 Constructors

//    Quatern_class.def(boost::python::constructor<>());
//    Quatern_class.def(boost::python::constructor<const coord&,   bool>());
//    Quatern_class.def(boost::python::constructor<const EAngles&, bool>());
//    Quatern_class.def(boost::python::constructor<const ParameterSet&, int, int>());
//    Quatern_class.def(boost::python::constructor<double, double, double, double, bool>());

//                                Member Functions

//    Quatern_class.def(&quatern::A,       "A");
//    Quatern_class.def(&quatern::B,       "B");
//    Quatern_class.def(&quatern::C,       "C");
//    Quatern_class.def(&quatern::D,       "D");

//    Quatern_class.def(&quatern::alpha,   "alpha");
//    Quatern_class.def(&quatern::beta,    "beta");
//    Quatern_class.def(&quatern::gamma,   "gamma");

//    Quatern_class.def(&quatern::EA,      "EA");
//    Quatern_class.def(&quatern::ABG,     "ABG");

//    Quatern_class.def(&quatern::norm,    "norm");
//    Quatern_class.def(&quatern::inverse, "inverse");

//    Quatern_class.def((SinglePar (quatern::*)()                                       const) &quatern::param,  "param");
//    Quatern_class.def((SinglePar (quatern::*)(const std::string&)                     const) &quatern::param,  "param");
//    Quatern_class.def((SinglePar (quatern::*)(const std::string&, const std::string&) const) &quatern::param,  "param");


//                                Global Functions

//    PyModule.def((quatern (*)(const EAngles&, const EAngles&)) &composite, "composite");
//    PyModule.def((quatern (*)(const coord&,   const coord&))   &composite, "composite");
//    PyModule.def((quatern (*)(const quatern&, const quatern&)) &composite, "composite");
//    PyModule.def((quatern (*)(const matrix&,  const quatern&)) &composite, "composite");

//                           Python Specialty Functions

// ----------------------------------------------------------------------------
//                                Mutual Exchange
// ----------------------------------------------------------------------------

//                                Global Functions

//    PyModule.def((matrix   (*)(const spin_sys&,    const ExchProcM&)) &Kex, "Kex");
//    PyModule.def((super_op (*)(const spin_sys&,    const std::vector<ExchProcM>&, const basis& )) &Kex, "Kex");
//    PyModule.def((super_op (*)(const sys_dynamic&, const basis&))     &Kex, "Kex");

//                           Python Specialty Functions


#endif					// End of PyESRLib.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

