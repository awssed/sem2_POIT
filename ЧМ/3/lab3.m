F = @(x) x.^3+12.*x-12;

a = -2;
b = 2;
e = 0.01; %допустимая погрешность
[proiz1, proiz2] = proiz();
x1=popolam(F,a,b,e)
x2=newton(F,a,b,e,proiz1,proiz2)
x3=interpretation(F,a,e,proiz1)
function k = popolam(F,a,b,eps)
    while abs(b-a) > eps 
        k = (a+b)/2;
        if F(a)*F(k) < 0 %если принимает значения разных знаков, то b будет принят как интервал 
            b = k;
        elseif F(b)*F(k) < 0
            a = k;
        end     
    end
    k = (a+b)/2;
end

function k = newton(F,a,b,eps, der1,der2) 

    if F(a)*der2(a) > 0 %если верно, то за начальное приближен будет конец отрезка на a
            k = a;
    elseif F(b)*der2(b) > 0
            k = b;
    end     
    pr = F(k)/der1(k); %за след приближ 
    while abs(pr) > eps
        pr = F(k)/der1(k);
        k = k- pr;
    end
end

function s = interpretation(F,a,eps,der1)
    M = @(a) 1.01.*der1(a); %Неизвестн постоян велич,которая определяется из условия сходимости метода простой итерации
    k = M(a);
    f = @(s) s-F(s)./k; %привод к функц, для дальн использ
    s = a;
    pr = 1;
    while pr > eps %прекращ, если результ двух послед итерац близки 
       s = a;
       a = f(s);
       pr = abs(a - s);
    end
    
end
    

%производная
function [proiz1,proiz2] = proiz()
    syms x;  
    f = x.^3+12.*x-12;
    proiz1 = matlabFunction(diff(f));
    proiz2 = matlabFunction(diff(f, 2));
    
end