% loads TargetLink demo model 'vcfp'
model = 'vcfp';

disp (' ');
disp (['Working directory is ' pwd]);
disp (' ');
disp (['Loading TargetLink demo file "' model '" ...']);
disp (' ');

% load VCFP parameters
vcfp_par

%%%for test

ts = 0.0001;
fprintf ('ts = %3g us\n',fix(1000000*ts));

% open Simulink models
open_system(model);

clear model
