/* MultiLib.h ***************************************************-*-c++-*-
**                                                                      **
**                                G A M M A                             **
**                                                                      **
**      Multiple System Library		               Interface	**
**                                                                      **
**      Copyright (c) 1995                                              **
**      Nikolai Skrynnikov                                              **
**      Dr. Scott A. Smith                                              **
**      National High Magnetic Field Laboratory                         **
**      1800 E. Paul Dirac Drive                                        **
**      Tallahassee Florida, 32306-4005                                 **
**                                                                      **
**      $Header: $
**                                                                      **
*************************************************************************/

/*************************************************************************
**                                                                      **
** This module of function supports the multi_sys, the GAMMA class      **
** handling mulitple spin systems.  The routines herein generally       **
** involve such a spin system and build up common operators, in this    **
** case in a direct product space of the systems involved.              **
**                                                                      **
*************************************************************************/

#ifndef MultiLib_h			// Is the file already included?
#define MultiLib_h_ 1			// If no, then remember it
#  if defined(GAMPRAGMA)				// Using the GNU compiler?
#    pragma interface			// Then this is the interface
#endif

#include <HSLib/GenOp.h>		// Knowledge of operators
#include <LSLib/SuperOp.h>		// Knowledge of superoperators
#include <Matrix/row_vector.h>		// Knowledge of row vectors
#include <MultiSys/MultiSys.h>
#include <HSLib/SpinSystem.h>
#include <LSLib/sys_dynamic.h>

 
// ____________________________________________________________________________
//             GENERAL PRODUCTION OF MULTISPIN SYSTEM OPERATORS
// ____________________________________________________________________________

// ----------------------------------------------------------------------------
//  Generic Functions For Making Primitive Operators in Composite Space
// ----------------------------------------------------------------------------

gen_op multize(gen_op OpFct(const spin_system &sys), const multi_sys &msys); 

        // Input                OpFct   : A function of sys returning Op
        //                      msys    : A multi_spin spin system
        // Output       	MOp     : Operator for multi_sys msys
        // Note                         : Forms composite space operator
	//				  for msys from function OpFct
        // Note				: Routine calls a function with
	//				  the name OpFct of the form
        //                                 gen_op OpFct(spin_system&)
        //				  msys will supply the system 


gen_op multize(gen_op& Op, const multi_sys &msys, int icomp);

        // Input        Op      : An operator
        //              msys    : A multi_sys spin system
        //              icomp   : Component index
        //              MOp     : Operator in the composite space of msys
        //                        for the specified component icomp

 
// ----------------------------------------------------------------------------
//                 Generic Functions Which Involve Spin Operators
//                  (Often These Are Rotations Or Spin Operators)
// ----------------------------------------------------------------------------
 
gen_op multize(spin_op op(const spin_sys&), const multi_sys &msys);
 
        // Input        op      : Function which returns a
        //                        spin operator given a system
        //              msys    : A multi_sys spin system
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        spin_op Name(const spin_sys&)
        //                        where line will be the string input
        // Example              : Fx(sys)


gen_op multize(spin_op op(const spin_sys&, const std::string&),
                                         const std::string&, const multi_sys&);
// ----------------------------------------------------------------------------

        // Input        op      : Function which returns a spin
        //                        operator given a system, and string
        //              String  : Density operator
        //              msys    : A multi_sys spin system
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function 
        //                        of the following form
        //                        spin_op Name(const spin_sys&, const string&)
        //                        where String will be the argument


gen_op multize(spin_op op(const spin_sys&, double),
                             double beta, const multi_sys &msys, int icomp=-1);

        // Input        sop      : Function which returns a
        //                        spin operator given a system
        //                        &  a double double
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator sop for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        spin_op Name(const spin_sys&, double)
        //                        where beta will be the argument
        // Example              : Rz(sys, 90.0)

 

// ----------------------------------------------------------------------------
//           Generic Functions Which Take A Density Operator
//            (Often These Are Evolution Or Pulse Functions)
// ----------------------------------------------------------------------------

gen_op multize(gen_op op(const spin_sys&, const gen_op&, double),
	                      gen_op&, double, const multi_sys&, int icomp=-1);

        // Input        op      : Function which returns an
        //                        operator given a system, operator,
        //                        & double
        //              sigma   : Density operator
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function 
        //                        of the following form
        //                        gen_op Name(const spin_sys&, gen_op&, double)
        //                        where sigma and beta will be the arguments
        // Example              : Iypuls(sys, sigma, "13C", 90.0)
 

gen_op multize(gen_op op(const spin_sys&, const gen_op&, int, double),
                         gen_op&, int, double, const multi_sys&, int icomp=-1);
 
        // Input        op      : Function which returns an
        //                        operator given a system, operator,
        //                        integer & double
        //              sigma   : Density operator
        //              nspin   : Spin index
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        gen_op Name(const spin_sys&, gen_op&, int, double)
        //                        where sigma, nspin and beta will be the arguments
        // Example              : Iypuls(sys, sigma, 1, 90.0)


