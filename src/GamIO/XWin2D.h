/* XWin2D.h *****************************************************-*-c++-*-
**                                                                      **
**                             G A M M A                                **
**                                                                      **
**      XWin2D                                    Interface		**
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
** The XW* files provide an interface to Bruker XWinNMR (uxnmr) data    **
** sets. This class embodies a Bruker data set for a 2D acquisition.    **
** Each 2D acquisition generates several files (binary and ASCII) 	**
** spanning several directories.  This class is intended to handle 	**
** this structure.  Below is a typical Bruker directory structure 	**
** associated with a 2D acquisiton.					**
**									**
**                          __ acqu, acqu2 (changable parameter file)	**
**			   / 						**
**                        /___ acqus, acqu2s (static parameter file)	**
**			 /						**
**  expname -- expnum --< ---- ser (binary data)			**
**			 \						**
**			  \___ pdata -- 1 -- proc, proc2, procs, proc2s **
**									**
** This class will handle the directory hierarchy shown above as	**
** well as most of the files therein. Thus, given a base directory 	**
** for an experiment/simulation output (expname) & an experiment	**
** number (expnum) this class will generate the subdirectories shown,	**
** the acquisition parameter (acqu*) and binary (ser) files as well as	**
** the processing files (proc*, meta).  It is NOT intended to generated	**
** processed 2D/ND data files - that should be done using the XWinNMR 	**
** software.  The class will also allow for import of 2D data sets.	**
** The serial file (ser), & to a more limited extent processed spectra,	**
** can be read and placed into GAMMA row_vectors and matrices. The	**
** associated parameters are also provided for.				**
**									**
*************************************************************************/

#ifndef   XWin2D_H_ 				// Is file already included?
#  define XWin2D_H_ 1				// If no, then remember it
#  if defined(GAMPRAGMA)			// Using the GNU compiler?
#    pragma interface				// This is the implementation
#  endif

#include <GamGen.h>				// Know MSVCDLL (__declspec)
#include <string>				// Include libstdc++ std::strings
#include <GamIO/XWinSer.h>			// Include XWinNMR serial file 
#include <GamIO/XWinAcqus.h>			// Include XWinNMR acqus file
#include <GamIO/XWinAcqu2s.h>			// Include XWinNMR acqu2s file
#include <GamIO/XWinProcs.h>			// Include XWinNMR procs file
#include <GamIO/XWinProc2s.h>			// Include XWinNMR proc2s file
#include <GamIO/XWinMeta.h>			// Include XWinNMR meta file
#include <GamIO/XWinOutd.h>			// Include XWinNMR outd file

class XWin2D

