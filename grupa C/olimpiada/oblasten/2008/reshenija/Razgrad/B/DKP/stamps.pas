program stamps;
var s,st,n,i,j,l,r,rt:integer;
    a,b,rr:array[1..3000]of integer;
begin
 read(S);readln(n);
 for i:=1 to n do
 read(a[i]);
 b[1]:=a[1];
 for i:=1 to n do
 begin
  for j:=1 to n do
   if a[j]>b[i] then b[i]:=a[j];
  for l:=1 to n do
   if b[i]=a[l] then a[l]:=0;
 end;
 for i:=1 to n do
 repeat
  if s>=b[i] then
  begin
   s:=s-b[i];
   r:=r+1;
  end;
 until(s<b[i]);
 writeln(r);
end.