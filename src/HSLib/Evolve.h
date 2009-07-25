// evolve.h

#ifndef _evolve_h_20090721_1620_
#define _evolve_h_20090721_1620_

#  if defined(GAMPRAGMA)		// Using the GNU compiler?
#    pragma interface			  // this is the interface
#  endif

#include <GamGen.h>			    // Know MSVCDLL (__declspec)
#include <HSLib/GenOp.h>		// Know operator information

class Evolve
{

public:

static gen_op prop(const gen_op& ham, double time); 

static void prop_ip(gen_op& U, double time);

static gen_op evolve(const gen_op& sigma, const gen_op& ham, double time);

static void evolve_ip(gen_op& sigma, const gen_op& ham, double time);

static gen_op evolve(const gen_op& sigma, const gen_op& U);

static void evolve_ip(gen_op& sigma, const gen_op& U);

};

#endif // end of #ifndef evolve_h_20090721_1620_