// ----------------------------------------------------------------------------
// ------------------------------- STRUCTURE ----------------------------------
// ----------------------------------------------------------------------------
 
  {
  int         oldMeta;				// Flag older meta format
  std::string dname;				// Acquisition directory name
  int         Aidx;				// Acquisition experiment index
  int         Pidx;				// Acquisition processing index
  std::string NAIdir, NPdir, NPIdir;		// Data set directory names
  std::string Nacqu, Nacqus, Nacqu2, Nacqu2s;	// Acquisition ASCII file names
  std::string Nser;				// Acquisition data file name
  std::string Nproc, Nprocs, Nproc2, Nproc2s;	// Processing ASCII file names
  std::string Nmeta, Noutd;			// Processing ASCII file names
  XWinAcqus   Acqs;				// Acq.  Parameter file for 1D
  XWinProcs   Procs;				// Proc. Parameter file for 1D
  XWinSer     Ser;				// Binary serial data file 
  XWinAcqu2s  Acq2s;				// Acq.  Parameter file for 2D
  XWinProc2s  Proc2s;				// Proc. Parameter file for 2D
//  double     FieldT;				// Bo Field in Teslas
 
// ----------------------------------------------------------------------------
// ----------------------------- PRIVATE FUNCTIONS ----------------------------
// ----------------------------------------------------------------------------
 
// ____________________________________________________________________________       
// i                   XWinNMR 2D Data Set Error Handling
// ____________________________________________________________________________
 
         void XWin2D::XWin2Derror(int eidx, int noret=1) const;
         void XWin2D::XWin2Derror(int eidx, const std::string& P, int noret=1) const;
volatile void XWin2D::XWin2Dfatality(int eidx) const;
volatile void XWin2D::XWin2Dfatality(int eidx, const std::string& P) const;
 
// ____________________________________________________________________________       
// ii                  XWinNMR 2D Data Set Error Handling
// ____________________________________________________________________________

int CheckDir(int TF,   int warn, const std::string& dout) const;
int CheckWrite(int TF, int warn, const std::string& dout) const;

// ____________________________________________________________________________ 
// iii                   XWinNMR 2D Data Set Setup Functions
// ____________________________________________________________________________
/* These functions are used to quickly set up values associated with the 2D
   data set.  In particular they handle setting up a standard Bruker directory
   structure and the file names in the data set.  Another function is used to
   insure the that the parameter sets are self-consistent. This should be
   called before the data set (or at least the parameter files) are output.  */

//void XWin2D::SetField();			// Set Spectrometer Field (T)
//void XWin2D::FieldReset(double BoT);		// Set Spectrometer Field (T)
void XWin2D::SetNames();			// Set Directory & File Names
int  XWin2D::MakeDirs(int warn=2);		// Construct Directories
int  XWin2D::ReadPars(int warn=2);		// Read All Parameter Files
void XWin2D::SetConsistent();
 
public:
// ____________________________________________________________________________ 
// A                XWinNMR 2D Data Set Constructors, Destructor
// ____________________________________________________________________________

/* These are the constructors of the class handling Bruker XWinNMR 2D data
   sets. There are several files associated with such a data set. Those
   associated with the acquisition are the four ASCII parameter files
  (acqu, acqus, acqu2, and acqu2s) and the binary serial data file (ser).
   In the processed data sub-directory, pdata will reside more files - whether
   or NOT the data has actually been processed.  These will be the six
   parameter files (proc, procs, proc2, proc2s, meta, and outd).  If the data
   has been processed there may also exist more binary files (e.g. 2rr) if the
   data has been processed.  GAMMA has individual XWin* classes for handling
   these individual files, so this class has the job of keeping track of
   directories and making sure all these are appropriate files are dealt with.

   Note that these constructors do NO writing! Furthermore, they will only read
   the ASCII parameter files and NOT the larger binary files.  Writing and/or
   binary reading is left to other functions.                                */

XWin2D::XWin2D();
XWin2D::XWin2D(const std::string& dname, int mode = std::ios::in, int eno=1, int pno=0);
XWin2D::XWin2D(const XWin2D& XW2D);
virtual XWin2D::~XWin2D();
virtual XWin2D& XWin2D::operator=(const XWin2D& XW2D);

 
// ____________________________________________________________________________
// B                    XWin2D Parameter Access Functions
// ____________________________________________________________________________

/* These functions allow direct access to some of the more important parameters
   that each 2D data set should know.  This class contains objects of many
   types associated with the Bruker 2D data set files. Since they are quite
   similar we do not derive XWin2D from these, since this might cause conflicts
   (that may or may not be sorted out by virtual tables). Rather we rewrite the
   functions herein to match the lower classes and route to the proper
   dimension when necessary.....                                             */

/* --------------------------------------------------------------------------
                          Functions To Retrieve Parameters
   --------------------------------------------------------------------------*/
 
/*                   NOT REALLY INHERITED FROM CLASS XWinAcqPar
                           (Applies To Acqs and Acq2s)                       */
 
std::string XWin2D::acqname(int d=0)    const;	// Acq. Par. File name (short)
double XWin2D::AQ(int d=0)         const;	// Acquisition length (sec)
int    XWin2D::AQ_mod(int d=0)     const;	// Acquisition mode
double XWin2D::BF1(int d=0)        const;	// Base Spectrometer freq.
double XWin2D::BF2(int d=0)        const;	// Base Spectrometer freq.
int    XWin2D::BYTORDA(int d=0)    const;	// Binary byte order
int    XWin2D::DS(int d=0)         const;	// Number of dummy scans
std::string XWin2D::EXP(int d=0)        const;	// Experiment name
double XWin2D::XW_IN(int i,int d=0)   const;	// Dwell time
std::string XWin2D::NAME(int d=0)       const;	// Full File Name
int    XWin2D::NS(int d=0)         const;	// Number of scans
std::string XWin2D::NUC(int i,int d=0)  const;	// Nucleus for a channel
std::string XWin2D::NUCLEUS(int d=0)    const;	// Base nucleus
double XWin2D::O1(int d=0)         const;	// Offset freq.
double XWin2D::O2(int d=0)         const;	// Offset freq.
int    XWin2D::PARMODE(int d=0)    const;	// Acquisiiton dimension
std::string XWin2D::PULPROG(int d=0)    const;	// Pulse program
double XWin2D::SFO1(int d=0)       const;	// Spectrometer freq.
double XWin2D::SFO2(int d=0)       const;	// Spectrometer freq.
double XWin2D::SFO3(int d=0)       const;	// Spectrometer freq.
std::string XWin2D::SOLVENT(int d=0)    const;	// Solvent
double XWin2D::SW(int d=0)         const;	// Spectral width (PPM)
double XWin2D::SW_h(int d=0)       const;	// Spectral width (Hz)
int    XWin2D::TD(int d=0)         const;	// Total points
double XWin2D::TE(int d=0)         const;	// Sample temperature

/*                   NOT REALLY INHERITED FROM CLASS XWinSer
                             (Applies to File ser)                           */
 
std::string XWin2D::sername() 	const;		// File name
int    XWin2D::TDS()		const;		// No. total points

/*                  NOT REALLY INHERITED FROM CLASS XWinProcPar
                           (Applies To Procs and Proc2s)                    */
 
std::string XWin2D::parname(int d=0)   const;  // ASCII File name
int    XWin2D::BYTORDP(int d=0)   const;  // Binary byte order
int    XWin2D::FT_mod(int d=0)    const;  // How FFT is performed
double XWin2D::LB(int d=0)        const;  // Line Broadening
int    XWin2D::MC2(int d=0)       const;  // FT type on t1
double XWin2D::OFFSET(int d=0)    const;  // Spectrum offset
double XWin2D::PHC0(int d=0)      const;  // Zero order phase
double XWin2D::PHC1(int d=0)      const;  // 1st order phase
int    XWin2D::PH_mod(int d=0)    const;  // Phasing type
int    XWin2D::REVERSE(int d=0)   const;  // Plot spectrum reverse
double XWin2D::SF(int d=0)        const;  // Spectrometer frequency
int    XWin2D::SI(int d=0)        const;  // Data size (re+im)
int    XWin2D::SSB(int d=0)       const;  // Sine bell
int    XWin2D::STSI(int d=0)      const;  // Strip size
int    XWin2D::STSR(int d=0)      const;  // Strip start
double XWin2D::SW_p(int d=0)      const;  // Spectral width (PPM)
double XWin2D::TDeff(int d=0)     const;  // Effective FFT size
int    XWin2D::WDW(int d=0)       const;  // Window function
 
/*                   ACCESS FUNCTIONS ON THIS LEVEL ONLY                     */

std::string XWin2D::name()  const;
double XWin2D::Field() const;


/* -------------------------------------------------------------------------- 
                          Functions To Specify Parameters
   --------------------------------------------------------------------------*/

/*                NOT REALLY INHERITED FROM CLASS XWinAcqPar
                         (Applies To Acqs and Acq2s)                         */
 
void XWin2D::AQ_mod(int aqmo, int d=0);		// Acquisiiton mode
//void XWin2D::BF1(double bf, int d=0);		// 1st/2nd channel Omega
//void XWin2D::BF2(double bf, int d=0);		// 2nd/1st channel Omega
//void XWin2D::BYTORDA(int bo, int d=0);	// Bin. byte order <=== arch
int  XWin2D::D(int idx, double tsec, int d=0, int warn=2);
void XWin2D::DS(int ds, int d=0);		// Dummy scans
void XWin2D::EXP(const std::string& exp, int d=0);	// Experiment name
void XWin2D::XW_IN(int i, double in, int d=0);	// Delay increments
void XWin2D::O1(double of, int d=0);		// 1st/2nd channel offset
void XWin2D::O2(double of, int d=0);		// 2nd/1st channel offset
//void XWin2D::NAME(const std::string& n, int d=0);	// File name <===== on output
void XWin2D::NS(int ns, int d=0);		// Number of scans
//void XWin2D::NUC(int i, const std::string& N, int d=0);
void XWin2D::NUCLEI(int channel, const std::string& I, double O, int warn=2);
//void XWin2D::NUCLEUS(const std::string& I, int d=0);
int  XWin2D::P(int idx, double tp, int d=0, int warn=2);
//void XWin2D::PARMODE(int pm, int d=0);	// Data dimension <======== 2
void XWin2D::PULPROG(const std::string& P, int d=0);	// Pulse program
void XWin2D::SFO1(double sf, int d=0);		// 1st/2nd channel spec. freq.
void XWin2D::SFO2(double sf, int d=0);		// 2nd/1st channel spec. freq.
//void XWin2D::SFO3(double sf, int d=0);	// 3rd channel spec. freq.
//void XWin2D::SFO(double sf, int i, int d=0);	// Spectrometer frequencies
void XWin2D::SOLVENT(const std::string& S, int d=0);	// Solvent type
void XWin2D::SW(double sw, int d=-1);		// Spectral width in ppm 
void XWin2D::SW_h(double sw, int d=-1);		// Spectral width in Hz
//void XWin2D::TD(int npts, int d=0);		// Set size <======= on output
void XWin2D::TE(double te, int d=0);		// Set temperature
 
/*                  NOT REALLY INHERITED FROM CLASS XWinProcPar
                           (Applies To Procs and Proc2s)                    */

//void XWin2D::BYTORDP(int bo, int d=0);	// Bin. byte order <===== arch
void XWin2D::FT_mod(int ft, int d=-1);		// Set transform type 
void XWin2D::FT_mod(const std::string& ft, int d=0);	// Set transform type
void XWin2D::GB(int gb,  int d=-1);		// Set Gaussian broadening
void XWin2D::LB(int lb,  int d=-1);		// Set line broadening
void XWin2D::MC2(int mc, int d=0);		// Set acquisition type (t1)
void XWin2D::MC2(const std::string& mc, int d=0);	// Set acquisition type (t1)
void XWin2D::PHC0(double ph0,  int d=-1);	// Set 0th order phase correct
void XWin2D::PHC1(double ph1,  int d=-1);	// Set 1st order phase correct
void XWin2D::PH_mod(const std::string& p, int d=-1);	// Set type of phase correct
void XWin2D::REVERSE(int yn, int d=-1);		// Set spectrum reverse
//void XWin2D::PPARMOD(int pm, int d=0);	// Data dim. <============== 2
//void XWin2D::SI(int si, int d=0);		// Set data size (re+im)
//void XWin2D::SF(double SF, int d=0);		// Set spectrometer freq.
//void XWin2D::SR(double SR, int d=0);		// Ref. freq. <========= BF-SF
void XWin2D::SSB(int sb, int d=0);		// Sine offset (pi/sb)
//void XWin2D::STSI(int sb, int d=0);		// Strip size
//void XWin2D::STSR(int sr, int d=0);		// Strip start
//void XWin2D::SW_p(double swp, int d=0);	// SW (ppm) <========= acqus SW
void XWin2D::WDW(int wd, int d=-1);		// Set window function
void XWin2D::WDW(const std::string& wd, int d=-1);	// Set window function

/*                   ACCESS FUNCTIONS ON THIS LEVEL ONLY                     */  
 
void XWin2D::Field(double Bo);
void XWin2D::Field(double Om, const std::string& I);
void XWin2D::OldMeta(int om);

 

// ____________________________________________________________________________
// C                 XWinNMR 2D Data Set Input Functions
// ____________________________________________________________________________

/* These functions will read part, or the entire, Bruker XWinNMR 2D Data Set. 

                           __ acqu, acqu2 (changable parameter files)
			  / 
                         /___ acqus, acqu2s (static parameter files)
			/
   expname -- expnum --< ---- ser (binary data)
			\
			 \--- pdata -- 1 -- proc, proc2, procs, proc2s, meta

   Here expname is the base directory containing the data set. The number
   expnum is the experiment number an will default to 1. The acquisition
   parameters are taken from the file acqus and the acquisition binary
   points from fid.  The processed data, if accessed, will come from the
   parameter files procs, meta, etc. and binary data files 1r and 1i.

                       INHERITED FROM CLASS XWinSer

   Function   Arguments              Action                       Return
   --------  ------------  -----------------------------------  ----------
   readFID   fn,TD,bytord  Read 1st block in serial/FID file    row_vector
   readFID   fn,TD,bord,i  Read ith block in serial/FID file    row_vector
 + readFID   idx           Read block of index idx(-1=current)  row_vector
   readFIDs  fn,TD,bytord  Read entire serial file                matrix
 + readFIDs                Read entire serial file                matrix
		    
	     Above +=File Must Be Properly Opened For Reading

row_vector XWinSer::readFID(const std::string& fin, int TD, int bytord, int idx=-1)
row_vector XWinSer::readFID(int idx=-1)
matrix     XWinSer::readFIDs(const std::string& fin, int TD, int bytord)
matrix     XWinSer::readFIDs()                                               */

row_vector XWin2D::readFID(const std::string& d,int I=-1,int a=1,int p=1,int wn=2);
row_vector XWin2D::readFID(int idx, int warn=2);

// ____________________________________________________________________________
// D                 XWinNMR 2D Data Set Output Functions
// ____________________________________________________________________________

/* These functions will write an entire Bruker XWinNMR 2D Data Set. 

                           __ acqu, acqu2  (changable parameter files)
			  / 
                         /___ acqus, acqu2s (static parameter file)
			/
     expname -- Aidx --< ---- ser (binary data)
			\
			 \--- pdata -- Pidx -- proc, procs, proc2, proc2s

   Here expname is the base directory specified for output. The numbers Aidx
   and Pidx default to 1.  The produced files are all ASCII except ser. The
   files acqu and acqus will be equivalent as will acqu2-acqu2s, proc-procs,
   and proc2-proc2s.  All files in pdata, since this class will NOT do any
   OUTPUT of frequency domain 2D data, will be defaults based on values in
   acqus and acqu2s. 

   Function  Arguments                         Result
   ________  _________  _______________________________________________________
    write    dir,mx,i     XWinNMR 2D data set produced in dir with data mx 

   Note that GAMMA handles only some of the ASCII parameters one might want
   set in these data sets (# dimensions, # blocks, block size,...). Thus users
   should set additional parameters prior using these functions if values other
   than defaults are desired.  Suggested parameters one might set are:

   Parmeter File  Parameter                    Settings
   _____________  _________  __________________________________________________
    acqu,acqus     AQ_mod    0=qf=one channel, 1=qsim=quadrature simultaneous
			     2=qseq=quadrature sequential, 3=digital quadrature
                   BF1,BF2   Base frequencies in MHz
                   O1,O2     Offset frequencies in Hz
                  SFO{1,2,3} Spectrometer frequencies in MHz
		  SW, SW_h   Spectral Width (PPM, Hz)
									     */

int XWin2D::write(const std::string& Bdir, const matrix& data, int warn=2);
//int XWin2D::write(const row_vector& data, int warn=2);


// ____________________________________________________________________________ 
// E                 XWinNMR 2D Data Set ASCII Output Functions
// ____________________________________________________________________________

/* These functions allow for a quick output of the data set contents. They
   don't have anything to do with output while running XWinNMR, rather users
   may just glance at acquisition parameters & values or store then in a 
   small file if needed.  The two function "dpa" and "dpp" mimick the output
   that would be seen in XWinNMR.                                            */

std::ostream& XWin2D::dpa(std::ostream& ostr, const std::string& dirin);
std::ostream& XWin2D::dpa(std::ostream& ostr) const;
std::ostream& XWin2D::dpp(std::ostream& ostr, const std::string& dirname);
std::ostream& XWin2D::dpp(std::ostream& ostr) const;

       std::ostream& print(std::ostream& out, int full=1) const;
friend std::ostream& operator<<(std::ostream& out, const XWin2D& XW2D);
 
        // Input                out      : output stream;
        //                      XW2D     : XWinNMR 2D Data Set
        // Output               none     : Modifies output stream


// ____________________________________________________________________________
// F              XWinNMR 2D Data Set Interactive Functions
// ____________________________________________________________________________


//std::string XWin2D::ask_read(int argc, char* argv[], int& argn, int idx=1);

	// Input                XW2D : An XWinNMR 2D data set
	//                      argc    : Number of arguments
	//                      argv    : Vector of argc arguments
	//                      argn    : Argument index
	//			idx	: Flag to request expt #
	//			           idx < 1: Ask for it
	//			           idx >=1: Use idx itself def (1)
	// Output               dirname : The parameter argn of array argc
	//                                is used to supply a directory name
	//                                from which the 2D data set resides
	//                                If the argument argn is not in argv,
	//                                the user is asked to supply a name
	//				  and experiment number
	//                                The directory is returned
	// Note                         : The directory should contain an
	//				  XWinNMR 2D data set.
};

#endif 							// XWin2D.h
