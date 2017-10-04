program primes;
var
a,a1,a2,a3,i,n:integer;

begin
readln(n);
case n of
1,2,3,4,5:a:=1;
else begin
a1:=1;
a2:=1;
a3:=1;
for i:=6 to n do
  begin
   a:=a2+a3;
   a3:=a2;
   a2:=a1;
   a1:=a;
   end;
end;
end;
writeln(a);
readln;
end.

