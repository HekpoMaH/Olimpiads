Program stamps;
type ar = array[1..3001] of integer;
function musk(a:ar;n:integer):integer
;var max,i:integer;
begin
for i:=2 to n do
if (a[i]>max)and(a[i]<=n) then
max:=a[i];
musk:=max;
end;
var s:1..5000;n:1..3000;a:ar;i,br,j,max,max1:integer;
begin
read(s,n);
for i:=1 to n do
begin
read(a[i]);
if (i>2)and(a[i]<a[i-1]) then max1:=a[i-1];end;
br:=0;
max:=0;
for i:=1 to n do
for j:=i+1 to n do
if ((a[i]+a[j])>max)and((a[i]+a[j])<s) then
max:=a[i]+a[j];
i:=0;
while s>0 do
begin
s:=s-musk(a,s-max);
br:=br+1;end;
br:=br+1;
writeln(br);
end.
