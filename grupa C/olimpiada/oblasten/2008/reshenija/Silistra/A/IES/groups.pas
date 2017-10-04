Program groups;
var p,n,x,i:integer;sr,k,d,s,v:real;
    a,c:array[1..500] of real;
begin
v:=0;
s:=0;
sr:=0;
d:=0;
k:=0;
writeln('vyv n');
readln(n);
writeln('vyv p kydeto p trqbva da e po malko ot n');
readln(p);
for i:=1 to n do
begin
writeln('vyv koordinatna to4ka koqto e po golqma ot predi6nata');
readln(a[i]);
end;
x:=n-p+1;
for i:=1 to n-x+1 do
begin
s:=0;
repeat
s:=s+a[i];
i:=i+1;
until i=x+1;
i:=i-x+1;
c[i]:=s;
end; writeln('dada',s);
for i:=1 to n-x+1 do
begin
c[i]:=c[i]/x;
sr:=c[i];
for i:=1 to n do
begin
k:=(sr-a[i])*(sr-a[i]);
d:=d+k;
end;
c[i]:=d;
end;
for i:=1 to n-x+1 do
if c[i]<v then v:=c[i];
writeln('minimalnata suma e',v);
end.
