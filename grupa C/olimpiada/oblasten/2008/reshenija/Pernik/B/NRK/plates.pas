program plates;
type M1=array [1..30,1..30] of integer;
     M2=array [1..10] of m1;
var
a:m1;
b:m2;
i,j,k,l,n,m:integer;
nerazl:integer;
procedure obr(var x:m1);
var f:integer;
 begin
  for k:=n+1 to n+n+1 do
   begin
    f:=x[i,k+1];
    x[i,k+1]:=x[i,k];
    x[i,k]:=f;
     for j:=n+1 downto 1 do
      begin
      f:=x[i,j];
      x[i,j]:=x[i,k];
      x[i,k]:=x[i,j-n];
      x[i,j-n]:=x[i,k]
     end;
     end;
     end;

begin
readln(m,n);
j:=1;
k:=n+1 ;
for i:=1 to m do
  begin
    while  (j<=n+1) and (k<=n+n+1) do
      begin
       readln(a[i,j]);
       readln(a[i,k]);
       j:=j+1;
       k:=k+1 ;
     end;
  end;
  for i:=1 to m do
   obr(a);
for i:=1 to m do
begin
 if a[i,j]=a[i+1,j] then
 if a[i,k]=a[i+1,k] then
 nerazl:=nerazl+1
end;
 writeln(nerazl);
 end.



