function [] = estatisticaMatrizRandomica(t)
tic();
n=5;
v = zeros(t);
w = zeros(t);
for i=1:1:t
    a = rand(n,n,'normal');
    b = rand(n,n,'normal');
    c = rand(n,n,'normal');
    d = rand(n,n,'normal');
    P = [a, b, c, d];
    Q = [a, b; c, d];
    v(i) = trace((P' * P) ^ 4);
    w(i) = trace((Q' * Q) ^ 4);    
end
stdev(v)/mean(v);
stdev(w)/mean(w);
t =toc();
disp(t);
end
