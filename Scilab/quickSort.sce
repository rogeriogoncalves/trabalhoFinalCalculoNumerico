function y = quickSort(n,x)
    y = [];
    if x == [] then
        y = [];
    elseif ((size(x,'r') > 1) | (length(n) > 1)) then
        error ('quickSort(n,x): n deve ser escalar, e x deve ser matriz-linha')
    else
        select n
        case 1 then
            [lt,gt] = partition(x(1),x)
            y = [quickSort(1,lt) x(1) quickSort(1,gt)]
        else
            if n > length (x)
                y = quickSort(n-1,x)
            else
                ps = quickSort(1,x(1:n));
                xs = x((n+1):$);
                for i = 1:n
                    if i == 1 then
                        [lt,gt] = partition(ps(i),xs);
                        y = [quickSort(n,lt) ps(i)];
                    elseif i < n then
                        [lt,gt] = partition(ps(i),gt);
                        y = [y quickSort(n,lt) ps(i)];
                    else
                        [lt,gt] = partition(ps(i),gt);
                        y = [y quickSort(n,lt) ps(i) quickSort(n,gt)]
                    end
                end
            end
        end
    end
endfunction
function varargout = partition(x,xs)
    lt=[]; gt=[]; 
    for i = 1:length(xs)
        if xs(i)<x
            lt = [lt xs(i)];
        elseif xs(i)>x
            gt = [gt xs(i)];
        end
    end
    varargout = list(lt,gt)
endfunction
function b = isOrd(x)
    b = %T;
    for i = 2 : length(x)
        if x(i)<x(i-1) then
            b = %F;
            break
        end
    end
endfunction