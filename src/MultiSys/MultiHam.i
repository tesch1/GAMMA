/* MultiHam.i */

%{
#include "MultiSys/MultiHam.h"
%}


gen_op Ho(const multi_sys &msys);
gen_op Hcs(const multi_sys &msys);
gen_op HJ(const multi_sys &msys);
gen_op Hcs_lab(const multi_sys &msys);
