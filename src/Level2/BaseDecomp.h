/* decomp.h *********************************************-*-c++-*-
**								**
**	                      G A M M A				**
**								**
**	Decomposition	                      Interface		**
**								**
**	Copyright (c) 1996					**
**	Scott Smith						**
**      National High Magnetic Field Laboratory                 **
**      1800 E. Paul Dirac Drive                                **
**      Tallahassee Florida, 32306-4005                         **
**								**
**      $Header: $
**								**
*****************************************************************/

/*****************************************************************
**								**
**  Description							**
**								**
**  Class decomp provides the means with which an operator can	**
**  be readily decomposed into a set of basis operators.  Each	**
**  variable of class decomp may contains a set of such basis	**
**  operators.  Functions are provided which will construct	**
**  the basis set and which will break down a provided operator	**
**  into the basis components.					**
**								**
*****************************************************************/

///Chadecer Class decomp
///Section Overview

#ifndef   decomp_h			// Is file already included?
#  define decomp_h 1			// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the interface
#  endif

# include <GamGen.h>			// Know MSVCDLL (__declspec)
# include <Matrix/row_vector.h>		// Include GAMMA vectors
# include <string>			// Include libstdc++ strings
# include <vector>			// Include libstdc++ STL vectors
# include <HSLib/GenOp.h>		// Include GAMMA operators
# include <HSLib/SpinSys.h>		// Include base spin systems

class decomp
{
    
// ----------------------------------------------------------------------------
// ------------------------------- STRUCTURE ----------------------------------
// ----------------------------------------------------------------------------

std::string         dname;		// Basis name	(e.g. Product Operator)
int		    _NS;		// Number of spins
int                 _LS;		// Liouville space
std::vector<gen_op> BaseOps;		// Base Ops           (e.g. 2*Ix1*Iz2)
std::vector<std::string> BaseNames;		// Base Op names      (e.g. 2Ix1Iy2)
std::vector<std::string> BaseAltNames;	// Base Op alternate names
std::vector<std::string> BaseCoeffNames;	// Base Op spin names (e.g. Ix1, Iz2)
std::vector<int>    BaseCoherences;	// Base Op coherence order
std::vector<int>    BaseSpins;		// Base Op spins
row_vector          BaseVals;		// Base operator intensities
std::vector<double> BaseCoefficients;	// Base operator coefficients
double              thresh;		// Output magnitude threshold
int                 prif;		// Print flag (real/imaginary)
  
private:


// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// I                 CLASS DECOMPOSITION ERROR HANDLING
// ____________________________________________________________________________

         void decomp::ODerror(int eidx, int noret=0) const;
volatile void decomp::ODfatal(int eidx)              const;

// ____________________________________________________________________________
// II                     SPECIFIC DECOMPOSITIONS
// ____________________________________________________________________________

std::vector<int> decomp::sub_indices(int ils, int ssdim, int nss);
void sub_indices(int indices[], int ils, int ssdim, int nss);

        // Input                indices : Basis indices per subspace
        //                      ils     : Full space index
        //                      ssdim   : Dimension of a single subspace
        //                      nss     : Number components in full space
        // Output               void    : Fills array "indices" with
        //                                sub-space indices corresponding
        //                                to the full space index ils


void spin3halves(const spin_sys& sys);

        // Input                sys     : Spin system
        // Output               void    : Fills dec with irreducible
        //                                spherical tensor components
        // Note                         : This pertains ONLY to a system
        //                                containing a single spin I=3/2


void decomp::product_operators(const spin_sys& sys);

        // Input                sys     : Spin system
        // Output               void    : Fills dec with product operator
        //                                components
        // Note                         : This pertains ONLY to a system
        //                                containing a all spin I=1/2
        //                                (so it's private & taken care of)

// ____________________________________________________________________________
// Y                              TEST FUNCTIONS
// ____________________________________________________________________________

        // Input                dec     : Decomposition (this)
        //                      i       : An index
        //                      fat     : Flag for fatal error
        // Output               TF      : True if index i is
        //                                in the Liouville space
        // Note                         : If fat is set non-zero,
        //                                then the routine will die
        //                                rather than return FALSE

bool decomp::ChkIndex(int  i, bool warn=true) const;
bool decomp::ChkSize(int  ls, bool warn=true) const;


// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

  public:

// ____________________________________________________________________________
// A             CLASS GENERAL DECOMPOSITION CONSTRUCTORS/DESTRUCTOR
// ____________________________________________________________________________

///Center Decomposition Algebraic
///F_list decomp		- Decomposition constructor
///F_list =			- Decomposition assignment
	
MSVCDLC      decomp::decomp( );
MSVCDLC      decomp::decomp(const decomp &dec1);
MSVCDLC      decomp::decomp(const spin_sys& sys);
MSVCDLC      decomp::~decomp ( );
MSVCDLL void decomp::operator= (const decomp &dec);

	// Input		dec    : Decomposition(this)
	// 			dec1   : Decomposition
	// Output		none  : dec set identical to dec1


// ____________________________________________________________________________
// B                      DECOMPOSITION FUNCTIONS
// ____________________________________________________________________________

///Center Decomposition Functions

MSVCDLL void decomp::decompose(const gen_op& Op);
 
