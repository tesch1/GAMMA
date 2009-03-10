/* GgnuplotC.h **************************************************-*-c++-*-
**                                                                      **
**                                 G A M M A                            **
**                                                                      **
**      Gnuplot Controls                           Interface		**
**                                                                      **
**      Scott A. Smith							**
**      Copyright (c) 2002						**
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
**  Description                                                         **
**                                                                      **
** This class does bookkeeping for the GAMMA gnuplot functions. They	**
** allow the user to set aspects of Gnuplot output that will apply in	**
** all functions.							**
**                                                                      **
*************************************************************************/

#ifndef GgnuplotC_h_			// Is this file already included?
#  define GgnuplotC_h_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the interface
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <Matrix/row_vector.h>		// Know GAMMA row vectors
#include <Matrix/matrix.h>		// Know GAMMA matrices
#include <Level1/coord_vec.h>		// Know GAMMA coordinate vectors
#include <string>                       // Know libstdc++ strings
#include <vector>                       // Know libstdc++ STL vectors
#include <list>                         // Know libstdc++ STL lists

class GPControls 			// Gnuplot controls
  {
  std::ofstream Lfp, Dfp;		// Ouptut streams (ASCII) 
  std::string datafile;			// Gnuplot data file name
  std::string loadfile;			// Gnuplot loadfile name
  std::vector<std::string> datafiles;	// Additional output files

  std::string plottitle;		// Label for plot
  std::string xlabel;			// Label for xaxis
  std::string ylabel;			// Label for yaxis
  std::string zlabel;			// Label for zaxis
  std::string delim;			// Data column delimiter

  bool parametric;			// Flag for parametric (yes/no)
  bool nokey;				// Flag for key (yes/no)

  std::string term;			// Terminal type
  std::string basedir;			// Base directory
  std::string macro;			// Macro local filename
  std::string data;			// ASCII data local filename
  std::string outfile;			// Output filename
  std::string basename;			// Base filename
  std::string cmd;			// System command 
  std::string tics;				// Tics in vs out
 
  bool border;				// Border flag (yes/no)
  bool join;				// Line draw flag (yes/no)
  bool xtics;				// X-axis tic flag (yes/no)
  bool ytics;				// Y-axis tic flag (yes/no)
  int  xaxis;				// X-axis tic flag (yes/no)
  int  yaxis;				// Flag for y-axis draw (yes/no)

  double xmin;				// XY plot x minimum value
  double xmax;				// XY plot x maximum value
  double cutoff;			// XY plot intensity resolution
  bool   compress;			// XY plot data compression
  double riflag;			// XY plot {real,imag,complex} flag
  double xsize;				// X-axis scaling factor
  double ysize;				// Y-axis scaling factor



// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// i                      GAMMA Gnuplot Error Handling
// ____________________________________________________________________________
 
/*         Input                eidx    : Error index
                                pname   : string in message
                                noret   : Flag for return (0=linefeed)
           Output               none    : Error message output
                                          Execution stopped (if fatal)       */  
 
         void GPControls::GPCerror(int eidx,                            int noret=0);
         void GPControls::GPCerror(int eidx,  const std::string& pname, int noret=0);
volatile void GPControls::GPCfatal(int eidx);
volatile void GPControls::GPCfatal(int eidx,  const std::string& pname);

//____________________________________________________________________________
// ii                        Gnuplot Structure Functions
//____________________________________________________________________________

void GPControls::defaults();
void GPControls::copy(const GPControls& GPC);

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

  public:

  friend class GPSphere;

// ____________________________________________________________________________
// A           Gnuplot Controls Contruction, Assigment, Destruction 
// ____________________________________________________________________________


// ----------------------------------------------------------------------------
//                  Simple Constructors That Don't Do Much
// ----------------------------------------------------------------------------

MSVCDLC GPControls::GPControls();				// Default controls
MSVCDLC GPControls::GPControls(const GPControls& GPC);		// Duplicate controls

MSVCDLC virtual GPControls::~GPControls();
MSVCDLL GPControls& GPControls::operator= (const GPControls& GPC);

// ____________________________________________________________________________
//                        Gnuplot Load File Basics
// ____________________________________________________________________________

MSVCDLL bool GPControls::NewLoadFile(bool warn=true);
MSVCDLL void GPControls::CloseLoadFile();
MSVCDLL void GPControls::RunLoadFile();

// ____________________________________________________________________________
//                        Gnuplot Data File Basics
// ____________________________________________________________________________

MSVCDLL bool GPControls::NewDataFile(int idx=-1, bool warn=true);
MSVCDLL void GPControls::CloseDataFile();

// ____________________________________________________________________________
//            Gnuplot Controls Gnuplot Loadfile Output Commands
// ____________________________________________________________________________

MSVCDLL void GPControls::SetLoadFile(const  std::string& lfn);
MSVCDLL void GPControls::SetDataFile(const  std::string& dfn);
MSVCDLL void GPControls::SetDataFiles(const std::vector<std::string>& dfs);
MSVCDLL void GPControls::SetDelimiter(const std::string& dlt);
MSVCDLL void GPControls::SetParametric( bool par);
MSVCDLL void GPControls::SetKey(        bool key);
MSVCDLL void GPControls::SetBorder(     bool bord);
MSVCDLL void GPControls::SetXTics(      bool xt);
MSVCDLL void GPControls::SetYTics(      bool yt);

// ____________________________________________________________________________
//            Gnuplot Controls Gnuplot Loadfile Output Commands
// ____________________________________________________________________________

MSVCDLL void GPControls::WriteParametric(std::ofstream&  ostr);
MSVCDLL void GPControls::WriteBorder(std::ofstream& ostr);
MSVCDLL void GPControls::WriteKey(std::ofstream&    ostr);
MSVCDLL void GPControls::WriteXLabel(std::ofstream& ostr);
MSVCDLL void GPControls::WriteYLabel(std::ofstream& ostr);
MSVCDLL void GPControls::WriteZLabel(std::ofstream& ostr);
MSVCDLL void GPControls::WriteXTics(std::ofstream&  ostr);
MSVCDLL void GPControls::WriteYTics(std::ofstream&  ostr);
MSVCDLL void GPControls::WritePause(std::ofstream&  ostr);

// ____________________________________________________________________________
//            Loadfile Output Commands For Spherical 3D Plots
// ____________________________________________________________________________



// ____________________________________________________________________________
// Z              Gnuplot Controls Standard Output Functions
// ____________________________________________________________________________

MSVCDLL virtual std::ostream& GPControls::print(std::ostream& ostr, bool phdr=true);
MSVCDLL friend  std::ostream& operator<< (std::ostream& ostr, GPControls& GPC);


  };
#endif 								// GgnuplotC.h
