h=2/N; t(1)=0; y(1)=1;
for n=1:N
    t(n+1)=t(n)+h;
    y(n+1)=y(n)+(-0.5*y(n)-t(n)+2)*h;
end