gen_op multize(gen_op op(const spin_sys&,const gen_op&,const std::string&, double),
               gen_op&, const std::string&, double, const multi_sys&, int icomp=-1);

        // Input        op      : Function which returns an 
        //                        operator given a system, operator, 
        //                        string & double 
        //              sigma   : Density operator 
        //              iso     : Isotope channel
        //              beta    : Rotation angle 
        //              msys    : A multi_sys spin system 
        //              icomp   : System components affected (-1 = all) 
        // Output       MOp     : Operator op for multi_sys msys 
        //                        in the direct product Hilbert space 
        // Note                 : This routine calls an arbitrary function 
        //                        of the following form 
        //                        gen_op Name(const spin_sys&, gen_op&, const string&, double) 
        //                        where sigma, nspin and iso will be the arguments    
        // Example              : Iypuls(sys, sigma, "13C", 90.0)


// ----------------------------------------------------------------------------
//           Generic Functions Which Take No Density Operator
//          (Often These Are Propagator or Rotation Functions)
// ----------------------------------------------------------------------------


gen_op multize(gen_op op(const spin_sys&, int, double),
               int nspin, double beta, const multi_sys &msys, int icomp=-1);

        // Input        op      : Function which returns an
        //                        operator given a system, operator,
        //                        string & double
        //              nspin   : Spin index
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        gen_op Name(const spin_sys&, int, double)
        //                        where nspin and beta will be the arguments
        // Example              : Iypuls_U(sys, 1, 90.0)


gen_op multize(gen_op op(const spin_sys&, const std::string& iso, double),
               const std::string& iso, double beta, const multi_sys &msys, int icomp=-1);
 
        // Input        op      : Function which returns an
        //                        operator given a system, operator,
        //                        string & double
        //              iso     : Isotope channel
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        gen_op Name(const spin_sys&, const string&, double)
        //                        where iso and beta will be the arguments
        // Example              : Iypuls_U(sys, "13C", 90.0)

 
gen_op multize(gen_op op(const spin_sys&, double),
               double beta, const multi_sys &msys, int icomp=-1);

        // Input        op      : Function which returns an
        //                        operator given a system, operator,
        //                        string & double
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        gen_op Name(const spin_sys&, double)
        //                        where beta will be the argument
        // Example              : Iypuls_U(sys, 90.0)
 

gen_op multize(gen_op op(const spin_sys&, double, double),
               double phi, double beta, const multi_sys &msys, int icomp=-1);
 
        // Input        op      : Function which returns an
        //                        operator given a system, operator,
        //                        string & double
        //              phi     : Phase angle 
        //              beta    : Rotation angle
        //              msys    : A multi_sys spin system
        //              icomp   : System components affected (-1 = all)
        // Output       MOp     : Operator op for multi_sys msys
        //                        in the direct product Hilbert space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form
        //                        gen_op Name(const spin_sys&, double, double)
        //                        where iso and beta will be the arguments
        // Example              : Ixypuls_U(sys, 90.0, 90.0)


// ----------------------------------------------------------------------------
//                  Generic Functions Which Use Superoperators
//              (Often These Are Relaxation Or Exchange Functions)
// ----------------------------------------------------------------------------

super_op multize(super_op SOpFct(const gen_op&), const gen_op& Op, const multi_sys& msys);
 
        // Input        SOpFct  : Function which returns a  superoperator
        //                        given an operator as its only argument
        //              Op      : An operator
        //              msys    : A multi_sys spin system
        // Output       MSOp    : Superoperator SOp for multi_sys msys
        //                        in the direct product Liouville space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form 
        //                              super_op SOpFct(gen_op& Op) 
        //                        where Op is the only function arguments
        //                        and SopFct is the name of the function
        // Note                 : There is no check herein to insure that
        //                        the composite space of Op is the same
        //                        as that which is the default of msys 
 

super_op multize(super_op sop(const sys_dynamic&,gen_op&,int,int), gen_op&,
                                                    int, int, const multi_sys&);

        // Input        sop     : Function which returns an  
        //                        superoperator given a system, operator,  
        //                        and two integers
        //              H       : An operator (isotropic Hamiltonian)  
        //              type    : Computation type  
        //              level   : Computation level 
        //              msys    : A multi_sys spin system  
        // Output       MSOp    : Superoperator op for multi_sys msys  
        //                        in the direct product Liouville space 
        // Note                 : This routine calls an arbitrary function  
        //                        of the following form  
        //                        super_op Name(sys_dynamic&, gen_op&, int, int) 
        //                        where H, type and level will be the arguments     
 

super_op multize(super_op sop(const sys_dynamic&,gen_op&,int), gen_op&,
                                                         int, const multi_sys&);
 
        // Input        sop     : Function which returns an 
        //                        superoperator given a system, operator,
        //                        and an integer  
        //              H       : An operator (isotropic Hamiltonian)
        //              level   : Computation level 
        //              msys    : A multi_sys spin system 
        // Output       MSOp    : Superoperator op for multi_sys msys
        //                        in the direct product Liouville space
        // Note                 : This routine calls an arbitrary function
        //                        of the following form 
        //                        super_op Name(sys_dynamic&, gen_op&, int, int)
        //                        where H, type and level will be the arguments

// ____________________________________________________________________________
//                PRODUCTION OF MULTISPIN SYSTEM SUPEROPERATORS
// ____________________________________________________________________________
 

basis D_basis(const multi_sys& msys);

row_vector LS_qState_bra(const multi_sys& msys, int i);

row_vector LS_qState_ket(const multi_sys& msys, int i);

super_op Xnm(const multi_sys& msys);


#endif						// multi_lib.h
