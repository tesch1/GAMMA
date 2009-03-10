/* GenOpRep.h ***************************************************-*-c++-*-
**                                                                      **
**                               G A M M A                              **
**                                                                      **
**      General Operator Represenation              Interface           **
**                                                                      **
**      Copyright (c) 1990, 1991, 1992                                  **
**      Scott Smith                                                     **
**      Eidgenoessische Technische Hochschule                           **
**      Labor fuer physikalische Chemie                                 **
**      8092 Zuerich / Switzerland                                      **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
**  Description                                                         **
**                                                                      **
** The class genoprep defines a single operator representaion for a     **
** variable of type gen_op, i.e. a GAMMA general operator.  Each        **
** representation consists of a matrix, a basis, and a priority #.      **
**                                                                      **
*************************************************************************/

#ifndef _GenOpRep_h_ 			// Is file already included?
#define _GenOpRep_h_ 1			// If no, then remember it
#  if defined(GAMPRAGMA) 			// Using the GNU compiler?
#    pragma interface			// If yes, then we are the interface
#endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <Matrix/matrix.h>		// Know about GAMMA matrices
#include <HSLib/Basis.h>		// Know about operator bases

class genoprep
  {
public:
 
         matrix RepMx;			// Op matrix representation
         basis  RepBs;			// Associated Op basis (array)
         int    RepPty;			// Representation priority
  static bool   BSPrnt;			// Flag to print basis array

// ____________________________________________________________________________
// i                CLASS OPERATOR REPRESENTATION ERROR HANDLING
// ____________________________________________________________________________

	// Input		OpRep	: Operator representation (this)
        //                      eidx    : Error index
        //                      noret   : Flag for linefeed (0=linefeed)
        // Output               void    : An error message is output   (error)
        //                                or program execution stopped (fatal)
 
         void genoprep::OpReperror(int eidx, int noret=0) const;
volatile void genoprep::OpRepfatal(int eidx)              const;
 
// ____________________________________________________________________________
// A            OPERATOR REPRESENTATION CONSTRUCTORS/DETRUCTOR
// ____________________________________________________________________________

MSVCDLC genoprep::genoprep();
MSVCDLC genoprep::genoprep(const genoprep& OpRep);
MSVCDLC genoprep::genoprep(const matrix& mx, const basis& bs, int pty);
MSVCDLC genoprep::~genoprep();
genoprep& genoprep::operator= (const genoprep& OpRep); 

// ____________________________________________________________________________
// J                    OPERATOR REPRESENTATION CHECKS
// ____________________________________________________________________________


	// Input		OpRep: A operator representation
	// 			warn : A warning level
	//			         0 = no warning
	//			         1 = non-fatal warning
	//			         2 = fatal warnings
	// Output		bool : True if OprRep matrix mx square.
        //			       & its dimension matches its basis

MSVCDLL bool genoprep::OpRepCheck(int warn=2) const;

// ____________________________________________________________________________
// K                  CLASS OPERATOR REPRESENTATION I/O FUNCTIONS
// ____________________________________________________________________________
 
// ------------------------ ASCII Output Functions ----------------------------
 
/*              Input           OpRep: Operator representation (this)
                                ostr : Output ASCII file stream
                                full : Flag for amount of output
                Return          void : OpRep is sent to the output stream    */
 
MSVCDLL        std::ostream& genoprep::print(std::ostream& ostr, int full=0) const;
MSVCDLL friend std::ostream& operator<< (std::ostream& ostr,const genoprep &OpRep);
 
// ------------------------ Binary Output Functions ---------------------------

/*              Input           OpRep: Operator representation (this)           
                                fn   : Input binary filename
                                fp   : File stream (pointing at OpRep spot)
                Return          void : OpRep is written to either the
                                       specified file or filestream.
                Note                 : Output format is partially set by
                                       class matrix (matrix typing)          */  

MSVCDLL void           genoprep::write(const std::string& fn) const;
MSVCDLL std::ofstream& genoprep::write(std::ofstream& fp)     const;

// ------------------------ Binary Input Functions ----------------------------

/*              Input           OpRep: Operator representation (this)
                                fn   : Input binary filename
                                fp   : File stream (pointing at OpRep)
                Return          void : OpRep is read in from either the
                                       specified file or filestream.         */  

MSVCDLL void           genoprep::read(const std::string& fn);
MSVCDLL std::ifstream& genoprep::read(std::ifstream& fp);

// ____________________________________________________________________________
// L        OPERATOR REPRESENTATION LIST/VECTOR SUPPORT FUNCTIONS
// ____________________________________________________________________________

MSVCDLL bool genoprep::operator==(const genoprep& OpRep) const;
MSVCDLL bool genoprep::operator!=(const genoprep& OpRep) const;
MSVCDLL bool genoprep::operator<(const  genoprep& OpRep) const;
MSVCDLL bool genoprep::operator>(const  genoprep& OpRep) const;

// ____________________________________________________________________________
// S                         PyGAMMA Code (Non-Member)
// ____________________________________________________________________________


#ifdef PYGAMMA					// Begin PyGAMMA code block

//void PyGenOpRep();

#endif						// End of PyGAMMA code block
 
};

#endif							// GenOpRep.h
