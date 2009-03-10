/* XWinProcs.h ***************************************************-*-c++-*-
**                                                                      **
**                             G A M M A                                **
**                                                                      **
**      XWinProcs                                   Interface		**
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
** sets. This class embodies a Bruker parameter file, procs, that which **
** to control access to NMR processing parameters within XWinNMR. This	**
** is another ASCII file that has nothing to do with GAMMA and will	**
** only be used	for output. The file is usually dir/1/pdata/1/procs	**
** where dir is the directory base that contains XWinNMR data.  Note	**
** that without	the existence of a proc file XWinNMR will complain when	**
** looking at the data, even if it is just the associated fid.  One may	**
** still be able to plot the fid, but then one cannot display status 	**
** parameters under the "Output" menu in XWinNMR.  Below is a typical	**
** Bruker directory structure in a 1D acquisiton case.			**
**									**
**                          __ Acqu  (changable parameter file)		**
**			   / 						**
**                        /___ acqus (static parameter file)		**
**			 /						**
**  expname -- expnum --< ---- fid (binary data)			**
**			 \						**
**			  \___ pdata -- 1 -- proc, procs, meta		**
**									**
*************************************************************************/

#ifndef   XWinProcs_H_ 			// Is file already included?
#  define XWinProcs_H_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the implementation
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <string>			// Include libstdc++ strings
#include <GamIO/XWinProcPar.h>		// Include processing ASCII files
#include <Basics/ParamSet.h>		// Include GAMMA parameter sets

class XWinProcs: public XWinProcPar

