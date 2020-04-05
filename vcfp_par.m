% set VCFP plant parameters
R   = 1;
L   = 1e-4;
kE  = 1;
kI  = 10;
kM  = 0.1;
kx  = 1e5;
J1  = 1.1e-4;
J2  = 2.6e-4;
J3  = 1.1e-4;
d1  = 0.08;
d2  = 0.08;
d3  = 0.03;
c12 = 1e4;
c23 = 1e4;
d12 = 0.08;
d23 = 0.08;
kr  = 0.1;

% VCFP linear state space model
a_p      = zeros(7,7);
a_p(1,7) = kM/J1;
a_p(1,1) = (-d1-d12)/J1;
a_p(1,3) = d12/J1;
a_p(1,2) = -c12/J1;
a_p(1,4) = c12/J1;
a_p(2,1) = 1.0;
a_p(3,1) = d12/J2;
a_p(3,3) = (-d12-d23-d2)/J2;
a_p(3,5) = d23/J2;
a_p(3,2) = c12/J2;
a_p(3,4) = (-c12-c23)/J2;
a_p(3,6) = c23/J2;
a_p(4,3) = 1;
a_p(5,3) = d23/J3;
a_p(5,5) = (-d23-d3)/J3;
a_p(5,4) = c23/J3;
a_p(5,6) = -c23/J3;
a_p(6,5) = 1.0;
a_p(7,7) = -R/L;
a_p(7,1) = -kE/L;

b_p      = zeros(7,1);
b_p(7,1) = 1/L;

c_p      = zeros(2,7);
c_p(1,6) = kr*kx;
c_p(2,7) = kI;

d_p(1,1) = 0.0;
d_p(2,1) = 0.0;

