/* MultiLib.cc **************************************************-*-c++-*-
**									**
**                                G A M M A 				**
**									**
**      Multiple System Library		           Implementation	**
**									**
**      Copyright (c) 1995						**
**      Nikolai Skrynnikov						**
**      Dr. Scott A. Smith						**
**      National High Magnetic Field Laboratory				**
**      1800 E. Paul Dirac Drive					**
**      Tallahassee Florida, 32306-4005					**
**									**
**      $Header: $
**									**
*************************************************************************/

/*************************************************************************
**									**
** This module of function supports the multi_sys, the GAMMA class 	**
** handling mulitple spin systems.  The routines herein	generally	**
** involve such a spin system and build up common operators, in this	**
** case in a direct product space of the systems involved.		**
**									**
*************************************************************************/

#ifndef MultiLib_cc			// Is the file already included?
#define MultiLib_cc_ 1			// If no, then remember it
#  if defined(GAMPRAGMA)				// Using the GNU compiler?
#    pragma implementation			// Then this is the implementation
#endif

#include <HSLib/SpinSys.h>
#include <MultiSys/MultiLib.h>		// Include the header file
#include <MultiSys/MultiSys.h>		// Include multi_sys spin systems
//#include <MultiSys/MultiAux.h>		// Include multi_sys auxiliary
#include <HSLib/HSauxil.h>		// Include common sigma_eq
#include <HSLib/HSham.h>		// Include common Hamiltonians
#include <HSLib/PulseI.h>		// Include ideal pulses
#include <HSLib/SpinOp.h>		// Include simple spin operators
#include <HSLib/SpinOpCmp.h>		// Include composite spin operators
#include <HSLib/SpinOpRot.h>		// Include rotation spin operators
#include <HSLib/GenOp.h>		// Inlcude general operators
#include <BWRRelax/relaxDip.h>		// Include dipolar relaxation
#include <BWRRelax/relaxCSA.h>		// Include CSA relaxation
#include <BWRRelax/relaxQuad.h>		// Include quadrupole relaxation
#include <BWRRelax/relaxQCSA.h>		// Include CSA-Quad X-correlation

// ____________________________________________________________________________
// A  Generic Functions For Making Primitive Operators in Composite Space
// ____________________________________________________________________________
// sosi - why does this use n_matrix_type?

/*
                   Function Form                             Example
 --------------------------------------------------- --------------------------
 gen_op Name(const spin_sys&)                        Ho(sys)
 gen_op& Op                                          gen_op H = Hcs(sys)

        Input      OpFct   : A function Returning Op (gen_op)
                   Op      : An operator
                   msys    : A multi_sys spin system
                   icomp   : System components affected (-1 = all)
        Output     MOp     : Operator op for multi_sys msys                  */

gen_op multize(gen_op op(const spin_system&), const multi_sys &msys)
  {
  int nc = msys.NComps();			// Number of components
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;				// Temp spin system
  gen_op op_sys;				// Temp operator
  for(int i=0; i<nc; i++)			// Loop over msys components
    {
    sys = msys.Comp(i);				//   Get component
    op_sys = op(sys);				//   Operator for component
    mxc.push_back(op_sys.get_mx());		//   Matrix for component
    (mxc[i]).set_type(n_matrix_type);		//   It is a normal matrix
    bsc.push_back((op_sys.get_basis()).U());
    }
  gen_op MultiOp(mxc,bsc);			// Make composiste operator
  return MultiOp;				// Return the operator
  }

gen_op multize(gen_op& Op, const multi_sys &msys, int icomp)
  {
// sosi - check that comp exists
  int nc = msys.NComps();			// Number of components
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  int hs;
  sys_dynamic sys;				// Temp spin system
  gen_op OpComp;				// Operator component
  for(int i=0; i<nc; i++)			// Loop over msys components
    {
    hs = msys.HS(i);				// Component Hilbert space
    if(i == icomp)				// If its the specified
      {						// component 
      if(hs != Op.dim())			// Insure proper dim
	{
// sosi - need proper error message here 
        exit(-1);
	}
      mxc.push_back(Op.get_mx());		// Store its matrix 
      bsc.push_back((Op.get_basis()).U());	// Store its basis
      }
    else					// If its not the specified
      {						// component
      matrix mxd(hs,hs,0.,d_matrix_type);	//   Temp diagonal mx
      matrix mxi(hs,hs,i_matrix_type);		//   Temp identity mx
      mxc.push_back(mxd);			//   Matrix rep is zero
      bsc.push_back(mxi);			//   Basis is identity
      }
    }
  return gen_op(mxc, bsc);
  }

