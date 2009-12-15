import pygamma as pg 

infile = 'glutamate.sys' 
outfile = "glutamate_fid__test.txt" 
h1 = "FID Simulation Test"
h2 = "using input sys file: " + infile
header = (h1, h2)
sys = pg.spin_system() 
sys.read(infile) 
specfreq = sys.Omega() 
H = pg.Hcs(sys) + pg.HJ(sys) 
D = pg.Fm(sys) 
ac = pg.acquire1D(pg.gen_op(D), H, 0.001) 
ACQ = ac 
sigma = pg.sigma_eq(sys) 
sigma0 = pg.Ixpuls(sys, sigma, 90.0) 
mx = ACQ.table(sigma0) 
mx.dbwrite_old(outfile, "glutamate", 0, 10, specfreq, .1, 0, header)

