function [y]=f(x)
    /*Dados de Entrada
    x0: 4
    tolerancia: 0.00001
    */
y = (x^4 + 2 * (x^3) - 13 * (x^2) -14 * x + 24)
endfunction

function [y]=df(x)
y = (4 * (x^3) + 6 * (x^2) - 26 * x - 14)
endfunction
tic();
t=100;
for i=1:1:t
xZero=4;
tolerancia=0.00001;
Fx=f(xZero);
DFx = df(xZero);
xx = xZero;
iter=0;
DeltaX = 1000;
DF = 1;
while((abs(DeltaX>tolerancia) || abs(Fx)> tolerancia) && (DF ~= 0) && (iter < 100)  
    DeltaX = Fx/DFx; 
    xx = xx + DeltaX;
    Fx = f(xx);
    DFx= df(xx);       
    iter=iter+1
end
Raiz = xx;
if abs(DeltaX)<= tolerancia && abs(Fx) <= tolerancia       
    printf('\nCondErro = 0');
else
    printf('\nCondErro = 0');
end
end
end

t=toc();
disp(t);s
