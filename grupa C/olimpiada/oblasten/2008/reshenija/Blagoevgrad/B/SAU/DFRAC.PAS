program dfrac;
var a,b,i,j,k,p:longint;c,d:real;s:longint;
begin
 write('a,b=');readln(a,b);
 write('k,p=');readln(k,p);
 c:=a/b;
 d:=frac(c);
 for i:= 1 to (k-1) do
  begin
  d:=d*10;
  d:=frac(d);
  end;
 for j:= 1 to p do
 begin
  d:=d*10;
  s:=trunc(d);
  write(s);
  d:=frac(d);
 end;
 writeln;
 end.
