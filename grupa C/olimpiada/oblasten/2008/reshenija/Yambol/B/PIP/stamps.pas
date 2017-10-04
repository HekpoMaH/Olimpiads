program b3;
var i,n,s,t,br:integer;
    a:array[1..3000] of byte;

    procedure sort(l,r:integer);
    var i,j,x,m,p:integer;
    begin
     m:=((l+r)div 2);
     x:=((A[m]+A[l]+A[r]) div 3);
     i:=l;
     j:=r;
     repeat
     while A[i]<x do
     inc(i);
     while A[j]>x do
     dec(j);
     if not (i>j) then
     begin
     p:=A[i];
     A[i]:=A[j];
     A[j]:=p;
     inc(i);
     dec(j);
     end;
     until i>j;
     if l<j then sort(l,j);
     if i<r then sort(i,r);
     end;

begin
br:=0;
readln(s,n);
for i:=1 to n do
read(A[i]);

sort(1,n);
br:=n+A[4];
writeln(br);
end.










