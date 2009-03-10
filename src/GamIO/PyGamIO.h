/* PyGamIO.h ****************************************************-*-c++-*-
**									**
**                              G A M M A				**
**									**
**      PyGAMMA Input/Output		             Interface		**
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
** The PyGAMMA interface contains all of the needed definitions as to	**
** what should be/will be exported into Python from the sources. This	**
** is that file.							**
**									**
*************************************************************************/

#ifdef PYGAMMA				// If we are compiling PyGAMMA
					// we will include this stuff
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

#ifndef _PyGamIO_h_			// Is this file already included?
#define _PyGamIO_h_ 1			// If no, then remember it

// ____________________________________________________________________________
// ____________________________________________________________________________
// G                     GAMMA Input/Output Module Exports
// ____________________________________________________________________________
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                                Python Vectors
// ----------------------------------------------------------------------------

// Many of the functions in the GAMMA I/O module make use of STL vectors, which
// cannot be directly exported into Python. Two in particular, vector<string>
// and vector<row_vector> are utilized. There is no way we can tell Python that
// something like vector<row_vector> is a valid class type. So, what we must do
// instead is to give such data types alternative names, e.g. Vrow_vector, and
// then define the "class" accordingly. We must also define all of functions we
// will need for the class. For example, Vrow_vector.push_back(row_vector).

    boost::python::class_builder<std::vector<std::string> > Vstring(PyModule, "Vstring");
    Vstring.def(boost::python::constructor<>());
    Vstring.def(Vstring_push_back, "push_back");

    boost::python::class_builder<std::vector<row_vector> > Vrow_vector(PyModule, "Vrow_vector");
    Vrow_vector.def(boost::python::constructor<>());
    Vrow_vector.def(Vrowvec_push_back, "push_back");

// ----------------------------------------------------------------------------
//                                     Gnuplot
// ----------------------------------------------------------------------------

// boost::python::class_builder<GPdat> GPdat_class(PyModule, "GPdat");

//                             Global Functions

//PyModule.def((std::vector<std::string> (*)())      &GPSeekStrings, "GPSeekStrings");
//PyModule.def((std::string (*)(bool))               &GPFind,        "GPFind");
PyModule.def((std::string (*)(int))                &GPExec,        "GPExec");
PyModule.def((void        (*)(const std::string&)) &RunGnuplot,    "RunGnuplot");


PyModule.def((void (*)(const std::string&, const row_vector&,  int, double, double, double))&GP_1D, "GP_1D");
PyModule.def((void (*)(const std::string&, const std::string&, int))                        &GP_1Dplot, "GP_1Dplot");

// PyModule.def((void (*)(GPdat&))                                                          &GP_1Dplot, "GP_1Dplot");
// PyModule.def((void (*)(const std::string&, const std::string&, const std::string&, int)) &GP_1Dplot, "GP_1Dplot");
// PyModule.def((void (*)(const std::string&, const std::string&, const std::string&, const std::string&, int))&GP_1Dplot, "GP_1Dplot");

// PyModule.def((void (*)(const std::string&, const row_vector&, GPdat&))&GP_1D, "GP_1D");
		
// can't do arrays or std::vectors for GP_1Dm


/*
void GP_1D(const std::string& filename, const row_vector &vx,
                      int ri=0, double xmin=0, double xmax=0, double cutoff=0);
void GP_1D(const std::string& filename, const row_vector& vx, GPdat& G);
void GP_1D(std::ofstream& ofstr, const row_vector& vx,
                      int ri=0, double xmin=0, double xmax=0, double cutoff=0);
void GP_1D(std::ofstream& ofstr, const row_vector& vx, GPdat& G);

void GP_1Dm(const std::string& filename, row_vector* vxs, int N,
                     int ri=0, double xmin=0, double xmax=0, double cutoff=0);
void GP_1Dm(const std::string& filename, const std::vector<row_vector>& vxs,
                     int ri=0, double xmin=0, double xmax=0, double cutoff=0);
void GP_1Dm(const std::vector<std::string>& fnames, const std::vector<row_vector>& vxs,
                     int ri=0, double xmin=0, double xmax=0, double cutoff=0);
		
void Gnuplot1D(const std::string& name, const row_vector &vx,
          int ri=0, double xmin=0, double xmax=0, int join=1, double cutoff=0);

void Gnuplot1D(const std::string& name, const std::vector<row_vector>& vxs,
                     int ri=0, double xmin=0, double xmax=0,
                             bool samefile=false, int join=1, double cutoff=0);

void Gnuplot1D(const std::vector<std::string>& names, const std::vector<row_vector>& vxs,
                     int ri=0, double xmin=0, double xmax=0,
                             bool samefile=false, int join=1, double cutoff=0);
*/

    PyModule.def((void (*)(const std::string&, const row_vector&))                            &GP_xy,      "GP_xy");
    PyModule.def((void (*)(const std::string&, matrix&, int, double, double, double, double)) &GP_contour, "GP_contour");
    PyModule.def((void (*)(const std::string&, matrix&, int, double, double, double, double)) &GP_stack,   "GP_stack");	
// PyModule.def(GP_sphere, "GP_sphere");

//			Python Specialty Functions


    PyModule.def((void (*)(const std::string&, const row_vector&)) &GP_1DGP1, "GP_1D");
    PyModule.def((void (*)(const std::string&, const row_vector&)) &GP_1DGP2, "GP_1D");

    PyModule.def((void (*)(const std::string&, const row_vector&))                               &Gnuplot1DGP1, "Gnuplot1D");
    PyModule.def((void (*)(const std::string&, const row_vector&, int))                          &Gnuplot1DGP2, "Gnuplot1D");
    PyModule.def((void (*)(const std::string&, const row_vector&, int, double , double))         &Gnuplot1DGP3, "Gnuplot1D");
