program stamps;
var a:array[1..3000] of integer;
    n,s,i,k,j,br,t,r:integer;
    m:boolean;
Begin
     readln (s,n);
     for i:=1 to n do
         read (a[i]);
     br:=0;
     repeat
     m:=true;
     for j:=1 to (n-1) do
         if a[j]>a[j+1] then
                            begin
                                 k:=a[j];
                                 a[j]:=a[j+1];
                                 a[j+1]:=k;
                                 m:=false;
                            end;
     until m=true;
     repeat
           r:=s div a[n];
           s:=s mod a[n];
           n:=n-1;
           br:=br+r;
     until n=0;
     writeln (br);
end.