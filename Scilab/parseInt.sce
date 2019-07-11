function num = parseInt (t)
    tic();
    for i=1:1:t
        n = rand (1.2147483646);
        disp(n);
        s = dec2hex(n);
        m = hex2dec(s);
        assert (m == n);
    end
    t = toc();
    disp(t);
endfunction
