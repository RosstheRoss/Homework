h=2/5; t(1)=0; y(1)=1;
for n=1:5
    t(n+1)=t(n)+h;
    y(n+1)=y(n)+(-y(n)+t(n))*h;
end