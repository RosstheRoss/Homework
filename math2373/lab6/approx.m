z=8-2*2-7*exp(-2/2);%exact solution at t=2
for k=1:5
    N=5*2^(k-1);eulerN;
    %difference between Euler approximation and exact solution at t=2.
    error(k)=y(N+1)-z;
end