/* row_vector.h *************************************************-*-c++-*-
**                                                                      **
**                                G A M M A                             **
**                                                                      **
**      Row Vectors                                 Interface           **
**                                                                      **
**      Copyright (c) 1990, 2002                                        **
**      Tilo Levante & Scott A. Smith                                   **
**      Eidgenoessische Technische Hochschule                           **
**      Labor fuer physikalische Chemie                                 **
**      8092 Zuerich / Switzerland                                      **
**                                                                      **
**      $Header: $
**                                                                      **
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
**  Description                                                         **
**                                                                      **
**  Class row_vector defines row vectors for C++ with the usual         **
**  algebraic operations, higher functions and I/O routines.            **
**                                                                      **
*************************************************************************/

#ifndef   Grow_vector_h_		// Is this file included?
#  define Grow_vector_h_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the interface
#  endif

#include <GamGen.h>			// Include system specifics
#include <iostream>			// Include libstdc++ io streams
#include <Matrix/complex.h>		// Include GAMMA complex numbers
#include <Matrix/matrix.h>		// Include GAMMA matrices
#include <Matrix/col_vector.h>		// Include GAMMA column vectors
#include <vector>			// Include libstdc++ STL vectors

class col_vector;
class row_vector : public matrix
   {
   friend class col_vector;


private:

// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// i                     CLASS ROW VECTOR ERROR HANDLING
// ____________________________________________________________________________


/*      Input                   rvec    : A row_vector (this)
                                eidx    : Error index
                                noret   : Flag for linefeed (0=linefeed)
                                pname   : string in message
        Output                  none    : Error message output
                                          Program execution stopped if fatal */

void row_vector::RVerror(int eidx, int noret=0) const;
void row_vector::RVerror(int eidx, const std::string& pname, int noret=0) const;
volatile void row_vector::RVfatality(int eidx) const;
volatile void row_vector::RVfatality(int eidx, const std::string& pname) const;

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

public:


// ____________________________________________________________________________
// A                  ROW VECTOR CONSTRUCTION, DESTRUCTION
// ____________________________________________________________________________

///F_list row_vector            - Constructor
///F_list ~                     - Destructor

/*    Arguments                         Constructed Row Vector
    -------------       -------------------------------------------------------
          -             An empty row vector (size = 0)
          nc            A row vector with nc elements (columns) uninitialized
        nc, z           A row vector with nc elements (columns) all set to z
          rv            A row vector equivalent to the input vector rv
          mx            A row vector equivalent to input matrix mx
                        (in this case mx MUST be of dimension 1xn)           */

MSVCDLC row_vector::row_vector( );
MSVCDLC row_vector::row_vector(int i);
MSVCDLC row_vector::row_vector(int i, const complex& z);
MSVCDLC row_vector::row_vector(int i, double d);
MSVCDLC row_vector::row_vector(const row_vector& rvec);
MSVCDLC row_vector::row_vector(const matrix& mx);
MSVCDLC row_vector::~row_vector();

// ____________________________________________________________________________
// B                     ROW VECTOR ACCESS AND ASSIGNMENT
// ____________________________________________________________________________

/*  Function/Operator                         Result
    -----------------   ------------------------------------------------------
          =             Current row vector set equal to input rvec
        (int)           Reference to element <rvec|i>
       get(int)         Copy of element <rvec|i>
      getRe(int)        Copy of real part of element <rvec|i>
      getIm(int)        Copy of imaginary part of element <rvec|i>
       put(int)         Assigns element <rvec|i>                            */

MSVCDLL void     row_vector::operator = (const row_vector& rvec);
MSVCDLL void     row_vector::operator = (const col_vector& cvec);
MSVCDLL void     row_vector::operator = (const matrix& mx);
MSVCDLL complex& row_vector::operator() (int i);
MSVCDLL complex  row_vector::get(int i)   const;
MSVCDLL double   row_vector::getRe(int i) const;
MSVCDLL double   row_vector::getIm(int i) const;
MSVCDLL void     row_vector::put(const complex& z, int i);

// ____________________________________________________________________________
// E             CLASS ROW VECTOR VARIOUS CHECKS & PARAMETERS
// ____________________________________________________________________________

/*  Function  Output                       Description
    --------  ------  ---------------------------------------------------------
    elements   int    Returns # of vector columns
      size     int    Returns # of vector columns
      rows     int    Returns # of vector rows       - handled by matrix
      cols     int    Returns # of vector columns    - handled by matrix
      refs     int    Returns # of vector references - handled by matrix
      pts      int    Returns # of vector elements   - handled by matrix     */

MSVCDLL int row_vector::elements( ) const;
MSVCDLL int row_vector::size( )     const;
/*
int matrix::rows();		     // Number of matrix rows       INHERITED
int matrix::cols();		     // Number of matrix columns    INHERITED
int matrix::refs();		     // Number of matrix references INHERITED
int matrix::pts();		     // Number of matrix points     INHERITED
*/

// ____________________________________________________________________________
// F                  ROW VECTOR BINARY ARITHMETIC FUNCTIONS
// ____________________________________________________________________________

// Note: The operators which must be defined here, as opposed to those
//       inherited from class matrix, are they which return row_vector.
//       (or at least, return a type other than what class matrix does)
//       Definition  herein also allows for more explicit error messages

// Note: 1.) rvec +/- cvec is not defined, only works when (1x1) +/- (1x1) so
//                         return is left as 1x1 matrix, error matrix error
//

/*

   Operator Arguments      Result        Operator Arguments       Result
   -------- --------- -----------------  -------- --------- -------------------
      +      rv1,rv2      rv1+rv2           *       mx,z           z*mx
      +      rv,mx        rv+mx             *       mx,z           z*mx
      -      rv1,rv2      rv1-rv2           *       z,mx           z*mx
      -      rv,mx        rv-mx             *       z,mx           z*mx
      *      rv1,rv2      rv1*rv2           *       mx,d           d*mx
      *      rv,cv        rv*cv == z        *       mx,d           d*mx
      /      mx1,mx2      mx1*inv(mx2)      *       d,mx           d*mx
      /      mx,z         (1/z)*mx          *       mx,d         (1/d)*mx
      /      z,mx         z*inv(mx)         *       d,mx         d*inv(mx)  */
/*      -     rv1,rv2 Returns rv1-rv2                      */
//		            z = <rvec|cvec>

        // Output              rvec1 : A row vector from the product mx*rvec
	// Note		 	     : The dimensions must match here

        //                                 rvec1  =  rvec  *  mx
        //                                (1 x n)   (1 x m) (m x n)
	//				        rvec1 = (1/z) * rvec

MSVCDLL friend row_vector operator * (const complex& z, const row_vector& rvec);
MSVCDLL friend row_vector operator * (double         d, const row_vector& rvec);

MSVCDLL row_vector row_vector::operator + (const row_vector& rvec) const;
MSVCDLL row_vector row_vector::operator + (const matrix&     mx)   const;
MSVCDLL row_vector row_vector::operator - (const row_vector& rvec) const;
MSVCDLL row_vector row_vector::operator - (const matrix&     mx)   const;
MSVCDLL complex    row_vector::operator * (const row_vector& rvec) const;
MSVCDLL complex    row_vector::operator * (const col_vector& cvec) const;
MSVCDLL row_vector row_vector::operator * (const matrix& mx)       const;
MSVCDLL row_vector row_vector::operator * (const complex& z)       const;
MSVCDLL row_vector row_vector::operator * (double d)               const;
MSVCDLL row_vector row_vector::operator / (const complex& z)       const;
MSVCDLL row_vector row_vector::operator / (double d)               const;

// ____________________________________________________________________________
// G                  ROW VECTOR UNARY ARITHMETIC FUNCTIONS
// ____________________________________________________________________________

// Note: These operators, as they are unable to change the type of the
//       result, can only be those which return row_vector.

MSVCDLL void row_vector::operator += (const row_vector& rvec1);
MSVCDLL void row_vector::operator += (const matrix& mx);
MSVCDLL void row_vector::operator -= (const row_vector& rvec1);
MSVCDLL void row_vector::operator -= (const matrix& mx);
MSVCDLL void row_vector::operator *= (      double d);
MSVCDLL void row_vector::operator *= (const complex& z);
MSVCDLL void row_vector::operator /= (      double d);
MSVCDLL void row_vector::operator /= (const complex& z);

// ____________________________________________________________________________
// J               ROW VECTOR SIMPLE UNARY FUNCTIONS
// ____________________________________________________________________________

// Note: The negation operator must be defined herein.  The function conjugate
//       is inherited, but adjoint and transpose return col_vectors so they
//       are also here.  Transpose is included just for specific error message.

/*  Function  Output                       Description
    --------  ------  ---------------------------------------------------------
      -       rvec    Returns the vector mutiplied by -1 (negation) -|rvec >
    adjoint   cvec    Returns col. vector where <i|cvec> = <rvec|i>*
   transpose  cvec    Returns col. vector where <i|cvec> = <rvec|i>
     trace    ----    This is disallowed for row vectors (but MUST exist)    */

// row_vector row_vector::operator- () const;		// MATRIX INHERITED
//friend row_vector operator - (const row_vector& rvec);
MSVCDLL friend col_vector adjoint(const     row_vector& rvec);
MSVCDLL friend col_vector transpose(const   row_vector& rvec);
MSVCDLL friend complex    trace(const       row_vector& rvec);
MSVCDLL row_vector row_vector::differential() const;

// ____________________________________________________________________________
// I                    ROW VECTOR SIMPLE BINARY FUNCTIONS
// ____________________________________________________________________________

/*  Function  Output                       Description
    --------  ------  ---------------------------------------------------------
      norm    double  Returns the vector norm, sq.rt. of sum of squares
      sum     complex Returns the sum ov all vector elements
     maxRe    double  Returns largest real value in the vector
     maxIm    double  Returns largest imaginary value in the vector
     maxZ     complex Returns largest complex (biggest norm) value in vector
     minRe    double  Returns smallest real value in the vector
     minIm    double  Returns smallest imaginary value in the vector
     minZ     complex Returns smallest complex (biggest norm) value in vector
      max      int    Returns index of largest (  real, imag, norm } element
      min      int    Returns index of smallest { real, imag, norm } element
     flip     void    Inverses the element order in the vector
     zero     void    Sets all elements to zero
     sort     vector  Returns vector<int> array of sorted indices

  The vector norm is given by

                     [ size-1          ]
                     |  ---            |
                     |  \            2 |            2                *
          Norm = sqrt|  /  |<rvec|i>|  |, |<rvec|i>| = <rvec|i>*<rvec |i>
                     |  ---            |
                     [  i=0            ]

  & the following definitions apply to the max, min and sort functions:

                          type         max/min
                            0       norm (default)
                           <0         imaginary
                           >0           real                                 */

MSVCDLL double           row_vector::norm()              const;
MSVCDLL complex          row_vector::sum()               const;
MSVCDLL double           row_vector::maxRe()             const;
MSVCDLL double           row_vector::maxIm()             const;
MSVCDLL complex          row_vector::maxZ()              const;
MSVCDLL double           row_vector::minRe()             const;
MSVCDLL double           row_vector::minIm()             const;
MSVCDLL complex          row_vector::minZ()              const;
MSVCDLL int              row_vector::max(int type=0)     const;
MSVCDLL int              row_vector::min(int type=0)     const;
MSVCDLL void             row_vector::flip();
MSVCDLL complex          row_vector::sum(int st, int ne) const;
MSVCDLL void             row_vector::zero();
MSVCDLL std::vector<int> row_vector::sort(int type=0)    const;

// ____________________________________________________________________________
// J                    ROW VECTOR COMPLEX UNARY FUNCTIONS
// ____________________________________________________________________________

// ******************************      FFT      *******************************

        // Input        rvec : A row vector
        // Output      rvec1 : A row vector containing the discrete Fourier
        //                     (inverse) transform of the values in rvec
        // Note              : The matrix rvec should be of dimension
        //                     1 x (2^n)

MSVCDLL friend row_vector FFT(const  row_vector& rvec);
MSVCDLL friend row_vector IFFT(const row_vector& rvec);

// ____________________________________________________________________________
// K                  ROW VECTOR COMPLEX BINARY FUNCTIONS
// ____________________________________________________________________________

//*************************** comparisons *******************************

        // Input      rvec1  : A row vector
        //            rvec2  : A row vector
        // Output ==    T/F  : Returns TRUE if rvec1 is equal to rvec2.
        // Output !=    T/F  : Returns TRUE if rvec1 is NOT equal to rvec2.

MSVCDLL friend int operator==(const row_vector& rvec1, const row_vector& rvec2);
MSVCDLL friend int operator!=(const row_vector& rvec1, const row_vector& rvec2);

//*************************** straight product ********************************

MSVCDLL friend row_vector product(const row_vector& rvec1, const row_vector& rvec2);
MSVCDLL friend row_vector product(const row_vector& rvec,        col_vector& cvec);

MSVCDLL row_vector row_vector::product()                        const;
MSVCDLL row_vector row_vector::product(const row_vector& cvec2) const;
MSVCDLL row_vector row_vector::product(const col_vector& rvec)  const;

        // Input              rvec1  : A row vector
        //               rvec2,cvec  : Second row vector, or column vector
        // Output             rvec3  : A "product" of two vectors
        // Note                      : This is NOT a scalar product

        //                             rvec3(i) = rvec1(i) * rvec1(i)
        //                                      = rvec1(i) * rvec2(i)
        //                                      = rvec(i) * cvec(i)

//**************************** scalar product *********************************

MSVCDLL friend double  scalar_product(const row_vector& rvec);
MSVCDLL friend complex scalar_product(const row_vector& rvec1, const row_vector& rvec2);
MSVCDLL friend complex scalar_product(const row_vector& rvec,  const col_vector& cvec);

MSVCDLL double  row_vector::scalar_product()                        const;
MSVCDLL complex row_vector::scalar_product(const row_vector& cvec2) const;
MSVCDLL complex row_vector::scalar_product(const col_vector& rvec)  const;

        // Input              rvec1  : A row vector
        //               rvec2,cvec  : Second row vector, or column vector
        // Output             z      : Scalar product of rvec & adjoint(rvec)

        //                             z = <rvec|rvec'>,   |rvec'> = adjoint(<rvec|)
        //                               = <rvec1|rvec2'>, |rvec2'> = adjoint(<rvec|)
        //                               = <rvec|cvec>

// ____________________________________________________________________________
// L                      ROW VECTOR I/O FUNCTIONS
// ____________________________________________________________________________

// --------------------- ASCII Input/Output Functions -------------------------

/*              Input           rvec    : A row vector (this)
                                ostr    : Output ASCII file stream
                                full    : Flag for amount of output
                Return          void    : rvec is sent to the output stream  */

MSVCDLL std::string              row_vector::hdrString() const;
MSVCDLL std::vector<std::string> row_vector::printStrings(const MxPrint& PFlgs) const;

MSVCDLL        std::ostream& row_vector::printcols(std::ostream& ost, int nc=4,int rc=1,int ne=0) const;
MSVCDLL        std::ostream& row_vector::print(std::ostream& ostr, int full=0) const;
MSVCDLL friend std::ostream& operator << (std::ostream& ostr, const row_vector& rvec);
MSVCDLL friend std::istream& operator >> (std::istream& istr, row_vector& rvec);

        // Input                rvec : Row vector (this)
        // Output               void : The function sends questions to
        //                             standard output interactively asking
        //                             the user to supply the information to
        //                             specify the vector.  rvec is modified.
        // Note                      : Function is for INTERACTIVE programs

MSVCDLL void row_vector::ask();

// _______________________________________________________________________
// M                       PyGAMMA Code (Member)
// _______________________________________________________________________

#ifdef PYGAMMA				// Begin PyGAMMA code block

//-----------------------------------------------------------------------------
//                            ASCII OUTPUT FUNCTIONS
//-----------------------------------------------------------------------------

std::string row_vector::PyPrint() const;

//-----------------------------------------------------------------------------
//                            ACCESS FUNCTIONS
//-----------------------------------------------------------------------------

/* These add to the put function for Python because there is no automatic
   cast from double complex as is done in C++.                               */

void row_vector::putRVEC(double d, int i);

//-----------------------------------------------------------------------------
//                            VARIOUS FUNCTIONS
//-----------------------------------------------------------------------------

/* I have not clue at the moment why these are exported in such a manner.    */

friend col_vector adjoint_ROW_VECTOR_py1(const     row_vector& rvec);
friend col_vector transpose_ROW_VECTOR_py1(const   row_vector& rvec);
friend complex    trace_ROW_VECTOR_py1(const       row_vector& rvec);
friend row_vector FFT_ROW_VECTOR_py1(const row_vector& rvec);
friend row_vector IFFT_ROW_VECTOR_py1(const row_vector& rvec);
friend double scalar_product_ROW_VECTOR_py1(const row_vector& rvec);
friend complex scalar_product_ROW_VECTOR_py2(const row_vector& rvec1, const row_vector& rvec2);
friend complex scalar_product_ROW_VECTOR_py3(const row_vector& rvec, const col_vector& cvec);
// matrix operator * (const matrix& mx);

#endif						// End of PyGAMMA code block

   };

// ____________________________________________________________________________
// N                         PyGAMMA Code (Non-Member)
// ____________________________________________________________________________

// Of all GAMMA's matrix classes, only the main matrix class, matrix.{cc,h} is
// exported into Python. All of the sub-classes are usually not used explicitly
// in programs anyway. Also, note that there is trouble with enumerations in
// Boost.Python so we use string intead for the time being until we can figure
// out how to get enum working.

#ifdef PYGAMMA					// Begin PyGAMMA code block

void PyRowVector();

#endif			

#endif							// row_vector.h
