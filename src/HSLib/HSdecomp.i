/* HSdecomp.i */

%{
#include "HSLib/HSdecomp.h"
%}

void Prod_base_dec(const spin_sys &sys, const gen_op &Op, double thres=BD_SMALL);
