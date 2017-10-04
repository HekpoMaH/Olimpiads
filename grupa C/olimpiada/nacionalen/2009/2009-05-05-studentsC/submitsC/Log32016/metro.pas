{
TASK:METRO
LANG:PASCAL
}
program metro_0;
var n,sum,ya,y,i:longint;
begin
  readln(n);
  sum:=0;
  read(ya);
  for i:= 2 to n do
    begin
      read(y);
      sum:=sum+abs(ya-y);
      ya:=y;
    end;
  writeln(sum);
end.