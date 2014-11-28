dir = ''

sysfile = [dir 'gsh_test.sys']
outfile = [dir 'gsh_spinecho_pytest.txt']

runname = 'test_lines'

sysfilestr = ['using input sys file: ' sysfile]

header = {'Spin Echo Simulation Test', sysfilestr}

sys = gammat.spin_system()
sys.read(sysfile)

specfreq = sys.Omega()

H = gammat.Hcs(sys) + gammat.HJ(sys)
D = gammat.Fm(sys)

t1 = 0.00833333
t2 = 0.00833333

Udelay1 = gammat.prop(H, t1)
Udelay2 = gammat.prop(H, t2)

ac = gammat.acquire1D(gammat.gen_op(D), H, 0.001)

ACQ = ac

sigma0 = gammat.sigma_eq(sys)
sigma1 = gammat.Ixpuls(sys, sigma0, 90.0)
sigma0 = gammat.evolve(sigma1, Udelay1)
sigma1 = gammat.Ixpuls(sys, sigma0, 180)
sigma0 = gammat.evolve(sigma1, Udelay2)

mx = ACQ.table(sigma0)

mx.dbwrite(outfile, runname, specfreq, sys.spins(), 0, header)
