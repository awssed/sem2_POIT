a=-0.7;
b=0.5;
x=a;
n=100;
h=(b-a)/(2*n);
f1=@(x) (x.^5+3*x.^2)/(4-9*x.^6);
f2=@(x) sin(x.^2 -x);
s1=simpson(a,b,n,h,f1);
s11=integral(f1,a,b,'arrayvalued', true);
s2=simpson(a,b,n,h,f2);
s22=integral(f2,a,b,'arrayvalued', true);
tall1=(s11-s1)/s1;
tall2=(s22-s2)/s2;
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

