/* MatLabFile.h *************************************************-*-c++-*-
**									**
**	                            G A M M A			 	**
**								 	**
**	MATLAB File 				Interface		**
**								 	**
**	Copyright (c) 1990					 	**
**	Scott Smith 	          				 	**
**      1800 E. Paul Dirac Drive                                        **
**      National High Magnetic Field Laboratory                         **
**      Tallahassee FL 32306 USA                                        **
**						 			**
**      $Header: $
**								 	**
*************************************************************************/

/*************************************************************************
**							 		**
**  Description							 	**
**								 	**
** The MatLabFile class facilitates reading and writing of MATLAB MAT	**
** binary files. MATLAB is a commercial	product and can be purchased 	**
** from The MathWorks, Inc.						**
**							 		**
*************************************************************************/

#ifndef   GMLFILE_h_				// Is file already included?
#  define GMLFILE_h_ 1				// If no, then remember it
#  if defined(GAMPRAGMA)			// Using the GNU compiler?
#    pragma interface				// This is the interface 
#  endif

#include <GamGen.h>				// Know MSVCDLL (__declspec)
#include <fstream>				// File streams from libstdc++ 
#include <string>				// Strings from libstdc++ 
#include <GamIO/ML5Hdr.h>			// Include MAT V5 main headers
#include <Matrix/matrix.h>			// Knowledge of matrices
#include <Level1/coord_vec.h>			// Knowledge of coord. vectors

class MatLabFile
    