// ____________________________________________________________________________
// B      General Operator <=== Spin Operator Function(spin system)
// ____________________________________________________________________________

/*                 (Often These Are Rotations Or Spin Operators)

                    Function Form                             Example
 --------------------------------------------------- --------------------------
 spin_op Name(const spin_sys&)                       Fx(sys)
 spin_op Name(const spin_sys&, const string&)        Fx(sys, 1H)
 spin_op Name(const spin_sys&, double)               Rz(sys, 90.0)

        Input      SOpFct  : A function Returning SOp (spin_op)
                   msys    : A multi_sys spin system
                   double  : Anything (often a pulse angle, e.g. 90.0)
                   string  : Anything (often an isotope name, e.g. "1H")
                   icomp   : System components affected (-1 = all)
        Output     MOp     : Operator op for multi_sys msys
                             that parallels SOpFct but resides in
                             the direct product Hilbert space of msys        */

gen_op multize(spin_op op(const spin_sys&), const multi_sys &msys)
  {
  int nc = msys.NComps();			// Number of components
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  gen_op Op;					// Scratch operator
  for(int i=0; i<nc; i++)			// Loop over spin components
    {
    Op = op(msys.Comp(i));			// Requested Op, component i
    mxc.push_back(Op.get_mx());			// Store its matrix 
    bsc.push_back((Op.get_basis()).U());	// Store its basis
    }
  return gen_op(mxc, bsc);
  }

gen_op multize(spin_op op(const spin_sys&, const string&),
                                     const string& line, const multi_sys &msys)
  {
  int nc = msys.NComps();			// Number of components
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  gen_op Op;					// Scratch operator
  for(int i=0; i<nc; i++)			// Loop over spin components
    {
    Op = op(msys.Comp(i), line);		// Requested Op, component i
    mxc.push_back(Op.get_mx());			// Store its matrix 
    bsc.push_back((Op.get_basis()).U());	// Store its basis
    }
  return gen_op(mxc, bsc);
  }

gen_op multize(spin_op op(const spin_sys&, double),
                                 double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1) msys.CheckComp(icomp);	// Insure component exists
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;				// System for single component
  gen_op op_sys, sigma_sys;
  int subHS=0;
  for(int i=0; i<nc; i++)			// Loop the system components
    {
    sys = msys.Comp(i);			//	Component i (sys dynamic)
//    sigma_sys = sigma.project_sub(i);		//	Density Op this component
    op_sys = gen_op(op(sys, beta));		//	Requested Op this component
    if((icomp == -1) || (i == icomp))		//	Add it if it was selected
      {
      mxc.push_back(op_sys.get_mx());		//	Matrix for operator, comp. i
      bsc.push_back((op_sys.get_basis()).U());	//	Basis for operator, comp. i
      mxc[i].set_type(n_matrix_type);		//	Insure matrix is n_matrix
      bsc[i].set_type(n_matrix_type);		//	Insure basis is n_matrix
      }
    else
      {
      subHS = sys.HS();				//	Hilbert space of component i
      mxc.push_back(matrix(subHS,subHS,i_matrix_type)); // 	Op matrix is I for this component
      bsc.push_back(mxc[i]);			//	Basis is I for this component
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);			// Return in composite space
  }

// ____________________________________________________________________________
// C    General Operator <=== General Operator Function(spin_sys, gen_op)
// ____________________________________________________________________________

