Program dfrac;
var a,b,p,k:longint;r:real;i,m,s:integer;
begin
readln(a,b);
read(k,p);
r:=(a)/(b);
for i:=1 to k-1 do
r:=r*10;
r:=frac(r);
m:=p div 5;
s:=p mod 5;
while(m>0) do
begin
for i:=1 to 5  do
begin
r:=r*10;
write(trunc(r));
r:=frac(r);
end;
m:=m-1;
end;
for i:=1 to s do
begin
r:=r*10;
write(trunc(r));
r:=frac(r);
end;
end.