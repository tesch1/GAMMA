gen_op sigma_eq(const multi_sys& msys)
  {
  int nc = msys.NComps();			// Number of components
  vector<matrix> mxc;				// Array of matrices
  vector<matrix> bsc;				// Array of bases
  gen_op Op;					// Scratch operator
  Isotope I = (msys.Comp(0)).isotope(0);
  for(int i=0; i<nc; i++)			// Loop over spin components
    {
    Op = sigma_eq(msys.Comp(i), I);		// Requested Op, comp i
    mxc.push_back(msys.pop(i)*Op.get_mx());	// Store its matrix 
    bsc.push_back((Op.get_basis()).U());	// Store its basis
    }
  return gen_op(mxc, bsc);
  }

