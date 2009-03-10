/* XWinAcqu2s.h *************************************************-*-c++-*-
**                                                                      **
**                             G A M M A                                **
**                                                                      **
**      XWinAcqu2s                                   Interface		**
**                                                                      **
**      Copyright (c) 1999                                              **
**      Scott Smith                                                     **
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Box 4005                                                        **
**      Tallahassee, FL 32306                                           **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
**      Description                                                     **
**                                                                      **
** The XWin* files provide an interface to Bruker XWinNMR (uxnmr) data  **
** sets. This class embodies a Bruker parameter file, acqu2s, which     **
** contains parameters detailing a 2D  acquisition. When such a file is **
** read in the class will contain all important acquisition parameters, **
** such as TD (# points) and SW (spectral width PPM), and make them     **
** accessible to outside functions.  When such a file is output this    **
** class will insure the file acqu2s is in Bruker XWinNMR format (ASCII) **
** When used in conjunction with other XWinNMR related GAMMA classes,   **
** reading and writing of XWinNMR 2D (&ND) serial files should be	**
** trivial. Note that this data file has nothing to do with GAMMA and	**
** will primarily be used for output.  It is usually found as		**
** expdir/1/acqu2s where expdir is a directory where an experiment is	**
** writing an acquisition.  Below is a typical Bruker directory		**
** structure in a 2D acquisiton case.					**
**									**
**                          __ acqu, acqu2u (changable parameter files)	**
**			   / 						**
**                        /___ acqus, acqu2s (static parameter file)	**
**			 /						**
**  expname -- expnum --< ---- ser (binary data)			**
**			 \						**
**			  \___ pdata -- 1 -- proc, proc2, procs, proc2s **
**                                           meta, outd, 2rr, 2ii       **
**									**
*************************************************************************/

#ifndef   XWinAcqu2s_H_ 		// Is file already included?
#  define XWinAcqu2s_H_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the implementation
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <string>			// Include libstdc++ strings
#include <Basics/ParamSet.h>		// Include GAMMA parameter sets
#include <GamIO/XWinAcqPar.h>           // Include Bruker acquisition pars

class XWinAcqu2s: public XWinAcqPar 

