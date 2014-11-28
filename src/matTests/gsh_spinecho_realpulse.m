dir = ''

insysfile = [dir 'gsh_test.sys'];
inpulse180file = [dir 'bjs180_1.txt'];

outfile = [dir 'gsh_spinecho_realpulses_pytest.txt'];

out_name = 'test_lines';


h1 = 'Spin Echo Simulation Test With Real 180 Pulse'
h2 = ['using input sys file: ' insysfile]
h3 = ['and input 180 pulse file: ' inpulse180file]

header = {h1, h2, h3}

sys = gammat.spin_system()

t1 = 0.025 
t2 = 0.025
pulsestep = 0.00001

sys.read(insysfile)
specfreq = sys.Omega()

% read_pulse replaces ReadPulse() and is a static member of row_vector
pulse = gammat.row_vector.read_pulse(inpulse180file, gammat.row_vector.ASCII_MT_DEG)

ptime = gammat.row_vector(pulse.size())

%need to use gammat.complex() so it can find correct function to call.
for j=1:pulse.size()
    ptime.put(gammat.complex(pulsestep, 0), j)
end

pwf = gammat.PulWaveform(pulse, ptime, 'TestPulse')

pulc = gammat.PulComposite(pwf, sys, '1H')

H = gammat.Hcs(sys) + gammat.HJ(sys);
D = gammat.Fm(sys);

Udelay1 = gammat.prop(H, t1);
Udelay2 = gammat.prop(H, t2);

% Neet to effectively typecast D as a gen_op.
ac = gammat.acquire1D(gammat.gen_op(D), H, 0.001)

ACQ = ac;

sigma0 = gammat.sigma_eq(sys)

sigma1 = gammat.Iypuls(sys, sigma0, 90.0)   %Apply a 90y pulse

sigma0 = gammat.evolve(sigma1, Udelay1)     %Evolve through T1

Ureal180  = pulc.GetUsum(-1)                %Get the propagator for steps of 180

sigma1 = Ureal180.evolve(sigma0)            %Evolve through pulse

sigma0 = gammat.evolve(sigma1, Udelay2)     %Evolve through T2

mx = ACQ.table(sigma0)                      %Transitions table (no lb)

mx.dbwrite(outfile, out_name, specfreq, sys.spins(), 0, header)
