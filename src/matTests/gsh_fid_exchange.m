infile = 'gsh_test.sys'
outfile = 'gsh_fid_exchange_pytest.txt'

s1 = 'FID/Exchange  Test'
s2 = ['using input sys file: '  infile]

runname = 'test_lines';

header = {s1, s2}

sys = gammat.sys_dynamic()

sys.read(infile)

specfreq = sys.Omega()

mx = gammat.TTable1D()

H = gammat.Ho(sys)

detect = gammat.Fm(sys)

sigma0 = gammat.sigma_eq(sys)

sigmap = gammat.Iypuls(sys, sigma0, 90.)

L = gammat.Hsuper(H)
L = L * gammat.complex(0,1)

L = L + gammat.Kex(sys, H.get_basis());

ACQ1 = gammat.acquire1D(gammat.gen_op(detect), L)

mx = ACQ1.table(sigmap);

%mx.dbwrite_old(outfile, 'test_lines', -10, 10, specfreq, .1, 0, header)
mx.dbwrite(outfile, runname, specfreq, sys.spins(), 0, header)

