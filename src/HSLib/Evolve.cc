// evolve.cc


#include <HSLib/Evolve.h>

using namespace Evolve;

// ______________________________________________________________________
// F                      PROPAGATOR FUNCTIONS
// ______________________________________________________________________

// These are from before the invention of propagators.  The will one day
//   become deprecated.  For now the are just "friend" functions of this
//   class and gleaned from what used to be nmrlib.cc                     


        //                      ham   : "Hamiltonian" for propagation (in Hertz)
        //                      time  : Evolution time (seconds)
        // Output               U     : Propagator for the input Hamiltonian
        //                      ham   : "Hamiltonian" for propagation (in Hertz)
        //                      time  : Evolution time (seconds)
        // Output               U     : Propagator for the input Hamiltonian
        // Note                       : Done in place, overwriting ham
 

gen_op prop(const gen_op& ham, double time)
  {
  ham.set_EBR();                        // Put ham into its eigenbase
  complex z(0,-PIx2*time);		// Exponential factor (rad->Hz)
  return ham.exp(z);			// Generate evolution propagator
  }
        
void prop_ip(gen_op& U, double time)
  {
  U.set_EBR();                          // Put ham into its eigenbase
  complex z(0,-PIx2*time);		// Exponential factor (rad -> Hz)
  U = U.exp(z);                         // Generate evolution propagator
  }

// ____________________________________________________________________________
// G                      EVOLUTION  FUNCTIONS
// ____________________________________________________________________________
 
/* This set of functions were in GAMMA before the addition of this propagator
   class.  They will one day become deprecated.  For now the are just "friend"
   functions of this class and gleaned from what used to be nmrlib.cc        */ 

// ----------------------------------------------------------------------------
//                   EVOLUTION UNDER A STATIC HAMILTONIAN
// ----------------------------------------------------------------------------
 
        // Input                sig   : Op to be propagated (dens. mx.)
        //                      ham   : Op for propagation (in Hertz)
        //                              (usually a static Hamiltonian)
        //                      time  : Evolution time (seconds)
        // Output               sigma1: Sigma evolved by ham for time
        //                              EITHER to new or in place (ip)
        // Note                       : Sigma is set to the EB of U & ham
        //                              inside sim_trans. This is also the
        //                              basis in which the computation is done
        // Note                       : As propagator U is unitless & the exp
        //                              argument is in radians, 2*PI is used

gen_op evolve(const gen_op& sigma, const gen_op& ham, double time)
  {
  if(!ham.exists()) return sigma; 	// No ham, no change in sigma
  gen_op U = prop(ham,time);		// Construct HS propagator
  return U.sim_trans(sigma);		// Return sigma evolved by U
  }

void evolve_ip(gen_op& sigma, const gen_op& ham, double time)
  {
  if(!ham.exists()) return;             // Do nothing if no Hamiltonian
  gen_op U = prop(ham,time);		// Construct HS propagator
  sigma.sim_trans_ip(U);                // Evolve density matrix
  return;                               // Return
  }

// ----------------------------------------------------------------------------
//                EVOLUTION UNDER A HILBERT SPACE PROPAGATOR
// ----------------------------------------------------------------------------
 
        // Input                sigma : Op to be propagated (unitless)
        //                      U     : Propagator (unitless)
        // Output               sigma1: Op propagated by U to either make a
        //                              new density operator or in place (ip)
        // Note                       : If U is in its EB, sigma set to U EB
        //                              inside sim_trans. This is then the
        //                              basis in which the computation is done
        //                              If U not in its EB it is put into the
        //                              EB of sigma and the computation done
        //                              in that eigenbase

gen_op evolve(const gen_op& sigma, const gen_op& U)
  {
  if(!U.test_EBR()) 
    U.Op_base(sigma);   // Put U in sigma's basis unless EBR
  return U.sim_trans(sigma);            // Return propagated sigma
  }
 
void evolve_ip(gen_op& sigma, const gen_op& U)
  {
  if(!U.test_EBR()) U.Op_base(sigma);   // Put U in sigma's basis unless EBR
  sigma.sim_trans_ip(U);                // Evolve density matrix
  return;                               // Return sigma1
  }

