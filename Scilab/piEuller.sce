tic();
t=100;
soma = 0.0;
    for i=1:1:t
        soma =0.0;
        for j=1:1:10000
            soma = soma + 1.0/(j * j);
            end
    end
    t = toc();
    disp(t);
    disp(soma,"Pi : ");
    disp((3.1415^2)/6, "Pi Correto: ");