        // Input                dec     : Decomposition (this)
        //                      Op      : Operator to decompose 
        // Output               void    : The operator is decomposed,
        //                                projected intensities are put
        //                                into the internal array 


// ____________________________________________________________________________
// C                            ACCESS FUNCTIONS
// ____________________________________________________________________________

// ---------------------------- Dimension Access ------------------------------
 
MSVCDLL int decomp::size() const;			// Base Liouville space
MSVCDLL int decomp::LS()   const;			// Base Liouville space
MSVCDLL int decomp::HS()   const;			// Base Hilbert   space

// ------------------------------- Name Access --------------------------------

        // Input                dec     : Decomposition (this)
        //                      m       : Coherence order
        // Output               void    : Names of the base operators
        //                                are return in a vector of strings
	//				  If m is set then only those of the
	//				  coherence order m are returned

        // Input                dec     : Decomposition (this)
        //                      i       : An index (default = -1)
        //                      name    : A decomposition name
        // Output               void    : The name of the base is
        //                                is set or returned
	//                                If i !=-1 then the returned name is
	//				  that of the base operator i
	//                                For function altname, the return
	//				  is alternative base operator name
 
MSVCDLL std::vector<std::string> decomp::Names()           const;
MSVCDLL std::vector<std::string> decomp::Names(int     m)  const;
MSVCDLL void                decomp::Name(const std::string& name);
MSVCDLL std::string              decomp::Name(          )  const;
MSVCDLL std::string              decomp::OpName(int    i)  const;
MSVCDLL std::string              decomp::AltOpName(int i)  const;
MSVCDLL int                 decomp::MaxOpNameLen()    const;
MSVCDLL int                 decomp::MaxOpAltNameLen() const;

// ---------------------------- Coherence Access ------------------------------

MSVCDLL int decomp::Coherence(int i) const;
MSVCDLL int decomp::MaxCoherence()   const;
 
// ----------------------------- Operator Access ------------------------------
 


        // Input                dec     : Decomposition (this)
        //                      Opname  : Name of a basis operator
        // Output               Op      : The base operator with
        //                                the name Opname


MSVCDLL gen_op decomp::Op(const std::string& Opname) const;
MSVCDLL gen_op decomp::Op(int i) const;
 
        // Input                dec     : Decomposition (this)
        //                      i       : An index
        // Output               Op      : The ith base operator


// ------------------------------ Value Access --------------------------------

        // Input                dec     : Decomposition (this)
	//			m 	: Coherence order
        //                      i       : An index
        // Output               vx      : Row vector of the current
        //                                decomposition values
        // Or                   vx      : Row vector of the current
        //                                decomposition values
	//				  with the coherence order m
        // Or                   z       : Current decomposition value
        //                                of the ith basis operator

MSVCDLL row_vector decomp::values()      const;
MSVCDLL row_vector decomp::values(int m) const;
MSVCDLL complex    decomp::value(int  i) const;


// ----------------------- Operator Coefficient Access ------------------------

MSVCDLL double decomp::bcoefficient(int i) const;
 
        // Input                dec     : Decomposition (this)
        //                      i       : An index
        // Output               z       : A coefficient which, when
        //                                taken out of the ith operator
        //                                matrix representation, makes
        //                                the matrrix elemnts nice
 


// ------------------------------ Index Access --------------------------------


MSVCDLL int decomp::index(const std::string& Opname) const;

        // Input                dec     : Decomposition (this)
	//			Opname  : Name of a basis operator
        // Output               i       : Index of specified basis
        //                                operator.
	// Note				: If requested operator does
 	//				  not exist, return is -1


// ____________________________________________________________________________
// U                          SORTING FUNCTIONS
// ____________________________________________________________________________

/* Allows for the basis operators to be sorted based on three possibilities.

         1.) The number of spin components in the operator
         2.) The name   of the  operator
         3.) The coherenece order of the operator

   Product operators are best displayed by first sorting by the number of
   spins involved, followed by the coherence order, followed by the operator
   name.                                                                     */

MSVCDLL std::vector<int> decomp::SortBySpins() const;

// ____________________________________________________________________________
// X                         FRIEND FUNCTIONS
// ____________________________________________________________________________

 
MSVCDLL friend void PB_dec(const spin_sys &sys, const gen_op &Op);
 
        // Input        sys  : Spin_system
        //              Op   : Operator to be decomposed
        // Output            : Decomposition is written to stdout
 
// ____________________________________________________________________________
// Z                     CLASS DECOMPOSITION I/O FUNCTIONS
// ____________________________________________________________________________

///Center Decomposition I/O Functions
///F_list <<		     - Standard output

	// Input 		ostr : Output stream
	//			dec  : Decomposition
	// Output 		ostr : Returns the modified output stream

MSVCDLL        std::ostream& decomp::print(std::ostream& ostr, int nc=3) const;
MSVCDLL friend std::ostream &operator <<  (std::ostream &ostr, const decomp &dec);
 
        // Input                dec     : Decomposition (this)
        //                      ostr    : An output stream
        // Output               ostr    : The output stream, modified to
        //                                contain the information about
        //                                the decomposition
 
MSVCDLL std::ostream& decomp::printOps(std::ostream& ostr, bool bs=false) const;
MSVCDLL std::ostream& decomp::print(std::ostream& ostr, const gen_op& Op);
};


// ____________________________________________________________________________
// S                         PyGAMMA Code (Non-Member)
// ____________________________________________________________________________

#ifdef PYGAMMA					// Begin PyGAMMA code block

void PyBaseDecomp();

#endif						// End of PyGAMMA code block


#endif 						// Class decomp Header