// ----------------------------------------------------------------------------
// ------------------------------- STRUCTURE ----------------------------------
// ----------------------------------------------------------------------------
 
  {
 
// ----------------------------------------------------------------------------
// ----------------------------- PRIVATE FUNCTIONS ----------------------------
// ----------------------------------------------------------------------------
 
// ____________________________________________________________________________
// i                      XWinNMR Acqu2s File Error Handling
// ____________________________________________________________________________

/* These functions take care of any errors encountered when reading, writing,   
   and setting parameters in Bruker acquisition parameter files.
 
	Input		AcqPar  : XWinNMR Acqusition parameters (this)
			eidx    : Error index
                        pname   : Additional error message
                        noret   : Flag for linefeed (0=linefeed)
        Output          void    : An error message is output                 */

         void XWinAcqu2serror(int    eidx, int noret=0) const;
         void XWinAcqu2serror(int    eidx, const std::string& pname, int noret=0) const;
volatile void XWinAcqu2sfatality(int eidx) const;
volatile void XWinAcqu2sfatality(int eidx, const std::string& pname) const;

public:
// ____________________________________________________________________________ 
// A             XWinAcqu2s Parameter File Constructors, Destructor
// ____________________________________________________________________________
 
/* These are the constructors of the class handling Bruker XWinNMR acquisition
   parameter files.  This doesn't do anything in particular, it is the read
   and write functions that perform the work.  Thus, we only have a default
   constructor specified.  The reading and writing of the associated ASCII
   parameter file is done in one step, so we don't need anything complex.    */

        XWinAcqu2s::XWinAcqu2s();
        XWinAcqu2s::XWinAcqu2s(const std::string& name);
        XWinAcqu2s::XWinAcqu2s(const XWinAcqu2s& XWA2);
virtual XWinAcqu2s::~XWinAcqu2s();
void    XWinAcqu2s::operator= (const XWinAcqu2s& XWA2);

// ____________________________________________________________________________
// B                  XWinAcqu2s Parameter Access Functions
// ____________________________________________________________________________
 
/* These functions allow direct access to some of the more important parameters
   that each acqusition file should know.  The two primary values are the fid
   point size (TD) and the data byte order (BYTORDA).

		     INHERITED FROM CLASS XWinAcqPar

int    XWinAcqu2s::acqname()  const;     // File name (short)
double XWinAcqu2s::field()    const;     // Field strength (T)
int    XWinAcqu2s::AQ()	      const; 	// Acquisiiton length (sec)
int    XWinAcqu2s::AQ_mod()   const;	// Acquisition mode
double XWinAcqu2s::BF1()      const;     // Base Spectrometer freq.
double XWinAcqu2s::BF2()      const;     // Base Spectrometer freq.
int    XWinAcqu2s::BYTORDA()  const;     // Binary byte order
int    XWinAcqu2s::DS()       const;	// Number of dummy scans
string XWinAcqu2s::EXP()      const;	// Experiment name
double XWinAcqu2s::IN(int i)  const;     // Dwell time
string XWinAcqu2s::NAME()     const;     // Full File Name
int    XWinAcqu2s::NS()       const;	// Number of scans
string XWinAcqu2s::NUC(int i) const;     // Nucleus for a channel
string XWinAcqu2s::NUCLEUS()  const;	// Base nucleus
double XWinAcqu2s::O1()       const;     // Offset freq.
double XWinAcqu2s::O2()       const;     // Offset freq.
int    XWinAcqu2s::PARMODE()  const;	// Acquisiiton dimension
string XWinAcqu2s::PULPROG()  const;	// Pulse program
double XWinAcqu2s::SW()       const;	// Spectral width (PPM)
double XWinAcqu2s::SFO1()     const;	// Spectrometer freq.
double XWinAcqu2s::SFO2()     const;	// Spectrometer freq.
double XWinAcqu2s::SFO3()     const;	// Spectrometer freq.
string XWinAcqu2s::SOLVENT()  const;	// Solvent
double XWinAcqu2s::SW()       const;     // Spectral width (PPM)
double XWinAcqu2s::SW_h()     const;     // Spectral width (Hz)
int    XWinAcqu2s::TD()       const;	// Total points 
double XWinAcqu2s::TE()       const;	// Sample temperature

void XWinAcqu2s::field(bo);
void XWinAcqu2s::AQ_mod(int aqmo);
void XWinAcqu2s::BF1(double bf);
void XWinAcqu2s::BF2(double bf);
void XWinAcqu2s::BYTORDA(int bo);
int  XWinAcqu2s::D(int idx, double tsec, int warn=2);
void XWinAcqu2s::DS(int ds);
void XWinAcqu2s::EXP(const string& exp);
void XWinAcqu2s::IN(int i, double in);
void XWinAcqu2s::O1(double of);
void XWinAcqu2s::O2(double of);
void XWinAcqu2s::NAME(const string& name);
void XWinAcqu2s::NS(int ns);
void XWinAcqu2s::NUC(int i, const string& N);
void XWinAcqu2s::NUCLEI(int channel, const string& I, double O, int warn=2);
void XWinAcqu2s::NUCLEUS(const string& I);
int  XWinAcqu2s::P(int idx, double tp, int warn=2);
void XWinAcqu2s::PARMODE(int pm);
void XWinAcqu2s::PULPROG(const string& P);
void XWinAcqu2s::SFO1(double sf);
void XWinAcqu2s::SFO2(double sf);
void XWinAcqu2s::SFO3(double sf);
void XWinAcqu2s::SFO(double sf, int i);
void XWinAcqu2s::SOLVENT(const string& S);
void XWinAcqu2s::SW(double sw);
void XWinAcqu2s::SW_h(double sw);
void XWinAcqu2s::TE(double te);
void XWinAcqu2s::TD(int npts);                                               */

// ____________________________________________________________________________
// C                       XWinAcqu2s Input Functions
// ____________________________________________________________________________

/* These functions will read in the acquisition parameters from an XWinNMR
   parameter file, typically named acqu2s.  By design, the Bruker parameter
   file is initially read into a GAMMA parameter set so that ALL parameters in
   the file are stored.  Subsequently, the parameters in the parameter set are
   parsed to obtain values of consequence to GAMMA and these are explicitly
   maintained variables in the class.

      Function                               Purpose
   ____________________________________________________________________________

     parsePSet          Parses a Bruker parameter set (XWinPSet) for parameters
                        of consequence to an acquisition.
       read             Read in parameter set (class XWinPset) and parse out
                        parameters of consequence to an acquisition.

virtual bool XWinAcqus::read(const string& filein, int warn=1);
virtual bool XWinAcqus::read(int warn=1);
virtual bool XWinAcqus::parsePSet(int warn=1);                               */

// ____________________________________________________________________________
// D                       XWinAcqu2s Output Functions
// ____________________________________________________________________________

/* These function allow for output of NMR parameters directly into a Bruker
   XWinNMR ASCII parameter file (Acqu2s).
 
                     INHERITED FROM CLASS XWinAcqPar
 
int XWinAcqu2s::writeAPar(const string& name, int warn=2);
int XWinAcqu2s::writeAPar(int warn=2) const;                                 */

// ____________________________________________________________________________
// E                    XWinAcqu2s Standard Output Functions
// ____________________________________________________________________________

/* These function allow for a quick output of the parameter file contents.
   They don't have anything to do with output while running XWinNMR, rather
   users can just glance at Acqu2s parameters or store then in a small file.  */

// ostream& printPset(ostream& ostr) const;		INHERITED
virtual std::ostream& XWinAcqu2s::print(std::ostream& ostr, int full=0, int hdr=1) const;
friend  std::ostream& operator<< (std::ostream& ostr, const XWinAcqu2s& AcqPar);

// ____________________________________________________________________________
// Z                    XWinAcqu2s BrukerLike Output Functions
// ____________________________________________________________________________

/* These functions perform ASCII output of acquisiton parameters.  The format
   here is similar to issuing a "dpa" command in XWinNMR or using the menu
   choice "Output/Display status pars./Acquisition only".  It isn't as complete
   as the Bruker output because I'm bored and its often a mystery how they
   get some of their values.....                                             */

std::ostream& XWinAcqu2s::dpa(std::ostream& ostr) const;
virtual std::ostream& printGAMMA(std::ostream& ostr) const;
};

#endif 								// XWinAcqu2s.h
