/* RelaxBas.h ***************************************************-*-c++-*-
**									**
**	                           G A M M A				**
**									**
**	Basic Relaxation 				Interface	**
**									**
**	Scott A. Smith							**
**      Copyright (c) 1999                                              **
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**									**
**      $Header: $
**									**
*************************************************************************/

/*************************************************************************
**									**
** Description								**
**									**
** This module deals with a very primitive relaxation treatement. In 	**
** this case the users ascribes a single T1 and T2 value to each spin	**
** in a system.  The class RelaxBas provides the means of reading such	**
** values from an external file, generating a pseudo-relaxation super-	**
** operator, and evolving a density operator under simple relaxation.	**
**									**
** In this treatment, the off-diagonal density operator elements in the	**
** product basis (single and multiple quantum coherences) will decay	**
** with a rate of 1/T2 = R2 and the Fz components of each spin, Izi,    **
** will relax at a rate 1/T1 = R1.                                      **
**									**
*************************************************************************/

///Chapter Basic Relaxation
///Section Overview
///Body The ...
///Section Available Basic Relaxation Functions

#ifndef   RBasic_h_			// Is this file already included?
#  define RBasic_h_ 1			// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the interface
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <vector>			// Include libstdc++ STL vectors
#include <Matrix/row_vector.h>		// Include GAMMA row vectors
#include <HSLib/GenOp.h>		// Include GAMMA general operators

class RBasic

