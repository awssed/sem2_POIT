%variant 10
a=-0.7;
b=0.5;
n=100;
h=(b-a)/n;
f1=@(x) (x.^5+3*x.^2)/(4-9*x.^6);
f2=@(x) sin(x.^2 -x);

sTrap1 =trapeziod(a,n,h,f1);
sTrap11=integral(f1,a,b,'arrayvalued', true);
sTrap2=trapeziod(a,n,h,f2);
sTrap22=integral(f2,a,b,'arrayvalued',true);
tallTrap1=abs((sTrap11-sTrap1)/sTrap1);
tallTrap2=abs((sTrap22-sTrap2)/sTrap2);

a=-0.7;
b=0.5;
n=100;
h=(b-a)/n;
sPriam1 =priam(a,n,h,f1);
sPriam11=integral(f1,a,b,'arrayvalued', true);
sPriam2=priam(a,n,h,f2);
sPriam22=integral(f2,a,b,'arrayvalued', true);
tallPriam1=abs((sPriam11-sPriam1)/sPriam1);
tallPriam2=abs((sPriam22-sPriam2)/sPriam2);


a=-0.7;
b=0.5;
n=100;
h=(b-a)/(2*n);
sSimp1=simpson(a,b,n,h,f1);
sSimp11=integral(f1,a,b,'arrayvalued', true);
sSimp2=simpson(a,b,n,h,f2);
sSimp22=integral(f2,a,b,'arrayvalued', true);
tallSimp1=abs((sSimp11-sSimp1)/sSimp1);
tallSimp2=abs((sSimp22-sSimp2)/sSimp2);
function s=simpson(a,b,N,h,f)
x=a;
n=N;
sum1=0;
while(n>1)
    sum1=sum1+f(x-h);
    x=x+2*h;
    n=n-1;
end
n=N;
sum2=0;
x=a;
while(n>2)
    sum2=sum2+f(x);
    x=x+2*h;
    n=n-1;
end
s=(h/3)*(f(a)+4*sum1+2*sum2+f(b));
end


function s= trapeziod(a,n, h, f)
s=0;
x=a;
while (n>1)
    s=s+((f(x)+f(x+h))/2)*h;
    x=x+h;
    n=n-1;
end
end


function s= priam(a,n, h, f)
s=0;
x=a;
while (n>1)
   s=s+h*f(x+(h/2));
   x=x+h;
    n=n-1;
end
end
