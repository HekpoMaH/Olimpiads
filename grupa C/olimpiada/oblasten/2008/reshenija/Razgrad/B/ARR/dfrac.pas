{$N+}
program dfrac;
        var a,b,n,m:comp;
            k,br,i:extended;
            p,t,l:integer;
            j,r:real;
Begin
     readln (a,b);
     readln (k,p);
     n:=124124235.2352;
     i:=k+p;
     l:=1;
     r:=0;
     if (0<a) and (a<30000000)and (0<b)and (b<30000000) and (a<b)and (0<k) and (k<i
     )and (p<50)
     then
         begin
              writeln (n);
              m:= int(n);
              n:=n-m;
              repeat
                    n:=n*10;
                    br:=br+1;
                    if br=(k-1) then
                                    begin
                                         for t:=1 to p do
                                             begin
                                               n:=frac(n);
                                               n:=n*10;
                                               j:=int(n);
                                               l:=l*10;
                                               r:=r*10+j;
                                             end;
                                    end;
              until br=(k-1);
         end
     else writeln ('4islata ne sa vavedeni korektno');
end.



