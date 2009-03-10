/* GgnuplotSph.h ************************************************-*-c++-*-
**                                                                      **
**                                 G A M M A                            **
**                                                                      **
**      Gnuplot 3D Spherical Plots                   Interface		**
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
**  This file contains the functions that generate 3D spherical plots	**
**  in Gnuplot from GAMMA coordinate vectors. Normally the coordinate	**
**  vector will contain Cartesian coordinates. These are mapped into	**
**  three dimension upon output into a Gnuplot compatible ASCII file.	**
**                                                                      **
*************************************************************************/

#ifndef   GgnuplotSph_h_		// Is this file already included?
#  define GgnuplotSph_h_ 1		// If no, then remember it
#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			// This is the interface
#  endif

#include <GamGen.h>			// Know MSVCDLL (__declspec)
#include <GamIO/GgnuplotC.h>		// Know GAMMA Gnuplot controls
#include <Level1/coord_vec.h>		// Know GAMMA coordinate vectors
#include <string>                       // Know libstdc++ strings
#include <vector>                       // Know libstdc++ STL vectors

class GPSphere: public GPControls	// Gnuplot info
  {
  bool   degrees;			// Flag angles in degrees/radians
  double POVtheta;			// Point of view theta angle
  double POVphi;			// Point of view phi angle
  bool   basesphere;
  bool   sphereaxes;
  double spherescale;
  double zaxisscale;
  bool   spherical;
  bool   hidden;
  bool   dataout;
  bool   normalize;

// ----------------------------------------------------------------------------
// --------------------------- PRIVATE FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

// ____________________________________________________________________________
// i           GAMMA Gnuplot Sphereical 3D Plot Error Handling
// ____________________________________________________________________________

/*         Input                eidx    : Error index
                                pname   : string in message
                                noret   : Flag for return (0=linefeed)
           Output               none    : Error message output
                                          Execution stopped (if fatal)       */

         void GPSphere::GPSerror(int eidx,                            int noret=0);
         void GPSphere::GPSerror(int eidx,  const std::string& pname, int noret=0);
volatile void GPSphere::GPSfatal(int eidx);
volatile void GPSphere::GPSfatal(int eidx,  const std::string& pname);

//____________________________________________________________________________
// ii                        Gnuplot Structure Functions
//____________________________________________________________________________

void GPSphere::defaults();
void GPSphere::copy(const GPSphere& GPS);

// ____________________________________________________________________________
// iii             Gnuplot Spherical 3D Plot Loadfile Output
// ____________________________________________________________________________

void GPSphere::WriteTitle(std::ofstream&   ofstr);
void GPSphere::WriteView(std::ofstream&    ofstr);
void GPSphere::WriteAngles(std::ofstream&  ofstr);
void GPSphere::WriteMapping(std::ofstream& ofstr);
void GPSphere::WriteSplot(std::ofstream&   ofstr);

// ----------------------------------------------------------------------------
// ---------------------------- PUBLIC FUNCTIONS ------------------------------
// ----------------------------------------------------------------------------

  public:

// ____________________________________________________________________________
// A     Gnuplot Spherical 3D Controls Contruction, Assigment, Destruction
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//                  Simple Constructors That Don't Do Much
// ----------------------------------------------------------------------------

MSVCDLC GPSphere::GPSphere();				// Default controls
MSVCDLC GPSphere::GPSphere(const GPSphere& GPS);	// Duplicate controls

MSVCDLC virtual   GPSphere::~GPSphere();
MSVCDLL GPSphere& GPSphere::operator= (const GPSphere& GPS);

// ____________________________________________________________________________
// B              Gnuplot Spherical 3D Control Access
// ____________________________________________________________________________

MSVCDLL void GPSphere::SetDegrees(bool       dg);
MSVCDLL void GPSphere::SetSphereAxes(bool    ax);
MSVCDLL void GPSphere::SetBaseSphere(bool    bs);
MSVCDLL void GPSphere::SetNormalization(bool nm);

// ____________________________________________________________________________
// C              Gnuplot Spherical 3D Loadfile Generation
// ____________________________________________________________________________

MSVCDLL void GPSphere::LoadFile();

// ____________________________________________________________________________
// D              Gnuplot Spherical 3D Datafile Generation
// ____________________________________________________________________________

/* The ASCII data is set into three columns { theta, phi, R }. However, Gnuplot
   takes theta as the angle over from the +x axis - that which GAMMA calls the
   phase angle phi. Gnuplot takes the angle up/down from the XY plane as phi,
   which also contrasts with GAMMA in that we take theta as the angle down from
   the +z axis. So, we need to output {PHI, 90-THETA, R} to keep Gnuplot happy.
   Lastly, we can output out data in either degrees or radians, the later
   being the default.                                                        */

MSVCDLL bool GPSphere::DataAxisFile(char axis, bool warn=true);
MSVCDLL void GPSphere::DataFile(const coord_vec& data, int idx = -1);
MSVCDLL void GPSphere::DataFiles(const std::vector<coord_vec>& data);

// ____________________________________________________________________________
// E             Gnuplot Spherical 3D Plot Output Generation
// ____________________________________________________________________________

/* These functions will generate the Gnuplot load file and one or more ASCII
   data files that will be plotted. Subsequently, the command is issued to
   run gnuplot using the produced load file which reads the data files.      */

MSVCDLL void GPSphere::Plot();
MSVCDLL void GPSphere::Plot(const coord_vec& data);
MSVCDLL void GPSphere::Plot(const std::vector<coord_vec>& data);

// ____________________________________________________________________________
// F         Gnuplot Spherical 3D Controls Standard Output Functions
// ____________________________________________________________________________

MSVCDLL virtual std::ostream& GPSphere::print(std::ostream& ostr);
MSVCDLL friend  std::ostream& operator<< (std::ostream&     ostr, GPSphere& GPS);

// ____________________________________________________________________________
// G                          Non-Member Functions
// ____________________________________________________________________________

/* These are functions built prior to construction of this class. Some of
   them are deprecated and will issue warnings if utilized.                  */

MSVCDLL friend void GP_sphere(const std::string& name, const coord_vec& data, bool old=false);
MSVCDLL friend void GP_sphereplot(const std::string& gnumacro, const std::string& Aname, bool old=false);
MSVCDLL friend void GP_sphereplot(const std::string& gnumacro, int N, std::string* files);
MSVCDLL friend void GnuplotSphere(const std::string& name, const coord_vec& data);

};

// ____________________________________________________________________________
// H                         PyGAMMA Code (Non-Member)
// ____________________________________________________________________________

#ifdef PYGAMMA					// Begin PyGAMMA code block

void PyGgnuplotSph();

#endif						// End of PyGAMMA code block

#endif 								// GgnuplotSph.h
