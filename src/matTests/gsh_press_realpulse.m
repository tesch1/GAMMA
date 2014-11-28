dir = ''

outfile = [dir 'gsh_press_realpulses_pytest.txt']
sysfile = [dir 'gsh_test.sys']
pulse180file = [dir 'bjs180_1.txt']

runname = 'test_lines'

h1 = 'Press Simulation Test With Real 90,180 Pulses'
h2 = ['using input sys file: ' sysfile]
h3 = ['and input 180 pulse file: ' pulse180file]

header = {h1, h2, h3}


sys = gammat.spin_system()

tinit = 0.005           % evolution after 90 before first 180
TE = 0.025              % TE in sec
TE2 = TE/2.0            % TE/2
pulsestep = 0.00001     % 1 msec pulse steps


sys.read(sysfile)

specfreq = sys.Omega()

pulse = gammat.row_vector.read_pulse(pulse180file, gammat.row_vector.ASCII_MT_DEG)

ptime = gammat.row_vector(pulse.size())

for j=1:size(pulse(:),1)
    ptime.put(gammat.complex(pulsestep, 0), j)  % pulse steps
end

pwf = gammat.PulWaveform(pulse, ptime, 'TestPulse')

pulc = gammat.PulComposite(pwf, sys, '1H')

H = gammat.Hcs(sys) + gammat.HJ(sys)

D = gammat.Fm(sys)

Udelay1 = gammat.prop(H, tinit)
Udelay2 = gammat.prop(H, TE2)
Udelay3 = gammat.prop(H, TE2)

ac = gammat.acquire1D(gammat.gen_op(D), H, 0.001) % Set up acquisition
ACQ = ac

sigma0 = gammat.sigma_eq(sys)                   %Equilibrium density matrix
sigma1 = gammat.Iypuls(sys, sigma0, 90.0)       %Apply a 90y pulse
sigma0 = gammat.evolve(sigma1, Udelay1)         %Evolve through TINIT

Ureal180  = pulc.GetUsum(-1)                    %Get the propagator for steps of 180

sigma1 = Ureal180.evolve(sigma0)                %Evolve through pulse
sigma0 = gammat.evolve(sigma1, Udelay2)         %Evolve through TE/2
sigma1 = Ureal180.evolve(sigma0)                %Evolve through pulse
sigma0 = gammat.evolve(sigma1, Udelay3)         %Evolve through TE/2

mx = ACQ.table(sigma0)                          % Transitions table (no lb)

mx.dbwrite(outfile, runname, specfreq, sys.spins(), 0, header)      % Print Table

