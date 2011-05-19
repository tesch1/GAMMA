/* nmr_tensor.i */
// Swig interface file.

%{
#include "Level1/nmr_tensor.h"
%}

MSVCDLL spin_T T_D(const spin_sys &sys, int spin1, int spin2);

MSVCDLL spin_T T_D(const spin_sys &sys, spin_op &Im1, spin_op &Iz1, spin_op &Ip1,
				spin_op &Im2, spin_op &Iz2, spin_op &Ip2);

MSVCDLL spin_op T_D(const spin_sys &sys, int spin1, int spin2, int m);

MSVCDLL spin_T T_CSA(const spin_sys &sys, int spin);

MSVCDLL spin_T T_CS2(const spin_sys &sys, int spin);

MSVCDLL spin_T T_CS2(const spin_sys &sys, int spin, coord &B);

MSVCDLL spin_op T_CS2(const spin_sys &sys, int spin, coord &B, int l, int m);

MSVCDLL spin_T T_CS(const spin_sys &sys, int spin);

MSVCDLL spin_op T_CS(const spin_sys &sys, int spin, int m);

MSVCDLL spin_T T_RF(const spin_sys &sys, int spin);

MSVCDLL spin_op T_RF(const spin_sys &sys, int spin, int l, int m);

MSVCDLL spin_T T_Q(const spin_sys &sys, int spin);

MSVCDLL spin_op T_Q(const spin_sys &sys, int spin, int l, int m);
