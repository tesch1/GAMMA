infile = 'gsh_test.sys' 
outfile = 'gsh_fid_pytest.txt' 
h1 = 'FID Simulation Test'
h2 = ['using input sys file: ' infile]
outname = 'test_lines'
sys = gammat.spin_system() 
sys.read(infile) 
specfreq = sys.Omega() 
H = gammat.Hcs(sys) + gammat.HJ(sys) 
D = gammat.Fm(sys) 
ac = gammat.acquire1D(gammat.gen_op(D), H, 0.001) 
ACQ = ac 
sigma = gammat.sigma_eq(sys) 
sigma0 = gammat.Ixpuls(sys, sigma, 90.0) 
mx = ACQ.table(sigma0) 
header = {h1, h2};
mx.dbwrite(outfile, outname, specfreq, sys.spins(), 0, header);   % Print Table