// ----------------------------------------------------------------------------
// ------------------------------- STRUCTURE ----------------------------------
// ----------------------------------------------------------------------------

  {
  std::fstream    fp;		// Input/Output file stream
  std::string     fname;	// Filename associated with MatLabFile
  int        fsize;		// Size of the file (in bytes)
  MatLab5Hdr ML5Hdr;		// MatLab MAT Version 5 main header	
  int        MATVerOut;		// MatLab MAT Version (for output)
  int	     wxr;		// Flag for write/nothing/read (-1,0,1);

// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// i                         MatLab File Error Handling
// ____________________________________________________________________________

/*              Input           MLF     : MatLab MAT file
                                eidx    : Error index
                                pname   : string in message
                                noret   : Flag for return (0=linefeed)
           Output               none    : Error message output
                                          Execution stopped (if fatal)       */  
 
void MatLabFile::MLFerror(int eidx, int noret=0) const;
void MatLabFile::MLFerror(int eidx, const std::string& pname, int noret=0) const;
volatile void MatLabFile::MLFfatality(int eidx) const;
volatile void MatLabFile::MLFfatality(int eidx, const std::string& pname) const;
 
// ----------------------------------------------------------------------------
// ii                       Mode Checking Functions
// ----------------------------------------------------------------------------

/* These functions check the mode specified when opening a MATLAB MAT file.
   We do not allow all of the possible modes availble to C++ filestreams.  In
   particular, we do not allow users to append to an existing file (since this
   would be bad if the existing data was written with a different byte order).
   Additonally, there seems to be some discrepancy between compilers as to
   what modes are available to fstream, so we just stick to the basics.      */  
 
 
void MatLabFile::CheckMode(int mode); 
 

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

public:
 
// ____________________________________________________________________________
// A                   MatLab File Constructors, Destructor
// ____________________________________________________________________________

MSVCDLC MatLabFile::MatLabFile();
MSVCDLC MatLabFile::MatLabFile(const std::string& name, int mode = std::ios::binary|std::ios::in);
MSVCDLC MatLabFile::MatLabFile(const MatLabFile& MLF);

        // Input                MLF     : MATLAB MAT file
        //                      name    : External filename
        //                      mode    : I/O mode
        //                                 app    = append
        //                                 ate    = open & seek end (at end)
        //                                 binary = I/O in binary
        //                                 in     = open for reading
        //                                 out    = open for writing
        //                                 trunc  = truncate file at 0 length
 
MSVCDLC MatLabFile::~MatLabFile();
MSVCDLL MatLabFile& MatLabFile::operator=(const MatLabFile& MLF);

MSVCDLL void MatLabFile::close();
MSVCDLL void MatLabFile::open(int mode = std::ios::binary|std::ios::in);


// ____________________________________________________________________________
// B                        MatLab File Access Functions
// ____________________________________________________________________________

/* These functions allow users to access MAT file versions.  GAMMA currently
   only knows of two versions, 4 & 5.  Users may get/set the output version
   to either 4 or 5.  The output version is returned by the function overload
   taking no arguments.  The disk file version is returned by the overload
   that takes a file stream.  The disk file version cannot be changed.       */
 
MSVCDLL        int  MatLabFile::Version() const;
MSVCDLL        int  MatLabFile::Version(std::fstream& fp);
MSVCDLL static int  MatLabFile::Version(const std::string& filename);
MSVCDLL        void MatLabFile::Version(int V);

// ____________________________________________________________________________
// C                   MatLab File Auxiliary Functions
// ____________________________________________________________________________
 
MSVCDLL static void MatLabFile::whos(const std::string& filename, std::ostream& ostr);
MSVCDLL        void MatLabFile::whos(std::ostream& ostr);
MSVCDLL static void MatLabFile::details(const std::string& filename, std::ostream& ostr);
MSVCDLL        void MatLabFile::details(std::ostream& ostr);
MSVCDLL static void MatLabFile::Header(const std::string& filename, std::ostream& ostr);

// ____________________________________________________________________________
// D                  MatLab File (Binary) Read Functions
// ____________________________________________________________________________
         
/* These functions will access a MATLAB file and read one of its array data
   elements into a GAMMA array. Since MATLAB arrays are not distinguished
   from matrices, the read always produces matrices as well.  Users must do
   a type cast to produce the data in a row or column vector.                */

MSVCDLL friend matrix MATLAB(const std::string& filename, const std::string& name, int warn=2);
MSVCDLL matrix MatLabFile::GetMatrix(const std::string& name, int warn=1);

// ____________________________________________________________________________
// E                 MatLab File (Binary) Write Functions
// ____________________________________________________________________________

/* These functions will access/create a MATLAB file and write a data element    
   from a GAMMA array.                                                       */  
 
MSVCDLL friend int MATLAB(const std::string& file, const std::string& N,
                                       const matrix& mx, int rc=1, int warn=2);
MSVCDLL int MatLabFile::write(const std::string& N, const matrix& mx, int rc=1, int warn=2);
MSVCDLL friend int MATLAB(const std::string& file, const std::string& N,
                                       const coord_vec& cvec, int warn=2);
MSVCDLL int MatLabFile::write(const std::string& N, const coord_vec& cvec, int warn=2);

// ____________________________________________________________________________
// F                  MatLab File (ASCII) Print Functions
// ____________________________________________________________________________

/* 	   Input                MLF     : MAT version 5 file (this)
                                ostr    : An output stream 
				full	: Flag for full output
           Output               ostr    : Output stream with MATLAB MAT file 
                                          base info placed into it           */
 
MSVCDLL static void MatLabFile::print(const std::string& filename,std::ostream& ostr,int full=0);
MSVCDLL void   MatLabFile::print(std::ostream& ostr, int full=0);
MSVCDLL friend std::ostream& operator<< (std::ostream& ostr, MatLabFile& MLF);

// ____________________________________________________________________________
// G              MatLab File (ASCII) Auxiliary Print Functions
// ____________________________________________________________________________
 
/* These functions are just used for testing purposes.  The mirror the binary   
   write functions, but instead of writing in binary to a filestream the write
   in ASCII to an output stream.  Thus it is easy to see most of what is
   being written, at least in principle.....                                 */
 
MSVCDLL void MatLabFile::print(std::ostream& ostr, 
                        const matrix& mx, const std::string& N, int cmplx=1) const;

// ____________________________________________________________________________
//                                  PyGAMMA Code
// ____________________________________________________________________________

#ifdef PYGAMMA					// Begin PyGAMMA code block

std::string Print();
std::string whos_MATLABFILE_py1(const std::string& filename);
std::string details_MATLABFILE_py1(const std::string& filename);
std::string Header_MATLABFILE_py1(const std::string& filename);

#endif						// End of PyGAMMA code block

};							// MatLabFile.h

#endif