//    PyModule.def((void (*)(const std::string&, const std::vector<row_vector>& vxs))              &Gnuplot1DGP3, "Gnuplot1D");
//    PyModule.def((void (*)(const std::vector<std::string>&, const std::vector<row_vector>& vxs)) &Gnuplot1DGP4, "Gnuplot1D");

// ----------------------------------------------------------------------------
//                              MatLab File Class
// ----------------------------------------------------------------------------

//                                  The Class

   boost::python::class_builder<MatLabFile> MatLabFile_class(PyModule, "MatLabFile");

//                                 Constructors

MatLabFile_class.def(boost::python::constructor<>());
MatLabFile_class.def(boost::python::constructor<const std::string&, int>());

//                               Member Functions


MatLabFile_class.def((int (MatLabFile::*)() const) &MatLabFile::Version, "Version");
MatLabFile_class.def((int (*)(const std::string&)) &MatLabFile::Version, "Version"); // figure out about static
MatLabFile_class.def((void (MatLabFile::*)(int))   &MatLabFile::Version, "Version");
		
//                               Global Functions

PyModule.def((matrix (*)(const std::string&, const std::string&, int))                     &MATLAB, "MATLAB"); // causes warning
PyModule.def((int    (*)(const std::string&, const std::string&, const matrix&, int, int)) &MATLAB, "MATLAB");
PyModule.def((int    (*)(const std::string&, const std::string&, const coord_vec&, int))   &MATLAB, "MATLAB"); 

//			Python Specialty Functions

MatLabFile_class.def(&MatLabFile::Print, "__str__");

// ----------------------------------------------------------------------------
//                                 FrameMaker
// ----------------------------------------------------------------------------

// boost::python::class_builder<FMPar> FMPar_class(PyModule, "FMPar");
// boost::python::class_builder<FMcont> FMcont_class(PyModule, "FMcont");
boost::python::class_builder<FMclev> FMclev_class(PyModule, "FMclev");
// boost::python::class_builder<FMxy> FMxy_class(PyModule, "FMxy");

PyModule.def((void (*)(const std::string&, const row_vector&, double, double, double, double, int))&FM_1D, "FM_1D");
// PyModule.def((void (*)(const std::string&, const row_vector&, FMPar&))FM_1D, "FM_1D");
PyModule.def((void (*)(const std::string&, row_vector&, double, double, double, double, double, double))&FM_xyPlot, "FM_xyPlot");
// PyModule.def((void (*)(const std::string&, row_vector&, FMxy&))&FM_xyPlot, "FM_xyPlot");
//		PyModule.def((void (*)(const std::string&, row_vector&, char, double, double))&FM_scatter, "FM_scatter");	// Will not work on Pygamma1
//		PyModule.def((void (*)(const std::string&, row_vector&, char, FMxy&))&FM_scatter, "FM_scatter");			// Will not work on Pygamma1
PyModule.def((void (*)(const std::string&, row_vector&, int, double, double))&FM_histogram, "FM_histogram");
PyModule.def((void (*)(const std::string&, const matrix&, double, int, double, double, int, double, double))&FM_contour, "FM_contour");
// PyModule.def((void (*)(const std::string&, const matrix&, FMcont&))&FM_contour, "FM_contour");
PyModule.def((void (*)(const std::string&, int, double, double, double, double, int))&FM_sphere, "FM_sphere");
//		PyModule.def((void (*)(const std::string&, coord_vec&, int, double, double, double, double, int))&FM_sphere, "FM_sphere");
PyModule.def((void (*)(const std::string&, coord_vec&, coord_vec&, int, double, double, double, double, int))&FM_sphere, "FM_sphere");
PyModule.def((void (*)(const std::string&, const matrix&, double, double, int, double, double, int, int))&FM_stack, "FM_stack");
// do we need more stack plots?
// PyModule.def((void (*)(const std::string&, const gen_op&, int, double))&FM_Matrix, "FM_Matrix"); // doesn't exist!
// PyModule.def((void (*)(const std::string&, const super_op&, int, double))&FM_Matrix, "FM_Matrix"); // doesn't exist!
PyModule.def((void (*)(const std::string&, const matrix&, int, double))&FM_Matrix, "FM_Matrix");
// PyModule.def((void (*)(const std::string&, const gen_op&, double))&FM_Mat_Plot, "FM_Mat_Plot"); // doesn't exist!
// PyModule.def((void (*)(const std::string&, const super_op&, double))&FM_Mat_Plot, "FM_Mat_Plot"); // doesn't exist!
// PyModule.def((void (*)(const std::string&, const gen_op&, const gen_op&, double))&FM_Mat_Plot, "FM_Mat_Plot"); // doesn't exist!
// PyModule.def((void (*)(const std::string&, const super_op&, const super_op&, double))&FM_Mat_Plot, "FM_Mat_Plot"); // doesn't exist!
PyModule.def((void (*)(const std::string&, const matrix&, double))&FM_Mat_Plot, "FM_Mat_Plot");
PyModule.def((void (*)(const std::string&, const matrix&, const matrix&, double))&FM_Mat_Plot, "FM_Mat_Plot");


#endif					// End of PyPyModule.h

#endif					// End PyGAMMA include. Note that
					// we will include file contests only
					// when building PyGAMMA (PYGAMMA=1)
					// BUT INCLUDE NOTHING UNLESS
					// PYGAMMA DEFINED (build PyGAMMA)