// ----------------------------------------------------------------------------
// ------------------------------- STRUCTURE ----------------------------------
// ----------------------------------------------------------------------------

  {
  std::vector<double> R1rates;		// The R1 relaxation rates
  std::vector<double> R2rates;		// The R2 relaxation rates
  matrix              FZxNS;		// Basis functions spin Fz values
  col_vector          Fzs;		// Basif functions total Fz values
  std::vector<double> Cinf;		// Iz coefficients of sigma inf
  std::vector<double> Csig;		// Iz coefficients of sigma 
  std::vector<gen_op> Izis;		// Iz operators for all spins
  gen_op              H0;		// Static Hamiltonian
  gen_op              Det;		// Detection operator
  gen_op              SigInf;		// Infinite time density operator
  matrix              R2mx;		// Array of system R2 rates
 
// ----------------------------------------------------------------------------
// ----------------------------- PRIVATE FUNCTIONS ----------------------------
// ----------------------------------------------------------------------------
 
// ____________________________________________________________________________
// i                        Relax Basic Error Handling
// ____________________________________________________________________________

/* These functions take care of any errors encountered when reading, writing,   
   and setting parameters in Bruker acquisition parameter files.
 
	Input		RBas    : Basic relaxation (this)
			eidx    : Error index
                        pname   : Additional error message
                        noret   : Flag for linefeed (0=linefeed)
        Output          void    : An error message is output                 */

void RBasic::RBasErr(int   eidx,                           int noret=0) const;
void RBasic::RBasErr(int   eidx, const std::string& pname, int noret=0) const;
void RBasic::RBasFatal(int eidx)                                        const;
void RBasic::RBasFatal(int eidx, const std::string& pname)              const;

// ____________________________________________________________________________
// ii                        Relax Basic Setup Functions
// ____________________________________________________________________________
 
 
bool RBasic::GetNPoints(const ParameterSet& pset, int& ns, bool warn=true);
 
// ____________________________________________________________________________
// iii                  Relaxation Value Checking Functions
// ____________________________________________________________________________
 
void RBasic::CheckR1(double r1);
void RBasic::CheckR2(double r2);
void RBasic::CheckT1(double t1);
void RBasic::CheckT2(double t2);
void RBasic::CheckLW(double lw);

bool RBasic::CheckSpin(double  i, bool warn=true) const;
bool RBasic::CheckSpins(double N, bool warn=true) const;
bool RBasic::CheckHS(double    H, bool warn=true) const;

// ____________________________________________________________________________
// iv                      Longitudinal Setup Functions
// ____________________________________________________________________________

bool RBasic::SetIzs(const    spin_sys& sys,   bool warn=true);
bool RBasic::SetCinfs(const  gen_op&   sigma, bool warn=true);
bool RBasic::SetCsigs(const  gen_op&   sigma, bool warn=true);
bool RBasic::TestLong(double cutoff=1.e-9);

// ____________________________________________________________________________
// v                      Transverse Setup Functions
// ____________________________________________________________________________

/* This function sets up an array containing R2 times for each coherence in
   the system Hilbert space. If the associated spin system changes (i.e. its
   Hilbert space) or any relaxation rates are altered then this must be
   regnerated!                                                               */

void RBasic::SetR2Mx();
void RBasic::ZeroR2Mx();

public:
// ____________________________________________________________________________ 
// A                  RBasic File Constructors, Destructor
// ____________________________________________________________________________

/* These are the constructors of the class handling Bruker Relax Basic 1D
   acquisition binary files.  The default name such files is "fid". The
   output byte order is automatically set for the computer architecture.

        //                      name    : External filename 
	//			vx	: Data vector
	//			TD	: Total points (real + imag)
	//			byteord : Input byte order                   */
 
MSVCDLC      RBasic::RBasic();
MSVCDLC      RBasic::RBasic(const row_vector& vx);
MSVCDLC      RBasic::RBasic(const RBasic& RB);
MSVCDLC      RBasic::~RBasic();
MSVCDLL void RBasic::operator= (const RBasic& RB);

// ____________________________________________________________________________
// B                     Relax Basic Access Functions
// ____________________________________________________________________________
 
// ----------------------------------------------------------------------------
//                     Access To Rates, Times, Linewidths
// ----------------------------------------------------------------------------

MSVCDLL int    RBasic::spins() 	     const;		// No. spins
MSVCDLL int    RBasic::HS()          const;		// Hilbert space
MSVCDLL double RBasic::T1(int i)     const;		// Single T1
MSVCDLL double RBasic::T2(int i)     const;		// Single T2
MSVCDLL double RBasic::R1(int i)     const;		// Single R1
MSVCDLL double RBasic::R2(int i)     const;		// Single R2
MSVCDLL double RBasic::LW(int i)     const;		// Single LW
MSVCDLL double RBasic::RB(int i, int type) const;	// Generic function

MSVCDLL void RBasic::T1(double val, int i);		// Single T1
MSVCDLL void RBasic::T2(double val, int i);		// Single T2
MSVCDLL void RBasic::R1(double val, int i);		// Single R1
MSVCDLL void RBasic::R2(double val, int i);		// Single R2
MSVCDLL void RBasic::LW(double val, int i);		// Single LW
MSVCDLL void RBasic::RB(double val, int i, int type);	// Generic function

MSVCDLL std::vector<double> RBasic::T1s() const;		// Set of T1s
MSVCDLL std::vector<double> RBasic::T2s() const;		// Set of T2s
MSVCDLL std::vector<double> RBasic::R1s() const;		// Set of R1s
MSVCDLL std::vector<double> RBasic::R2s() const;		// Set of R2s
MSVCDLL std::vector<double> RBasic::LWs() const;		// Set of LWs
MSVCDLL std::vector<double> RBasic::RBRates(int type) const;	// Generic set of rates

// ----------------------------------------------------------------------------
//                     Access To System & System Operators
// ----------------------------------------------------------------------------

MSVCDLL bool   RBasic::SetSystem(const spin_sys& sys, int warn=2);
MSVCDLL bool   RBasic::SetH0(const     gen_op&     H, int warn=2);
MSVCDLL bool   RBasic::SetDet(const    gen_op&     D, int warn=2);
MSVCDLL bool   RBasic::SetSigInf(const gen_op&     S, int warn=2);
MSVCDLL matrix RBasic::R2Mx();
MSVCDLL matrix RBasic::R2LOp();
  

// ----------------------------------------------------------------------------
//                    Longitudinal Relaxation System Values
// ----------------------------------------------------------------------------

/* The longitudinal relaxation rates are strictly specified in the vector
   R1rates. These change only when that vector is altered. The R1 superoperator
   simply contains the specified R1 values ordered by spin. It will be of
   dimension NSxNS and diagonal.                                             */

matrix RBasic::R1LOp();

// ____________________________________________________________________________
//      Functions For Relaxation/Evolution Using Longitudinal Coefficients
// ____________________________________________________________________________

MSVCDLL gen_op     RBasic::SigmaT1(const  gen_op& sigma);
MSVCDLL gen_op     RBasic::SigmaT2(const  gen_op& sigma);
MSVCDLL col_vector RBasic::SigmaC(const   gen_op& sigma);
MSVCDLL col_vector RBasic::SigmaCEq(const gen_op& sigeq);
MSVCDLL col_vector RBasic::SigmaCEq();
MSVCDLL matrix     RBasic::RC();
MSVCDLL matrix     RBasic::HC(const gen_op& H);
MSVCDLL matrix     RBasic::HC();
MSVCDLL gen_op     RBasic::Sigma(const col_vector& sigmaC);



// sosik

// ____________________________________________________________________________
// C                  Basic Relaxation Parameter Set Functions
// ____________________________________________________________________________

/*                 Single Spin Relaxation Parameter Functions

     Function                          Result
     ---------        ------------------------------------------
      ReadT2          T2 Value From pset Parameter [idx]T2(spin)
      ReadT1          T1 Value From pset Parameter [idx]T1(spin)
      ReadLW          LW Value From pset Parameter [idx]LW(spin)
      ReadR2          R2 Value From pset Parameter [idx]R2(spin)
      ReadR1          R1 Value From pset Parameter [idx]R1(spin)             */

MSVCDLL double RBasic::ReadT2(const  ParameterSet& pset, int sp, int idx=-1, int pf=0);
MSVCDLL double RBasic::ReadT1(const  ParameterSet& pset, int sp, int idx=-1, int pf=0);
MSVCDLL double RBasic::ReadLW(const  ParameterSet& pset, int sp, int idx=-1, int pf=0);
MSVCDLL double RBasic::ReadR2(const  ParameterSet& pset, int sp, int idx=-1, int pf=0);
MSVCDLL double RBasic::ReadR1(const  ParameterSet& pset, int sp, int idx=-1, int pf=0);
MSVCDLL double RBasic::ReadPar(const ParameterSet& P,int I,int t,int idx=-1, int pf=0);

/*               Multiple Spin Relaxation Parameter Functions
 
            Function                      Result
            ---------   -------------------------------------------
            ReadT2s     T2 Values From pset Parameter [idx]T2(spin)
            ReadT1s     T1 Values From pset Parameter [idx]T1(spin)
            ReadLWs     LW Values From pset Parameter [idx]LW(spin)
            ReadR2s     R2 Values From pset Parameter [idx]R2(spin)
            ReadR1s     R1 Values From pset Parameter [idx]R1(spin)          */

MSVCDLL std::vector<double> RBasic::ReadT2s(const ParameterSet& p,int N,int idx=-1,int pf=0);
MSVCDLL std::vector<double> RBasic::ReadT1s(const ParameterSet& p,int N,int idx=-1,int pf=0);
MSVCDLL std::vector<double> RBasic::ReadLWs(const ParameterSet& p,int N,int idx=-1,int pf=0);
MSVCDLL std::vector<double> RBasic::ReadR2s(const ParameterSet& p,int N,int idx=-1,int pf=0);
MSVCDLL std::vector<double> RBasic::ReadR1s(const ParameterSet& p,int N,int idx=-1,int pf=0);
MSVCDLL std::vector<double> RBasic::ReadPars(const ParameterSet& p,
                                          int N, int type, int idx=-1,int pf=0);

// ____________________________________________________________________________
// D                    Basic Relaxation Input Functions
// ____________________________________________________________________________

MSVCDLL int RBasic::read(const std::string &filename, int idx=-1, int warn=2);
MSVCDLL int RBasic::read(const ParameterSet& pset,    int idx=-1, int warn=2);
 

// ____________________________________________________________________________
// E                   Basic Relaxation Evolution Functions
// ____________________________________________________________________________
 
MSVCDLL gen_op RBasic::Evolve(const spin_sys& sys, const gen_op& sig0, double t);
MSVCDLL gen_op RBasic::Evolve(const gen_op& sigmap, double t);

// ____________________________________________________________________________
// F                        Basic Acquisition Functions
// ____________________________________________________________________________

/* These functions will perform an ad-hoc evolution of the density operator
   under basic relaxation during an acquisition.  The density operator sig0
   will evolve for the time specified.  The evolution will first occur under
   the static Hamiltonian HO if one has be set, then under the pseudo-
   relaxation scheme of this class.                                          */


MSVCDLL void RBasic::FID(const gen_op& sigmap, double td, row_vector& fid, int N=0);

MSVCDLL void       RBasic::FID(const spin_sys& sys, const gen_op& sigmap,
                                          double td, row_vector& fid, int N=0);
MSVCDLL row_vector RBasic::FID(const spin_sys& sys, const gen_op& sigmap,
                                          double td,                  int N);

MSVCDLL row_vector RBasic::FID(const gen_op& sigmap, double td, int N);

// ____________________________________________________________________________
// G                   Basic Relaxation Output Functions
// ____________________________________________________________________________

MSVCDLL        std::ostream& RBasic::print(std::ostream& ostr, bool hdr=true) const;
MSVCDLL friend std::ostream& operator <<  (std::ostream& ostr, const RBasic& RB);

// __________________________________________________________________________
// H               Basic Relaxation Auxiliary Functions
// __________________________________________________________________________

MSVCDLL std::vector <double>RBasic::FzCoeffs(const spin_sys& sys, const gen_op& sigma);

// ____________________________________________________________________________
// S                            PyGAMMA Code
// ____________________________________________________________________________

#ifdef PYGAMMA					// Begin PyGAMMA code block

void PyRelaxBas();

#endif						// End of PyGAMMA code block

};

#endif 							// RelaxBas.h
