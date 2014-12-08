/* cosy1.cc *******************************************************************-*-c++- *-
**
**
** Example program for the GAMMA Library
**
**
**
** This program simulates a basic COSY experiment.
**
** No phase cycling is performed and all input are
**
** kept positive to avoid the need for quadrature
**
** detection in t1.
**
**
**
**************************************************************************************** */
#include <gamma.h>
int main(int argc, char *argv[])
{
  const char * sysfile = "cosy.1.sys";
  const char * outfile = "cosy.1.mat";
  if (argc > 1)
    sysfile = argv[1];
  if (argc > 2)
    outfile = argv[2];

  //
  //  DEFINE SYSTEM & NMR PARAMETERS
  const double dt1 = 0.001;     // t1 time increment
  const double dt2 = 0.001;     // t2 time increment
  const int t1pts = 1024;       // points on t1 axis
  const int t2pts = 1024;       // points on t2 axis
  spin_system sys;              // define the system, 
  sys.read(sysfile);            // read in from disk

  //
  //  SET UP NECESSARY VARIABLES
  block_1D tmp(t2pts);          // 1D-data block storage
  block_2D data(t1pts, t2pts);  // 2D-data matrix storage
  gen_op H = Hcs(sys) + HJw(sys); // Hamiltonian, weak coupling
  gen_op detect = Fm(sys);      // F- for detection operator
  gen_op sigma0, sigma1, sigma; // working density matrices

  //
  //      APPLY PULSE SEQUENCE
  sigma0 = sigma_eq(sys);               // equilibrium density matrix
  sigma1 = Iypuls(sys, sigma0, 90);     // apply first 90 y-pulse
  for (int t1 = 0; t1 < t1pts; t1++) {  // loop over t1 points
    sigma = evolve(sigma1, H, t1 * dt1);// evolution during t1
    sigma = Iypuls(sys, sigma, 90);     // apply second 90 y-pulse
    FID(sigma, detect, H, dt2, t2pts, tmp); // acquisition
    data.put_block(t1, 0, tmp);         // store it in a 2D block
  }
  MATLAB(outfile, "cosy", data);   // output for MATLAB
  //matrix Hm = H;
  //MATLAB(outfile, "H", data);   // output for MATLAB
}
