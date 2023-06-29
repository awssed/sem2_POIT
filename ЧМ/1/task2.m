%variant 10
a=-0.7;
b=0.5;
n=100;
h=(b-a)/n;
f1=@(x) (x.^5+3*x.^2)/(4-9*x.^6);
f2=@(x) sin(x.^2 -x);
s1 =priam(a,n,h,f1);
s11=integral(f1,a,b,'arrayvalued', true);
s2=priam(a,n,h,f2);
s22=integral(f2,a,b,'arrayvalued', true);
tall=(s2-s1)/s2;
function s= priam(a,n, h, f)
s=0;
x=a;
while (n>1)
   s=s+h*f(x+(h/2));
   x=x+h;
    n=n-1;
end
end