/*                (Often These Are Evolution Or Pulse Functions)

                    Function Form                             Example
 --------------------------------------------------- --------------------------
 Name(const spin_sys&,gen_op&,double)                Iypuls(sys, sigma, 90.0)
 Name(const spin_sys&,gen_op&,int, double)           Iypuls(sys, sigma, 1, 90.)
 Name(const spin_sys&,gen_op&,const string&, double) Iypuls(sys,sigma,"1H",90.)

        Input      OpFct   : A function Returning Op (gen_op)
                   msys    : A multi_sys spin system
                   icomp   : System components affected (-1 = all)
                   double  : Anything (often a pulse angle, e.g. 90.0)
                   int     : Anyting (often a spin index)
                   string  : Anything (often an isotope name, e.g. "1H")
        Output     MOp     : Operator op for multi_sys msys
                             that parallels OpFct but resides in
                             the direct product Hilbert space of msys        */

gen_op multize(gen_op op(const spin_sys&, gen_op&, double),
                  gen_op& sigma, double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1) msys.CheckComp(icomp);	// all blocks; otherwise over 
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic dsys;
  gen_op op_sys, sigma_sys;
  for(int i=0; i<nc; i++)			// Loop over components
    {
    dsys = msys.Comp(i);			// This is the ith component
    sigma_sys = sigma.project_sub(i);		// sigma in component i subspace
    op_sys = op(dsys, sigma_sys, beta);		// Call desired subspace function
    if((icomp == -1) || (i == icomp))
      {
      mxc.push_back(op_sys.get_mx());
      bsc.push_back((op_sys.get_basis()).U());
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    else
      {
      mxc.push_back(sigma_sys.get_mx());	// remains untouched
      bsc.push_back((sigma_sys.get_basis()).U());
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);
  }

gen_op multize(gen_op op(const spin_sys&, const gen_op&, int, double),
       gen_op& sigma, int nspin, double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if (icomp != -1)				// -1 to perform operation over
        msys.CheckComp(icomp);			// all blocks; otherwise over
                                                // icomp block
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;
  gen_op op_sys, sigma_sys;
  for(int i=0; i<nc; i++)
    {
    sys = msys.Comp(i);
    sigma_sys = sigma.project_sub(i);
    op_sys = op(sys, sigma_sys, nspin, beta);
    if ((icomp == -1) || (i == icomp))
      {
      mxc.push_back(op_sys.get_mx());
      bsc.push_back((op_sys.get_basis()).U());
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    else
      {
      mxc.push_back(sigma_sys.get_mx());	// remains untouched
      bsc.push_back((sigma_sys.get_basis()).U());
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);
  }


gen_op multize(gen_op op(const spin_sys&,const gen_op&,const string&, double),
   gen_op& sigma,const string& iso,double beta,const multi_sys &msys,int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1)				// -1 to perform operation over
        msys.CheckComp(icomp);                 // all blocks; otherwise over
                                                // icomp block
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;
  gen_op op_sys, sigma_sys;
  for(int i=0; i<nc; i++)
    {
    sys = msys.Comp(i);
    sigma_sys = sigma.project_sub(i);
    op_sys = op(sys, sigma_sys, iso, beta);
    if ((icomp == -1) || (i == icomp))
      {
      mxc.push_back(op_sys.get_mx());
      bsc.push_back((op_sys.get_basis()).U());
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    else
      {
      mxc.push_back(sigma_sys.get_mx());    // remains untouched
      bsc.push_back((sigma_sys.get_basis()).U());
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);
  }

// ____________________________________________________________________________
// D    General Operator <=== General Operator Function(spin_sys, values)
// ____________________________________________________________________________

/*          (Often These Are Propagator or Rotation Functions)

                    Function Form                             Example
 --------------------------------------------------- --------------------------
 Name(const spin_sys&, int, double)                  Iypuls_U(sys, 1, 90.0)
 Name(const spin_sys&, const string&, double)        Iypuls_U(sys, "13C", 90.0)
 Name(const spin_sys&, double)                       Iypuls_U(sys, 90.0)
 Name(const spin_sys&, double, double)               Ixypuls_U(sys, 90.0, 90.0)

        Input      OpFct   : A function Returning Op (gen_op)
                   msys    : A multi_sys spin system
                   icomp   : System components affected (-1 = all)
                   double  : Anything (often a pulse angle, e.g. 90.0)
                   int     : Anyting (often a spin index)
                   string  : Anything (often an isotope name, e.g. "1H")
        Output     MOp     : Operator op for multi_sys msys
                             that parallels OpFct but resides in
                             the direct product Hilbert space of msys        */

gen_op multize(gen_op op(const spin_sys&, int, double),
                    int nspin, double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1) msys.CheckComp(icomp);	// Insure component exists
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;				// System for single component
  gen_op op_sys, sigma_sys;
  int subHS=0;
  for(int i=0; i<nc; i++)			// Loop the system components
    {
    sys = msys.Comp(i);			//	Component i (sys dynamic)
//    sigma_sys = sigma.project_sub(i);		//	Density Op this component
    op_sys = op(sys, nspin, beta);		//	Requested Op this component
    if((icomp == -1) || (i == icomp))		//	Add it if it was selected
      {
      mxc.push_back(op_sys.get_mx());		//	Matrix for operator, comp. i
      bsc.push_back((op_sys.get_basis()).U());	//	Basis for operator, comp. i
      mxc[i].set_type(n_matrix_type);		//	Insure matrix is n_matrix
      bsc[i].set_type(n_matrix_type);		//	Insure basis is n_matrix
      }
    else
      {
      subHS = sys.HS();				//	Hilbert space of component i
      mxc.push_back(matrix(subHS,subHS,i_matrix_type)); // 	Op matrix is I for this component
      bsc.push_back(mxc[i]);				//	Basis is I for this component
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);			// Return in composite space
  }

gen_op multize(gen_op op(const spin_sys&, const string& iso, double),
          const string& iso, double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1) msys.CheckComp(icomp);	// Insure component exists
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;				// System for single component
  gen_op op_sys, sigma_sys;
  int subHS=0;
  for(int i=0; i<nc; i++)			// Loop the system components
    {
    sys = msys.Comp(i);			//	Component i (sys dynamic)
//    sigma_sys = sigma.project_sub(i);		//	Density Op this component
    op_sys = op(sys, iso, beta);		//	Requested Op this component
    if((icomp == -1) || (i == icomp))		//	Add it if it was selected
      {
      mxc.push_back(op_sys.get_mx());			//	Matrix for operator, comp. i
      bsc.push_back((op_sys.get_basis()).U());	//	Basis for operator, comp. i
      mxc[i].set_type(n_matrix_type);		//	Insure matrix is n_matrix
      bsc[i].set_type(n_matrix_type);		//	Insure basis is n_matrix
      }
    else
      {
      subHS = sys.HS();				//	Hilbert space of component i
      mxc.push_back(matrix(subHS,subHS,i_matrix_type)); // 	Op matrix is I for this component
      bsc.push_back(mxc[i]);			//	Basis is I for this component
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);			// Return in composite space
  }


gen_op multize(gen_op op(const spin_sys&, double),
                    double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1) msys.CheckComp(icomp);	// Insure component exists
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;				// System for single component
  gen_op op_sys, sigma_sys;
  int subHS=0;
  for(int i=0; i<nc; i++)			// Loop the system components
    {
    sys = msys.Comp(i);			//	Component i (sys dynamic)
//    sigma_sys = sigma.project_sub(i);		//	Density Op this component
    op_sys = op(sys, beta);			//	Requested Op this component
    if((icomp == -1) || (i == icomp))		//	Add it if it was selected
      {
      mxc.push_back(op_sys.get_mx());		//	Matrix for operator, comp. i
      bsc.push_back((op_sys.get_basis()).U());	//	Basis for operator, comp. i
      mxc[i].set_type(n_matrix_type);		//	Insure matrix is n_matrix
      bsc[i].set_type(n_matrix_type);		//	Insure basis is n_matrix
      }
    else
      {
      subHS = sys.HS();				//	Hilbert space of component i
      mxc.push_back(matrix(subHS,subHS,i_matrix_type)); // 	Op matrix is I for this component
      bsc.push_back(mxc[i]);			//	Basis is I for this component
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);			// Return in composite space
  }

gen_op multize(gen_op op(const spin_sys&, double, double),
               double phi, double beta, const multi_sys &msys, int icomp)
  {
  int nc = msys.NComps();			// Number of components
  if(icomp != -1) msys.CheckComp(icomp);	// Insure component exists
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  sys_dynamic sys;				// System for single component
  gen_op op_sys, sigma_sys;
  int subHS=0;
  for(int i=0; i<nc; i++)			// Loop the system components
    {
    sys = msys.Comp(i);			//	Component i (sys dynamic)
//    sigma_sys = sigma.project_sub(i);		//	Density Op this component
    op_sys = op(sys, phi, beta);		//	Requested Op this component
    if((icomp == -1) || (i == icomp))		//	Add it if it was selected
      {
      mxc.push_back(op_sys.get_mx());		//	Matrix for operator, comp. i
      bsc.push_back((op_sys.get_basis()).U());	//	Basis for operator, comp. i
      mxc[i].set_type(n_matrix_type);		//	Insure matrix is n_matrix
      bsc[i].set_type(n_matrix_type);		//	Insure basis is n_matrix
      }
    else
      {
      subHS = sys.HS();				//	Hilbert space of component i
      mxc.push_back(matrix(subHS,subHS,i_matrix_type)); // 	Op matrix is I for this component
      bsc.push_back(mxc[i]);				//	Basis is I for this component
      mxc[i].set_type(n_matrix_type);
      bsc[i].set_type(n_matrix_type);
      }
    }
  return gen_op(mxc, bsc);			// Return in composite space
  }


// sosik






// ----------------------------------------------------------------------------
//	          Generic Functions Which Use Superoperators
//            (Often These Are Relaxation Or Exchange Functions)
// ----------------------------------------------------------------------------

super_op multize(super_op SOpFct(const gen_op&), const gen_op& Op, const multi_sys& msys)
// sosi - basis problems with this function?!

        // Input        SOpFct	: Function which returns a  superoperator
        //                        given an operator as its only argument
        //              Op	: An operator
        //              msys    : A multi_sys spin system 
        // Output       MSOp    : Superoperator SOp for multi_sys msys 
        //                        in the direct product Liouville space 
        // Note                 : This routine calls an arbitrary function 
        //                        of the following form 
        //                              super_op SOpFct(gen_op& Op) 
        //                        where Op is the only function arguments
	//			  and SopFct is the name of the function
	// Note			: There is no check herein to insure that
	//			  the composite space of Op is the same
	//			  as that which is the default of msys

  {
  int nc = msys.NComps();			// Number of components
  matrix *mxc;				// Array for superop matrices
  mxc = new matrix[nc];
  gen_op OpComp;				// Operator component
  super_op SOpComp;				// Superoperator component
  for(int i=0; i<nc; i++)			// Loop all msys components
    {
    OpComp = Op.project_sub(i);			// Get Op's ith component
    SOpComp = SOpFct(OpComp);			// Superoperator ith component
    mxc[i] = SOpComp.get_mx();			// Store SOpComp matrix rep.
    }
  super_op LOp(mxc, nc);			// implies default basis
  delete [] mxc;
  return LOp;
  }


super_op multize(super_op sop(const sys_dynamic&,gen_op&,int,int), gen_op& H,
                                     int type, int level, const multi_sys& msys)
// sosi - basis problems with this function?!   This is
//        the main relaxation superoperator interface.

        // Input        sop     : Function which returns a  
        //                        superoperator given a system, operator, 
        //                        and two integers
        //              H       : An operator (isotropic Hamiltonian) 
	//		type    : Computation type  
	//		level   : Computation level 
        //              msys    : A multi_sys spin system 
        // Output       MSOp    : Superoperator op for multi_sys msys 
        //                        in the direct product Liouville space 
        // Note                 : This routine calls an arbitrary function 
        //                        of the following form 
        //                        super_op Name(sys_dynamic&, gen_op&, int, int) 
        //                        where H, type and level will be the arguments    

  {
  int nc = msys.NComps();			// Number of components
  vector<matrix> mxc;				// Array of superop matrices
  vector<matrix> bsc;				// Array of superop HS bases
  sys_dynamic dsys;				// Temp dynamic spin system
  gen_op H_sys;					// Temp isotropic Hamiltonian
  super_op R;					// Temp (relaxation) superop
  for(int i=0; i<nc; i++)			// Loop all components (systems)
    {
    dsys = msys.Comp(i);			// Get component i
    H_sys = H.project_sub(i);			// H's ith comp. (i's H.space)
    R = sop(dsys, H_sys, type, level);		// Rfunct comp. i (i's L.space)
    mxc.push_back(R.get_mx());			// Store matrix rep this superop
    bsc.push_back((R.get_basis()).U());		// Store HS basis for this rep
    }
  return super_op(mxc, bsc);			// Implies default basis
  }


super_op multize(super_op sop(const sys_dynamic&,gen_op&,int), gen_op& H,
                                          int level, const multi_sys& msys)

        // Input        sop     : Function which returns an 
        //                        superoperator given a system, operator, 
        //                        and two integers
        //              H       : An operator (isotropic Hamiltonian) 
	//		level   : Computation level 
        //              msys    : A multi_sys spin system 
        // Output       MSOp    : Superoperator op for multi_sys msys 
        //                        in the direct product Liouville space 
        // Note                 : This routine calls an arbitrary function 
        //                        of the following form 
        //                        super_op Name(sys_dynamic&, gen_op&, int, int)
        //                        where H, type and level will be the arguments    

// sosi - basis problems with this function?!
  {
  int nc = msys.NComps();			// Number of components
 matrix *mxc;				// Array for superop matrices
  mxc = new matrix[nc];
  sys_dynamic dsys;				// Temp dynamic spin system
  gen_op H_sys;					// Temp isotropic Hamiltonian
  super_op R;					// Temp (relaxation) superop.
  for(int i=0; i<nc; i++)			// Loop all components (systems)
    {
    dsys = msys.Comp(i);			// Get component i
    H_sys = H.project_sub(i);			// H's ith comp. (i's H. space)
    R = sop(dsys, H_sys, level);		// R's ith comp. (i's L. space)
    mxc[i] = R.get_mx();			// Store matrix rep of superop
    }
  super_op LOp(mxc, nc);			// implies default basis
  delete [] mxc;
  return LOp;
  }


basis D_basis(const multi_sys &msys)

	// Input	msys	: A multi_sys spin system
	// Output	bs      : A default basis in the
	//			  composite Hilbert space
	//			  of msys

  {
  int nc = msys.NComps();			// Number of components
  matrix bsm(msys.HS(),msys.HS(),i_matrix_type);// I in full msys Hilbert space 
  int *ncd;					// Array for subspace dimensions
  ncd = new int[nc];
  sys_dynamic sys;				// System for one component 
  for (int i=0; i<nc; i++)			// Loop system cmpts (sub-systs)
    {					
    sys = msys.Comp(i);			// 	Component i(sys_dynamic)
    ncd[i] = sys.HS();				//	Hilbert space of cmpt i
    }
  basis Bs(bsm, nc, ncd);			// implies default basis
  delete [] ncd;
  return Bs;
  } 


row_vector LS_qState_bra(const multi_sys &msys, int i)
  {
  basis Dbs = D_basis(msys);
  int ic = Dbs.which_sub_LS(i);		       // component hosting state i
  int i_sys = i - Dbs.sub_anchor_LS(ic);       // number of state i in its block
  sys_dynamic sys = msys.Comp(ic);
  int dim = sys.HS();
  int j = i_sys/dim;			       // this is modulo division
					       // j is bra in |j><k|
  complex elt;
  int nspins = sys.spins();
  row_vector mk(nspins), mk1(nspins);
  mk1 = sys.qState(j);
  for (int it=0; it<nspins; it++)
    {
    elt = mk1.get(nspins-it-1);
    mk.put(elt,it);				// NB, sys.qState(j) vector
    }						// is flipped, i.e. (3,2,1) ->
						// (1,2,3). In this way
// states go as |+++>, |++->, |+-+>, ... instead of |+++>,|-++>, |+-+>...

  return mk;
} 


row_vector LS_qState_ket(const multi_sys &msys, int i)
  {
  basis Dbs = D_basis(msys);
  int ic = Dbs.which_sub_LS(i);                // component hosting state i
  int i_sys = i - Dbs.sub_anchor_LS(ic);       // number of state i in its block
  sys_dynamic sys = msys.Comp(ic);
  int dim = sys.HS();
  int k = i_sys - (dim*(i_sys/dim));	       // this is modulo division
                                               // parse k in |j><k|
  complex elt;
  int nspins = sys.spins();
  row_vector mk(nspins), mk1(nspins);
  mk1 = sys.qState(k);
  for (int it=0; it<nspins; it++)
    {
      elt = mk1.get(nspins-it-1);
      mk.put(elt,it); 
    }  					        // NB, sys.qState(k) vector
                                                // is flipped, i.e. (3,2,1) ->
                                                // (1,2,3). In this way
// states go as |+++>, |++->, |+-+>, ... instead of |+++>,|-++>, |+-+>...

  return mk;
}


/*************************************************************************
**									**
**			      Function Xnm				**
**									**
** The purpose of this function is to calcualte a superoperator that	**
** represents non-mutual exchange between the spin system components 	**
** in a given multi_sys spin system.  The input spin system, msys, 	**
** contains a set of defined non-mutual exchange processes, each of	**
** which contains the spin systems exchanging, their exchange rates,	**
** and their spin<-->spin mappings.					**
**									**
** The general principle is to compute the element of exchange matrix	**
** Xex between								**
**									**
**	        LHS				    RHS			**
** |m1, m2,...mN><m'1, m'2,...m'N|  &  |k1, k2,...kL><k'1, k'2,...k'L|	**
**									**
** Some of the spins from the left hand side (LHS) are exchanging with	**
** their counnterparts from the right. For example 2nd spin from the	**
** left can be mapped by exchange onto 5th spin from the right. The	**
** exchange must preserve quantum state: 				**
**									**
**                        m2 = k5, m'2 = k'5				**
**									**
** Some other spins are not mapped between left and right. For example,	**
** 1st spin from the left and 7th spin from the right (they leave for	**
** some third molecule). These spins must be in |m><m| state both on	**
** the right and on the left, i.e.					**
**									**
**                       m1 = m'1 and k7 = k'7				**
**									**
** If these conditions are fullfilled, the element of Xex exits.	**
**									**
** In the basis of conveniently normalized spin operators (multiplied	**
** by population of respective species) the exchange matrix assumes 	**
** the following form:							**
**									**
**                  	(   -k1      k2     )				**
**		        (   	            )				**
**			(    k1     -k2     )				**
**									**
**									**
** where k factors multiply the whole blocks between (or within) 	**
** exchanging components and are related to each other as		**
**									**
**                     n1 k1 = n2 k2 = n3 k3 =...			**
**									**
** For more information on the theory, see 				**
**									**
**   R.O.Kuhne, T.Schaffhauser, A.Wokaun, R.R.Ernst JMR 35, 39 (1979)	**
**									**
** In addition, blocks have normalization associated with HS dimension	**
** of the component spin systems.					**
**									**
** N. Skrynnikov, Oct. 1995						**
**									**
*************************************************************************/

super_op Xnm(const multi_sys& mixture)

	// Input		msys    : A multi_spin spin system
	// Output		XL	: Non-mutual exchange superoperator
	// Note				: This superoperator is returned
	//				  in the default basis

  {
  int dim = mixture.LS();			// Determine overall LS dim
  basis Dbs = D_basis(mixture);	        	// Default basis
  matrix Xmx(dim, dim, 0.0);			// Superop matrices to host Xex
  int i, j, k;			
  int ic0=0, ic1=0, ic2=0;			// Multi_sys components
  int s1, s2;					// Spin numbers within comp's
  int match, mover;				// Flags
  double q1b = 0, q1k = 0;			// Mz quantum numbers of s1, s2
  double q2b = 0, q2k = 0;			// Mz quantum numbers of s1, s2
  double pop0, pop2, kex0, kex2;
  int spinHS, norm;				// Normalization by dim of HS
  ExchProc Pro;
  sys_dynamic dsys;
  row_vector bra1, ket1, bra2, ket2;
  for(i=0; i<mixture.NExProcs(); i++)		// Loop over exchange processes
     {
     Pro = mixture.ExProc(i);			// Get exchange process i
     matrix Xel(dim, dim, 0.0);			// Start with zero superop
     ic0 = Pro.LHSComp(0);			// 0th component on lhs
     pop0 = mixture.pop(ic0);		        // population of 0th component
     kex0 = Pro.Kex();			        // k refers to 0th comp on lhs
     if(kex0 == 0) continue;			// Don't contribute if K=0
     for(j=0; j<dim; j++)			// Loop rows and columns of
       { 					// Xel for process i and set
       for(k=0; k<dim; k++)  			// <j|Xel|k> elements
	 {
         ic1 = Dbs.which_sub_LS(j);		// Index of component 1
         ic2 = Dbs.which_sub_LS(k);	        // Index of component 2 
         pop2 = mixture.pop(ic2);
         kex2 = (pop0*kex0)/pop2;

         if(ic1 == ic2)			// Component with itself 
	   if(Pro.involves(ic1) )		// It's exchanging component
             {
             if(j == k) Xel.put(kex2, j, j); 	// Only diagonal decay terms
             continue;
             }
         if(!Pro.mixes(ic1, ic2)) continue;	// Not in exchange
						// Generate cross-terms
         bra1 = LS_qState_bra(mixture, j);	// |ket1><bra1| form superbra
         ket1 = LS_qState_ket(mixture, j);	//
         bra2 = LS_qState_bra(mixture, k);	//
         ket2 = LS_qState_ket(mixture, k);	// |ket2><bra2| form superket
         norm = 1;
         match = 1;
         for(s1=0; s1<bra1.cols(); s1++)	// parse bra1;
	   {
           mover = 0;				// flag for exchanging spin s1
           for(s2=0; s2<bra2.cols(); s2++)	// look for s2 <-> s1 
	     {
             q1b = bra1.getRe(s1);		// Mz of spin s1 in bra1
             q1k = ket1.getRe(s1);		// Mz of spin s1 in ket1
             q2b = bra2.getRe(s2);		// Mz of spin s2 in bra2
             q2k = ket2.getRe(s2);		// Mz of spin s2 in ket2
	     if(Pro.mapped(ic1,s1,ic2,s2))	// if partners in exchange
               {
               mover = 1;			// s1 in exchange with s2
               if((q1b!=q2b) || (q1k!=q2k))	// different quantum state
                 {
		 match = 0;			// do not click
                 break;
                 }
               }
             }
           if(!match) break;
           if(!mover)			    // s1 is not exchanging
             {
             if(q1b!=q1k)                  // it's not |m><m|
               {
               match = 0;
               break;
               }
             dsys = mixture.Comp(ic1);	// spin that is in superbra
             spinHS = dsys.HS(s1);		// but not in superket
             norm *= spinHS;			// contributes into norm 
             } 
           }
	 if(!match) continue;
         for(s2=0; s2<bra2.cols(); s2++)	// now parse bra2 to find
           {					// local non-movers
           q2b = bra2.getRe(s2);		// Mz of spin s2 in bra2
           q2k = ket2.getRe(s2);		// Mz of spin s2 in ket2

           mover = 0;				// flag for exchanging s2
           for(s1=0; s1<bra1.cols(); s1++)     
	     if(Pro.mapped(ic2, s2, ic1, s1))	  
	       mover = 1;			// this is mover
             if(!mover)				// s2 is not exchanging
               if(q2b!=q2k)			// it is not |m><m|
		 {
                 match = 0;
                 break;
                 }
           }			
 
         if(!match) continue;
         else
           {
	   kex2 /= double(norm);
           Xel.put(-kex2,j,k);			// Normalization good for any 
           }					// non-mutual exchange. 
         }
       }
     Xmx += Xel;				// Add this exchange process'
     }						// contribution to Xnm
   return super_op(Xmx,Dbs);
   }

#endif							// MultiLib.cc
