/* DetVec.h ***************************************************-*-c++-*-
**									**
**	                        G A M M A				**
**								 	**
**	Bloch Detection Vector 			Interface		**
**						 			**
**      Copyright (c) 2002                                              **
**      Dr. Scott A. Smith						**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Box 4005                                                        **
**      Tallahassee, FL 32306                                           **
**						 			**
**      $Header: $
**								 	**
*************************************************************************/

/*************************************************************************
**								 	**
** Description							 	**
**								 	**
** The class DetVec defines a Bloch detection vector. Such vectors	**
** are used when determining detectable magnetization values from	**
** magnetization vectors that evolve according to the phenomenological	**
** Bloch equations. A magnetization vector as specified herein involves **
** N individual sub-vectors, each of these sub-vectors has three	**
** magnetization components. The vector with N components takes the 	**
** blocked form								**
**		     |M> = ||M > |M > |M > ..... |M   >>		**
**                            0    1    2          N-1			**
**								 	**
** & each sub-vector is							**
**                        |M > = |M  , M   , M  >		 	**
**                          i      ix   iy    iz			**
**								 	**
** A Bloch detection vector is a vector whcih selects of various	**
** components from the magnetization vector. It will (should) have a	**
** corresponding blocked structure.					**
**								 	**
**		     <D| = <<D | <D | <D | ..... <D   ||		**
**                            0    1    2          N-1			**
**								 	**
** As an example one might consider detection of x magnetization. The	**
** compoennts of |M> are generally given by				**
**								 	**
**           <3*i|M> = M     <3*i+1|M> = M     <3*i+2|M> = M		**
**                      ix                iy                iz		**
**								 	**
** so the Bloch detection vector will have components			**
**								 	**
**        <D |3*i> = 1     <D |3*i+1> = 0     <D |3*i+2> = 0		**
**          x                y                  z         		**
**									**
** Bloch detection vectors are simply GAMMA row vectors set to interact	**
** with Bloch magnetization vectors (MagVec). They add additional	**
** functionality beyond row vectors (row_vector) that make simulations	**
** involving the phenomenological Bloch equations integrate smoothly	**
** into the rest of the platform. 					**
**									**
*************************************************************************/

#ifndef   DetVec_h_			// Is file already included?
#  define DetVec_h_ 1			// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// this is the interface
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <string>			// Include libstdc++ strings
#include <vector>			// Include libstdc++ STL vectors
#include <Matrix/row_vector.h>		// Include GAMMA column vectors
#include <Basics/ParamSet.h>		// Include GAMMA parameter sets
#include <Level1/coord.h>		// Include GAMMA coordinates

