set PROD;
set RES;

param MAX{RES};
param p{PROD};
param a{RES, PROD};

var x{PROD} >=0;

maximize profitto: sum{j in PROD} p[j]*x[j];

s.t. c_res{i in RES}: sum{j in PROD} a[i,j]*x[j] <= MAX[i];