tic()
t=100;
for k=1:1:t
w = 1.6;
tolerancia = 0.00001;
iterMax = 500;
a = [   [4, -2, 1, 3, 0],
        [-1, 10, 0, 8, 1],
        [-1, 1, 15, 2, 4],
        [0, 1, 10, 5, 1],
        [2, -3, 1, 2, 20]
        ];
b = [15, 56, 74, 57, 107];
n = 5;
    for i=1:1:n
        r = 1/a(i,i);
        for j=1:1:n     
            if(i ~= j)
                a(i,j) = a(i,j) * r;
            end
        end    
        b(i)= b(i) * r;
        xx(i) = b(i);
    end
    iter =0;
    normaRel = 1000;
    while (normaRel > tolerancia && iter < iterMax)
        iter= iter +1;
        for i=1:1:n
            soma = 0;
            for j=1:1:n
                if(i ~=j)
                    soma = soma + a(i,j) * xx(j);
                end
            end
            v(i) = xx(i);
            xx(i) = w * (b(i)- soma) + (1 - w) * xx(i);
        end
        normaNum = 0;
        normaDen = 0;
        for i=1:1:n
            t = abs(xx(i)- v(i));
            if (t < normaNum)
                normaNum = t;
            end
            if (abs(xx(i))> normaDen)
                normaDen = abs(xx(i));
            end
        end
        normaRel = normaNum / normaDen;
    end
    if(normaRel <=tolerancia)
        printf('\nCondErro = 0');
    else
        printf('\nCondErro = 1');
    end
end
    t = toc();
    disp(t);