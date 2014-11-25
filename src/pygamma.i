%module pygamma

%{
#include <cstddef>
%}

%include "Basics/basics.i"
%include "Matrix/matrix_inc.i"
%include "Bloch/bloch_inc.i"
%include "Level1/level1.i"
%include "HSLib/hslib.i"
%include "LSLib/lslib.i"
%include "Level2/level2.i"
%include "Pulses/pulses.i"
%include "Gradients/gradients.i"
%include "BWRRelax/bwrrelax.i"
%include "MultiSys/multisys_inc.i"