// ----------------------------------------------------------------------------
// ------------------------------- STRUCTURE ----------------------------------
// ----------------------------------------------------------------------------
 
  {
 
// ----------------------------------------------------------------------------
// ----------------------------- PRIVATE FUNCTIONS ----------------------------
// ----------------------------------------------------------------------------
 
// ____________________________________________________________________________       
// i                      XWinNMR Procs File Error Handling
// ____________________________________________________________________________

/* These functions take care of any errors encountered when reading, writing,   
   and setting parameters in Bruker procs parameter files.
 
	Input		ProcPar : XWinNMR procs parameters (this)
			eidx    : Error index
                        pname   : Additional error message
                        noret   : Flag for linefeed (0=linefeed)
        Output          void    : An error message is output                 */

         void XWinProcserror(int    eidx, int noret=0) const;
         void XWinProcserror(int    eidx, const std::string& pname, int noret=0) const;
volatile void XWinProcsfatality(int eidx) const;
volatile void XWinProcsfatality(int eidx, const std::string& pname) const;

public:
// ____________________________________________________________________________ 
// A             XWinProcs Parameter File Constructors, Destructor
// ____________________________________________________________________________
 
/* These are the constructors of the class handling Bruker XWinNMR output
   parameter files.  This doesn't do anything in particular, it is the write
   functions that perform the work.                                          */

        XWinProcs::XWinProcs();
        XWinProcs::XWinProcs(const std::string& name);
        XWinProcs::XWinProcs(const XWinProcs& XWP);
virtual XWinProcs::~XWinProcs();
void    XWinProcs::operator= (const XWinProcs& XWP);

// ____________________________________________________________________________
// B                  XWinProcs Parameter Access Functions
// ____________________________________________________________________________
 
/* These functions allow users to set any more important parameters that these
   files contain.  The two primary values are the spectrum point size (SI)
   and the data byte order (BYTORDP).
 
                     INHERITED FROM CLASS XWinProcPar

string XWinProcs::parname()   const;  // ASCII File name
int    XWinProcs::BYTORDP()   const;  // Binary byte order
int    XWinProcs::FT_mod()    const;  // How FFT is performed
double XWinProcs::LB()        const;  // Line Broadening
int    XWinProcs::MC2()       const;  // FT type on t1
double XWinProcs::OFFSET()    const;  // Spectrum offset
double XWinProcs::PHC0()      const;  // Zero order phase
double XWinProcs::PHC1()      const;  // 1st order phase
string XWinProcs::REVERSE()   const;  // Plot spectrum reverse
double XWinProcs::SF()        const;  // Spectrometer frequency
int    XWinProcs::SI()        const;  // Data size (re+im)
int    XWinProcs::SSB()       const;  // Sine bell
int    XWinProcs::STSI()      const;  // Strip size
int    XWinProcs::STSR()      const;  // Strip start
double XWinProcs::SW_p()      const;  // Spectral width (PPM)
double XWinProcs::TDeff()     const;  // Effective FFT size
int    XWinProcs::WDW()       const;  // Window function

void XWinProcs::BYTORDP(int bo);      // Set binary byte order
void XWinProcs::MC2(int mc);          // Set transform type on t1
void XWinProcs::REVERSE(int yn);      // Set spectrum reverse
void XWinProcs::PPARMOD(int pm);      // Data set dimension
void XWinProcs::SI(int si);	      // Data size (re + im)
void XWinProcs::SF(double SF);        // Spectrometer freq. (MHz)
void XWinProcs::SSB(int sb);          // Sine offset (pi/sb)
void XWinProcs::STSI(int sb);         // Strip size
void XWinProcs::STSR(int sr);         // Strip start
void XWinProcs::SW_p(double swp);     // Sweep width (ppm)
void XWinProcs::WDW(int wd);          // Window function                     */

// ____________________________________________________________________________
// C                       XWinProcs Input Functions
// ____________________________________________________________________________

/* These functions will read in the 1D processing parameters from an XWinNMR
   parameter file, typically named procs.  By design, the Bruker parameter
   file is initially read into a GAMMA parameter set so that ALL parameters in
   the file are stored (class XWinPSet).  Subsequently, the parameters in the
   parameter set are parsed (herein) to obtain values of consequence to GAMMA
   and these are explicitly maintained variables in this class.

      Function                               Purpose
    ____________________________________________________________________________

     parsePSet          Parses a Bruker parameter set (XWinPSet) for parameters
                        of consequence to processing.
       read             Read in parameter set for class object.  This is done
		        special since Bruker format is NOT in GAMMA parameter
		        format so it must be parsed appropriately.

                     INHERITED FROM CLASS XWinProcPar

	bool XWinProcs::readPPar(const string& filein, int warn=2);
	bool XWinProcs::readPPar(int warn=2);
virtual bool XWinProcPar::parsePSet(int warn=2);                              */


// ____________________________________________________________________________
// D                      XWinProcs Output Functions
// ____________________________________________________________________________

/* These function allow for output of NMR parameters directly into a Bruker
   XWinNMR ASCII parameter file (procs). 

int      writePPar(const string& name, int warn=2);
int      writePPar(int warn=2) const;                                        */

// ____________________________________________________________________________
// E                    XWinProcs Standard Output Functions
// ____________________________________________________________________________

/* These function allow for a quick output of the parameter file contents.
   They don't have anything to do with output while running XWinNMR, rather
   users can just glance at procs parameters or store then in a small file.  */

//ostream& XWinProcs::printPset(ostream& O) const;		INHERITED
//virtual ostream& XWinProcs::print(ostream& ostr, int full=0, int hdr=1) const;
//friend ostream& operator<< (ostream& O, const XWinProcs& P);

// ____________________________________________________________________________
// F                    XProcPar BrukerLike Output Functions
// ____________________________________________________________________________

/* These functions perform ASCII output of processing parameters.  The format
   here is similar to issuing a "dpp" command in XWinNMR or using the menu
   choice "Output/Display status pars./Processing only".  It isn't as complete
   as the Bruker output because I'm bored and its often a mystery how they
   get some of their values.....  Most of the values output are taken from the
   parameter set which holds all the values which were read in from the
   Bruker parameter file.  It makes no sense to use these functions if on
   hasn't first read such a file since all the parameters will be empty.  A
   couple of values are used directly from the class when parameters need to
   be calculated.                                                            */

std::ostream& XWinProcs::dpp(std::ostream& ostr, double BF0=0) const;
};

#endif 								// XWinProcs.h

                                                                                



