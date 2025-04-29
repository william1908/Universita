set J1;
set J2;
set J = J1 union J2;
set I;                   

param c{J};              
param b{I};               
param a{I, J};     
param alpha;    

var x{J};            

minimize z: sum{j in J} c[j] * x[j];

subject to v1 {i in I}: sum{j in J} a[i,j] * x[j] <= b[i];
subject to v2 {j in J1}: x[j]>=0;
subject to v3 {j in J2}: x[j]<=0;