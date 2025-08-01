set J1;
set J2;
set J:= J1 union J2;
set I;
param b{I};
param c{J};
param a{I, J};
param alpha;
var x{J};

minimize z: sum{j in J}c[j]*x[j];
s.t. v1 :sum{j in J}a["r1",j]<=b["r1"]+alpha;
s.t. v3{j in J2}: x[j]<=0;
s.t. v4{j in J1}: x[j]>=0;


