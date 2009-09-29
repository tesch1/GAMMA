/* evolve.i */
// Swig interface file.

%{
#include "HSLib/Evolve.h"
%}


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

