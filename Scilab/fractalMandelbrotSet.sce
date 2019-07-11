function R = computeMandelbrotVect(xsize,ysize,nmax,xmin,xmax,ymin,ymax)
    tic():
    xvect = linspace( xmin, xmax, xsize );
    yvect = linspace( ymin, ymax, ysize );
    [X,Y]=meshgrid(xvect,yvect);
    Z = zeros(xsize,ysize);
    R = -ones(xsize,ysize);
    W = zeros(xsize,ysize);
    C=X+%i*Y;
    J = 1:xsize*ysize;
    for k=0:nmax
        L = J(J>0);
        Z(L) = Z(L).^2+C(L);
        W(L) = abs(Z(L));
        M = find(W(L)>2);
        R(L(M)) = k;
        J(L(M)) = 0;
    end
    R = R';
    CMAX = 1000;
    f=gcf();
    f.color_map = jetcolormap(CMAX);
    D = R;
    k = find(R<>-1);
    D(k) = floor(R(k)/max(R(k))*CMAX);
    k = find(R==-1);
    D(k) = CMAX;
    Matplot(D);
    f.children.isoview="on";
    f.children.axes_visible=["off" "off" "off"];
    t = toc();
    disp(t);
endfunction
