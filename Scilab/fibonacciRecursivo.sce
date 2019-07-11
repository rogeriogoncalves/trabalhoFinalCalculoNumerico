function f = fibonacciRecursivo(n)
    tic();
        select n
        case 0 then
            f = 1
        case 1 then
            f = 1
        else 
            f = fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2)
         end
        t = toc();
        disp(t);
endfunction