class DetVec : public row_vector
  {

friend class BlochSys;
  
// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// i                    Bloch Detection Vector Error Handling
// ____________________________________________________________________________


        // Input                sys     : Spin system (this)
        //                      ei	: Error index
        //                      nr	: Flag for linefeed (0=linefeed)
        //                      pn	: string in message
     
         void DetVec::BDVerror(int ei,                        int nr=0) const;
         void DetVec::BDVerror(int ei, const std::string& pn, int nr=0) const;
volatile void DetVec::BDVfatal(int ei) const;
volatile void DetVec::BDVfatal(int ei, const std::string& pn) const;

// ____________________________________________________________________________
// ii                   Bloch Detection Vector Checking Functions
// ____________________________________________________________________________

bool DetVec::CheckNorms(const std::vector<double>&  Ns, bool warn=true) const;
bool DetVec::CheckRange(int cmp,                        bool warn=true) const;

// ____________________________________________________________________________
// iii                     Bloch Detection Vector Setup Functions
// ____________________________________________________________________________

/* These are protected functions because they allow specific aspects of the
   vector to be set up without worrying about consistency! Basically what we
   must determine are

                          1.) Number of sub-vectors
                          2.) Mx, My, and Mz for each sub-vector

   Parameter NDetVecs is used indicate how many sub-vectors are defined.
   If that is NOT found, it is assumed that there is only 1 sub-vector.     */

bool DetVec::SetVector(const   ParameterSet& P, int pfx=-1, bool W=true);
bool DetVec::GetNVects(const   ParameterSet& P, int&     N, bool W=true) const;
bool DetVec::SetSubVects(const ParameterSet& P, int      N, bool W=true);
bool DetVec::GetCoord(const  ParameterSet& P, 
                                     coord& pt, int idx=-1, bool W=true) const;
bool DetVec::GetMxMyMz(const   ParameterSet& P, 
            double& Mx, double& My, double& Mz, int idx=-1, bool W=true) const;

// ----------------------------------------------------------------------------
//         These Read All Single Bloch Detection Vector Parameters
// ----------------------------------------------------------------------------


//bool DetVec::GetVect(const ParameterSet& pset, int i, double& v, Isotope& I,
//             double& R1, double& R2, coord& Pt, int& Sp, bool warn=true) const;

// ----------------------------------------------------------------------------
//         These Read All Bloch Detection Vector Pair Parameters
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

public:

// ____________________________________________________________________________
// A                   SPIN SYSTEM CONSTRUCTION, DESTRUCTION
// ____________________________________________________________________________

///Center Spin System Algebraic
///F_list DetVec		- Constructor
///F_list ~			- Destructor
///F_list =			- Assignment	

// ----------------------------------------------------------------------------
//                          Simple Constructors
// ----------------------------------------------------------------------------

MSVCDLC DetVec::DetVec(int   N=0);
MSVCDLC DetVec::DetVec(const DetVec&   BD);
MSVCDLC DetVec::DetVec(const row_vector& RV);

// ----------------------------------------------------------------------------
//              Constructors Using Individual Bloch Detection Vectors
// ----------------------------------------------------------------------------

MSVCDLC DetVec::DetVec(double x, double y, double z);
MSVCDLC DetVec::DetVec(const coord& D);
MSVCDLC DetVec::DetVec(double x1,double y1,double z1,double x2,double y2,double z2);
MSVCDLC DetVec::DetVec(const coord& D1, const coord& D2);
MSVCDLC DetVec::DetVec(const std::vector<coord>& Ds);

// ----------------------------------------------------------------------------
//              Constructors Of Common Detection Vectors
// ----------------------------------------------------------------------------

MSVCDLC DetVec::DetVec(int N, char x);			// x = x,y,z,+,-

// ----------------------------------------------------------------------------
//                       Assignment and Destruction
// ----------------------------------------------------------------------------

//        DetVec::~DetVec();
//DetVec& DetVec::operator= (const DetVec& BDV);

// ____________________________________________________________________________
// B                    Bloch Detection Vector Access
// ____________________________________________________________________________

//int DetVec::size()   const;			// Inherited
MSVCDLL int DetVec::NComps() const;

// ----------------------------------------------------------------------------
//                     Detection (Sub)Vector Components
// ----------------------------------------------------------------------------

MSVCDLL double DetVec::Dx(int cmp) const;
MSVCDLL double DetVec::Dy(int cmp) const;
MSVCDLL double DetVec::Dz(int cmp) const;

MSVCDLL void   DetVec::Dx(int cmp, double mx);
MSVCDLL void   DetVec::Dy(int cmp, double my);
MSVCDLL void   DetVec::Dz(int cmp, double mz);

MSVCDLL double DetVec::x(int     cmp=0) const;
MSVCDLL double DetVec::y(int     cmp=0) const;
MSVCDLL double DetVec::z(int     cmp=0) const;
MSVCDLL double DetVec::norm(int  cmp=0) const;
MSVCDLL double DetVec::theta(int cmp=0) const;
MSVCDLL double DetVec::phi(int   cmp=0) const;

// ----------------------------------------------------------------------------
//                     Detection (Sub)Vector Norms
// ----------------------------------------------------------------------------

MSVCDLL std::vector<double> DetVec::Norms() const;
MSVCDLL void                DetVec::Norms(const std::vector<double>& Ns);

MSVCDLL double DetVec::Norm(int i) const;
MSVCDLL void   DetVec::Norm(double nv, int i);

// ____________________________________________________________________________
// C              Bloch Detection Vector Parameter Set Functions
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//       Functions To Make A Bloch Detection Vector From A Parameter Set
// ----------------------------------------------------------------------------


/*
virtual int write(const std::string &filename, int idx=-1, int warn=2) const;
virtual int write(std::ofstream& ofstr, int idx=-1, int warn=2) const; 
*/


//-----------------------------------------------------------------------------
//                   Parameter Set From Bloch Detection Vector
//-----------------------------------------------------------------------------

MSVCDLL             operator ParameterSet( ) const;
MSVCDLL friend void operator+= (ParameterSet& pset, const DetVec& BDV);
MSVCDLL bool DetVec::PSetAdd(ParameterSet& pset, int pfx=-1)   const;

//-----------------------------------------------------------------------------
//            Parameter Set File From Bloch Detection Vector
//-----------------------------------------------------------------------------

        // Input                M       : Detection vector (this)
        //                      filename: Output file name
        //                      ofstr   : Output file stream
        //                      pfx     : Vector prefix (default -1)
        //                      warn    : Warning level
        // Output               none    : Vector is written as a parameter
        //                                to file or output file stream

MSVCDLL bool DetVec::write(const std::string& filename, int pfx=-1, int warn=2) const;
MSVCDLL bool DetVec::write(std::ofstream& ofstr,        int pfx=-1, int warn=2) const;

// ____________________________________________________________________________
// D                  Bloch Detection Vector Input Functions
// ____________________________________________________________________________

///F_list read		- Read magnetization vector from disk file
///F_list ask_read	- Ask for file, read magnetization vector from file

	// Input		M	 : Detection vector (this)
	// 			filename : Input filename
	//			idx	 : Parameter index value used for
	//				   prefix [#] in input names
	//			argc	 : Number of arguments
	//			argv     : Vector of argc arguments
	//			argn     : Argument index
	//			warn	 : Warning output level
	//					0 = no warnings
	//					1 = warnings
	//				       >1 = fatal warnings
	// Output		none	 : Vector is filled with values in
	//				   parameters read from file
	// Output		string   : The parameter argn of array argc
	//				   is used to supply a filename
	//				   from which the spin system is read
	//				   If the argument argn is not in argv,
	//				   the user is asked to supply a filename
        //                                 The set filename is returned 
	// Note			 	 : The file should be an ASCII file
	//				   containing recognized M parameters
	// Note			 	 : The vector is modifed (filled)


MSVCDLL bool DetVec::read(const std::string& fn,    int idx=-1, int warn=2);
MSVCDLL bool DetVec::read(const ParameterSet& pset, int idx=-1, int warn=2);

MSVCDLL std::string DetVec::ask_read(int argc, char* argv[], int argn);
MSVCDLL std::string DetVec::ask_read(int argc, char* argv[], int argn,
                                                       const std::string& def); 

// ____________________________________________________________________________
// E                Bloch Detection Vector Standard I/O Functions
// ____________________________________________________________________________

MSVCDLL std::vector<std::string> DetVec::printStrings() const;
MSVCDLL std::ostream&            DetVec::print(std::ostream& out, int np=20) const;
MSVCDLL friend std::ostream& operator<<(std::ostream& out, const DetVec& M);

// ____________________________________________________________________________
// F                  Specialized Bloch Detection Vectors
// ____________________________________________________________________________

MSVCDLL        DetVec DetVec::Dx()    const;
MSVCDLL        DetVec DetVec::Dy()    const;
MSVCDLL        DetVec DetVec::Dz()    const;
MSVCDLL static DetVec DetVec::DxVec(int NC);
MSVCDLL static DetVec DetVec::DyVec(int NC);
MSVCDLL static DetVec DetVec::DzVec(int NC);
MSVCDLL        DetVec DetVec::DxVec() const;
MSVCDLL        DetVec DetVec::DyVec() const;
MSVCDLL        DetVec DetVec::DzVec() const;

// ____________________________________________________________________________
// G                Bloch Detection Vector Evolution Functions
// ____________________________________________________________________________	

// ____________________________________________________________________________	
// H                       PyGAMMA Code (Member)
// ____________________________________________________________________________	


#ifdef PYGAMMA					// Begin PyGAMMA code block

std::string DetVec::PyPrint() const;

#endif						// End PyGAMMA include.	

};

// ____________________________________________________________________________
// I                     PyGAMMA Code (Non-Member)
// ____________________________________________________________________________

#ifdef PYGAMMA					// If we are compiling PyGAMMA

void PyDetVec();

#endif						// End PyGAMMA include.	

#endif						// DetVec.h

