{Ilian Ivanov Ivanov 7 klas}
program pathi;
var
vr:array[1..20,1..20]of integer;
res:array[1..20]of integer;
m,j,a,sum,i,r,z,x,p,c,b,n:integer;
bool:boolean;
procedure path(a:integer);
begin
if vr[a,b]=1
then bool:=true
else begin
repeat
c:=c+1;
if vr[a,c]=1
then begin
vr[a,c]:=0;
vr[c,a]:=0;
path(c);
end;
vr[a,c]:=1;
vr[c,a]:=1;
until (bool<>true)or(c<n);
if bool=true
then begin
r:=r+1;
res[r]:=c;end;
end;end;
begin
r:=1;
bool:=false;
c:=0;
readln(n);
for i:=1 to n do
for j:=1 to n do
vr[i,j]:=0;
sum:=0;
for i:=n-1 downto 1 do
sum:=sum+i;
for i:=1 to sum do begin
readln(z,x,p);
if p=1
then begin
vr[z,x]:=1;
vr[x,z]:=1;end;
end;
readln(m,b);
path(m);
res[1]:=m;
writeln(r);
for i:=1 to r do
write(res[i],' ');
readln;
end.