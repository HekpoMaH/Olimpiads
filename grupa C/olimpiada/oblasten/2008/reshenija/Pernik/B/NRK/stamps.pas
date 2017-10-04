program stamps;
type M1=array [1..100] of integer ;
var
z,s,n,sum1,sum2,sum,i:integer ;
c:m1;
procedure sort(var x:m1);
var sw:boolean;f:integer;
 begin
sw:=true  ;
 while sw do
 begin
 sw:=false;
  for i:=1 to n do
 if x[i]<x[i+1] then
begin
 f:=x[i];
 x[i]:=x[i+1];
 x[i+1]:=f;
 sw:=true;
end;
end;
end;
begin
readln(s,n);
z:=s      ;
for i:=1 to n do
read(c[i]);
sort(c);
writeln ;
sum2:=1000;
for i:=1 to n do
begin
for i:=i+1 to n do
begin
if s>c[i] then
begin
repeat
sum:=sum +(s div c[i]);
s:=s mod c[i] ;
until s<c[i];
end;
if c[i]=1 then
begin
repeat
s:=s-1 ;
sum:=sum+1;
until s=0;
end;
end;
if sum2<sum then sum:=sum2
end;
writeln(sum)
end.
